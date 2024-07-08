#include <stdio.h>
#include <stdbool.h>

// Función para verificar si un número ya está en el arreglo
bool numeroRepetido(int numeros[], int num, int size) {
    for (int i = 0; i < size; i++) {
        if (numeros[i] == num) {
            return true;
        }
    }
    return false;
}

// Función para leer un número válido entre 1 y 13
int leerNumeroValido(int numeros[], int size) {
    int num;
    do {
        printf("Ingresa un número del 1 al 13 sin repetir: ");
        scanf("%d", &num);

        if (num < 1 || num > 13) {
            printf("Número fuera de rango. Ingresa un número del 1 al 13.\n");
        } else if (numeroRepetido(numeros, num, size)) {
            printf("Número repetido. Ingresa un número del 1 al 13 sin repetir.\n");
        } else {
            return num;
        }
    } while (true);
}

int main() {
    int numeros[4][13];
    int temp;

    printf("Ingresa 13 números del 1 al 13 desordenados:\n");

    // Leer los 13 números ingresados por el usuario
    for (int j = 0; j < 13; j++) {
        numeros[0][j] = leerNumeroValido(numeros[0], j);
    }

    // Copiar los números ingresados en las otras secciones
    for (int i = 1; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            numeros[i][j] = numeros[0][j];
        }
    }

    // Ordenar los números en cada sección
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            for (int k = j + 1; k < 13; k++) {
                if (numeros[i][j] > numeros[i][k]) {
                    temp = numeros[i][j];
                    numeros[i][j] = numeros[i][k];
                    numeros[i][k] = temp;
                }
            }
        }
    }

    // Imprimir los números ordenados por secciones
    printf("\nLos números ingresados ordenados por las distintas cartas de la baraja son:\n");

    // Imprimir corazón rojo
    printf("Corazón Rojo: ");
    for (int j = 0; j < 13; j++) {
        if (numeros[0][j] == 1) {
            printf("A ");
        } else if (numeros[0][j] == 11) {
            printf("J ");
        } else if (numeros[0][j] == 12) {
            printf("Q ");
        } else if (numeros[0][j] == 13) {
            printf("K ");
        } else {
            printf("%d ", numeros[0][j]);
        }
    }
    printf("\n");

    // Imprimir diamante
    printf("Diamante: ");
    for (int j = 0; j < 13; j++) {
        if (numeros[1][j] == 1) {
            printf("A ");
        } else if (numeros[1][j] == 11) {
            printf("J ");
        } else if (numeros[1][j] == 12) {
            printf("Q ");
        } else if (numeros[1][j] == 13) {
            printf("K ");
        } else {
            printf("%d ", numeros[1][j]);
        }
    }
    printf("\n");

    // Imprimir trébol
    printf("Trébol: ");
    for (int j = 0; j < 13; j++) {
        if (numeros[2][j] == 1) {
            printf("A ");
        } else if (numeros[2][j] == 11) {
            printf("J ");
        } else if (numeros[2][j] == 12) {
            printf("Q ");
        } else if (numeros[2][j] == 13) {
            printf("K ");
        } else {
            printf("%d ", numeros[2][j]);
        }
    }
    printf("\n");

    // Imprimir corazón negro
    printf("Corazón Negro: ");
    for (int j = 0; j < 13; j++) {
        if (numeros[3][j] == 1) {
            printf("A ");
        } else if (numeros[3][j] == 11) {
            printf("J ");
        } else if (numeros[3][j] == 12) {
            printf("Q ");
        } else if (numeros[3][j] == 13) {
            printf("K ");
        } else {
            printf("%d ", numeros[3][j]);
        }
    }
    printf("\n");

    return 0;
}
