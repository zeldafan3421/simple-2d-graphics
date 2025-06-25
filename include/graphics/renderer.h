#pragma once

#include "raylib.h"
#include "../context/window_context.h"

class Renderer
{
public:
    enum class ProductionMode
    {
        Debug,
        Release
    };

    Renderer(WindowContext& windowContext, ProductionMode mode=ProductionMode::Debug);

    void BeginFrame() const;
    void EndFrame() const;
    void ClearBackground(const Color& color) const;
    
private:
    WindowContext& m_WindowContext;
};  