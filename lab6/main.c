#include <stdio.h>

int _sum(int x, int y) {
    int k = 0;
    k = x+y;
    return k;
}

int _sub(int x, int y) {
    int k = 0;
    k = x-y;
    return k;
}

int _mult(int x, int y) {
    int k = 0;
    k = x*y;
    return k;
}

int _div(int x, int y) {
    int k = 0;
    k = x/y;
    return k;
}

int _power(int x, int y) {
    int k = 1;
    for (int i=0; i < y; i++) {
       k *= x;
    }
    return k;
}


int main() {
    int x, y, choice;
    int (*ope[4])(int, int);
    ope[0] = _sum;
    ope[1] = _sub;
    ope[2] = _mult;
    ope[3] = _div;
    ope[4] = _power;
    
    printf("Enter two integer: ");
    scanf("%d%d", &x,&y);
    
    printf("Enter 0:+, 1:-, 2:*, 3:/, 4 ^:");
    scanf("%d", &choice);
    
    printf("%d", ope[choice](x,y));
    return 0;
}