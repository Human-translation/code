#include "tcpsvr.hpp"
#include "epoll_et_svr.hpp"

#define CHECK_RET(p) if(p != true){return 0;}

int main()
{
	TcpSvr listen_ts;

	CHECK_RET(listen_ts.CreateSock());
	CHECK_RET(listen_ts.Bind("0.0.0.0", 19998));
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
				//�����׽����пɶ��¼�������
				TcpSvr peerts;
				struct sockaddr_in peeraddr;
				if (!listen_ts.Accept(peerts, &peeraddr))
				{
					continue;
				}
				printf("have a new conntion %s : %d\n", inet_ntoa(peeraddr.sin_addr), ntohs(peeraddr.sin_port));

				epoll_svr.AddFd(peerts.Getfd(), true);
			}
			else
			{
				//�ϵ��������������ݵ�����
				std::string buf;
				bool ret = out[i].RecvNonblock(&buf);
				if (!ret)
				{
					//�Զ˹رյ���
					//����Ҫ��epoll��ض�Ӧ���ӵ��׽�����������
					epoll_svr.DeleteFd(out[i].Getfd());
					out[i].Close();
					continue;
				}

				printf("client say : %s\n", buf.c_str());
				buf.clear();
				buf.assign("wo jiu shi server");
				out[i].SendNonblock(buf);
			}
		}
	}

	return 0;
}