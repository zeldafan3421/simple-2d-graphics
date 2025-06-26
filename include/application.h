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
private:
    using ScreenPtr = std::unique_ptr<Screen>;

    template <std::size_t T>
    using ScreenArray = std::array<ScreenPtr, T>;

    constexpr static std::size_t c_ScreenCount = 2;
    
public:
    Application();

    void Run();
    void Update();
    void Draw();

    ~Application();

private:
    Screen& GetCurrentScreen();
    const std::string FormatTitle() const;

private:
    WindowContext m_WindowContext;
    std::size_t m_CurrentScreenIndex;   

    ScreenArray<c_ScreenCount> m_Screens;
};