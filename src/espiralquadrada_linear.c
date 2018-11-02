#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void calculateCoords(int n);
void stepForward(int* x, int* y, int amount_of_vertices);
void printCoords(int* x, int* y);

int main() {
    int n;
    scanf("%d", &n);
    calculateCoords(n);    
    return 0;
}

void calculateCoords(int n) {
    int x=0, y=0;
    int i, amount_of_vertices=0, index_of_next_turn = 1, segment_size = 1, amount_of_same_size_segments = 0;
    bool isVertex = false;
    for (i=1; i <= n; i++) {
        isVertex = i == index_of_next_turn;
        stepForward(&x, &y, amount_of_vertices);
        if (isVertex) {
            ++amount_of_same_size_segments;
            if (i > 1 && amount_of_same_size_segments == 2) {
                ++segment_size;
                amount_of_same_size_segments = 0;
            }
            index_of_next_turn = i + segment_size;
            ++amount_of_vertices;
        }
    }
    printCoords(&x, &y);
}

void stepForward(int* x, int* y, int amount_of_vertices) {
    int mod = amount_of_vertices % 4;
    switch (mod) {
        case 0:
            ++(*y);
            break;
        case 1:
            --(*x);
            break;
        case 2:
            --(*y);
            break;
        case 3:
            ++(*x);
            break;
        default:
            break;
    }
}

void printCoords(int* x, int* y) {
    printf("(%d, %d)\n", *x, *y);
}
