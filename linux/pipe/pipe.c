#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main()
{
	
	int fd[2];
	int ret = pipe(fd);
	if (ret != 0)
	{
		printf("create pipe failed\n");
		return 0;
	}

	
	int flags = fcntl(fd[0], F_GETFL, 0);
	
	flags |= O_NONBLOCK;
	
	fcntl(fd[0], F_SETFL, flags);
	

	
	ret = fork();
	if (ret < 0)
	{
		perror("fork");
		return 0;
	}
	else if (ret == 0)
	{

		//close(fd[1]);
		//close(fd[0]);
		
//        int count = 0;
//        while(1)
//        {
//            printf("write count [%d]\n", count);
//            int ret = write(fd[1], "1", 1);
//            if(ret == -1)
//            {
//                perror("write\n");
//                break;
//            }
//            count++;
//        }
//
		while (1)
		{
			sleep(1);
		}
	}
	else
	{
		//close(fd[0]);
		//close(fd[1]);
		sleep(1);
		char arr[1024] = { 0 };
		int ret = read(fd[0], arr, sizeof(arr) - 1);
		printf("ret = %d\n", ret);
		if (ret == -1)
		{
			perror("read");
		}
		printf("i am father fd[0] read [%s]\n", arr);
		memset(arr, '0', 1024);
		//read(fd[0], arr, sizeof(arr) - 1);
		//printf("i am father1 fd[0] read [%s]\n", arr);
		while (1)
		{
			sleep(1);
		}
	}


	return 0;
}