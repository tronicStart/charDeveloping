#ifndef CFILE_H
#define CFILE_H

#include <stdio.h>

void _create_file(const char *file, const char *data, int mode)
{
    FILE *archivo;
    char  variable[1025];

    if (mode == 0)
    { // modo W

        archivo = fopen(file, "w");

        if (archivo == NULL)
        {
            perror("Escrity ");
            return;
        }

        printf("Escrity: guardado: '%s'", file);
        fprintf(archivo, "%s", data);
        fclose(archivo);

        return;
    }

    else if (mode == 1)
    { //mode WB

        archivo = fopen(file, "wb");

        if (archivo == NULL)
        {
            perror("Escrity ");
            return;
        }

        printf("Escrity: guardado: '%s'", file);
        fprintf(archivo, "%s", data);
        fclose(archivo);

        return;
    }

    if (mode == 2)
    { //mode A

        archivo = fopen(file, "a");

        if (archivo == NULL)
        {
            perror("Escrity ");
            return;
        }

        printf("Escrity: guardado: '%s'", file);
        fprintf(archivo, "%s", data);
        fclose(archivo);

        return;
    }

    else if (mode == 3)
    { //modo R

        archivo = fopen(file, "r");
        
        if (file == NULL)
        {
            perror("Escrity ");
            printf("Directorio o Archivo: [\" ");
            printf("%s", file);
            printf(". \"] \n");
        }

        else
        {
            while (feof(file) == 0)
            {
                fgets(variable, 1025, file);
                printf("%s", variable);
            }
        }
        fclose(file);

        return;
    }

    if (mode == -1)
    { //modo RB

        archivo = fopen(file, "rb");
        
        if (file == NULL)
        {
            perror("Escrity ");
            printf("Directorio o Archivo: [\" ");
            printf("%s", file);
            printf(". \"] \n");
        }

        else
        {
            while (feof(file) == 0)
            {
                fgets(variable, 1025, file);
                printf("%s", variable);
            }
        }
        fclose(file);

        return;
    }
}

int delete_file(const char *url){
    
    if (remove(url) == -1)
	{
		printf("Escrity : 'error delete' \n");
		return -1;
	}
	else
	{
		printf("Escrity : Archivo : %s eliminado.\n", url);
		return 0;
	}
    
}

void StringReadFileModeRB(const char *URL){
    
    FILE *lectura;
	char variable[1025];

	lectura = fopen(URL, "rb");

	if (lectura == NULL)
	{
		perror("Escrity ");
		printf("Directorio o Archivo: [\" ");
		printf("%s", URL);
		printf(". \"] \n");
	}
	else
	{
		while (feof(lectura) == 0)
		{
			fgets(variable, 1025, lectura);
			printf("%s", variable);
		}
	}
	fclose(lectura);
    
}

void read_file_how_Error(const char *URL){
    
    FILE *lectura;
	char variable;

	lectura = fopen(URL, "r");

	if (lectura == NULL)
	{
		perror("Escrity ");
		printf("Directorio o Archivo: [\" ");
		printf("%s",URL);
		printf(". \"] \n");
	}
	else
	{
		while (feof(lectura) == 0)
		{
			variable = fgetc(lectura);
			printf("%c", variable);
		}
	}
	fclose(lectura);
    
}

void read_file(const char *URL){
    
    FILE *lectura;
	char variable[1024];

	lectura = fopen(URL, "rb");

	if (lectura == NULL)
	{
		perror("Escrity ");
	}
	else
	{
		while (feof(lectura) == 0)
		{
			fgets(variable, 1024, lectura);
			printf("%s", variable);
		}
	}
	fclose(lectura);
    
}

#endif
