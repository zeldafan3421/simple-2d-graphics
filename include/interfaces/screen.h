#pragma once

#include "raylib.h"
#include <memory>

class Screen
{
public:
    enum Index : std::size_t
    {
        Start,
        Null
    };

    Screen(const Screen&) = delete;
    Screen(Screen&&) = delete;

    Screen& operator=(const Screen&) = delete;
    Screen& operator=(Screen&&) = delete;

    virtual void Update() = 0;
    virtual void Draw() = 0;

    virtual ~Screen() = default;
    bool IsFinished() const { return m_Finished; };
protected:
    Screen() : m_Finished(false) {};
    void SetFinished(bool finished) { m_Finished = finished; };
    
private:
    bool m_Finished = false;
};