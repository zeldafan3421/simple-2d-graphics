#include "application.h"

Application::Application()
    : m_WindowContext("My Application", 800, 600),
    m_CurrentScreenIndex(Screen::Index::Start),
    m_Screens()
{
    m_Screens[Screen::Index::Start] = std::make_unique<StartScreen>();
    m_Screens[Screen::Index::Null] = std::make_unique<NullScreen>();
}

void Application::Run()
{
    while (m_WindowContext.IsOpen())
    {
        Update();
        Draw();
    }
}

void Application::Update()
{
    m_WindowContext.SetTitle(FormatTitle());

    GetCurrentScreen().Update();

    if (GetCurrentScreen().IsFinished())
        m_CurrentScreenIndex++;
}

void Application::Draw()
{
    m_WindowContext.BeginDrawing();
        m_WindowContext.ClearBackground(RAYWHITE);
        GetCurrentScreen().Draw();
    m_WindowContext.EndDrawing();
}

Application::~Application()
{
}

Screen& Application::GetCurrentScreen()
{
    return *m_Screens[m_CurrentScreenIndex];
}

const std::string Application::FormatTitle() const
{
    return m_WindowContext.GetTitle() + " - FPS: " + std::to_string(m_WindowContext.GetCurrentFPS());
}
