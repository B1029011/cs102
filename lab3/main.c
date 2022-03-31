#include<stdio.h>

int my_strlen(char* s){
    int i =0;
    while(s[i] != '\0')
        i++;
    return i;
}

int rec_strlen(char* s,int* i){
    
}

char* my_sort(char* s){
    char save;
    for(int i = 0; i < my_strlen(s); i++){
        for( int j = 0; j < my_strlen(s); j++){
            if(s[j] > s[i]){
                save = s[i];
                s[i] = s[j];
                s[j] = save;
            }
        }
    }
    return s;
}

int main(){
    char s[] = "IU is a girl!";
    printf("len = %d\n", my_strlen(s));
    //printf("len = %d\n", rec_strlen(s.0));
    printf("sort = %s\n", my_sort(s));
    return 0;
 }