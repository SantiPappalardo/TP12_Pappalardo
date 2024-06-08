/*
 * main.c --> TP12
 *
 *  Created on: Jun 6, 2024
 *      Author: Santiago Pappalardo - Grupo 5
 */

#include <stdio.h>
#include "Obtener_Dato.h"
#include "hardware.h"

int main (){
	char c;
	Initialization ();
	do{
		puts ("Por favor ingrese el caracter deseado: ");
		c = ObtenerDato();
		while (c == ERROR){
			puts ("\nPor favor vuelva a ingresar el dato: ");
			c = ObtenerDato();
		}
		if (c >= '0' && c <= '7'){
			int num = c - '0';
			printf ("Se prende el led nro %d\n", num);
			TurnOnLed (num);
		}
		else{
			switch (c){
				case 't':
					puts ("Todos los leds cambian de estado...\n");
					//ChangeStatus();
					break;
				case 'c':
					puts ("Todos los leds se apagan...\n");
					//TurnOffAll ();
					break;
				case 's':
					puts ("Todos los leds se prenden...\n");
					//TurnOnAll();
					break;
				}
		}
	}
	while (c != 'q');

	return 0;
}
