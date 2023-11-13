#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura do nó da lista encadeada
struct Node {
    int data;
    struct Node* next;
};

// Função para inserir um novo elemento no início da lista
void insertAtBeginning(struct Node** head_ref, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Função para inverter uma lista encadeada em uma nova lista
struct Node* reverseList(struct Node* head) {
    struct Node* new_head = NULL; // Cria a nova lista vazia

    // Percorre a lista original e insere cada elemento no início da nova lista
    while (head != NULL) {
        insertAtBeginning(&new_head, head->data);
        head = head->next;
    }

    return new_head;
}

// Função para imprimir os elementos de uma lista
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* originalList = NULL;

    // Populando a lista original
    insertAtBeginning(&originalList, 1);
    insertAtBeginning(&originalList, 2);
    insertAtBeginning(&originalList, 3);
    insertAtBeginning(&originalList, 4);
    insertAtBeginning(&originalList, 5);

    printf("Lista Original: ");
    printList(originalList);

    // Invertendo a lista original em uma nova lista
    struct Node* reversedList = reverseList(originalList);

    printf("Lista Invertida: ");
    printList(reversedList);

    return 0;
}
