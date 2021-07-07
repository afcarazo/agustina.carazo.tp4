#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "LinkedList.h"
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief devuelve puntero a nuevo empleado e inicializa los campos de la estructura en 0
 *
 * \return Employee* retorna  puntero a nuevo empleado si consiguio espacio sino NULL
 *
 */
Employee* employee_new();
/** \brief permite reservar memoria para un empleado y dar valor inicial a varios campos de la entidad
 *
 * \param idStr char* puntero a id
 * \param nombreStr char* puntero a nombre
 * \param horasTrabajadasStr char* puntero a horas trabajadas
 * \param sueldoStr char* puntero a sueldo
 * \return Employee* retorna puntero a empleado si consiguio espacio sino NULL
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
void employee_delete(Employee* this);

/** \brief asigna id validado al campo id de la identidad
 *
 * \param this Employee* puntero a empleado
 * \param id int id que sera asignado y validado
 * \return int retorna 1 sino hubo ningun error de lo contrario 0
 *
 */
int employee_setId(Employee* this,int id);
/** \brief permite acceder al valor del atributo id de la identidad
 *
 * \param this Employee* puntero a empleado
 * \param id int* puntero a id
 * \return int retorna 1 sino hubo ningun error de lo contrario 0
 *
 */
int employee_getId(Employee* this,int* id);

/** \brief asigna nombre validado al campo nombre de la identidad
 *
 * \param this Employee* puntero a empleado
 * \param nombre char* nombre que sera asignado y validado
 * \return int retorna 1 sino hubo ningun error de lo contrario 0
 *
 */
int employee_setNombre(Employee* this,char* nombre);

/** \brief permite acceder al valor del atributo nombre de la identidad
 *
 * \param this Employee* puntero a empleado
 * \param nombre char* puntero a nombre
 * \return int retorna 1 sino hubo ningun error de lo contrario 0
 *
 */
int employee_getNombre(Employee* this,char* nombre);

/** \brief asigna hora validada al campo horas trabajadas de la identidad
 *
 * \param this Employee* puntero a empleado
 * \param horasTrabajadas int hora que sera asignada y validada
 * \return int retorna 1 sino hubo ningun error de lo contrario 0
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
/** \brief permite acceder al valor del atributo horas trabajadas de la identidad
 *
 * \param this Employee* puntero a empleado
 * \param id int* puntero a horas trabajadas
 * \return int retorna 1 sino hubo ningun error de lo contrario 0
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);


/** \brief asigna sueldo validado al sueldo de la identidad
 *
 * \param this Employee* puntero a empleado
 * \param horasTrabajadas int hora que sera asignada y validada
 * \return int retorna 1 sino hubo ningun error de lo contrario 0
 *
 */
int employee_setSueldo(Employee* this,int sueldo);
/** \brief permite acceder al valor del atributo sueldo de la identidad
 *
 * \param this Employee* puntero a empleado
 * \param id int* puntero a sueldo
 * \return int retorna 1 sino hubo ningun error de lo contrario 0
 *
 */
int employee_getSueldo(Employee* this,int* sueldo);


/** \brief obtiene id mas grande de la lista de empleados
 *
 * \param listaEmpleados LinkedList* lista empleados
 * \param id int* puntero a ID
 * \return int retorna 1 sino hubo ningun error de lo contrario 0
 *
 */
int obtenerIdMasGrande(LinkedList* listaEmpleados,int* id);

/** \brief realiza las validaciones y permite agregar un nuevo empleado
 *
 * \param listaEmpleados LinkedList* lista de empleados
 * \param id* int puntero a id
 * \return int retorna 1 sino hubo ningun error de lo contrario 0
 *
 */
int Employee_add(LinkedList* listaEmpleados,int*id);


/** \brief permite mostrar la lista de empleados
 *
 * \param listaEmpleados LinkedList* lista de empleados
 * \return int retorna 1 sino hubo ningun error de lo contrario 0
 *
 */
int Employee_printAllEmployees(LinkedList* listaEmpleados);

/** \brief permite mostrar un solo empleado
 *
 * \param this Employee*  puntero a empleado
 * \return int retorna 1 sino hubo ningun error de lo contrario 0
 *
 */
