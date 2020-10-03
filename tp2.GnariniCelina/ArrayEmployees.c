#include "ArrayEmployees.h"
#include <string.h>

int BuscarLibre(Employee nominaEmployee[], int cant)
{
    int index=-1;
    int i;

    for(i=0;i<cant;i++)
    {
        if(nominaEmployee[i].isEmpty==1)
        {
            index=i;
            break;
        }
    }
    return index;
}

int InitEmployees(Employee nominaEmployee[], int cant)
{
    int i;

    for(i=0;i<1000;i++)
    {
        nominaEmployee[i].isEmpty=1;
    }

    return 0;
}
void MenuOpciones(Employee nominaEmployee[],int cant)
{
    int opcion;

    InitEmployees(nominaEmployee,1000);

    do
    {
        printf("\n1.ALTAS\n2.MODIFICAR\n3.BAJA\n4.INFORMAR\n5.SALIR\n");
        printf("\nElija una opcion: ");

        opcion=ValidOption();
        switch(opcion)
        {
            case 1:
                AddEmployee(nominaEmployee,1000);
                break;
            case 2:
                ValidCase(nominaEmployee);
                FindEmployeeById(nominaEmployee,1000);
                break;
            case 3:
                ValidCase(nominaEmployee);
                RemoveEmployee(nominaEmployee,1000);
                break;
            case 4:
                ValidCase(nominaEmployee);
                PrintEmployees(nominaEmployee,1000);
                PrintTotalSalaries(nominaEmployee, 1000);
                PrintAverageSalary(nominaEmployee, 1000);
                PrintPromedioSuperado(nominaEmployee, 1000);
                break;
            case 5:
                printf  ("\nADIOS!!!\n");
                break;
        }
    }while(opcion!=5);
}

int ValidOption()
{
    int opcion;
    scanf("%d",&opcion);
    while(opcion!=1&&opcion!=2&&opcion!=3&&opcion!=4&&opcion!=5)
        {
            printf("\nERROR!!! \n1.ALTAS\n2.MODIFICAR\n3.BAJA\n4.INFORMAR\n5.SALIR\n");
            printf("Elija una opcion: ");
            scanf("%d",&opcion);
        }
    return opcion;
}
void ValidCase(Employee nominaEmployee[])
{
    int i;
    int cont;
    cont=0;
    for(i=0;i<1000;i++)
    {
        if (nominaEmployee[i].isEmpty==0){
            cont++;
        }
    }
    if(cont==0)
    {
        printf("Error!!! Primero cargue un empleado: \n");
        AddEmployee(nominaEmployee,1000);
    }
}
void AddEmployee(Employee nominaEmployee[],int cant)
{
    int i;

    Employee aEmployee;

    i=BuscarLibre(nominaEmployee,1000);
    if(i!=-1)
    {
        printf("Ingrese nombre: ");
        fflush(stdin);
        scanf("%[^\n]", aEmployee.name);
        printf("Ingrese apellido: ");
        fflush(stdin);
        scanf("%[^\n]", aEmployee.lastName);
        printf("Ingrese salario: ");
        scanf("%f", &aEmployee.salary);
        while(aEmployee.salary<0)
        {
            printf("ERROR!!! Ingrese salario mayor a 0: ");
            scanf("%f", &aEmployee.salary);
        }
        printf("Ingrese sector: ");
        scanf("%d",&aEmployee.sector);
        while(aEmployee.sector<0)
        {
            printf("ERROR!!! Ingrese sector mayor a 0: ");
            scanf("%d", &aEmployee.sector);
        }


        nominaEmployee[i]=aEmployee;
        aEmployee.isEmpty=0;

    }
    else
    {
        printf("No hay espacio\n");
    }
}
void FindEmployeeById(Employee nominaEmployee[],int cant)
{
    int i;
    int id;
    int opcion;

    PrintEmployees(nominaEmployee,1000);
    printf("ingrese el ID del empleado a modificar: ");
    scanf("%d", &id);

    for(i=0;i<1000;i++)
    {
        if(nominaEmployee[i].isEmpty==0&&nominaEmployee[i].id==id)
        {
            printf("\nDesea modificar:\n\n1.NOMBRE\n2.APELLIDO\n3.SALARIO\n4.SECTOR\n");
            scanf("%d",&opcion);
            switch(opcion)
            {
                case 1:
                    printf("\ningrese nombre: ");
                    fflush(stdin);
                    scanf("%[^\n]",nominaEmployee[i].name);
                    break;
                case 2:
                    printf("\ningrese apellido: ");
                    fflush(stdin);
                    scanf("%[^\n]",nominaEmployee[i].lastName);
                    break;
                case 3:
                    printf("\ningrese calario: ");
                    scanf("%f",&nominaEmployee[i].salary);
                    break;
                case 4:
                    printf("\ningrese sector: ");
                    scanf("%d",&nominaEmployee[i].sector);
                    break;
            }
        }
    }
}
void PrintEmployees(Employee nominaEmployee[], int cant)
{
    int i;

    SortEmployees(nominaEmployee,1000);
    for(i=0;i<1000;i++)
    {
        if(nominaEmployee[i].isEmpty==0)
        {
            nominaEmployee[i].id=i+1;
            printf("\nID\t| NOMBRE\t| APELLIDO\t| SALARIO\t| SECTOR\t\n");
            printf("\n%4d\t| %10s\t| %10s\t| %10.2f\t|%10d\n", nominaEmployee[i].id,nominaEmployee[i].name,nominaEmployee[i].lastName,nominaEmployee[i].salary,nominaEmployee[i].sector);
        }
    }
}

