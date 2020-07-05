#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

//�����ȫ�ֱ��������ӵ��е���
int g_noodle = 0;

#define THREADCOUNT 4

pthread_mutex_t g_mutex;

//�Է���
pthread_cond_t g_cond;
//������
pthread_cond_t g_makecond;

void* EatStart(void* arg)
{
	while (1)
	{
		//
		pthread_mutex_lock(&g_mutex);
		while (g_noodle == 0)
		{
			//�������������ĵȴ��ӿ�
			pthread_cond_wait(&g_cond, &g_mutex);
		}
		g_noodle--;
		printf("EatStart g_noodle [%d]\n", g_noodle);
		pthread_mutex_unlock(&g_mutex);
		//֪ͨ�����������
		pthread_cond_signal(&g_makecond);
	}
	return NULL;
}

void* MakeStart(void* arg)
{
	while (1)
	{
		//������ֻ�Ǳ����ٽ���Դ��
		pthread_mutex_lock(&g_mutex);
		while (g_noodle == 1)
		{
			pthread_cond_wait(&g_makecond, &g_mutex);
		}
		g_noodle++;
		printf("MakeStart g_noodle [%d]\n", g_noodle);
		pthread_mutex_unlock(&g_mutex);
		pthread_cond_signal(&g_cond);
	}
	return NULL;
}

int main()
{
	pthread_mutex_init(&g_mutex, NULL);
	pthread_cond_init(&g_cond, NULL);
	pthread_cond_init(&g_makecond, NULL);

	pthread_t eat_tid[THREADCOUNT], make_tid[THREADCOUNT];
	int i = 0;
	for (; i < THREADCOUNT; i++)
	{
		int ret = pthread_create(&eat_tid[i], NULL, EatStart, NULL);
		if (ret != 0)
		{
			printf("create thread failed\n");
			return 0;
		}
		ret = pthread_create(&make_tid[i], NULL, MakeStart, NULL);
		if (ret != 0)
		{
			printf("create thread failed\n");
			return 0;
		}
	}

	for (i = 0; i < THREADCOUNT; i++)
	{
		pthread_join(eat_tid[i], NULL);
		pthread_join(make_tid[i], NULL);
	}
	pthread_mutex_destroy(&g_mutex);
	pthread_cond_destroy(&g_cond);
	pthread_cond_destroy(&g_makecond);
	return 0;
}