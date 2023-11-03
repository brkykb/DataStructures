#include <stdio.h>
#include <stdlib.h>

#define STACK_SİZE 100

typedef struct{                     //stack oluşturuyorum
    char data[STACK_SİZE];
    int top;

}stack;

void initi(stack *);
void push(stack *,char);
void pop(stack *);


void initi(stack *ptr){                     //top değerimi atıyorum
    ptr->top=-1;
}

void push(stack *ptr,char a){               //push fonksiyonu ile gonderilen degeri stack e ekliyorum
    if(ptr->top>=STACK_SİZE-1){
        printf("Stack is full");
    }
    else{
        ptr->top++;
        ptr->data[ptr->top]=a;

    }
}

void pop(stack *ptr){                           //pop fonksiyonu ile top un gosterdigi degeri diliyorum
    if(ptr->top<=-1){
        printf("Stack is empty!");
    }
    else{
        ptr->top--;

    }
}

int main(void){

    FILE *p;                                    //test.txt dosyasından okuma yapıyorum
    p = fopen("test.txt", "r");

    stack *pt;

    int i=0;
    char sample;

    pt = (stack *)malloc(sizeof(stack));
    initi(pt);

    while(fscanf(p,"%c",&sample)!=EOF){                 //dosyanin sonuna gelene kadar tek tek char okuma yapıyorum
        
        if (sample == '{' || sample == '[' || sample == '(') {                  //if kosulu ile char degerinin push operatoru veya pop operatorunu kontrol ediyorum
            push(pt, sample);                                                   //kontorol sonrasi duruma gore push veya pop fonksiyonuna gonderiyorum
        } else if (sample == '}' || sample == ']' || sample == ')') {
            if (pt->top >= 0 &&
                ((pt->data[pt->top] == '{' && sample == '}') ||
                 (pt->data[pt->top] == '[' && sample == ']') ||
                 (pt->data[pt->top] == '(' && sample == ')'))) {
                pop(pt);
            } else {
                printf("Hata:%c",sample);                               //eger yanlis bir parantez islemi ile karsilasirsa hata mesaji vererek donguden cikariyorum
                break;
            }
        }
    }
        
    free(pt);                   //dosyayi kapatip bellegi serbest birakiyorum
    fclose(p);
}