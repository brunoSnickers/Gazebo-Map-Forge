#!/usr/bin/env python3
import random
import argparse
import time
import sys

CHAR_STRAIGHT_H = '─'
CHAR_STRAIGHT_V = '│'
CHAR_CURVE_SE    = '┌'
CHAR_CURVE_SW    = '┐'
CHAR_CURVE_NE    = '└'
CHAR_CURVE_NW    = '┘'
CHAR_T_DOWN      = '┬'
CHAR_T_UP        = '┴'
CHAR_T_RIGHT     = '├'
CHAR_T_LEFT      = '┤'
CHAR_CROSS       = '┼'
EMPTY_CHAR       = ' '

CONNECTIONS_TO_CHAR = {
    frozenset(['W','E']): CHAR_STRAIGHT_H,
    frozenset(['N','S']): CHAR_STRAIGHT_V,
    frozenset(['S','E']): CHAR_CURVE_SE,
    frozenset(['S','W']): CHAR_CURVE_SW,
    frozenset(['N','E']): CHAR_CURVE_NE,
    frozenset(['N','W']): CHAR_CURVE_NW,
    frozenset(['S','W','E']): CHAR_T_DOWN,
    frozenset(['N','W','E']): CHAR_T_UP,
    frozenset(['N','S','E']): CHAR_T_RIGHT,
    frozenset(['N','S','W']): CHAR_T_LEFT,
    frozenset(['N','S','W','E']): CHAR_CROSS,
}

def adjacency_to_char(adj, i, j):
    return CONNECTIONS_TO_CHAR.get(frozenset(adj.get((i,j), set())), EMPTY_CHAR)

def fix_dead_ends_expand(adj, n, selected, max_dead_ends=0, allow_expand=True, max_expand=None):
    changed = True
    expand_count = 0
    while changed:
        dead_ends = [(i,j) for (i,j) in list(selected) if len(adj.get((i,j), set())) == 1]
        if len(dead_ends) <= max_dead_ends:
            break
        changed = False
        for (i,j) in dead_ends:
            if len(dead_ends) <= max_dead_ends:
                break
            conns = adj.get((i,j), set())
            dirs = [('N',(-1,0)),('S',(1,0)),('W',(0,-1)),('E',(0,1))]
            random.shuffle(dirs)
            connected = False
            for d,(di,dj) in dirs:
                ni, nj = i+di, j+dj
                if 0 <= ni < n and 0 <= nj < n and (ni,nj) in selected and d not in conns:
                    adj.setdefault((i,j), set()).add(d)
                    opp = {'N':'S','S':'N','W':'E','E':'W'}[d]
                    adj.setdefault((ni,nj), set()).add(opp)
                    changed = True
                    connected = True
                    break
            if connected:
                continue
            if allow_expand:
                for d,(di,dj) in dirs:
                    ni, nj = i+di, j+dj
                    if 0 <= ni < n and 0 <= nj < n and (ni,nj) not in selected:
                        adj.setdefault((i,j), set()).add(d)
                        opp = {'N':'S','S':'N','W':'E','E':'W'}[d]
                        adj.setdefault((ni,nj), set()).add(opp)
                        selected.add((ni,nj))
                        expand_count += 1
                        changed = True
                        break
                if max_expand is not None and expand_count >= max_expand:
                    allow_expand = False
    return adj, selected

