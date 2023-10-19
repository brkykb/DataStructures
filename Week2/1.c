#include <stdio.h>

int faktoriyel(int x);

int main(void){

    int x;

    x=5;


    return 0;
}

int faktoriyel(int x){

    if(x==0)
        return 1;

    else{
        return x*faktoriyel(x-1);
    }


}