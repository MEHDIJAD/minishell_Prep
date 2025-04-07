#include "cell.h"

// WRAPPERS

void Getcwd(char *buf, size_t size)
{
    if (!getcwd(buf, size))
        perror(RED"getcwd FAILED"RST);
}