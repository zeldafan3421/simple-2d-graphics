#pragma once

#include "raylib.h"
#include "context/window_context.h"
#include "interfaces/screen.h"
#include "screens/start_screen.h"
#include <string>
#include <memory>

class Application
{
public:
    Application();

    void Run();
    void Update();
    void Draw();

    ~Application();

private:

    const std::string FormatTitle() const;

    WindowContext m_WindowContext;
    std::unique_ptr<Screen> m_CurrentScreen;
};