//Программа, иллюстрирующая создание процесса-ребёнка при помощи системного вызова fork()
//с разными действиями процесса-ребёнка и процесса-родителя
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
int main() {
	pid_t prid, parprid;
	int a = 0, c;
	prid = getpid();
	parprid = getppid();
	printf ("До выполнения fork():\n");
	printf("Ид. текущего процесса: %d\n", prid);
	printf("Ид. родительского процесса: %d\n", parprid);
	printf("Начальное значение переменной a: %d\n", a);
	c = fork();
	if(c<0) {
		printf("Ошибка при вызове fork()\n");
		exit(-1);
	}
	else if (c==0) {
		printf("Выполнение дочернего процесса\n");
		a = a+1;
		prid = getpid();
	        parprid = getppid();
	        printf ("После выполнения fork() для дочернего процесса:\n");
	        printf("Ид. текущего процесса: %d\nИд. родительского процесса: %d\n", prid, parprid);
	        printf("Значение переменной a: %d\n", a);
	}
	else {
		printf("Выполнение родительского процесса, порождён процесс с ид. %d\n", c);
		a = a+1000;
		prid = getpid();
		parprid = getppid();
		printf("После выполнения fork() для родительского процесса:\n");
		printf("Ид. текущего процесса: %d\nИд. родительского процесса: %d\n", prid, parprid);
		printf("Значение переменной a: %d\n", a);
	}
	return 0;
}
