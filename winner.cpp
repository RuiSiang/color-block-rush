#include"common.h"
#include<iostream>
void winner_is(int who_won)
{
    if(who_won==1) {
        //attacker won;
        if(attacker_control==0) {
            //AI won
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,"Winner","Attacker: AI won!!!!!",NULL);
        } else if(attacker_control==1) {
            //player 1 won
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,"Winner","Attacker: Player won!!!!!",NULL);
        }
    } else if(who_won==2) {
        //defender won;
        if(defender_control==0) {
            //AI won
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,"Winner","Defender: AI won!!!!!",NULL);
        } else if(defender_control==2) {
            //player 2 won
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,"Winner","Defender: Player won!!!!!",NULL);
        }
    } else if(who_won==3) {
        //defender won;
        if(defender_control==0) {
            //AI won
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,"Winner","Defender: AI won!!\n Attacker failed to eliminate Defender within 80 rounds",NULL);
        } else if(defender_control==2) {
            //player 2 won
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,"Winner","Defender: Player won!!\n Attacker failed to eliminate Defender within 80 rounds",NULL);
        }
    } else if(who_won==4) {
        if(defender_control==0) {
            //AI won
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,"Winner","Defender: AI won!!\n Hope you get luckier next time, Attacker.",NULL);
        } else {
            //player 1 won
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,"Winner","Defender: Player won!!\n Hope you get luckier next time, Attacker.",NULL);
        }
    }
}

