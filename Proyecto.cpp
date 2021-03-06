 #include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
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
        char usuario[20];
        char password[20];//password deifinida por el administrador
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
        char nombre[20];
        char descripcion[40];
        float precio;
        int habilitado; //habilitado o deshabilitado
}receta;

typedef struct{//Tabla de receta
		int id_detalle_orden;
        int id_receta;//id de receta
        int id_orden;//id de orden
}detalle_orden;

void inicio_sesion(FILE *arch, FILE *erch, int * sesion);
void menu_principal_emp(FILE *arch,  int * sesion);
void menu_principal(FILE *arch,  int * sesion);
void modificar_area(FILE *arch);
void modificar_inventario(FILE *arch);
void modificar_orden(FILE *arch);
void modificar_receta(FILE *arch);
void modificar_empleado(FILE *arch);
void ver_orden(FILE *arch);
void ver_inventario(FILE *arch);
void ver_receta(FILE *arch);
void ver_area(FILE *arch);
void ver_empleado(FILE *arch);
void registro_receta(FILE *arch);
void registro_orden(FILE *arch);
void registro_inventario();
void registro(FILE *arch);
void registro_area();
void baja_recetas(FILE *arch);
void baja_empleados(FILE *arch);
int verificar_numero(int numero);
int verificar(char string[]);
void portada();
int verificar_direccion(char string[]);
void atender_orden(FILE *arch);
void cobrar_orden(FILE *arch);

main(){
		FILE *arch;
		FILE *erch;
       int sesion;
       portada();
       	sesion=0;
       inicio_sesion(arch, erch, &sesion);
}


void atender_orden(FILE *arch){
	inventario temporal,inv;
	FILE *erch,*irch,*orch;
	int id,id_orden,id_receta,id_recetaDos,id_inventario,cantidad,id_inventarioDos,nombre,habilitado,opcion;
	float peso,costo,cantidadDos;
	ver_orden(&(*arch));
	
	printf("Dame el ID para atender.\n");
	scanf("%d",&id);
	
	if(arch = fopen("Orden_deltalle","r+")){
		while(!feof(arch)){
			fscanf(arch,"%d*",&id_orden);
			fscanf(arch,"%d*",&id_orden);
			fscanf(arch,"%d\n",&id_receta);
			if(id_orden==id){
				if(erch=fopen("Receta_inventario.txt","r+")){
					while(!feof(erch)){
						fscanf(erch,"%d*",&id_recetaDos);
						fscanf(erch,"%d*",&id_inventario);
						fscanf(erch,"%d",&cantidad);
						if(id_receta==id_recetaDos){
							if(irch = fopen("Inventario.txt","r+")){
								if(orch = fopen("InventarioTempo.txt","w")){
									while(!feof(irch)){
										fscanf(irch,"%d*",&id_inventarioDos);
										fscanf(irch,"%[^*]*",nombre);
										fscanf(irch,"%f*",&peso);
										fscanf(irch,"%f*",&costo);
										fscanf(irch,"%f*",&cantidadDos);
										fscanf(irch,"%d\n",&habilitado);
										if(id_inventario==id_inventarioDos){
											cantidad = cantidadDos-cantidad;
											fprintf(orch,"%d*%s*%f*%f*%f*%d\n",id_inventarioDos,nombre,peso,costo,cantidad,habilitado);
										}else{
											fprintf(orch,"%d*%s*%f*%f*%f*%d\n",id_inventarioDos,nombre,peso,costo,cantidadDos,habilitado);
										}
									}
								
								}
								
							}
							fclose(irch);
							fclose(orch);
							if(irch = fopen("InventarioTempo.txt","r+")){
								if(orch = fopen("Inventario.txt","w")){
									while(!feof(irch)){
										fscanf(irch,"%d*",&id_inventarioDos);
										fscanf(irch,"%[^*]*",nombre);
										fscanf(irch,"%f*",&peso);
										fscanf(irch,"%f*",&costo);
										fscanf(irch,"%f*",&cantidadDos);
										fscanf(irch,"%d\n",&habilitado);
										fprintf(orch,"%d*%s*%f*%f*%f*%d\n",id_inventarioDos,nombre,peso,costo,cantidadDos,habilitado);
										}
									}
								
								}
								
							}
							fclose(irch);
							fclose(orch);	
						}
					}
				}
			}
		}
	fclose(arch);
	fclose(erch);
	// descontando del inventario
	if(arch = fopen("Inventario.txt","r+")){
		if(erch = fopen("InventarioTemp.txt","w")){
		while(!feof(arch)){
			fscanf(arch,"%d*",&temporal.id_inventario);
	        fscanf(arch,"%[^*]*",temporal.nombre);
	        fscanf(arch,"%f*",&temporal.peso);
	        fscanf(arch,"%f*",&temporal.costo);
	        fscanf(arch,"%f*",&temporal.cantidad);
	        fscanf(arch,"%d\n",&temporal.habilitado);
	        
			if(opcion==temporal.id_inventario){
	        	fprintf(erch,"%d*%s*%f*%f*%f*%d\n",opcion,inv.nombre,inv.peso,inv.costo,inv.cantidad,inv.habilitado);
	        }else{
	        	fprintf(erch,"%d*%s*%f*%f*%f*%d\n",temporal.id_inventario,temporal.nombre,temporal.peso,temporal.costo,temporal.cantidad,temporal.habilitado);
	        }
		}
	}
}
	fclose(arch);
	fclose(erch);
		//DE REGRESO :D
	if(erch = fopen("InventarioTemp.txt","r")){
		if(arch = fopen("Inventario.txt","w")){
		while(!feof(erch)){
			fscanf(erch,"%d*",&temporal.id_inventario);
	        fscanf(erch,"%[^*]*",temporal.nombre);
	        fscanf(erch,"%f*",&temporal.peso);
	        fscanf(erch,"%f*",&temporal.costo);
	        fscanf(erch,"%f*",&temporal.cantidad);
	        fscanf(erch,"%d\n",&temporal.habilitado);
	        	fprintf(arch,"%d*%s*%f*%f*%f*%d\n",temporal.id_inventario,temporal.nombre,temporal.peso,temporal.costo,temporal.cantidad,temporal.habilitado);
		}
	}
}
	fclose(arch);
	fclose(erch);
	

}
//PORTADA DE INICIO
void portada(){
     printf("\n\t\t\t****** Proyecto Final******\n\n\n\t\t>>RESTAURANTE>>\n\n\t\tUniversidad Politecnica de San Luis Potosi\n\n\n\t\tIntegrantes:\n\n\t\tPedro Perafan Carrasco\n\t\tJorgei Nava Granados\n\t\tAlejandra Melendez Reyes\n\n\t\tProgramacion 2\n\n");
     system("pause");
     system("cls");
     }

int verificar(char string[]){
	int num = strlen(string);
	char numeros[10] = {'1','2','3','4','5','6','7','8','9','0'};
	if(strchr(string,'*')>0){
		printf("Nombre no valido , no uses * (asterisco)\n\n");
		return 2;
	}else{
		if(strlen(string)==0){
			printf("Longuitud minima es de un caracter\n\n");
			return 3;
		}else{
			for(int i=0;i<10;i++){
				if(strchr(string,numeros[i])>0){
					printf("No introduzca numeros\n\n");
						return 4;
				}
			}
			return 1;
		}
	}
}
int verificar_telefono(char string[]){
	int num = strlen(string);
	
	if(strchr(string,'*')>0){
		printf("Telefono no valido , no uses * (asterisco)\n\n");
		return 2;
	}else{
		if(strlen(string)==0){
			printf("Longuitud minima es de un caracter\n\n");
			return 3;
		}else{
			for(int i=0;i<num;i++){
				if(string[i]=='0'||string[i]=='1'||string[i]=='2'||string[i]=='3'||string[i]=='4'||string[i]=='5'||string[i]=='6'||string[i]=='7'||string[i]=='8'||string[i]=='9'){
					
				}else{
					printf("Solo son permitidos los numeros\n");
					return 4;
				}
			}
			return 1;
		}
	}
}
int verificar_direccion(char string[]){
	int num = strlen(string);
	if(strchr(string,'*')>0){
		printf("Direccion no valida , no uses * (asterisco)\n\n");
		return 2;
	}else{
		if(strlen(string)==0){
			printf("Longuitud minima es de un caracter\n\n");
			return 3;
		}else{
			return 1;
		}
	}
}

int verificar_numero(int numero){
	char numeros[10] = {'1','2','3','4','5','6','7','8','9','0'};
	char string[30];
	itoa(numero,string,10);
	printf("%s \n",string);
}

/////*+++++++++++++++++++++++++++ BAJAS +++++++++++++++++++++++++++++++++++++++////////


void baja_empleados(FILE *arch){
	FILE *erch;
	int id;
	empleado temporalDos;
	if(arch = fopen("Empleados.txt","r+")){
		ver_empleado(&(*arch));
		printf("Dame el ID del usuario\n");
		scanf("%d",&id);
		
		erch = fopen("EmpleadosTemp.txt","w");
		while(!feof(arch)){
			
			fscanf(arch,"%d*",&temporalDos.id_empleado);
	        fscanf(arch,"%[^*]*",temporalDos.nombre);
	        fscanf(arch,"%[^*]*",temporalDos.apellido_p);
	        fscanf(arch,"%[^*]*",temporalDos.apellido_m);
	        fscanf(arch,"%d*",&temporalDos.day);
	        fscanf(arch,"%d*",&temporalDos.month);
	        fscanf(arch,"%d*",&temporalDos.year);
	        fscanf(arch,"%[^*]*",temporalDos.sexo);
	        fscanf(arch,"%[^*]*",temporalDos.direccion);
	        fscanf(arch,"%[^*]*",temporalDos.telefono);
	        fscanf(arch,"%d*",&temporalDos.id_area);
	        fscanf(arch,"%[^*]*",temporalDos.puesto);
	        fscanf(arch,"%[^*]*",temporalDos.usuario);
	        fscanf(arch,"%[^*]*",temporalDos.password);
	        fscanf(arch,"%d\n",&temporalDos.habilitado);
			if(temporalDos.id_empleado==id){
				fprintf(erch,"%d*%s*%s*%s*%d*%d*%d*%s*%s*%s*%d*%s*%s*%s*%d\n",temporalDos.id_empleado,temporalDos.nombre,temporalDos.apellido_m,temporalDos.apellido_p,temporalDos.day,temporalDos.month,temporalDos.year,temporalDos.sexo,temporalDos.direccion,temporalDos.telefono,temporalDos.id_area,temporalDos.puesto, temporalDos.usuario,temporalDos.password,0);
			}else{
	        	fprintf(erch,"%d*%s*%s*%s*%d*%d*%d*%s*%s*%s*%d*%s*%s*%s*%d\n",temporalDos.id_empleado,temporalDos.nombre,temporalDos.apellido_m,temporalDos.apellido_p,temporalDos.day,temporalDos.month,temporalDos.year,temporalDos.sexo,temporalDos.direccion,temporalDos.telefono,temporalDos.id_area,temporalDos.puesto, temporalDos.usuario,temporalDos.password,temporalDos.habilitado);
	        }
		}
		fclose(arch);
		fclose(erch);
		//DE REGRESO :D
		if(erch = fopen("EmpleadosTemp.txt","r+")){
			arch = fopen("Empleados.txt","w");
			while(!feof(erch)){
				fscanf(erch,"%d*",&temporalDos.id_empleado);
		        fscanf(erch,"%[^*]*",temporalDos.nombre);
		        fscanf(erch,"%[^*]*",temporalDos.apellido_p);
		        fscanf(erch,"%[^*]*",temporalDos.apellido_m);
		        fscanf(erch,"%d*",&temporalDos.day);
		        fscanf(erch,"%d*",&temporalDos.month);
		        fscanf(erch,"%d*",&temporalDos.year);
		        fscanf(erch,"%[^*]*",temporalDos.sexo);
		        fscanf(erch,"%[^*]*",temporalDos.direccion);
		        fscanf(erch,"%[^*]*",temporalDos.telefono);
		        fscanf(erch,"%d*",&temporalDos.id_area);
		        fscanf(erch,"%[^*]*",&temporalDos.puesto);
	        	fscanf(erch,"%[^*]*",temporalDos.usuario);
	        	fscanf(erch,"%[^*]*",temporalDos.password);
		        fscanf(erch,"%d\n",&temporalDos.habilitado);
		        	fprintf(arch,"%d*%s*%s*%s*%d*%d*%d*%s*%s*%s*%d*%s*%s*%s*%d\n",temporalDos.id_empleado,temporalDos.nombre,temporalDos.apellido_m,temporalDos.apellido_p,temporalDos.day,temporalDos.month,temporalDos.year,temporalDos.sexo,temporalDos.direccion,temporalDos.telefono,temporalDos.id_area,temporalDos.puesto,temporalDos.usuario, temporalDos.password,temporalDos.habilitado);
		    
			}
		}
		
		fclose(arch);
		fclose(erch);
	}else{
	printf("\tPara dar de baja un empleado primero tienes que tener registrado alguno (EL archivo no existe)\n");
	system("pause");
	registro(&(*arch));
	}

		
}


