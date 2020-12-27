/* Name: Kesar Shrivastava
   Roll no. : 2019051 */

#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <errno.h>
#include <unistd.h>
#include<stdlib.h>


// Please include ALL the files indicated in the manual
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char** argv)
{  
	printf("-------Invoking Test For 'sh_task_info' System Call-------\n");
	
	int pid=atoi(argv[1]);
	if(argv[2]==NULL){
	printf("File name not given.\n");
		perror("Error: ");
		printf("Error No.: %d\n", errno);
		return 0;
	}
	
	long int status = syscall(548, pid, argv[2]); 
	
	if(status == 0) {
		printf("System Call 'sh_task_info' executed correctly.\nUse dmesg to check processInfo\n");
		}

	else 
	{
		printf("System call sh_task_info did not execute as expected\n");
		perror("Error ");
		printf("Error No.: %d\n", errno);
	}
	return 0;
}
