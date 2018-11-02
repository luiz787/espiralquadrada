#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int getNearestPerfectSquare(int num);
void calculateCoords(int n);
void calculatePsCoords(int ps, int* x, int* y);
int calculateDistanceFromNToPerfectSquare(int n, int nearestPs);
char determineMovementAxis(int n, int nearestPs);
int determineMovementSign(int nearestPs);
void applyOffSet(int amountOfSteps, char movementAxis, int movementSign, int* x, int* y);
void printCoords(int* x, int* y);

int main() {
    int n;
    scanf("%d", &n);
    calculateCoords(n);
    return 0;
}

void calculateCoords(int n) {
    int x=0, y=0;
    int nearestPs = getNearestPerfectSquare(n);
    calculatePsCoords(nearestPs, &x, &y);
    int distOfNToPerfectSquare = calculateDistanceFromNToPerfectSquare(n, nearestPs);
    char movementAxis = determineMovementAxis(n, nearestPs);
    int movementSign = determineMovementSign(nearestPs);
    applyOffSet(distOfNToPerfectSquare, movementAxis, movementSign, &x, &y);
    printCoords(&x, &y);
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

void calculatePsCoords(int ps, int* x, int* y) {
	if (ps % 2 == 0) {  // even ps
        *x = sqrt(ps) / 2 * -1;
        *y = sqrt(ps) / 2 * -1;
    } else {  // odd ps
        *x = floor(sqrt(ps) / 2);
        *y = ceil(sqrt(ps) / 2);
    }
}

int calculateDistanceFromNToPerfectSquare(int n, int nearestPs) {
	return abs(n - nearestPs);
}

char determineMovementAxis(int n, int nearestPs) {
	return n > nearestPs ? 'X' : 'Y';
}

int determineMovementSign(int nearestPs) {
	int movementSign = 0;
	if ((int)sqrt(nearestPs) % 2 == 0) {
		movementSign = 1;
	} else {
		movementSign = -1;
	}
	return movementSign;
}

void applyOffSet(int amountOfSteps, char movementAxis, int movementSign, int* x, int* y) {
	int i;
    for (i = 0; i < amountOfSteps; i++) {
        if (movementAxis == 'X') {
            *x = *x + movementSign;
        } else {
            *y = *y + movementSign;
        }
    }
}

void printCoords(int* x, int* y) {
    printf("(%d, %d)\n", *x, *y);
}