void baja_recetas(FILE *arch){
	FILE *erch;
	receta temporal;
	int id;
	ver_receta(&(*arch));
	
	printf("Dame el ID para eliminar \n");
	scanf("%d",&id);
	
	if(arch = fopen("Receta.txt","r")){
		erch = fopen("RecetaTemp.txt","w");
		while(!feof(arch)){
			fscanf(arch,"%d*",&temporal.id_receta);
	        fscanf(arch,"%[^*]*",temporal.nombre);
	        fscanf(arch,"%[^*]*",temporal.descripcion);
	        fscanf(arch,"%f*",&temporal.precio);
	        fscanf(arch,"%d\n",&temporal.habilitado);
	        
			if(id==temporal.id_receta){
	        	fprintf(erch,"%d*%s*%s*%f*%d\n",temporal.id_receta,temporal.nombre,temporal.descripcion,temporal.precio,0);
	        }else{
	        	fprintf(erch,"%d*%s*%s*%f*%d\n",temporal.id_receta,temporal.nombre,temporal.descripcion,temporal.precio,temporal.habilitado);
	        }
		}
	fclose(arch);
	fclose(erch);
		//DE REGRESO :D
	if(erch = fopen("RecetaTemp.txt","r")){
		arch = fopen("Receta.txt","w");
		while(!feof(erch)){
			fscanf(erch,"%d*",&temporal.id_receta);
	        fscanf(erch,"%[^*]*",temporal.nombre);
	        fscanf(erch,"%[^*]*",temporal.descripcion);
	        fscanf(erch,"%f*",&temporal.precio);
	        fscanf(erch,"%d\n",&temporal.habilitado);
	        
	        	fprintf(arch,"%d*%s*%s*%f*%d\n",temporal.id_receta,temporal.nombre,temporal.descripcion,temporal.precio,temporal.habilitado);
	    
		}
	}
	
	fclose(arch);
	fclose(erch);
	}else{
		printf("No existe el archivo de Recetas,ingresa nuevas recetas\n");
		registro_receta(&(*arch));
	}
}

void baja_inventario(FILE *arch){
	FILE *erch;
	inventario temporal;
	int id;
	ver_inventario(&(*arch));
	printf("Dame el ID para eliminar \n");
	scanf("%d",&id);
	
	if(arch = fopen("Inventario.txt","r")){
		erch = fopen("InventarioTemp.txt","w");
		while(!feof(arch)){
			fscanf(arch,"%d*",&temporal.id_inventario);
	        fscanf(arch,"%[^*]*",temporal.nombre);
	        fscanf(arch,"%f*",&temporal.peso);
	        fscanf(arch,"%f*",&temporal.costo);
	        fscanf(arch,"%f*",&temporal.cantidad);
	        fscanf(arch,"%d\n",&temporal.habilitado);
	        
			if(id==temporal.id_inventario){
	        	fprintf(erch,"%d*%s*%f*%f*%f*%d\n",temporal.id_inventario,temporal.nombre,temporal.peso,temporal.costo,temporal.cantidad,0);
	        }else{
	        	fprintf(erch,"%d*%s*%f*%f*%f*%d\n",temporal.id_inventario,temporal.nombre,temporal.peso,temporal.costo,temporal.cantidad,temporal.habilitado);
	        }
		}
	}
	fclose(arch);
	fclose(erch);
		//DE REGRESO :D
	if(erch = fopen("InventarioTemp.txt","r")){
		arch = fopen("Inventario.txt","w");
		while(!feof(erch)){
			fscanf(erch,"%d*",&temporal.id_inventario);
	        fscanf(erch,"%[^*]*",temporal.nombre);
	        fscanf(erch,"%f*",&temporal.peso);
	        fscanf(erch,"%f*",&temporal.costo);
	        fscanf(erch,"%f*",&temporal.cantidad);
	        fscanf(erch,"%d\n",&temporal.habilitado);
	        
	        	fprintf(arch,"%d*%s*%f*%f*%f*%d\n",temporal.id_inventario,temporal.nombre,temporal.peso,temporal.costo,temporal.cantidad,temporal.habilitado);
	    
		}
	}
	
	fclose(arch);
	fclose(erch);
}
void baja_area(FILE *arch){
	FILE *erch;
	int id;
	area temporal;
	ver_area(&(*arch));
	printf("Dame el ID para eliminar \n");
	scanf("%d",&id);
	
	
	if(arch = fopen("Area.txt","r")){
		erch = fopen("AreaTemp.txt","w");
		while(!feof(arch)){
			fscanf(arch,"%d*",&temporal.id_area);
	        fscanf(arch,"%[^*]*",temporal.nombre);
	        fscanf(arch,"%[^*]*",temporal.desc_area);
	        fscanf(arch,"%d\n",&temporal.habilitado);
	        
			if(id==temporal.id_area){
	        	fprintf(erch,"%d*%s*%s*%d\n",temporal.id_area,temporal.nombre,temporal.desc_area,0);
	        }else{
	        	fprintf(erch,"%d*%s*%s*%d\n",temporal.id_area,temporal.nombre,temporal.desc_area,temporal.habilitado);
	        }
		}
	}
	fclose(arch);
	fclose(erch);
		//DE REGRESO :D
	if(erch = fopen("AreaTemp.txt","r")){
		arch = fopen("Area.txt","w");
		while(!feof(erch)){
			fscanf(erch,"%d*",&temporal.id_area);
	        fscanf(erch,"%[^*]*",temporal.nombre);
	        fscanf(erch,"%[^*]*",temporal.desc_area);
	        fscanf(erch,"%d\n",&temporal.habilitado);
	        
	        	fprintf(arch,"%d*%s*%s*%d\n",temporal.id_area,temporal.nombre,temporal.desc_area,temporal.habilitado);
	    
		}
	}
	
	fclose(arch);
	fclose(erch);
}
////*************************REGISTROS*****************************************////////
     
     
//REGISTRO DE AREA//
void registro_area(){
     FILE *arch;
     area agregar;
     area temp;
     temp.id_area =0;
     if(arch = fopen("Area.txt","r+")){
        while(!feof(arch)){
            fscanf(arch,"%d*",&temp.id_area);
            fscanf(arch,"%[^*]*",temp.nombre);
            fscanf(arch,"%[^*]*",temp.desc_area);
            fscanf(arch,"%d\n",&temp.habilitado);
        }
     }
     
     printf("ID de Area : %d\n",temp.id_area+1);
     agregar.id_area = temp.id_area+1;
     do{
	 printf("Nombre del area: ");
     fflush(stdin);
     gets(agregar.nombre);
 	}while(verificar(agregar.nombre)!=1);
 	
 	do{
	 printf("Descripcion del area:\n");
     fflush(stdin);
     gets(agregar.desc_area);
 	}while(verificar(agregar.desc_area)!=1);
 	

         if(arch = fopen("Area.txt","a+")){//archivo de area
            fprintf(arch,"%d",agregar.id_area);
            fputc('*',arch);
            fprintf(arch,"%s",agregar.nombre);
            fputc('*',arch);
            fprintf(arch,"%s",agregar.desc_area);
            fputc('*',arch);
            fprintf(arch,"%d",1);
            fputc('\n',arch);
         }else{
            printf("Error al abrir el archivo\n");
         }
        fclose(arch);
}     
     
