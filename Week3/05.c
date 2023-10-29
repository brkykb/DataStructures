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

list *head=NULL,*temp,*delete;

void menu(void);                            //secimler icin menu fonksiyonu
void createlist(void);                      //liste olusturma fonksiyonu
void search(char[]);                      //ogrenci arama fonksiyonu


int main(void){

    menu();
}

void menu(void){

    int a,deneme,sifre=1234,secenek;
    char name[20];
    
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
                
                printf("Aranacak kelimeyi giriniz");
                scanf("%s",name);
                search(name);
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
void search(char name[20]){                 //ogrenci ismi ile listede arama yapan program

    delete=(list*)malloc(sizeof(list));
    int x;
    temp=head;
    
    while(temp != NULL && temp->next != NULL){
        x= strcmp(temp->next->stdname,name);          // karsilastirma fonksiyonu
        if(x==0){
            printf("Ogrenci Bilgileri\nNumarasi:%d\nAdi:%s\nYasi:%d\n",temp->next->stdnum,temp->next->stdname,temp->next->stdage);
            temp=temp->next;
            delete=temp->next;                   //dugum silme islemi 
            temp->next=temp->next->next;
            free(delete);
            
        }
        else
            temp=temp->next;
    }
    int i=1;
    temp=head;

    while(temp!=NULL){                      //dugum silinen listeyi yazdirir
        printf("%d- %s %d %d\n",i,temp->stdname,temp->stdage,temp->stdnum);
        i++;
        temp=temp->next;
    }
}
