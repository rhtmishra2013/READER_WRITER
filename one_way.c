#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<semaphore.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<fcntl.h>
#include<sys/stat.h>
#include "one_way.h"



key_t key_gen(void)
{
	key_t key;
	key=ftok(KEY_PATH,MAGIC);
	return key;

}

int get_id(key_t key)
{
int shmid;
shmid = shmget(key,1024,0644|IPC_CREAT);
return shmid;
}


 
char* mapper(int id)
{
	return (shmat(id,(void*)0,0));

} 
 

sem_t * rcv_mutex(void)
{
	return (sem_open(RCV_PATH, O_CREAT|O_RDWR, 0644, 0));


}

sem_t* snd_mutex(void)
{
	return (sem_open(SND_PATH, O_CREAT|O_RDWR, 0644, 1));	

}


sem_t * rcv_mutex_open(void)
{
	return (sem_open(RCV_PATH, O_RDWR));

}

sem_t * snd_mutex_open(void)
{
	return (sem_open(SND_PATH, O_RDWR));

}


void cleanup(int id)

{ 
  sem_unlink(RCV_PATH);
  sem_unlink(SND_PATH);
  shmctl(id, IPC_RMID, NULL);

}
