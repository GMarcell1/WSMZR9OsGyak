#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE * fPointer;
    fPointer = fopen("gazdicsko.txt", "w");
    fprintf(fPointer, "Gazdicsk� Marcell, Programtervez� Informatikus, WSMZR9");
    fclose(fPointer);
    return 0;
}
