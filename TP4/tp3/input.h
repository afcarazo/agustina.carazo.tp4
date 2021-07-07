#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED
/**
 * \brief Solicita un numero al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado untero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje mensaje a ser mostrado
 * \param mensajeError  mensaje de error a ser mostrado
 * \param minimo numero maximo que se aceptara
 * \param maximo numero minimo que se aceptara
 * \return Retorna 0 si se obtuvo el numero de lo contrario -1
 */
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

/**
 * \brief pide una letra al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado puntero al espacio de memoria donde se dejara el resultado
 * \param longitud  longitud del array resultado
 * \param mensaje  mensaje a ser mostrado
 * \param mensajeError  mensaje de error a ser mostrado
 * \param reintentos cantidad de reintentos
 * \return Retorna 0 si se obtuvo una letra de lo contrario -1
 *
 */
int utn_getChar(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);

/**
 * \brief Pide nombre al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado puntero al espacio de memoria donde se dejara el resultado
 * \param longitud longitud del array resultado
 * \param mensaje  mensaje a ser mostrado
 * \param mensajeError  mensaje de error a ser mostrado
 * \param reintentos cantidad de reintentos
 * \return Retorna 0 si se obtuvo una letra de lo contrario -1
 *
 */
int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);


#endif // INPUT_H_INCLUDED
