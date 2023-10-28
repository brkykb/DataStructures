/*Klavyeden -1 girilinceye kadar, girilen tüm tek sayilari listenin basina, 
cift sayilari ise listenin sonuna ekleyen fonksiyonu yaziniz.*/

#include <stdio.h>
#include <stdlib.h>
void menu(void);
void program(void);

struct node{                            //struct olusturma

    int data;
    struct node *next;
};

typedef struct node list;

int main(void){

    menu();

    return 0;
}

void menu(){
    int a;

    printf("Klavyeden -1 girilinceye kadar, girilen tüm tek sayilari listenin basina, cift sayilari ise listenin sonuna ekleyen fonksiyon.\n\n");
    printf("1.Programi Baslat\n2.Cikis\n");
    scanf("%d",&a);

    switch(a){
        case 1:
            program();                  //tek sayiları liste basina, cift sayilari liste sonuna ekleyen fonskiyon
            break;
        case 2:
            break;
    }
}

void program(void){

    list *head=NULL,*temp,*node=NULL;

    while(1){
        node=(list*)malloc(sizeof(list));                       
        printf("Sayi giriniz: ");
        scanf("%d",&node->data);

        if(node->data==-1){                                     //-1 girilene kadar devam eder
            temp=head;
            while(temp!=NULL){
    
                printf("%d\n",temp->data);
                temp=temp->next;
            }
            break;
        }
        else{
            
            if(head==NULL){                                     //ilk elemanin listeye eklenmesi
                    head=(list*)malloc(sizeof(list));
                    head->data=node->data;
                    temp=head;
                    temp->next=NULL;
                }
            else{
                
                if(node->data%2==0){                            //listenin sonuna eklenecek sayilari bulur ve ekler

                    while(temp->next!=NULL){
                        temp=temp->next;
                    }
                    temp->next=(list*)malloc(sizeof(list));

                    temp->next->data=node->data;
                    temp->next->next=NULL;
                    temp=head;
                        
                }
                else{                                           // listenin basina eklenicek sayilari bulur ve ekler

                    node->next=head;
                    head=node;
                    temp=head; 
                }
            }
        }
    }
}

