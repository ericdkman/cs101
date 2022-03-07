#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
    char a[6];
    char b[30];
    int num = 0;
    int j = 0;
    int i = 0;
    int c = 0;
    int times = 0;

    srand(time(NULL));
    printf("Enter number 1~5: ");
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
        if (c==0) {
            for (int i=0; i<6; i++) {
                b[i] = a[i];
            }
        }
        if (c==1) {
            for (int i=0; i<6; i++) {
                b[i+6] = a[i];
            }
        }
        if (c==2) {
            for (int i=0; i<6; i++) {
                b[i+12] = a[i];
            }
        }
        if (c==3) {
            for (int i=0; i<6; i++) {
                b[i+18] = a[i];
            }
        }
        if (c==4) {
            for (int i=0; i<6; i++) {
                b[i+24] = a[i];
            }
        }
    }

    FILE* fp;
    fp = fopen("lotto.txt", "w+");
    if (times >= 1) {
        fprintf(fp,"第一組: ");
        for (int i=0; i<6; i++) {
            fprintf(fp,"%d ", b[i]);
        }
    }
    
    if (times >= 2) {
       fprintf(fp,"\n");
       fprintf(fp,"第二組: ");
       for (int i=6; i<12; i++) {
           fprintf(fp,"%d ", b[i]);
        } 
    }
    if (times >= 3) {
        fprintf(fp,"\n");
        fprintf(fp,"第三組: ");
        for (int i=12; i<18; i++) {
            fprintf(fp,"%d ", b[i]);
        }
    }
    
    if (times >= 4) {
        fprintf(fp,"\n");
        fprintf(fp,"第四組: ");
        for (int i=18; i<24; i++) {
            fprintf(fp,"%d ", b[i]);
        }
    }
    
    if (times >= 5) {
        fprintf(fp,"\n");
        fprintf(fp,"第五組: ");
        for (int i=24; i<30; i++) {
           fprintf(fp,"%d ", b[i]); 
        }
    }
    
    fclose(fp);
}