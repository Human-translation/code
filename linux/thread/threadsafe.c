#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>

#define THREADCOUNT 4

int g_tickets = 100;

pthread_mutex_t g_mutex;

//�̵߳����������Ʊ��������100��Ʊ��ÿ����һ�žͽ��м�1����
void* thread_start(void* arg)
{
	(void)arg;
	while (1)
	{
		// A B C D --> ����Ȼ����м������� ���裬B�����ˣ�A C Dû������
		// A C D�̣߳���������pthread_mutex_lock
		// B �ڽ��� ��Դ����֮������ �ص���whileѭ��,Ҳ��Ҫִ��pthread_mutex_lock���������������أ�������ͱ����Լ����ţ��Լ�û���ͷ��������ǻ����ڻ�ȡ���������Ҳ�ͱ�������
		pthread_mutex_lock(&g_mutex);
		//���ж� g_tickets��ֵΪ0��ʱ������else�߼�
		if (g_tickets > 0)
		{
			g_tickets--;
			printf("i am thread [%p], i have ticket num is [%d]\n", pthread_self(), g_tickets + 1);
		}
		else
		{
			//��break������ѭ��
			pthread_mutex_unlock(&g_mutex);
			break;
		}
		pthread_mutex_unlock(&g_mutex);
	}
	//��return ���з�����
	return NULL;
}

int main()
{
	pthread_t tid[THREADCOUNT];
	int i = 0;
	pthread_mutex_init(&g_mutex, NULL);
	for (; i < THREADCOUNT; i++)
	{
		pthread_create(&tid[i], NULL, thread_start, NULL);
	}

	for (i = 0; i < THREADCOUNT; i++)
	{
		pthread_join(tid[i], NULL);
	}
	pthread_mutex_destroy(&g_mutex);
	return 0;
}