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

// Función para imprimir la matriz
void imprimirMatriz(int filas, int columnas, int matriz[filas][columnas]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

// Función para calcular la matriz transpuesta
void calcularMatrizTranspuesta(int filas, int columnas, int matriz[filas][columnas], int transpuesta[columnas][filas]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            transpuesta[j][i] = matriz[i][j];
        }
    }
}

// Función para imprimir la matriz transpuesta
void imprimirMatrizTranspuesta(int filas, int columnas, int matriz[columnas][filas]) {
    printf("Matriz transpuesta:\n");
    for (int i = 0; i < columnas; i++) {
        for (int j = 0; j < filas; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
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

    // Declarar la matriz
    int matriz[filas][columnas];
    int matrizTranspuesta[columnas][filas];

    // Generar e imprimir la matriz aleatoria
    generarMatrizAleatoria(filas, columnas, min, max, matriz);
    printf("Matriz aleatoria generada:\n");
    imprimirMatriz(filas, columnas, matriz);

    // Calcular la matriz transpuesta
    calcularMatrizTranspuesta(filas, columnas, matriz, matrizTranspuesta);

    // Imprimir la matriz transpuesta
    imprimirMatrizTranspuesta(filas, columnas, matrizTranspuesta);

    return 0;
}
