# 🕹️ so_long

> A simple 2D graphical game where the player navigates a map to collect items and reach the exit — built using the MiniLibX graphics library.

## 📘 Project Description

**so_long** is a small 2D game written in C using the **MiniLibX** graphics library. The player must move through a map, collect all collectibles, and find the exit while avoiding enemies (if bonus is implemented). This project teaches basic graphics rendering, input handling, and game loop logic.

## 🎯 Objectives

- Parse and validate a `.ber` map file
- Render a tile-based game map with MiniLibX
- Allow player movement via keyboard
- Count moves and display them
- Implement win/lose conditions

## 🛠️ Skills Learned

- Using **MiniLibX** for simple graphics
- Keyboard input handling
- Map parsing and file I/O
- Linked list or matrix representation
- Pathfinding / flood fill (for bonus)
- Modular C programming
- Memory and resource management

---

## 🧪 Usage

### ✅ Requirements

- macOS or Linux (with X11 support)
- MiniLibX installed (can be included or cloned with the project)

### 🔧 Build

```bash
make
./so_long maps/map1.ber
