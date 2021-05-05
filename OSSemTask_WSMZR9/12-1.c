#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>

int main()
{
    int rtn;
    int i;
    void *shared_memory;
    int shmid;

    shmid=shmget((key_t)2345, 1024, 0666);
    printf("A megosztott memória kulcsa: %d\n",shmid);
    shared_memory=shmat(shmid,NULL,0);
    printf("A folyamat csatolva %p\n",shared_memory);
    printf("A megosztott memóriából olvasott adatok: %s\n",(char *)shared_memory);

    FILE *fp;
    fp = fopen("masodik", "w");
    fputs(shared_memory, fp);
    fclose(fp);

    rtn = shmctl(shmid, IPC_RMID, NULL);
    printf("Szegmens torolve!\n");
}
