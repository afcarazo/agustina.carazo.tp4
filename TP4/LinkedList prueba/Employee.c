#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Employee.h"
#include "Controller.h"
#include "input.h"


static int esNombreValido(char*cadena, int tam);


Employee* employee_new()
{
    Employee* nuevoEmpleado = (Employee*) malloc(sizeof(Employee));

    if(nuevoEmpleado!=NULL)
    {
        nuevoEmpleado->horasTrabajadas = 0;
        strcpy(nuevoEmpleado->nombre, " ");
        nuevoEmpleado->id= 0;
        nuevoEmpleado->sueldo=0;

    }
    return nuevoEmpleado;
}

int employee_setId(Employee* this,int id)
{
    int retorno=0;
    if(this!=NULL && id>0)
    {
        this->id = id;
        retorno=1;
    }
    return retorno;
}

int employee_getId(Employee* this,int* id)
{
    int retorno= 0;
    if(this!=NULL && id!=NULL)
    {
        *id = this->id;
        retorno =1;
    }
    return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno = 0;

    if(this!=NULL && nombre!=NULL)
    {
        if(esNombreValido(nombre,128)==1)
        {
            strcpy(this->nombre, nombre);
            retorno=1;
        }
    }

    return retorno;
}
int employee_getNombre(Employee* this,char* nombre)
{
    int retorno = 0;
    if(this!=NULL && nombre !=NULL)
    {
        strcpy(nombre, this->nombre);
        retorno= 1;

    }
    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno = 0;

    if(this!=NULL && horasTrabajadas>=0)
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno=1;
    }

    return retorno;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno = 0;
    if(this!=NULL && horasTrabajadas!=NULL && horasTrabajadas>0)
    {
        *horasTrabajadas= this->horasTrabajadas;
        retorno=1;
    }
    return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno=0;
    if(this!=NULL && sueldo>0)
    {
        this->sueldo = sueldo;
        retorno=1;
    }
    return retorno;

}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno=0;
    if(this!=NULL && sueldo!=NULL)
    {
        *sueldo= this->sueldo;
        retorno=1;
    }
    return retorno;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* nuevoEmpleado = employee_new();
    int flagOk=0;
    if(nuevoEmpleado!=NULL )
    {
        if(employee_setId(nuevoEmpleado, atoi(idStr)) && employee_setNombre(nuevoEmpleado,nombreStr) && employee_setHorasTrabajadas(nuevoEmpleado,atoi(horasTrabajadasStr))&&employee_setSueldo(nuevoEmpleado, atoi(sueldoStr)))
        {
            flagOk=1;
        }
    }

    if(flagOk==0)
    {
        employee_delete(nuevoEmpleado);
        nuevoEmpleado=NULL;
    }

    return nuevoEmpleado;
}
void employee_delete(Employee* this)
{

    if(this!=NULL)
    {
        free(this);
    }

}


//validacion para set nombre


/** \brief verifica si se trata de un nombre valido
 *
 * \param char*cadena cadena que sera evaluada
 * \param tam int tamanio del array cadena
 * \return int retorna 1 si es una cadena valida de lo contrario 0
 *
 */
static int esNombreValido(char*cadena, int tam)
{

    int retorno = 0;

    if(cadena!=NULL && tam>0)
    {
        for(int i=0 ; cadena[i] != '\0' && i < tam; i++)
        {

            if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' || cadena[i] > ' ' || cadena[i] > '-'))
            {
                retorno=1;
                break;
            }
        }
    }
    return retorno;
}


int Employee_add(LinkedList* listaEmpleados,int*id)
{
    int retorno = 0;
    char auxNombre[128];
    int auxHorasTrabajadas;
    int auxSueldo;
    int auxId=0;
    Employee* auxEmpleado = NULL;
    char respuesta[2];

    if(listaEmpleados!=NULL)
    {
        auxEmpleado= employee_new();
        if(auxEmpleado!=NULL)
        {
            if(!utn_getNombre(auxNombre,128,"\nIngrese nombre: ","\nError, nombre invalido.\n",3) &&
                    !utn_getNumero(&auxHorasTrabajadas,"\nIngrese horas trabajadas: ","\nError, no es valido, reingrese.\n",1,300,3)&&
                    !utn_getNumero(&auxSueldo,"\nIngrese sueldo: ","\nError, no es valido, reingrese.\n",1,120000,3)
              )
            {
                auxId=*id;
                auxId+=1;
                if( employee_setVerificar(auxEmpleado,auxId,auxNombre,auxHorasTrabajadas,auxSueldo))
                {

                    printf("\nLegajo       Nombre  Horas trabajadas Sueldo\n");
                    Employee_printAnEmployee(auxEmpleado);
                    utn_getChar(respuesta,2,"\nEsta seguro de que quiere agregar este empleado? s/n: ", "\nError, ingrese s/n\n",3);
                    if(!strcmp(respuesta, "s"))
                    {
                        ll_add(listaEmpleados,auxEmpleado);
                        *id=auxId;
                        retorno=1;
                    }

                }

            }
            else
            {
                printf("Intente nuevamente.\n");
            }
        }
        else
        {
            printf("\nNo hay espacio para un nuevo empleado");
        }

    }
    return retorno;
}


