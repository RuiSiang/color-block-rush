#ifndef DEFENDER_H_INCLUDED
#define DEFENDER_H_INCLUDED
class defender
{
public:
    int x, y;
    defender() {};
    void initialize(void);
    void up();
    void down();
    void left();
    void right();
    void ai_move();
private:
};

#endif // DEFENDER_H_INCLUDED
