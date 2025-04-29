#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
	int fd;
	size_t size;
	char string[] = "3.124.2.24. OVSAINT\n";
	umask(0);
	if((fd = open("myfile", O_WRONLY | O_CREAT, 0666))<0) {
		printf("Ошибка при открытии файла на запись \n");
		exit(-1);
	}
	size = write(fd, string, 20);
	if(size != 20) {
		printf("Не удалось записать строку полностью\n");
		exit(-1);
	}
	if(close(fd) < 0) {
		printf("Ошибка при закрытии файла\n");
		exit(-1);
	}
	return 0;
}
