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

	

int main (int argc, char *argv[])
{

  int id;
  char buffer[MAXBUF];
  key_t key;
  char *addr;
  sem_t *rcv, *snd;
   

  key = key_gen();
  id=get_id(key);
  rcv = rcv_mutex();
  snd = snd_mutex();
  addr = mapper(id);
  
  while (1)
  {
		printf("Enter some Message !!\n");
		fgets(buffer, MAXBUF, stdin);
                sem_wait(snd);
		strcpy(addr, buffer);
		sem_post(rcv);
		printf("send more messages.if yes then press any key.if you want to exit just type EXIT\n");
		if (strcmp("exit\n", buffer) == 0)
		{
			break;
		}
  }

 cleanup(id);

  
  return 0;
  

}

