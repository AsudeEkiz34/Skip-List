
////
//  main.c
//  DataStructuresAssignment1
//  Created by Asude Ekiz on 27.03.2022.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 20
typedef struct node{
    int data;
    struct node* next;
    struct node* below;
}NODE;


NODE* createNode(int data);
void insertByKey(NODE **head, int data);
void printNode(NODE *n);
void printLinkedList(NODE *head);
void swap(int *a, int *b) ;
int* sortList(int randList[],int n);
//void printRandomList(int randList[MAX],int n);
void deneme(int z,int *rand);
void printLinkedListbyArray(NODE**headptr, int stair);
void recursiveMakeLinkedLists(int stair,int n,NODE **headptr,int *rand,int* dizi);
void compareAndConnect(int stair,NODE **headptr);
int * MakingSortedRandArray(int n);
void searchData(NODE **headptr, int n,int data);
void deleteList(NODE **headptr,int n);
int main(int argc, const char * argv[]) {
    int choose=-1;
      printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
      printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
      printf("\n\t\t\t        =          Fast Linked List Program         =");
      printf("\n\t\t\t        =         created by Asude Merve Ekiz       =");
      printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
      printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    
    
    int i,n;
    printf("Lutfen temel dizinin eleman sayisini giriniz.\n");
    scanf("%d",&n);
    
    int step=n/2; //basamak ADEDİ
    int stair=0;//taban 0 zaten hazir, tabandan bir yukarda olmak uzere dizide de kullanılacak kacinci basamak oldugunu belirten variable
    
    int *rand_indis;
    rand_indis=(int*)calloc(n/2, sizeof(int));
    int *dizi;
    dizi=(int*)calloc(n, sizeof(int));
    
    NODE **headptr=(NODE**)calloc(step,sizeof(NODE*));//tum headleri tutan cift pointer arrayi
    //headler olusturuldu
    //bu gosterimde tum headlerin de datası 0 olarak belirtilmistir.
    //yani dizinin ilk  0 ı headi gosteriyor ondan sonraki elemanlar dizinin kendisi
    NODE *head0=(NODE*)calloc(1, sizeof(NODE));//ilk dizinin headi
    NODE *head1=(NODE*)calloc(1, sizeof(NODE));//bir ust basamak headi
    NODE *head2=(NODE*)calloc(1, sizeof(NODE));//bir ust basamak headi
    NODE *head3=(NODE*)calloc(1, sizeof(NODE));//bir ust basamak headi
    NODE *head4=(NODE*)calloc(1, sizeof(NODE));//bir ust basamak headi
    NODE *head5=(NODE*)calloc(1, sizeof(NODE));//bir ust basamak headi
    
    //headleri tutan diziye atamalar yapıldı.
    headptr[0]=head0;
    headptr[1]=head1;
    headptr[2]=head2;
    headptr[3]=head3;
    headptr[4]=head4;
    headptr[5]=head5;

    printf("Eleman girisi:\n");
    for (i=0; i<n; i++) {
        printf("Lutfen %d. elemani girin: ",i+1);
        scanf("%d",&dizi[i]);
    }
    
    printf("Girdiginiz dizi: \n\n");
    for (i=0; i<n; i++) {
        printf("%d ",dizi[i]);
    }
    printf("\n\n");
 
    while(choose!=5){
        printf("=================== Yapmak Istediginiz Islemi Seciniz =====================\n");
        printf("1)Hizli Linkli Liste Yapisi Olusturma\n");
        printf("2)Mevcut Veri Yapisina Ekleme Islemi \n");
        printf("3)Mevcut Veri Yapisindan Silme Islemi \n");
        printf("4)Veri Yapisinda Arama İslemi \n");
        printf("5)Cıkis\n");
        printf("NOT:Arama islemi yapmadan once 1 numarali secenek ile Hizli Linkli Liste Yapisi Olusturulmalidir.\n");
        printf("Secim: ");
        scanf("%d",&choose);
        if(choose==1){
        
            for (i=0; i<n; i++) {
                insertByKey(&(head0->next), dizi[i]);
            }
            
            printf("\n1.seviye linkli dizi asagidaki gibidir:\n");
           
            printLinkedList(head0->next);
            printf("\n");
            rand_indis=MakingSortedRandArray(n);
       
            printf("\n");
            stair++;
            
            recursiveMakeLinkedLists(stair, n, headptr, rand_indis, dizi);
            printf("\n");
            printf("\nFast Link List Veri Yapisi asagidaki gibidir:\n");
            
            printLinkedList(head5->next);
            printf("\n");
            printLinkedList(head4->next);
            printf("\n");
            printLinkedList(head3->next);
            printf("\n");
            printLinkedList(head2->next);
            printf("\n");
            printLinkedList(head1->next);
            printf("\n");
            printLinkedList(head0->next);
            printf("\n\n\n");
            
            //printf("KONTROLLER: \n");
           // printf("headptr[3]->next->below: %d\n",headptr[3]->next->below->data); //7
            //printf("headptr[3]->next->below->next: %d\n",headptr[3]->next->below->next->data);//9
            //printf("headptr[3]->next->below->next->below->below->data%d",headptr[3]->next->below->next->below->below->data);
            
        }

        else if(choose==2){
            int x;
            printf("Dizinin mevcut durumu asagidaki gibidir.\n");
            int i;
            for (i=0; i<n; i++) {
                printf("%d ",dizi[i]);
            }
            printf("Eklemek istediginiz elemani giriniz:\n");
            scanf("%d",&x);
            
            int *newdizi=calloc(n+1, sizeof(int));
            for (i=0; i<n; i++) {
                newdizi[i]=dizi[i];
            }
          
            newdizi[n]=x;
            sortList(newdizi, n+1);
            printf("Veri eklenmis dizinin mevcut durumu asagidaki gibidir.\n");
            for (i=0; i<n+1; i++) {
                printf("%d ",newdizi[i]);
            }
            
            NODE **newheadptr=(NODE**)calloc(step,sizeof(NODE*));//tum headleri tutan YENI cift pointer arrayi
            //headler olusturuldu
            //bu gosterimde tum headlerin de datası 0 olarak belirtilmistir.
            //yani dizinin ilk  0 ı headi gosteriyor ondan sonraki elemanlar dizinin kendisi
            NODE *newhead5=(NODE*)calloc(1, sizeof(NODE));//ilk dizinin headi
            NODE *newhead4=(NODE*)calloc(1, sizeof(NODE));//bir ust basamak headi
            NODE *newhead3=(NODE*)calloc(1, sizeof(NODE));//bir ust basamak headi
            NODE *newhead2=(NODE*)calloc(1, sizeof(NODE));//bir ust basamak headi
            NODE *newhead1=(NODE*)calloc(1, sizeof(NODE));//bir ust basamak headi
            NODE *newhead0=(NODE*)calloc(1, sizeof(NODE));//bir ust basamak headi

            //headleri tutan diziye atamalar yapıldı.
            newheadptr[0]=newhead0;
            newheadptr[1]=newhead1;
            newheadptr[2]=newhead2;
            newheadptr[3]=newhead3;
            newheadptr[4]=newhead4;
            newheadptr[5]=newhead5;

            for (i=0; i<n; i++) {
                insertByKey(&(newhead0->next), newdizi[i]);
            }

            //printf("\n1.seviye linkli dizi asagidaki gibidir:\n");

            //printLinkedList(newhead0->next);

            printf("\n");
            rand_indis=MakingSortedRandArray(n);

            printf("\n");
            stair++;

            recursiveMakeLinkedLists(stair, n, newheadptr, rand_indis, newdizi);
            printf("\n");
            printf("\nEkleme yapilmis Fast Link List Veri Yapisi asagidaki gibidir:\n");

            printLinkedList(newhead5->next);
            printf("\n");
            printLinkedList(newhead4->next);
            printf("\n");
            printLinkedList(newhead3->next);
            printf("\n");
            printLinkedList(newhead2->next);
            printf("\n");
            printLinkedList(newhead1->next);
            printf("\n");
            printLinkedList(newhead0->next);
            printf("\n\n\n");
 
            
        }
        else if(choose==3){
            int y;
            int bayrak=0;
            printf("Silmek istediginiz elemani giriniz:\n");
            scanf("%d",&y);
            i=0;
            while (i<n && bayrak!=1) {
                if (dizi[i]==y) {
                    bayrak=1;
                    dizi[i]=100;//max deger atanarak sort sonucunda dizinin sonuna gitmesi hedeflendi
                }
                i++;
                }
            if (bayrak==1) {
                printf("Deger bulundu ve silindi.\n");
                sortList(dizi, n);
                n=n-1;
                int *newV2dizi=calloc(n, sizeof(int));
                for (i=0; i<n; i++) {
                    newV2dizi[i]=dizi[i];
                }
                printf("Yeni dizi asagidaki gibidir:\n");
                for (i=0; i<n; i++) {
                    printf("%d ",newV2dizi[i]);
                }
                printf("\n");
                
                NODE **newV2headptr=(NODE**)calloc(step,sizeof(NODE*));//tum headleri tutan YENI cift
                NODE *newV2head5=(NODE*)calloc(1, sizeof(NODE));//ilk dizinin headi
                NODE *newV2head4=(NODE*)calloc(1, sizeof(NODE));//bir ust basamak headi
                NODE *newV2head3=(NODE*)calloc(1, sizeof(NODE));//bir ust basamak headi
                NODE *newV2head2=(NODE*)calloc(1, sizeof(NODE));//bir ust basamak headi
                NODE *newV2head1=(NODE*)calloc(1, sizeof(NODE));//bir ust basamak headi
                NODE *newV2head0=(NODE*)calloc(1, sizeof(NODE));//bir ust basamak headi

                //headleri tutan diziye atamalar yapıldı.
                newV2headptr[0]=newV2head0;
                newV2headptr[1]=newV2head1;
                newV2headptr[2]=newV2head2;
                newV2headptr[3]=newV2head3;
                newV2headptr[4]=newV2head4;
                newV2headptr[5]=newV2head5;

                for (i=0; i<n; i++) {
                    insertByKey(&(newV2head0->next), newV2dizi[i]);
                }

                //printf("\n1.seviye linkli dizi asagidaki gibidir:\n");

                //printLinkedList(newV2head0->next);
                rand_indis=MakingSortedRandArray(n);
                printf("\n");
                stair++;

                recursiveMakeLinkedLists(stair, n, newV2headptr, rand_indis, newV2dizi);
                printf("\n");
                printf("\nSilme islemi yapilmis Fast Link List Veri Yapisi asagidaki gibidir:\n");

                printLinkedList(newV2head3->next);
                printf("\n");
                printLinkedList(newV2head2->next);
                printf("\n");
                printLinkedList(newV2head1->next);
                printf("\n");
                printLinkedList(newV2head0->next);
                printf("\n\n\n");
     
              
            }
            else{
                printf("Silinmek istenen deger dizide zaten bulunmuyor.\n");
            }
           
    
            }
        else if (choose==4){
            printf("Aramak istediginiz degeri giriniz: \n");
            int aranan;
            scanf("%d",&aranan);
            searchData(headptr, n, aranan);
        }
       
        printf("\n_____________________________________________________________________\n                      RETURNING THE MAIN MENU               _____________________________________________________________\n\n");
        }

    
    return 0;
}

