#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>


typedef struct sharedData {

	int a, b, c;
	sem_t* semaphore;

}sharedData;


void* p(void* params) {

	sharedData* data = (sharedData*)params;
	sem_wait(data->semaphore);
	sem_wait(data->semaphore);
	sem_wait(data->semaphore);
	int res = data->a + data->b + data->c;
	printf("%d\n", res);


}


void* a(void* params) {
	sharedData* data = (sharedData*)params;
	data->a = rand() % 10;
	sem_post(data->semaphore);

}

void* b(void* params) {
	sharedData* data = (sharedData*)params;
	data->a = rand() % 10;
	sem_post(data->semaphore);

}


void* c(void* params) {
	sharedData* data = (sharedData*)params;
	data->a = rand() % 10;
	sem_post(data->semaphore);

}



typedef void* (*threadFunc)(void*);

int main() {
	

	sharedData data;
	data.semaphore = (sem_t*)malloc(sizeof(sem_t));
	pthread_t threads[4];
	threadFunc funcs[4] = { p,a, b, c };

	srand(time(0));

	sem_init(data.semaphore, 0, 0);

	for (int i = 0; i < 4; i++)
	{
		pthread_create(&threads[i], 0, funcs[i], &data);
	}

	for (int i = 0; i < 4; i++)
	{
		pthread_join(threads[i], 0);
	}

	sem_destroy(data.semaphore);
	free(data.semaphore);


	return 0;
}