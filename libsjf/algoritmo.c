#include "algoritmo.h"
#include <stdlib.h>
#include <stdio.h>

int compare(const void *a, const void *b) {
    Process *p1 = (Process *)a;
    Process *p2 = (Process *)b;
    return p1->burst - p2->burst;  // Ordena por duración (SJF)
}

int* schedule_sjf(Process processes[], int n) {
    // Ordenamos los procesos por duración (SJF)
    qsort(processes, n, sizeof(Process), compare);

    // Creamos un array con el orden de ejecución (IDs)
    int *order = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        order[i] = processes[i].id;
    }

    return order;
}
