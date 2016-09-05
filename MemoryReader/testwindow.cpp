#include "testwindow.h"
#include "ui_testwindow.h"
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <qmessagebox.h>
#include "util.h"
#include "client.h"

using namespace std;

TestWindow::TestWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TestWindow)
{
    ui->setupUi(this);
    mr = MemoryReader();
}

TestWindow::~TestWindow()
{
    delete ui;
}


void TestWindow::on_pushButton_clicked()
{
    int addr = 0x85254d0;
    int value = mr.ReadInt(addr);
    Util::Alert("Yay", value);
}
