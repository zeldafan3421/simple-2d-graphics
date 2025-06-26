#pragma once

#include "raylib.h"
#include "context/window_context.h"
#include "interfaces/screen.h"
#include "screens/start_screen.h"
#include <string>
#include <memory>
#include <array>
#include <typeinfo>
#include <functional>
#include <utility>

class Application
{
public:
    using ScreenPtr = std::unique_ptr<Screen>;

    Application();

    void Run();
    void Update();
    void Draw();

    ~Application();

private:
    Screen& GetCurrentScreen();

    const std::string FormatTitle() const;

    WindowContext m_WindowContext;
    int m_CurrentScreenIndex;   

    constexpr static int c_ScreenCount = 2;
    std::array<ScreenPtr, c_ScreenCount> m_Screens;
};