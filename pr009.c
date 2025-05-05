#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
	int fd[2];
	size_t size;
	char string[] = "3.124.2.24. OVSAINT.\n";
	char resstring[20];
	//Создание канала связи (pipe)
	if(pipe(fd) < 0) {
		printf("Не удалось создать пайп\n");
		exit(-1);
	}
	size = write(fd[1], string, 20);
	if(size != 20) {
		printf("Не удалось записать всю строку в пайп\n");
		exit(-1);
	}
	size = read(fd[0], resstring, 20);
	if(size != 20) {
		printf("Не удалось прочитать всю строку из пайпа\n");
                exit(-1);
	}
	printf("Прочитанная строка: %s\n", resstring);
	if(close(fd[1]) < 0) {
		printf("Не удалось закрыть выходной поток\n");
		exit(-1);
	}
	if(close(fd[0]) < 0) {
		printf("Не удалось закрыть входной поток\n");
		exit(-1);
	}
	return 0;
}
