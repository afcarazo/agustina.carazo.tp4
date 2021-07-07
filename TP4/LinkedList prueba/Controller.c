#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "parser.h"
#include "input.h"
#include <string.h>

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE *pArchivo= NULL;
    int retorno = 0;
    system("cls");
    printf("\n------------------------------------------------------\n");
    printf("               Cargar archivo modo texto");
    printf("\n------------------------------------------------------\n\n");

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pArchivo= fopen(path, "r");
        if(pArchivo!=NULL)
        {

            if(parser_EmployeeFromText(pArchivo,pArrayListEmployee))
            {
                printf("\nSe ha cargado con exito\n\n");
                retorno=1;

            }
        }
        else
        {
            printf("No se pudo abrir el archivo\n\n");
            system("pause");
            exit(1);
        }
        fclose(pArchivo);
    }

    return retorno;
}

int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE *pArchivo = NULL;
    system("cls");
    printf("\n------------------------------------------------------\n");
    printf("              Cargar archivo modo binario");
    printf("\n------------------------------------------------------\n\n");

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pArchivo= fopen(path,"rb");

        if(pArchivo!=NULL)
        {
            if(parser_EmployeeFromBinary(pArchivo,pArrayListEmployee))
            {
            printf("Empleados cargados correctamente\n\n");
            }
        }
        else
        {
        	printf("No se pudo abrir el archivo\n\n");
            system("pause");
        	exit(1);

        }
        fclose(pArchivo);
    }

    return 1;
}

int controller_addEmployee(LinkedList* pArrayListEmployee,int* id)
{
    int retorno = 0;
    int auxId;
    system("cls");
      printf("\n------------------------------------------------------\n");
      printf("                     Alta empleado");
      printf("\n------------------------------------------------------\n\n");

    if(pArrayListEmployee!=NULL )
    {
        controller_saveAsTextIdEmpleado("idEmpleados.csv", pArrayListEmployee, *id);
        auxId=*id;
        if(Employee_add(pArrayListEmployee,&auxId))
        {
        	*id=auxId;
            printf("\nAlta de empleado exitosa\n\n");
            retorno=1;
        }
    }
    else
    {
        printf("\nOcurrio un problema al dar de alta el empleado\n");
    }

    return retorno;
}

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    if(pArrayListEmployee!=NULL)
    {

        if(employee_modificar(pArrayListEmployee))
        {
            printf("\nModificacion exitosa\n\n");
            retorno = 1;
        }
        else
        {
            printf("\nOcurrio un problema al realizar la modificacion\n\n");
        }


    }

    return retorno;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    system("cls");
      printf("\n------------------------------------------------------\n");
      printf("                    Baja empleado");
      printf("\n------------------------------------------------------\n\n");

    if(pArrayListEmployee!=NULL)
    {
        if(bajaEmpleado(pArrayListEmployee))
        {
            printf("\nLa baja del empleado ha sido exitosa\n\n");
            retorno=1;
        }
        else
        {
            printf("\nOcurrio un problema al realizar la baja\n\n");
        }
    }

    return retorno;
}

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=0;
    system("cls");
    printf("\n-----------------------------------------");
    printf("\n             Listar empleados         ");
    printf("\n-----------------------------------------\n");
    if(pArrayListEmployee!=NULL)
    {
        if(Employee_printAllEmployees(pArrayListEmployee))
        {
            retorno=1;

        }
    }
    return retorno;
}

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    Employee_printAllEmployees(pArrayListEmployee);
    system("cls");
    printf("\n------------------------------------------------------\n");
    printf("              Ordenar empleados");
    printf("\n------------------------------------------------------\n\n");

    if(pArrayListEmployee!=NULL)
    {
        if(employee_menuOrdenarEmpleados(pArrayListEmployee))
        {
            printf("\n Los empleados se han ordenado\n\n");
            retorno=1;
        }
        else
        {
            printf("\nOcurrio un problema al ordenar a los empleados\n");
        }
    }

    return retorno;
}

int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    Employee* auxEmpleado = NULL;
    int retorno = 0;
    int auxSueldo;
    int auxHoras;
    char nombre[128];
    int auxId;
    int cantidadCargados=0;

	system("cls");
	printf("\n------------------------------------------------------\n");
	printf("             Guardar archivo modo texto");
    printf("\n------------------------------------------------------\n\n");

    if(path!=NULL && pArrayListEmployee!=NULL)
    {

        pArchivo = fopen(path, "w");

        if(pArchivo==NULL)
        {
            printf("No se pudo abrir el archivo\n");
            system("pause");
            exit(1);
        }
        else
        {

            fprintf(pArchivo,"Legajo,nombre,horasTrabajadas,sueldo\n");

            for(int i =0; i<ll_len(pArrayListEmployee); i++)
            {
                auxEmpleado= (Employee*)ll_get(pArrayListEmployee,i);
                if(auxEmpleado!=NULL)
                {
                    if(employee_getVerificar(auxEmpleado,&auxId,nombre,&auxHoras,&auxSueldo)==1)
                    {
                        fprintf(pArchivo,"%d,%s,%d,%d\n",auxId,nombre,auxHoras,auxSueldo);
                        cantidadCargados++;
                    }
                    else
                    {
                        employee_delete(auxEmpleado);
                        printf("\nNo se pudo guardar");
                    }
                }
                auxEmpleado= NULL;
            }
            if(cantidadCargados == ll_len(pArrayListEmployee)){
            retorno=1;
            }
        }

    }
    fclose(pArchivo);


    return retorno;
}

int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    Employee* auxEmpleado = NULL;
    int flag=0;
    int retorno = 0;
    int cantidadCargados =0;
    system("cls");
    printf("\n------------------------------------------------------\n");
    printf("             Guardar archivo modo binario");
    printf("\n------------------------------------------------------\n\n");

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pArchivo =fopen(path,"wb");
        if(pArchivo==NULL)
        {
            printf("No se pudo abrir el archivo\n\n");
            system("pause");
            exit(1);
        }
        else
        {
            for(int i =0; i<ll_len(pArrayListEmployee); i++)
            {
                auxEmpleado = (Employee*)ll_get(pArrayListEmployee,i);
                if(auxEmpleado!=NULL)
                {
                    if(fwrite(auxEmpleado,sizeof(Employee),1,pArchivo)==1)
                    {
                        flag=1;//hubo un problema
                        cantidadCargados++;
                        break;
                    }
                }
            }
            if(cantidadCargados==ll_len(pArrayListEmployee)){
            retorno = 1;
            }
        }

        if(flag)
        {
            printf("Hubo un problema al guardar los empleados\n\n");
            system("pause");
            exit(1);
        }

    }

    printf("\nEmpleados guardados con exito\n\n");
    fclose(pArchivo);

    return retorno;
}

int controller_saveAsTextIdEmpleado(char* path, LinkedList* pArrayListEmployee, int id)
{
    FILE* pFile=NULL;
    int retorno = 0;
    int mayorId = 0;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        if(id==1000)
        {
            mayorId = id;
        }
        else
        {
            obtenerIdMasGrande(pArrayListEmployee,&mayorId);
        }

        pFile = fopen(path,"w");

        if(pFile!= NULL)
        {
            fprintf(pFile,"Siguiente ID empleado:\n");
            fprintf(pFile,"%d\n",mayorId);
        }

        retorno = 0;
        fclose(pFile);
    }

    return retorno;
}
