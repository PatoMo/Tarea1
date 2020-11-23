#include <stdio.h>
#include <string.h> //libreria para comparar palabras
#include <cstdlib>
#include <iostream> //contiene los algoritmos basicos
#include <fstream>  //permite la manipulacion de archivos desde el programar, tanto leer como escribir en ellos
#include <conio.h>      // para almacenar archivos o leer archivos Externos
#include <ctime>  //PARA LA FECHA ACTUAL
using namespace std;
float dosis,concentracion;
char name[60],rut[20],confirmar[10];
int edad,opcion,cantidadmg,cantidadml,peso;

int main(){
   ofstream entrada;                      //ESTO ES PARA GUARDAR EN EL ARCHIVO DE NOMBRE entrada Con la hora y fecha 
    entrada.open("entrada.txt",ios::out);
    time_t hora = time(0);
    char* fecha = ctime(&hora);
   
   //INGRESO PACIENTE           (Creo que debería ir en el loop pero no estoy seguro)
printf("Ingrese nombre del paciente: \n");
gets(name); //lee la cadena de caracteres y las almacena en name
printf("Ingrese rut del paciente y edad: \n");
scanf("%s %d",rut,&edad);
printf("Ingrese peso del paciente en kilogramos: ");
scanf("%d",&peso);

do //Las opciones
{   printf("¿Qué medicamento desea dosificar? \n");
    printf( " 1.  Noradrenalina \n");
    printf( " 2.  Adrenalina \n");
    printf( " 3.  Fentanilo \n");
    printf( " 4.  Midazolam \n");
    printf( " 5.  Esmeron \n");
    printf( " 6.  Propofol \n");
    printf( " 7.  Amiodarona \n");
    printf( " 8.  Nitroglicerina \n");
    printf( " 9.  Labetalol \n");
    printf( " 10. Nitropusiato \n");
    printf( " 11. Lidocaina \n");
    printf( " 12. Cloruro de Potasio \n");
    do{
        printf("Introduzca la opción(1-12) y pulse enter: ");
        scanf("%d",&opcion);
        }
    while ((opcion <1) && (opcion>12) && (opcion!=1234)); //CODIGO 1234 PARA SACAR LOOP
    switch ( opcion ){
case 1:     do{
            printf( "\n   Concentración(mg)/Dilusión(ml) de Adrenalina : " ); //ADRENALINA
            scanf( "%d %d", &cantidadmg,&cantidadml ); //hacer lo que haya que hacer
            concentracion= (cantidadmg/cantidadml);
            printf( "Su dosis es %.4f mg/ml\n",concentracion );
            printf("Agregue la dosis: (gamma*kilogramo*minuto) \n");
            scanf("%f",&dosis);
            printf("La dosis es %.4f, ¿confirmar?   \n",dosis); //CONFIRMAR CON PALABRA???
        do{printf("Aceptar o Cancelar \n"); //Hice un Loop para darle a aceptar o cancelar y al presionar cancelar deberia empezar 
            scanf("%s",confirmar);}
            while((strcmp(confirmar,"aceptar") !=0) && (strcmp(confirmar,"cancelar") !=0));
}
            while(strcmp(confirmar, "aceptar") != 0);
            entrada<<"Su concentracion de adrenalina fue de "<<concentracion<<" mg/ml con una dosis de "<<dosis<<"  Fecha:"<<fecha<<endl; //GUARDADO LO QUE SE HIZO
            entrada.close();
            cout << "Los datos fueron almacenados correctamente \n"    ;
            getch();
            break;

case 2: printf( "\n   Dosificar Amiodarona: ");
            scanf( "%d", &cantidadmg ); //hacer lo que haya que hacer
            printf( "test 2 \n \n" ); //entregar resultado
            break;
case 3: printf( "\n   Dosificar Cloruro de Potasio: ");
            scanf( "%d", &cantidadmg ); //hacer lo que haya que hacer
            printf( "test 3 \n" ); //entregar resultado
            break;
case 4: printf( "\n   Dosificar Esmeron: ");
            scanf( "%d", &cantidadmg ); //hacer lo que haya que hacer
            printf( "" ); //entregar resultado
            break;
case 5: printf( "\n   Dosificar Fentanilo: ");
            scanf( "%d", &cantidadmg ); //hacer lo que haya que hacer
            printf( "" ); //entregar resultado
            break;
case 6: printf( "\n   Dosificar Labetalol: ");
            scanf( "%d", &cantidadmg ); //hacer lo que haya que hacer
            printf( "" ); //entregar resultado
            break;
case 7: printf( "\n   Dosificar Lidocaina: ");
            scanf( "%d", &cantidadmg ); //hacer lo que haya que hacer
            printf( "" ); //entregar resultado
            break;
case 8: printf( "\n   Dosificar Midazolam: ");
            scanf( "%d", &cantidadmg ); //hacer lo que haya que hacer
            printf( "" ); //entregar resultado
            break;
case 9: printf( "\n   Dosificar Nitroglicerina: ");
            scanf( "%d", &cantidadmg ); //hacer lo que haya que hacer
            printf( "" ); //entregar resultado
            break;
case 10: printf( "\n   Dosificar Nitroprusiato: ");
            scanf( "%d", &cantidadmg ); //hacer lo que haya que hacer
            printf( "" ); //entregar resultado
            break;
case 11: printf( "\n   Dosificar Noradrenalina: ");
            scanf( "%d", &cantidadmg ); //hacer lo que haya que hacer
            printf( "" ); //entregar resultado
            break;
case 12: printf( "\n   Dosificar Propofol: ");
            scanf( "%d", &cantidadmg ); //hacer lo que haya que hacer
            printf( "" ); //entregar resultado
            break;
    }
} while(opcion!=1234); //PARA QUE ACABE EL LOOP



return 0;}

