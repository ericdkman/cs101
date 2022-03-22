#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#define COUNTER_FILE "counter.bin"
#define RECORD_FILE "counter.record"

int num_in_numset(int num, int numset[], int Len) {
    int ret = 0;
    for (int i=0; i< Len; i++) {
        if (num == numset[i]) {
            ret = 1;
            break;
        }
    }
    return ret;
}

void record_a_times(int counter, ) {
    FILE* rfp = fopen(RECORD_FILE, "ab");
    int write_array[1];
    write_array[0] = counter;
    fwrite(write_array, sizeof(int), 1, rfp);
    fclose(rfp);
}

typedef struct emp {
    int no;
    int receipt;
    char ID[6];
    char date[9];
    char time[9];strcpy(emp_.ID,"%s");
            fprintf(tmpfp, "%02d ", num);
            i++;
        }
    }

    for(int i = 0; i<1; ) {
        int num = (rand() % 10) + 1;
        if (num_in_numset(num, numset, 6)) {
            continue;
        } else {
            fprintf(tmpfp, "%02d ", num);
            i++;
        }
    }

    fprintf(tmpfp, "\n");
}

void print_lottofile(int num_set, int counter, char lotto_file[]) {
    time_t curtime;
    time(&curtime);
    srand(time(0));
    FILE* tmpfp = fopen(lotto_file, "w+");
    fprintf(tmpfp, "========= lotto649 =========\n");
    fprintf(tmpfp, "========+ No.%05d +========\n", counter);
    fprintf(tmpfp, "= %.*s =\n", 24, ctime(&curtime));
    for (int i=1; i<6; i++) {
        if (i <= num_set) {
            printf_lotto_num(tmpfp, i);
        } else {
            fprintf(tmpfp, "[%d]: -- -- -- -- -- -- --\n", i);
        }
    }
    fprintf(tmpfp, "========= csie@CGU =========\n");
    fclose(tmpfp);
}

void do_lotto_main(int counter) {
    char lotto_file[32];
    int num_set = 0;
    snprintf(lotto_file, 32, "lotto[%05d].txt", counter);
    printf("歡迎光臨長庚樂透採購買機台\n");
    printf("請問您要買幾組樂透彩：");
    scanf("%d", &num_set);
    print_lottofile(num_set, counter, lotto_file);
    printf("已為您購買的 %d 組樂透組合輸出至 %s\n", num_set, lotto_file);
}

void init_file() {
    int write_array[1] = {0};
    FILE* fp = fopen(COUNTER_FILE,"r");
    if (fp == NULL) {
        FILE* tmpfp = fopen(COUNTER_FILE,"wb+");
        fwrite(write_array, sizeof(int), 1, tmpfp);
        fclose(tmpfp);
    }
}

int get_counter() {
    int read_array[1];
    FILE* tmpfp = fopen(COUNTER_FILE,"rb");
    fread(read_array, sizeof(int), 1, tmpfp);
    fclose(tmpfp);
    return read_array[0];
}

void set_counter(int counter) {
    int write_array[1];
    write_array[0] = counter;
    FILE* tmpfp = fopen(COUNTER_FILE,"wb");
    fwrite(write_array, sizeof(int), 1, tmpfp);
    fclose(tmpfp);
}

int main() {
    lotto_recoed_t emp_i;
    int counter;
    int sell;
    char szbuff[32];
    char id[6];
    init_file();
    counter = get_counter();
    do_lotto_main(++counter);
    set_counter(counter);

    time_t now = time(0);
    strftime (szbuff, 100, "%Y%m%d-%H:%M:%S", localtime(&now));
    printf ("%s\n", szbuff);
    sell = counter*50*1.1;
    scanf("%s", &id);
    strcpy(emp_i.receipt,"%s",);
    strcpy(emp_i.ID,"%s",);
    strcpy(emp_i.date,"%s",);
    strcpy(emp_i.time,"%s", szbuff);

    return 0;
}
