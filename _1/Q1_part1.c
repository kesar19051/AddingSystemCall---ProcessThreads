/* Name: Kesar Shrivastava
   Roll_Number: 2019051 */

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int var = 10;
int main(int argc, char const *argv[])
{
	int id = fork();

	if(id<0){
		printf("%s\n", "fork() has failed");
	}
	else if(id==0){
		while(var>-90){
			var-=1;
		}
		printf("The child process: %d\n", var);
	}
	else{
		while(var<100){
			var+=1;
		}
		printf("The parent process: %d\n", var);
		exit(1);
	}
	return 0;
}