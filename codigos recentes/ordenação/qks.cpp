#include<iostream>
using namespace std;

int partHoore(int A[], int inicio, int final){
    int pivo = A[inicio];
    int i = inicio, j = final + 1, aux = 0;
    //decrescente
    while (i<=j){
        while(A[i]>=pivo && i<=j){
            i++;
        }
        while(A[j]<=pivo && j>=i){
            j--;
        }
        //troca
        aux = A[j];
        A[j] = A[i];
        A[i] = aux;
    }   
    //se o i ultrapassar o j tem que destrocar:
    aux = A[i];
    A[i] = A[j];
    A[j] = aux;
    /*crescente
    while (i<=j){
        while(A[i]<=pivo && i<=j){
            i++;
        }
        while(A[j]>=pivo && j>=i){
            j--;
        }
        //troca
        aux = A[i];
        A[i] = A[j];
        A[j] = aux;
    } 
    aux = A[j];
    A[j] = A[i];
    A[i] = aux;
    */
    //e o valor do inicio vai para o lugar  do j:
    aux = A[j];
    A[j] = A[inicio];
    A[inicio] = aux;

    return j;
}
void quickSort(int A[], int inicio, int final){
    if (final>inicio){
        int pivo = partHoore(A, inicio, final);
        quickSort(A, inicio, pivo-1);
        quickSort(A, pivo+1, final);
    }
}
int main(){
    int Array[10] = {4,19,10,11,1,9,16,17,18,7};
    int final = 10, inicio = 0;
    quickSort(Array, inicio, final-1);
    for(int i = 0; i<final;i++) printf("%d ", Array[i]);
    return 0;
}