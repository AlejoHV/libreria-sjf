#include "algoritmo.h"
#include <stdio.h>

int main() {
    Process processes[] = {
        {1, 0, 6},  // {id, arrival, burst}
        {2, 1, 3},
        {3, 2, 4}
    };
    int n = 3;

    int *order = schedule_sjf(processes, n);
    printf("Orden SJF: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", order[i]);
    }
    free(order);
    return 0;
}
