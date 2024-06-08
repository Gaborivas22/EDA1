#include <stdio.h>
#include <stdlib.h>

#define p printf
#define s scanf

// Función para leer la matriz de un archivo
void leerMatriz(int filas, int columnas, int matriz[][columnas], char nombreArchivo[]) {
  FILE *archivo;
  int i, j;

  // Abrir el archivo en modo lectura
  archivo = fopen(nombreArchivo, "r");
  if (archivo == NULL) {
    printf("Error al abrir el archivo %s\n", nombreArchivo);
    exit(1);
  }

  // Leer los elementos de la matriz
  for (i = 0; i < filas; i++) {
    for (j = 0; j < columnas; j++) {
      fscanf(archivo, "%d ", &matriz[i][j]);
    }
  }

  // Cerrar el archivo
  fclose(archivo);
}

// Función para imprimir la matriz
void imprimirMatriz(int filas, int columnas, int matriz[][columnas]) {
  int i, j;

  for (i = 0; i < filas; i++) {
    for (j = 0; j < columnas; j++) {
      p("%d ", matriz[i][j]);
    }
    printf("\n");
  }
}

// Función para obtener la transpuesta de la matriz
void calcularTranspuesta(int filas, int columnas, int matriz[][columnas], int matrizTranspuesta[][filas]) {
  int i, j;

  for (i = 0; i < filas; i++) {
    for (j = 0; j < columnas; j++) {
      matrizTranspuesta[j][i] = matriz[i][j];
    }
  }
}

// Función para multiplicar las matrices
void multiplicarMatrices(int filasA, int columnasA, int matrizA[][columnasA], int filasB, int columnasB, int matrizB[][columnasB], int matrizC[][columnasB]) {
  int i, j, k;

  if (columnasA != filasB) {
    printf("Las matrices no se pueden multiplicar porque el número de columnas de la primera matriz no es igual al número de filas de la segunda matriz.\n");
    return;
  }

  for (i = 0; i < filasA; i++) {
    for (j = 0; j < columnasB; j++) {
      matrizC[i][j] = 0;
      for (k = 0; k < columnasA; k++) {
        matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
      }
    }
  }
}

int main() {
  int filas, columnas;
  int matriz[100][100], matrizT[100][100],matrizR[100][100];
  const char *nombreArchivo="matriz.txt";


  // Leer el número de filas y columnas de la matriz
  p("Ingrese el numero de filas de la matriz: ");
  s("%d", &filas);
  p("Ingrese el numero de columnas de la matriz: ");
  s("%d", &columnas);

  // Leer la matriz del archivo
  leerMatriz(filas, columnas, matriz, nombreArchivo);

  // Mostrar la matriz leída
  p("Matriz leida:\n");
  imprimirMatriz(filas, columnas, matriz);
  
  // Muestra la matriz transpuesta
  p("Matriz transpuesta:\n");
  calcularTranspuesta(filas, columnas, matriz, matrizT);
  imprimirMatriz(columnas, filas, matrizT);
  
  // Muestra la matriz multiplicada
  p("Matriz Multiplicada:\n");
  multiplicarMatrices(filas, columnas, matriz, columnas, filas, matrizT, matrizR);
  imprimirMatriz(filas, filas, matrizR);
  
  // Muestra la matriz transpuesta de la multiplicada
  p("Matriz Multiplicada transpuesta:\n");
  calcularTranspuesta(filas, filas, matriz, matrizT);
  imprimirMatriz(filas, filas, matrizR);
  

  return 0;
}
