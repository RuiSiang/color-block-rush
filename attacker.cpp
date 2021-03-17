#include"common.h"
#include<algorithm>
//#include<iostream>
void attacker::initialize(void)
{
	x=rand() % 18;
	y=rand() % 18;
	while(!m.islegal(x, y)){
		x=17;
		y=17;
	}
	legal_move=1;
}
void attacker::up()
{
    if(m.islegal(x,y-1)) {
        y--;
        legal_move=1;
    }
}
void attacker::down()
{
    if(m.islegal(x,y+1)) {
        y++;
        legal_move=1;
    }
}
void attacker::left()
{
    if(m.islegal(x-1,y)) {
        x--;
        legal_move=1;
    }
}
void attacker::right()
{
    if(m.islegal(x+1,y)) {
        x++;
        legal_move=1;
    }
}
void attacker::ai_move(void)
{
    int a_move[4][2]= {{0,-1 },{0,1 },{-1,0 },{1,0 } };
    int current_minimum=2147483647;
    int current_index=-1;
    int temp;
    for(int i=0; i<4; i++) {
        if(m.islegal(_attacker.x+a_move[i][0], _attacker.y+a_move[i][1])) {
            temp=get_distance(_attacker.x+a_move[i][0], _attacker.y+a_move[i][1], _defender.x, _defender.y);
            //std::cout<<temp<<"\n";
            current_minimum=std::min(current_minimum, temp);
            if(temp==current_minimum) {
                current_index=i;
            }
        }
    }
    _attacker.x+=a_move[current_index][0];
    _attacker.y+=a_move[current_index][1];
}
