#include "application.h"

Application::Application()
    : m_WindowContext("My Application", 800, 600),
    m_CurrentScreen{std::make_unique<StartScreen>()}
{
}

void Application::Run()
{
    while (m_WindowContext.IsOpen()) // Detect window close button or ESC key
    {
        Update();
        Draw();
    }
}

void Application::Update()
{
    m_WindowContext.SetTitle(FormatTitle());

    m_CurrentScreen->Update();
    
    if (m_CurrentScreen->IsFinished())
    {
        m_CurrentScreen = m_CurrentScreen->GetNextScreen();
    }
}

void Application::Draw()
{
    m_WindowContext.BeginDrawing();
        m_WindowContext.ClearBackground(RAYWHITE);
        m_CurrentScreen->Draw();
    m_WindowContext.EndDrawing();
}

Application::~Application()
{
}

const std::string Application::FormatTitle() const
{
    return m_WindowContext.GetTitle() + " - FPS: " + std::to_string(m_WindowContext.GetCurrentFPS());
}
