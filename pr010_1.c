//Обмен данными через FIFO процесс 1
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
	printf("Процесс-отправитель начал работу\n");
	if((fd = open(name, O_WRONLY)) < 0) {
		printf("Не удалось открыть FIFO на запись\n");
		exit(-1);
	}
	size = write(fd, "Строка для чтения процессом-получателем", BYTES);
	if(size != BYTES) {
		printf("Не удалось записать всю строку в FIFO\n");
		exit(-1);
	}
	printf("Строка записана в FIFO процессом-отправителем\n");
	if (close(fd)<0) {
		printf("Не удалось закрыть FIFO для процесса-родителя\n");
		exit(-1);
	}
	printf("Отправитель завершил работу\n");

	return 0;
}
