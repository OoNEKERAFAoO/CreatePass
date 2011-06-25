/*
 * CreatePass 1.0 (Linux)
 * Si no sabes cómo hacer una contraseña segura, CreatePass puede ser su solución.
 * 
 * Creado por NEKERAFA el sáb, 25 jun 2011 13:25:22 (CEST) 
 * Creative Commons Reconocimiento-NoComercial-CompartirIgual 3.0 España, 2011 NEKERAFA (nekerafa@gmail.com)
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
	printf("CreatePass %.2fv (%s)\nCopyleft %s 2011\n\n", VERSION, SYSTEM, CREATOR);
	printf("¿Cómo de grande es su contraseña? (Máx. 32 caracteres)\n");

	scanf("%i", &size);
	size--;
	if(size>31) {
		size = 31;
	}

	// Create the password
	printf("Su contraseña: ");
	for(cycle=0; cycle<=size; cycle++) {
			password[cycle] = randomer(33,126);
			if (password[cycle] >= 48 && password[cycle] <= 57) {
				numbers++;
			}
			else if	((password[cycle] >= 65 && password[cycle] <= 90) || (password[cycle] >= 97 && password[cycle] <= 122)) {
				letters++;
			}
			else {
				symbols++;
			}
			printf("%c", password[cycle]);
	}
	
	// Print password
	if (numbers >= letters && numbers >= symbols) {
		printf(" (Segura*)\n	*Se recomendaría volver a generar la contraseña.\n\n");
	}
	else if (letters >= numbers && letters >= symbols) {
		printf(" (Segura)\n\n");
	}
	else if (symbols >= letters && symbols >= numbers) {
		printf(" (Muy Segura)\n\n");
	}
	else {
		printf(" (Excelente)\n\n");
	}

	// Print a advice for use a password
	advice = randomer(1,4);
	switch (advice) {
		case 1:
			printf("Consejo: Aunque se le proporcione una contraseña segura, es recomendable cambiarla con regularidad.\n");
			break;
		case 2:
			printf("¿Sabía que entre las contraseñas más populares de la historia figuran contraseñas del tipo '1234' o incluso '0000'.\n");
			break;
		case 3:
			printf("Consejo: nunca escriba en una contraseña su nombre propio o que este compuesta por numeros. Para más seguridad se recomienda intercalar mayúsculas, minúsculas y símbolos.\n");
			break;
		case 4:
			printf("¿Sabía que las primeras contraseñas eran el  \"Santo y seña\" que utilizaban los centinelas?\n");
			break;
		}

	getchar();
	return 0;
}