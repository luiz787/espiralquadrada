#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int calcular_x(int prev_x, int qtd_viradas);
int calcular_y(int prev_y, int viradas);

int main() {
    int n;
    scanf("%d", &n);
    int i, qtd_viradas=0, proxima_virada = 1, passo_virada = 1, qtd_viradas_mesmo_passo = 0;
    int x=0, y=0;
    bool virou = false;
    for (i=1; i <= n; i++) {
        virou = i == proxima_virada;
        x = calcular_x(x, qtd_viradas);
        y = calcular_y(y, qtd_viradas);
        if (virou) {
            ++qtd_viradas_mesmo_passo;
            if (i > 1 && qtd_viradas_mesmo_passo == 2) {
                ++passo_virada;
                qtd_viradas_mesmo_passo = 0;
            }
            proxima_virada = i + passo_virada;
            ++qtd_viradas;
        }
    }
    printf("(%d,%d)\n", x, y);
    return 0;
}

int calcular_x(int prev_x, int qtd_viradas) {
    int mod = qtd_viradas % 4;
    int x = prev_x;
    switch (mod) {
        case 1:
            --x;
            break;
        case 3:
            ++x;
            break;
        default:
            break;
    }
    return x;
}

int calcular_y(int prev_y, int qtd_viradas) {
    int mod = qtd_viradas % 4;
    int y = prev_y;
    switch (mod) {
        case 0:
            ++y;
            break;
        case 2:
            --y;
            break;
        default:
            break;
    }
    return y;
}