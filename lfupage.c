#include <stdio.h>

int main() {
    int pages[] = {5, 7, 5, 6, 7, 8, 5, 7, 8, 9};
    int n = 10;
    int frame[3] = {-1, -1, -1};
    int freq[3] = {0};
    int hits = 0, misses = 0;

    for (int i = 0; i < n; i++) {
        int page = pages[i];
        int found = -1;

        // check if already present
        for (int j = 0; j < 3; j++) {
            if (frame[j] == page) {
                found = j;
                hits++;
                freq[j]++;
                break;
            }
        }

        if (found == -1) {
            // find least freq
            int min = 0;
            for (int j = 1; j < 3; j++) {
                if (freq[j] < freq[min])
                    min = j;
            }
            frame[min] = page;
            freq[min] = 1;
            misses++;
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

