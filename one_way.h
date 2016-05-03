#ifndef _ONE_WAY_H_
#define _ONE_WAY_H_

#define MAXBUF 256
#define MAGIC 'R'
#define KEY_PATH "/rohit"
#define RCV_PATH "/RCV"
#define SND_PATH "/SND"

int get_id(key_t key);
key_t key_gen(void);
char* mapper(int id);
sem_t * rcv_mutex(void);
sem_t * snd_mutex(void);
sem_t * snd_mutex_open(void);
sem_t * rcv_mutex_open(void);
void cleanup(int id);


#endif
