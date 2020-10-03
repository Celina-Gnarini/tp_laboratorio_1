#include <stdio.h>
#include <stdlib.h>

struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}typedef Employee;

int BuscarLibre(Employee[], int);
int InitEmployees(Employee[],int);
void AddEmployee(Employee[],int);
void FindEmployeeById(Employee[],int);
void RemoveEmployee(Employee[],int);
void PrintEmployees(Employee[],int);
void MenuOpciones(Employee[],int);
void SortEmployees(Employee[],int);
int ValidOption();
void ValidCase(Employee[]);
int ContadorSalarios(Employee[],int);
int TotalSalaries(Employee[],int);
float AverageSalary(Employee[],int);
int PromedioSuperado(Employee[],int);
void PrintContadorSalarios(Employee[],int);
void PrintTotalSalaries(Employee[],int);
void PrintAverageSalary(Employee[],int);
void PrintPromedioSuperado(Employee[],int);
