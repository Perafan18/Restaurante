#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#define N 1 //para prueba todos los registros se realizan solo dos veces
typedef struct{//Tabla de Empleado
        int id_empleado; //id de la tabla
        char nombre[20];
        char apellido_p[20];
        char apellido_m[20];
        int day,month,year;
        char sexo[10];
        char direccion[50];
        char telefono[12];
        int no_nomina;
        int id_area;
        char puesto[20];
        int habilitado; //habilitado o deshabilitado
        }empleado;
typedef struct{//Tabla de Inventario
		int id_inventario; //id de la tabla
		char nombre[20];
		float peso,costo,cantidad;
		int habilitado; //habilitado o deshabilitado
}inventario;
typedef struct{//Tabla de Area
		int id_area; //id de la tabla
		char nombre[20];
		char desc_area[50];
		int habilitado; //habilitado o deshabilitado
}area;
typedef struct{//Tabla de Egresos
		int id_egreso; //id de la tabla
		char concepto;
		int day,month,year;
}egreso;
typedef struct{ //Tabla Orden
        int id_orden; //id de la tabla
        int day,month,year;
        int mesa;
        char detalles[40];
        float total;
        int habilitado; //habilitado o deshabilitado
}orden;
typedef struct{ //Tabla de Receta
        int id_receta; //id de la tabla
        char nombre_receta[20];
        char descripcion_receta[40];
        float precio_receta;
        int habilitado; //habilitado o deshabilitado
}receta;
//PORTADA DE INICIO
void portada(){
     printf("\n\t\t\t****** Proyecto Final******\n\n\n\t\t>>RESTAURANTE>>\n\n\t\tUniversidad Politecnica de San Luis Potosi\n\n\n\t\tIntegrantes:\n\n\t\tPedro Perafan Carrasco\n\t\tJorgei Nava Granados\n\t\tAlejandra Melendez Reyes\n\n\t\tProgramacion 2\n\n");
     system("pause");
     system("cls");
     }
