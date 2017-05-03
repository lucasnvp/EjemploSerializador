/*
 ============================================================================
 Name        : Serializador.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Serializador
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#include "servidor/servidor.h"
#include "serializador/serializador.h"

#define CANTCONECIONES 10 	// Si quiero el maximo de conexiones posibles en el sockect reemplazar por 'SOMAXCONN'

int main(void) {
	//Creacion del servidor
	int servidor = build_server(5002, CANTCONECIONES);

	//El socket esta listo para escuchar
	if(servidor > 0){
		printf("Servidor Escuchando\n");
	}

	// acepto una nueva conexion
	int cliente = accept_conexion2(servidor);

	//Reservo la memoria de lo que voy a enviar
	char *buff=malloc(256);
	fgets(buff,256,stdin);
	int dimen = strlen(buff) - 1;

	//Serializo
	serializar(cliente, 1, dimen, buff);

	return EXIT_SUCCESS;
}
