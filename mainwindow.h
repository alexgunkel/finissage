#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "venuewidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void openFile();
    void save();

signals:
    void newVenueCreated(const Venue &v);
private:
    Ui::MainWindow *ui;
    VenueWidget *vWidget;
};
#endif // MAINWINDOW_H
