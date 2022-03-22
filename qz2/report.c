#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

typedef struct lotto_daty{
    char date[8];
    int counter;
    int quantity;
    int receipt;
} lotto_daty;

typedef struct lotto_sum{
    int date;
    int counter;
    int quantity;
    int receipt;
}lotto_sum;

int string_check(char str1[],char str2[]){
    int n = 0;
    int i = 0;
    
    while(i < 8){
        if(str1[i] != str2[i])  n++;
        i++;
    }
    
    
    return n;
}

int main(){
    FILE* report = fopen("report.txt","w+");
    FILE* record = fopen("records.bin","r");
    char save[256];
    lotto_daty lotto[10];
    lotto_daty lotto_save ={" ",0,0,0};
    lotto_sum lotto_total;
    
    int n = 0;
    int n_move = n;
    while(fgets(save,sizeof(save),record) != NULL){
        int no;
        n_move = n;
        
        no = atoi(save);
        
        char time[8];
        fgets(save,sizeof(save),record);
       
        lotto_save.receipt = atoi(save);
        //printf("1.%d\n",lotto_save.receipt);
        fgets(save,sizeof(save),record);
        fgets(save,sizeof(save),record);
        strcpy(lotto_save.date , save);
        fgets(save,sizeof(save),record);
        while(n_move > 0){
            //printf("--\n");
            if(string_check(lotto_save.date , lotto[n_move].date ) == 0){
                lotto[n_move].receipt +=lotto_save.receipt;
                lotto[n_move].quantity +=lotto_save.receipt/55; 
                lotto[n_move].counter++;
                //printf("n_move = %d\n",n_move);
                n_move = -1;
               
            }else{
                n_move--;
            }
            
        }
        if(n_move == 0){
            lotto[++n].receipt = lotto_save.receipt;
            lotto[n].quantity = lotto_save.receipt/55; 
            strcpy(lotto[n].date , lotto_save.date);
            lotto[n].counter = 1;
        }
        
        //printf("\n\n");
    }

    //printf("%s\n",lotto_save.date);
    int a = 1;
    fprintf(report,"========= lotto649 Report =========\n- Date ------ Num. ------ Receipt -\n");
    while(a <= n){
        lotto_total.counter += lotto[a].counter;
        lotto_total.quantity += lotto[a].quantity;
        lotto_total.receipt += lotto[a].receipt;
        fprintf(report,"%.*s      %d/%d           %d\n",8,lotto[a].date
                                            ,lotto[a].counter
                                            ,lotto[a].quantity
                                            ,lotto[a].receipt);
        a++;
    }
    fprintf(report,"-----------------------------------\n");
    fprintf(report,"       %d     %d/%d           %d\n",n,lotto_total.counter,lotto_total.quantity-1,lotto_total.receipt);
    fprintf(report,"========= %.*s Printed =========\n",8,lotto[n].date);
    fclose(record);
    fclose(report); 
    return 0;  
}