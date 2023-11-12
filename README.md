# Snake Game

A classic Snake Game implementation in C++ using the SFML graphics library, with added features such as multiple game modes, a pause screen, and a rolling high score.

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Getting Started](#getting-started)
- [Game Modes](#game-modes)
- [Pause Screen](#pause-screen)
- [Rolling High Score](#rolling-high-score)
- [ToDo](#todo)
- [Building and Running](#building-and-running)
- [Screenshots](#screenshots)

## Overview

The Snake Game is a timeless classic where players control a snake to eat food and grow longer. As the snake grows, the game becomes more challenging, as the player must avoid collisions with the snake's own body and the game borders.

## Features

1. **Multiple Game Modes**: Choose from three different game speeds.

2. **Pause Screen**: Pause the game at any time to take a break or strategize your next move.

3. **Rolling High Score**: Track your performance with a rolling high score.

## Getting Started

Clone the repository to your local machine. The project uses the [CMake SFML Project Template](https://github.com/SFML/cmake-sfml-project), which means you don't need to have SFML pre-installed unless you're a Linux user.

For Linux users, ensure you have SFML installed on your system.

Follow the building and running instructions in the next section.

## Game Modes

### Snail Mode

The traditional Snake Game experience. Eat food, grow longer, and try to achieve the highest score possible.

### Mamba Mode

Snail mode, but double time!

### Progressive Mode

The game starts nice and slowly, but the speed increases each time you eat food, getting progressively more challenging.

## Pause Screen

Press the designated pause key during gameplay to pause the game and take a break. The pause screen provides options to resume the game or return to the main menu.

## Rolling High Score

The game keeps track of your performance with a rolling high score. Your highest score achieved across all game modes in the current session is displayed on the main menu.

## ToDo

- **Add graphics to make it pretty :D
- **Add a different food item that is only available for a set amount of time

## Building and Running

Follow these steps to build and run the Snake Game:

### Using CMake

For a single-configuration generator (typically the case on Linux and macOS):

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
```

For a multi-configuration generator (typically the case on Windows):

```bash
cmake -S . -B build
cmake --build build --config Release
```

### Using Make

Build the game using Make:

```bash
make -C build/
```

Run the game executable:

```bash
./build/bin/snake
```

Now, you're ready to enjoy the Snake Game! If you encounter any issues or have feedback, feel free to reach out to the developers.

## Screenshots

<img width="797" alt="Start Screen" src="https://github.com/deelliot/Snake/assets/93197340/f70b9dc8-d1f6-43c6-b388-30ab39e7d23d">

<img width="797" alt="Game Screen" src="https://github.com/deelliot/Snake/assets/93197340/1f6ed822-43f9-4484-be2b-5b8ea1556b9f">

<img width="809" alt="Pause Screen" src="https://github.com/deelliot/Snake/assets/93197340/722dbd15-ca8a-4483-a75e-832803e588a0">

<img width="808" alt="Game Over" src="https://github.com/deelliot/Snake/assets/93197340/5e7e6f52-14a1-4bcf-bbb2-7e41f18c555c">



