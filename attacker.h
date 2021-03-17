#ifndef ATTACKER_H_INCLUDED
#define ATTACKER_H_INCLUDED
class attacker
{
public:
    int x, y;
    attacker() {};
    void initialize(void);
    void up();
    void down();
    void left();
    void right();
    void ai_move();
private:
};

#endif // ATTACKER_H_INCLUDED