int obtenerIdMasGrande(LinkedList* listaEmpleados,int* id)
{
    int tam;
    Employee* auxEmpleado= NULL;
    int retorno = 0;
    int mayor;
    if(listaEmpleados!=NULL && id!=NULL)
    {
        tam = ll_len(listaEmpleados);
        if(tam>0)
        {
            for(int i = 0; i<tam; i++)
            {
                auxEmpleado= (Employee*) ll_get(listaEmpleados,i);
                if(i==0 ||auxEmpleado->id>mayor)
                {
                    mayor=auxEmpleado->id;
                }
            }
            *id=mayor+1;
            retorno=1;
        }
    }
    return retorno;
}

int Employee_printAnEmployee(Employee* this)
{
    int retorno=0;
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
    if(this!=NULL && employee_getVerificar(this,&id,nombre,&horasTrabajadas,&sueldo)
      )
    {
        printf(" %d   %10s         %5d        %d \n",
               id,
               nombre,
               horasTrabajadas,
               sueldo);
        retorno=1;
    }

    return retorno;
}

int Employee_printAllEmployees(LinkedList* listaEmpleados)
{
    int retorno=0;
    int tam;
    Employee* auxEmpleado= NULL;

    tam= ll_len(listaEmpleados);
    if(listaEmpleados!=NULL && tam>0)
    {
        printf("\nLegajo       Nombre  Horas trabajadas Sueldo\n");
        for(int i=0; i<tam; i++)
        {
            auxEmpleado= (Employee*)ll_get(listaEmpleados,i);
            Employee_printAnEmployee(auxEmpleado);
        }
        printf("\n");
        retorno=1;
    }
    return retorno;
}


