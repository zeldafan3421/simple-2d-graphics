#pragma once

#include "raylib.h"
#include "../interfaces/screen.h"

class StartScreen : public Screen
{
public:
    StartScreen();

    virtual void Update();
    virtual void Draw();

    ~StartScreen();
private:
};