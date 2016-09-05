#ifndef UTIL_H
#define UTIL_H

#include "QString"
#include "QMessageBox"
#include <stdio.h>

class Util
{
public:
    static void Alert(QString error, QString message)
    {
        QMessageBox qmb;
        qmb.setText(error);
        qmb.setInformativeText(message);
        qmb.setStandardButtons(QMessageBox::Ok);
        qmb.setDefaultButton(QMessageBox::Ok);
        qmb.exec();
    }

    static void Alert(QString message, int id)
    {
        char buffer[32];
        sprintf(buffer, "%d", id);

        QMessageBox qmb;
        qmb.setText(message);
        qmb.setInformativeText(buffer);
        qmb.setStandardButtons(QMessageBox::Ok);
        qmb.setDefaultButton(QMessageBox::Ok);
        qmb.exec();
    }

};

#endif // UTIL_H
