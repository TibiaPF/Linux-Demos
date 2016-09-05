#include "client.h"
#include "testwindow.h"
#include "ui_testwindow.h"
#include <sys/ptrace.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <qmessagebox.h>

using namespace std;

Client::Client()
{
    int pid = -1;
    string procName = "Tibia";
    DIR *dp = opendir("/proc");
    if (dp != NULL) {
        struct dirent * dirp;
        while (pid < 0 && (dirp = readdir(dp))) {
            int id = atoi(dirp->d_name);
            if (id > 0) {
                string cmdPath = string("/proc/") + dirp->d_name + "/cmdline";
                ifstream cmdFile(cmdPath.c_str());
                string cmdLine;
                getline(cmdFile, cmdLine);
                if (!cmdLine.empty())
                {
                    size_t pos = cmdLine.find('\0');
                    if (pos != string::npos) {
                        cmdLine = cmdLine.substr(0, pos);
                    }
                    pos = cmdLine.rfind('/');
                    if (pos != string::npos) {
                        cmdLine = cmdLine.substr(pos + 1);
                    }
                    if (procName == cmdLine) {
                        this->processID = id;
                    }
                }
            }
        }
    }
}
