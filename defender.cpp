#include"common.h"
#include<algorithm>
//#include<iostream>
void def_calc(void);
void defender::initialize(void)
{
	x=rand() % 18;
	y=rand() % 18;
	if(!m.istrapped(x, y)){
		x=0;
		y=0;
	}
	legal_move=1;
}
void defender::up(void)
{
    if(m.istrapped(x,y-1)) {
        y--;
        legal_move=1;
    }
}
void defender::down(void)
{
    if(m.istrapped(x,y+1)) {
        y++;
        legal_move=1;
    }
}
void defender::left(void)
{
    if(m.istrapped(x-1,y)) {
        x--;
        legal_move=1;
    }
}
void defender::right(void)
{
    if(m.istrapped(x+1,y)) {
        x++;
        legal_move=1;
    }
}
void defender::ai_move(void)
{

    int d_move[4][2]= {{0,-1 },{0,1 },{-1,0 },{1,0 } };
    int current_maximum=-1;
    int current_index=-1;
    int temp;
    for(int i=0; i<4; i++) {
        if(m.istrapped(_defender.x+d_move[i][0], _defender.y+d_move[i][1])) {
            temp=get_distance(_defender.x+d_move[i][0], _defender.y+d_move[i][1], _attacker.x, _attacker.y);
            //std::cout<<temp<<"\n";
            current_maximum=std::max(current_maximum, temp);
            if(temp==current_maximum) {
                current_index=i;
            }
        }
    }
    if(current_index==-1) {
        int random_selection;
        while(true) {
            random_selection=rand()%4;
            if(m.istrapped(_defender.x+d_move[random_selection][0], _defender.y+d_move[random_selection][1])) {
                _defender.x+=d_move[random_selection][0];
                _defender.y+=d_move[random_selection][1];
                break;
            }
        }

    } else {
        _defender.x+=d_move[current_index][0];
        _defender.y+=d_move[current_index][1];
    }
}
