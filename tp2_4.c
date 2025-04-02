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
