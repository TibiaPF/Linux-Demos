#include "memoryreader.h"
#include "util.h"
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>

MemoryReader::MemoryReader(){

}

int MemoryReader::ReadInt(int Address) {
    PeekPause();
    int res = PeekRead(Address);
    PeekUnpause();
    return res;
}

void MemoryReader::PeekPause() {
    int stat;
    if (ptrace(PTRACE_ATTACH, this->c.processID, 0, 0) != 0) {
        Util::Alert("We dun fucked up.", strerror(errno));
    }
    // wait for the big freeze
    int res = waitpid(c.processID, &stat, WUNTRACED);
    if ((res != c.processID) || !(WIFSTOPPED(stat)) ) {
        printf("Unexpected wait result res %d stat %x\n",res,stat);
        exit(1);
    }
}

int MemoryReader::PeekRead(int Address) {
    int value = ptrace(PTRACE_PEEKDATA, c.processID, Address, 0);
    if (errno != 0)
    {
        Util::Alert("We dun fucked up.", errno);
    }
    return value;
}

void MemoryReader::PeekUnpause() {
    if (ptrace(PTRACE_DETACH, c.processID, 0, 0) != 0) {
        Util::Alert("We dun fucked up.", strerror(errno));
    }
}
