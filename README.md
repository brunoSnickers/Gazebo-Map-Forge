# Gazebo-Map-Forge

Dieses Projekt dient zur Erstellung und Konvertierung von Maps für Gazebo-Simulationen.

## Workflow

1. **Parameter anpassen**
   - Öffne die Datei `generator/gazebo_map_forge.py` in VSCode.
   - Passe am Anfang des Skripts die Parameter an, z.B. Größe, Namen oder andere Einstellungen deiner Map.
   - Beispiel:
     ```python
     width = 10
     height = 10
     output_name = "maze"
     ```

2. **Map generieren**
   - Führe das Skript aus:
     ```sh
     python generator/gazebo_map_forge.py
     ```
   - Die Dateien `maze.txt` und `maze.cpp` werden im Ordner `output/` erstellt bzw. überschrieben.

3. **Map verwenden**
   - Nutze die generierte `maze.txt` z.B. für weitere Bearbeitung oder Visualisierung.
   - Die Datei `maze.cpp` kann direkt in C++-Projekte eingebunden werden.

## Wichtige Dateien

- **generator/gazebo_map_forge.py**  
  Hauptskript zur Erstellung und Anpassung der Map.

- **output/maze.txt**  
  Textuelle Repräsentation der generierten Map.

- **output/maze.cpp**  
  Generierte Map als C++-Quelldatei.

## Hinweise

- Änderungen an den Map-Parametern immer im Python-Skript vornehmen.
- Nach jeder Änderung das Skript erneut ausführen, um die Ausgaben zu aktualisieren.