void RemoveEmployee(Employee nominaEmployee[],int cant)
{
    int i;
    int id;

    PrintEmployees(nominaEmployee,1000);
    printf("ingrese el ID del empleado a eliminar: ");
    scanf("%d", &id);

    for(i=0;i<cant;i++)
    {
        if(nominaEmployee[i].isEmpty==0&&nominaEmployee[i].id==id)
        {
            nominaEmployee[i].isEmpty=1;
            printf("Empleado eliminado!!!\n");
        }
    }
}

void SortEmployees(Employee nominaEmployee[],int cant)
{
    int i;
    int j;
    Employee auxEmployee;

    for(i=0;i<1000-1;i++)
    {
        for(j=i+1;j<1000;j++)
        {
            if((strcmp(nominaEmployee[i].lastName,nominaEmployee[j].lastName)>0) || (strcmp(nominaEmployee[i].lastName,nominaEmployee[j].lastName)==0  && nominaEmployee[i].sector>nominaEmployee[j].sector))
            {
                auxEmployee=nominaEmployee[i];
                nominaEmployee[i]=nominaEmployee[j];
                nominaEmployee[j]=auxEmployee;
            }
        }
    }
}


int NumberofSalaries(Employee nominaEmployee[], int cant)
{
    int cont;
    cont=0;
    int i;

    for(i=0;i<1000;i++)
    {
        if(nominaEmployee[i].isEmpty != 1)
        {
            cont++;
        }
    }
    return cont;


}
int TotalSalaries(Employee nominaEmployee[], int cant)
{
    float suma;
    int i;
    suma=0;
    for(i=0; i < 1000; i++)
    {
        if(nominaEmployee[i].isEmpty!=1)
        {
            suma= suma + nominaEmployee[i].salary;
        }
    }
    return suma;
}

float AverageSalary(Employee nominaEmployee[], int cant)
{
    float promedio;
    promedio=0;
    promedio = TotalSalaries(nominaEmployee, cant) / NumberofSalaries(nominaEmployee, 1000);
    return promedio;
}

int PromedioSuperado(Employee nominaEmployee[], int cant)
{
    int cont;
    int i;
    cont=0;
    for(i=0;i<cant;i++)
    {
        if(nominaEmployee[i].salary > AverageSalary(nominaEmployee, cant))
        {
            cont=cont + 1;
        }
    }
    return cont;
}

void PrintTotalSalaries(Employee nominaEmployee[],int cant)
{
    float suma;
    suma = TotalSalaries(nominaEmployee, 1000);
    printf ("Total salarios: %.2f\n", suma);
}

void PrintAverageSalary(Employee nominaEmployee[],int cant)
{
    float promedio;
    promedio = AverageSalary(nominaEmployee, 1000);
    printf ("Promedio salarios: %.2f\n", promedio);
}
void PrintPromedioSuperado(Employee nominaEmployee[],int cant){
    int superados;
    superados = PromedioSuperado(nominaEmployee, 1000);
    printf ("Numero de salarios que superan el promedio: %d\n", superados);
}