///REGISTRO DE EMPLEADOS////
void registro(FILE *arch){ //manejo de archivos
system("cls");
    FILE *erch;
    FILE *irch;
    int resultado,correcto=0;
    area temporal;
	 empleado emp,tempo,temporalDos;
	 char cadena[30];
     //fputs("**Registro de Empleados**\n",arch);
     //fputs("ID Nom   \tAp_Pat\t   Ap_Mat\t\t Fecha_Nac\t\t Genero\t\t Direccion\t Telefono  Nomina  Puesto\n",arch); //Acomodo en el archivo
	emp.id_empleado = 0;
	tempo.id_empleado =0;
	if(!(arch = fopen("Area.txt","r+"))){
		printf("Para ingresar usuarios primero tienes que ingresar las areas\n");
		system("pause");
		registro_area();
	}
	if(arch = fopen("Empleados.txt","r+")){
		while(!feof(arch)){
	        fscanf(arch,"%d*",&tempo.id_empleado);
	        fscanf(arch,"%[^*]*",&tempo.nombre);
	        fscanf(arch,"%[^*]*",&tempo.apellido_m);
	        fscanf(arch,"%[^*]*",&tempo.apellido_p);
	        fscanf(arch,"%d*",&tempo.day);
	        fscanf(arch,"%d*",&tempo.month);
	        fscanf(arch,"%d*",&tempo.year);
	        fscanf(arch,"%[^*]*",&tempo.sexo);
	        fscanf(arch,"%[^*]*",&tempo.direccion);
	        fscanf(arch,"%[^*]*",&tempo.telefono);
	        fscanf(arch,"%d*",&tempo.id_area);
	        fscanf(arch,"%[^*]*",&tempo.puesto);
	        fscanf(arch,"%[^'\n']\n",&tempo.password);
		}
	}
	arch=fopen("Empleados.txt","a+"); //archivo de empleado
	emp.id_empleado = tempo.id_empleado +1;
	fprintf(arch,"%d*",emp.id_empleado);

        printf("\n***Registro de empleados***\n\n");
          
		do{
			printf("Nombre: ");
			fflush(stdin);
			gets(emp.nombre);
		}while(verificar(emp.nombre)!=1);
		
		fputs(emp.nombre, arch);
		fputc('*',arch);
        
		do{   
		printf("Apellido Paterno: ");
		fflush(stdin);
		gets(emp.apellido_p);
		}while(verificar(emp.apellido_p)!=1);
		
		fputs(emp.apellido_p, arch);
		fputc('*',arch);
           
    	do{ 
		printf("Apellido Materno: ");
		fflush(stdin);
		gets(emp.apellido_m);
		}while(verificar(emp.apellido_m)!=1);
		fputs(emp.apellido_m, arch);
		fputc('*',arch);
		
		printf("Fecha de Nacimiento\n");
		do{ //validacion de dias, mes y a�o
			printf("Dia: ");
			fflush(stdin);
			resultado =  scanf("%d", &emp.day);
			if(resultado!=1){
				printf("Solo ingrese numeros\n");
			}
			if(emp.day<0 || emp.day>31){
				printf("\tDia Invalido\n");
			}
		}while(emp.day<0 || emp.day>31 || resultado !=1);
		fprintf(arch,"%d",emp.day);
		fputc('*',arch);
          
		do{
			printf("Mes: ");
			fflush(stdin);
			resultado = scanf("%d", &emp.month);
			if(resultado!=1){
				printf("Solo ingrese numeros\n");
			}
			if(emp.month<0 || emp.month>12)
			printf("\tMes Invalido\n");
		}while(emp.month<0 || emp.month>12 || resultado !=1);
		fprintf(arch,"%d",emp.month);
		fputc('*',arch);
        
        do{
			printf("A\xA4o: ");
			fflush(stdin);
			scanf("%d", &emp.year);
			if(emp.year<1924){
				printf("A\xA4o Invalido, a\xA4o minimo 1924\n\n");
			}else if(emp.year>2014){
				printf("A\xA4o Invalido , a\xA4o maximo 2014\n\n");
			}
		}while(emp.year<1924||emp.year>2014);
		fprintf(arch,"%d",emp.year);
		fputc('*',arch);
		
		do{ //validacion de sexo solo Masculino o Femenino
			printf("Sexo: Masculino o Femenino  \n");
			fflush(stdin);
			gets(emp.sexo);
			if(strcmp(emp.sexo,"Masculino")!= 0&&strcmp(emp.sexo,"Femenino")!= 0)
			printf("\tSolo es valido 'Masculino' y 'Femenino'\n");
		}while(strcmp(emp.sexo,"Masculino")!= 0&&strcmp(emp.sexo,"Femenino")!= 0);
		fputs(emp.sexo, arch);
		fputc('*',arch);
		
		do{
        printf("Direccion: ");
        gets(emp.direccion);

    	}while(verificar_direccion(emp.direccion)!=1);
        fputs(emp.direccion, arch);
        fputc('*',arch);
        
        do{
		printf("Telefono: ");
		gets(emp.telefono);
		}while(verificar_telefono(emp.telefono)!=1);
		
		fputs(emp.telefono, arch);
		fputc('*',arch);
           
        do{
    
			if(erch = fopen("Area.txt","r+")){
				while(!feof(erch)){
				fscanf(erch,"%d*",&temporal.id_area);
				fscanf(erch,"%[^*]*",temporal.nombre);
				fscanf(erch,"%[^*]*",temporal.desc_area);
				fscanf(erch,"%d\n",&temporal.habilitado);
					if(temporal.habilitado==1){
					printf("%d\t%s\t%s\n",temporal.id_area,temporal.nombre,temporal.desc_area);
					}
				}
			}else{
				printf("Hubo un error al abrir el archivo \"Area \" ");
				system("pause");
				registro_area();
			}
		do{
		printf("Elige un area:\n");
		fflush(stdin);
		scanf("%d",&emp.id_area);
		itoa (emp.id_area,cadena,10);
		}while(verificar_telefono(cadena)!=1);
		
			if(erch = fopen("Area.txt","r+")){
				while(!feof(erch)){
				fscanf(erch,"%d*",&temporal.id_area);
				fscanf(erch,"%[^*]*",temporal.nombre);
				fscanf(erch,"%[^*]*",temporal.desc_area);
				fscanf(erch,"%d\n",&temporal.habilitado);
					if(temporal.habilitado==1){
						if(temporal.id_area==emp.id_area){
							correcto = 1;
						}
					}
				}
			}
			if(correcto!=1){
				printf("Area no valida,por favor vuele a elegir\n\n");
			}
		}while(correcto!=1);
		correcto=0;
		
		fprintf(arch,"%d",emp.id_area);
		fputc('*',arch);
		
		do{
		printf("Puesto: ");
		fflush(stdin);
		gets(emp.puesto);		
		}while(verificar(emp.puesto)!=1);
		
		fputs(emp.puesto, arch);
		fputc('*',arch);
		do{
		
			do{
				printf("Usuario :");
				fflush(stdin);
				gets(emp.usuario);

			}while(verificar_direccion(emp.usuario)!=1);
			correcto=1;
			if(irch=fopen("Empleados.txt","r+")){
				while(!feof(irch)){
					fscanf(irch,"%d*",&temporalDos.id_empleado);
			        fscanf(irch,"%[^*]*",&temporalDos.nombre);
			        fscanf(irch,"%[^*]*",&temporalDos.apellido_p);
			        fscanf(irch,"%[^*]*",&temporalDos.apellido_m);
			        fscanf(irch,"%d*",&temporalDos.day);
			        fscanf(irch,"%d*",&temporalDos.month);
			        fscanf(irch,"%d*",&temporalDos.year);
			        fscanf(irch,"%[^*]*",&temporalDos.sexo);
			        fscanf(irch,"%[^*]*",&temporalDos.direccion);
			        fscanf(irch,"%[^*]*",&temporalDos.telefono);
			        fscanf(irch,"%d*",&temporalDos.id_area);
			        fscanf(irch,"%[^*]*",&temporalDos.puesto);
			        fscanf(irch,"%[^*]*",&temporalDos.usuario);
			        fscanf(irch,"%[^*]*",&temporalDos.password);
			        fscanf(irch,"%d\n",&temporalDos.habilitado);
			        if(temporalDos.habilitado==1){
			        	if(strcmp(temporalDos.usuario,emp.usuario)==0){
			        		correcto=2;
			        	}
			        }
				}
				fclose(irch);
			}
			
			if(correcto==2)
			printf("Este nombre de usuario ya esta en uso\n");
			
		}while(correcto!=1);
		
		fputs(emp.usuario, arch);
		fputc('*',arch);
		
		do{
			printf("Password: ");
			fflush(stdin);
			gets(emp.password);
		}while(verificar_direccion(emp.password)!=1);
		
		fputs(emp.password, arch);

		fputs("*1",arch);//Habilitado
		fputc('\n',arch);
		
        
        fclose(arch);
}

//REGISTRO DE INVENTARIO//
void registro_inventario(){
	 printf("***************Nuevo Producto (INVENTARIO)***************\n");
     FILE *arch;
     inventario nuevo;
     nuevo.id_inventario =0;
     if(arch = fopen("Inventario.txt","r+")){
        while(!feof(arch)){
            fscanf(arch,"%d*",&nuevo.id_inventario);
            fscanf(arch,"%[^*]*",&nuevo.nombre);
            fscanf(arch,"%f*",&nuevo.peso);
            fscanf(arch,"%f*",&nuevo.costo);
            fscanf(arch,"%f*",&nuevo.cantidad);
            fscanf(arch,"%d\n",&nuevo.habilitado);
        }
     }
   
    nuevo.id_inventario+=1;
    nuevo.habilitado=0;
    do{
    printf("Nombre : ");
    fflush(stdin);
    gets(nuevo.nombre);
	}while(verificar(nuevo.nombre)!=1);
	
	do{
    printf("Peso : ");
    fflush(stdin);
	}while(scanf("%f",&nuevo.peso)==0||nuevo.peso<=0);
	
	do{
    printf("Costo : ");
    fflush(stdin);
    }while(scanf("%f",&nuevo.costo)==0||nuevo.costo<=0); 
    
    do{
    printf("Cantidad : ");
    fflush(stdin);
    }while(scanf("%f",&nuevo.cantidad)==0||nuevo.cantidad<=0);
    
    if(arch = fopen("Inventario.txt","a+")){
            fprintf(arch,"%d*",nuevo.id_inventario);
            fprintf(arch,"%s*",nuevo.nombre);
            fprintf(arch,"%f*",nuevo.peso);
            fprintf(arch,"%f*",nuevo.costo);
            fprintf(arch,"%f*",nuevo.cantidad);
            fprintf(arch,"%d\n",1);
    }
    fclose(arch);
}
///REGISTRO DE ORDEN
void registro_orden(FILE *arch){
	FILE *erch,*irch;
	orden ord, tempo;
	int continuar,resultado,opcion,seguir;
	detalle_orden temporal;
	receta rec;
	system("cls");
	do{
	printf("\tBienvenido , puedo tomar su orden ?\n\t1.-Si\n\t2.-No\n\t");
	}while(scanf("%d",&continuar)==0||(continuar!=1&&continuar!=2));
	if(continuar==1){
		do{
		
		tempo.id_orden = 0;
		ord.id_orden=0;
		temporal.id_detalle_orden=0;
		if(erch=fopen("Orden_detalle.txt","r+")){
			while(!feof(erch)){
				fscanf(erch,"%d*",&temporal.id_detalle_orden);
				fscanf(erch,"%d*",&temporal.id_orden);
				fscanf(erch,"%d\n",&temporal.id_receta);
			}
			fclose(erch);
		}
		temporal.id_detalle_orden+=1;
		erch = fopen("Orden_detalle.txt","a+"); 
		
		printf("Menu\n");
		ver_receta(&(*irch));
		do{
		printf("Elige mediante ID: ");
		resultado = scanf("%d",&opcion);	
		}while(resultado==0||opcion==0);
		fprintf(erch,"%d*",temporal.id_detalle_orden);
		fprintf(erch,"%d*",opcion);
		
		if(arch=fopen("Orden.txt","r+")){ //archivo de Orden
			while(!feof(arch)){
				fscanf(arch,"%d*",&tempo.id_orden);
				fscanf(arch,"%d*",&tempo.day);
				fscanf(arch,"%d*",&tempo.month);
				fscanf(arch,"%d*",&tempo.year);
				fscanf(arch,"%d*",&tempo.mesa);
				fscanf(arch,"%[^*]*",tempo.detalles);
				fscanf(arch,"%f*",&tempo.total);
				fscanf(arch,"%d\n",&tempo.habilitado);
			}
		}
		fclose(arch);
		arch=fopen("Orden.txt","a+");
		
		printf("\n***Registro de Ordenes***\n\n");
		ord.id_orden= tempo.id_orden+1;
		
		fprintf(arch,"%d*",ord.id_orden);
		fprintf(erch,"%d\n",ord.id_orden);
		printf("Fecha de la orden \n");
		
		do{ //validacion de dias, mes y a�o
				printf("Dia: ");
				fflush(stdin);
				resultado =  scanf("%d", &ord.day);
				if(resultado!=1){
					printf("Solo ingrese numeros\n");
				}
				if(ord.day<0 || ord.day>31){
					printf("\tDia Invalido\n");
				}
			}while(ord.day<0 || ord.day>31 || resultado !=1);
			fprintf(arch,"%d",ord.day);
			fputc('*',arch);
	          
			do{
				printf("Mes: ");
				fflush(stdin);
				resultado = scanf("%d", &ord.month);
				if(resultado!=1){
					printf("Solo ingrese numeros\n");
				}
				if(ord.month<0 || ord.month>12)
				printf("\tMes Invalido\n");
			}while(ord.month<0 || ord.month>12 || resultado !=1);
			fprintf(arch,"%d",ord.month);
			fputc('*',arch);
	        
	        do{
				printf("A\xA4o: ");
				fflush(stdin);
				scanf("%d", &ord.year);
				if(ord.year<2014){
					printf("A\xA4o Invalido , a\xA4o minimo 2014\n\n");
				}
			}while(ord.year<2014);
			fprintf(arch,"%d",ord.year);
			fputc('*',arch);
	
		do{
		printf("Numero de Mesa: ");
		fflush(stdin);
		}while(scanf("%d", &ord.mesa)==0||ord.mesa==0);
		fprintf(arch,"%d",ord.mesa);
		fputc('*',arch);
		
		do{
		printf("Detalles: ");
		fflush(stdin);
		gets(ord.detalles);
		}while(verificar_direccion(ord.detalles)!=1);
		fputs(ord.detalles, arch);
		fputc('*',arch);
		
		if(erch = fopen("Receta.txt","r+")){
		    while(!feof(erch)){
		    	fscanf(erch,"%d*",&rec.id_receta);
		       fscanf(erch,"%[^*]*",&rec.nombre);
		       fscanf(erch,"%[^*]*",&rec.descripcion);
		       fscanf(erch,"%f*",&rec.precio);
		       fscanf(erch,"%d\n",&rec.habilitado);
		       if(rec.habilitado==1){
		       		if(rec.id_receta==opcion){
		       			fprintf(arch,"%f",rec.precio);
						fputc('*',arch);
					}
		    			
		       }
		    }
		    fclose(arch);
		}

	
		fprintf(arch,"%d",1);
		fputc('\n',arch);
		fclose(arch);
		do{
		printf("Desea seguir ordenando\n1.-Si\n2.-No\n");
		}while(scanf("%d",&seguir)==0||(seguir!=1&&seguir!=2));
		
		}while(seguir==1);
	}else{
		printf("\n\tEntonces volvere m�s tarde..\n");
	}
}

