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

int main() {
    srand(time(NULL));
    struct compu pcs[CANT_PC];
    
    generarPCs(pcs, CANT_PC);
    listarPCs(pcs, CANT_PC);

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