#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE * fPointer;
    fPointer = fopen("gazdicsko.txt", "w");
    fprintf(fPointer, "Gazdicskó Marcell, Programtervezõ Informatikus, WSMZR9");
    fclose(fPointer);
    return 0;
}
