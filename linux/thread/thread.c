#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void* thread_start(void* arg)
{
	printf("����һ���̣߳�����������\n");
	printf("�һ�û���˳���\n");
	//while(1)
	{
		printf("���ǹ����̣߳�������ѭ��\n");
		sleep(1);
	}
	sleep(25);
	printf("��Ҫ����pthread_exit������\n");
	pthread_exit(NULL);
	printf("��Ҫ����return������\n");
	return NULL;
}

int main()
{
	pthread_t tid;
	pthread_create(&tid, NULL, thread_start, NULL);

	printf("�Ҹոմ�����һ���̣߳����ڲ�֪����ô����\n");
	//���߳��ڵ���pthread_join�ĵط�����������
	pthread_join(tid, NULL);
	//sleep(20);
	while (1)
	{
		printf("�Ҹոմ�����һ���̣߳����ڲ�֪����ô����\n");
		sleep(1);
	}
	pthread_cancel(tid);
	return 0;
}