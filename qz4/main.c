#include<stdio.h>
#include<stdlib.h>

void swap(int *n,int *m){
    int a = *n;
    *n = *m;
    *m = a;
}

void swapArray(int n[],int m[],int size){
    int tmp;
    for(int i = 0; i < size; i++){
        tmp = n[i];
        n[i] = m[i];
        m[i] = tmp;
    }
}

void printArray(int n[],int size){
    for(int i = 0; i < size;i++){
        printf("%d",n[i]);
        if(i+1 != size){
            printf(", ");
        }
    }
    printf("]\n");
}

char* copy_string(char* s){
    char* a = (char*)calloc(*s,sizeof(char));
    a = s;
    return a;
}

int main(){ 
    printf("No.1 -------------------\n");
    int n,m;
    n =1;
    m =2;
    swap(&n,&m);
    printf("after swap, n=%d m=%d\n",n,m);

    printf("No.2 -------------------\n");
    int size = 10;
    int source[10] = {0,9,8,7,6,5,4,3,2,1};
    int dest[10] = {10,20,30,40,50,6,70,80,90,100};
    swapArray(source,dest,size);
    printf("after swap array, source array = [");
    printArray(source,size);
    printf("after swap array, dest array = [");
    printArray(dest,size);

    printf("No.3 -------------------\n");
    char str[] = "IU!IU!IU!IU!";
    char* cp_str = copy_string(str);
    printf("copy string = %s\n",cp_str);
    free(cp_str);
    return 0;
}