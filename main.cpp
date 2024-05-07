#include <iostream>
#include <string.h>
#include <math.h>
#ifndef _WIN32
#include <unistd.h>
#else
#include <windows.h>
void usleep(__int64 usec)
{
  HANDLE timer;
  LARGE_INTEGER ft;

  ft.QuadPart = -(10 * usec); // Convert to 100 nanosecond interval, negative value indicates relative time

  timer = CreateWaitableTimer(NULL, TRUE, NULL);
  SetWaitableTimer(timer, &ft, 0, NULL, NULL, 0);
  WaitForSingleObject(timer, INFINITE);
  CloseHandle(timer);
}
#endif


//void consoleThing() {
    //std::cout << "\033[H\033[2J";
    //memset
//}

int main() {
    // Write C++ code here
    //std::cout << "Thing....";
    printf("Hello");
    printf("\x1b[2J");
    usleep(8000*2);
    printf("\x1b[H");


    return 0;
}
