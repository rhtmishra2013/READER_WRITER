#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<semaphore.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<fcntl.h>
#include<sys/stat.h>
#include "one_way.h"

int main (int argc, char *argv[])
{

  int id;
  char buffer[MAXBUF];
  key_t key;
  char *addr;
  sem_t *rcv, *snd;
  key = key_gen();
  id = get_id(key);
  rcv = rcv_mutex_open();
  snd = snd_mutex_open();
  addr = mapper(id);
  
  

  while (1)
  {
		          
		sem_wait(rcv);
		strcpy(buffer,addr);
                sem_post(snd);
		if (strcmp("exit\n", buffer) == 0)
		{
			printf("Reader Received -%s", buffer);
			break;
		}
		printf("Reader Received -%s", buffer);
  }
  return 0;

}
