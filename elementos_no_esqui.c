#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Función para generar un número aleatorio en un rango dado
int generarNumeroAleatorio(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Función para generar una matriz aleatoria cuadrada
void generarMatrizAleatoria(int lado, int min, int max, int matriz[lado][lado]) {
    for (int i = 0; i < lado; i++) {
        for (int j = 0; j < lado; j++) {
            matriz[i][j] = generarNumeroAleatorio(min, max);
        }
    }
}

// Función para imprimir la matriz con espacios en las esquinas
void imprimirMatrizNoEsquineros(int lado, int matriz[lado][lado]) {
    printf("Elementos no esquineros de la matriz:\n");
    for (int i = 0; i < lado; i++) {
        for (int j = 0; j < lado; j++) {
            // Verificar si estamos en las esquinas
            if ((i == 0 && (j == 0 || j == lado - 1)) || (i == lado - 1 && (j == 0 || j == lado - 1))) {
                printf(" \t"); // Imprimir espacio en blanco en las esquinas
            } else if (i == 0 || i == lado - 1 || j == 0 || j == lado - 1) {
                // Imprimir los bordes no esquineros
                printf("%d\t", matriz[i][j]);
            } else {
                // Imprimir los elementos no esquineros
                printf("%d\t", matriz[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    // Semilla para los números aleatorios
    srand(time(NULL));

    int lado, min, max;

    // Solicitar al usuario el tamaño de la matriz (lado x lado)
    printf("Introduce el tamaño de la matriz (lado): ");
    scanf("%d", &lado);

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

    // Declarar la matriz cuadrada
    int matriz[lado][lado];

    // Generar e imprimir la matriz aleatoria
    generarMatrizAleatoria(lado, min, max, matriz);
    printf("\nMatriz aleatoria generada:\n");
    for (int i = 0; i < lado; i++) {
        for (int j = 0; j < lado; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }

    // Imprimir los elementos no esquineros con espacios en las esquinas
    imprimirMatrizNoEsquineros(lado, matriz);

    return 0;
}

