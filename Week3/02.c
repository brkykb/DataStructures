/* Listeye rastgele uretilmis 100 sayi eklensin, girilen tüm sayilar büyükten küçüge siralayan
ve ekrana basan c kodunu yaziniz. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct example{                                         //struct yapısı

    int number;
    struct example *next;

};
typedef struct example placement;


void menu(void);                                         //menu fonksiyonu
void program(void);                                     //rastgele liste olusturan fonk
void program2(placement *);                              // olusturulan listeyi buyukten kucuge siralayan fonk
void list(placement *);                                 //olusturulan listeyi listeleyen program

int main(){

    menu();


    return 0;
}


void menu(void){

    int secim;

    printf("Rastgele 100 sayi ureten ve girilen tüm sayilari büyükten küçüge siralayan program.");
    printf("1.Programi baslat\n2.Cikis\n");
    scanf("%d",&secim);

    switch(secim){                                                   //menu kismi 
        case 1:
            program();
            break;
        case 2:
            break;
    }
}

void program(void){

    int i;
    placement *head=NULL,*temp;

    srand(time(NULL));

    for(i=0;i<100;i++){                                         //1 den 100 e kadar rastgele sayı olusturur
        if(i==0){                                                 //ilk degeri listeye alir
            head=(placement*)malloc(sizeof(placement));
            head->number=rand();
            temp=head;
            temp->next=NULL;
            i++;
        }
        else{                                                   //diger degerleri listeye ekler
            temp->next=(placement*)malloc(sizeof(placement));
            temp->next->number=rand();
            temp=temp->next;
            temp->next=NULL;
            i++;
        }
    }
    temp=head;
    program2(head);
}

void program2(placement *head){             //siralama fonksiyonu
    placement *temp;
    temp=head;

    int i,x;

    for(i=0;i<1000;i++){                    //bubble sort algoritmasi ile bastan sona surekli tekrar ederek duzenleme yapar
        while(temp->next!=NULL){

            if(temp->number < temp->next->number){              
                x=temp->number;
                temp->number=temp->next->number;
                temp->next->number=x;
                temp=temp->next;
            }
            else{
                temp=temp->next;
            }
        }
        i++;
        temp=head;
    }
    list(head);
}

void list(placement *head){                 //duzenlenen listeyi yazdirir

        while(head!=NULL){
            printf("%d\n",head->number);
            head=head->next;
    }
}