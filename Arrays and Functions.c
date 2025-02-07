#include <stdio.h>

void behind(int *, int);

int main(void) {
    int array[10];
    int N, i;
    
    scanf("%d", &N);
    for (i=0; i<N; i++) {
        scanf("%d", &array[i]);
    }
    behind(array, N);
    for (i=0; i<N; i++) {
        printf("%d\n", array[i]);
    }
    
    return 0;
}

void behind(int *scores, int num_players) {
    int max_score = scores[0];
    for (int i = 1; i < num_players; i++) {
        if (scores[i] > max_score) {
            max_score = scores[i];
        }
    }

    for (int i = 0; i < num_players; i++) {
        scores[i] = max_score - scores[i];
    }
}
