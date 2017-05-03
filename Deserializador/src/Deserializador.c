/*
 ============================================================================
 Name        : Deserializador.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "servidor/servidor.h"
#include "serializador/serializador.h"

int main(void) {
	//Conexion al servidor FileSystem
	int servidor = connect_server("127.0.0.1",5002);

	char *buff = deserializar(servidor);

	//Muestro lo que recibi
	printf("TEXT RECEIVER == %s\n",buff);

	return EXIT_SUCCESS;
}
