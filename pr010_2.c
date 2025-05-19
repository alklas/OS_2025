//Обмен данными через FIFO (именованый pipe) - процесс, читающий информацию
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define BYTES 75 

int main() {
	int fd;
	size_t size;
	char resstring[BYTES];
	char name[] = "fifo.file";
/*	
 *	if(mknod(name, S_IFIFO | 0664, 0) < 0) {
		printf("Не удалось создать FIFO\n");
		exit(-1);
	}
	*/
	printf("Прцесс-приёмник начал работу\n");
	if((fd = open(name, O_RDONLY)) < 0) {
		printf("Не удалось открыть FIFO на чтение\n");
		exit(-1);
	}
	size = read(fd, resstring, BYTES);
	if(size < 0) {
		printf("Не удалось прочитать строку из FIFO\n");
		exit(-1);
	}
	printf("Прочитанная строка: %s\n", resstring);
	if (close(fd)<0) {
		printf("Не удалось закрыть FIFO для процесс-ребёнка\n");
		exit(-1);
	}
	printf("Процесс-приёмник завершил работу\n");
	return 0;	
}
