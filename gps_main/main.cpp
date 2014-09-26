#include <iostream>
#include <cstdio>
#include "gpsData.h"

void WaitForClose();

int main(int argc, char **argv)
{

    WaitForClose();
    return 0;
}

inline void WaitForClose()
{
    printf("PROGRAM COMPLETE. PRESS ENTER TO CONTINUE");
    getchar();
}
