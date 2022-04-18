#include <stdio.h>

typedef struct my_mm {
    int allocated_num[10];
    int record_mem[10];
} my_mm_t;
int g_mem[10];
my_mm_t mms;


int *my_calloc(int n, int size) {
    int start = -1;
    for (int i = 0; i < 10; i++) {
        int j = i, non_allocated = 0;
        while (mms.record_mem[j] == 0 && non_allocated < n*size && j < 10) {
            non_allocated++;
            j++;
        }
        if (non_allocated == n*size) {
            start = i;
            break;
        }
        i = j;
    }
    
    if (start == -1) {
        for (int k = 0; k < 10; k++) {
            printf("%d", mms.record_mem[k]);
        }
        printf("\n");
        return NULL;
    } else {
        for (int i = 0; i < n*size; i++) {
            mms.record_mem[start + i] = 1;
        }
        mms.allocated_num[start] = n*size;
        for (int k = 0; k < 10; k++) {
            printf("%d", mms.record_mem[k]);
        }
        printf("\n");
        return &g_mem[start];
    }
}

void my_free(int *p) {
    if (p == NULL) {
        for (int k = 0; k < 10; k++) {
            printf("%d", mms.record_mem[k]);
        }
        printf("\n");
        return;
    }
    
    int start = p - g_mem;
    for (int i = 0; i < mms.allocated_num[start]; i++) {
        mms.record_mem[start + i] = 0;
    }
    mms.allocated_num[start] = 0;
    
    for (int k = 0; k < 10; k++) {
            printf("%d", mms.record_mem[k]);
        }
        printf("\n");
}

int main() {
    int *np1 = my_calloc(1, 1);
    int *np2 = my_calloc(1, 2);
    int *np3 = my_calloc(1, 3);
    int *np4 = my_calloc(1, 4);
    my_free(np1);
    my_free(np4);
    int *np5 = my_calloc(1, 3);
    return 0;
}