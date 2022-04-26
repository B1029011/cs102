#include<stdio.h>
#include<stdlib.h>

typedef struct struct_array_list{
    int n;
    int* (*func1_ptr)(int);
    void (*func2_ptr)(int*,int);
    void (*func3_ptr)(int*,int);
}array_list_t;

int* get_int_array(int n){
    int* a = (int*)calloc(n,sizeof(int));
    return a;
    free(a);
}

void set_value(int* p, int v){
    *p = v;
}

void print_array(int* p, int n){
    printf("[");
    for(int i = 0; i < n-1; i++,p++)    printf("%d, ",*p);
    
    printf("%d]\n",*p);
}

int main(){
    printf("--------------------No.1\n");
    int n = 10;
    int *ip = get_int_array(n);

    for(int i = 0; i < n; i++){
        set_value(ip+i,i+1);
    }
    print_array(ip,n);
    
    printf("--------------------N0.2\n");
    array_list_t n_2;
    n_2.n = 20;
    n_2.func1_ptr = get_int_array;
    n_2.func2_ptr = set_value;
    n_2.func3_ptr = print_array;

    int *ip_2 = n_2.func1_ptr(n_2.n);

    for(int i = 0; i < n_2.n; i++){
        n_2.func2_ptr(ip_2+i,i+1);
    }
    n_2.func3_ptr(ip_2,n_2.n);

    printf("--------------------N0.3\n");

    return 0;
}