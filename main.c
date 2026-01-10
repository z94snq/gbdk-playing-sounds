#include <gb/gb.h>
#include "BallSprite.h"

uint8_t spriteX, spriteY;
int8_t velocityX, velocityY;
uint8_t joypadCurrent = 0, joypadPrevious = 0;

void main(void)
{
    // This enables Sound
    // these registers must be in this specific order!
    NR52_REG = 0x80; // is 1000 0000 in binary and turns on sound
    NR50_REG = 0x77; // sets the volume for both left and right channel just set to max 0x77
    NR51_REG = 0xFF; // is 1111 1111 in binary, select which chanels we want to use in this case all of them. One bit for the L one bit for the R of all four channels

    DISPLAY_ON;
    SHOW_SPRITES;

    set_sprite_data(0, 1, BallSprite_tiles);
    set_sprite_tile(0, 0);
    move_sprite(0, 84, 88);

    // Set default position
    spriteX = 80;
    spriteY = 72;

    // Set default velocity
    velocityX = 0;
    velocityY = 0;

    // Loop forever
    while(1){
        // update joypad previous and get current joypad data
        joypadPrevious = joypadCurrent;
        joypadCurrent = joypad();

        // Check if right d-pad is held down
        if(joypadCurrent & J_RIGHT){
            velocityX = 1;

        // Check if left d-pad is held down
        }else if(joypadCurrent & J_LEFT){
            velocityX = -1;
        
        // Set velocity to 0 if no buttin held down
        }else{
            velocityX = 0;
        }

        // Check if A button is pressed
        if((joypadCurrent & J_A) && !(joypadPrevious & J_A)){

            // Play a sound on channel 1
            NR10_REG=0X00;
            NR11_REG=0X81;
            NR12_REG=0X43;
            NR13_REG=0X73;
            NR14_REG=0X86;

            spriteY += 8;
        }

        // Check if B button is pressed
        if((joypadCurrent & J_B) && !(joypadPrevious & J_B)){

            // Play a sound on channel 1
            NR10_REG=0X00;
            NR11_REG=0X81;
            NR12_REG=0X43;
            NR13_REG=0X73;
            NR14_REG=0X86;

            spriteY -= 8;
        }

        // Apply velocity
        spriteX += velocityX;
        spriteY += velocityY;

        // Position the first sprite at our spriteX and spriteY
        // All sprites are render 8 pixels to the left of their x position and 16 pixels ABOVE their actual y position
        // This means an object rendered at 0,0 will not be visible
        // x+5 and y+12 will center the 8x8 tile at our x and y position
        move_sprite(0, spriteX + 4, spriteY + 12);

        // Done processing, yield CPU and wait for start of next frame
        wait_vbl_done();
    }
}
