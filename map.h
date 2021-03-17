#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED
class map
{
public:
    int array[18][18]= {{0}};
    void initialize();
    void set_bomb();
    void set_poison();
    bool islegal(int, int);
    void operator+();//intergrate_player
    bool check_win();
    bool istrapped(int, int);
private:

};
#endif // MAP_H_INCLUDED
