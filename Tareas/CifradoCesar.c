#include <stdio.h>

/*
Programa que realiza la implementación del cifrado César
*/

#define TAM_PALABRA 20 //define el tamaño de las palabras
#define TAM_ABC 26 //define el tamaño del Abecedario

char abecedarioEnClaro[TAM_ABC] =
    {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
     'U', 'V', 'W', 'X', 'Y', 'Z'}; //Crea un arreglo con todas las letras del abecedario

char abecedarioCifrado[TAM_ABC] =
    {'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
     'X', 'Y', 'Z', 'A', 'B', 'C'};//Crea un arreglo con todas las letras del abecedario cifradas

void cifrar(char *textoEnClaro);//declaracion de la funcion cifrar
void descifrar(char *textoCifrado);//declaracion de la funcion descifrar 

int main()
{
    short opcion = 0, contador; //creacion de las variables opcion y contador de tipo short
    char palabra[TAM_PALABRA]; //creacion del arreglo palabra

    while (1)//inicio del ciclo while para las opciones
    {
        printf("\n\t*** CIFRADO CESAR ***\n");//muestra el titulo del programa

        for (contador = 0; contador < 26; contador++)//inicia un ciclo for para mostrar cada letra del abecedario
            printf("%c", abecedarioEnClaro[contador]);//imprime cada letra del abecedario

        printf("\n");//imprime un salto de linea

        for (contador = 0; contador < 26; contador++)//inicia un ciclo for para mostrar cada letra del abecedario cifrado
            printf("%c", abecedarioCifrado[contador]);//imprime cada letra del abecedario cifrado

        printf("\nElegir una opcion:\n");//imprime el inicio del menu
        printf("1) Cifrar\n");//imprime la opcion cifrar
        printf("2) Descifrar.\n");//imprime la opcion descifrar
        printf("3) Salir.\n");//imprime el mensaje salir
        scanf("%d", &opcion);//lee lo que el usuario ponga en el teclado

        switch (opcion){//Inicia un condicional para la opcion elegida en el menu
        case 1://inicio del caso 1
            printf("Ingresar la palabra a cifrar (en mayúsculas): ");//imprime un mensaje para la palabra a cifrar
            scanf("%s", palabra);//lee lo que el usuario ponga en el teclado y lo almacena en palabra
            cifrar(palabra);//manda a llamar la funcion cifrar para cifrar la palabra
            break;//finaliza el caso 1
        case 2://inicio del caso 2
            printf("Ingresar la palabra a descifrar (en mayúsculas): ");//imprime un mensaje para la palabra a descifrar
            scanf("%s", palabra);//lee lo que el usuario ponga en el teclado y lo almacena en palabra
            descifrar(palabra);//manda a llamar la funcion descifrar para descifrar la palabra
            break;//finaliza el caso 2
        case 3://inicio del caso 3
            return 0;//finaliza el programa
        default://inicio del caso default
            printf("Opción no válida.");//muestra un mensaje de opcion no valida
        }
    }

    return 0;//finaliza el programa
}

void cifrar(char *textoEnClaro)//inicia la funcion cifrar pasando como argumento el texto en claro
{
    printf("El texto %s cifrado es: ", textoEnClaro);//muestra un mensaje para el texto cifrado
    int contadorAbcedario, contadorPalabra, indice = 0;//declaracion e inicializacion de variables

    for (contadorPalabra = 0; contadorPalabra < textoEnClaro[contadorPalabra]; contadorPalabra++)//inicio del ciclo for para recorrer contador palabra
    {
        for (contadorAbcedario = 0; contadorAbcedario < TAM_ABC; contadorAbcedario++)//inicio del ciclo for para recorrer contador abecedario
        {
            if (abecedarioEnClaro[contadorAbcedario] == textoEnClaro[contadorPalabra])//verifica que se cumpla cierta condicion
            {
                printf("%c", abecedarioCifrado[contadorAbcedario]);//imprime la nueva letra cifrada
                contadorAbcedario = 26;//iguala la variable contadorAbecedario a 26
            }
        }
    }

    printf("\n");//imprime un salto de linea
}

void descifrar(char *textoCifrado)//inicia la funcion descifrar pasando como argumento el texto cifrado
{
    printf("El texto %s descifrado es: ", textoCifrado);//muestra un mensaje para el texto descifrado
    int contadorAbcedario, contadorPalabra, indice = 0;//declaracion e inicializacion de variables

    for (contadorPalabra = 0; contadorPalabra < textoCifrado[contadorPalabra]; contadorPalabra++)//inicio del ciclo for para recorrer contador palabra
    {
        for (contadorAbcedario = 0; contadorAbcedario < TAM_ABC; contadorAbcedario++)//inicio del ciclo for para recorrer contador abecedario
        {
            if (abecedarioCifrado[contadorAbcedario] == textoCifrado[contadorPalabra])//verifica que se cumpla cierta condicion
            {
                printf("%c", abecedarioEnClaro[contadorAbcedario]);//imprime la letra descifrada
                contadorAbcedario = 26;//iguala la variable contadorAbecedario a 26
            }
        }
    }

}

