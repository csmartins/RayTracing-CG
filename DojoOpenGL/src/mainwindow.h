#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class GLDisplay;

class MainWindow : public QMainWindow
{
    Q_OBJECT

signals:
    void wireframeClicked(bool);
    void saveResultAsImage();
    void lightRotationToggle(bool);

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setGLDisplay(GLDisplay *);

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
