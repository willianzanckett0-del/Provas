#include <stdio.h>
#include <stdlib.h>

// // Lista dupla
struct tld {
    int n;
    struct tld *next, *prev;
};
typedef struct tld Ld;
typedef struct {
    Ld *head;
    Ld *tail;
} Sent;


// // Fila
struct tq {
    int n;
    struct tq *next;
};
typedef struct tq Q;
typedef struct {
    Q *head;
    Q *tail;
} Queue;


// // Pilha
struct ts {
    int n;
    struct ts *next;
};
typedef struct ts S;
typedef struct {
    S *top;
} Stack;

Sent *getDoubly(Stack *p){
    Sent *lista = malloc(sizeof(Sent));
    
    lista->head = NULL;
    lista->tail = NULL;

    while(p->top != NULL){
        S *doughter = p->top;

        Ld *son = malloc(sizeof(Ld)); //Nota: son não vai ser rescritoa assim.

        son->next = NULL;
        son->prev = lista->tail;

        son->n = doughter->n;
        p->top = doughter->next;

        if(lista->head == NULL){
            lista->head = son;
            lista->tail = son;
        }

        else{
            lista->tail->next = son;
        }

        lista->tail = son;

        free(doughter);
    }

    return lista;
}

Queue *getThreeDoubly(Sent *l){
    Queue *aux = malloc(sizeof(Queue));

    aux->head = NULL;
    aux->tail = NULL;

    while(l->head != NULL){
        Ld *auxiliar = l->head;
        l->head = auxiliar->next;

        if(auxiliar->n % 3 ==0){
            Q *xua = malloc(sizeof(Q));

            xua->n = auxiliar->n;

            if(aux->head == NULL){
                aux->head = xua;
                aux->tail = xua;
            }

            else{
                aux->tail->next = xua;
                aux->tail = xua;
            }
        }

        free(auxiliar);
        
    }

    return aux;
}
