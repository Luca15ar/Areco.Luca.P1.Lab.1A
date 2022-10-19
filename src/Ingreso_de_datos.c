/*
 * Ingreso_de_datos.c
 *
 *  Created on: 19 oct 2022
 *      Author: Luqui
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Ingreso_de_datos.h"

int menu()
{
	int opcion;

	    system("cls");

	    printf("*** ABM Mascotas ***\n\n");
	    printf("1- Alta Mascota\n");
	    printf("2- Modificar Mascota\n");
	    printf("3- Baja Mascota\n");
	    printf("4- Listar Mascotas\n");
	    printf("5- Listar Tipos\n");
	    printf("6- Listar Colores\n");
	    printf("6- Listar Servicio\n");
	    printf("10- Salir.\n\n");
	    printf("Ingrese opcion: ");
	    scanf("%d", &opcion);

	    return opcion;
}

int confirmarSalida(char* pVariable, char confirma, char rechaza)
{

    int todoBien = 0;
    char respuesta;

    if(pVariable != NULL)
    {

        printf("Esta seguro de que desea salir?: ");
        fflush(stdin);
        scanf("%c", &respuesta);

        if(respuesta == 's')
        {
            *pVariable = confirma;
        }
        else
        {
        	if(respuesta == 'n')
        	{
        		*pVariable = rechaza;
        	}
        	else
        	{
        		printf("Respuesta inválida. Reingrese respuesta: ");
        		fflush(stdin);
        		scanf("%c", &respuesta);
        	}
        }

        todoBien = 1;
    }
    return todoBien;
}

int altaMascota(int* pId, eMascota vecMascota[], int tam_M)
{

    int todoBien = 0;
    int indice;
    eMascota auxMascota;

    if(pId != NULL && vecMascota != NULL && tam_M > 0)
    {

        system("cls");

        printf("**** Alta Mascotas ****\n\n");

        buscarLibre(&indice, vecMascota, tam_M);

        if(indice == -1)
        {
            printf("No hay lugar en el sistema.\n");
        }
        else
        {
            cargarMascota(&auxMascota);

            auxMascota.idMascota = *pId;

            *pId = *pId + 1;

            vecMascota[indice] = auxMascota;

            todoBien = 1;
        }
    }

    return todoBien;
}

int bajaMascota( eMascota vecMascota[], int tam_M, eTipo vecTipo[], int tam_T)
{

    int todoOk = 0;
    int idMascota;
    int indice;
    char confirma;

    if(vecMascota != NULL && tam_M > 0 && vecTipo != NULL && tam_T > 0)
    {

        system("cls");

        printf("**** Baja Mascota ****\n\n");

        mostrarMascotas(vecMascota, tam_M, 0, vecTipo, tam_T);

        printf("Ingrese id de la mascota a dar de baja: ");
        scanf("%d", &idMascota);

        buscarMascota(&indice, idMascota, vecMascota, tam_M);
        if(indice == -1)
        {
            printf("No existe una mascota con ese id: %d\n", idMascota);
        }
        else
        {
        	for(int i = 0; i < tam_M; i++)
        	{
        		mostrarMascota(vecMascota[i], vecTipo, tam_T);
        	}

            printf("¿Confirma la baja de esta mascota?: ");
            fflush(stdin);
            confirma = getchar();

            if(confirma == 's')
            {
                vecMascota[indice].isEmpty = 1;
                printf("Baja exitosa.\n");
            }
            else
            {
                printf("Se ha cancelado la baja.\n");
            }
        }

        todoOk = 1;
    }
    return todoOk;
}

int mostrarMascotas(eMascota vecMascota[], int tam_M, int limpiar, eTipo vecTipo[], int tam_T)
{
	int todoBien = 0;

    int flag = 1;

    if(vecMascota != NULL && tam_M > 0 && vecTipo != NULL && tam_T > 0 && limpiar >= 0 && limpiar <= 1)
    {
        if(limpiar)
        {
            system("cls");
        }

        printf("		**** Lista de mascotas ****\n");
        printf("ID		Nombre			Tipo		Color		Servicio		Edad\n");

        for(int i = 0 ; i < tam_M ; i++)
        {
            if(!vecMascota[i].isEmpty)
            {
                mostrarMascota(vecMascota[i], vecTipo, tam_T);
                flag = 0;
            }
        }

        printf("\n\n");

        if(flag)
        {
            printf("No hay mascotas en el sistema.\n\n");
        }

        todoBien = 1;
    }

	return todoBien;
}

int mostrarMascota(eMascota mascota, eTipo vecTipo[], int tam_T)
{
	int todoBien = 0;
	if(vecTipo != NULL && tam_T > 0)
	{
		printf("%3d		%20s	%4d		%4d		%2d", mascota.idMascota, mascota.nombre, mascota.idTipo, mascota.idColor, mascota.edad);

		todoBien = 1;
	}

	return todoBien;
}

int inicializarMascotas(eMascota vecMascota[], int tam_M)
{
    int todoOk = 0;

    if(vecMascota != NULL && tam_M > 0)
    {
        for(int i = 0 ; i < tam_M ; i++)
        {
            vecMascota[i].isEmpty = 1;
        }

        todoOk = 1;
    }

    return todoOk;
}

int buscarLibre(int* pIndice, eMascota vecMascota[], int tam_M)
{
    int todoBien = 0;
    int indice = -1;

    if(pIndice != NULL && vecMascota != NULL && tam_M > 0)
    {
        for(int i = 0 ; i < tam_M ; i++)
        {
            if( vecMascota[i].isEmpty)
            {
                indice = i;
                break;
            }
        }
        *pIndice = indice;

        todoBien = 1;
    }

    return todoBien;
}

int buscarMascota(int* pIndice, int idMascota, eMascota vecMascotas[], int tam_M)
{
    int todoBien = 0;
    int indice = -1;

    if(pIndice != NULL && vecMascotas != NULL && tam_M > 0)
    {
        for(int i = 0 ; i < tam_M ; i++)
        {
            if(!vecMascotas[i].isEmpty && vecMascotas[i].idMascota == idMascota)
            {
                indice = i;
                break;
            }
        }

        *pIndice = indice;

        todoBien = 1;
    }

    return todoBien;
}

int cargarMascota(eMascota* pMascota)
{
    int todoOk = 0;

    if(pMascota != NULL)
    {
        printf("Ingrese nombre: ");
        fflush(stdin);
        scanf("%s", pMascota->nombre);

        printf("Ingrese edad: ");
        scanf("%d", &pMascota->edad);

        printf("Ingrese id Tipo: ");
        scanf("%d", &pMascota->idTipo);
        if(pMascota->idTipo < 1000)
        {
            printf("Id Tipo inválido. Reingrese id Tipo: ");
            scanf("%d", &pMascota->idTipo);
        }

        printf("Ingrese id Color: ");
        scanf("%d", &pMascota->idColor);
        if(pMascota->idColor < 5000)
        {
            printf("Id Color inválido. Reingrese id Color: ");
            scanf("%d", &pMascota->idColor);
        }

        printf("¿Está vacunado? Responda: ");
        fflush(stdin);
        scanf("%c", &pMascota->vacunado);

        pMascota->isEmpty = 0;

        todoOk = 1;
    }

    return todoOk;
}

int modificarMascota( eMascota vecMascotas[], int tam_M, eTipo vecTipos[], int tam_T)
{

    int todoBien = 0;
    int idMascota;
    int indice;
    char confirma;
    char nuevoNombre[20];

    if(vecMascotas != NULL && tam_M > 0 && vecTipos != NULL && tam_T > 0)
    {

        system("cls");
        printf("**** Modificar Mascota ****\n\n");

        mostrarMascotas(vecMascotas, tam_M, 0, vecTipos, tam_T);

        printf("Ingrese id de la mascota a modificar: ");
        scanf("%d", &idMascota);

        buscarMascota(&indice, idMascota, vecMascotas, tam_M);
        if(indice == -1)
        {
            printf("No existe una mascota con ese id: %d\n", idMascota);
        }
        else
        {
            mostrarMascota(vecMascotas[indice], vecTipos, tam_M);

            printf("Ingrese nuevo nombre: ");
            scanf("%s", nuevoNombre);

            printf("¿Confirma modificación?: ");
            fflush(stdin);
            confirma = getchar();

            if(confirma == 's')
            {
                strcpy(vecMascotas[indice].nombre, nuevoNombre);
                printf("Modificacion exitosa.\n");
            }
            else
            {
                printf("Se ha cancelado la modificacion.\n");
            }
        }

        todoBien = 1;
    }

    return todoBien;
}

int mostrarTipos(eTipo tipo[], int tam_T)
{
	int todoBien = 0;
	if(tipo != NULL && tam_T > 0)
	{
		printf("	***Lista de tipos***	\n"
				"ID			Tipo\n");
		for(int i = 0; i < tam_T; i++)
		{
			printf("%d		%s\n", tipo[i].idTipo, tipo[i].descripcion);
		}

		todoBien = 1;
	}
	return todoBien;
}
int mostrarColores(eColor colores[], int tam_C)
{
	int todoBien = 0;
	if(colores != NULL && tam_C > 0)
	{
		printf("	***Lista de colores***	\n"
				"ID			Tipo\n");
		for(int i = 0; i < tam_C; i++)
		{
			printf("%d		%s\n", colores[i].idColor, colores[i].nombreColor);
		}

		todoBien = 1;
	}
	return todoBien;
}
int mostrarServicios(eServicio servicios[], int tam_S)
{
	int todoBien = 0;

	if(servicios != NULL && tam_S > 0)
	{
		printf("	***Lista de Servicios***	\n"
				"ID			Tipo\n");
		for(int i = 0; i < tam_S; i++)
		{
			printf("%d		%s		%.2f\n", servicios[i].idServicio, servicios[i].descripcion, servicios[i].precio);
		}

		todoBien = 1;
	}

	return todoBien;
}

int listarTipos(eMascota mascotas[], int tam_M, eTipo tipos[], int tam_T)
{
	int todoBien = 0;

    if(mascotas != NULL && tipos != NULL && tam_M > 0 && tam_T > 0)
    {
        printf("    **Lista de tipos**\n");

        for(int i =0; i < tam_T; i++)
        {
            printf("Tipo: %s\n", tipos[i].descripcion);
            mostrarTipos(tipos, tam_T);
        }

        todoBien = 1;
    }

	return todoBien;
}
int listarColores(eMascota mascotas[], int tam_M, eColor colores[], int tam_C)
{
	int todoBien = 0;

    if(mascotas != NULL && colores != NULL && tam_M > 0 && tam_C > 0)
    {
    	printf("    **Lista de colores**\n");
        for(int i =0; i < tam_C; i++)
        {
            printf("Color: %s\n", colores[i].nombreColor);
            mostrarColores(colores, tam_C);
        }

        todoBien = 1;
    }

	return todoBien;
}

int listarServicios(eMascota mascotas[], int tam_M, eServicio servicios[], int tam_S)
{
	int todoBien = 0;
	eServicio servicio;

    if(mascotas != NULL && servicios != NULL && tam_M > 0 && tam_S > 0)
    {
        system("cls");
        printf("    **Lista de servicios**\n");

        mostrarServicios(&servicio, tam_S);

        todoBien = 1;
    }

	return todoBien;
}

int listarMascotas(eMascota mascotas[], int tam_M, eTipo tipos[], int tam_C)
{
	int todoBien = 0;
	//int idMascotas;

    if(mascotas != NULL && tipos != NULL && tam_M > 0 && tam_C > 0)
    {


        todoBien = 1;
    }

	return todoBien;
}
