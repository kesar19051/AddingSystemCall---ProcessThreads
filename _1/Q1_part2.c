/* Name: Kesar Shrivastava
   Roll_Number: 2019051 */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int var = 10;

void *func(void *vargp){
	printf("The initial value of the variable in child thread: %d\n", var);
	while(var>-90){
		var-=1;
	}
	printf("Final value in child thread: %d\n", var);
	return NULL;
}

int main(){
	pthread_t ptid;
	pthread_create(&ptid, NULL, func, NULL);
	printf("The initial value of the variable in the parent thread: %d\n", var);
	while(var<100){
		var+=1;
	}
	printf("Final value in parent thread: %d\n", var);
	pthread_join(ptid, NULL);
	pthread_exit(NULL);
	return 0;
}