/// REGISTRO DE RECETA
void registro_receta(FILE *arch){
	receta rec, tempo;
	FILE *erch,*irch;
	int continuar,ingrediente,correcto=0,cont=0,id,correctoDos=0;
    float porciones;
   inventario temp;

	arch=fopen("Receta.txt","a+");//Archivo de Receta
	rec.id_receta = 0;

	while(!feof(arch)){
       fscanf(arch,"%d*",&rec.id_receta);
       fscanf(arch,"%[^*]*",&rec.nombre);
       fscanf(arch,"%[^*]*",&rec.descripcion);
       fscanf(arch,"%d*",&rec.precio);
       fscanf(arch,"%d\n",&rec.habilitado);
    }
    rec.id_receta+=1;
    fprintf(arch,"%d*",rec.id_receta);
    do{
    printf("Nombre de la receta: ");
    fflush(stdin);
    gets(rec.nombre);
	}while(verificar(rec.nombre)!=1);
	fputs(rec.nombre, arch);
    fputc('*',arch);
    
    do{
    printf("Descripcion : ");
    fflush(stdin);
    gets(rec.descripcion);
	}while(verificar_direccion(rec.descripcion)!=1);
	
    fputs(rec.descripcion, arch);
    fputc('*',arch);

    do{

	    if(erch = fopen("Inventario.txt","r+")){
	        while(!feof(erch)){

	         fscanf(erch,"%d*",&temp.id_inventario);
	         fscanf(erch,"%[^*]*",temp.nombre);
	         fscanf(erch,"%f*",&temp.peso);
	         fscanf(erch,"%f*",&temp.costo);
	         fscanf(erch,"%f*",&temp.cantidad);
	         fscanf(erch,"%d\n",&temp.habilitado);
	             if(temp.habilitado==1){
	             		cont+=1;
	             		printf("ID: %d\nNombre: %s\n\n",temp.id_inventario,temp.nombre);

	             }
	        }
	        if(cont==0){
	        	printf("\nNo hay nada en el inventario\nprimero tiene que agregar algo\n");
	    		registro_inventario();
	        }
	        fclose(erch);
	        
		        do{
		        correcto=2;
		        do{
				printf("Elige un ingrediente del inventario por ID\n");
		        fflush(stdin);
		        }while(scanf("%d",&ingrediente)==0);
		        
			        erch = fopen("Inventario.txt","r+");
			        while(!feof(erch)){
			         fscanf(erch,"%d*",&temp.id_inventario);
			         fscanf(erch,"%[^*]*",temp.nombre);
			         fscanf(erch,"%f*",&temp.peso);
			         fscanf(erch,"%f*",&temp.costo);
			         fscanf(erch,"%f*",&temp.cantidad);
			         fscanf(erch,"%d\n",&temp.habilitado);
			             if(temp.habilitado==1){ 
			             	if(ingrediente==temp.id_inventario){
			             		correcto=1;
			             	}
			             }
			        }
			    if(correcto!=1){
			    	printf("No existe este elemento en el inventario, por favor vuelve a intentar\n");
			    }
		    	}while(correcto!=1);
		        
		        do{
		        printf("Cuantas porciones?\n");
		        fflush(stdin);
		        }while(scanf("%f",&porciones)==0||porciones<=0);//Validar que el numeor de porciones elegidas sea menor al que hay en el inventario
		        
		        irch = fopen("Receta_Inventario.txt","a+");
		        fprintf(irch,"%d*",rec.id_receta);
		        fprintf(irch,"%d*",ingrediente);
		        fprintf(irch,"%f\n",porciones);
		        fclose(irch);
		        
		        do{
		        printf("Desea Agregar un nuevo Ingrediente\n1.-SI\n2.-NO\n\n");
		        scanf("%d",&continuar);
		    	}while(continuar!=1&&continuar!=2);	

	    }else{
	    	printf("\nNo hay nada en el inventario\nprimero tiene que agregar algo\n");
	    	registro_inventario();
	    	continuar=1;
	    }
    }while(continuar==1);
	
	do{
    printf("Precio : ");
    fflush(stdin);
    }while(scanf("%f",&rec.precio)==0||rec.precio<=0);
    
    fprintf(arch,"%f*",rec.precio);


    fprintf(arch,"%d",1);//Habilitado
    fputc('\n',arch);
    
    
 /*   arch=fopen("Receta.txt","a+");
        fprintf(arch,"%d ",rec.id_receta);
        fprintf(arch,"%s ",rec.nombre);
        fprintf(arch,"%s ",rec.descripcion);
        fprintf(arch,"%f ",rec.precio);
        fprintf(arch,"%d\n",rec.habilitado);*/
    fclose(arch);
}
/////////////////////////////****************************VER********************************//////////////////////////////////
//VER EMPLEADO//
void ver_empleado(FILE *arch){
	system("cls");
    empleado temporal;
    area temp;
    char area[30];
    int cont=0;
    FILE *erch;
    
    if(arch = fopen("Empleados.txt","r+")){
    	
	while(!feof(arch)){
        fscanf(arch,"%d*",&temporal.id_empleado);
        fscanf(arch,"%[^*]*",&temporal.nombre);
        fscanf(arch,"%[^*]*",&temporal.apellido_p);
        fscanf(arch,"%[^*]*",&temporal.apellido_m);
        fscanf(arch,"%d*",&temporal.day);
        fscanf(arch,"%d*",&temporal.month);
        fscanf(arch,"%d*",&temporal.year);
        fscanf(arch,"%[^*]*",&temporal.sexo);
        fscanf(arch,"%[^*]*",&temporal.direccion);
        fscanf(arch,"%[^*]*",&temporal.telefono);
        fscanf(arch,"%d*",&temporal.id_area);
        fscanf(arch,"%[^*]*",&temporal.puesto);
        fscanf(arch,"%[^*]*",&temporal.usuario);
        fscanf(arch,"%[^*]*",&temporal.password);
        fscanf(arch,"%d\n",&temporal.habilitado);

        erch = fopen("Area.txt","r+");
        while(!feof(erch)){
            fscanf(erch,"%d*",&temp.id_area);
            fscanf(erch,"%[^*]*",temp.nombre);
            fscanf(erch,"%[^*]*",temp.desc_area);
            fscanf(erch,"%d\n",&temp.habilitado);
            if(temporal.id_area==temp.id_area){
                strcpy(area,temp.nombre);
            }
        }
        if(temporal.habilitado==1){
        	cont+=1;
	        printf("\tID: %d \n\tNombre :%s %s %s\n\tFecha de Nacimiento: %d %d %d\n\tSexo: %s\n\tDireccion: %s\n\tTelefono: %s \n\tArea: %s\n\tPuesto: %s\n\tUsuario: %s\n\tPassword: %s\n\n",temporal.id_empleado,temporal.nombre,temporal.apellido_p,temporal.apellido_m,temporal.day,temporal.month,temporal.year,temporal.sexo,temporal.direccion,temporal.telefono,area,temporal.puesto,temporal.usuario,temporal.password);
        }
    }
    fclose(arch);
    fclose(erch);
    if(cont==0){
    	printf("\tUpps! No hay empleados!\n");
    }
	}else{
		printf("\tNo existe este archivo, primero  tienes que registrar a algun empleado\n");
		system("pause");
		registro(&(*arch));
	}
}
//VER AREA
void ver_area(FILE *arch){
	int cont=0;
	area temp;
	if(arch = fopen("Area.txt","r+")){
        while(!feof(arch)){
            fscanf(arch,"%d*",&temp.id_area);
            fscanf(arch,"%[^*]*",temp.nombre);
            fscanf(arch,"%[^*]*",temp.desc_area);
            fscanf(arch,"%d\n",&temp.habilitado);
            if(temp.habilitado==1){
            	cont+=1;
				printf("\tID de Area:%d\n\tNombre del Area:%s\n\tDescripcion del Area:%s\n", temp.id_area, temp.nombre, temp.desc_area, temp.habilitado);
        	}
        }
        fclose(arch);
        if(cont==0){
    		printf("\tUpps! No hay areas!\n");
    	}
	}else{
		printf("\tNo existe este archivo, primero  tienes que registrar a alguna area\n");
	}
}
//VER RECETA
void ver_receta(FILE *arch){
	int cont=0,agregar;
    receta rec;
    
    if(arch = fopen("Receta.txt","r+")){
	    while(!feof(arch)){
	    	fscanf(arch,"%d*",&rec.id_receta);
	       fscanf(arch,"%[^*]*",&rec.nombre);
	       fscanf(arch,"%[^*]*",&rec.descripcion);
	       fscanf(arch,"%f*",&rec.precio);
	       fscanf(arch,"%d\n",&rec.habilitado);
	       if(rec.habilitado==1){
	       		cont+=1;
	    		printf("\tID:%d\n\tNombre del Platillo:%s\n\tDescripcion:%s\n\tPrecio:%g\n",rec.id_receta,rec.nombre,rec.descripcion,rec.precio);
	       }
	    }
	    fclose(arch);
	    if(cont==0){
    		printf("\tUpps! No hay recetas!\n\n");
    		system("pause");
	    	registro_receta(&(*arch));
    	}
	}else{
		printf("\tNo existe este archivo\nprimero  tienes que registrar a alguna receta\n");
		registro_receta(&(*arch));
	}
}
//VER INVENTARIO
void ver_inventario(FILE *arch){
	inventario nuevo;
	int cont=0;
	if(arch = fopen("Inventario.txt","r+")){
        while(!feof(arch)){
            fscanf(arch,"%d*",&nuevo.id_inventario);
            fscanf(arch,"%[^*]*",&nuevo.nombre);
            fscanf(arch,"%f*",&nuevo.peso);
            fscanf(arch,"%f*",&nuevo.costo);
            fscanf(arch,"%f*",&nuevo.cantidad);
            fscanf(arch,"%d\n",&nuevo.habilitado);
            if(nuevo.habilitado==1){
            	cont+=1;
           	 	printf("\tID:%d\n\tNombre:%s\n\tPeso:%g\n\tCosto:%g\n\tCantidad:%g\n\t", nuevo.id_inventario, nuevo.nombre, nuevo.peso, nuevo.costo, nuevo.cantidad, nuevo.habilitado);
        	}
        }
        fclose(arch);
        if(cont==0){
    		printf("\tUpps! No hay recetas!\n");
    	}
    }else{
		printf("\tNo existe este archivo, primero  tienes que registrar a alguo en el inventario\n");
	}
     
}
//VER_ORDEN
void ver_orden(FILE *arch){
    FILE *erch;
	orden ord;
	receta rec;
    detalle_orden temporal;
    int cont;
    if(erch = fopen("Orden_detalle.txt","r+")){
    	while(!feof(erch)){
    		printf("hola1");
    		fscanf(erch,"%d*",&temporal.id_detalle_orden);
    		fscanf(erch,"%d*",&temporal.id_orden);
    		fscanf(erch,"%d\n",&temporal.id_receta);
		    if(arch = fopen("Orden.txt","r+")){
			    while(!feof(arch)){
						printf("hola2");
			    	fscanf(arch,"%d*",&ord.id_orden);
				        fscanf(arch,"%d*",&ord.day);
				        fscanf(arch,"%d*",&ord.month);
				        fscanf(arch,"%d*",&ord.year);
				        fscanf(arch,"%d*",&ord.mesa);
				        fscanf(arch,"%[^*]*",ord.detalles);
				        fscanf(arch,"%f*",&ord.total);
				        fscanf(arch,"%d\n",&ord.habilitado);
					    if(ord.habilitado==1&&temporal.id_orden==ord.id_orden){
					    cont+=1;
				        printf("\nID:%d \n\tFecha: %d %d %d\n\tMesa:%d\n\tDetalles:%s\n\tTotal:%f\n\t",ord.id_orden,ord.day,ord.month,ord.year,ord.mesa,ord.detalles,ord.total,ord.habilitado);
				    	}
			    }
			    fclose(arch);
			}
			if(cont>0){
				if(arch = fopen("Receta.txt","r+")){
					while(!feof(arch)){
					   fscanf(arch,"%d*",&rec.id_receta);
				       fscanf(arch,"%[^*]*",&rec.nombre);
				       fscanf(arch,"%[^*]*",&rec.descripcion);
				       fscanf(arch,"%f*",&rec.precio);
				       fscanf(arch,"%d\n",&rec.habilitado);
				       if(rec.habilitado==1){
				    		printf("Nombre del Platillo:%s\n\t",rec.nombre);
				       }
					}
				}
			}
    	}
    }else{
		printf("\tNo existe el archivo, primero  tienes que registrar a alguna orden\n");
		system("pause");
		registro_orden(&(*arch));
	}
}
//******MODIFICAR***///
//MODIFICAR EMPLEADO//
void modificar_empleado(FILE *arch){
	area temporal;
	FILE *erch,*irch;
	empleado emp,temporalDos,temporalTres;
	int opcion,resultado,correcto=0;
	char cadena[30];
	if(arch = fopen("Empleados.txt","r+")){
	printf("Empleados\n");
	ver_empleado(arch);
	
	printf("Elige mediante ID:");
	scanf("%d",&opcion);
	
	printf("\n***Modificacion de empleados***\n\n");
	do{
			printf("Nombre: ");
			fflush(stdin);
			gets(emp.nombre);
		}while(verificar(emp.nombre)!=1);
          
	do{   
		printf("Apellido Paterno: ");
		fflush(stdin);
		gets(emp.apellido_p);
		}while(verificar(emp.apellido_p)!=1);
    
	do{ 
		printf("Apellido Materno: ");
		fflush(stdin);
		gets(emp.apellido_m);
		}while(verificar(emp.apellido_m)!=1);
    
	printf("Fecha de Nacimiento\n");
    do{ //validacion de dias, mes y a�o
			printf("Dia: ");
			fflush(stdin);
			scanf("%d", &emp.day);
			if(emp.day<0 || emp.day>31){
				printf("\tDia Invalido\n");
			}
		}while(emp.day<0 || emp.day>31);
          
	do{
			printf("Mes: ");
			fflush(stdin);
			resultado = scanf("%d", &emp.month);
			if(resultado!=1){
				printf("Solo ingrese numeros");
			}
			if(emp.month<0 || emp.month>12)
			printf("\tMes Invalido\n");
		}while(emp.month<0 || emp.month>12 || resultado !=1);
    
	do{
			printf("A\xA4o: ");
			fflush(stdin);
			scanf("%d", &emp.year);
			if(emp.year<1924){
				printf("A\xA4o Invalido, a\xA4o minimo 1924\n\n");
			}else if(emp.year>2014){
				printf("A\xA4o Invalido , a\xA4o maximo 2014\n\n");
			}
		}while(emp.year<1924||emp.year>2014);
              
	do{ //validacion de sexo solo Masculino o Femenino
        printf("Sexo: Masculino o Femenino  \n");
		fflush(stdin);
    	gets(emp.sexo);
        if(strcmp(emp.sexo,"Masculino")!= 0&&strcmp(emp.sexo,"Femenino")!= 0)
        	printf("\tSolo es valido 'Masculino' y 'Femenino'\n");
    }while(strcmp(emp.sexo,"Masculino")!= 0&&strcmp(emp.sexo,"Femenino")!= 0);
          
	do{
        printf("Direccion: ");
        gets(emp.direccion);
    	}while(verificar_direccion(emp.direccion)!=1);
          
  	do{
		printf("Telefono: ");
		gets(emp.telefono);
		}while(verificar_telefono(emp.telefono)!=1);
	
	do{
    
			if(erch = fopen("Area.txt","r+")){
				while(!feof(erch)){
				fscanf(erch,"%d*",&temporal.id_area);
				fscanf(erch,"%[^*]*",temporal.nombre);
				fscanf(erch,"%[^*]*",temporal.desc_area);
				fscanf(erch,"%d\n",&temporal.habilitado);
					if(temporal.habilitado==1){
					printf("%d\t%s\t%s\n",temporal.id_area,temporal.nombre,temporal.desc_area);
					}
				}
			}else{
				printf("Hubo un error al abrir el archivo \"Area \" ");
				system("pause");
				registro_area();
			}
		do{
		printf("Elige un area\n");
		fflush(stdin);
		scanf("%d",&emp.id_area);
		itoa (emp.id_area,cadena,10);
		}while(verificar_telefono(cadena)!=1);
		
			if(erch = fopen("Area.txt","r+")){
				while(!feof(erch)){
				fscanf(erch,"%d*",&temporal.id_area);
				fscanf(erch,"%[^*]*",temporal.nombre);
				fscanf(erch,"%[^*]*",temporal.desc_area);
				fscanf(erch,"%d\n",&temporal.habilitado);
					if(temporal.habilitado==1){
						if(temporal.id_area==emp.id_area){
							correcto = 1;
						}
					}
				}
			}
			if(correcto!=1){
				printf("Area no valida,por favor vuele a elegir\n\n");
			}
		}while(correcto!=1);
		correcto=0;
	do{
		printf("Puesto: ");
		fflush(stdin);
		gets(emp.puesto);		
		}while(verificar(emp.puesto)!=1);
	do{
		
			do{
				printf("Usuario :");
				fflush(stdin);
				gets(emp.usuario);

			}while(verificar_direccion(emp.usuario)!=1);
			correcto=1;
			if(irch=fopen("Empleados.txt","r+")){
				while(feof(irch)){
					fscanf(irch,"%d*",&temporalDos.id_empleado);
			        fscanf(irch,"%[^*]*",&temporalDos.nombre);
			        fscanf(irch,"%[^*]*",&temporalDos.apellido_p);
			        fscanf(irch,"%[^*]*",&temporalDos.apellido_m);
			        fscanf(irch,"%d*",&temporalDos.day);
			        fscanf(irch,"%d*",&temporalDos.month);
			        fscanf(irch,"%d*",&temporalDos.year);
			        fscanf(irch,"%[^*]*",&temporalDos.sexo);
			        fscanf(irch,"%[^*]*",&temporalDos.direccion);
			        fscanf(irch,"%[^*]*",&temporalDos.telefono);
			        fscanf(irch,"%d*",&temporalDos.id_area);
			        fscanf(irch,"%[^*]*",&temporalDos.puesto);
			        fscanf(irch,"%[^*]*",&temporalDos.usuario);
			        fscanf(irch,"%[^*]*",&temporalDos.password);
			        fscanf(irch,"%d\n",&temporalDos.habilitado);
			        if(temporalDos.habilitado==1){
			        	if(strcmp(temporalDos.usuario,emp.usuario)==0){
			        		correcto=2;
			        	}
			        }
				}
			}
			
			if(correcto==2)
			printf("Este nombre de usuario ya esta en uso\n");
			
		}while(correcto!=1);
	do{
			printf("Password: ");
			fflush(stdin);
			gets(emp.password);
		}while(verificar_direccion(emp.password)!=1);

	if(arch = fopen("Empleados.txt","r+")){
		erch = fopen("EmpleadosTemp.txt","w");
		while(!feof(arch)){
			fscanf(arch,"%d*",&temporalDos.id_empleado);
	        fscanf(arch,"%[^*]*",temporalDos.nombre);
	        fscanf(arch,"%[^*]*",temporalDos.apellido_p);
	        fscanf(arch,"%[^*]*",temporalDos.apellido_m);
	        fscanf(arch,"%d*",&temporalDos.day);
	        fscanf(arch,"%d*",&temporalDos.month);
	        fscanf(arch,"%d*",&temporalDos.year);
	        fscanf(arch,"%[^*]*",temporalDos.sexo);
	        fscanf(arch,"%[^*]*",temporalDos.direccion);
	        fscanf(arch,"%[^*]*",temporalDos.telefono);
	        fscanf(arch,"%d*",&temporalDos.id_area);
	        fscanf(arch,"%[^*]*",temporalDos.puesto);
	        fscanf(arch,"%[^*]*",&temporalDos.usuario);
	        fscanf(arch,"%[^*]*",&temporalDos.password);
	        fscanf(arch,"%d\n",&temporalDos.habilitado);
			if(opcion==temporalDos.id_empleado){
	        	fprintf(erch,"%d*%s*%s*%s*%d*%d*%d*%s*%s*%s*%d*%s*%s*%s*%d\n",opcion,emp.nombre,emp.apellido_m,emp.apellido_p,emp.day,emp.month,emp.year,emp.sexo,emp.direccion,emp.telefono,emp.id_area,emp.puesto,emp.usuario,emp.password,1);
	        }else{
	        	fprintf(erch,"%d*%s*%s*%s*%d*%d*%d*%s*%s*%s*%d*%s*%s*%s*%d\n",temporalDos.id_empleado,temporalDos.nombre,temporalDos.apellido_m,temporalDos.apellido_p,temporalDos.day,temporalDos.month,temporalDos.year,temporalDos.sexo,temporalDos.direccion,temporalDos.telefono,temporalDos.id_area,temporalDos.puesto,temporalDos.usuario,temporalDos.password,temporalDos.habilitado);
	        }
		}
	}
	fclose(arch);
	fclose(erch);
		//DE REGRESO :D
	if(erch = fopen("EmpleadosTemp.txt","r+")){
		arch = fopen("Empleados.txt","w");
		while(!feof(erch)){
			fscanf(erch,"%d*",&temporalDos.id_empleado);
	        fscanf(erch,"%[^*]*",temporalDos.nombre);
	        fscanf(erch,"%[^*]*",temporalDos.apellido_p);
	        fscanf(erch,"%[^*]*",temporalDos.apellido_m);
	        fscanf(erch,"%d*",&temporalDos.day);
	        fscanf(erch,"%d*",&temporalDos.month);
	        fscanf(erch,"%d*",&temporalDos.year);
	        fscanf(erch,"%[^*]*",temporalDos.sexo);
	        fscanf(erch,"%[^*]*",temporalDos.direccion);
	        fscanf(erch,"%[^*]*",temporalDos.telefono);
	        fscanf(erch,"%d*",&temporalDos.id_area);
	        fscanf(erch,"%[^*]*",&temporalDos.puesto);
	        fscanf(erch,"%[^*]*",&temporalDos.usuario);
	        fscanf(erch,"%[^*]*",&temporalDos.password);
	        fscanf(erch,"%d\n",&temporalDos.habilitado);
	        	fprintf(arch,"%d*%s*%s*%s*%d*%d*%d*%s*%s*%s*%d*%s*%s*%s*%d\n",temporalDos.id_empleado,temporalDos.nombre,temporalDos.apellido_m,temporalDos.apellido_p,temporalDos.day,temporalDos.month,temporalDos.year,temporalDos.sexo,temporalDos.direccion,temporalDos.telefono,temporalDos.id_area,temporalDos.puesto,temporalDos.usuario,temporalDos.password,temporalDos.habilitado);
	    
		}
	}
	
	fclose(arch);
	fclose(erch);
	}else{
		printf("\tNo existe el archivo, primero  tienes que registrar a algun empleado\n");
	}
}


