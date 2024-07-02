#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Función para generar un número aleatorio en un rango dado
int generarNumeroAleatorio(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Función para generar una matriz aleatoria
void generarMatrizAleatoria(int filas, int columnas, int min, int max, int matriz[filas][columnas]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = generarNumeroAleatorio(min, max);
        }
    }
}

// Función para imprimir la matriz con un título
void imprimirMatrizConTitulo(int filas, int columnas, int matriz[filas][columnas], const char* titulo) {
    printf("%s:\n", titulo);
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Función para restar dos matrices y guardar el resultado en una tercera matriz
void restarMatrices(int filas, int columnas, int matriz1[filas][columnas], int matriz2[filas][columnas], int resultado[filas][columnas]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            resultado[i][j] = matriz1[i][j] - matriz2[i][j];
        }
    }
}

int main() {
    // Semilla para los números aleatorios
    srand(time(NULL));

    int filas, columnas, min, max;

    // Solicitar al usuario las dimensiones de la matriz
    printf("Introduce el número de filas: ");
    scanf("%d", &filas);
    printf("Introduce el número de columnas: ");
    scanf("%d", &columnas);

    // Repetir hasta que el valor mínimo sea menor o igual al valor máximo
    do {
        printf("Introduce el valor mínimo: ");
        scanf("%d", &min);
        printf("Introduce el valor máximo: ");
        scanf("%d", &max);

        if (min > max) {
            printf("El valor mínimo debe ser menor o igual al valor máximo. Inténtalo de nuevo.\n");
        }
    } while (min > max);

    // Declarar las matrices
    int matriz1[filas][columnas];
    int matriz2[filas][columnas];
    int matrizResultado[filas][columnas];

    // Generar las matrices aleatorias
    generarMatrizAleatoria(filas, columnas, min, max, matriz1);
    generarMatrizAleatoria(filas, columnas, min, max, matriz2);

    // Imprimir las matrices generadas
    imprimirMatrizConTitulo(filas, columnas, matriz1, "Primera Matriz");
    imprimirMatrizConTitulo(filas, columnas, matriz2, "Segunda Matriz");

    // Restar las matrices
    restarMatrices(filas, columnas, matriz1, matriz2, matrizResultado);

    // Imprimir la matriz resultante
    imprimirMatrizConTitulo(filas, columnas, matrizResultado, "Matriz Resultante (Resta)");

    return 0;
}