
#include "stdafx.h"
#include "string.h"
#include <stdio.h>

typedef struct TAlumno
{
	char nombre[40];
	int telefono;
	int  edad;
}TAlumno;

void escribirFichero(struct TAlumno tabla[6],
	char nFichero[40])
{
	FILE *pf;

	fopen_s(&pf,nFichero, "wt");
	for (int i = 0;i < 6;i++)
	{
		fprintf(pf, "%s\n%s\n%d\n",
			tabla[i].nombre,
			tabla[i].telefono,
			tabla[i].edad);
	}
	fclose(pf);
}

void leerFichero(struct TAlumno tabla[6],
	char nFichero[40])
{
	FILE *pf;

	fopen_s(&pf, nFichero, "rt");
	for (int i = 0;i < 6;i++)
	{
		fgets(tabla[i].nombre, 40, pf);
		fgets(tabla[i].telefono, 40, pf);
		fscanf_s(pf,"%d\n",&(tabla[i].edad));
	}
	fclose(pf);
}

int main()
{
	struct TAlumno MiTabla[6];

	for (int i = 0;i < 6;i++)
	{
		MiTabla[i].nombre[0] = '\0';
		MiTabla[i].telefono[0] = '\0';
		MiTabla[i].edad = 0;
	}
	

	leerFichero(MiTabla, "E:\2ºDam\Acceso a datos\Programas en C\clase.txt");

	return EXIT_SUCCESS;
}

