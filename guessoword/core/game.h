#ifndef GAME_H
#define GAME_H

#include "game_status.h"

class Game
{
public:
    Game() {}
    ~Game() {}

    GameStatus gameStatus = GameStatus();

    int handleKeyPress(const QString &keyText);
    int handleEnter(); // 0: do nothing, 1: word not valid, 2: word valid then enter
    int handleBackspace();

    QStringList getValidWords();
    void resetGame();
    

private:
    void _cmpWord();
    int _isValidWord(); // 1: not valid, 2: valid
    
};

#endif // GAME_H
