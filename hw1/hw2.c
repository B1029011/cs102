#include<stdio.h>
#include<time.h>
#include<stdlib.h>





int main(){
    int n=0;
    int nowtime;
    int save[5];

    time_t curtime;
    time(&curtime);

    printf("歡迎光臨長庚樂透彩購買機台\n");
    printf("請問你要買幾組樂透彩：");
    scanf("%d",&n);
    printf("以為你購買的%d組樂透組合輸出至 lotto.txt",n);

    srand((unsigned) time(NULL));
    
    FILE* fp;

    fp = fopen("lotto.txt","w+");


    fprintf(fp,"======== lotto649 =========\n");
    fprintf(fp,"= %s = \n",ctime(&curtime));
    for(int i = 1; i <= 5; i++){
        fprintf(fp,"[%d]: ",i);
        if(n>=i){
            for(int j = 0; j < 5; j++)  save[j]=(rand() % 70);
            
            for(int j = 0; j < 4; j++)
                for(int k = 0; k < 4; k++)
                    if(save[k] > save[k+1]){
                        int a;
                        a = save[k];
                        save[k] = save[k+1];
                        save[k+1] = a;
                    }  



            for(int j = 0; j < 5; j++){
                if(save[j] >= 10)
                    fprintf(fp,"%d ",save[j]);
                else
                    fprintf(fp,"0%d ",save[j]);
            }
            fprintf(fp,"0%d",rand() % 10);
        }else{
            for(int j = 0; j < 6; j++)  fprintf(fp,"-- ");
        }
        fprintf(fp,"\n");
    }
    fprintf(fp,"======== csie@CGU =========\n");
    fclose(fp);
    return 0;
}