NODE* createNode(int data){
    NODE *tmp;
    tmp=(NODE*)malloc(sizeof(NODE));
    tmp->data=data;
    tmp->next=NULL;
    return tmp;
}

void insertByKey(NODE **head, int data){
    NODE *tmp;
    NODE *newNode=createNode(data);
    if (*head==NULL) {
        newNode->next=*head;
        *head=newNode;
    }
    else{
        tmp=*head;
        while (tmp->next!=NULL && tmp->next->data<data) {
            tmp=tmp->next;
        }
        if (tmp->next==NULL) { //sona gelmisiz bu yuzden node'u en sona ekleyecegiz
            tmp->next=newNode;
            newNode->next=NULL;
        }
        else{//sona gelmemisiz arada bir yere node'u koyacagiz.
            newNode->next=tmp->next;
            tmp->next=newNode;
        }
    }
}

void printNode(NODE *n){
    printf("|%d|--",n->data);
}

void printLinkedListbyArray(NODE**headptr,int stair){
    NODE* tmp;
    tmp=headptr[stair];
    while (tmp!=NULL) {
        printNode(tmp);
        tmp=tmp->next;
    }
}

void printLinkedList(NODE *head){
    NODE *tmp;
    tmp=head;
    while (tmp!=NULL) {
        printNode(tmp);
        tmp=tmp->next;
    }
}

