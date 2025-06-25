#pragma once

#include "../interfaces/screen.h"

class NullScreen : public Screen
{
public:
    NullScreen() : Screen() {}

    virtual void Update() {}
    virtual void Draw() {}
};