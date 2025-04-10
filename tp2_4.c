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

    char **tipos;
    tipos = (char *[]){"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};

    if (pcs == NULL) return 1;

    generarPCs(pcs, CANT_PC, tipos);
    listarPCs(pcs, CANT_PC);
    mostrarMasVieja(pcs, CANT_PC);
    mostrarMasVeloz(pcs, CANT_PC);

    free(pcs);

    return 0;
}

void generarPCs(PC pcs[], int cantidad, char *tipos[]) {
    for (int i = 0; i < cantidad; i++) {
        pcs[i].velocidad = rand() % 3 + 1;
        pcs[i].anio = rand() % 10 + 2015;
        pcs[i].cantidad_nucleos = rand() % 8 + 1;
        pcs[i].tipo_cpu = tipos[rand() % 6];
    }
}

void listarPCs(PC pcs[], int cantidad) {
    printf("\nLista de PCs:\n");
    for (int i = 0; i < cantidad; i++) {
        printf("PC: Velocidad: %d GHz, Año: %d, Núcleos: %d, Tipo CPU: %s\n",
               pcs[i].velocidad, pcs[i].anio, pcs[i].cantidad_nucleos, pcs[i].tipo_cpu);
    }
}

void mostrarMasVieja(PC pcs[], int cantidad) {
    int indiceMasVieja = 0;
    for (int i = 1; i < cantidad; i++) {
        if (pcs[i].anio < pcs[indiceMasVieja].anio) {
            indiceMasVieja = i;
        }
    }
    printf("\nPC más vieja: Velocidad: %d GHz, Año: %d, Núcleos: %d, Tipo CPU: %s\n",
           pcs[indiceMasVieja].velocidad, pcs[indiceMasVieja].anio,
           pcs[indiceMasVieja].cantidad_nucleos, pcs[indiceMasVieja].tipo_cpu);
}

void mostrarMasVeloz(PC pcs[], int cantidad) {
    int indiceMasVeloz = 0;
    for (int i = 1; i < cantidad; i++) {
        if (pcs[i].velocidad > pcs[indiceMasVeloz].velocidad) {
            indiceMasVeloz = i;
        }
    }
    printf("\nPC más veloz: Velocidad: %d GHz, Año: %d, Núcleos: %d, Tipo CPU: %s\n",
           pcs[indiceMasVeloz].velocidad, pcs[indiceMasVeloz].anio,
           pcs[indiceMasVeloz].cantidad_nucleos, pcs[indiceMasVeloz].tipo_cpu);
}
