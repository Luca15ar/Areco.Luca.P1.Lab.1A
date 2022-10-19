/*
 ============================================================================
 Name        : 22.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Ingreso_de_datos.h"

int main(void)
{
	setbuf(stdout, NULL);

	eMascota mascotas[5];

	eTipo tipos[5] = {{1000, "Ave"},
					 {1001, "Perro"},
					 {1002, "Roedor"},
					 {1003, "Gato"},
					 {1004, "Pez"}};

	eColor colores[5] = {{5000, "Negro"},
						{5001, "Blanco"},
						{5002, "Rojo"},
						{5003, "Gris"},
						{5004, "Azul"}};

	eServicio servicios[3] = {{20000, "Corte", 450},
							 {20001, "Desparasitado", 800},
							 {20002, "Castrado", 600}};

	inicializarMascotas(mascotas, 5);

	char seguir = 's';
	int nextIdMascota = 100;

	do
	{
		switch(menu())
		{
		case 1:
			if(altaMascota(&nextIdMascota, mascotas, 5))
			{
				printf("¡¡Alumno agregado con éxito!!");
				}
				else
				{
					printf("Ocurrió un problema al dar de alta.");
				};
			break;
		case 2:
			modificarMascota(mascotas, 5, tipos, 5);
			break;
		case 3:
			bajaMascota(mascotas, 5, tipos, 5);
			break;
		case 4:
			listarMascotas(&mascotas, 5, tipos, 5);
			break;
		case 5:
			listarTipos(&mascotas, 5, tipos, 5);
			break;
		case 6:
			listarColores(&mascotas, 5, colores, 5);
			break;
		case 7:
			listarServicios(&mascotas, 5, servicios, 5);
			break;
		case 10:
			confirmarSalida(&seguir, 'n', 's');
			break;
		default:
			printf("Opcion invalida\n");
			system("pause");
		}
	}
	while(seguir == 's');

	return EXIT_SUCCESS;
}


