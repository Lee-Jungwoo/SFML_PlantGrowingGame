#ifndef STATE_H
#define STATE_H

enum class stage
{
    A,
    B,
    C,
    D
};

class GameState
{
private:
    int day;

public:
    void update();
};

#endif
