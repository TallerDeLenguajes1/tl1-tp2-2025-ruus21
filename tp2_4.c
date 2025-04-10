#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CANT_PC 5

typedef struct {
    int velocidad;
    int anio;
    int cantidad_nucleos;
    char *tipo_cpu;
} PC;

void generarPCs(PC pcs[], int cantidad, char *tipos[]);
void listarPCs(PC pcs[], int cantidad);
void mostrarMasVieja(PC pcs[], int cantidad);
void mostrarMasVeloz(PC pcs[], int cantidad);

int main() {
    srand(time(NULL));

    PC *pcs;
    pcs = malloc(CANT_PC * sizeof(PC));

    char *tipos[6] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};

    generarPCs(pcs, CANT_PC, tipos);
    listarPCs(pcs, CANT_PC);
    mostrarMasVieja(pcs, CANT_PC);
    mostrarMasVeloz(pcs, CANT_PC);

    free(pcs);
    return 0;
}

void generarPCs(PC pcs[], int cantidad, char *tipos[]) {
    int i;
    for (i = 0; i < cantidad; i++) {
        pcs[i].velocidad = rand() % 3 + 1;
        pcs[i].anio = rand() % 10 + 2015;
        pcs[i].cantidad_nucleos = rand() % 8 + 1;
        pcs[i].tipo_cpu = tipos[rand() % 6];
    }
}

void listarPCs(PC pcs[], int cantidad) {
    int i;
    printf("\nLista de PCs:\n");
    for (i = 0; i < cantidad; i++) {
        printf("PC: Velocidad: %d GHz, Anio: %d, Nucleos: %d, Tipo CPU: %s\n",
               pcs[i].velocidad, pcs[i].anio, pcs[i].cantidad_nucleos, pcs[i].tipo_cpu);
    }
}

void mostrarMasVieja(PC pcs[], int cantidad) {
    int i, indice = 0;
    for (i = 1; i < cantidad; i++) {
        if (pcs[i].anio < pcs[indice].anio) {
            indice = i;
        }
    }
    printf("\nPC mas vieja: Velocidad: %d GHz, Anio: %d, Nucleos: %d, Tipo CPU: %s\n",
           pcs[indice].velocidad, pcs[indice].anio, pcs[indice].cantidad_nucleos, pcs[indice].tipo_cpu);
}

void mostrarMasVeloz(PC pcs[], int cantidad) {
    int i, indice = 0;
    for (i = 1; i < cantidad; i++) {
        if (pcs[i].velocidad > pcs[indice].velocidad) {
            indice = i;
        }
    }
    printf("\nPC mas veloz: Velocidad: %d GHz, Anio: %d, Nucleos: %d, Tipo CPU: %s\n",
           pcs[indice].velocidad, pcs[indice].anio, pcs[indice].cantidad_nucleos, pcs[indice].tipo_cpu);
}
