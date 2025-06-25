#pragma once

#include "raylib.h"
#include <memory>

class Screen
{
public:
    Screen(const Screen&) = delete;
    Screen(Screen&&) = delete;

    Screen& operator=(const Screen&) = delete;
    Screen& operator=(Screen&&) = delete;

    virtual void Update() = 0;
    virtual void Draw() = 0;

    virtual ~Screen() = default;
    bool IsFinished() const { return m_Finished; };
    std::unique_ptr<Screen> GetNextScreen() { return std::move(m_NextScreen); }

protected:
    Screen() : m_NextScreen(nullptr), m_Finished(false) {};
    void SetFinished(bool finished) { m_Finished = finished; };
    void SetNextScreen(std::unique_ptr<Screen>& nextScreen) { m_NextScreen = std::move(nextScreen); };
    
private:
    bool m_Finished = false;
    std::unique_ptr<Screen> m_NextScreen = nullptr;
};