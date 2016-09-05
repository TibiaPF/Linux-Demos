#ifndef TESTWINDOW_H
#define TESTWINDOW_H

#include <QMainWindow>
#include "memoryreader.h"

namespace Ui {
class TestWindow;
}

class TestWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TestWindow(QWidget *parent = 0);
    ~TestWindow();
    Client c;
    MemoryReader mr;

private slots:
    void on_pushButton_clicked();

private:
    Ui::TestWindow *ui;
};

#endif // TESTWINDOW_H
