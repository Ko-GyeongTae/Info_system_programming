#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	int fd;
	char* buff;

	buff = (char*)malloc(100);
	printf("Please Enter Message : ");
	fgets(buff, 100, stdin);
	buff[strlen(buff)] = '\n';

	fd = open("linux.txt", O_RDWR, 0644);
	if(fd == -1)
			puts("open() Error!");
	if(write(fd, buff, strlen(buff)) == -1)
			puts("write() Error!");
	close(fd);
	free(buff);
	
	fd = open("linux.txt", O_RDONLY);
	buff = (char*)malloc(100);
	memset(buff, 0, 100);

	read(fd, buff, 30);
	printf("%s\n", buff);
	free(buff);
 	return 0; 
}     
