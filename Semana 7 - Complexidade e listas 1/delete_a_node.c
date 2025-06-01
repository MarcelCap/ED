SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* n, int pos){
    SinglyLinkedListNode* remov=n;
    SinglyLinkedListNode* end = n;
    while(end->next!=NULL){
        end=end->next;
    }
    if (pos == 0) {
        remov = n;
        n = remov->next;
        if (!n) end = NULL;
    } else {
        SinglyLinkedListNode* anterior = n;
        for (int i = 0; i < pos - 1 ; i++) anterior = anterior->next;
        remov = anterior->next;
        anterior->next = remov->next;
        if (remov == end) end = anterior;
    }
    free(remov);
    return n;
}
