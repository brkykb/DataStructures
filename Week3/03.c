#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct program{                 //struct yapısı
    int stdnum;
    char stdname[20];
    int stdage;
    struct program *next;
};  
typedef struct program list;

list *head=NULL,*temp;

void menu(void);
void createlist(void);
void listshow(void);

int main(void){

    menu();
}

void menu(void){

    int a,deneme,sifre=1234,secenek;
    
    printf("Ogrenci Numarasi, İsim ve Yasini yazan ve sayan program");

    while(1){
        printf("1.Yonetici girisi\n2.Ogrenci girisi\n3.Cikis\n");       //secim kismi
        scanf("%d",&a);                                             //yonetici liste yapabilir, ogrenci girisi listeyi goruntuleyebilir

        switch(a){
            case 1:
                printf("Sifre giriniz:  (sifre:1234)");             //test sifresi
                scanf("%d",&deneme);
                if(deneme==sifre){
                    printf("Sifre dogru\n");
                    printf("Liste olusturmak icin 1 cikis icin 2 giriniz");
                    scanf("%d",&secenek);
                    switch(secenek){
                        case 1:
                            createlist();
                            break;
                        case 2:
                            exit(0);
                    }
                    break;
                }
                else
                    printf("Sifre Yanlis! Lutfen tekrar deneyiniz");
                
            case 2:
                
                listshow();
                break;

            case 3:
                exit(0);   
        }
    }
}

void createlist(void){

    int deger,i=0,number,age;
    char name[20];

    printf("Kac deger gireceginizi yaziniz");               //liste olusturma kismi
    scanf("%d",&deger);

    while(i<deger){                                         //ogrenci degerlerini alma
        printf("Ogrenci numarasini giriniz:");
        scanf("%d",&number);

        printf("Ogrenci adini giriniz: ");
        scanf("%s",name);

        printf("Ogrenci yasini giriniz: ");
        scanf("%d",&age);

        if(i==0){                                   //linked list kismini olusturma
            head=(list*)malloc(sizeof(list));
            temp=head;
            strcpy(temp->stdname,name);
            temp->stdnum=number;
            temp->stdage=age;
            temp->next=NULL;
            i++;

        }
        else{
            temp->next=(list*)malloc(sizeof(list));
            temp=temp->next;
            strcpy(temp->stdname,name);
            temp->stdnum=number;
            temp->stdage=age;
            temp->next=NULL;
            i++;
        }
    }
}
void listshow(void){            //listeyi goruntuleme 
    
    int i=1;
    temp=head;

    while(temp!=NULL){
        printf("%d- %s %d %d\n",i,temp->stdname,temp->stdage,temp->stdnum);
        i++;
        temp=temp->next;
    }
}