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

// Función para multiplicar dos matrices y guardar el resultado en una tercera matriz
void multiplicarMatrices(int filas1, int columnas1, int columnas2,
                         int matriz1[filas1][columnas1], int matriz2[columnas1][columnas2],
                         int resultado[filas1][columnas2]) {
    for (int i = 0; i < filas1; i++) {
        for (int j = 0; j < columnas2; j++) {
            resultado[i][j] = 0;
            for (int k = 0; k < columnas1; k++) {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }
}

int main() {
    // Semilla para los números aleatorios
    srand(time(NULL));

    int filas1, columnas1, filas2, columnas2, min, max;

    // Solicitar al usuario las dimensiones de la primera matriz
    printf("Introduce el número de filas de la primera matriz: ");
    scanf("%d", &filas1);
    printf("Introduce el número de columnas de la primera matriz: ");
    scanf("%d", &columnas1);

    // Solicitar al usuario las dimensiones de la segunda matriz
    printf("Introduce el número de filas de la segunda matriz: ");
    scanf("%d", &filas2);
    printf("Introduce el número de columnas de la segunda matriz: ");
    scanf("%d", &columnas2);

    // Validar que las dimensiones sean compatibles para la multiplicación
    if (columnas1 != filas2) {
        printf("No se pueden multiplicar las matrices. El número de columnas de la primera matriz debe ser igual al número de filas de la segunda matriz.\n");
        return 1;
    }

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
    int matriz1[filas1][columnas1];
    int matriz2[columnas1][columnas2];
    int matrizResultado[filas1][columnas2];

    // Generar las matrices aleatorias
    generarMatrizAleatoria(filas1, columnas1, min, max, matriz1);
    generarMatrizAleatoria(columnas1, columnas2, min, max, matriz2);

    // Imprimir las matrices generadas
    imprimirMatrizConTitulo(filas1, columnas1, matriz1, "Primera Matriz");
    imprimirMatrizConTitulo(columnas1, columnas2, matriz2, "Segunda Matriz");

    // Multiplicar las matrices
    multiplicarMatrices(filas1, columnas1, columnas2, matriz1, matriz2, matrizResultado);

    // Imprimir la matriz resultante
    imprimirMatrizConTitulo(filas1, columnas2, matrizResultado, "Matriz Resultante (Multiplicación)");

    return 0;
}
