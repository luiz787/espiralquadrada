#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool isPerfectSquare(int i);
int getNearestPerfectSquare(int num);
void calculateCoords(int n);
void printCoords(int x, int y);

int main() {
    int n;
    scanf("%d", &n);
    calculateCoords(n);
    return 0;
}

void calculateCoords(int n) {
    int x, y;
    bool isPs = isPerfectSquare(n);
    if (!isPs) {
        int nearestPs = getNearestPerfectSquare(n);
        if (nearestPs % 2 == 0) {  // even ps
            x = sqrt(nearestPs) / 2 * -1;
            y = sqrt(nearestPs) / 2 * -1;
        } else {  // odd ps
            x = floor(sqrt(nearestPs) / 2);
            y = ceil(sqrt(nearestPs) / 2);
        }
        if ((int)sqrt(nearestPs) % 2 == 0) {  // root of nearestPs is even
            if (n > nearestPs) {              // y is equal
                x = x + abs(n - nearestPs);
            } else if (n < nearestPs) {  // x is equal
                y = y + abs(n - nearestPs);
            }
        } else {                  // number is odd
            if (n > nearestPs) {  // y is equal
                x = x - abs(n - nearestPs);
            } else if (n < nearestPs) {  // x is equal
                y = y - abs(n - nearestPs);
            }
        }
    } else {                          // is Ps
        if ((int)sqrt(n) % 2 == 0) {  // even ps
            x = sqrt(n) / 2 * -1;
            y = sqrt(n) / 2 * -1;
        } else {  // odd ps
            x = floor(sqrt(n) / 2);
            y = ceil(sqrt(n) / 2);
        }
    }
    printCoords(x, y);
}

bool isPerfectSquare(int i) {
    float root = sqrt(i);
    int intRoot = root;
    return intRoot == root;
}

int getNearestPerfectSquare(int num) {
    float root = sqrt(num);
    float decimal = root - (int)root;
    int val;
    if (decimal > 0.5) {
        val = (int)root + 1;
    } else {
        val = (int)root;
    }
    return pow(val, 2);
}

void printCoords(int x, int y) { printf("(%d, %d)\n", x, y); }
