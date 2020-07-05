#pragma once
#include <stdio.h>
#include <unistd.h>
#include <sys/epoll.h>
#include <vector>

#include "tcpsvr.hpp"

class EpollSvr
{
public:
	EpollSvr()
	{
		epoll_fd_ = epoll_create(10);
	}

	~EpollSvr()
	{
		if (epoll_fd_ >= 0)
		{
			close(epoll_fd_);
		}
	}

	bool AddFd(int fd, bool IsEt = false)
	{
		struct epoll_event ev;
		//true
		if (IsEt)
		{
			ev.events = EPOLLIN | EPOLLET;
		}
		else
		{
			ev.events = EPOLLIN;
		}
		ev.data.fd = fd;
		int ret = epoll_ctl(epoll_fd_, EPOLL_CTL_ADD, fd, &ev);
		if (ret < 0)
		{
			perror("epoll_ctl");
			return false;
		}
		return true;
	}

	bool DeleteFd(int fd)
	{
		int ret = epoll_ctl(epoll_fd_, EPOLL_CTL_DEL, fd, NULL);
		if (ret < 0)
		{
			perror("epoll_ctl");
			return false;
		}
		return true;
	}

	bool EpollWait(std::vector<TcpSvr>* out)
	{
		struct epoll_event fd_arr[100];
		int ret = epoll_wait(epoll_fd_, fd_arr, sizeof(fd_arr) / sizeof(fd_arr[0]), -1);
		if (ret < 0)
		{
			perror("epoll_wait");
			return false;
		}
		printf("1234567890\n");

		for (int i = 0; i < ret; i++)
		{
			//�����¼��ṹ���飬�¼��ṹ���鵱�е�ÿһ���ļ����������Ǿ�����ֻ��Ҫ�������ظ������߾Ϳ�����
			//������һ��TcpSvr��Ķ��󣬽��������ļ������������ø�TcpSvr������еĳ�Ա����
			//�����е�TcpSvr�����ʹ��vector�������������ݸ�������
			//������ֻ��Ҫ����vector,ִ����Ӧ�Ĳ����Ϳ����ˣ�
			TcpSvr ts;
			ts.Setfd(fd_arr[i].data.fd);
			out->push_back(ts);
		}
		return true;
	}

	//map_->insert(std::make_pair(key, value));
private:
	//�����epoll�������
	int epoll_fd_;
};