int Employee_printAnEmployee(Employee* this);
/** \brief busca el id que se necesita
 *
 * \param listaEmpleados LinkedList* lista de empleados
 * \param id int id a buscar
 * \return int retorna el indice del empleado o -1 sino existe un empleado con ese id
 *
 */
int Employee_findId(LinkedList* listaEmpleados, int id);
/** \brief permite acceder al valor de los atributos de la identidad
 *
 * \param this Employee* puntero a empleado
 * \param id int* puntero a id
 * \param nombre char* puntero a nombre
 * \param horas int* puntero a horas trabajadas
 * \param sueldo int* puntero a sueldo
 * \return int retorna 1 sino hubo ningun error de lo contrario 0
 *
 */
int employee_getVerificar(Employee* this,int* id,char* nombre, int* horas,int* sueldo);
/** \brief  asigna valores validados de la identidad
 *
 * \param this Employee* puntero a empleado
 * \param id int id del empleado
 * \param nombre char* nombre del empleado
 * \param horas int horas trabajadas del empleado
 * \param sueldo int sueldo del empleado
 * \return int retorna 1 sino hubo ningun error de lo contrario 0
 *
 */
int employee_setVerificar(Employee* this,int id,char* nombre, int horas,int sueldo);

/** \brief verifica que el empleado exista, y muestra los atributos que pueden modificarse
 *
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \return int retorna 1 sino hubo ningun error de lo contrario 0
 *
 */
int employee_modificar(LinkedList* pArrayListEmployee);
/** \brief verifica que el empleado a dar de baja exista en el sistema, si es asi permite que se realice la baja
 *
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \return int int retorna 1 sino hubo ningun error de lo contrario 0
 *
 */
int bajaEmpleado(LinkedList* pArrayListEmployee);
/** \brief compara sueldos
 *
 * \param a void* puntero al primer empleado
 * \param b void* puntero al segundo empleado
 * \return int retorna si son iguales (0) cuando el primer elemento es mayor al segundo (1) sino -1
 *
 */
int employee_cmpSueldo(void* a,void* b);
/** \brief compara horas trabajadas
 *
 * \param a void* puntero al primer empleado
 * \param b void* puntero al segundo empleado
 * \return int retorna si son iguales (0) cuando el primer elemento es mayor al segundo (1) sino -1
 *
 */
int employee_cmpHoras(void* a,void* b);

/** \brief compara ID
 *
 * \param a void* puntero al primer empleado
 * \param b void* puntero al segundo empleado
 * \return int retorna si son iguales (0) cuando el primer elemento es mayor al segundo (1) sino -1
 *
 */
int employee_cmpId(void* a,void* b);

/** \brief permite editar un nombre
 *
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \param indice int indice del empleado al cual se le editara el nombre
 * \param this Employee* puntero a empleado
 * \return int retorna 1 sino hubo ningun error de lo contrario 0
 *
 */
int employee_editName(LinkedList* pArrayListEmployee, int indice,Employee* this);
/** \brief permite editar sueldo
 *
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \param indice int indice del empleado al cual se le editara el sueldo
 * \param this Employee* puntero a empleado
 * \return int retorna 1 sino hubo ningun error de lo contrario 0
 *
 */
int employee_editSueldo(LinkedList* pArrayListEmployee, int indice,Employee* this);
/** \brief permite horas trabajadas
 *
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \param indice int indice del empleado al cual se le editara las horas trabajadas
 * \param this Employee* puntero a empleado
 * \return int retorna 1 sino hubo ningun error de lo contrario 0
 *
 */
int employee_editHoras(LinkedList* pArrayListEmployee, int indice,Employee* this);

/** \brief muestra menu de opciones
 *
 * \return int retorna opcion seleccionada
 *
 */
int menuListaEmpleados();

/** \brief menu de opciones para ordenar empleados segun el criterio seleccionado
 *
 * \param pArrayListEmployee LinkedList* lista de empleados
 * \return int retorna 1 sino hubo ningun error de lo contrario 0
 *
 */
int employee_menuOrdenarEmpleados(LinkedList* pArrayListEmployee);
#endif // employee_H_INCLUDED
