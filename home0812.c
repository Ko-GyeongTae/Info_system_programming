#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#define FILE_NAME	"console.txt"

int init_log_file(const char *log_file);
void input();
void output(char* buff);

int main(){
	init_log_file(FILE_NAME);
	input();
	return 0;
}

void input(){	
	int fd, nread;
	char* buff;

	buff = malloc(50);
	nread = read(0, buff, 50);
	if(nread == -1)
			write(2, "A read error has occurred\n", 26);
	buff[strlen(buff)] = '\n';
	fd = open("output.txt", O_RDWR | O_NONBLOCK, 0644);
	if(fd == -1)
			puts("open() Error!");
	//if(write(fd, buff, strlen(buff)) == -1)
			//puts("write() Error!");
	write(fd, buff, strlen(buff));
	output(buff);
	
	close(fd);
}

void output(char* buff){
	printf("Student num & name : %s", buff);
}

int init_log_file(const char *log_file){
	int fd;
	//open error
	if((fd = open(log_file, O_WRONLY | O_CREAT | O_APPEND)) == -1)
			return 0;
	dup2(fd, 1);
	dup2(fd, 2);
	close(fd);
	return 1;
}
