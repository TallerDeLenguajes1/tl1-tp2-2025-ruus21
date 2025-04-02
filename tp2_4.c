#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CANT_PC 5

struct compu {
    int velocidad; // Velocidad en GHz (1-3)
    int anio; // Año de fabricación (2015-2024)
    int cantidad_nucleos; // Cantidad de núcleos (1-8)
    char *tipo_cpu; // Tipo de procesador
};
char *tipos[6] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};

void generarPCs(struct compu pcs[], int cantidad);
void listarPCs(struct compu pcs[], int cantidad);
void mostrarMasVieja(struct compu pcs[], int cantidad);
void mostrarMasVeloz(struct compu pcs[], int cantidad);


int main() {
    srand(time(NULL));
    struct compu pcs[CANT_PC];
    
    generarPCs(pcs, CANT_PC);
    listarPCs(pcs, CANT_PC);
    mostrarMasVieja(pcs, CANT_PC);
    mostrarMasVeloz(pcs, CANT_PC);

    return 0;
}

void generarPCs(struct compu pcs[], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        pcs[i].velocidad = rand() % 3 + 1; // 1 a 3 GHz
        pcs[i].anio = rand() % 10 + 2015; // 2015 a 2024
        pcs[i].cantidad_nucleos = rand() % 8 + 1; // 1 a 8 núcleos
        pcs[i].tipo_cpu = tipos[rand() % 6];
    }
}

void listarPCs(struct compu pcs[], int cantidad) {
    printf("\nLista de PCs:\n");
    for (int i = 0; i < cantidad; i++) {
        printf("PC: Velocidad: %d GHz, Año: %d, Núcleos: %d, Tipo CPU: %s\n",
               pcs[i].velocidad, pcs[i].anio, pcs[i].cantidad_nucleos, pcs[i].tipo_cpu);
    }
}

void mostrarMasVieja(struct compu pcs[], int cantidad) {
    int indiceMasVieja = 0;
    for (int i = 1; i < cantidad; i++) {
        if (pcs[i].anio < pcs[indiceMasVieja].anio) {
            indiceMasVieja = i;
        }
    }
    printf("\nPC más vieja: Velocidad: %d GHz, Año: %d, Núcleos: %d, Tipo CPU: %s\n",
           pcs[indiceMasVieja].velocidad, pcs[indiceMasVieja].anio, pcs[indiceMasVieja].cantidad_nucleos, pcs[indiceMasVieja].tipo_cpu);
}

void mostrarMasVeloz(struct compu pcs[], int cantidad) {
    int indiceMasVeloz = 0;
    for (int i = 1; i < cantidad; i++) {
        if (pcs[i].velocidad > pcs[indiceMasVeloz].velocidad) {
            indiceMasVeloz = i;
        }
    }
    printf("\nPC más veloz: Velocidad: %d GHz, Año: %d, Núcleos: %d, Tipo CPU: %s\n",
           pcs[indiceMasVeloz].velocidad, pcs[indiceMasVeloz].anio, pcs[indiceMasVeloz].cantidad_nucleos, pcs[indiceMasVeloz].tipo_cpu);
}
