#include <stdio.h>
#include <stdlib.h>

#define max 200

int heap[max];
int size = 0;

void heapifyUp(){ // Se creaza minHeap-ul
    int i = size;

    while(1){
        int parent = i/2;
        if (parent > 0 && heap[parent] > heap[i]){
            int t = heap[parent];
            heap[parent] = heap[i];
            heap[i] = t;
            i = parent;
        } else {
            break;
        }
    }

}


void insert(int key){ //Se creaza de fiecare cate un spatiu in plus pentru fiecare numar adaugat

    size = size + 1;
    heap[size] = key;
    heapifyUp();
}

int returnNumber(){ // Se intreaba daca exista un numar cautat in heap
    int ok = 0;
    int number;
    int i = 1;
    printf("Give the number you want");
    scanf("%d", &number);

    while( i <= size && ok == 0){
        if(heap[i] == number)
            ok=1;
            else i++;}
        if(ok==1)
            printf("Da");
        else
            printf("Nu");

}


int deleteNumber(){ // Daca elementul se afla in vector se sterge,
                    //altfel vectorul ramane neschimbat si se afiseaza mesaj

    int value;
    int k = 0;
    int i = 1;
    printf("\nGive the number you want to delete");
    scanf("%d", &value);
    for(i=1; i<=size;i++ ){
        if(heap[i] == value){
            i=i+1;
            k=k+1;
        }
         if(heap[i]!=value&&i<=size){
            printf("%d ", heap[i]);
         }
        }
        if(k==0){
            printf("Vectorul a ramas nemodificat, valoarea dorita nu se afla in vector");

        }

}

void printMinHeap(){  // Afisarea MinHeap-ului
    int i = 1;
    while(i <= size){
        printf("%d ", heap[i]);
        i++;
    }
    printf("\n");
}

int main() // Se pot insera oricate numere se doresc dar trebuie
           //de fiecare data introdus in functia main, insert(numar_dorit)
{ // Se insereaza cate un numar
    insert(10);
    insert(15);
    insert(30);
    insert(5);
    insert(3);
    insert(14);
    insert(7);
    insert(11);
    insert(2);
    insert(50);
    insert(25);
    insert(13);
    printf("The MinHeap is:");
    printMinHeap();
    returnNumber();
    deleteNumber();


    return 0;
}