int Employee_findId(LinkedList* listaEmpleados, int id)
{
    int tam;
    int indice=-1;
    tam = ll_len(listaEmpleados);
    Employee* auxEmpleado= NULL;
    if(listaEmpleados!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            auxEmpleado= (Employee*)ll_get(listaEmpleados,i);
            if(auxEmpleado->id == id)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}


int employee_getVerificar(Employee* this,int* id,char* nombre, int* horas,int* sueldo)
{
    int retorno = 0;
    if(this!=NULL)
    {
        if(employee_getId(this, id) && employee_getNombre(this,nombre) && employee_getHorasTrabajadas(this,horas)&&employee_getSueldo(this, sueldo))
        {
            retorno=1;
        }
    }

    return retorno;
}


int employee_setVerificar(Employee* this,int id,char* nombre, int horas,int sueldo)
{
    int retorno = 0;
    if(this!=NULL)
    {
        if(employee_setId(this,id) && employee_setNombre(this,nombre) && employee_setHorasTrabajadas(this,horas)&&employee_setSueldo(this, sueldo))
        {
            retorno=1;
        }
    }

    return retorno;
}

int employee_modificar(LinkedList* pArrayListEmployee)
{
    char respuesta[2];
    int auxId;
    int opcion;
    Employee* auxEmpleado = NULL;
    int indice;
    int retorno = 0;
    if(pArrayListEmployee!=NULL)
    {
        Employee_printAllEmployees(pArrayListEmployee);
        utn_getNumero(&auxId,"\nIngrese ID del empleado que desea modificar: ", "Error, ID no valido",1,5000,3);
        indice=Employee_findId(pArrayListEmployee,auxId);
        if(indice!=-1)
        {
            auxEmpleado = (Employee*)ll_get(pArrayListEmployee,indice);
            printf("\nLegajo       Nombre  Horas trabajadas Sueldo\n");
            Employee_printAnEmployee(auxEmpleado);
            utn_getChar(respuesta,2,"\nEsta seguro que desea modificar este empleado s/n: ","\nError, respuesta invalida.\n",3);
            if(!strcmp(respuesta, "s"))
            {
                utn_getNumero(&opcion, "\n\n1.Nombre\n2.Sueldo\n3.Horas trabajadas\n\nIngrese la opcion deseada: ","\nError, la opcion no existe\n",1,3,3);
                switch(opcion)
                {
                case 1:
                    if(employee_editName(pArrayListEmployee,indice,auxEmpleado))
                    {
                        retorno=1;
                    }
                    break;
                case 2:
                    if(employee_editSueldo(pArrayListEmployee,indice,auxEmpleado))
                    {
                        retorno=1;
                    }
                    break;
                case 3:
                    if(employee_editHoras(pArrayListEmployee,indice,auxEmpleado))
                    {
                        retorno=1;
                    }
                    break;
                default:
                    printf("\nLa opcion ingresada no existe\n");
                    break;

                }
            }
            else
            {
                printf("\nModificacion cancelada");
            }

        }
        else
        {
            printf("\nNo existe un empleado con ese ID\n");
        }
    }
    else
    {
        printf("\nNo es posible realizar la modificacion\n");
    }
    return retorno;
}


int employee_editName(LinkedList* pArrayListEmployee, int indice,Employee* this)
{
    int retorno = 0;
    char auxNombre[128];
    char opcion[2];
    if(pArrayListEmployee!=NULL && this!=NULL)
    {
       if(!utn_getNombre(auxNombre,128,"\nIngrese nuevo nombre: ", "\nError, nombre invalido\n",3)){

    	   utn_getChar(opcion,2,"\nEsta seguro que desea realizar la modificacion s/n: ","\nError, ingrese s/n\n",3);
    	          if(!strcmp(opcion,"s"))
    	          {
    	              if(employee_setNombre(this,auxNombre))
    	              {
    	                  retorno=1;
    	              }

    	          }
    	          else
    	          {
    	              printf("\nModificacion de nombre cancelada\n");
    	          }
       }


    }
    return retorno;
}


int employee_editSueldo(LinkedList* pArrayListEmployee, int indice,Employee* this)
{
    int retorno = 0;
    int auxInt;
    char opcion[2];
    if(pArrayListEmployee!=NULL && this!=NULL)
    {
       if(!utn_getNumero(&auxInt,"\nIngrese nuevo sueldo: ","\nError, sueldo invalido\n",1,100000,3)){
    	   utn_getChar(opcion,2,"\nEsta seguro que desea realizar la modificacion s/n: ","\nError, ingrese s/n\n",3);
    	          if(!strcmp(opcion,"s"))
    	          {
    	              if(employee_setSueldo(this,auxInt))
    	              {
    	                  retorno=1;
    	              }

    	          }
    	          else
    	          {
    	              printf("\nModificacion de sueldo cancelada\n");
    	          }
       }


    }
    return retorno;
}


int employee_editHoras(LinkedList* pArrayListEmployee, int indice,Employee* this)
{
    int retorno = 0;
    int auxInt;
    char opcion[2];
    if(pArrayListEmployee!=NULL && this!=NULL)
    {
        if(!utn_getNumero(&auxInt,"\nIngrese nuevas horas: ", "\nError, horas invalidas\n",1,600,3)){
        	utn_getChar(opcion,2,"\nEsta seguro que desea realizar la modificacion s/n: ","\nError, ingrese s/n\n",3);
        	        if(!strcmp(opcion,"s"))
        	        {
        	            if(employee_setHorasTrabajadas(this,auxInt))
        	            {
        	                retorno=1;
        	            }

        	        }
        	        else
        	        {
        	            printf("\nModificacion de horas cancelada\n");
        	        }
        }
    }
    return retorno;
}


int bajaEmpleado(LinkedList* pArrayListEmployee)
{
    int indice;
    int auxId;
    char confirma;
    int retorno=0;
    Employee* auxEmpleado = NULL;
    if(pArrayListEmployee!=NULL)
    {
        Employee_printAllEmployees(pArrayListEmployee);
        printf("\nIngrese el id del empleado que quisiera dar de baja: ");
        utn_getNumero(&auxId,"\nIngrese ID: ", "\nError, ID invalido\n",1,5000,3);
        printf("\n");
        indice=Employee_findId(pArrayListEmployee,auxId);
        if(indice==-1)
        {
            printf("\nNo hay ningun empleado registrado con ese id");
        }
        else
        {
            auxEmpleado=(Employee*)ll_get(pArrayListEmployee,indice);
            printf("\nLegajo       Nombre  Horas trabajadas Sueldo\n");
            Employee_printAnEmployee(auxEmpleado);
            printf("\nConfirma baja? s/n: ");
            fflush(stdin);
            scanf("%c",&confirma);
            if(confirma=='s')
            {
                ll_remove(pArrayListEmployee,indice);
                retorno=1;
            }
            else
            {
                printf("\nBaja cancelada por el usuario\n\n");

            }

        }
    }
    return retorno;
}

int employee_cmpId(void* a,void* b)
{
    int retorno=0;
    Employee* emp1 = NULL;
    Employee* emp2 = NULL;
    if(a!=NULL && b!=NULL)
    {
        emp1= (Employee*)a;
        emp2= (Employee*)b;
        if(emp1->id > emp2->id)
        {
            retorno=1;
        }
        else if(emp1->id < emp2->id)
        {
            retorno = -1;
        }
    }
    return retorno;
}

int employee_cmpSueldo(void* a,void* b)
{
    int retorno=0;
    Employee* emp1 = NULL;
    Employee* emp2 = NULL;
    if(a!=NULL && b!=NULL)
    {
        emp1= (Employee*)a;
        emp2= (Employee*)b;
        if(emp1->sueldo > emp2->sueldo)
        {
            retorno=1;
        }
        else if(emp1->sueldo < emp2->sueldo)
        {
            retorno = -1;
        }
    }
    return retorno;
}

int employee_cmpHoras(void* a,void* b)
{
    int retorno=0;
    Employee* emp1 = NULL;
    Employee* emp2 = NULL;
    if(a!=NULL && b!=NULL)
    {
        emp1= (Employee*)a;
        emp2= (Employee*)b;
        if(emp1->horasTrabajadas > emp2->horasTrabajadas)
        {
            retorno=1;
        }
        else if(emp1->horasTrabajadas < emp2->horasTrabajadas)
        {
            retorno = -1;
        }
    }
    return retorno;
}

int employee_cmpNombres(void* a,void* b)
{
    int retorno=0;
    Employee* emp1 = NULL;
    Employee* emp2 = NULL;
    if(a!=NULL && b!=NULL)
    {
        emp1= (Employee*)a;
        emp2= (Employee*)b;
        retorno=strcmp(emp1->nombre,emp2->nombre);
    }
    return retorno;
}

int employee_menuOrdenarEmpleados(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    int opcion;
    int criterio;
    if(pArrayListEmployee!=NULL)
    {
        if(!utn_getNumero(&opcion, "\nComo quisiera ordenar a los empleados?:\n1.Por ID\n2.Por nombre\n3.Por sueldo\n4.Por horas trabajadas\nIngrese opcion: ", "\nError,opcion invalida\n",1,4,3) &&
                !utn_getNumero(&criterio, "\nDe que forma?:\n1.Descendente\n2.Ascendente\nIngrese opcion: ", "\nError,opcion invalida\n",0,2,3)
          )
        {
        	criterio--;
            switch(opcion)
            {
            case 1:
                ll_sort(pArrayListEmployee,employee_cmpId,criterio);
                controller_ListEmployee(pArrayListEmployee);
                retorno=1;
                break;
            case 2:
                ll_sort(pArrayListEmployee,employee_cmpNombres,criterio);
                controller_ListEmployee(pArrayListEmployee);
                retorno=1;
                break;
            case 3:
                ll_sort(pArrayListEmployee,employee_cmpSueldo,criterio);
                controller_ListEmployee(pArrayListEmployee);
                retorno=1;
                break;
            case 4:
                ll_sort(pArrayListEmployee,employee_cmpHoras,criterio);
                controller_ListEmployee(pArrayListEmployee);
                retorno=1;
                break;
            }

        }

    }
    return retorno;
}


int menuListaEmpleados()
{
    int option;
    system("cls");
    printf("\n\n -------------------------------------------------------------------------------\n");
    printf("                                MENU DE OPCIONES");
    printf("\n -------------------------------------------------------------------------------\n\n");
    printf(" 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf(" 2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    printf(" 3. Alta de empleado\n");
    printf(" 4. Modificar datos de empleado\n");
    printf(" 5. Baja de empleado\n");
    printf(" 6. Listar empleados\n");
    printf(" 7. Ordenar empleados\n");
    printf(" 8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf(" 9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
    printf(" 10. Extras funciones.\n");
    printf(" 11. Salir.\n");
    printf("\n\n -------------------------------------------------------------------------------\n");

    utn_getNumero(&option, "\nIngrese opcion: ","\nERROR, opcion invalida. \n",1,10,3);

    return option;

}
