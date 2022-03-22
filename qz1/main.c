#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define COUNTER_FILE "counter.bin"
#define MAX_LOTTO_NUM 7
#define MAX_LOTTO_NUMSET 5

void set_counter(int counter) {
    int write_array[1];
    write_array[0] = counter;
    FILE* tmpfp = fopen(COUNTER_FILE,"wb");
    fwrite(write_array, sizeof(int), 1, tmpfp);
    fclose(tmpfp);
}

void init_file() {
    int write_array[1] = {0};
    FILE* fp = fopen(COUNTER_FILE,"r");
    if (fp == NULL) {
        FILE* tmpfp = fopen(COUNTER_FILE,"wb+");
        fwrite(write_array, sizeof(int), 1, tmpfp);
        fclose(tmpfp);
    } else {
        fclose(fp);
    }
}

int get_counter() {
      int read_array[1];
      FILE* tmpfp = fopen(COUNTER_FILE,"rb");
      fread(read_array, siz    fwrite(write_array, sizeof(int), 1, tmpfp);
    fclose(tmpfp);
      return read_array[0];
}



int main() {
    
    char a[6];
    char b[30];
    int num = 0;
    int j = 0;
    int i = 0;
    int c = 0;
    int times = 0;
    int array_read[1];

    time_t curtime;
    time(&curtime);
    srand(time(NULL));
    printf("要買幾份樂透\n請輸入1~5: ");
    scanf("%d", &times);

    for (int c=0; c < times; c++) {
        for (int i=0; i<5; i++) {
            num = (rand()%69)+1;
            for (int j=0; j<i; j++) {
                if (num == a[j]) {
                    i--;
                    break;
                }
            }
            if(num != a[j]) {
                a[i] = num;
            }
        }

        for (int i=0; i<1; i++) {
            num = (rand()%10)+1;
            a[5] = num;
        }

        for (int i=0; i<5; i++) {
            for (int j=0; j<5; j++) {
                if (a[i] < a[j]) {
                    num = a[i];
                    a[i] = a[j];
                    a[j] = num;
                }
            } 
        }

        for (int i=0; i<6; i++) {
            b[i+c*6] = a[i];
        }
    }

    FILE* fp;
    fp = fopen("","wb");
    fread(array_read, sizeof(int), 1, fp);
    printf("%d",array_read[1]);
    fclose(fp);
    fp = fopen("lotto[0001].txt", "w+");
    fprintf(fp, "====== lotto.txt =======\n");
    fprintf(fp, "%s",ctime(&curtime));
    for (int i=1; i <= times; i++) {
        fprintf(fp,"[%d]:",i);

        for (int j = 0 + (i-1)*6; j<(6 + (i-1)*6); j++) {
            fprintf(fp,"%02d ", b[j]);
        }

        fprintf(fp,"\n");
    }

    if ((5-times) > 0) {
        for (int j = times; j <= 5; j++) {
            fprintf(fp,"[%d]:__ __ __ __ __ __ ",j);
            fprintf(fp,"\n");
        }
    }

    fprintf(fp,"==== csie@B1029015 =====");
    fclose(fp);
}