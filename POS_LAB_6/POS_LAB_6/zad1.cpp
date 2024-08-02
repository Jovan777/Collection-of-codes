#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <iostream>


using namespace std;





class Buffer {

private:
	int* buff;
	int head, tail, cap;
	sem_t spaceAvail, itemAvail;
	sem_t mutexPut, mutexGet;

public:
	Buffer(int c) : cap(c) {
		head = tail = 0;
		sem_init(&spaceAvail, 0, cap);
		sem_init(&itemAvail, 0, 0);
		sem_init(&mutexPut, 0, 1);
		sem_init(&mutexGet, 0, 1);


	}

	~Buffer()
	{
		delete buff;
		sem_destroy(&spaceAvail);
		sem_destroy(&itemAvail);
		sem_destroy(&mutexPut);
		sem_destroy(&mutexGet);


	}

	int put(int item) {
		sem_wait(&spaceAvail);
		sem_wait(&mutexPut);
		buff[head] = item;
		head = (head + 1) % cap;
		sem_post(&mutexPut);
		sem_post(&itemAvail);

		return item;
	}

	int get() {

		sem_wait(&itemAvail);
		sem_wait(&mutexGet);
		int b = buff[tail];
		tail = (tail + 1) % cap;
		sem_post(&spaceAvail);
		sem_post(&mutexGet);

		return b;

	}


};


void* putThread(void* args) {
	Buffer* buff = (Buffer*)args;
	int iter = 10;
	srand(time(0));

	while (iter-- > 0)
	{

		cout << "Put: " << buff->put(rand() % 10) << endl;


	}

}
	
	void* getThread(void* args) {

		Buffer* buff = (Buffer*)args;
		int iter = 10;

		while (iter-->0)
		{
			cout << buff->get() << endl;


		}





	}




int main() {

	Buffer buff(2);

	pthread_t threads[2];
	pthread_create(&threads[0], 0, putThread, &buff);
	pthread_create(&threads[1], 0, getThread, &buff);


	pthread_join(threads[0], 0);
	pthread_join(threads[1], 0);


	cout << "Kraj" << endl;



	return 0;
}













