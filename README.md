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
- [Dependencies](#dependencies)
- [License](#license)

## Overview

The Snake Game is a timeless classic where players control a snake to eat food and grow longer. As the snake grows, the game becomes more challenging, as the player must avoid collisions with the snake's own body and the game borders.

## Features

1. **Multiple Game Modes**: Choose from three different game modes, each with its own unique challenge and gameplay dynamics.

2. **Pause Screen**: Pause the game at any time to take a break or strategize your next move.

3. **Rolling High Score**: Track your performance with a rolling high score that persists across game sessions.

## Getting Started

Clone the repository to your local machine. The project uses the [CMake SFML Project Template](https://github.com/SFML/cmake-sfml-project), which means you don't need to have SFML pre-installed unless you're a Linux user.

Follow the building and running instructions in the next section.

## Pause Screen

Press the designated pause key during gameplay to pause the game and take a break. The pause screen provides options to resume the game or return to the main menu.

## ToDo

- **Implement the Different Game Modes**: As described below:

	## Game Modes

	### Classic Mode

	The traditional Snake Game experience. Eat food, grow longer, and try to achieve the highest score possible.

	### Time Attack Mode

	Test your skills against the clock. Race to eat as much food as possible within a limited time.

	### Obstacle Mode

	Navigate through a maze of obstacles while trying to grow your snake. Avoid collisions to survive and thrive.

- **Rolling High Score Logic**:

	## Rolling High Score

	The game keeps track of your performance with a rolling high score. Your highest score achieved across all game modes is persistently displayed on the main menu.

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

Now, you're ready to enjoy the Snake Game! If you encounter any issues or have feedback, feel free to reach out.