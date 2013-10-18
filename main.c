#include <msp430.h> 
//Noel B Nicolas
//ECE 382
// This program will write a function that computes the "moving average" for a stream of data points it is receiving
/*
 * main.c
 */


#define N_AVG_SAMPLES 2
#define DATALENGTH 10

// Moving average functions
int getAverage(int array[], unsigned int arrayLength);
void addSample(int sample, int array[], unsigned int arrayLength);

// Array functions
int max(int array[], unsigned int arrayLength);
int min(int array[], unsigned int arrayLength);
unsigned int range(int array[], unsigned int arrayLength);


int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

    int sample[]= {174, 162, 149, 85, 130, 149, 153, 164, 169, 173};
    int arrayLength = DATALENGTH;

    int array[N_AVG_SAMPLES];
    int i;
    array[0]= 0;
    array[1]= 0;
    for (i=0; i < arrayLength; i++){
    	getAverage(array, N_AVG_SAMPLES);
    }


return (0);
}

// Array functions
int getAverage(int array[], unsigned int arrayLength){
	int sample = 0;
	int i;
	for(i =0; i< arrayLength; i++){
		sample += array[i];
	}
	return (sample/arrayLength);
}



int max(int array[], unsigned int arrayLength){
	int max;
	max= array[0];
	int i;
	for(i=1; i<arrayLength; i++)
		if(array[i]>max){
			max=array[i];
		}
	return(max);
}
int min(int array[], unsigned int arrayLength){
	int min;
	min=array[0];
	int i;
	for(i=1; i<arrayLength; i++)
		if(array[i]>min){
				min=array[i];
			}
		return(min);
	}

unsigned int range(int array[], unsigned int arrayLength){
	int End;
	int Begin;

	End = max(array, arrayLength);
	Begin = min(array, arrayLength);

	return( End - Begin);
}
