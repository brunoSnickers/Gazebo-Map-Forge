# Gazebo Maze Generator

Ein einfaches Python-Skript zur Erzeugung zufälliger, zusammenhängender ASCII‑Labyrinthe – direkt in VSCode.

---

### Workflow

1. Generiere eine `ascii-maze.txt`, die anschließend manuell bearbeitet werden kann.
2. Danach wird diese `ascii-maze.txt` in `generated_maze.cpp` umgewandelt.
3. Diese Datei kann in Gazebo eingebunden werden.

---

### Voraussetzungen

Installiere die benötigten Python-Pakete.

---

### How to

**Ausführung in VSCode**

- Öffne das Projekt in VSCode.
- Öffne die Datei `gazebo_maze_generator.ipynb`.
- Klicke oben auf **Run All**, um alle Zellen auszuführen.  
  Oder führe nur die **erste Zelle** aus, um nur das Textlabyrinth zu generieren.
- Die Textausgabe findest du unter `output/ascii-maze.txt`.

**Manuelle Bearbeitung des Maze**

- Öffne `output/ascii-maze.txt` in VSCode.
- Passe die ASCII-Zeichen (`─`, `│`, `┌`, `┐`, `└`, `┘`, `┬`, `┴`, `├`, `┤`, `┼`) direkt im Editor an.
- Danach: Führe alle unteren Zellen aus (alle außer der ersten).

---

### Erklärung der Variablen

#### `n` = Integer ≥ 2

Anzahl der Zellen in einem `n x n`-Maze.

Beispiel:  
`n = 3`

    ┌  
    ├┬┐
    └┴┘
`n = 5:`

      ┌┐
      ┤└┐
     ┌┴┐│
    ┌┼┬┴┤
    └┘└─┘
---

#### `density` = Float (0.0 – 1.0)

Anteil der belegten Kacheln durch den initial aufgebauten Baum.

Beispiel: `density = 0.3` (7x7):
            
          
      │   
    ┴┼┼┤  
      ┘    
          
`density = 0.9:`

    ┌─┐┌  
    └┴┬┼┼─ 
     ┬┘ └┬ 
    ┌┼┬─┐└┐
    │ ├┐├┐│
    │      
    └┴     
---

#### `loop_prob` = Float (0.0 – 1.0)

Wahrscheinlichkeit, mit der eine Kachel eine Abzweigung zu einem bereits besuchten Weg bekommt.

Typische Werte: `0`, `0.05`, `0.1`, `0.4` usw.

Beispiel: `loop_prob = 0.05`

      ─┐ ┐ 
     ─┬┴┬┼┤
     ┌┴┬┘  
    │└┐├─  
    ├┬┼┼┬┐ 
      │├┴ 
      ┴┴─ 

`loop_prop = 0.4`

    ┌┬┬┬┬┬┐
    ├┼┤├┴┼┤
    ├┤││┌┤│
    ├┤├┼┤││
    ├┤├┤└┼┤
    │├┴┴ └┘
    └┘   

---

#### `max_dead_ends` = Integer ≥ -1

Maximale Anzahl an erlaubten Sackgassen.  
- `-1` = unbegrenzt.  
- Reduziert beim Durchlauf die Anzahl der Blätter des Baumes (Sackgassen), bis sie kleiner oder gleich `max_dead_ends` ist.

Beispiel: `max_dead_ends = 2`

      ┌┬──┐
     ┌┤└──┤
    ├┴┼┐┌┐│
    └─┼┴┴┴┤
    ┌┐├─┐┌┤
    └┤└─┴┼┤
     └───┘

`max_dead_ends = -1`
          
     ┬┘││  
     │┌┴┘││
    │││┌ ││
    ││├┘┌┴┘
    └┼┘┌┴─ 
     ┴─┴─  

---

#### `spread_bias` = Float (0.0 – 1.0)

Beeinflusst die Wachstumsrichtung des Labyrinths.

Beispiel: `spread_bias = 0.1`

      ──┬ 
        └┐
         │
        ├┘
        ├ 
        │ 
        └┴┘

`spread_bias = 0.9`

    ┬┬─┬┐
       ┘│
      ┌┬┤
      ││
        
        
        .

---

#### `output_format` = `human` oder `default`

Gibt an, wie der Output formatiert wird.

- `human`: ASCII-Ansicht im Terminal (zum Testen).
- `default`: Python-Array für Gazebo.

Beispiel: `output_format = 'human'`

         ┌┐
         ├┘
    ┌─┬──┤ 
    │    └┐
    ├┐    │
    ├┴┬┬┬┬┤
      ┴┴┴┴┘

`output_format = 'default'`

    grid = [
        ['┌', '┬', '─', '┬', '┬', '┬', '┐'],
        ['│', '├', '┬', '┼', '┘', '└', '┤'],
        ['└', '┴', '┴', '┘', ' ', '┌', '┤'],
        [' ', ' ', ' ', ' ', '┌', '┴', '┘'],
        ['┌', '─', '─', '─', '┘', ' ', ' '],
        [' ', ' ', ' ', ' ', ' ', ' ', ' '],
        [' ', ' ', ' ', ' ', ' ', ' ', ' '],
    ]
