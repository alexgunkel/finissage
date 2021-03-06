#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "addvenuedialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , vWidget(new VenueWidget)
{
    ui->setupUi(this);
    setWindowTitle(tr("Finissage"));

    auto fileMenu = menuBar()->addMenu(tr("File"));

    connect(fileMenu->addAction(tr("New Venue")), &QAction::triggered, vWidget, &VenueWidget::addVenueDialog);

    fileMenu->addSeparator();

    connect(fileMenu->addAction(tr("Open File")), &QAction::triggered, this, &MainWindow::openFile);
    connect(fileMenu->addAction(tr("Save")), &QAction::triggered, this, &MainWindow::save);
    fileMenu->addAction(tr("Save as"));

    fileMenu->addSeparator();
    connect(fileMenu->addAction(tr("Exit")), &QAction::triggered, this, &QApplication::quit);

    auto viewMenu = menuBar()->addMenu(tr("View"));
    viewMenu->addAction(tr("Venues"));
    viewMenu->addAction(tr("Exhibitions"));

    auto helpMenu = menuBar()->addMenu(tr("Help"));
    helpMenu->addAction(tr("About"));

    setCentralWidget(vWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openFile()
{
    //
}

void MainWindow::save()
{
    //
}