void compareAndConnect(int stair,NODE **headptr){
    //headleri dısarda bagla
    NODE* tmp_ust=headptr[stair]->next; //ilk datalı node u tmp uste attik
    NODE* tmp_alt;
    while (tmp_ust!=NULL) {
        tmp_alt=headptr[stair-1]->next; //asagidaki pointerı da head[stair-1] olan listenin ilk datalı nodeuna koyduk
        while (tmp_alt!=NULL) {
            if (tmp_ust->data==tmp_alt->data) {
                tmp_ust->below=tmp_alt;
            }
            tmp_alt=tmp_alt->next;
        }
        tmp_ust= tmp_ust->next;
    }
}


void  recursiveMakeLinkedLists(int stair,int n,NODE **headptr,int *rand,int* dizi){
    
    int * rand_new=(int *)calloc(n/2, sizeof(int));
    int * rand_tmp=NULL; //icerdeki rand indis bu
    if ((n/2)==0) {
        printf("Son basamaga cikildi, recursive func bitti.\n");
       
    }
    else{
        int i;
        for (i=0; i<n/2; i++) {
            rand_new[i]=dizi[rand[i]];
        }
        sortList(rand_new, n/2);
        for (i=0; i<n/2; i++) {
            printf("%d ",rand_new[i]);
        }
        //rand new dedeigimiz sey ise yeni dizi olarak gordugumuz sey
        printf("\n");
        for (i=0; i<n/2; i++) {
            insertByKey(&(headptr[stair])->next, rand_new[i]);
            //icine rand_new[i] deki datalari koyarak n/2 adedince yeni node olusturup birbirine bagladi.
         //ama su an o iki kat birbirinden ayri durumda
        }
        printf("\n %d.kattaki linked list olusturuldu.\n",stair+1);
        //stair fonk buraya ilk girdiginde 1, cunku 0. katı disarda olusturduk.
        headptr[stair]->below=headptr[stair-1];//headleri bagladik
        //simdi bulundugumuz kattaki nodelarla bi asagidakilerin datasi aynı olanlarini baglayacagiz
        compareAndConnect(stair, headptr);
        n=n/2;//
        rand_tmp=(int*)calloc(n/2, sizeof(int));
        rand_tmp=MakingSortedRandArray(n); //icerdeki rand indisim
        stair++;
        recursiveMakeLinkedLists(stair, n, headptr, rand_tmp, rand_new);
     

        
    }
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
};


