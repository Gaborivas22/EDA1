#include <stdio.h>
#include<stdbool.h>

#define maxN 10
#define p printf
#define s scanf

int i,j;
bool suma = false, resta = false, transpuesta=false, escalar=false;


void ingresarMatriz(float matriz[maxN][maxN], int n) {
    p("Ingrese los valores de la matriz (%dx%d):\n", n, n);
    for (i = 0; i < n; ++i) {
        for ( j = 0; j < n; ++j) {
            s("%f", &matriz[i][j]);
        }
    }
}

void mostrarMatriz(float matriz[maxN][maxN], int n) {
    p("Matriz resultante:\n");
    for ( i = 0; i < n; ++i) {
        for ( j = 0; j < n; ++j) {
            p("%.2f\t", matriz[i][j]);
        }
        p("\n");
    }
}

void sumarMatrices(float matriz1[maxN][maxN], float matriz2[maxN][maxN], float resultado[maxN][maxN], int n) {
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            resultado[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }
    suma = true;
}

void restarMatrices(float matriz1[maxN][maxN], float matriz2[maxN][maxN], float resultado[maxN][maxN], int n) {
    for ( i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            resultado[i][j] = matriz1[i][j] - matriz2[i][j];
        }
    }
    resta = true;
}

void transponerMatriz(float matriz[maxN][maxN], float resultado[maxN][maxN], int n) {
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            resultado[i][j] = matriz[j][i];
        }
    }
    transpuesta = true;
}

void multiplicarPorEscalar(float matriz[maxN][maxN], float resultado[maxN][maxN], int n, float escalar) {
    for ( i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            resultado[i][j] = matriz[i][j] * escalar;
        }
    }
    escalar = true;
}

void guardarEnArchivo(float matriz[maxN][maxN], int n, const char* nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "w");
    if (archivo == NULL) {
        p("Error al abrir el archivo %s\n", nombreArchivo);
        exit(1);
    }

    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            fprintf(archivo, "%.2f ", matriz[i][j]);
        }
        fprintf(archivo, "\n");
    }

    fclose(archivo);
}

void verArchivos() {
	if(suma || resta || transpuesta ||escalar){
		p("\nLos archivos creados son los siguientes:\n");
	    if(suma)
	    	p("suma.txt\n");
	    if(resta)
	    	p("resta.txt\n");
	    if(transpuesta)
	    	p("transpuesta.txt\n");
	    if(escalar)
	    	p("escalar.txt\n");
	}
	else{
		p("\nAun no haz creado archivos \n");
	}
}

int main() {
    int n;
    float matriz1[maxN][maxN], matriz2[maxN][maxN], resultado[maxN][maxN], escalar;

    p("Ingrese el tamanio de las matrices (N): ");
    s("%d", &n);

    ingresarMatriz(matriz1, n);
    ingresarMatriz(matriz2, n);

    char opcion;
    do {
        p("\nMenu Matrices:\n");
        p("a) Suma de Matrices\n");
        p("b) Resta de Matrices\n");
        p("c) Transpuesta de Matrices\n");
        p("d) Multiplicacion por un escalar\n");
        p("e) Ver Archivos\n");
        p("f) Salir\n");

        p("Seleccione una opcion (a-f): ");
        s(" %c", &opcion);

        switch (opcion) {
            case 'a':
                sumarMatrices(matriz1, matriz2, resultado, n);
                guardarEnArchivo(resultado, n, "suma.txt");
                mostrarMatriz(resultado, n);
                break;
            case 'b':
                restarMatrices(matriz1, matriz2, resultado, n);
                guardarEnArchivo(resultado, n, "resta.txt");
                mostrarMatriz(resultado, n);
                break;
            case 'c':
                transponerMatriz(matriz1, resultado, n);
                guardarEnArchivo(resultado, n, "transpuesta.txt");
                mostrarMatriz(resultado, n);
                break;
            case 'd':
                p("Ingrese el escalar: ");
                s("%f", &escalar);
                multiplicarPorEscalar(matriz1, resultado, n, escalar);
                guardarEnArchivo(resultado, n, "multiplicacion_escalar.txt");
                mostrarMatriz(resultado, n);
                break;
            case 'e':
                verArchivos();
                break;
            case 'f':
                p("Saliendo del programa, AYOOOOS:D \n");
                break;
            default:
                p("Opción no válida. Intente nuevamente.\n");
        }
    } while (opcion != 'f');

    return 0;
}

