# Snake Game

A classic Snake Game implementation in C++ using the SFML graphics library, with added features such as multiple game modes, a pause screen, and a rolling high score.

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Getting Started](#getting-started)
- [Game Modes](#game-modes)
- [Pause Screen](#pause-screen)
- [Rolling High Score](#rolling-high-score)
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

Clone the repository to your local machine and follow the building and running instructions in the next section.

## Game Modes

The Snake Game offers three exciting game modes:

1. **Classic Mode**: The traditional Snake Game experience. Eat food, grow longer, and try to achieve the highest score possible.

2. **Time Attack Mode**: Test your skills against the clock. Race to eat as much food as possible within a limited time.

3. **Obstacle Mode**: Navigate through a maze of obstacles while trying to grow your snake. Avoid collisions to survive and thrive.

## Pause Screen

Press the designated pause key during gameplay to pause the game and take a break. The pause screen provides options to resume the game or return to the main menu.

## Rolling High Score

The game keeps track of your performance with a rolling high score. Your highest score achieved across all game modes is persistently displayed on the main menu.

Certainly! Here's an updated section with CMake and Make instructions:

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

Note: Ensure that you have CMake and SFML installed on your system before running the build commands.

Now, you're ready to enjoy the Snake Game! If you encounter any issues or have feedback, feel free to reach out to the developers.

## Dependencies

The Snake Game relies on the SFML graphics library. Ensure you have SFML installed on your system before building the game.

## License

The Snake Game is open-source and licensed under the MIT License. Feel free to explore, modify, and share the code. See the [LICENSE](LICENSE) file for more details.

Enjoy playing the Snake Game! If you have any questions or feedback, please reach out to the developers.
