#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{   printf("Abhinav Singh Yadav StudentId-20011780\n");
    fork();
    printf("Hello Abhinav the Process id is:- %d\n",getpid());
	return 0;
}
