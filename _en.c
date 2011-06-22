/*
 * CreatePass 1.0 (Linux)
 * If you do not know how to make a secure password, CreatePass may be your solution. This is the Linux version.
 * 
 * Create by NEKERAFA on thu, 22 jun 2011 00:20:31 (CEST)
 * Copyleft 2011 NEKERAFA (nekerafa@gmail.com)
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define VERSION 1.0
#define CREATOR "NEKERAFA"
#define SYSTEM "Linux"

int size;
int cycle;
int character;
int password[15];

// Randomer: Create a random number
int randomer(int from, int until) {
	// Save random number
	int random_value;
	// Set random value
	random_value = rand()%(until-from+1) + from;

	return random_value;
}

int main() {
	// Seed of random numbers
	srand(time(NULL));

	// Main of programme, print greeting
	printf("CreatePass %.2f (%s)\nCopyleft %s 2011\n\n", VERSION, SYSTEM, CREATOR);
	printf("How big is your password? (Max. 16 characteres)\n");
	
	scanf("%i", &size);
	size--;
	if(size>15) {
		size = 15;
	}

	printf("Your password: ");
	for(cycle=0; cycle<=size; cycle++) {
		character = randomer(0,2);
		switch(character) {
			case 0:
				password[cycle] = randomer(0,9);
				printf("%i", password[cycle]);
				break;
			case 1:
				password[cycle] = randomer(65,90);
				printf("%c", password[cycle]);
				break;
			case 2:
				password[cycle] = randomer(97,122);
				printf("%c", password[cycle]);
				break;
		}
	}
	printf("\n");
	
	return 0;
}
