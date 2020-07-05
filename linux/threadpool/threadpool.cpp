#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <iostream>
#include <queue>

#define THREADCOUNT 4

//��װ������
//
void ThreadTaskfunc(int Data)
{
	printf("i recv Data [%d]\n", Data);
}

void ThreadTaskfunc1(int Data)
{
	Data += 10;
	printf("i recv Data [%d]\n", Data);
}

typedef void(*Handler_t)(int);
class ThreadTask
{
public:
	ThreadTask()
	{
		Data_ = -1;
		Handler_ = NULL;
	}

	ThreadTask(int Data, Handler_t handler)
	{
		Data_ = Data;
		Handler_ = handler;
	}

	void Run()
	{
		Handler_(Data_);
	}
private:
	int Data_;
	Handler_t Handler_;
};


class ThreadPool
{
public:
	ThreadPool()
	{
		Capacity_ = 10;

		ThreadCapacity_ = THREADCOUNT;
		ThreadCurNum_ = THREADCOUNT;

		pthread_mutex_init(&Mutex_, NULL);
		pthread_cond_init(&Cond_, NULL);

		IsExit = false;

		//�����߳�
		bool IsCrate = ThreadCreate();
		if (!IsCrate)
		{
			printf("ThreadPool Create thread failed\n");
			exit(1);
		}
	}

	~ThreadPool()
	{
		pthread_mutex_destroy(&Mutex_);
		pthread_cond_destroy(&Cond_);
	}

	//main�߳�
	bool Push(ThreadTask* Tt)
	{
		pthread_mutex_lock(&Mutex_);
		if (IsExit)
		{
			pthread_mutex_unlock(&Mutex_);
			return false;
		}
		Que_.push(Tt);
		pthread_mutex_unlock(&Mutex_);

		//��������֮����Ҫ֪ͨ�̳߳ص��е��߳�
		pthread_cond_signal(&Cond_);
		return true;
	}

	bool Pop(ThreadTask** Tt)
	{
		*Tt = Que_.front();
		Que_.pop();
		return true;
	}

	void ThreadPoolClear()
	{
		pthread_mutex_lock(&Mutex_);
		IsExit = true;
		pthread_mutex_unlock(&Mutex_);

		//��Ҫ�����̳߳ص����߳���PCB�ȴ����е��е��߳�
		while (ThreadCurNum_ > 0)
		{
			pthread_cond_broadcast(&Cond_);
		}
	}

	void ThreadExit()
	{
		for (int i = 0; i < THREADCOUNT; i++)
		{
			pthread_cancel(tid_[i]);
		}
	}

	void ThreadJoin()
	{
		for (int i = 0; i < THREADCOUNT; i++)
		{
			pthread_join(tid_[i], NULL);
		}
	}

	static void* ThreadStart(void* arg)
	{
		ThreadPool* tp = (ThreadPool*)arg;
		while (1)
		{
			//1
			pthread_mutex_lock(&tp->Mutex_);
			while (tp->Que_.empty())
			{
				//true
				//printf("%d\n", tp->IsExit);
				if (tp->IsExit)
				{
					tp->ThreadQuit();
				}
				//2
				pthread_cond_wait(&tp->Cond_, &tp->Mutex_);
			}
			//3
			ThreadTask* tt;
			tp->Pop(&tt);
			pthread_mutex_unlock(&tp->Mutex_);
			tt->Run();

			delete tt;
		}
		//���Ӵ������ݵĲ���
		return NULL;
	}

	bool ThreadCreate()
	{
		for (int i = 0; i < THREADCOUNT; i++)
		{
			int ret = pthread_create(&tid_[i], NULL, ThreadStart, (void*)this);
			if (ret != 0)
			{
				perror("pthread_create");
				return false;
			}
		}
		return true;
	}

	void ThreadQuit()
	{
		ThreadCurNum_--;
		pthread_mutex_unlock(&Mutex_);
		pthread_exit(NULL);
	}
private:
	std::queue<ThreadTask*> Que_;
	size_t Capacity_;

	//�̳߳�
	//�̳߳ص����̳߳�ʼ��������
	pthread_t tid_[THREADCOUNT];

	size_t ThreadCapacity_;
	//��ǰ�̳߳������ж��ٸ��̵߳�
	size_t ThreadCurNum_;

	//�̰߳�ȫ�Ļ���
	pthread_mutex_t Mutex_;
	//���ѵ���������
	pthread_cond_t Cond_;

	//�̰߳�ȫ�˳��ı�־
	bool IsExit;
};


int main()
{
	ThreadPool* tp = new ThreadPool();
	for (int i = 0; i < 10; i++)
	{
		ThreadTask* tt = new ThreadTask(i, ThreadTaskfunc1);
		tp->Push(tt);
	}

	sleep(6);
	tp->ThreadPoolClear();
	tp->ThreadJoin();

	delete tp;
	return 0;
}