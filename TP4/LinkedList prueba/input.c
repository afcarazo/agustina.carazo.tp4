#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "input.h"

static int esNumerica(char* cadena);
static int myGets(char* cadena, int longitud);
static int getInt(int* pResultado);
static int getString(char* cadena, int longitud);
static int esLetra(char* cadena, int len);
static int getChar(char* pResultado, int len);
static int getNombre(char* pResultado, int longitud);
static int esNombre(char* cadena,int longitud);
/**
 * \brief verifica si la cadena ingresada es numerica
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado
 * \return Retorna 0 si se obtiene un numero entero y -1 si no
*
*/
static int getInt(int* pResultado)
{
    int retorno=-1;
    char buffer[64];
    if(pResultado != NULL)
    {
        if(myGets(buffer,sizeof(buffer))==0 && esNumerica(buffer))
        {
            *pResultado = atoi(buffer);
            retorno = 0;
        }
    }
    return retorno;
}
/**
* \brief Verifica si la cadena ingresada es numerica
* \param cadena Cadena de caracteres a ser analizada
* \return retorna 1 si la cadena es numerica y 0 si no lo es
*/
static int esNumerica(char* cadena)
{
    int i=0;
    int retorno = 1;
    if(cadena != NULL && strlen(cadena) > 0)
    {
        while(cadena[i] != '\0')
        {
            if(cadena[i] < '0' || cadena[i] > '9' )
            {
                retorno = 0;
                break;
            }
            i++;
        }
    }
    return retorno;
}

/**
 * \brief Lee de stdin hasta que encuentra '\n' o hasta que haya copiado en cadena un máximo de 'longitud - 1' caracteres.
 *
 * \param pResultado Puntero a donde se copiara la cadena obtenida
 * \param longitud Define el tamaño de cadena
 * \return Retorna 0  si se obtiene una cadena de lo contrario -1
*
*/
static int myGets(char* cadena, int longitud)
{
    if(cadena != NULL && longitud >0 && fgets(cadena,longitud,stdin)==cadena)
    {
        fflush(stdin);
        if(cadena[strlen(cadena)-1] == '\n')
        {
            cadena[strlen(cadena)-1] = '\0';
        }
        return 0;
    }
    return -1;
}

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;
	do
	{
		printf("%s",mensaje);
		if(	getInt(&bufferInt) == 0 &&
			bufferInt >= minimo &&
			bufferInt <= maximo)
		{
			retorno = 0;
			*pResultado = bufferInt;
			break;
		}
		printf("%s",mensajeError);
		reintentos--;
	}while(reintentos>=0);

	return retorno;
}


/**
 * \brief 	Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena un máximo de 'longitud - 1' caracteres.
 *
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tamaño de cadena
 * \return Retorna 0 si se obtiene una cadena y -1  si no
 *
 */
static int getString(char* cadena, int longitud)
{
    int retorno=-1;
    char bufferString[4096];

    if(cadena != NULL && longitud > 0)
    {
        fflush(stdin);
        if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
        {
            if(bufferString[strlen(bufferString)-1] == '\n')
            {
                bufferString[strlen(bufferString)-1] = '\0';
            }
            if(strlen(bufferString) <= longitud)
            {
                strcpy(cadena,bufferString);
                retorno=0;
            }
        }
    }
    return retorno;
}


/**
 * \brief Obtine una letra
 * \param pValor Puntero a donde se dejara el resultado
 * \return Retorna 0 si se obtiene un numero entero de lo contrario -1
 *
 */
static int getChar(char* pResultado, int len)
{
    int retorno=-1;
    char bufferChar[2];

    if(pResultado != NULL && len >0)
    {
        fflush(stdin);
        if(	getString(bufferChar,sizeof(bufferChar))==0 && esLetra(bufferChar,sizeof(bufferChar)) && strlen(bufferChar)<len)
        {
            strcpy(pResultado,bufferChar);
            retorno = 0;
        }
    }
    return retorno;
}
/**
 * \brief Verifica si es una letra
 * \param pValor Puntero de caracter a ser analizado
 * \return Retorna 1 si es una letra, 0 si no lo es
 *
 */
static int esLetra(char* cadena, int len)
{
    int i=0;
    int retorno = 1;
    if(cadena != NULL && len > 0)
    {
        for(i=0 ; cadena[i] != '\0' && i < len; i++)
        {
            if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}
int utn_getChar(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{
    char bufferChar[2];
    int retorno = -1;
    if(pResultado != NULL && longitud >0 && mensaje != NULL && mensajeError != NULL && reintentos > 0)
        while(reintentos>=0)
        {
            reintentos--;
            printf("%s",mensaje);
            if(getChar(bufferChar,sizeof(bufferChar)) == 0 && strlen(bufferChar) < longitud )
            {
                strcpy(pResultado,bufferChar);
                retorno = 0;
                break;
            }
            printf("%s",mensajeError);
        }
    return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es un nombre valido
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 si la cadena es valida de lo contrario 0
 *
 */
static int esNombre(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
/**
 * \brief pide un nombre al usuario tras verificarlo devuelve el resultado
 * \param pResultado puntero a donde se dejara el resultado
 * \param longitud longitud del array resultado
 * \param mensaje  mensaje a ser mostrado
 * \param mensajeError  mensaje de Error a ser mostrado
 * \param reintentos cantidad de reintentos
 * \return Retorna 0 si se obtuvo el numero flotante de lo contrario -1
 *
 */
static int getNombre(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(	getString(buffer,sizeof(buffer))==0 &&
    		esNombre(buffer,sizeof(buffer)) &&
			strlen(buffer)<longitud)
    	{
    		strcpy(pResultado,buffer);
			retorno = 0;
		}
    }
    return retorno;
}

int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getNombre(bufferString,sizeof(bufferString)) == 0 && strlen(bufferString) < longitud )
		{
			strcpy(pResultado,bufferString);
			retorno = 0;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}

