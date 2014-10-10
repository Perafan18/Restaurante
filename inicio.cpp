#include <stdio.h>
typedef struct{
	int day;
	int month;
	int year;
	char hola[20];
	float precio;
}fecha;

int main(){
	int opc;
    char nava[30] = "Hola ._. , no veas nada de lo de sensualona\n";
printf("Hola %s!\n",nava);
opc=menu();
return 0;
}

void menu(){
	int opc;
	printf("Holi elige opcion\n\n1.-Holi\n\nHoli2\n");
	scanf("%d",opc);
}
