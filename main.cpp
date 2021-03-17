#include"common.h"
//#include<iostream>
int map_selection;
int mode_selection;
int notice_selection;
int attacker_control, defender_control;
int rounds;
bool bomb_mode, poison_mode;
bool legal_move;
bool ended;
bool notice_updated=0;
map m;
//notify note;
attacker _attacker;
defender _defender;
/********************************/
const int SCREEN_WIDTH = 960;
const int SCREEN_HEIGHT = 720;
bool init();
bool loadMedia_menu();
void loadMedia_game();
void maingame();
void show();
void close();
Mix_Music *gMusic_menu = NULL;
Mix_Music *gMusic_game = NULL;
SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
LTexture gmenuTexture[5];
LTexture aoptionTexture[3];
LTexture doptionTexture[3];
LTexture boptionTexture[2];
LTexture poptionTexture[2];
LTexture gnoticeTexture[7];
LTexture gspaceTexture;
LTexture gattackerTexture;
LTexture gdefenderTexture;
LTexture gobs1Texture;
LTexture gobs2Texture;
LTexture gobs3Texture;
LTexture gbombTexture;
LTexture gpoisonTexture;
LTexture gattrangeTexture;
LTexture check;
LTexture uncheck;
LTexture rules;
LTexture bombtexture;
LTexture poisontexture;
/**********************************/
int getkey(void)
{
    SDL_Event e;
    SDL_WaitEvent(&e);
    while(e.type!=SDL_KEYDOWN) {
        SDL_WaitEvent(&e);
    }
    if(e.type==SDL_KEYDOWN) {
        switch( e.key.keysym.sym ) {
        case SDLK_w:
            return 0;
            break;
        case SDLK_s:
            return 1;
            break;
        case SDLK_a:
            return 2;
            break;
        case SDLK_d:
            return 3;
            break;
        case SDLK_o:
            return 4;
            break;
        case SDLK_l:
            return 5;
            break;
        case SDLK_k:
            return 6;
            break;
        case SDLK_SEMICOLON:
            return 7;
            break;
        case SDLK_UP:
            return 8;
            break;
        case SDLK_DOWN:
            return 9;
            break;
        case SDLK_LEFT:
            return 10;
            break;
        case SDLK_RIGHT:
            return 11;
            break;
        case SDLK_h:
            return 12;
            break;
        case SDLK_ESCAPE:
            return 12;
            break;
        default:
            return -1;
        }
    }
}
void printscr(void)
{
   +m;
    static int i=0;
    if(i>=5&&notice_updated) {
        i=0;
        gnoticeTexture[4].render(720,560,240,160);
        gnoticeTexture[notice_selection].render(720,560+32*i,240,32);
        i++;
        notice_updated=0;
    } else if(notice_updated) {
        gnoticeTexture[notice_selection].render(720,560+32*i,240,32);
        i++;
        notice_updated=0;
    }
    SDL_RenderPresent( gRenderer );
}
void menu(void)
{
    map_selection=1;
    attacker_control=1;
    defender_control=2;
    SDL_Event p;
    bool _q=false;
    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear( gRenderer );
    rules.render(0,0,960,720);
    SDL_RenderPresent( gRenderer );
    while( !_q ) {
        SDL_WaitEvent(&p);
        while(p.type!=SDL_KEYDOWN) {
            SDL_WaitEvent(&p);
        }

        if( p.type == SDL_QUIT ) {
            _q = true;
        } else {
            switch(p.key.keysym.sym) {
            case SDLK_SPACE:
                _q=true;
                break;
            }
        }
    }
    bool quit = false;
    SDL_Event e;
    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear( gRenderer );
    gmenuTexture[1].render(0,0,960,720);
    SDL_RenderPresent( gRenderer );
    while( !quit ) {
        SDL_WaitEvent(&e);
        while(e.type!=SDL_KEYDOWN) {
            SDL_WaitEvent(&e);
        }
        if( e.type == SDL_QUIT ) {
            quit = true;
        } else {
            switch(e.key.keysym.sym) {
            case SDLK_1:
                if(attacker_control==1) {
                    attacker_control=0;
                    check.render(169,217,160,160);
                } else {
                    attacker_control=1;
                    uncheck.render(169,217,160,160);
                }
                SDL_RenderPresent( gRenderer );
                break;
            case SDLK_2:
                if(defender_control==2) {
                    defender_control=0;
                    check.render(591,217,160,160);
                } else {
                    defender_control=2;
                    uncheck.render(591,217,160,160);
                }
                SDL_RenderPresent( gRenderer );
                break;
            case SDLK_SPACE:
                quit=true;
                break;
            }
        }
    }
    bool Quit=false;
    SDL_Event f;
    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear( gRenderer );
    gmenuTexture[2].render(0,0,960,720);
    SDL_RenderPresent( gRenderer );
    while( !Quit ) {
        SDL_WaitEvent(&f);
        while(f.type!=SDL_KEYDOWN) {
            SDL_WaitEvent(&f);
        }
        if( f.type == SDL_QUIT ) {
            Quit = true;
        } else {
            switch(f.key.keysym.sym) {
            case SDLK_0:
                map_selection=rand()%5+1;
                Quit=true;
                break;
            case SDLK_1:
                map_selection=1;
                Quit=true;
                break;
            case SDLK_2:
                map_selection=2;
                Quit=true;
                break;
            case SDLK_3:
                map_selection=3;
                Quit=true;
                break;
            case SDLK_4:
                map_selection=4;
                Quit=true;
                break;
            case SDLK_5:
                map_selection=5;
                Quit=true;
                break;
            case SDLK_6:
                map_selection=6;
                Quit=true;
                break;
            }
        }
    }
    bool Q=false;
    SDL_Event i;
    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear( gRenderer );
    gmenuTexture[4].render(0,0,960,720);
    SDL_RenderPresent( gRenderer );
    while( !Q ) {
        SDL_WaitEvent(&i);
        while(i.type!=SDL_KEYDOWN) {
            SDL_WaitEvent(&i);
        }
        if(i.type == SDL_QUIT ) {
            Q = true;
        } else {
            switch(i.key.keysym.sym) {
            case SDLK_7:
                mode_selection=1;
                bomb_mode=1;
                poison_mode=0;
                Q=true;
                break;
            case SDLK_8:
                mode_selection=2;
                bomb_mode=0;
                poison_mode=1;
                Q=true;
                break;
            case SDLK_9:
                mode_selection=3;
                bomb_mode=1;
                poison_mode=1;
                Q=true;
                break;
            case SDLK_0:
                mode_selection=0;
                bomb_mode=0;
                poison_mode=0;
                Q=true;
                break;
            }
        }

    }
    SDL_Event g;
    bool q=false;
    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear( gRenderer );
    gmenuTexture[3].render(0,0,960,720);
    SDL_RenderPresent( gRenderer );
    while( !q ) {
        SDL_WaitEvent(&g);
        while(g.type!=SDL_KEYDOWN) {
            SDL_WaitEvent(&g);
        }

        if( g.type == SDL_QUIT ) {
            q = true;
        } else {
            switch(g.key.keysym.sym) {
            case SDLK_SPACE:
                q=true;
                break;
            }
        }
    }
    Mix_HaltMusic();
    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear( gRenderer );
}
void game(void)
{
    ended=0;
    rounds=0;
    m.initialize();
    _attacker.initialize();
    _defender.initialize();
    +m;
    loadMedia_game();
    show();
    gnoticeTexture[4].render(720,560,240,160);
    Mix_PlayMusic( gMusic_game, -1 );
    SDL_Event e;
    bool quit=0;
    while(rounds<=80&&!ended) {
        if(attacker_control==1) {
            notice_selection=0;
            notice_updated=true;
        } else if(attacker_control==2) {
            notice_selection=1;
            notice_updated=true;
        }
        printscr();
        if(rounds==80) {
            winner_is(3);
            break;
        } else {
            int current_key;
            legal_move=0;
            if(attacker_control==0) {
                SDL_Delay(600);
                _attacker.ai_move();
            } else {
                while(!legal_move) {
                    current_key=getkey();
                    if(attacker_control==1) {
                        switch(current_key) {
                        case 0:
                            _attacker.up();
                            if(legal_move==0) {
                                notice_selection=2;
                                notice_updated=true;
                                printscr();
                            }
                            break;
                        case 1:
                            _attacker.down();
                            if(legal_move==0) {
                                notice_selection=2;
                                notice_updated=true;
                                printscr();
                            }
                            break;
                        case 2:
                            _attacker.left();
                            if(legal_move==0) {
                                notice_selection=2;
                                notice_updated=true;
                                printscr();
                            }
                            break;
                        case 3:
                            _attacker.right();
                            if(legal_move==0) {
                                notice_selection=2;
                                notice_updated=true;
                                printscr();
                            }
                            break;
                        case 12:
                            goto END;
                        default:
                            notice_selection=2;
                            notice_updated=true;
                            printscr();
                            break;
                        }
                    } else if(attacker_control==2) {
                        switch(current_key) {
                        case 4:
                            _attacker.up();
                            break;
                        case 5:
                            _attacker.down();
                            break;
                        case 6:
                            _attacker.left();
                            break;
                        case 7:
                            _attacker.right();
                            break;
                        case 12:
                            goto END;
                        default:
                            notice_selection=3;
                            notice_updated=true;
                            printscr();
                            break;
                        }
                    }
                }
            }
           +m;
            show();
            ended=m.check_win();
            if(ended) {
                break;
            }
            if(defender_control==1) {
                notice_selection=0;
                notice_updated=true;
            } else if(defender_control==2) {
                notice_selection=1;
                notice_updated=true;
            }
            printscr();
            legal_move=0;
            if(defender_control==0) {
                SDL_Delay(600);
                _defender.ai_move();
            } else {
                while(!legal_move) {
                    current_key=getkey();
                    if(defender_control==1) {
                        switch(current_key) {
                        case 0:
                            _defender.up();
                            break;
                        case 1:
                            _defender.down();
                            break;
                        case 2:
                            _defender.left();
                            break;
                        case 3:
                            _defender.right();
                            break;
                        case 12:
                            goto END;
                        default:
                            notice_selection=2;
                            notice_updated=true;
                            printscr();
                            break;
                        }
                    } else if(defender_control==2) {
                        switch(current_key) {
                        case 4:
                            _defender.up();
                            if(legal_move==0) {
                                notice_selection=3;
                                notice_updated=true;
                                printscr();
                            }
                            break;
                        case 5:
                            _defender.down();
                            if(legal_move==0) {
                                notice_selection=3;
                                notice_updated=true;
                                printscr();
                            }
                            break;
                        case 6:
                            _defender.left();
                            if(legal_move==0) {
                                notice_selection=3;
                                notice_updated=true;
                                printscr();
                            }
                            break;
                        case 7:
                            _defender.right();
                            if(legal_move==0) {
                                notice_selection=3;
                                notice_updated=true;
                                printscr();
                            }
                            break;
                        case 12:
                            goto END;
                        default:
                            notice_selection=3;
                            notice_updated=true;
                            printscr();
                            break;
                        }
                    }
                }
            }

            if((rounds%7==0)&&poison_mode) {
                m.set_poison();
                notice_selection=6;
                notice_updated=true;
                printscr();
            }
            if(bomb_mode&&(rounds%3==0)) {
                m.set_bomb();
                notice_selection=5;
                notice_updated=true;
                printscr();
            }
            +m;
            show();
            ended=m.check_win();
        }
        rounds++;
    }
END:
    Mix_HaltMusic();
    return;
}
bool init()
{
    bool success = true;
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    } else {
        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) ) {
            printf( "Warning: Linear texture filtering not enabled!" );
        }
        gWindow = SDL_CreateWindow( "", SDL_WINDOWPOS_CENTERED, 0, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_BORDERLESS );
        if( gWindow == NULL ) {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        } else {
            gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
            if( gRenderer == NULL ) {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            } else {
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
                int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) ) {
                    printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                    success = false;
                }else{
                if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
				else{
                        if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
                    {
                        printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
                        success = false;
                    }
                }
                }
            }
        }
    }

    return success;
}
void loadMedia_game()
{
    gnoticeTexture[0].loadFromFile("images/p1turn.png");
    gnoticeTexture[1].loadFromFile("images/p2turn.png");
    gnoticeTexture[2].loadFromFile("images/p1illkey.png");
    gnoticeTexture[3].loadFromFile("images/p2illkey.png");
    gnoticeTexture[4].loadFromFile("images/blank_notice.png");
    gnoticeTexture[5].loadFromFile("images/bomb_notice.png");
    gnoticeTexture[6].loadFromFile("images/poison_notice.png");
    gspaceTexture.loadFromFile("images/space.png");
    gattackerTexture.loadFromFile("images/attacker.png");
    gdefenderTexture.loadFromFile("images/defender.png");
    gobs1Texture.loadFromFile("images/obs1.png");
    gobs2Texture.loadFromFile("images/obs2.png");
    gobs3Texture.loadFromFile("images/obs3.png");
    getwidth(gobs1Texture);
    getwidth(gobs2Texture);
    getwidth(gobs3Texture);
    getheight(gobs1Texture);
    getheight(gobs2Texture);
    getheight(gobs3Texture);
    gattrangeTexture.loadFromFile("images/attacker_range.png");
    bombtexture.loadFromFile("images/bomb.png");
    poisontexture.loadFromFile("images/poison.png");
    gMusic_game=Mix_LoadMUS("musics/Sabor_Moreno.wav");

}
bool loadMedia_menu()
{
    bool success = true;
    if( !gmenuTexture[0].loadFromFile( "images/sam_menu.png" ) ) {
        !gmenuTexture[0];
        success = false;
    }
    if( !gmenuTexture[1].loadFromFile( "images/sam_choose.png" ) ) {
       !gmenuTexture[1];
        success = false;
    }
    if( !gmenuTexture[2].loadFromFile( "images/sam_mapchoose.png" ) ) {
        !gmenuTexture[2];
        success = false;
    }
    if( !gmenuTexture[3].loadFromFile( "images/sam_key.png" ) ) {
        !gmenuTexture[3];
        success = false;
    }
    if( !gmenuTexture[4].loadFromFile( "images/sam_mode.png" ) ) {
        !gmenuTexture[3];
        success = false;
    }
    aoptionTexture[0].loadFromFile("images/a0.png");
    aoptionTexture[1].loadFromFile("images/a1.png");
    aoptionTexture[2].loadFromFile("images/a2.png");
    doptionTexture[0].loadFromFile("images/d0.png");
    doptionTexture[1].loadFromFile("images/d1.png");
    doptionTexture[2].loadFromFile("images/d2.png");
    boptionTexture[0].loadFromFile("images/b0.png");
    boptionTexture[1].loadFromFile("images/b1.png");
    poptionTexture[0].loadFromFile("images/p0.png");
    poptionTexture[1].loadFromFile("images/p1.png");
    check.loadFromFile("images/check.png");
    uncheck.loadFromFile("images/uncheck.png");
    rules.loadFromFile("images/rules.png");
    gMusic_menu = Mix_LoadMUS( "musics/8_Bit_Dreamscape.wav" );
     printf( "Picture number=%d\n",LTexture::loadnum );
    return success;
}
void close()
{
    -gspaceTexture;
    -gattackerTexture;
    -gdefenderTexture;
    -gobs1Texture;
    -gobs2Texture;
    -gobs3Texture;
    -gbombTexture;
    -gpoisonTexture;
    -gattrangeTexture;
    -check;
    -uncheck;
    -rules;
    -poisontexture;
    -bombtexture;
    Mix_FreeMusic( gMusic_menu );
    Mix_FreeMusic( gMusic_game );
    for(int i=0; i<3; i++) {
        -aoptionTexture[i];
    }
    for(int i=0; i<3; i++) {
        -doptionTexture[i];
    }
    for(int i=0; i<2; i++) {
        -boptionTexture[i];
    }
    for(int i=0; i<2; i++) {
        -poptionTexture[i];
    }
    for(int i=0; i<7; i++) {
        -gnoticeTexture[i];
    }
    for (int i=0; i<4; i++) {
        -gmenuTexture[i];
    }
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gMusic_menu = NULL;
    gMusic_game = NULL;
    gWindow = NULL;
    gRenderer = NULL;
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
}
void show()
{
    /********************************************************************************/
    for(int p=0; p<18; p++) {
        for(int q=0; q<18; q++) {
            if(m.array[p][q]==0) {
                gspaceTexture.render(40*p,40*q,40,40);
            }
            if(m.array[p][q]==1) {
                gattackerTexture.render(40*p,40*q,40,40);
            }
            if(m.array[p][q]==2) {
                gdefenderTexture.render(40*p,40*q,40,40);
            }
            if(m.array[p][q]==3) {
                gobs1Texture.render(40*p,40*q,40,40);
            }
            if(m.array[p][q]==4) {
                gobs2Texture.render(40*p,40*q,40,40);
            }
            if(m.array[p][q]==5) {
                gobs3Texture.render(40*p,40*q,40,40);
            }
            if(m.array[p][q]==6) {
                bombtexture.render(40*p,40*q,40,40);
            }
            if(m.array[p][q]==7) {
                poisontexture.render(40*p,40*q,40,40);
            }
            if(m.array[p][q]==8) {
                gattrangeTexture.render(40*p,40*q,40,40);
            }
        }
    }
    /**********************************************************************************/
    aoptionTexture[attacker_control].render(720,0,240,140);
    doptionTexture[defender_control].render(720,140,240,140);
    boptionTexture[bomb_mode].render(720,280,240,140);
    poptionTexture[poison_mode].render(720,420,240,140);
    SDL_RenderPresent( gRenderer );
}
int main(int argc, char* argv[])
{
    if( !init() ) {
        printf( "Failed to initialize!\n" );
    } else {
        if( !loadMedia_menu() ) {
            printf( "Failed to load media!\n" );
        } else {
            bool quit = false;
            SDL_Event e;
            SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
            SDL_RenderClear( gRenderer );
            gmenuTexture[0].render(0,0,960,720);
            SDL_RenderPresent( gRenderer );
            Mix_PlayMusic( gMusic_menu, -1 );
            int i=0;
            while( !quit ) {
                here:
                SDL_WaitEvent(&e);
                while(e.type!=SDL_KEYDOWN) {
                    SDL_WaitEvent(&e);
                }
                if( e.type == SDL_QUIT ) {
                    quit = true;
                } else  if(e.type==SDL_KEYDOWN) {
                    /*SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
                    SDL_RenderClear( gRenderer );*/
                    if(e.key.keysym.sym==SDLK_ESCAPE) {
                        quit=1;
                    } else if(e.key.keysym.sym==SDLK_SPACE) {
                        menu();
                        game();
                        gmenuTexture[0].render(0,0,960,720);
                        Mix_PlayMusic(gMusic_menu,-1);
                    }else if(e.key.keysym.sym==SDLK_c){SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,"Credits","Made and brought to you by\nb08201007\nb08901001\nb08201042",NULL);}
                    else {
                        goto here;
                    }
                }
                SDL_RenderPresent( gRenderer );
            }
        }
    }
    close();
    return 0;
}
