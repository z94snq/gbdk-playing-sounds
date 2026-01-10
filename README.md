# gbdk-playing-sounds
GBDK simple playing sounds

## Build Instructions
Place gbdk for Windows in the `C:\gbdk` directory, then run this command in PowerShell:

```
C:\gbdk\bin\lcc.exe -c -o main.o main.c
C:\gbdk\bin\lcc.exe -c -o BallSprite.o BallSprite.c
C:\gbdk\bin\lcc.exe -o rom.gb main.o BallSprite.o
```

or just run `build.ps1`

This will create `rom.gb`, which can be loaded into an emulator or flashcart.

## Convert PNG into GBDK asset
```
C:\gbdk\bin\png2asset.exe .\BallSprite.png -spr8x8
```

## Resources
- GBDK: https://github.com/gbdk-2020/gbdk-2020
- Aseprite: https://www.aseprite.org/
- png2asset Tutorial: https://laroldsretrogameyard.com/tutorials/gb/png2asset-graphics-creation-for-gbdk-2020
- Playing Sounds Tutorial: http://laroldsretrogameyard.com/tutorials/gb/sounds-and-audio/
