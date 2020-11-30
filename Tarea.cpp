#include <stdio.h>
#include <string.h> //libreria para comparar palabras
#include <cstdlib>
#include <iostream> //contiene los algoritmos basicos
#include <fstream>  //permite la manipulacion de archivos desde el programar, tanto leer como escribir en ellos
#include <conio.h>      // para almacenar archivos o leer archivos Externos
#include <ctime>  //PARA LA FECHA ACTUAL
using namespace std;
char confirmar[10],nada[1];
int opcion;

int main(){
   ofstream entrada;                      //ESTO ES PARA GUARDAR EN EL ARCHIVO DE NOMBRE entrada Con la hora y fecha
    entrada.open("pacientes.txt",ios::out);
    time_t hora = time(0);
    char* fecha = ctime(&hora);

    struct receta{
    float dosis,concentracion;
    float cantidadmg,cantidadml;
    };

    struct paciente{
    char name[60],rut[20];
    int edad,peso,cama;
    struct receta;
    };
do {
   //INGRESO PACIENTE
   paciente p;
   receta r;
   printf("Bienvenido \n");
   gets(nada);
printf("Ingrese nombre del paciente: \n");
gets(p.name); //lee la cadena de caracteres y las almacena en name
printf("Ingrese rut del paciente,edad y numero de cama: \n");
scanf("%s %d %d",p.rut,&p.edad,&p.cama);
printf("Ingrese peso del paciente en kilogramos: ");
scanf("%d",&p.peso);

    printf("¿Qué medicamento desea dosificar? \n");
    printf( " 1.  Adrenalina \n");
    printf( " 2.  Amiodarona \n");
    printf( " 3.  Cloruro de Potasio \n");
    printf( " 4.  Esmeron \n");
    printf( " 5.  Fentanilo \n");
    printf( " 6.  Labetalol \n");
    printf( " 7.  Lidocaina \n");
    printf( " 8.  Midazolam \n");
    printf( " 9.  Nitroglicerina \n");
    printf( " 10. Nitropusiato \n");
    printf( " 11. Noradrenalina \n");
    printf( " 12. Propofol \n");
    do{
        printf("Introduzca la opción(1-12) y pulse enter: ");
        scanf("%d",&opcion);
        }
    while ((opcion <1) && (opcion>12) && (opcion!=1234)); //CODIGO 1234 PARA SACAR LOOP
    switch ( opcion ){
case 1:     do{
            printf( "\n   Concentración(mg)/Dilusión(ml) de Adrenalina : " ); //ADRENALINA
            scanf( "%f %f", &r.cantidadmg,&r.cantidadml ); //hacer lo que haya que hacer
            r.concentracion= (r.cantidadmg/r.cantidadml);
            printf( "Su dosis es %.4f mg/ml\n",r.concentracion );
            printf("Agregue la dosis: (gamma*kilogramo*minuto) \n");
            scanf("%f",&r.dosis);
            printf("La dosis es %.4f, ¿confirmar?   \n",r.dosis); //CONFIRMAR CON PALABRA???
        do{printf("Aceptar o Cancelar \n"); //Hice un Loop para darle a aceptar o cancelar y al presionar cancelar deberia empezar
            scanf("%s",confirmar);}
            while((strcmp(confirmar,"aceptar") !=0) && (strcmp(confirmar,"cancelar") !=0));
}
            while(strcmp(confirmar, "aceptar") != 0);
            entrada<<"Paciente "<<p.name<<" con edad "<< p.edad<<" en cama "<<p.cama<<" se le receto adrenalina. \n" <<endl;
            entrada<<"Su concentracion de adrenalina fue de "<<r.concentracion<<" mg/ml con una dosis de "<<r.dosis<<"  Fecha: \n"<<fecha<<endl; //GUARDADO LO QUE SE HIZO
            getch();
            break;
/*
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
  */  }
} while(opcion!=1234); //PARA QUE ACABE EL LOOP
            entrada.close();
            cout << "Los datos fueron almacenados correctamente \n"    ;



return 0;}

