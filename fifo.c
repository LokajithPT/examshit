#include <stdio.h>
#include <stdbool.h>

int main() {
    int burst[] = {1, 4, 10};
    int n = sizeof(burst) / sizeof(burst[0]);
    int quant = 4;
    int i = 0;
    int time = 0;
    bool allDone;

    while (1) {
        allDone = true;

        if (burst[i] > 0) {
            allDone = false;  // At least one process still running

            if (burst[i] <= quant) {
                time += burst[i];
                printf("Done: Process %d | Time Taken: %d | Time Now: %d\n", i, burst[i], time);
                burst[i] = 0;
            } else {
                burst[i] -= quant;
                time += quant;
                printf("Running: Process %d | Used: %d | Remaining: %d | Time Now: %d\n", i, quant, burst[i], time);
            }
        }

        i = (i + 1) % n;  // Loop around like a circle

        if (allDone) break;  // Exit if all are done
    }

    printf("All processes done at time %d!\n", time);
    return 0;
}

