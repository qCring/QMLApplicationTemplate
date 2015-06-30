#include <QMenuBar>
#include <QMenu>
#include <QString>

#include "AppMenu.h"

namespace App
{
    Menu* Menu::instance = nullptr;
    
    void Menu::init()
    {
#ifdef Q_OS_DARWIN
        initMacMenu();
#else
        initWinMenu();
#endif
    }
    
    Menu* Menu::Create()
    {
        instance = new Menu();
        
        return instance;
    }
    
    void Menu::initWinMenu()
    {
    }
    
    void Menu::initMacMenu()
    {
        QMenuBar* menuBar       = new QMenuBar(0);
        
        QMenu* fileMenu			= new QMenu(tr("File"), menuBar);
        QAction* newFile        = fileMenu->addAction(tr("New..."));
        QAction* open			= fileMenu->addAction(tr("Open..."));
        QAction* save			= fileMenu->addAction(tr("Save"));
        QAction* saveAs			= fileMenu->addAction(tr("Save As..."));
        
        QMenu *editMenu			= new QMenu(tr("Edit"), menuBar);
        QAction *undo			= editMenu->addAction(tr("Undo"));
        QAction *redo			= editMenu->addAction(tr("Redo"));
        QAction *cut			= editMenu->addAction(tr("Cut"));
        QAction *copy			= editMenu->addAction(tr("Copy"));
        QAction *paste			= editMenu->addAction(tr("Paste"));
        
        QMenu *helpMenu			= new QMenu(tr("Help"), menuBar);
        QAction *about			= helpMenu->addAction(tr("About"));
        QAction* preferences	= helpMenu->addAction(tr("Preferences..."));
        QAction* documentation	= helpMenu->addAction(tr("Documentation"));
        
        newFile->setShortcut(tr("Ctrl+N"));
        open->setShortcut(tr("Ctrl+O"));
        save->setShortcut(tr("Ctrl+S"));
        saveAs->setShortcut(tr("Shift+Ctrl+S"));
        
        undo->setShortcut(tr("Ctrl+Z"));
        redo->setShortcut(tr("Shift+Ctrl+Z"));
        cut->setShortcut(tr("Ctrl+X"));
        copy->setShortcut(tr("Ctrl+C"));
        paste->setShortcut(tr("Ctrl+V"));
        
        QObject::connect(newFile, SIGNAL(triggered()), this, SLOT(onFileNew()));
        QObject::connect(open, SIGNAL(triggered()), this, SLOT(onFileOpen()));
        QObject::connect(save, SIGNAL(triggered()), this, SLOT(onFileSave()));
        QObject::connect(saveAs, SIGNAL(triggered()), this, SLOT(onFileSaveAs()));
        
        QObject::connect(undo, SIGNAL(triggered()), this, SLOT(onEditUndo()));
        QObject::connect(redo, SIGNAL(triggered()), this, SLOT(onEditRedo()));
        QObject::connect(cut, SIGNAL(triggered()), this, SLOT(onEditCut()));
        QObject::connect(copy, SIGNAL(triggered()), this, SLOT(onEditCopy()));
        QObject::connect(paste, SIGNAL(triggered()), this, SLOT(onEditPaste()));
        
        QObject::connect(about, SIGNAL(triggered()), this, SLOT(onHelpAbout()));
        QObject::connect(preferences, SIGNAL(triggered()), this, SLOT(onHelpPreferences()));
        QObject::connect(documentation, SIGNAL(triggered()), this, SLOT(onHelpDocumentation()));
        
        menuBar->addMenu(fileMenu);
        menuBar->addMenu(editMenu);
        menuBar->addMenu(helpMenu);
    }

    void Menu::onFileNew()
    {
    }
    
    void Menu::onFileOpen()
    {
    }
    
    void Menu::onFileSave()
    {
    }
    
    void Menu::onFileSaveAs()
    {
    }
    
    void Menu::onEditUndo()
    {
    }
    
    void Menu::onEditRedo()
    {
    }
    
    void Menu::onEditCut()
    {
    }
    
    void Menu::onEditCopy()
    {
    }
    
    void Menu::onEditPaste()
    {
    }
    
    void Menu::onHelpAbout()
    {
    }
    
    void Menu::onHelpPreferences()
    {
    }
    
    void Menu::onHelpDocumentation()
    {
    }
}