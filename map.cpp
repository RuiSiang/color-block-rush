#include"common.h"
#include<fstream>
//#include<iostream>
void map::initialize(void)
{
    std::string str_map_line;
    std::string map_file_name;
    map_file_name="./maps/default_";
    map_file_name.push_back(map_selection+'0');
    map_file_name+=".txt";
    //std::cout<<map_file_name<<"\n";
    std::ifstream fin;
    fin.open(map_file_name.c_str());
    int j=0;
    while(fin>>str_map_line) {
        //std::cout<<str_map_line<<"\n";
        for(int i=0; i<18; i++) {
            m.array[i][j]=str_map_line[i]-'0';
        }
        j++;
    }
    fin.close();
}
void map::set_bomb()
{
    int randx, randy;
    for(int i=0; i<18; i++) {
        for(int j=0; j<18; j++) {
            if(array[i][j]==6) {
                array[i][j]=0;
            }
        }
    }
    for(int l=0; l<5; l++) {
        randx=rand()%18;
        randy=rand()%18;
        while(!islegal(randx, randy)) {
            randx=rand()%18;
            randy=rand()%18;
        }
        array[randx][randy]=6;
    }
}
void map::set_poison()
{
    int randx, randy, randr;
    int tempx, tempy, tempr;
    for(int i=0; i<18; i++) {
        for(int j=0; j<18; j++) {
            if(array[i][j]==7) {
                array[i][j]=0;
            }
        }
    }
    for(int l=0; l<2; l++) {
        randx=rand()%18;
        randy=rand()%18;
        randr=rand()%10+10;
        while(!islegal(randx, randy)) {
            randx=rand()%18;
            randy=rand()%18;
        }
        tempr=0;
        tempx=randx;
        tempy=randy;
        int randdir[5][2]= {{0,-1 },{0,1 },{-1,0 },{1,0 },{0,0} };
        while(tempr<=randr&&islegal(tempx, tempy)) {
            int rnd;
            rnd=rand()%4;
            int justincase=0;
            while(!islegal(tempx+randdir[rnd][0], tempy+randdir[rnd][1])&&justincase<20) {
                rnd=rand()%4;
                if(justincase==19) {
                    rnd=5;
                }
                justincase++;
            }
            array[tempx][tempy]=7;
            tempx+=randdir[rnd][0];
            tempy+=randdir[rnd][1];
            tempr++;
        }
    }
}
bool map::islegal(int x,int y)
{
    if(x<0||x>17||y<0||y>17) {
        return 0;
    }
    if(m.array[x][y]!=0&&m.array[x][y]!=8) {
        return 0;
    }
    return 1;
}
void map::operator+()
{
    for(int i=0; i<18; i++) {
        for(int j=0; j<18; j++)
            if(array[i][j]==1||array[i][j]==2||array[i][j]==8) {
                array[i][j] = 0;
            }
    }
    array[_attacker.x][_attacker.y] = 1;
    array[_defender.x][_defender.y] = 2;

    int x_up=_attacker.x-1;
    int y_up=_attacker.y;
    while(x_up>=0&&(array[x_up][y_up]==0||array[x_up][y_up]==2)) { //¤W
        if(array[x_up][y_up]==0) {
            array[x_up][y_up]=8;
            x_up--;
        } else if(array[x_up][y_up]==2) {
            x_up--;
        } else {
            break;
        }
    }
    int x_down=_attacker.x+1;
    int y_down=_attacker.y;
    while(x_down<=17&&(array[x_down][y_down]==0||array[x_down][y_down]==2)) { //¤U
        if(array[x_down][y_down]==0) {
            array[x_down][y_down]=8;
            x_down++;
        } else if(array[x_down][y_down]==2) {
            x_down++;
        } else {
            break;
        }
    }
    int x_left=_attacker.x;
    int y_left=_attacker.y-1;
    while(y_left>=0&&(array[x_left][y_left]==0||array[x_left][y_left]==2)) { //¥ª
        if(array[x_left][y_left]==0) {
            array[x_left][y_left]=8;
            y_left--;
        } else if(array[x_left][y_left]==2) {
            y_left--;
        } else {
            break;
        }
    }
    int x_right=_attacker.x;
    int y_right=_attacker.y+1;
    while(y_right<=17&&(array[x_right][y_right]==0||array[x_right][y_right]==2)) { //¥k
        if(array[x_right][y_right]==0) {
            array[x_right][y_right]=8;
            y_right++;
        } else if(array[x_right][y_right]==2) {
            y_right++;
        } else {
            break;
        }
    }
}
bool map::check_win()
{
    if(islegal(_attacker.x, _attacker.y+1)==0&&islegal(_attacker.x, _attacker.y-1)==0&&islegal(_attacker.x+1, _attacker.y)==0&&islegal(_attacker.x-1, _attacker.y)==0) {
        winner_is(4);
        return 1;
    } else if(istrapped(_defender.x, _defender.y+1)==0&&istrapped(_defender.x, _defender.y-1)==0&&istrapped(_defender.x+1, _defender.y)==0&&istrapped(_defender.x-1, _defender.y)==0) {
        winner_is(1);
        return 1;
    } else {
        return 0;
    }
}
bool map::istrapped(int x, int y)
{
    +m;
    bool valid=1;
    if(x<0||x>17||y<0||y>17) {
        return 0;
    }
    if(m.array[x][y]!=0) {
        return 0;
    }
    return 1;
}
