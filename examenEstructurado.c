//Erik Vital Muñoz
#include<stdio.h>
#include<string.h>

#define N 3

struct empleado
{
    int clave;
    char nombre[10];
    float estatura;
    float sueldo;
};

typedef struct empleado Empleado;

int buscarElAlto(Empleado empld[N]);
void arregloEmpleado(Empleado empld[N]);
void ordenaSueldo(Empleado empld[N]);
void imprime(Empleado empld[N]);


int main()
{
	Empleado empleados[N];
	int posMasAlto;

	arregloEmpleado(empleados);
	ordenaSueldo(empleados);
	imprime(empleados);
	posMasAlto=buscarElAlto(empleados);

    printf("\nEmpleado mas altillo es: %s\n", empleados[posMasAlto].nombre);
    printf("Su estatura es: %f\n", empleados[posMasAlto].estatura);
    
    return 0;
}

void imprime(Empleado empld[N])
{
    int i;

    printf("\n\n\nClave\tNombre\tEstatura\tSueldo\n");
    for(i = 0; i < N; i++)
    {
        printf("\n%i\t%s\t%.02f\t\t%.02f",empld[i].clave, empld[i].nombre, empld[i].estatura, empld[i].sueldo);
    }
}


int buscarElAlto(Empleado empld[N])
{
    int empleado;
    float mayor=empld[0].estatura;
    int posicion=0;

    for(empleado=0; empleado<N; empleado++)
    {
        if(empld[empleado].estatura>mayor)
        {
            mayor=empld[empleado].estatura;
            posicion=empleado;
        }
    }

    return posicion;
}

void ordenaSueldo(Empleado empld[N])
{
    int i, j, auxClave;
    float aux;
    char auxNombre[20];

    for(i=0; i<(N-1); i++)
    {
        for(j=0; j<(N-1); j++)
        {      
            if(empld[j].sueldo<empld[j+1].sueldo)
            {
                aux=empld[j].sueldo;
                empld[j].sueldo=empld[j+1].sueldo;
                empld[j+1].sueldo=aux;
                aux=empld[j].estatura;
                empld[j].estatura=empld[j+1].estatura;
                empld[j+1].estatura = aux;
                auxClave=empld[j].clave;
                empld[j].clave=empld[j+1].clave;
                empld[j+1].clave=auxClave;
                strcpy(auxNombre, empld[j].nombre);
                strcpy(empld[j].nombre, empld[j+1].nombre);
                strcpy(empld[j+1].nombre, auxNombre);
            }
        }    
    }
}

void arregloEmpleado(Empleado empld[N])
{
    int i;
    
    for(i=0; i<N; i++)
    {
        printf("Empleado[%d]\n", i);
        printf("     Clave: ");
        scanf("%d", &empld[i].clave);
        printf("     Nombre: ");
        scanf("%s", empld[i].nombre);
        printf("     Estatura: ");
        scanf("%f", &empld[i].estatura);
        printf("     Sueldo: ");
        scanf("%f", &empld[i].sueldo);
    }
}
