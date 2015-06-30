#pragma once

#include <QQuickView>

namespace App
{
    class Window
    {
    private:
        QQuickView* m_view;
    private:
        Window() = default;
    public:
        static Window* instance;
        static Window* Create();
        void init();
        void show();
        ~Window() = default;
    };
}