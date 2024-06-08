#include <stdio.h>
#include "Obtener_Dato.h"

char ObtenerDato(){
	char c, d;
	int cont = 0;
	while ((c = getchar()) != '\n'){
		cont ++;
		d = c;
	}
	if (( (d<'0' || d>'7') && d!='t' && d!='c' && d!='s' && d!='q')|| cont != 1 ){
		return ERROR;
	}
	else{
		return d;
	}
}
