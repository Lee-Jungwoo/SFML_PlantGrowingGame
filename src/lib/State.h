#ifndef STATE_H
#define STATE_H

enum class Stage
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
