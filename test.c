#include <time.h>
#include <stdio.h>

int main() {

    time_t now = time(NULL);         // Get current time
  struct tm *t = localtime(&now);  // Convert to local time structure

  char file_name[] = { 'l', 'o', 'g', 's', '/', 'l', 'o', 'g',
        ((t->tm_mon + 1) / 10) + '0', 
        ((t->tm_mon + 1) % 10) + '0', // month
        ((t->tm_mday) / 10) + '0',
        ((t->tm_mday) % 10) + '0',    // day
        ((t->tm_hour) / 10) + '0',
        ((t->tm_hour) % 10) + '0',    // hour
        ((t->tm_min) / 10) + '0',
        ((t->tm_min) % 10) + '0',     // minutes
        ((t->tm_sec) / 10) + '0',
        ((t->tm_sec) % 10) + '0'           // seconds
    };
    printf("%s", file_name);
  return 0;
}