///REGISTRO DE EMPLEADOS
void registro(FILE *arch){ //manejo de archivos
    FILE *erch;
    area temporal;
	arch=fopen("Empleados.txt","w"); //archivo de empleado
     empleado emp[N];
     //fputs("**Registro de Empleados**\n",arch);
     //fputs("ID Nom   \tAp_Pat\t   Ap_Mat\t\t Fecha_Nac\t\t Genero\t\t Direccion\t Telefono  Nomina  Puesto\n",arch); //Acomodo en el archivo
     for(int i=0;i<N;i++){
          printf("\n***Registro de empleados***\n\n");
          fprintf(arch,"%d  ",i+1);
          printf("Nombre: ");
          fflush(stdin);
          gets(emp[i].nombre);
          fputs(emp[i].nombre, arch);
           fputc('\t',arch);
          printf("Apellido Paterno: ");
          fflush(stdin);
          gets(emp[i].apellido_p);
          fputs(emp[i].apellido_p, arch);
           fputc('\t',arch);
          printf("Apellido Materno: ");
          fflush(stdin);
          gets(emp[i].apellido_m);
          fputs(emp[i].apellido_m, arch);
           fputc('\t',arch);
          printf("Fecha de Nacimiento\n");
          do{ //validacion de dias, mes y año
          printf("Dia: ");
          scanf("%d", &emp[i].day);
                      if(emp[i].day!=0 && emp[i].day>31)
                      	printf("\tDia Invalido\n");
          }while(emp[i].day!=0 && emp[i].day>32);
          fputc('\t',arch);
             fprintf(arch,"%d",emp[i].day);
             fputs("/",arch);
            do{
          printf("Mes: ");
          scanf("%d", &emp[i].month);
                      if(emp[i].month!=0 && emp[i].month>13)
                      	printf("\tMes Invalido\n");
          }while(emp[i].month!=0 && emp[i].month>13);
              fprintf(arch,"%d",emp[i].month);
               fputs("/",arch);
          printf("A\xA4o: ");
          scanf("%d", &emp[i].year);
          fprintf(arch,"%d",emp[i].year);
          fputc('\t',arch);
          fputc('\t',arch);
              do{ //validacion de sexo solo Masculino o Femenino
                   printf("Sexo: 1.Masculino 2.Femenino  \n");
                   fflush(stdin);
                   gets(emp[i].sexo);
                      if(strcmp(emp[i].sexo,"Masculino")!= 0&&strcmp(emp[i].sexo,"Femenino")!= 0)
                            printf("\tSolo es valido 'Masculino' y 'Femenino'\n");
                }while(strcmp(emp[i].sexo,"Masculino")!= 0&&strcmp(emp[i].sexo,"Femenino")!= 0);
                fputs(emp[i].sexo, arch);
                 fputc('\t',arch);
          printf("Direccion: ");
          gets(emp[i].direccion);
          fputs(emp[i].direccion, arch);
           fputc('\t',arch);
          printf("Telefono: ");
          gets(emp[i].telefono);
          fputs(emp[i].telefono, arch);
           fputc('\t',arch);
           if(erch = fopen("Area.txt","r+")){
               while(!feof(erch)){
               fscanf(erch,"%d",&temporal.id_area);
               fscanf(erch,"%s",temporal.nombre);
               fscanf(erch,"%s",temporal.desc_area);
               fscanf(erch,"%d",&temporal.habilitado);

                   if(temporal.habilitado==1){
                   printf("%d\t%s\t%s\n",temporal.id_area,temporal.nombre,temporal.desc_area);
                   }

               }
           }else{
           printf("Error en el archivo de Area.txt\n");
           break;
           }
           printf("Elige una opcion\n");
          scanf("%d",&emp[i].id_area);
            fprintf(arch,"%d",emp[i].id_area);
           fputc('\t',arch);

          printf("Puesto: ");
          fflush(stdin);
          gets(emp[i].puesto);
          fputs(emp[i].puesto, arch);
           fputc('\n',arch);
        }
        fclose(arch);
}
///REGISTRO DE ORDEN
void registro_orden(FILE *arch){
	orden ord[N];
	arch=fopen("Orden.txt","w"); //archivo de Orden
     printf("\n***Registro de Ordenes***\n\n");
     fputs("**Registro de Ordenes**\n",arch);
     fputs("ID    fecha   \t Mesa   \tDetalles\t   Total\n",arch); //Acomodo en el archivo
     for(int i=0;i<N;i++){
          fprintf(arch,"%d     ",i+1);
          printf("Fecha de la orden \n");
	          do{           //validacion de la fecha
	          printf("Dia: ");
	          scanf("%d", &ord[i].day);
	                      if(ord[i].day!=0 && ord[i].day>31)
	                      	printf("\tDia Invalido\n");
	          }while(ord[i].day!=0 && ord[i].day>32);
	        //  fputc('\t',arch);
	             fprintf(arch,"%d",ord[i].day);
	             fputs("/",arch);
	            do{
	          printf("Mes: ");
	          scanf("%d", &ord[i].month);
	                      if(ord[i].month!=0 && ord[i].month>13)
	                      	printf("\tMes Invalido\n");
	          }while(ord[i].month!=0 && ord[i].month>13);
	              fprintf(arch,"%d",ord[i].month);
	               fputs("/",arch);
	          printf("A\xA4o: ");
	          scanf("%d", &ord[i].year);
         	  fprintf(arch,"%d",ord[i].year);
        	  fputc('\t',arch);
          printf("Numero de Mesa: ");
	        scanf("%d",&ord[i].mesa);
	        fprintf(arch,"    %d   ",ord[i].mesa);
	        fputc('\t',arch);
          printf("Detalles: ");
          	fflush(stdin);
	        gets(ord[i].detalles);
	        fputs(ord[i].detalles, arch);
	        fputc('\t',arch);
          printf("Total: ");
          	scanf("%f",&ord[i].total);
          	fprintf(arch,"%f",ord[i].total);
          	fputc('\t',arch);
           fputc('\n',arch);
        }
        fclose(arch);
}
//REGISTRO DE AREA//
void agregar_area(){
     FILE *arch;
     area agregar;
     area temp;
     temp.id_area =0;
     if(arch = fopen("Area.txt","r+")){
        while(!feof(arch)){
            printf("hola\n");
            fscanf(arch,"%d",&temp.id_area);
            fscanf(arch,"%s",temp.nombre);
            fscanf(arch,"%s",temp.desc_area);
            fscanf(arch,"%d",&temp.habilitado);
        }
     }
     printf("ID de Area : %d\n",temp.id_area+1);
     agregar.id_area = temp.id_area+1;
     printf("Nombre del area: ");
     fflush(stdin);
     gets(agregar.nombre);
     printf("Descripcion del area:\n");
     fflush(stdin);
     gets(agregar.desc_area);
     printf("--Estado del area--\n");
     printf("\t1.- Habilitado\n\t2.- Deshabilitado\n");
     fflush(stdin);
     scanf("%d",&agregar.habilitado);
         if(arch = fopen("Area.txt","a+")){//archivo de area
            fprintf(arch,"%d %s %s %d\n",agregar.id_area,agregar.nombre,agregar.desc_area,agregar.habilitado);
            printf("Guardado en el archivo\n");
         }else{
            printf("Error al abrir el archivo\n");
         }
        fclose(arch);
}
/// REGISTRO DE RECETA
void registro_receta(FILE *arch){
	receta rec[N];
	arch=fopen("Receta.txt","w");//Archivo de Receta
     printf("\n***Registro de Recetas***\n\n");
     fputs("**Registro de Recetas**\n",arch);
     fputs("ID    Nombre    \tDescripcion    \tPrecio\n",arch);
     for(int i=0;i<N;i++){
          fprintf(arch,"%d     ",i+1);
          printf("Nombre de la Receta: ");
	        fflush(stdin);
	        gets(rec[i].nombre_receta);
	        fputs(rec[i].nombre_receta, arch);
	        fputc('\t',arch);
	        fputc('\t',arch);
          printf("Descripcion: ");
          	fflush(stdin);
	        gets(rec[i].descripcion_receta);
	        fputs(rec[i].descripcion_receta, arch);
	        fputc('\t',arch);
	        fputc('\t',arch);
          printf("Precio de la Receta: ");
          	scanf("%f",&rec[i].precio_receta);
          	fprintf(arch,"%f",rec[i].precio_receta);
          	fputc('\t',arch);
            fputc('\n',arch);
        }
        fclose(arch);
}
void ver_empleado(FILE *arch){
    empleado temporal;
    area temp;
    char area[30];
    FILE *erch;
    arch = fopen("Empleados.txt","r+");
    while(!feof(arch)){
        fscanf(arch,"%d",&temporal.id_empleado);
        fscanf(arch,"%s",&temporal.nombre);
        fscanf(arch,"%s",&temporal.apellido_p);
        fscanf(arch,"%s",&temporal.apellido_p);
        fscanf(arch,"%d",&temporal.day);
        fscanf(arch,"%d",&temporal.month);
        fscanf(arch,"%d",&temporal.year);
        fscanf(arch,"%s",&temporal.sexo);
        fscanf(arch,"%s",&temporal.direccion);
        fscanf(arch,"%s",&temporal.telefono);
        fscanf(arch,"%d",&temporal.id_area);
        fscanf(arch,"%s",&temporal.puesto);

        erch = fopen("Area.txt","r+");
        while(!feof(erch)){
            fscanf(erch,"%d",&temp.id_area);
            fscanf(erch,"%s",&temp.nombre);
            fscanf(erch,"%s",&temp.desc_area);
            fscanf(erch,"%s",&temp.habilitado);
            if(temporal.id_area==temp.id_area){
                strcpy(area,temp.nombre);
            }
        }
        printf("%d %s %s %s %d %d %d %s %s %s %s %s\n\t",temporal.id_empleado,temporal.nombre,temporal.apellido_p,temporal.apellido_m,temporal.day,temporal.month,temporal.year,temporal.sexo,temporal.direccion,temporal.telefono,area,temporal.puesto);
    }
}
//MENU PRINCIPAL
void menu_principal(FILE *arch){
     int op, op2;
     printf("\n\t**Menu Principal**\n\t");
     printf("1. Empleado\n\t2. Receta\n\t3. Orden\n\t4. Inventario\n\t5. Area\n\t6. Egresos\n");//Opciones
     scanf("%d",&op);
     switch(op){
                case 1:
                     printf("\n\t**Menu Empleado**\n\t"); //menús principales
                      printf("1. Agregar\n\t2. Ver\n\t3. Modificar\n\t4. Dar de Baja\n\t");
                      scanf("%d",&op2);
                     switch(op2){
                                 case 1:
                                      printf("\n\t**Agregar Empleado**\n\t");
                                      registro(arch);
                                      break;
                                 case 2:
                                     printf("\n\t**Ver Empleados**\n\t");
                                        ver_empleado(arch);
                                    break;
                                 case 3:
                                      printf("\n\t**Modificar Empleado**\n\t");
                                      //registro(arch);
                                      break;
                                 case 4:
                                      printf("\n\t**Dar de Baja Empleado**\n\t");
                                      //registro(arch);
                                      break;
                                 default:
                                      printf("\n\tNo existe esa opcion.\n\t");
                                      break;
                     }
                     break;
                case 2:
                     printf("\n\t**Menu Receta**\n\t");
                     printf("1. Agregar\n\t2. Modificar\n\t3. Dar de Baja\n\t");
                     scanf("%d",&op2);
                     switch(op2){
                                 case 1:
                                      printf("\n\t**Agregar Receta**\n\t");
                                      registro_receta(arch);
                                      break;
                                 case 2:
                                      printf("\n\t**Modificar Receta**\n\t");
                                      break;
                                 case 3:
                                      printf("\n\t**Dar de Baja Receta**\n\t");
                                      break;
                                 default:
                                      printf("\n\tNo existe esa opcion.\n\t");
                                      break;
                     }
                     break;
                case 3:
                     printf("\n\t**Menu Orden**\n\t");
                     printf("1. Agregar\n\t2. Modificar\n\t3. Dar de Baja\n\t");
                     scanf("%d",&op2);
                     switch(op2){
                                 case 1:
                                      printf("\n\t**Agregar Orden**\n\t");
                                      registro_orden(arch);
                                      break;
                                 case 2:
                                      printf("\n\t**Modificar Orden**\n\t");
                                      break;
                                 case 3:
                                      printf("\n\t**Dar de Baja Orden**\n\t");
                                      break;
                                 default:
                                      printf("\n\tNo existe esa opcion.\n\t");
                                      break;
                     }
                     break;
                case 4:
                     printf("\n\t**Menu Inventario**\n\t");
                     printf("1. Agregar\n\t2. Modificar\n\t3. Dar de Baja\n\t");
                     scanf("%d",&op2);
                     switch(op2){
                                 case 1:
                                      printf("\n\t**Agregar Producto en Inventario**\n\t");
                                      break;
                                 case 2:
                                       printf("\n\t**Modificar Producto en Inventario**\n\t");
                                      break;
                                 case 3:
                                      printf("\n\t**Dar de Baja Producto en Inventario**\n\t");
                                      break;
                                 default:
                                      printf("\n\tNo existe esa opcion.\n\t");
                                      break;
                     }
                     break;
                case 5:
                     printf("\n\t**Menu Area**\n\t");
                     printf("1. Agregar\n\t2. Modificar\n\t3. Dar de Baja\n\t");
                     scanf("%d",&op2);
                     switch(op2){
                                 case 1:
                                      printf("\n\t**Agregar Area**\n\t");
                                      agregar_area();
                                      break;
                                 case 2:
                                      printf("\n\t**Modificar Area**\n\t");
                                      //modificar_area();
                                      break;
                                 case 3:
                                      printf("\n\t**Dar de baja Area**\n\t");
                                      //baja_area();
                                      break;
                                 default:
                                      printf("\n\tNo existe esa opcion.\n\t");
                                      break;
                     }
                     break;
                case 6:
                     printf("\n\t**Menu Egresos**\n\t");
                     printf("1. Agregar\n\t2. Modificar\n\t3. Dar de Baja\n\t");
                     scanf("%d",&op2);
                     switch(op2){
                                 case 1:
                                      break;
                                 case 2:
                                      break;
                                 case 3:
                                      break;
                                 default:
                                      printf("\n\tNo existe esa opcion.\n\t");
                                      break;
                     }
                     break;
                default:
                        printf("\n\tNo existe esa opcion.\n\t");
                        break;
     }

}
// INICIO DE SESION
void inicio_sesion(FILE *arch,int * sesion){
     char usuariopredf[20]="admin"; //usuario predeteriminado
     char passpredf[20]="admin123"; //contraseña predeterminada
     char usuarioadmin[20],passadmin[20],adm[20],pw[20],hola[10]="hola";
     int tipo;
     char * n;
     printf("Elegir tipo de usuario:\n1.-Administrador.\n2.-Empleado.\n"); //opcion para entrar Administrador o Usuario
     scanf("%d",&tipo);
     if(tipo==1){       //si es administrador
        arch=fopen("Admin.txt","r+");  //abre el archivo de Administrador
         if(arch==NULL){   //si el archivo esta vacio significa que entra por primera vez y se le da un nombre y contraseña predeterminadas
             fflush(stdin);
             printf("Entraste por primera vez!\n");
             printf("Tu usuario es: %s\n",usuariopredf);
             printf("Tu contraseña es: %s\n",passpredf);
            arch = fopen("Admin.txt","w+");
            fprintf(arch,"%s %s",usuariopredf,passpredf);
            fclose(arch);
            *sesion = 1;  //puntero que indica que tipo de persona es, Administrador o Usuario
         }else{
            do{   //si no se entra por primera vez  se le pide que se registre
                printf("Ingresa tu usuario: ");
                fflush(stdin);
                gets(usuarioadmin);
                printf("Ingresa tu contrasena: ");
                fflush(stdin);
                gets(passadmin);
                if(arch==NULL){
                    printf("Error! \n");
                    system("pause");
                    inicio_sesion(arch,&(*sesion)); //si el archivo esta vacio regresa a la funcion inicio_sesion
                }else{
                    fscanf(arch,"%s",adm);
                    fscanf(arch,"%s",pw);
                }
                if((strcmp(usuarioadmin,adm)!=0)||(strcmp(passadmin,pw)!=0)){
                    printf("Usuario y/o Contrasena Incorrectos\n\n");
                }
            }while((strcmp(usuarioadmin,adm)!=0)||(strcmp(passadmin,pw)!=0));
            printf("Bienvenido!!\n");
            menu_principal(arch);
       }

     }else if(tipo==2){ //usuario tipo 2 es empleado
printf("Bienvenido empleado!!\n");
            menu_principal(arch);
     }else{


     }
}
main(){
		FILE *arch;
		receta rec[N];
    	orden ord[N];
       empleado emp[N];
       int sesion;
       portada();
       inicio_sesion(arch,&sesion);
       menu_principal(arch);
       system("pause");
       //registro(arch);
       }
