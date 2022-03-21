#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#define COUNTER_FILE "counter.bin"
#define MAX_LOTTO_NUM 7
#define MAX_LOTTO_NUMSET 5

typedef  struct lotto_record_t{
    int lotto_no;
    int lotto_receipt;
    int emp_id;
    char lotto_date[8];
    char lotto_time[8];

} lotto_record_t;

typedef struct emp_record_t{
    int emp_id;
    char emp_name[100];
    int emp_salary;
} emp_record_t;

void init_file() {
    int write_array[1] = {0};
    FILE* fp = fopen(COUNTER_FILE,"r");
    if(fp == NULL){
        FILE* tmpfp = fopen(COUNTER_FILE,"wb+");
        fwrite(write_array, sizeof(int), 1, tmpfp);
        fclose(tmpfp);
    } else {
        fclose(fp);
    }
}

int get_counter(){
    int read_array[1];
    FILE* tmpfp = fopen(COUNTER_FILE,"rb");
    fread(read_array,sizeof(int), 1, tmpfp);
    fclose(tmpfp);
    return read_array[0];
}

void set_counter(int counter){
    int write_array[1];
    write_array[0] = counter;
    FILE* tmpfp = fopen(COUNTER_FILE,"wb");
    fwrite(write_array, sizeof(int), 1, tmpfp);
    fclose(tmpfp);
}

void write_emp(){
    emp_record_t emp;
    printf("請輸入要新增操作人員 ID (1~99) :");
    scanf("%d",&emp.emp_id);
    printf("請輸入要新增操作人員 Name :");
    scanf("%s",&emp.emp_name);
    printf("請輸入要新增操作人員 Salary :");
    scanf("%d",&emp.emp_salary);
    
    FILE* emp_file = fopen("operator_id.bin","ab");
    fprintf(emp_file ,"%d\n" ,emp.emp_id);
    fprintf(emp_file ,"%s\n" ,emp.emp_name);
    fprintf(emp_file ,"%d\n" ,emp.emp_salary);
    fclose(emp_file);
    printf("輸入完成");
}


int main(){
    int n=0;
    int nowtime;
    int save[5];
    int round = -1;
    int l;
    int id;
    time_t curtime;
    time(&curtime);
    lotto_record_t lotto;

    
    

    srand((unsigned) time(NULL));
    
    FILE* fp;
    FILE* file;
    FILE* fid;
    
    
    fid = fopen("operator_id.bin","w+");
    fprintf(fid,"user_id:%d",id);
    fclose(fid);
    
    int counter;
    init_file();
    counter = get_counter();
    //round = counter;
    counter++;

    char lotto_file[32];
    int num_set = 0;
    snprintf(lotto_file, 32, "lotto[%05d].txt",counter);
    printf("歡迎光臨長庚樂透彩購買機台\n");
    printf("請輸入操作人員ID:(0~5):");
    scanf("%d",&id);
    if(id != 0){

    
        printf("請問你要買幾組樂透彩：");
        scanf("%d",&n);

        char szbuff[32];
        time_t now = time(0);
        strftime(szbuff, 100, "%Y%m%d-%H:%M:%S", localtime(&now));
        lotto.lotto_no = counter;
        lotto.lotto_receipt = n * 50 * 1.1;
        lotto.emp_id = id;
        for(int i = 0; i < 8; i++){
            lotto.lotto_date[i] = szbuff[i];
            lotto.lotto_time[i] = szbuff[i+9];
        }
        
        FILE* record = fopen("records.bin","ab");
        fprintf(record,"%d\n",lotto.lotto_no);
        fprintf(record,"%d\n",lotto.lotto_receipt);
        fprintf(record,"%d\n",lotto.emp_id);
        fprintf(record,"%.*s\n",8,lotto.lotto_date);
        fprintf(record,"%s\n",lotto.lotto_time);
        fclose(record);

        
        //print_lottofile(num_set, counter, lotto_file);
        fp = fopen(lotto_file,"w+");
        
        set_counter(counter);

        


        printf("以為你購買的%d組樂透組合輸出至 lotto[000%d].txt",n,counter);
        


        fprintf(fp,"======== lotto649 =========\n");
        fprintf(fp,"=======+ No.000%d +=========\n",counter);
        fprintf(fp,"= %.*s = \n",23,ctime(&curtime));


        for(int i = 1; i <= 5; i++){
            fprintf(fp,"[%d]: ",i);
            if(n>=i){
                for(int j = 0; j < 6; j++){
                    save[j]=(rand() % 69+1);
                    if(j !=0){
                        for(int k = 0; k < j; k++){
                            if(save[j] == save[k]){
                                k--;
                                save[j] = (rand()%69+1);
                            }
                        }
                    }
                }  
                
                for(int j = 0; j < 5; j++)
                    for(int k = 0; k < 5; k++)
                        if(save[k] > save[k+1]){
                            int a;
                            a = save[k];
                            save[k] = save[k+1];
                            save[k+1] = a;
                        }  



                for(int j = 0; j < 6; j++){
                    if(save[j] >= 10)
                        fprintf(fp,"%d ",save[j]);
                    else
                        fprintf(fp,"0%d ",save[j]);
                }
                fprintf(fp,"0%d",rand() % 8+1);
            }else{
                for(int j = 0; j < 7; j++)  fprintf(fp,"-- ");
            }
            fprintf(fp,"\n");
        }
        fprintf(fp,"=======* Op.0000%d *=======\n",id);
        fprintf(fp,"======== csie@CGU =========\n");
        fclose(fp);
        return 0;
    } else {
        write_emp();
        return 0;
    }
}