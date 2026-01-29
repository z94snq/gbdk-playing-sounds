# gbdk-playing-sounds
GBDK simple playing sounds

## Requirements
- Windows OS
- GBDK-2020 >= 4.5.0
- CMake >= 4.2.1
- GNU Make >= 4.4.1

**TIPS:** You can use [Chocolatey](https://community.chocolatey.org/) to install CMake and GNU Make easily: `choco install cmake` `choco install make`

## Build Instructions

### Prerequisites
Extract GBDK-2020 for Windows in the `C:\gbdk` directory.

### Quick Build
Run the build script using PowerShell:

```powershell
.\build.ps1
```

Optional flags:
- `-clean` - Clean build artifacts before building
- `-debug` - Build in debug mode

Example:
```powershell
.\build.ps1 -clean -debug
```

This will generate `rom.gb` in the `build` directory, which can be loaded into an emulator or flashcart.

### Manual Build
To build manually using CMake:

```powershell
mkdir build
cd build
cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release
make
cd ..
```

Use `-DCMAKE_BUILD_TYPE=Debug` for debug build.

## Generate Graphics Assets

To generate assets file from png we use png2asset, here are the commands we use:
```
C:\gbdk\bin\png2asset.exe .\BallSprite.png -spr8x8
```

## Resources
- GBDK: https://github.com/gbdk-2020/gbdk-2020
- Aseprite: https://www.aseprite.org/
- png2asset Tutorial: https://laroldsretrogameyard.com/tutorials/gb/png2asset-graphics-creation-for-gbdk-2020
- Playing Sounds Tutorial: http://laroldsretrogameyard.com/tutorials/gb/sounds-and-audio/