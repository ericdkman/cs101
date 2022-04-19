#include <stdio.h>

int func(int* i, int* j) {
    int tmp;
    tmp = *i;
    *i = *j;
    *j = tmp;
}

void swapArray(int* source, int* dest, int size) {
    int s = 0;
    int d = 0;
    for (int i=0; i < size; i++) {
        s = *(source + i);
        d = *(dest + i);
        func(&s, &d);
        *(source + i) = s;
        *(dest + i) = d;
    }
    return 0;
}

void printArray(int *k, int size) {
    for (int i=0; i < 10; i++) {
        printf("%d",k[i]);
        if(i<9) {
            printf(", "); 
        }
    }
    printf("]");
}

char* copy_string(char* s) {
	int size = 0;
	while(s[size++]);
	char* cp_str = (char*)calloc(size, sizeof(char));
	for(int i = 0; i < size - 1; i++) {
		cp_str[i] = s[i];
	}
	cp_str[size] = '\0';
	return cp_str;
}

int main() {
    int n, m;
    int size = 10;
    int source[10] = {0 ,9 , 8, 7, 6, 5, 4, 3, 2, 1};
    int dest[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    char str[] = "IU!IU!IU!IU!";
    
    n = 1;
    m = 2;
    func(&n, &m);
    printf("No.1 ----------------------\n");
    printf("after swap, n=%d, m=%d\n", n, m);
    printf("No.2 ----------------------\n");
    swapArray(source, dest, size);
    printf("after swap array, source array = [");
    printArray(source, size);
    printf("\nafter swap array, dest array = [");
    printArray(dest, size);
    printf("\nNo.3 ----------------------\n");
    char* cp_str = copy_string(str);
    printf("copy string = %s\n", cp_str);
    free(cp_str);
}
