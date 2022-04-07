#include<stdio.h>
#include<stdlib.h>



void rec_dec(char* s){
    if(*s != '\0'){
     printf("%c,",*s);
     rec_dec(++s);
    }
}

void* hanoi_tower(int n,char A,char B,char C){
    if (n == 1){
        fprintf(fopen("hanoi.txt","ab"),"move disk %d from %c to %c\n",n,A,C);
        close("hanoi.txt");
    }
    else{
        hanoi_tower(n-1,A,C,B);
        fprintf(fopen("hanoi.txt","ab"),"move disk %d from %c to %c\n",n,A,C);
        close("hanoi.txt");
        hanoi_tower(n-1,B,A,C);
    }
}

void multiplication(int a,int b){
    printf("%d*%d = %d ",a,b,a*b);
    if(b <= 8)
        multiplication(a,b+1);
    else{
        printf("\n");
        if(a <= 8)  multiplication(a+1,1);
    }


}


int main(){
    char s[] = "1234567890";
    rec_dec(s);
    printf("\nfunc#1----------------------\n");
    hanoi_tower(16,'A','B','C');
    printf("\nfunc#2----------------------\n");
    multiplication(1,1);
    printf("\nfunc#3----------------------\n");

    return 0;
}
