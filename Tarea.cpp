/*  Universidad de la Frontera
    Ingeniería Civil Electrónica

    IIE-344 Estructura de Datos y Algoritmos

    Tarea 1

    Autor 1: Mauricio Arismendi
    Autor 2: Patricio Morales

    Fecha: 8-12-2020

    Descripción general del programa: Programa de dosificación básica con los parametros de acuerdo a cada medicamento(12 en total),
                                    junto con un registro de paciente que es guardado en un archivo tipo txt, para revisiones
                                   o para ser adjuntadas en evoluciones de pacientes.

*/
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
    float dosis,concentracion,horas;
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
        printf("Introduzca la opción(1-12) y pulse enter: \n");
        scanf("%d",&opcion);
        }
    while ((opcion <1) && (opcion>12) && (opcion!=1234)); //CODIGO 1234 PARA SACAR LOOP
    switch ( opcion ){
case 1: printf("\n Dosificar Adrenalina: ");
       do{
            printf( "\n   Concentración(mg)/Dilusión(ml) de Adrenalina : " ); //ADRENALINA
            scanf( "%f %f", &r.cantidadmg,&r.cantidadml ); //hacer lo que haya que hacer
            r.concentracion= (r.cantidadmg/r.cantidadml);
            printf( "Su dosis es %.4f mg/ml\n",r.concentracion );
            printf("Agregue la dosis: (gramo*kilogramo*minuto) \n");
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

case 2: printf( "\n   Dosificar Amiodarona: ");
do{
           printf( "\n  Dosificación mg/hora(1) o ml/hora(2) de Amiodarona : " ); //AMIODARONA
           scanf("%d",opcion);
           if(opcion==1){
            printf("\n Ingrese la dosis en mg/hora");
            scanf( "%f %f", &r.cantidadmg,&r.horas );
            r.concentracion= (r.cantidadmg/r.horas);
           }else if(opcion==2){
           printf("\n Coloque la dosis en ml/hora");
           scanf( "%f %f", &r.cantidadml,&r.horas );
           r.concentracion=(r.cantidadml/r.horas);
           }
            else {"Opcion no valida";}
}
while((opcion!=1) && (opcion!=2));
if(opcion=1){
    printf( "Su dosis en %.4f mg/hora \n",r.concentracion );
}
else{ printf("Su dosis en %.4f ml/hora \n",r.concentracion);

}
        do{printf("Aceptar o Cancelar \n"); //Hice un Loop para darle a aceptar o cancelar y al presionar cancelar deberia empezar
            scanf("%s",confirmar);}
            while((strcmp(confirmar,"aceptar") !=0) && (strcmp(confirmar,"cancelar") !=0));

            while(strcmp(confirmar, "aceptar") != 0);
            entrada<<"Paciente "<<p.name<<" con edad "<< p.edad<<" en cama "<<p.cama<<" se le receto amiodarona. \n" <<endl;
            if(opcion==1){
            entrada<<"Su concentracion de amiodarona fue de "<<r.concentracion<<" mg/hora Fecha: \n"<<fecha<<endl; //GUARDADO LO QUE SE HIZO
            }
            else{entrada<<"Su concentracion de amiodarona fue de "<<r.concentracion<<" ml/hora Fecha: \n"<<fecha<<endl;}
            getch();
            break;

case 3: printf( "\n   Dosificar Cloruro de Potasio: ");
 do{
            printf( "\n   Concentración(mg)/Dilusión(ml) de Cloruro de Potasio : " );
            scanf( "%f %f", &r.cantidadmg,&r.cantidadml );
            r.concentracion= (r.cantidadmg/r.cantidadml);
            printf("La dosis es %.4f mg/ml por hora, ¿confirmar?   \n",r.concentracion);
        do{printf("Aceptar o Cancelar \n");
            scanf("%s",confirmar);}
            while((strcmp(confirmar,"aceptar") !=0) && (strcmp(confirmar,"cancelar") !=0));
}
            while(strcmp(confirmar, "aceptar") != 0);
            entrada<<"Paciente "<<p.name<<" con edad "<< p.edad<<" en cama "<<p.cama<<" se le receto cloruro de potasio. \n" <<endl;
            entrada<<"Su concentracion de cloruro de potasio fue de "<<r.concentracion<<" mg/ml por hora  Fecha: \n"<<fecha<<endl; //GUARDADO LO QUE SE HIZO
            getch();
            break;


case 4: printf( "\n   Dosificar Esmeron: ");
            do{
            printf( "\n   Concentración(mg)/Dilusión(ml) de Esmeron : " );
            scanf( "%f %f", &r.cantidadmg,&r.cantidadml ); //hacer lo que haya que hacer
            r.concentracion= (r.cantidadmg/r.cantidadml);
            printf( "Su dosis es %.4f mg/ml\n",r.concentracion );
            printf("Agregue la dosis: (gamma*kilogramo*minuto) \n");
            scanf("%f",&r.dosis);
            printf("La dosis es %.4f, ¿confirmar?   \n",r.dosis);
        do{printf("Aceptar o Cancelar \n");
            scanf("%s",confirmar);}
            while((strcmp(confirmar,"aceptar") !=0) && (strcmp(confirmar,"cancelar") !=0));
}
            while(strcmp(confirmar, "aceptar") != 0);
            entrada<<"Paciente "<<p.name<<" con edad "<< p.edad<<" en cama "<<p.cama<<" se le receto esmeron. \n" <<endl;
            entrada<<"Su concentracion de esmeron fue de "<<r.concentracion<<" mg/ml con una dosis de "<<r.dosis<<"  Fecha: \n"<<fecha<<endl; //GUARDADO LO QUE SE HIZO
            getch();
            break;

case 5: printf( "\n   Dosificar Fentanilo: ");
            //microgramo kilo hora
            do{
            printf( "\n   Concentración(mg)/Dilusión(ml) de Fentanilo : " );
            scanf( "%f %f", &r.cantidadmg,&r.cantidadml );
            r.concentracion= (r.cantidadmg/r.cantidadml);
            printf( "Su dosis es %.4f mg/ml\n",r.concentracion );
            printf("Agregue la dosis: (gamma*kilogramo*hora) \n");
            scanf("%f",&r.dosis);
            printf("La dosis es %.4f, ¿confirmar?   \n",r.dosis);
        do{printf("Aceptar o Cancelar \n");
            scanf("%s",confirmar);}
            while((strcmp(confirmar,"aceptar") !=0) && (strcmp(confirmar,"cancelar") !=0));
}
            while(strcmp(confirmar, "aceptar") != 0);
            entrada<<"Paciente "<<p.name<<" con edad "<< p.edad<<" en cama "<<p.cama<<" se le receto fentanilo. \n" <<endl;
            entrada<<"Su concentracion de fentanilo fue de "<<r.concentracion<<" mg/ml con una dosis de "<<r.dosis<<"  Fecha: \n"<<fecha<<endl; //GUARDADO LO QUE SE HIZO
            getch();
            break;
case 6: printf( "\n   Dosificar Labetalol: ");
            //gramos en hora
            do{
           printf( "\n  Dosificación mg/hora(1) o ml/hora(2) de Labetalol : " );
           scanf("%d",opcion);
           if(opcion==1){
            printf("\n Ingrese la dosis en g/hora");
            scanf( "%f %f", &r.cantidadmg,&r.horas );
            r.concentracion= (r.cantidadmg/r.horas);
           }else if(opcion==2){
           printf("\n Coloque la dosis en ml/hora");
           scanf( "%f %f", &r.cantidadml,&r.horas );
           r.concentracion=(r.cantidadml/r.horas);
           }
            else {"\n Opcion no valida";}
}
while((opcion!=1) && (opcion!=2));
if(opcion=1){
    printf( " Su dosis en %.4f g/hora \n",r.concentracion );
}
else{ printf("Su dosis en %.4f ml/hora \n",r.concentracion);

}
        do{printf("Aceptar o Cancelar \n"); //Hice un Loop para darle a aceptar o cancelar y al presionar cancelar deberia empezar
            scanf("%s",confirmar);}
            while((strcmp(confirmar,"aceptar") !=0) && (strcmp(confirmar,"cancelar") !=0));

            while(strcmp(confirmar, "aceptar") != 0);
            entrada<<"Paciente "<<p.name<<" con edad "<< p.edad<<" en cama "<<p.cama<<" se le receto labetalol. \n" <<endl;
            if(opcion==1){
            entrada<<"Su concentracion de labetalol fue de "<<r.concentracion<<" g/hora Fecha: \n"<<fecha<<endl; //GUARDADO LO QUE SE HIZO
            }
            else{entrada<<"Su concentracion de labetalol fue de "<<r.concentracion<<" ml/hora Fecha: \n"<<fecha<<endl;}
            getch();
            break;
case 7: printf( "\n   Dosificar Lidocaina: ");
            // miligramos minuto
             do{
            printf( "\n   Concentración(mg)/Dilusión(ml) de Lidocaina : " );
            scanf( "%f %f", &r.cantidadmg,&r.cantidadml );
            r.concentracion= (r.cantidadmg/r.cantidadml);
            printf( "Su dosis es %.4f mg/ml\n",r.concentracion );
            printf("Agregue la dosis: (miligramo*minuto) \n");
            scanf("%f",&r.dosis);
            printf("La dosis es %.4f, ¿confirmar?   \n",r.dosis);
        do{printf("Aceptar o Cancelar \n");
            scanf("%s",confirmar);}
            while((strcmp(confirmar,"aceptar") !=0) && (strcmp(confirmar,"cancelar") !=0));
}
            while(strcmp(confirmar, "aceptar") != 0);
            entrada<<"Paciente "<<p.name<<" con edad "<< p.edad<<" en cama "<<p.cama<<" se le receto lidocaina. \n" <<endl;
            entrada<<"Su concentracion de lidocaina fue de "<<r.concentracion<<" mg/ml con una dosis de "<<r.dosis<<"  Fecha: \n"<<fecha<<endl; //GUARDADO LO QUE SE HIZO
            getch();
            break;
case 8: printf( "\n   Dosificar Midazolam: ");
            //miligramos kilo hora
             do{
            printf( "\n   Concentración(mg)/Dilusión(ml) de Midazolam : " );
            scanf( "%f %f", &r.cantidadmg,&r.cantidadml );
            r.concentracion= (r.cantidadmg/r.cantidadml);
            printf( "Su dosis es %.4f mg/ml\n",r.concentracion );
            printf("Agregue la dosis: (mg*kilogramo*hora) \n");
            scanf("%f",&r.dosis);
            printf("La dosis es %.4f, ¿confirmar?   \n",r.dosis);
        do{printf("Aceptar o Cancelar \n");
            scanf("%s",confirmar);}
            while((strcmp(confirmar,"aceptar") !=0) && (strcmp(confirmar,"cancelar") !=0));
}
            while(strcmp(confirmar, "aceptar") != 0);
            entrada<<"Paciente "<<p.name<<" con edad "<< p.edad<<" en cama "<<p.cama<<" se le receto midazolam. \n" <<endl;
            entrada<<"Su concentracion de midazolam fue de "<<r.concentracion<<" mg/ml con una dosis de "<<r.dosis<<"  Fecha: \n"<<fecha<<endl; //GUARDADO LO QUE SE HIZO
            getch();
            break;
case 9: printf( "\n   Dosificar Nitroglicerina: ");
            //ml/hora mg/hora
                 do{
           printf( "\n  Dosificación mg/hora(1) o ml/hora(2) de Nitroglicerina : " );
           scanf("%d",opcion);
           if(opcion==1){
            printf("\n Ingrese la dosis en mg/hora");
            scanf( "%f %f", &r.cantidadmg,&r.horas );
            r.concentracion= (r.cantidadmg/r.horas);
           }else if(opcion==2){
           printf("\n Coloque la dosis en ml/hora");
           scanf( "%f %f", &r.cantidadml,&r.horas );
           r.concentracion=(r.cantidadml/r.horas);
           }
            else {"\n Opcion no valida";}
}
while((opcion!=1) && (opcion!=2));
if(opcion=1){
    printf( " Su dosis en %.4f mg/hora \n",r.concentracion );
}
else{ printf("Su dosis en %.4f ml/hora \n",r.concentracion);

}
        do{printf("Aceptar o Cancelar \n"); //Hice un Loop para darle a aceptar o cancelar y al presionar cancelar deberia empezar
            scanf("%s",confirmar);}
            while((strcmp(confirmar,"aceptar") !=0) && (strcmp(confirmar,"cancelar") !=0));

            while(strcmp(confirmar, "aceptar") != 0);
            entrada<<"Paciente "<<p.name<<" con edad "<< p.edad<<" en cama "<<p.cama<<" se le receto Nitroglicerina. \n" <<endl;
            if(opcion==1){
            entrada<<"Su concentracion de nitroglicerina fue de "<<r.concentracion<<" mg/hora Fecha: \n"<<fecha<<endl; //GUARDADO LO QUE SE HIZO
            }
            else{entrada<<"Su concentracion de nitroglicerina fue de "<<r.concentracion<<" ml/hora Fecha: \n"<<fecha<<endl;}
            getch();
            break;
case 10: printf( "\n   Dosificar Nitroprusiato: ");
            //ml/hora mg/hora
               do{
           printf( "\n  Dosificación mg/hora(1) o ml/hora(2) de Nitroprusiato : " );
           scanf("%d",opcion);
           if(opcion==1){
            printf("\n Ingrese la dosis en mg/hora");
            scanf( "%f %f", &r.cantidadmg,&r.horas );
            r.concentracion= (r.cantidadmg/r.horas);
           }else if(opcion==2){
           printf("\n Coloque la dosis en ml/hora");
           scanf( "%f %f", &r.cantidadml,&r.horas );
           r.concentracion=(r.cantidadml/r.horas);
           }
            else {"\n Opcion no valida";}
}
while((opcion!=1) && (opcion!=2));
if(opcion=1){
    printf( " Su dosis en %.4f mg/hora \n",r.concentracion );
}
else{ printf("Su dosis en %.4f ml/hora \n",r.concentracion);

}
        do{printf("Aceptar o Cancelar \n"); //Hice un Loop para darle a aceptar o cancelar y al presionar cancelar deberia empezar
            scanf("%s",confirmar);}
            while((strcmp(confirmar,"aceptar") !=0) && (strcmp(confirmar,"cancelar") !=0));

            while(strcmp(confirmar, "aceptar") != 0);
            entrada<<"Paciente "<<p.name<<" con edad "<< p.edad<<" en cama "<<p.cama<<" se le receto nitroprusiato. \n" <<endl;
            if(opcion==1){
            entrada<<"Su concentracion de nitroprusiato fue de "<<r.concentracion<<" mg/hora Fecha: \n"<<fecha<<endl; //GUARDADO LO QUE SE HIZO
            }
            else{entrada<<"Su concentracion de nitroprusiato fue de "<<r.concentracion<<" ml/hora Fecha: \n"<<fecha<<endl;}
            getch();
            break;
case 11: printf( "\n   Dosificar Noradrenalina: ");
            // microgramo kilo minuto
              do{
            printf( "\n   Concentración(mg)/Dilusión(ml) de Noradrenalina : " );
            scanf( "%f %f", &r.cantidadmg,&r.cantidadml );
            r.concentracion= (r.cantidadmg/r.cantidadml);
            printf( "Su dosis es %.4f mg/ml\n",r.concentracion );
            printf("Agregue la dosis: (ug*kilogramo*hora) \n");
            scanf("%f",&r.dosis);
            printf("La dosis es %.4f, ¿confirmar?   \n",r.dosis);
        do{printf("Aceptar o Cancelar \n");
            scanf("%s",confirmar);}
            while((strcmp(confirmar,"aceptar") !=0) && (strcmp(confirmar,"cancelar") !=0));
}
            while(strcmp(confirmar, "aceptar") != 0);
            entrada<<"Paciente "<<p.name<<" con edad "<< p.edad<<" en cama "<<p.cama<<" se le receto noradrenalina. \n" <<endl;
            entrada<<"Su concentracion de noradrenalina fue de "<<r.concentracion<<" mg/ml con una dosis de "<<r.dosis<<"  Fecha: \n"<<fecha<<endl; //GUARDADO LO QUE SE HIZO
            getch();
            break;
case 12: printf( "\n   Dosificar Propofol: ");
            // mg kilo hora
              do{
            printf( "\n   Concentración(mg)/Dilusión(ml) de Propofol : " );
            scanf( "%f %f", &r.cantidadmg,&r.cantidadml );
            r.concentracion= (r.cantidadmg/r.cantidadml);
            printf( "Su dosis es %.4f mg/ml\n",r.concentracion );
            printf("Agregue la dosis: (mg*kilogramo*hora) \n");
            scanf("%f",&r.dosis);
            printf("La dosis es %.4f, ¿confirmar?   \n",r.dosis);
        do{printf("Aceptar o Cancelar \n");
            scanf("%s",confirmar);}
            while((strcmp(confirmar,"aceptar") !=0) && (strcmp(confirmar,"cancelar") !=0));
}
            while(strcmp(confirmar, "aceptar") != 0);
            entrada<<"Paciente "<<p.name<<" con edad "<< p.edad<<" en cama "<<p.cama<<" se le receto propofol. \n" <<endl;
            entrada<<"Su concentracion de propofol fue de "<<r.concentracion<<" mg/ml con una dosis de "<<r.dosis<<"  Fecha: \n"<<fecha<<endl; //GUARDADO LO QUE SE HIZO
            getch();
            break;

    }
} while(opcion!=1234); //PARA QUE ACABE EL LOOP
            entrada.close();
            cout << "Los datos fueron almacenados correctamente \n"    ;



return 0;}


