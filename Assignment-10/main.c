#include "functions.h"

int main(void){
	PQueue q = createPQueue(10);

	for(int i = 0 ; i < 5 ; i++){
		enqueue(q,getemp());
		printf("Queue after adding: \n");
		display(q);
	}
	printf("De-Queued Element\n");
	putemp(dequeue(q));
}
