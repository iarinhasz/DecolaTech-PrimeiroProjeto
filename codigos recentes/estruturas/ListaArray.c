//Implementacao arcaica de uma lista
#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int maxTamanho;
    int qntdElementos;
    int cursor;
}Lista;
typedef struct{
    Lista *list;
    int *array;
}Array;
void menu(){
    printf ("Se deseja inserir: 0\nSe deseja remover: 1\nSe deseja saber qual valor se repete mais: 2\nMover cursor para a esquerda: 3\nMover cursor para a direita: 4\nPosicao Atual:5\nCaso queira sair: 6\n");
}
Lista *decrementando(Lista *list){
    (*list).maxTamanho = 12;
    (*list).cursor -=1;
    (*list).qntdElementos -= 1;
    return list;
}
Array *insert(Lista it, Array *v, int inserir){
    printf ("cursor: %d\n", it.cursor);
    int aux = v->array[it.cursor];
        for(int i=it.qntdElementos; i>it.cursor; i--){
            it.qntdElementos++;
            v->array[i] = v->array[i+1];
            v->array[it.qntdElementos-1] = aux; 
            v->array[it.cursor] = inserir;
        }
    return v;
}
Array *remover(Lista it, Array *v, int indRemove){
    it.cursor = indRemove;
    for (int i = it.cursor; i< it.qntdElementos-1;i++){
        v->array[i] = v->array[i+1];
        if(i==it.qntdElementos-2)
            it.qntdElementos--;
    }
    return v;
}
Lista *moverEsq(Lista *it, Array v){
    if(it->cursor == 0) printf ("inacessivel\n"); 
    else{
        printf ("o cursor esta: %d\n", it->cursor);
        it->cursor-=1;
        printf ("Agora o cursor esta na posicao: %d\n", it->cursor);
    }
    return it;
}
Lista *moverDir(Lista *it, Array v){
    if(v.array[it->cursor+1]!=0){
        printf ("o cursor esta: %d\n", it->cursor);
        it->cursor+=1;
        printf ("Agora o cursor esta na posicao: %d\n", it->cursor);
        return it;
    }
    return it;
}
int count(Lista it, Array v, int valor){
    int cont = 0;
    for(int i=0; i<it.qntdElementos;i++){
        if ( valor == v.array[i]){
            cont++;
        }
    }
    return cont;
}

int main(){
    Lista *lista = malloc(sizeof(Lista));
    
    Array *vetor = malloc (sizeof(Array));
    int opcao, valorInsert, valorRemove, comparar;
    menu();
    scanf("%d", &opcao);
    (*lista).maxTamanho = 12;
    (*lista).cursor = 0;
    (*lista).qntdElementos = 0;
    vetor->array[lista->maxTamanho];
    while((*lista).qntdElementos<(*lista).maxTamanho && opcao!=6){
        switch (opcao){
            case 0:
                    (*lista).qntdElementos +=1;
                    printf ("Valor para inserir:\n");
                    scanf ("%d", &valorInsert);
                    insert(*lista, vetor, valorInsert);
                    (*lista).cursor+=1;
                break;
            case 1:
                printf ("indice para remover:\n");
                scanf ("%d", &valorRemove);
                remover(*lista, vetor, valorRemove);
                decrementando(lista);
                break;
            case 2:
                printf("Qual valor voce deseja verificar: ");
                scanf ("%d", &comparar);
                printf ("Ele se repete: %d vezes\n", count(*lista, *vetor, comparar));
                break;
            case 3:
                moverEsq(lista, *vetor);
                break;
            case 4:
                moverDir(lista, *vetor);
                break;
            case 5:
                printf ("Posicao: %d\n", lista->cursor);
                break;
            default:
                opcao = 6;
                break;
        }
        printf ("Nossa lista tem: %d elementos\n", (*lista).qntdElementos);
        for(int i=0; i<(*lista).qntdElementos;i++)
            printf ("%d ", (*vetor).array[i]);
        printf ("\n");
        menu();
        scanf("%d", &opcao);
    }
    printf ("Nossa lista tem: %d elementos\n", (*lista).qntdElementos);
    for(int i=0; i<(*lista).qntdElementos;i++)
        printf ("%d ", (*vetor).array[i]);

    free(lista);
    free(vetor);
    return 0;
}