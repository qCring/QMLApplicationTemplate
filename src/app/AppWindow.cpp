#include "AppWindow.h"
#include "AppConfig.h"
#include "AppInfo.h"
#include "AppController.h"

#include <QGuiApplication>
#include <QQmlComponent>
#include <QQmlContext>
#include <QQmlEngine>
#include <QDir>

namespace App
{
    Window* Window::instance = nullptr;
    
    Window* Window::Create()
    {
        instance = new Window();
        return instance;
    }
    
    void Window::init()
    {
        this->m_view = new QQuickView();
        this->m_view->setTitle(Info::appName.c_str());
        this->m_view->engine()->rootContext()->setContextProperty("App", Controller::instance);
        this->m_view->setSource(QUrl::fromLocalFile(Config::resourceDir + "/qml/view/Window.qml"));
        this->m_view->setResizeMode(QQuickView::SizeRootObjectToView);
    }
    
    void Window::show()
    {
        this->m_view->showMaximized();
    }
}
