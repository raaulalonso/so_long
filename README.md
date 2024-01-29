# so_long

 [![Intro](https://img.shields.io/badge/Cursus-So_long-success?style=for-the-badge&logo=42)](https://github.com/raaulalonso/so_long)
 
 [![Stars](https://img.shields.io/github/stars/raaulalonso/so_long?color=ffff00&label=Stars&logo=Stars&style=?style=flat)](https://github.com/raaulalonso/so_long)
 [![Size](https://img.shields.io/github/repo-size/raaulalonso/so_long?color=blue&label=Size&logo=Size&style=?style=flat)](https://github.com/raaulalonso/so_long)
 [![Activity](https://img.shields.io/github/last-commit/raaulalonso/so_long?color=red&label=Last%20Commit&style=flat)](https://github.com/raaulalonso/so_long)

All the textures used in the game have been hand-painted. This game is programmed in C and is designed for macOS(Intel).

## How to Play

In so_long, the objective is to navigate through a map, collect all the items, and then reach the exit to complete the level. The game comes with a set of pre-designed maps, but you can create your own custom maps to challenge yourself or others.

## Getting Started

### Prerequisites

Before you can start playing so_long, make sure you have the following prerequisites installed on your Mac:

- C Compiler (e.g., GCC)
- Make
- XQuartz (for graphics display on Mac)

### Installation

1. Clone the so_song repository to your local machine:

   ```shell
   git clone https://github.com/raaulalonso/so_long.git so_long
2. Change your current working directory to the project folder:
   
   ```shell
   cd so_long
3. Compile the game using the provided Makefile:

   ```shell
   make

## Running the Game

To launch So_Long, you need to execute it with the following command:

   ```shell
   ./so_long [map_path]
   ```
Replace [map_path] with the directory of the map you want to play, for example: "maps/maze.ber"
The game will automatically load the specified map, and you can start playing!

## Creating Custom Maps

To create your own custom maps, follow these rules:

- The map should be in a .ber format.
- It must have a player (P) and an exit (E).
- The map must be a rectangle.
- It should be surrounded by walls (1).
- Use collectibles (C) to make the game challenging.
- Ensure there's a valid path for the player to collect all the items and reach the exit.

If your custom map violates any of these rules, the game will provide a personalized error message.

## Gameplay

- Move the player (P) using WSAD.
- Collect all the collectibles (C).
- Reach the exit (E) to complete the level.

## Screenshots

![Demo GIF](https://github.com/raaulalonso/so_long/blob/main/screenshots/screenrecording1.gif)
![Demo IMG_1](https://github.com/raaulalonso/so_long/blob/main/screenshots/screenshoot1.png)
![Demo IMG_1](https://github.com/raaulalonso/so_long/blob/main/screenshots/screenshoot2.png)



