#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \return int retorna 1 sino hubo ningun error de lo contrario 0
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee);

/** \brief Parsea los datos los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \return int  retorna 1 sino hubo ningun error de lo contrario 0
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee);
#endif // PARSER_H_INCLUDED
