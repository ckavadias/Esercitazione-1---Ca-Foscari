/* Esercitazione 1, CT0421, Constantinos Kavadias
	984223@stud.unive.it, October 2016, uses documents
   created from code sourced from 
     https://people.sc.fsu.edu/~jburkardt/c_src/poisson_simulation
     /poisson_simulation.html*/
	

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "esercitazione.h"

int
main(int argc, char *argv[]) {
	int i = 0, j = 0;
	double velocity = 0.00;
	
/* pick random velocity for testing */
	velocity = (double)(rand()%1000)/100.00;
	fprintf(stderr, "velocity = %f\n", velocity);
	
/* run simulation for situation 1, single buffer, single line */
	fprintf(stderr, "Situation 1, single buffer, single line\n");
	for( i = 0; i < MAX_TESTS; i++){
		call_poisson();
		initialise(1);
		departure(2*velocity);
		response();
		compile_statistics();
	
		if(DEBUG){
			for(j = 0; j <size_list; j++){
				printf("Event: %d, Arrival: %f, Departure: %f \n", j, 
					event_list[j].arrival, event_list[j].departure);
			}
		}
		free_attempt();
	}
	print_statistics();
	reset();
	
/* run simulation for situation 2, single buffer, 2 lines */
	fprintf(stderr, "Situation 2, single buffer, two lines\n");
	for( i = 0; i < MAX_TESTS; i++){
		call_poisson();
		initialise(2);
		departure(velocity);
		response();
		compile_statistics();
	
		if(DEBUG){
			for(j = 0; j <size_list; j++){
				printf("Event: %d, Arrival: %f, Departure: %f \n", j, 
					event_list[j].arrival, event_list[j].departure);
			}
		}
		free_attempt();
	}
	print_statistics();
	reset();
	
/* run simulation for situation 3, 2 buffers, 2 lines */
	fprintf(stderr, "Situation 3, 2 buffers, two lines\n");
	for( i = 0; i < MAX_TESTS; i++){
		call_poisson();
		initialise(3);
		departure(velocity);
		response();
		compile_statistics();
	
		if(DEBUG){
			for(j = 0; j <size_list; j++){
				printf("Event: %d, Arrival: %f, Departure: %f \n", j, 
					event_list[j].arrival, event_list[j].departure);
			}
		}
		free_attempt();
	}
	print_statistics();
	reset();
	
	return 0;
}