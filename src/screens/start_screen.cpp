#include "screens/start_screen.h"

StartScreen::StartScreen()
    : Screen()
{
}

void StartScreen::Update()
{
    if (IsKeyPressed(KEY_ENTER))
    {
        SetFinished(true);
    }
}

void StartScreen::Draw()
{
    DrawText("Press enter.", 10, 10, 20, BLACK);
}

StartScreen::~StartScreen()
{
    TraceLog(LOG_DEBUG, "Unloading start screen.");
}