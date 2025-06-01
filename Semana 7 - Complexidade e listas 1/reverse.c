SinglyLinkedListNode* reverse(SinglyLinkedListNode* n){
    SinglyLinkedListNode* end = n;
    while(end->next!=NULL){
        end=end->next;
    }
    SinglyLinkedListNode* anterior = NULL;
    SinglyLinkedListNode* atual = n;
    SinglyLinkedListNode* proximo = NULL;
    end = n; // O antigo início se tornará o novo final

    while (atual) {
        proximo = atual->next;
        atual->next = anterior;
        anterior = atual;
        atual = proximo;
    }

    n = anterior;
    return n;
}