def generate_random_connected(n, density, loop_prob, max_dead_ends, spread_bias):
    total = n*n
    target = max(1, int(total * density))
    adj = {}
    cells = [(random.randrange(n), random.randrange(n))]
    selected = {cells[0]}
    while len(selected) < target:
        if spread_bias > 0 and cells:
            scores = []
            for (i,j) in cells:
                cnt = 0
                for (di,dj) in [(-1,0),(1,0),(0,-1),(0,1)]:
                    ni, nj = i+di, j+dj
                    if (ni,nj) in selected:
                        cnt += 1
                scores.append((cnt, (i,j)))
            scores.sort(key=lambda x: x[0])
            cutoff = max(1, int(len(scores) * spread_bias))
            _, (i,j) = random.choice(scores[:cutoff])
        else:
            i,j = random.choice(cells)
        dirs = [('N',(-1,0)),('S',(1,0)),('W',(0,-1)),('E',(0,1))]
        random.shuffle(dirs)
        found = False
        for d,(di,dj) in dirs:
            ni, nj = i+di, j+dj
            if 0 <= ni < n and 0 <= nj < n and (ni, nj) not in selected:
                adj.setdefault((i,j), set()).add(d)
                opp = {'N':'S','S':'N','W':'E','E':'W'}[d]
                adj.setdefault((ni,nj), set()).add(opp)
                selected.add((ni,nj))
                cells.append((ni,nj))
                found = True
                break
        if not found:
            new_cells = []
            for (ci,cj) in cells:
                for (di,dj) in [(-1,0),(1,0),(0,-1),(0,1)]:
                    ni, nj = ci+di, cj+dj
                    if 0 <= ni < n and 0 <= nj < n and (ni,nj) not in selected:
                        new_cells.append((ci,cj))
                        break
            cells = new_cells
            if not cells:
                break
    for i,j in list(selected):
        for d,(di,dj) in [('N',(-1,0)),('S',(1,0)),('W',(0,-1)),('E',(0,1))]:
            ni, nj = i+di, j+dj
            if 0 <= ni < n and 0 <= nj < n and (ni,nj) in selected:
                if d not in adj.get((i,j), set()) and random.random() < loop_prob:
                    adj.setdefault((i,j), set()).add(d)
                    opp = {'N':'S','S':'N','W':'E','E':'W'}[d]
                    adj.setdefault((ni,nj), set()).add(opp)
    if max_dead_ends >= 0:
        adj, selected = fix_dead_ends_expand(adj, n, selected, max_dead_ends, allow_expand=True, max_expand=None)
    return adj

def build_cycle(n, target_len, time_limit):
    start = time.time()
    dirs = [('N',(-1,0)),('S',(1,0)),('W',(0,-1)),('E',(0,1))]
    def neighbors(i,j):
        for d,(di,dj) in dirs:
            ni, nj = i+di, j+dj
            if 0 <= ni < n and 0 <= nj < n:
                yield d, ni, nj
    for attempt in range(100):
        visited = [[False]*n for _ in range(n)]
        path = []
        si, sj = random.randrange(n), random.randrange(n)
        visited[si][sj] = True
        path.append((si,sj))
        start_time = time.time()
        def dfs(i,j,depth):
            if time.time() - start_time > time_limit:
                return False
            if depth == target_len:
                for d, ni, nj in neighbors(i,j):
                    if (ni, nj) == (si, sj):
                        path.append((i,j))
                        return True
                return False
            for d, ni, nj in random.sample(list(neighbors(i,j)), len(list(neighbors(i,j)))):
                if not visited[ni][nj]:
                    visited[ni][nj] = True
                    path.append((i,j))
                    if dfs(ni, nj, depth+1):
                        return True
                    path.pop()
                    visited[ni][nj] = False
            return False
        if dfs(si, sj, 1):
            adj = {}
            for idx in range(len(path)-1):
                i,j = path[idx]
                ni,nj = path[idx+1]
                if ni == i-1 and nj == j: d='N'
                elif ni == i+1 and nj == j: d='S'
                elif ni == i and nj == j-1: d='W'
                elif ni == i and nj == j+1: d='E'
                else: continue
                adj.setdefault((i,j), set()).add(d)
                opp = {'N':'S','S':'N','W':'E','E':'W'}[d]
                adj.setdefault((ni,nj), set()).add(opp)
            i,j = path[-1]
            if si == i-1 and sj == j: d='N'
            elif si == i+1 and sj == j: d='S'
            elif si == i and sj == j-1: d='W'
            elif si == i and sj == j+1: d='E'
            else: d=None
            if d:
                adj.setdefault((i,j), set()).add(d)
                opp = {'N':'S','S':'N','W':'E','E':'W'}[d]
                adj.setdefault((si,sj), set()).add(opp)
            return adj
    return None

