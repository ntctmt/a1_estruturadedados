#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura do nó da lista encadeada
struct Node {
    int data;
    struct Node* next;
};

// Definindo o tipo TLista como um ponteiro para struct Node
typedef struct Node* TLista;

// Função para inserir um novo elemento no início da lista
void insertAtBeginning(TLista* head_ref, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Função para criar uma lista encadeada a partir de um vetor
TLista constroi(int n, int *v) {
    TLista head = NULL;

    // Inserindo elementos do vetor na lista encadeada na ordem inversa
    for (int i = n - 1; i >= 0; i--) {
        insertAtBeginning(&head, v[i]);
    }

    return head;
}

// Função para imprimir os elementos de uma lista
void printList(TLista head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    int arr[] = {3, 8, 12, 5, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Criando uma lista encadeada a partir do vetor
    TLista myList = constroi(n, arr);

    printf("Lista Criada a partir do Vetor: ");
    printList(myList);

    return 0;
}
