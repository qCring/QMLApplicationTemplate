#pragma once

#include <QObject>

namespace App
{
    class Menu : public QObject
    {
        Q_OBJECT
    private:
        void initMacMenu();
        void initWinMenu();
    private:
        Menu() = default;
    public:
        static Menu* instance;
        static Menu* Create();
        void init();
        ~Menu() = default;
    public slots:
        void onFileNew();
        void onFileOpen();
        void onFileSave();
        void onFileSaveAs();
        
        void onEditUndo();
        void onEditRedo();
        void onEditCut();
        void onEditCopy();
        void onEditPaste();
        
        void onHelpAbout();
        void onHelpPreferences();
        void onHelpDocumentation();
    };
}