//MODIFICAR RECETA
void modificar_receta(FILE *arch){
	FILE *erch;
	receta emp,temporal;
	int opcion,ingrediente;
	float porciones;
	if(arch = fopen("Receta.txt","r+")){
	printf("Recetas\n");
	ver_receta(arch);
	printf("Elige mediante ID:");
	scanf("%d",&opcion);
	
	printf("\n***Modificacion de Recetas***\n\n");
	printf("Nombre de la receta: ");
    fflush(stdin);
    gets(emp.nombre);
          
	printf("Descripcion: ");
    fflush(stdin);
    gets(emp.descripcion);
    
	printf("Precio: ");
    fflush(stdin);
    scanf("%f",&emp.precio);
    
	printf("Habilitado: ");
    scanf("%d", &emp.habilitado);
    /*do{
    printf("Elige un ingrediente del inventario por ID\n");
    erch = fopen("Inventario.txt","r+");
        while(!feof(erch)){
         fscanf(erch,"%d",&temp.id_inventario);
         fscanf(erch,"%s",temp.nombre);
         fscanf(erch,"%f",&temp.peso);
         fscanf(erch,"%f",&temp.costo);
         fscanf(erch,"%f",&temp.cantidad);
         fscanf(erch,"%d",&temp.habilitado);
             if(temp.habilitado==0){ 
             printf("ID: %d\nNombre: %s\n\n",temp.id_inventario,temp.nombre);
             }
        }
        scanf("%d",&ingrediente);
        fflush(stdin);
    printf("Cuantas porciones?\n");
        fflush(stdin);
        scanf("%f",&porciones);
	*/
	if(arch = fopen("Receta.txt","r")){
		erch = fopen("RecetaTemp.txt","w");
		while(!feof(arch)){
			fscanf(arch,"%d*",&temporal.id_receta);
	        fscanf(arch,"%[^*]*",temporal.nombre);
	        fscanf(arch,"%[^*]*",temporal.descripcion);
	        fscanf(arch,"%f*",&temporal.precio);
	        fscanf(arch,"%d\n",&temporal.habilitado);
	        
			if(opcion==temporal.id_receta){
	        	fprintf(erch,"%d*%s*%s*%f*%d\n",opcion,emp.nombre,emp.descripcion,emp.precio,emp.habilitado);
	        }else{
	        	fprintf(erch,"%d*%s*%s*%f*%d\n",temporal.id_receta,temporal.nombre,temporal.descripcion,temporal.precio,temporal.habilitado);
	        }
		}
	}
	fclose(arch);
	fclose(erch);
		//DE REGRESO :D
	if(erch = fopen("RecetaTemp.txt","r")){
		arch = fopen("Receta.txt","w");
		while(!feof(erch)){
			fscanf(erch,"%d*",&temporal.id_receta);
	        fscanf(erch,"%[^*]*",temporal.nombre);
	        fscanf(erch,"%[^*]*",temporal.descripcion);
	        fscanf(erch,"%f*",&temporal.precio);
	        fscanf(erch,"%d\n",&temporal.habilitado);
	        
	        	fprintf(arch,"%d*%s*%s*%f*%d\n",temporal.id_receta,temporal.nombre,temporal.descripcion,temporal.precio,temporal.habilitado);
	    
		}
	}
	
	fclose(arch);
	fclose(erch);
	}else{
		printf("\tNo existe el archivo, primero  tienes que registrar alguna receta\n");
	}
}
//MODIFICAR ORDEN
void modificar_orden(FILE *arch){
	FILE *erch;
	orden ord,temporal;
	int opcion;
	if(arch = fopen("Orden.txt","r+")){
	printf("Ordenes\n");
	ver_orden(arch);
	printf("Elige mediante ID:");
	scanf("%d",&opcion);
	
	printf("\n***Modificacion de Ordenes***\n\n");
	printf("Fecha de la orden: ");
    fflush(stdin);
    do{ //validacion de dias, mes y a�o
          printf("Dia: ");
          scanf("%d", &ord.day);
            if(ord.day!=0 && ord.day>31)
                      	printf("\tDia Invalido\n");
          }while(ord.day!=0 && ord.day>32);
          do{
          printf("Mes: ");
          scanf("%d", &ord.month);
                      if(ord.month!=0 && ord.month>13)
                      	printf("\tMes Invalido\n");
          }while(ord.month!=0 && ord.month>13);
          printf("A\xA4o: ");
          scanf("%d", &ord.year);
	printf("Numero de mesa: ");
    scanf("%d", &ord.mesa);
	printf("Detalles: ");
    fflush(stdin);
    gets(ord.detalles);
    printf("Total: ");
          scanf("%f", &ord.total);
	printf("Habilitado 1. Si 0. No: ");
    scanf("%d", &ord.habilitado);
    
	if(arch = fopen("Orden.txt","r")){
		erch = fopen("OrdenTemp.txt","w");
		while(!feof(arch)){
			fscanf(arch,"%d*",&temporal.id_orden);
	        fscanf(arch,"%d*",&temporal.day);
	        fscanf(arch,"%d*",&temporal.month);
	        fscanf(arch,"%d*",&temporal.year);
	        fscanf(arch,"%d*",&temporal.mesa);
	        fscanf(arch,"%[^*]*",temporal.detalles);
	        fscanf(arch,"%f*",&temporal.total);
	        fscanf(arch,"%d\n",&temporal.habilitado);
	        
			if(opcion==temporal.id_orden){
	        	fprintf(erch,"%d*%d*%d*%d*%d*%s*%f*%d\n",opcion,ord.day,ord.month,ord.year,ord.mesa,ord.detalles,ord.total,ord.habilitado);
	        }else{
	        	fprintf(erch,"%d*%d*%d*%d*%d*%s*%f*%d\n",temporal.id_orden,temporal.day,temporal.month,temporal.year,temporal.mesa,temporal.detalles,temporal.total,temporal.habilitado);
	        }
		}
	}
	fclose(arch);
	fclose(erch);
		//DE REGRESO :D
	if(erch = fopen("OrdenTemp.txt","r")){
		arch = fopen("Orden.txt","w");
		while(!feof(erch)){
			fscanf(erch,"%d*",&temporal.id_orden);
	        fscanf(erch,"%d*",&temporal.day);
	        fscanf(erch,"%d*",&temporal.month);
	        fscanf(erch,"%d*",&temporal.year);
	        fscanf(erch,"%d*",&temporal.mesa);
	        fscanf(erch,"%[^*]*",temporal.detalles);
	        fscanf(erch,"%f*",&temporal.total);
	        fscanf(erch,"%d\n",&temporal.habilitado);
	        
	        	fprintf(arch,"%d*%d*%d*%d*%d*%s*%f*%d\n",temporal.id_orden,temporal.day,temporal.month,temporal.year,temporal.mesa,temporal.detalles,temporal.total,temporal.habilitado);
	    
		}
	}
	
	fclose(arch);
	fclose(erch);
	}else{
		printf("\tNo existe el archivo, primero  tienes que registrar alguna orden\n");
	}
}
//MODIFICAR INVENTARIO
void modificar_inventario(FILE *arch){
	FILE *erch;
	inventario inv,temporal;
	int opcion;
	if(arch = fopen("Inventario.txt","r+")){
	printf("Inventario\n");
	ver_inventario(arch);
	printf("Elige mediante ID:");
	scanf("%d",&opcion);
	
	printf("\n***Modificacion de Inventario***\n\n");
	printf("Nombre: ");
    fflush(stdin);
    gets(inv.nombre);
	printf("Peso: ");
    fflush(stdin);
    scanf("%f",&inv.peso);
    printf("Costo: ");
    scanf("%f", &inv.costo);
    printf("Cantidad: ");
    scanf("%f", &inv.cantidad);
	printf("Habilitado 1. Si 0. No: ");
    scanf("%d", &inv.habilitado);
    
	if(arch = fopen("Inventario.txt","r")){
		erch = fopen("InventarioTemp.txt","w");
		while(!feof(arch)){
			fscanf(arch,"%d*",&temporal.id_inventario);
	        fscanf(arch,"%[^*]*",temporal.nombre);
	        fscanf(arch,"%f*",&temporal.peso);
	        fscanf(arch,"%f*",&temporal.costo);
	        fscanf(arch,"%f*",&temporal.cantidad);
	        fscanf(arch,"%d\n",&temporal.habilitado);
	        
			if(opcion==temporal.id_inventario){
	        	fprintf(erch,"%d*%s*%f*%f*%f*%d\n",opcion,inv.nombre,inv.peso,inv.costo,inv.cantidad,inv.habilitado);
	        }else{
	        	fprintf(erch,"%d*%s*%f*%f*%f*%d\n",temporal.id_inventario,temporal.nombre,temporal.peso,temporal.costo,temporal.cantidad,temporal.habilitado);
	        }
		}
	}
	fclose(arch);
	fclose(erch);
		//DE REGRESO :D
	if(erch = fopen("InventarioTemp.txt","r")){
		arch = fopen("Inventario.txt","w");
		while(!feof(erch)){
			fscanf(erch,"%d*",&temporal.id_inventario);
	        fscanf(erch,"%[^*]*",temporal.nombre);
	        fscanf(erch,"%f*",&temporal.peso);
	        fscanf(erch,"%f*",&temporal.costo);
	        fscanf(erch,"%f*",&temporal.cantidad);
	        fscanf(erch,"%d\n",&temporal.habilitado);
	        
	        	fprintf(arch,"%d*%s*%f*%f*%f*%d\n",temporal.id_inventario,temporal.nombre,temporal.peso,temporal.costo,temporal.cantidad,temporal.habilitado);
	    
		}
	}
	
	fclose(arch);
	fclose(erch);
	}else{
		printf("\tNo existe el archivo, primero  tienes que registrar algun producto\n");
	}
}
//MODIFICAR AREA
void modificar_area(FILE *arch){
	FILE *erch;
	area ar,temporal;
	int opcion;
	if(arch = fopen("Area.txt","r+")){
	printf("Areas\n");
	ver_area(arch);
	printf("Elige mediante ID:");
	scanf("%d",&opcion);
	
	printf("\n***Modificacion de Area***\n\n");
	printf("Nombre: ");
    fflush(stdin);
    gets(ar.nombre);
	printf("Descripcion: ");
    fflush(stdin);
    gets(ar.desc_area);

    ar.habilitado=1;
    
	if(arch = fopen("Area.txt","r")){
		erch = fopen("AreaTemp.txt","w");
		while(!feof(arch)){
			fscanf(arch,"%d*",&temporal.id_area);
	        fscanf(arch,"%[^*]*",temporal.nombre);
	        fscanf(arch,"%[^*]*",temporal.desc_area);
	        fscanf(arch,"%d\n",&temporal.habilitado);
	        
			if(opcion==temporal.id_area){
	        	fprintf(erch,"%d*%s*%s*%d\n",opcion,ar.nombre,ar.desc_area,ar.habilitado);
	        }else{
	        	fprintf(erch,"%d*%s*%s*%d\n",temporal.id_area,temporal.nombre,temporal.desc_area,temporal.habilitado);
	        }
		}
	}
	fclose(arch);
	fclose(erch);
		//DE REGRESO :D
	if(erch = fopen("AreaTemp.txt","r")){
		arch = fopen("Area.txt","w");
		while(!feof(erch)){
			fscanf(erch,"%d*",&temporal.id_area);
	        fscanf(erch,"%[^*]*",temporal.nombre);
	        fscanf(erch,"%[^*]*",temporal.desc_area);
	        fscanf(erch,"%d\n",&temporal.habilitado);
	        
	        	fprintf(arch,"%d*%s*%s*%d\n",temporal.id_area,temporal.nombre,temporal.desc_area,temporal.habilitado);
	    
		}
	}
	
	fclose(arch);
	fclose(erch);
	}else{
		printf("\tNo existe el archivo, primero  tienes que registrar alguna area\n");
	}
}

