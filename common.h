#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED
#include<SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_mixer.h>
//#include<SDL2/SDL_ttf.h>
#include<graphics.h>
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<string>
#include"attacker.h"
#include"defender.h"
#include"map.h"
//#include"notify.h"
#include"winner.h"
#include"ai.h"
#include"LTexture.h"
extern int map_selection;
extern int attacker_control, defender_control;
extern bool bomb_mode, poison_mode;
extern map m;
//extern notify note;
extern bool legal_move;//don't alter
extern bool ended;//don't alter
extern SDL_Window* gWindow;
extern SDL_Renderer* gRenderer;
extern attacker _attacker;
extern defender _defender;
extern LTexture gmenuTexture[5];
extern LTexture aoptionTexture[3];
extern LTexture doptionTexture[3];
extern LTexture boptionTexture[2];
extern LTexture poptionTexture[2];
extern LTexture gnoticeTexture[7];
extern LTexture gspaceTexture;
extern LTexture gattackerTexture;
extern LTexture gdefenderTexture;
extern LTexture gobs1Texture;
extern LTexture gobs2Texture;
extern LTexture gobs3Texture;
extern LTexture gbombTexture;
extern LTexture gpoisonTexture;
extern LTexture gattrangeTexture;
extern LTexture check;
extern LTexture uncheck;
extern LTexture rules;
extern LTexture bombtexture;
extern LTexture poisontexture;
#endif // COMMON_H_INCLUDED
