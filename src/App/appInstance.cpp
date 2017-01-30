#include "appInstance.hpp"

#include "meta.hpp"
#include "appQmlRegister.hpp"
#include "appController.hpp"

#include <QFontDatabase>
#include <QApplication>
#include <QQmlContext>
#include <QQmlEngine>
#include <QDirIterator>
#include <QDir>

namespace app {

    Instance* Instance::instance = nullptr;

    Instance::Instance() {
    }

    auto Instance::init() -> void {
        QApplication::setOrganizationName(Meta::orgName);
        QApplication::setOrganizationDomain(Meta::orgDomain);
        QApplication::setApplicationName(Meta::appName);
        QApplication::setApplicationVersion(Meta::versionString);

        auto path = QDir(QGuiApplication::applicationDirPath());

#ifdef __APPLE__
        path.cdUp();
#endif
        auto resourceDir = path.absolutePath() + "/Resources/";

        AddFontDir(resourceDir + "fonts/roboto/");
        AddFontDir(resourceDir + "fonts/font-awesome/");

        this->m_view = new QQuickView();
        this->m_view->setTitle(QGuiApplication::applicationName());

        Qml::Register::Init();
        
        auto engine = this->m_view->engine();
        auto context = engine->rootContext();

        engine->addImportPath(resourceDir + "qml");
        context->setContextProperty("App", Controller::Create());

        this->m_view->setSource(QUrl::fromLocalFile(resourceDir + "qml/App/window.qml"));
        this->m_view->setResizeMode(QQuickView::SizeRootObjectToView);
        this->m_view->showMaximized();
    }

    auto Instance::Execute(int argc, char** argv) -> int {
        QApplication application(argc, argv);

        if (!instance) {
            instance = new Instance();
            instance->init();
            return application.exec();
        }

        return 1;
    }

    auto Instance::AddFontDir(const QString& directory) -> void {
        QDirIterator it(directory, {"*.ttf", "*.otf"}, QDir::Files);

        while (it.hasNext()) {
            QFontDatabase::addApplicationFont(it.next());
        }
    }
}
