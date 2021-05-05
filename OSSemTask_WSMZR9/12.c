#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>

int main()
{
    int i;
    void *shared_memory;
    int shmid;

    shmid=shmget((key_t)2345, 1024, 0666|IPC_CREAT);
    printf("A megosztott memória kulcsa: %d\n",shmid);
    shared_memory=shmat(shmid,NULL,0);
    printf("A folyamat csatolva %p\n",shared_memory);

    char * buffer = 0;
    long length;
    FILE * f = fopen("elso", "r");

    if (f)
    {
      fseek(f, 0, SEEK_END);
      length = ftell (f);
      fseek(f, 0, SEEK_SET);
      buffer = malloc(length);
      if (buffer)
      {
        fread(buffer, 1, length, f);
      }
      fclose (f);
    }

    strcpy(shared_memory,buffer);
    printf("Beolvasott adatok: %s\n",(char *)shared_memory);
}
