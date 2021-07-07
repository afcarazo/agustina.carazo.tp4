#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "input.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* auxEmpleado= NULL;
    char buffer[4][20];
    int retorno=0;
    int cant=0;
    int flag=0;

    fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);

    while(!feof(pFile))
    {

        cant=fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);

        if(cant==4)
        {
            auxEmpleado=employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);
            if(auxEmpleado!=NULL)
            {
                ll_add(pArrayListEmployee,auxEmpleado);
                auxEmpleado=NULL;
                retorno=1;
            }
            else
            {
                employee_delete(auxEmpleado);
                flag= 2; // problema para crear el empleado
                break;
            }
        }
        else
        {
            flag=3; // problema al leer el empleado
            break;
        }
    }

    if(flag==2)
    {
        printf("\nNo se pudo crear al empleado\n");
    }
    else if(flag==3)
    {
        printf("\nProblema al leer el empleado\n");
    }

    return retorno;
}


int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* auxEmpleado= NULL;
    int retorno = 0;

    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        while(!feof(pFile))
        {
            auxEmpleado = employee_new();
            if(auxEmpleado!=NULL)
            {

                if( fread(auxEmpleado,sizeof(Employee),1,pFile)==1)
                {
                	ll_add(pArrayListEmployee,auxEmpleado);
                	retorno=1;
                }
                else
                {
                	employee_delete(auxEmpleado);

                }
            }
        }
    }

    return retorno;
}
