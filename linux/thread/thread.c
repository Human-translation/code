#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void* thread_start(void* arg)
{
	printf("我是一个线程，我曾经来过\n");
	printf("我还没有退出吗？\n");
	//while(1)
	{
		printf("我是工作线程，我在死循环\n");
		sleep(1);
	}
	sleep(25);
	printf("我要调用pthread_exit返回了\n");
	pthread_exit(NULL);
	printf("我要调用return返回了\n");
	return NULL;
}

int main()
{
	pthread_t tid;
	pthread_create(&tid, NULL, thread_start, NULL);

	printf("我刚刚创建了一个线程，现在不知道怎么样了\n");
	//主线程在调用pthread_join的地方进行阻塞了
	pthread_join(tid, NULL);
	//sleep(20);
	while (1)
	{
		printf("我刚刚创建了一个线程，现在不知道怎么样了\n");
		sleep(1);
	}
	pthread_cancel(tid);
	return 0;
}