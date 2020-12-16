#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <math.h>

// Jill Pownall
// Comp 411 Lab 2
// 9/3/2020

int main() {

	char processors[10][100];
    char str_temp[100];
	float costs[10];
	float clockrates[10];
	float cpis[10];
	float executiontimes[10];
    float temp = 0.0;
	int p_num = 0;
	
	printf("Please enter the number of processors [1 to 10]: \n");
	scanf("%d",&p_num);

    for(int i = 0; i < p_num; i++) {
	printf("Processor Name (no spaces): \n");
	scanf("%s",processors[i]);
	printf("Processor cost (US dollars): \n");
	scanf("%f",&costs[i]);
	printf("Processor clock rate (in GHz): \n");
	scanf("%f",&clockrates[i]);
	printf("Processor average CPI: \n");
	scanf("%f",&cpis[i]);

    executiontimes[i] = (cpis[i]*(1/clockrates[i]))/100;

    };

    
    for(int i = 0; i < p_num-1; i++) {
    	for(int j = 0; j < p_num-i-1; j++) {
    		if(executiontimes[j] > executiontimes[j+1]) {
    			temp = executiontimes[j];
                executiontimes[j] = executiontimes[j+1];
                executiontimes[j+1] = temp;
                
                temp = clockrates[j];
                clockrates[j] = clockrates[j+1];
                clockrates[j+1] = temp;
                
                temp = cpis[j];
                cpis[j] = cpis[j+1];
                cpis[j+1] = temp;
            
                temp = costs[j];
                costs[j] = costs[j+1];
                costs[j+1] = temp;
            
                strcpy( str_temp, processors[j] ); 
                strcpy( processors[j], processors[j+1] ); 
                strcpy( processors[j+1], str_temp ); 
    		}
    	}
    }

    printf("Now ranking execution times... from lowest to highest execution time, your results are: \n");

    for(int i = 0; i < p_num; i++) {
    	printf("%s: %.4f\n", processors[i], executiontimes[i]);
    }

    float lowestPrice = 1e20;
    float targetTime = 0.0;
    int index = 0;

	printf("What execution time (in seconds) are you targeting? \n");
    scanf("%f",&targetTime);
    for(int i = 0; i < p_num; i++) {
    	if(executiontimes[i] < targetTime) {
    		if(costs[i] < lowestPrice) {
    			index = i;
    			lowestPrice = costs[i];
    		}
    	}
    }

    printf("The cheapest processor to meet your specification is: %s at a price of $%0.2f.\n'", processors[index], costs[index]);

	return 0;
}
