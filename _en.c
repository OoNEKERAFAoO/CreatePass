/*
 * CreatePass 1.0 (Linux)
 * If you do not know how to make a secure password, CreatePass may be your solution.
 * 
 * Create by NEKERAFA on sat, 25 jun 2011 13:25:22 (CEST) 
 * Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Spain 2011 NEKERAFA (nekerafa@gmail.com)
 * http://creativecommons.org/licenses/by-nc-sa/3.0/es/legalcode.es
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define VERSION 1.01
#define CREATOR "NEKERAFA"
#define SYSTEM "Linux"

int size;
int cycle;
int advice;
int symbols = 0;
int numbers = 0;
int letters = 0;
char password[31];

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
	printf("How big is your password? (Max. 32 characteres)\n");
	
	scanf("%i", &size);
	size--;
	if(size>15) {
		size = 15;
	}

	printf("Your password: ");
	for(cycle=0; cycle<=size; cycle++) {
			password[cycle] = randomer(33,126);
			if (password[cycle] >= 48 && password[cycle] <= 57) {
				numbers++;
			}
			else if	(password[cycle] >= 65 && password[cycle] <= 90 || password[cycle] >= 97 && password[cycle] <= 122) {
				letters++;
			}
			else {
				symbols++;
			}
			printf("%c", password[cycle]);
	}
	
	// Print password
	if (numbers >= letters && numbers >= symbols) {
		printf(" (Safely*)\n	*Recommending re-generate the password.\n\n");
	}
	else if (letters >= numbers && letters >= symbols) {
		printf(" (Safely)\n\n");
	}
	else if (symbols >= letters && symbols >= numbers) {
		printf(" (Very Safely\n\n");
	}
	else {
		printf(" (Excellent)\n\n");
	}

	// Print a advice for use a password
	advice = randomer(1,4);
	switch (advice) {
		case 1:
			printf("Advice: Although you supply a password, you should change it regularly.\n");
			break;
		case 2:
			printf("Did you know that among the most popular passwords in history are passwords of type '1234' or '0000'?\n");
			break;
		case 3:
			printf("Advice: Never write a password with your name or that is composed by numbers. For more security we recommend insert uppercase and lowercase letters and symbols.\n");
			break;
		case 4:
			printf("Did you know firsts passwords were \"passwords\" that use sentinels?\n");
			break;
		}

	getchar();
	return 0;
}