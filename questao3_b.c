#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da lista duplamente encadeada
struct lista {
    int info;
    struct lista* prox;
    struct lista* ant;
};
typedef struct lista TLDE;

// Função para criar um novo nó
TLDE* createNode(int data) {
    TLDE* newNode = (TLDE*)malloc(sizeof(TLDE));
    newNode->info = data;
    newNode->prox = NULL;
    newNode->ant = NULL;
    return newNode;
}

// Função para inserir um nó no início da lista
TLDE* inserir(TLDE* l, int info) {
    TLDE* newNode = createNode(info);
    
    if (l == NULL) {
        return newNode;
    }
    
    newNode->prox = l;
    l->ant = newNode;
    
    return newNode;
}

// Função para excluir um nó da lista
TLDE* excluir(TLDE* l, int info) {
    TLDE* current = l;
    
    while (current != NULL) {
        if (current->info == info) {
            // Se o nó a ser excluído estiver no meio da lista
            if (current->ant != NULL) {
                current->ant->prox = current->prox;
            }
            // Se o nó a ser excluído for o primeiro nó da lista
            if (current == l) {
                l = current->prox;
                if (l != NULL) {
                    l->ant = NULL;
                }
            }
            free(current);
            return l;
        }
        current = current->prox;
    }
    
    // Elemento não encontrado, retorna a lista original
    return l;
}

// Função para exibir a lista do início ao fim
void displayForward(TLDE* head) {
    TLDE* current = head;
    while (current != NULL) {
        printf("%d -> ", current->info);
        current = current->prox;
    }
    printf("NULL\n");
}

int main() {
    TLDE* head = NULL;
    
    // Inserir elementos no início da lista
    head = inserir(head, 3);
    head = inserir(head, 2);
    head = inserir(head, 1);
    
    printf("Lista Encadeada (do início ao fim): ");
    displayForward(head);
    
    // Excluir o elemento 2 da lista
    head = excluir(head, 2);
    
    printf("Lista Encadeada após a exclusão: ");
    displayForward(head);
    
    return 0;
}
