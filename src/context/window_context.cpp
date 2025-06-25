#include "context/window_context.h"

WindowContext::WindowContext(const std::string &_title, int _width, int _height)
    : m_Title(_title), m_Width(_width), m_Height(_height)
{
    InitWindow(m_Width, m_Height, m_Title.c_str());
}

int WindowContext::GetWidth() const
{
    return m_Width;
}

int WindowContext::GetTargetFPS() const
{
    return m_TargetFPS;
}

int WindowContext::GetCurrentFPS() const
{
    return GetFPS();
}

int WindowContext::GetHeight() const
{
    return m_Height;
}

const std::string &WindowContext::GetTitle() const
{
    return m_Title;
}

void WindowContext::SetWidth(int _width)
{
    m_Width = _width;
    SetWindowSize(m_Width, m_Height);
}

void WindowContext::SetHeight(int _height)
{
    m_Height = _height;
    SetWindowSize(m_Width, m_Height);
}

void WindowContext::SetTitle(const std::string &_title)
{
    SetWindowTitle(_title.c_str());
}

bool WindowContext::IsOpen() const
{
    return !WindowShouldClose();
}

bool WindowContext::IsReady() const
{
    return IsWindowReady();
}

void WindowContext::BeginDrawing() const
{
    ::BeginDrawing();
}

void WindowContext::EndDrawing() const
{
    ::EndDrawing();
}

void WindowContext::ClearBackground(const Color &color) const
{
    ::ClearBackground(color);
}

void WindowContext::SetTargetFPS(int fps)
{
    m_TargetFPS = fps;
    ::SetTargetFPS(fps);
}

WindowContext::~WindowContext()
{
    CloseWindow();
}
