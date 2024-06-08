#include<stdio.h>
/*
 Programa que realiza la implementación de la escitala espartana
 Para cifrar y descifrar.
*/

//En esta parte del codigo se realiza la declaracion de funciones
void crearMensaje(); //declaracion de la funcion crear mensaje
void descifrarMensaje(); //declaracion de la funcion descifrar mensaje

int main(){
	short opcion=0; //declaracion e inicializacion de la variable opcion
	while (1){ //inicio del ciclo while(al poner cualquier numero se crea un bucle infinito)
		printf("\n\t*** ESCITALA ESPARTANA ***\n"); //Muestra el nombre del programa
		printf("¿Que desea realizar?\n"); //Muestra la pregunta sobre lo que quiere realizar el usuario
		printf("1) Crear mensaje cifrado.\n");//muestra la primer opcion
		printf("2) Descifrar mensaje.\n");//muestra la segunda opcion
		printf("3) Salir.\n");//muestra la tercera opcion
		scanf("%d", &opcion);//escanea la opcion que selecciona el usuario
		switch(opcion){ //inicia el condicional switch para el menu
			case 1: //Inicio del caso 1
		 		crearMensaje();//Manda a llamar a la funcion crear mensaje
		 	break;//finaliza el caso 1
			case 2://Inicio del caso 2
				descifrarMensaje();//Manda a llamar a la funcion descifrar mensaje
		 	break;//finaliza el caso 2
		 	case 3://Inicio del caso 3
				return 0;//mediante esta linea finaliza el programa
			default://Manda a la opcion por defecto en caso de que se ingrese algo no valido
				printf("Opción no valida.\n");//muestra el mensaje de opcion no valida
		}
	}
	return 0;//mediante esta linea finaliza el programa
}
void crearMensaje(){ //en esta linea da inicio la funcion crear mensaje
	int ren, col, i, j, k=0; //Declaracion de variables
	printf("Ingresar el tamanio de la escitala:\n"); //Muestra un mensaje para el tamaño de la escitala
	printf("\nRenglones:");//Muestra un mensaje para el numero de renglones
	scanf("%i",&ren);//escanea el numero de renglones
	printf("\nColumnas:");//Muestra un mensaje para el numero de columnas
	scanf("%i",&col);//escanea el numero de columnas
	char escitala[ren][col]; //crea un arreglo bidimensional de tipo char con el numero de renglones y columnas
	char texto[ren*col]; //crea un arreglo unidimensional de tipo char con el tamaño de los renglones por las columnas
	printf("Escriba el texto a cifrar:\n"); //muestra un mensaje para preguntar el texto a cifrar
	scanf("%s", texto);//lee el texto a cifrar
	for (i=0 ; i<ren ; i++)//inicia un ciclo for para recorrer el arreglo
		for (j=0 ; j<col ; j++)//inicia un ciclo for para recorrer el arreglo
			escitala[i][j] = texto[k++];//asigna lo que esta en texto al array escitala
		
	printf("El texto en la tira queda de la siguiente manera:\n");//muestra un mensaje de como queda el texto en pantalla
	for (i=0 ; i<col ; i++)//inicia un ciclo for para recorrer el arreglo
		for (j=0 ; j<ren ; j++)//inicia un ciclo for para recorrer el arreglo
			printf("%c", escitala[j][i]);//imprime como se veria el texto encriptado
	
	printf("\n");//imprime un salto de linea
}
void descifrarMensaje(){//inicia la funcion descifrarMensaje
	int ren, col, i, j, k=0;//declalaracion de las variables
	printf("Ingresar el tamanio de la escitala:\n");//muestra un mensaje para preguntar el tamaño de la escitala
	printf("\nRenglones:");//pregunta el numero de renglones
	scanf("%i",&ren);//escanea y almacena el numero de renglones
	printf("\nColumnas:");//pregunta el numero de columnas
	scanf("%i",&col);//escanea y almacena el numero de columnas
	
	char escitala[ren][col];//declara un arreglo para la escitala de tipo caracter
	char texto[ren*col];//declara un arreglo para el texto de tipo caracter
	
	printf("Escriba el texto a descifrar:\n");//muestra un mensaje donde pide el texto para descifrar
	scanf("%s", texto);//lee el texto a descifrar
	
	for (i=0 ; i<col ; i++)//inicia un ciclo for para recorrer el arreglo
		for (j=0 ; j<ren ; j++)//inicia un ciclo for para recorrer el arreglo
			escitala[j][i] = texto[k++];//asigna lo que esta en el array texto al array escitala
		
	printf("El texto descifrado es:\n");
	for (i=0 ; i<ren ; i++)//inicia un ciclo for para recorrer el arreglo
		for (j=0 ; j<col ; j++)//inicia un ciclo for para recorrer el arreglo
			printf("%c", escitala[i][j]);//imprime como se veria el texto desencriptado
}
