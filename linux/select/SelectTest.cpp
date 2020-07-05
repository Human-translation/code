#include <stdio.h>
#include <unistd.h>
#include <sys/select.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main()
{
	//定义
	fd_set readfds;
	FD_ZERO(&readfds);

	//添加, 关心标准输入是否有可读事件产生;
	FD_SET(0, &readfds);

	//监控
	int ret = select(1, &readfds, NULL, NULL, NULL);
	if (ret)
	{
		printf("ret : %d\n", ret);
		//FD_ISSET --> 返回0的时候一定是判断的fd没有在集合当中；
		if (FD_ISSET(0, &readfds) != 0)
		{
			char buf[1024] = { 0 };
			read(0, buf, sizeof(buf) - 1);
			printf("buf:%s\n", buf);
		}
	}

	//去除
	FD_CLR(0, &readfds);
	return 0;
}