//MENU PRINCIPAL
void menu_principal(FILE *arch,  int * sesion){
     int op, op2, continuar=2,cont;
     
  do{
  	system("cls");
     printf("\n\t**Menu Principal**\n\t");
     printf("1. Empleado\n\t2. Receta\n\t3. Orden\n\t4. Inventario\n\t5. Area\n\t6. Egresos\n\t7.-Salir\n\t Opcion:");//Opciones
     scanf("%d",&op);
     switch(op){
                case 1:
                     printf("\n\t**Menu Empleado**\n\t"); //men�s principales
                      printf("1. Registro de Empleado\n\t2. Ver Empleados\n\t3. Modificar Empleados \n\t4. Dar de Baja un Empleado\n\t5. Regresar al menu principal\n\tOpcion:");
                      scanf("%d",&op2);
                     switch(op2){
                                 case 1:
                                 	if((*sesion) !=1){
                                 		printf("Opcion deshabilitada para empleados\n");
                                 	}else{
                                      printf("\n\t**Agregar Empleado**\n\t");
                                      registro(arch);
                                    }
                                      break;
                                 case 2:
                                     printf("\n\t**Ver Empleados**\n\t");
                                        ver_empleado(arch);
                                     break;
                                 case 3:
                                 	if((*sesion) !=1){
                                 		printf("Opcion deshabilitada para empleados\n");
                                 	}else{	
                                      printf("\n\t**Modificar Empleado**\n\t");
                                      modificar_empleado(arch);
                                    }
                                      break;
                                 case 4:
                                 	if((*sesion) !=1){
                                 		printf("Opcion deshabilitada para empleados\n");
                                 	}else{		
                                    	printf("\n\t**Dar de Baja Empleado**\n\t");
                                    	baja_empleados(arch);
                                    }
                                      break;
                                case 5:
                                	cont=1;
                                	break;
                                 default:
                                      printf("\n\tNo existe esa opcion.\n\t");
                                      break;
                     }
                     break;
                case 2:
                     printf("\n\t**Menu Receta**\n\t");
                     printf("1. Registro de Receta\n\t2. Ver Recetas\n\t3. Modificar Recetas\n\t4. Dar de Baja una Receta\n\t5. Regresar al menu principal\n\tOpcion:");
                     scanf("%d",&op2);
                     switch(op2){
                                 case 1:
                                      printf("\n\t**Agregar Receta**\n\t");
                                      registro_receta(arch);
                                      break;
                                 case 2:
                                      printf("\n\t**Ver Receta**\n\t");
                                      ver_receta(arch);
                                      break;
                                 case 3:
                                      printf("\n\t**Modificar Receta**\n\t");
                                      modificar_receta(arch);
                                      break;
                                 case 4:
                                      printf("\n\t**Dar de Baja Receta**\n\t");
                                      baja_recetas(arch);
                                      break;
                                case 5:
                                	cont=1;
                                	break;
                                 default:
                                      printf("\n\tNo existe esa opcion.\n\t");
                                      break;
                     }
                     break;
                case 3:
                     printf("\n\t**Menu Orden**\n\t");
                     printf("1. Registro de Orden\n\t2. Ver Orden\n\t3. Modificar Orden\n\t4. Atender Orden\n\t5. Cobrar Orden\n\t6. Dar de Baja una Orden\n\t7. Regresar al menu principal\n\tOpcion:");
                     scanf("%d",&op2);
                     switch(op2){
                                 case 1:
                                      printf("\n\t**Agregar Orden**\n\t");
                                      registro_orden(arch);
                                      break;
                                 case 2:
                                 	system("pause");
                                      printf("\n\t**Ver Orden**\n\t");
                                      ver_orden(arch);
                                      break;
                                case 3:
                                      printf("\n\t**Modificar Orden**\n\t");
                                      modificar_orden(arch);
                                      break;
                                 case 4:
                                      printf("\n\t**Atender Orden (cocina)**\n\t");
                                      atender_orden(arch);
                                      break;
                            	case 5:
                            		printf("\n\t**Cobrar Orden (caja)**\n\t");
                            		//cobrar_orden(arch);
                            		break;
                                case 6:
                                		printf("\n\t**Dar de Baja Orden**\n\t");
                                	break;
                                case 7:
                                	cont=1;
                                	break;
                                 default:
                                      printf("\n\tNo existe esa opcion.\n\t");
                                      break;
                     }
                     break;
                case 4:
                     printf("\n\t**Menu Inventario**\n\t");
                     printf("1. Registrar un Producto \n\t2. Ver Inventario \n\t3.oModificar un Producto \n\t4. Dar de Baja un Product\n\t5. Regresar al menu principal\n\tOpcion:");
                     scanf("%d",&op2);
                     switch(op2){
                                 case 1:
                                      printf("\n\t**Agregar Producto en Inventario**\n\t");
                                      registro_inventario();
                                      break;
                                 case 2:
                             	  	  printf("\n\t**Ver Inventario**\n\t");
                                  	  ver_inventario(arch);
                                      break;
                                 case 3:
                                      printf("\n\t**Modificar Producto en Inventario**\n\t");
                                      modificar_inventario(arch);
                                      break;
                                case 4:
                                	  printf("\n\t**Dar de Baja Producto en Inventario**\n\t");
                                	   baja_inventario(arch);
                                	break;
                                case 5:
                                	cont=1;
                                	break;
                                 default:
                                      printf("\n\tNo existe esa opcion.\n\t");
                                      break;
                     }
                     break;
                case 5:
                     printf("\n\t**Menu Area**\n\t");
                     printf("1.Registrar un Area \n\t2.Ver Areas\n\t3.Modificar un Area\n\t4. Dar de Baja un Area\n\t5. Regresar al menu principal\n\tOpcion:");
                     scanf("%d",&op2);
                     switch(op2){
                                 case 1:
                                 	 if((*sesion) !=1){
                                 		printf("Opcion deshabilitada para empleados\n");
                                 	}else{
                                      printf("\n\t**Agregar Area**\n\t");
                                      registro_area();
                                     }
                                      break;
                                 case 2:
                                 	printf("\n\t**Ver Areas**\n\t");
                                 	ver_area(arch);
                                      break;
                                 case 3:
                                 	if((*sesion) !=1){
                                 		printf("Opcion deshabilitada para empleados\n");
                                 	}else{
                                      printf("\n\t**Modificar Area**\n\t");
                                      modificar_area(arch);
                                    }
                                      break;
                                case 4:
                                	 if((*sesion) !=1){
                                 		printf("Opcion deshabilitada para empleados\n");
                                 	}else{
                                      printf("\n\t**Dar de baja Area**\n\t");
                                      baja_area(arch);
                                    }
                                	break;
                                case 5:
                                	cont=1;
                                	break;
                                 default:
                                      printf("\n\tNo existe esa opcion.\n\t");
                                      break;
                     }
                     break;
                case 6:
                     printf("\n\t**Menu Egresos**\n\t");
                     if((*sesion) !=1){
                            printf("Opcion deshabilitada para empleados\n");
                   	}else{
                     	printf("1. Agregar\n\t2. Modificar\n\t3. Dar de Baja\n\t4. Regresar al menu principal\n\tOpcion:");
                     	scanf("%d",&op2);
                     	switch(op2){
                     	            case 1:
                     	                 break;
                     	            case 2:
                     	                 break;
                     	            case 3:
                     	                 break;
                     	            case 4:
                     	            	cont=1;
                     	            	break;
                     	            default:
                     	                 printf("\n\tNo existe esa opcion.\n\t");
                     	                 break;
                     	}
                    }
                break;
                case 7:
                	printf("\tADIOS\n");
                     break;
                default:
                        printf("\n\tNo existe esa opcion, vuelve a elegir\n");
                        system("pause");
                         menu_principal(&(*arch),&(*sesion));
                        break;
     }
	if(cont==1){
		continuar=1;
	}
    if(op!=7){
    	if(cont!=1){
	    	 do{
	    	 
				 printf("\t1.-Seguir\n\t2.-Salir\n");
		         fflush(stdin);
		         scanf("%d",&continuar);
		         if(continuar!=1&&continuar!=2){
		         	printf("Esta Opcion no es valida, vuelve a elegir\n");
		         }
    		}while(continuar!=1&&continuar!=2);
    	}else{
    		cont=0;
		}
    }
 }while(continuar==1&&op!=7);
  system("pause");
}
void menu_principal_emp(FILE *arch,  int * sesion){
     int op, op2, continuar;
  do{
     printf("\n\t**Menu Principal**\n\t");
     printf("1. Empleado\n\t2. Receta\n\t3. Orden\n\t4. Inventario\n\t5. Area\n\t6. Salir\n\t");//Opciones
     scanf("%d",&op);
     switch(op){
                case 1:
                     printf("\n\t**Menu Empleado**\n\t"); //men�s principales
                      printf("1. Ver\n\t");
                      scanf("%d",&op2);
                     switch(op2){
                                 case 1:
                                     printf("\n\t**Ver Empleados**\n\t");
                                        ver_empleado(arch);
                                     break;
                                 default:
                                      printf("\n\tNo existe esa opcion.\n\t");
                                      break;
                     }
                     break;
                case 2:
                     printf("\n\t**Menu Receta**\n\t");
                     printf("1. Registro de Receta\n\t2. Ver Recetas\n\t3. Modificar Recetas\n\t4. Dar de Baja una Receta\n\t");
                     scanf("%d",&op2);
                     switch(op2){
                                 case 1:
                                      printf("\n\t**Agregar Receta**\n\t");
                                      registro_receta(arch);
                                      break;
                                 case 2:
                                      printf("\n\t**Ver Receta**\n");
                                      ver_receta(arch);
                                      break;
                                 case 3:
                                      printf("\n\t**Modificar Receta**\n\t");
                                      modificar_receta(arch);
                                      break;
                                 case 4:
                                      printf("\n\t**Dar de Baja Receta**\n\t");
                                      baja_recetas(arch);
                                      break;
                                 default:
                                      printf("\n\tNo existe esa opcion.\n\t");
                                      break;
                     }
                     break;
                case 3:
                     printf("\n\t**Menu Orden**\n\t");
                     printf("1. Registro de Orden\n\t2. Ver Orden\n\t3. Modificar Orden\n\t4. Atender orden\n\t");
                     scanf("%d",&op2);
                     switch(op2){
                                 case 1:
                                      printf("\n\t**Agregar Orden**\n\t");
                                      registro_orden(arch);
                                      break;
                                 case 2:
                                 	system("pause");
                                      printf("\n\t**Ver Orden**\n\t");
                                      ver_orden(arch);
                                      break;
                                case 3:
                                      printf("\n\t**Modificar Orden**\n\t");
                                      modificar_orden(arch);
                                      break;
                                 case 4:
                                      printf("\n\t**Atender Orden (cocina)**\n\t");
                                      atender_orden(arch);
                                      break;
                                 default:
                                      printf("\n\tNo existe esa opcion.\n\t");
                                      break;
                     }
                     break;
                case 4:
                      printf("\n\t**Menu Inventario**\n\t");
                     printf("1. Registrar un Producto \n\t2. Ver Inventario \n\t3. Modificar un Producto \n\t4. Dar de Baja un Producto\n\t");
                     scanf("%d",&op2);
                     switch(op2){
                                 case 1:
                                      printf("\n\t**Agregar Producto en Inventario**\n\t");
                                      registro_inventario();
                                      break;
                                 case 2:
                             	  	  printf("\n\t**Ver Inventario**\n\t");
                                  	  ver_inventario(arch);
                                      break;
                                 case 3:
                                      printf("\n\t**Modificar Producto en Inventario**\n\t");
                                      modificar_inventario(arch);
                                      break;
                                case 4:
                                	  printf("\n\t**Dar de Baja Producto en Inventario**\n\t");
                                	   baja_inventario(arch);
                                	break;
                                 default:
                                      printf("\n\tNo existe esa opcion.\n\t");
                                      break;
                     }
                     break;
                case 5:
                     printf("\n\t**Menu Area**\n\t");
                     printf("1. Ver Areas\n\tElige una Opcion: ");
                     scanf("%d",&op2);
                     switch(op2){
                                 case 1:
                                 	printf("\n\t**Ver Areas**\n\t");
                                 	ver_area(arch);
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

     if(op!=7){
    	 printf("\t1.-Seguir\n\t2.-Salir\n");
         fflush(stdin);
        scanf("%d",&continuar);
    }
 }while(continuar==1&&op!=7);
  system("pause");
}
// INICIO DE SESION
void inicio_sesion(FILE *arch, FILE *erch, int * sesion){
     char usuariopredf[20]="admin"; //usuario predeteriminado
     char passpredf[20]="admin123"; //contrase�a predeterminada
     char usuarioadmin[20],passadmin[20],usuarioemp[20], passemp[20],emp[20], pswe[20],adm[20],pw[20],hola[10]="hola";
     int tipo;
     char * n;
     empleado temporalDos;
     
     printf("Elegir tipo de usuario:\n1.-Administrador.\n2.-Empleado.\n"); //opcion para entrar Administrador o Usuario
     fflush(stdin);
	 scanf("%d",&tipo);
     if(tipo==1){       //si es administrador
        arch=fopen("Admin.txt","r+");  //abre el archivo de Administrador
         if(arch==NULL){   //si el archivo esta vacio significa que entra por primera vez y se le da un nombre y contrase�a predeterminadas
             fflush(stdin);
             printf("Entraste por primera vez!\n");
             printf("Tu usuario es: %s\n",usuariopredf);
             printf("Tu contrase%ca es: %s\n",164,passpredf);
            arch = fopen("Admin.txt","w+");
            fprintf(arch,"%s %s",usuariopredf,passpredf);
            fclose(arch);
            *sesion = 1;  //puntero que indica que tipo de persona es, Administrador o Usuario
            system("pause");
            printf("Bienvenido!!\n");
            menu_principal(arch,&(*sesion));
         }else{
            do{ 
				*sesion = 1;  //si no se entra por primera vez  se le pide que se registre
                printf("Ingresa tu usuario: ");
                fflush(stdin);
                gets(usuarioadmin);
                printf("Ingresa tu contrase%ca: ",164);
                fflush(stdin);
                gets(passadmin);
                if(arch==NULL){
                    printf("Error! \n");
                    system("pause");
                    inicio_sesion(arch,erch,&(*sesion)); //si el archivo esta vacio regresa a la funcion inicio_sesion
                }else{
                    fscanf(arch,"%s",adm);
                    fscanf(arch,"%s",pw);
                }
                if((strcmp(usuarioadmin,adm)!=0)||(strcmp(passadmin,pw)!=0)){
                    printf("Usuario y/o Contrase%ca Incorrectos\n\n",164);
                }
            }while((strcmp(usuarioadmin,adm)!=0)||(strcmp(passadmin,pw)!=0));
            printf("Bienvenido!!\n");
            menu_principal(arch,&(*sesion));
       }

     }else{
     	
	  	if(tipo==2){ //usuario tipo 2 es empleado
			if(erch=fopen("Empleados.txt","r+")){  //abre el archivo de Administrador
	         	if(arch==NULL){   //si el archivo esta vacio significa que entra por primera vez y se le da un nombre y contrase�a predeterminadas
	            	 fflush(stdin);
	             	printf("Los empleados aun no estan autorizados para entrar\n");
	            	*sesion = 2;  //puntero que indica que tipo de persona es, Administrador o Usuario
	         	}else{
	            	do{ 
						*sesion = 2;   //si no se entra por primera vez  se le pide que se registre
	                	do{
						printf("Ingresa tu usuario: ");
	                	fflush(stdin);
	                	gets(usuarioemp);
	                	}while(verificar(usuarioemp)!=1);
						
						do{
						printf("Ingresa tu contrase%ca: ",164);
	                	fflush(stdin);
	                	gets(passemp);
	                	}while(verificar_direccion(passemp)!=1);
						while(!feof(erch)){
							fscanf(erch,"%d*",&temporalDos.id_empleado);
					        fscanf(erch,"%[^*]*",temporalDos.nombre);
					        fscanf(erch,"%[^*]*",temporalDos.apellido_p);
					        fscanf(erch,"%[^*]*",temporalDos.apellido_m);
					        fscanf(erch,"%d*",&temporalDos.day);
					        fscanf(erch,"%d*",&temporalDos.month);
					        fscanf(erch,"%d*",&temporalDos.year);
					        fscanf(erch,"%[^*]*",temporalDos.sexo);
					        fscanf(erch,"%[^*]*",temporalDos.direccion);
					        fscanf(erch,"%[^*]*",temporalDos.telefono);
					        fscanf(erch,"%d*",&temporalDos.id_area);
					        fscanf(erch,"%[^*]*",&temporalDos.puesto);
					        fscanf(erch,"%[^*]*",&temporalDos.usuario);
							fscanf(erch,"%[^*]*",&temporalDos.password);
					        fscanf(erch,"%d\n",&temporalDos.habilitado);
	                	}
	                	if((strcmp(usuarioemp,temporalDos.usuario)!=0)||(strcmp(passemp,temporalDos.password)!=0)){
	                    	printf("Usuario y/o Contrasena Incorrectos\n\n");
	                	}	
	        		}while((strcmp(usuarioemp,temporalDos.usuario)!=0)||(strcmp(passemp,temporalDos.password)!=0));
	        			printf("Bienvenido!!\n");
	        		 menu_principal_emp(arch,&(*sesion));	
	     		}
			}else{
				printf("Primero tienes que agregar usuarios como Administrador");
			}
		 }else{
		printf("Error! \nIntenta otra opcion\n");
		system("pause");
		system("cls");
       inicio_sesion(arch,erch,&(*sesion));
        }
    }
}
