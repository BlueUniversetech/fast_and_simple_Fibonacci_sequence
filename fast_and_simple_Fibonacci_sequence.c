///////////////////////////////////////////////////////////////////
 // @file        fast_and_simple_Fibonacci_sequence.c
 // @brief       Calculating and writing the sentences of the Fibonacci sequence up to the desired sentence, Almost SAFE & FAST.
 // @author      @BlueUniversetech
 // @github      https://github.com/BlueUniversetech
 // @ripo        https://github.com/BlueUniversetech/fast_and_simple_Fibonacci_sequence.git
 // @date        2025-03-28
 // @version     v1.0
///////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void show(int);
int scaler(void);
int getTermNum(int);
void fiboCalc(int, int);

int main() {
	int mood, termNum;
	mood = scaler();
	show(mood);
	char ans = 'y';
	while (ans == 'y') {
		termNum = getTermNum(mood);
		fiboCalc(mood, termNum);
		printf("\n***************************\n");
		printf("\n> Do you want to continue? (y/n) : ");
		ans = _getch();// if your compiler allows it, you can do it with getch() as well
		printf("%c", ans);
		while (getchar() != '\n');//clear the buffer
		while (ans != 'y' && ans != 'n') {
			printf("\nInvalid input. Please enter 'y' or 'n' and presss enter : ");
			scanf_s("%c", &ans);// if your compiler allows it, you can do it with scanf() as well
		}
	}
	return 0;
}
void show(int mood) {
	printf("\n");
	printf("     ==================================================\n");
	printf("     #       fast_and_simple_Fibonacci_sequence       #\n");
	printf("     #                Version: 1.0.0                  #\n");
	printf("     #================================================#\n");
	printf("     #  GitHub:    @BlueUniversetech                  #\n");
	printf("     ==================================================\n");
	printf("\n");
	printf("         _________   _________________________  ____  _________    __    ______\n");
	printf("        / ____/   | / ___/_  __/ ____/  _/ __ )/ __ \\/ ____/   |  / /   / ____/\n");
	printf("       / /_  / /| | \\__ \\ / / / /_   / // __  / / / / /   / /| | / /   / /     \n");
	printf("      / __/ / ___ |___/ // / / __/ _/ // /_/ / /_/ / /___/ ___ |/ /___/ /___   \n");
	printf("     /_/   /_/  |_/____//_/ /_/   /___/_____/\\____/\\____/_/  |_/_____/\\____/   \n");
	printf("\n");
	printf("\n");
	printf("***************************\n");
	printf("Hello! This program is designed for your system to generate\n");
	printf("the terms of the Fibonacci sequence up to a desired number.\n");
	printf("It performs this computation efficiently and quickly.\n");
	printf("Based on your system's capabilities, it can calculate up to the %dth term.\n\n", mood);
	printf("***************************\n");
}
int scaler(void) { // returns last possible term number which is in the range of your standard system
	int size = sizeof(unsigned long long) * 8;
	switch (size) {
	case 8:
		return 13;
	case 16:
		return 24;
	case 32:
		return 47;
	case 64:
		return 93;
	default:
		printf("\n *** ERROR in 'scaler()' function : finding max varable size and reporting failed!!!. Exiting... *** \n");
		exit(1);
	}
}
int getTermNum(int max) {// gets term number with good safety
	int term;
	while (1) {
		printf("\n >> Enter the last number of sequense term and press Enter (MAX = %d) : ", max);
		int resultCheck = scanf("%d", &term);
		if (resultCheck == EOF) {
			printf("\nInput terminated by user. Exiting...\n");
			exit(1);
		}
		else if (resultCheck != 1) {
			printf("\nInvalid input! Expected a number (between 1 and %d).\n", max);
			while (getchar() != '\n');//clear the buffer
		}
		else if (term < 1 || term > max) {
			printf("\nNumber out of range! Please enter a number (between 1 and %d).\n", max);
			while (getchar() != '\n');//clear the buffer
		}
		else break;// good job.
	}
	return term;
}
void fiboCalc(int maxSize, int lastTerm) {
	unsigned long long* x1 = malloc((maxSize / 8) * 2);// creates two neighboring memory blocks
	if (x1 == NULL) {
		printf("\n *** ERROR : Memory allocation failed! Exiting... *** \n");
		exit(1);
	}
	unsigned long long* x2 = x1 + 1;// setting the address of neighbor pointer
	*x1 = 1, * x2 = 0;
	for (register int i = 1;i <= lastTerm;++i) {
		*x1 = *x1 + *x2;
		*x2 = *x1 - *x2;
		printf(" F(%d) = ", i);
		printf("%llu\n", *x2);
	}
	free(x1);// freeing memory taken with malloc
}