int* sortList(int randList[],int n){
    int step;
    for (step = 0; step < n- 1; step++) {
      int min_idx = step;
      for (int i = step + 1; i < n; i++) {

        // To sort in descending order, change > to < in this line.
        // Select the minimum element in each loop.
        if (randList[i] < randList[min_idx])
          min_idx = i;
      }

      // put min at the correct position
      swap(&randList[min_idx], &randList[step]);
    }
    return randList;
}




int * MakingSortedRandArray(int n){
    int * randArray=(int*)calloc(n/2, sizeof(int));
    int random;
    int uniqueflag;
    int i, j;
    for(i = 0; i < n/2; i++) {
         do {
            /* Assume things are unique... we'll reset this flag if not. */
            uniqueflag = 1;
            random = rand() % n;
            /* This loop checks for uniqueness */
            for (j = 0; j < i && uniqueflag == 1; j++) {
               if (randArray[j] == random) {
                  uniqueflag = 0;
               }
            }
         } while (uniqueflag != 1);
        randArray[i] = random;
    }
    sortList(randArray, n/2);
    return randArray;
}



int* addToArray(int *dizi, int n,int x){
    dizi=realloc(dizi, n+1);
    int i,j;
    i=0;
    while ((i<=n)&&(x>=dizi[i])) {
        i=i+1;
    }
   
    for (j=n-1; (j>=i); j--) {
        dizi[j+1]=dizi[j];
    }
    dizi[i]=x;
    return dizi;
    
}

void searchData(NODE **headptr, int n,int data){
    int kat;
    kat=log2(n);
    int flag=0;
    NODE *tmp;
    tmp=headptr[kat];
    while (kat!=-1 && flag!=1) {
        while (tmp!=NULL && flag!=1) {
            if (tmp->data!=data) {
                tmp=tmp->next;
            }
            else {
                printf("Data %d. katta bulundu, degeri %d\n",kat,tmp->data);
                flag=1;
                }
            }
       
            kat--;
            tmp=headptr[kat];
        
        }
    if (flag==1) {
        printf("Data bulundugu icin cıkıldı.\n");
    }
    else
        printf("Data bu listede bulunamadi.\n");
}

void deleteList(NODE **headptr,int n){
    int stair=log2(n);
    NODE *tmp=NULL;
    NODE *tmp2=NULL;
    
    int i;
    for (i=0; i<=stair; i++) {
        tmp=headptr[i]->next;
        tmp2=headptr[i]->next;
        while (tmp!=NULL) {
            tmp=tmp->next;
            tmp2=NULL;
            tmp2=tmp;
            }
        printf("%d.kat temizlendi\n",i);
    }
}

