#ifndef ALGORITMO_H
#define ALGORITMO_H

typedef struct {
    int id;         // ID del proceso
    int arrival;    // Tiempo de llegada
    int burst;      // Duración del proceso
} Process;

// Función que implementa SJF y devuelve el orden de ejecución
int* schedule_sjf(Process processes[], int n);

#endif
