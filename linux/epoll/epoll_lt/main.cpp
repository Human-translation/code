#include "tcpsvr.hpp"
#include "epoll_lt_svr.hpp"

#define CHECK_RET(p) if(p != true){return 0;}

int main()
{
	TcpSvr listen_ts;

	CHECK_RET(listen_ts.CreateSock());
	CHECK_RET(listen_ts.Bind("172.16.99.129", 19999));
	CHECK_RET(listen_ts.Listen());

	EpollSvr epoll_svr;
	epoll_svr.AddFd(listen_ts.Getfd());

	while (1)
	{
		std::vector<TcpSvr> out;
		if (!epoll_svr.EpollWait(&out))
		{
			continue;
		}

		for (size_t i = 0; i < out.size(); i++)
		{
			if (listen_ts.Getfd() == out[i].Getfd())
			{
				//侦听套接字有可读事件发生了
				TcpSvr peerts;
				struct sockaddr_in peeraddr;
				if (!listen_ts.Accept(peerts, &peeraddr))
				{
					continue;
				}
				printf("have a new conntion %s : %d\n", inet_ntoa(peeraddr.sin_addr), ntohs(peeraddr.sin_port));

				epoll_svr.AddFd(peerts.Getfd());
			}
			else
			{
				//老的连接上面有数据到来了
				std::string buf;
				int recvsize = out[i].Recv(buf);
				if (recvsize == 0)
				{
					//对端关闭掉了
					//不需要让epoll监控对应连接的套接字描述符了
					epoll_svr.DeleteFd(out[i].Getfd());
					out[i].Close();
					continue;
				}

				printf("client say : %s\n", buf.c_str());
			}
		}
	}

	return 0;
}