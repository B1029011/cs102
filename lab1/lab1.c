#include<stdio.h>
#include<time.h>
#include<stdlib.h>




int main(){
    int n=0;
    int nowtime;
    int save[5];
    int round = -1;
    int l;
    int id;
    time_t curtime;
    time(&curtime);

    printf("歡迎光臨長庚樂透彩購買機台\n");
    printf("請輸入操作人員ID:(0~5):");
    scanf("%d",&id);
    printf("請問你要買幾組樂透彩：");
    scanf("%d",&n);
    

    srand((unsigned) time(NULL));
    
    FILE* fp;
    FILE* file;
    FILE* fid;
    
    fid = fopen("operator_id.bin","w+");
    fprintf(fid,"user_id:%d",id);
    fclose(fid);
    /*
    for(int i = 5; i>=0; i++){
        if(file = fopen("lotto[000%d].txt","r",i)){
            fclose(file);
            fp = fopen("lotto[000%d].txt","w+",i+1);
            round = 5;
        }
    }
    */
    if(file = fopen("lotto[0005].txt","r")){
        fclose(file);
        fp = fopen("lotto[0006].txt","w+");
        round = 5;
    }else if(file = fopen("lotto[0004].txt","r")){
        fclose(file);
        fp = fopen("lotto[0005].txt","w+");
        round = 4;
    }else if(file = fopen("lotto[0003].txt","r")){
        fclose(file);
        fp = fopen("lotto[0004].txt","w+");
        round = 3;
    }else if(file = fopen("lotto[0002].txt","r")){
        fclose(file);
        fp = fopen("lotto[0003].txt","w+");
        round = 2;
    }else if(file = fopen("lotto[0001].txt","r")){
        fclose(file);
        fp = fopen("lotto[0002].txt","w+");
        round = 1;
    }else{
        fp = fopen("lotto[0001].txt","w+");
        round = 0;
    }
    
    printf("以為你購買的%d組樂透組合輸出至 lotto[000%d].txt",n,round+1);
    


    fprintf(fp,"======== lotto649 =========\n");
    fprintf(fp,"=======+ No.000%d +=========\n",round+1);
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
}