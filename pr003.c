#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
int main() {
	pid_t procid, parentprocid;
	procid = getpid();
	parentprocid = getppid();
	printf("Ид. текущего процесса: %d\nИд. родительского процесса: %d\n", procid, parentprocid);
	return 0;
}
