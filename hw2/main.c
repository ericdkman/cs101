#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct lotto_record_t {
    int lotto_no;
    int lotto_receipt;
    int emp_id;
    char lotto_date[8];
    char lotto_time[8];
} emp_record_k;

typedef struct lotto_record_c {
    int emp_id;
    char emp_name[6];
    int salary;
} emp_record_t;

int main() {
    FILE* fp_bin;
    FILE* fp_txt;
    FILE* op_bin;
    FILE* fp_rec;
    
    char szbuff[16];
    char name[6];
    int money;
    emp_record_k emp_i;
    emp_record_t emp_j;
    time_t now = time(0);
    strftime (szbuff, 100, "%Y%m%d", localtime(&now));
    printf("%s\n", szbuff);
    strcpy(emp_i.lotto_date, szbuff);
    strftime (szbuff, 100, "%H:%M:%S", localtime(&now));
    printf("%s\n", szbuff);
    strcpy(emp_i.lotto_time, szbuff);
    

    int count[]={1};
    
    
    if((fp_bin = fopen("count.bin", "rb")) != NULL){
        fread(count, sizeof(count), 1 ,fp_bin);
        fclose(fp_bin);
    }
    else{
        fp_bin = fopen("count.bin","wb+");
        fwrite(count, sizeof(count), 1 , fp_bin);
        fclose(fp_bin);
    }
    
    time_t curtime;
    time(&curtime);
    int arr_num[5][7],group,flag,temp,ID;
    srand((unsigned) time(NULL));
    printf("請輸入操作人員ID:(0~5):");
    scanf("%d",&ID);
    if (ID != 0) {
        
    
    printf("歡迎光臨長庚樂透彩購買機台,請問您要買幾組樂透彩:");
    scanf("%d",&group);
    emp_i.emp_id = ID;
    emp_i.lotto_no = group;
    emp_i.lotto_receipt = group*50*(1.1);
    fp_rec = fopen("records.bin", "ab");
    fprintf(fp_rec, "lotto_no: %05d\n" , emp_i.lotto_no);
    fprintf(fp_rec, "lotto_receipt: %d\n" , emp_i.lotto_receipt);
    fprintf(fp_rec, "emp_id: %d\n" , emp_i.emp_id);
    fprintf(fp_rec, "lotto_date: ");
    fwrite(emp_i.lotto_date, 8 , 1 , fp_rec);
    fprintf(fp_rec, "\n");
    fprintf(fp_rec, "lotto_time: ");
    fwrite(emp_i.lotto_time, 8 , 1 , fp_rec);
    fclose(fp_rec);
    
    

    char filename[50];
    snprintf(filename, sizeof(filename), "lotto[%04d].txt",count[0]);
    fp_txt = fopen(filename,"w+");
    fprintf(fp_txt,"========= lotto649 =========\n");
    fprintf(fp_txt,"========+ No.%05d +========\n",count[0]);
    fprintf(fp_txt,"= %.*s =\n", 24, ctime(&curtime));
    for(int i=0; i<5; i++){
        if(group>=(i+1)){
            for(int j=0; j<=6;){
                do{
                    j!=6? (arr_num[i][j] = rand()%69+1) : (arr_num[i][j] = rand()%10+1);
                    flag=0;
                    for(int k=0; k<j; k++){
                        temp=0;
                        if(arr_num[i][j]==arr_num[i][k]){
                            flag=1;
                        }
                        else if(j<5 && arr_num[i][j]<arr_num[i][k]){
                            temp=arr_num[i][j];
                            arr_num[i][j]=arr_num[i][k];
                            arr_num[i][k]=temp;
                        }
                    }
                }while(flag==1);
                j++;
            }
        }
    }

    for(int i=0; i<5; i++){
        fprintf(fp_txt,"[%d] : ",i+1);
        for(int j=0; j<=6; j++){
            if(group>=(i+1)){
                fprintf(fp_txt,"%02d ",arr_num[i][j]);
            }
            else{
                fprintf(fp_txt,"-- ");
            }
        }
        fprintf(fp_txt,"\n");
    }
    fprintf(fp_txt,"========* Op.0000%d *=========\n",ID);
    fprintf(fp_txt,"========= csie@CGU =========\n");
    printf("已為您購買的%d組樂透組合輸出至%s\n",group,filename);
    fclose(fp_txt);
    count[0]++;
    fp_bin=fopen("count.bin","wb+");
    fwrite(count,sizeof(count),1,fp_bin);
    fclose(fp_bin);
    
    
    }
    
    op_bin = fopen("operator_id.bin", "wb+");
    printf("請輸入操作人員name(0~6word):");
    scanf("%s", emp_j.emp_name);
    emp_j.emp_id = ID;
    printf("請輸入操作人員salary:");
    scanf("%d", &money);
    emp_j.salary = money;
    fprintf(op_bin, "emp_id: %d\n" ,emp_j.emp_id);
    fwrite(emp_j.emp_name, 6 , 1 , op_bin);
    fprintf(op_bin, "\n");
    fprintf(op_bin, "salary: %d\n" ,emp_j.salary);
    fclose(op_bin);
}