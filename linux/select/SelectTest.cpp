#include <stdio.h>
#include <unistd.h>
#include <sys/select.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main()
{
	//����
	fd_set readfds;
	FD_ZERO(&readfds);

	//���, ���ı�׼�����Ƿ��пɶ��¼�����;
	FD_SET(0, &readfds);

	//���
	int ret = select(1, &readfds, NULL, NULL, NULL);
	if (ret)
	{
		printf("ret : %d\n", ret);
		//FD_ISSET --> ����0��ʱ��һ�����жϵ�fdû���ڼ��ϵ��У�
		if (FD_ISSET(0, &readfds) != 0)
		{
			char buf[1024] = { 0 };
			read(0, buf, sizeof(buf) - 1);
			printf("buf:%s\n", buf);
		}
	}

	//ȥ��
	FD_CLR(0, &readfds);
	return 0;
}
