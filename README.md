# NeoRaquet Game Engine

NeoRaquet is a game engine developed using SDL2 for creating 2D games. This engine includes functionalities for rendering, audio, input handling, and basic game object management.

## Table of Contents

- [Features](#features)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [File Structure](#file-structure)
- [Contributing](#contributing)
- [License](#license)

## Features

- 2D Rendering
- Audio playback with SDL2_mixer
- Input handling (keyboard and mouse)
- Basic game object management (actors)
- Collision detection

## Requirements

- GCC (or any compatible C compiler)
- SDL2
- SDL2_mixer

## Installation

1. **Clone the repository:**
    ```sh
    git clone https://github.com/colack/NeoRaquet.git
    cd NeoRaquet
    ```

2. **Install SDL2 and SDL2_mixer:**
    - **Linux:**
        ```sh
        sudo apt-get install libsdl2-dev libsdl2-mixer-dev
        ```
    - **MacOS:**
        ```sh
        brew install sdl2 sdl2_mixer
        ```
    - **Windows:**
        - Download and install [SDL2](https://libsdl.org/download-2.0.php) and [SDL2_mixer](https://www.libsdl.org/projects/SDL_mixer/).

3. **Build the project:**
    ```sh
    make
    ```

## Usage

After building the project, you can run the executable from the `bin` directory:

```sh
./bin/game
```

## File Structure

```
NeoRaquet/
├── src/                # Source files
│   ├── NeoRaquet.h
│   ├── NeoRaquet_Actor.c
│   ├── NeoRaquet_Actor.h
│   ├── NeoRaquet_Audio.c
│   ├── NeoRaquet_Audio.h
│   ├── NeoRaquet_Input.c
│   ├── NeoRaquet_Input.h
│   ├── NeoRaquet_Main.c
│   ├── NeoRaquet_Math.h
│   ├── NeoRaquet_Render.c
│   ├── NeoRaquet_Render.h
│   └── NeoRaquet_Types.h
└── README.md
```

## Contributing

Contributions are welcome! If you are looking for a way to contribute, just add some new features, look at our issues, or make something.

## License

This project is licensed under the Apache 2.0 License - see the [LICENSE](LICENSE) file for details.
