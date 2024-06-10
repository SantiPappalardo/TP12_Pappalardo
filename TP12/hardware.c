#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "hardware.h"

FILE * archivo;
int mapeo [8] = {17, 4 , 18, 23, 24, 25, 22, 27};

void Initialization (){
	int i;
	for (i = 0; i < 8; i++){
		if ((archivo = fopen("/sys/class/gpio/export", "w")) == NULL){
			puts ("No es posible acceder al archivo deseado\n");
			exit (1);
		}
		sleep (1);
		char npin [MAX];
		char arr [MAX];
		int export_tool;
		snprintf (npin, MAX, "%d", mapeo [i]);
		export_tool = fputs (npin, archivo);
		if (export_tool == -1){
			printf ("No es posible exportar el pin nro %d\n", mapeo [i]);
			exit (1);
		}
		snprintf (arr, MAX, "sys/class/gpio/gpio%d/direction", mapeo [i]);
		if ((archivo = fopen (arr, "w")) == NULL){
			puts ("No es posible abrir la direccion del archivo deseado\n");
			exit (1);
		}
		if ((export_tool= fputs ("out", archivo)) == -1){
			printf ("No es posible exportar el pin nro %d como output\n", mapeo [i]);
		}
		fclose (archivo);
	}
}


void TurnOnLed (int led){
	char arr [MAX];
	snprintf (arr, MAX, "/sys/class/gpio/gpio%d/value", mapeo[led]);
	if ((archivo = fopen (arr, "w")) == NULL){
		printf ("No es posible acceder al pin nro %d\n", mapeo[led]);
		exit (1);
	}
	if (putc ('1', archivo) == -1){
		printf ("No es posible prender el led nro %d\n", led);
		exit (1);
	}
	fclose (archivo);
}

void ChangeStatus (){
	FILE * copia_archivo;
	char status;
	int i;
	for (i = 0; i < 8; i++){
		char arr [MAX];
		snprintf (arr, MAX, "/sys/class/gpio/gpio%d/value", mapeo [i]);
		if ((archivo = fopen (arr, "r+")) == NULL){
			printf ("No es posible acceder al pin nro %d\n", mapeo [i]);
			exit (1);
		}
		copia_archivo = archivo;
		status = fgetc (copia_archivo);
		if (status == '1'){
			if (putc ('0', archivo) == -1){
				printf ("No es posible apagar el led nro %d\n", i);
				exit (1);
			}
		}
		else{
			if (putc ('1', archivo) == -1){
				printf ("No es posible prender el led nro %d\n", i);
				exit (1);
			}
		}
		fclose (archivo);
		fclose (copia_archivo);
	}
}

void TurnOffAll (){
	int i;
	for (i = 0; i < 8; i++){
		char arr [MAX];
		snprintf (arr, MAX, "/sys/class/gpio/gpio%d/value", mapeo [i]);
		if ((archivo = fopen (arr, "w")) == NULL){
			printf ("No es posible acceder al pin nro %d\n", mapeo [i]);
			exit (1);
		}
		if (putc ('0', archivo) == -1){
			printf ("No es posible apagar el led nro %d\n", i);
		}
		fclose (archivo);
	}
}



void TurnOnAll (){
	int i;
	for (i = 0; i < 8; i++){
		char arr [MAX];
		snprintf (arr, MAX, "/sys/class/gpio/gpio%d/value", mapeo [i]);
		if ((archivo = fopen (arr, "w")) == NULL){
			printf ("No es posible acceder al pin nro %d\n", mapeo [i]);
			exit (1);
		}
		if (putc ('1', archivo) == -1){
			printf ("No es posible prender el led nro %d\n", i);
		}
		fclose (archivo);
	}
}