def adjacency_to_grid(adj, n):
    grid = []
    for i in range(n):
        row = []
        for j in range(n):
            row.append(adjacency_to_char(adj, i, j))
        grid.append(row)
    return grid

def save_map_text(filename, adj, n):
    border = '#' * n
    with open(filename, 'w', encoding='utf-8') as f:
        f.write(border + "\n")
        f.write(f"# Size: {n} {n}\n")
        f.write("# Legend:\n")
        f.write(f"# {CHAR_STRAIGHT_H} : EW\n")
        f.write(f"# {CHAR_STRAIGHT_V} : NS\n")
        f.write(f"# {CHAR_CURVE_SE} : SE\n")
        f.write(f"# {CHAR_CURVE_SW} : SW\n")
        f.write(f"# {CHAR_CURVE_NE} : NE\n")
        f.write(f"# {CHAR_CURVE_NW} : NW\n")
        f.write(f"# {CHAR_T_DOWN} : T-down (S,W,E)\n")
        f.write(f"# {CHAR_T_UP} : T-up (N,W,E)\n")
        f.write(f"# {CHAR_T_RIGHT} : T-right (N,S,E)\n")
        f.write(f"# {CHAR_T_LEFT} : T-left (N,S,W)\n")
        f.write(f"# {CHAR_CROSS} : crossroad (N,S,W,E)\n")
        f.write(f"# {EMPTY_CHAR!r} : empty\n")
        f.write(border + "\n")
        for i in range(n):
            row = ''.join(adjacency_to_char(adj, i, j) for j in range(n))
            f.write(row + "\n")
        f.write(border + "\n")

def save_map_python(filename, adj, n):
    grid = adjacency_to_grid(adj, n)
    with open(filename, 'w', encoding='utf-8') as f:
        f.write("grid = [\n")
        for row in grid:
            f.write("    " + repr(row) + ",\n")
        f.write("]\n")

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("n", type=int)
    parser.add_argument("--mode", choices=['random','r','roundtrip','rt'], default='random')
    parser.add_argument("--density", type=float, default=0.5)
    parser.add_argument("--loop_prob", type=float, default=0.1)
    parser.add_argument("--max_dead_ends", type=int, default=0)
    parser.add_argument("--spread_bias", type=float, default=0.5,
                        help="0=no bias, 1=strong bias to spread out")
    parser.add_argument("--time_limit", type=float, default=5.0)
    parser.add_argument("--format", choices=['human','hermann'], default='hermann')
    parser.add_argument("--output", default="map.txt")
    args = parser.parse_args()
    n = args.n
    if n < 2:
        sys.exit(1)
    if args.mode in ('random','r'):
        adj = generate_random_connected(n, args.density, args.loop_prob, args.max_dead_ends, args.spread_bias)
    else:
        target = max(4, int(n*n * args.density))
        adj = build_cycle(n, target, args.time_limit)
        if adj is None:
            sys.exit(1)
    if args.format == 'human':
        save_map_text(args.output, adj, n)
    else:
        save_map_python(args.output, adj, n)

if __name__ == "__main__":
    main()

'''
python3 generate_map.py <1-99> \
    --mode random \
    --density <0.0–1.0> \
    --loop_prob <0.0–1.0> \
    --max_dead_ends <0–99> \
    --spread_bias <0.0–1.0> \
    --format <human, hermann> \
    --output output.txt

python3 generate_map.py <1-99> \
    --mode roundtrip \
    --density <0.0–1.0> \
    --time_limit 5.0 \
    --format <human, hermann> \
    --output output.txt
# Increase --time_limit if needed for success on larger grids.

example:
python3 generate_map.py 10     --mode random     --density 0.6     --loop_prob 0.001     --max_dead_ends 0     --spread_bias 1.0     --format human     --output output.txt
'''
