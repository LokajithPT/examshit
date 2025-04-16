#include <stdio.h>

int main() {
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3};
    int n = 10;
    int frame[3] = {-1, -1, -1};
    int recent[3] = {0}; // how recently used
    int time = 0;
    int hits = 0, misses = 0;

    for (int i = 0; i < n; i++) {
        int page = pages[i];
        time++;
        int found = -1;

        for (int j = 0; j < 3; j++) {
            if (frame[j] == page) {
                found = j;
                hits++;
                break;
            }
        }

        if (found == -1) {
            // find LRU
            int lru = 0;
            for (int j = 1; j < 3; j++) {
                if (recent[j] < recent[lru])
                    lru = j;
            }
            frame[lru] = page;
            recent[lru] = time;
            misses++;
        } else {
            recent[found] = time;
        }

        printf("Page %d => Frame: ", page);
        for (int j = 0; j < 3; j++) {
            if (frame[j] != -1)
                printf("%d ", frame[j]);
            else
                printf("- ");
        }
        printf(found != -1 ? " [HIT]\n" : " [MISS]\n");
    }

    printf("\nTotal Hits: %d\nTotal Misses: %d\n", hits, misses);
    return 0;
}

