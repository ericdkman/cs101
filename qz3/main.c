#include <stdio.h>

void rec_dec(char* s) {
	if (!*s) {
	   return ; 
	}
	printf("%c,", *(s));
	return rec_dec(s+1);
}
void hanoi(int, char, char, char);

void hanoi_tower(int n) {
        hanoi(n, 'A', 'B', 'C');
}

int time = 0;

void hanoi(int n, char A, char B, char C) {
    FILE* wfp = fopen("hanoi.txt", "ab");
    
    if (n == 1)
    {
        fprintf(wfp, "%d: move disk %d from %c to %c\n", ++time, n, A, C);
    }
    else
    {
        hanoi(n - 1, A, C, B);
        fprintf(wfp, "%d: move disk %d from %c to %c\n", ++time, n, A, C);
        hanoi(n - 1, B, A, C);
    }
    fclose(wfp);
}

int multiplication(int i,int j) {
    if (i == 10) {
        return 0;
    } else if (j == 9) {
        printf("%d*%d=%d \n", i , j , i*j);
        multiplication(i+1, 1);
    } else {
        printf("%d*%d=%d ", i , j , i*j);
        multiplication(i, j+1);
    }
}

int main() {
    char s[] = "12655131vfs1";
    rec_dec(s);
    printf("\nfunc#1--------------------------\n");
    hanoi_tower(16);
    printf("func#2--------------------------\n");
    multiplication(1,1);
    printf("func#3--------------------------\n");
    return 0;
}
