#include <stdio.h>

int f(int x);

int main(void){

    f(1);

    return 0;
}

int f(int x){
    printf("%d\n",x);
    if(x<9)
        f(x+1);
    printf("%d\n",x);
}