
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \return int retorna 1 sino hubo ningun error de lo contrario 0
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
/** \brief Carga los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \return int retorna 1 sino hubo ningun error de lo contrario 0
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \return int retorna 1 sino hubo ningun error de lo contrario 0
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee,int* id);
/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \return int retorna 1 sino hubo ningun error de lo contrario 0
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);
/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \return int retorna 1 sino hubo ningun error de lo contrario 0
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);
/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \return int retorna 1 sino hubo ningun error de lo contrario 0
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);
/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \return int retorna 1 sino hubo ningun error de lo contrario 0
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);

/** \brief Guarda los datos de los empleados en el archivo empleados.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \return int retorna 1 sino hubo ningun error de lo contrario 0
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

/** \brief Guarda los datos de los empleados en el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \return int retorna 1 sino hubo ningun error de lo contrario 0
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
/** \brief guarda los datos de los empleados en el archivo idEmpleados.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \param id int del empleado
 * \return int retorna el siguiente id que se usara
 *
 */
int controller_saveAsTextIdEmpleado(char* path, LinkedList* pArrayListEmployee, int id);

