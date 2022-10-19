/*
 * Ingreso_de_datos.h
 *
 *  Created on: 19 oct 2022
 *      Author: Luqui
 */

#ifndef INGRESO_DE_DATOS_H_
#define INGRESO_DE_DATOS_H_

typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

typedef struct
{
    int idTipo;
    char descripcion[20];
} eTipo;

typedef struct
{
    int idColor;
    char nombreColor[20];
} eColor;

typedef struct
{
    int idMascota;
    char nombre[20];
    int idTipo; //Validar
    int idColor; //Validar
    int edad;
    char vacunado; //("s" o "n")
    int isEmpty;
} eMascota;

typedef struct
{
    int idServicio;
    char descripcion[25];
    float precio;
} eServicio;

typedef struct
{
    int idTrabajo; // incremental
    eMascota; // Validar
    eServicio; // Validar
    eFecha;
} eTrabajo;


#endif /* INGRESO_DE_DATOS_H_ */

int menu();

int confirmarSalida(char* pVariable, char confirma, char rechaza);

int inicializarMascotas(eMascota vecMascota[], int tam_M);
int buscarLibre(int* pIndice, eMascota vecMascota[], int tam_M);
int buscarMascota(int* pIndice, int idMascota, eMascota vecMascotas[], int tam_M);

int altaMascota(int* pId, eMascota vecMascota[], int tam_M);
int bajaMascota( eMascota vecMascota[], int tam_M, eTipo vecTipo[], int tam_T);

int mostrarMascotas(eMascota vecMascota[], int tam_M, int limpiar, eTipo vecTipo[], int tam_T);
int mostrarMascota(eMascota mascota, eTipo vecTipo[], int tam_T);

int mostrarTipos(eTipo tipo[], int tam_T);
int mostrarColores(eColor colores[], int tam_C);
int mostrarServicios(eServicio servicios[], int tam_S);

int cargarMascota(eMascota* pMascota);

int modificarMascota(eMascota vecMascotas[], int tam_M, eTipo vecTipos[], int tam_T);

int listarMascotas(eMascota mascotas[], int tam_M, eTipo tipos[], int tam_C);
int listarTipos(eMascota mascotas[], int tam_M, eTipo tipos[], int tam_C);
int listarColores(eMascota mascotas[], int tam_M, eColor tipos[], int tam_C);
int listarServicios(eMascota mascotas[], int tam_M, eServicio tipos[], int tam_C);
