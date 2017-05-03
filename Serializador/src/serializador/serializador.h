#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>

#include "../servidor/servidor.h"

typedef struct HeaderType{
	uint32_t id;
	uint32_t dimension;
} Header;

void printHeader(Header aux){
	printf("Id: %d\n",aux.id);
	printf("Dimension: %d\n",aux.dimension);
}

void serializar(int client, uint32_t id, uint32_t dimension, char *buff){
	//Cabezara de la informacion
	Header myHeader;
	myHeader.dimension = dimension;
	myHeader.id = id;

	//Muestro lo que voy a enviar
	printHeader(myHeader);
	printf("TEXT IN LOADER == %s\n",buff);

	//Preparo el mensaje
	void *ENVIAR = malloc(myHeader.dimension + sizeof(myHeader));

	memcpy(ENVIAR,&myHeader,sizeof(myHeader));
	memcpy(ENVIAR+sizeof(myHeader),buff,myHeader.dimension);

	//Envio el mensaje
	send_data(client, ENVIAR, sizeof(myHeader) + myHeader.dimension);

}
