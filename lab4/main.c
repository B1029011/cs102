#include<stdio.h>

void found(int n[],int number,int* p,int* save){
    for(int i = 0; i < 10; i++){
        if(n[i] == number){
            *p = &n[i];
            *save = i;
            break;
        }
    }
}

int main(){
    int n[] = {6,4,7,2,0,9,8,1,5,3};
    int* p;
    int* save;
    int number = 2;
    found(n,number,&p,&save);
    printf("No.1 -----------------\n");
    printf("&n[%d]->%p, n[%d] =%d; p->%p, *p=%d\n",save,p,save,*p,p,*p);
    printf("No.2 -----------------\n");
    int* ap[10];

}
