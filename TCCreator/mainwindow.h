#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>
#include <QDir>
#include "wrapper.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool initialize();
    // Wrapper* pyW = new Wrapper();
    Wrapper* pyW;
    // QSettings* settings = new QSettings(QDir::currentPath() + "ini.ini", QSettings::IniFormat);
    // QSettings settings;
    void changeType();
private:
    Ui::MainWindow *ui;
    void change2New();
    void change2Update();
    void change2Delete();
};
#endif // MAINWINDOW_H
