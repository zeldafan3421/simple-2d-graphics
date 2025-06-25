#pragma once 

#include "raylib.h" 

#include <string>

class WindowContext
{
public:
    WindowContext(const std::string& _title, int _width, int _height);

    int GetTargetFPS() const;
    int GetCurrentFPS() const;
    int GetWidth() const;
    int GetHeight() const;
    const std::string& GetTitle() const;

    void SetWidth(int _width);
    void SetHeight(int _height);
    void SetTitle(const std::string& _title);
    void SetTargetFPS(int fps);

    bool IsOpen() const;
    bool IsReady() const;

    void BeginDrawing() const;
    void EndDrawing() const;

    void ClearBackground(const Color& color) const;

    ~WindowContext();
private:
    std::string m_Title;

    int m_Width;
    int m_Height;
    int m_TargetFPS;
};