#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    Node* next;
};

Node* removeDuplicates(Node* head){

    Node* parent = head;
    for(Node* i = head->next;i!=NULL;i=i->next){
        if(i->data == parent->data){
            //remove i
            parent->next = i->next;
            free(i);
            i = parent;
        }else{
            parent = i;
        }
    }

    return head;
}

int main(){
    int n;
    scanf("%d", &n);

    Node* head = (Node*)malloc(sizeof(Node));
    head->next = NULL;
    Node* ptr = head;

    scanf("%d", &(ptr->data));

    for(int i=1;i<n;i++){
        Node* current = (Node*)malloc(sizeof(Node));
        current->next = NULL;
        ptr->next = current;
        ptr = ptr->next;
        scanf("%d", &(ptr->data));
    }

    head = removeDuplicates(head);

    for(Node* i = head;i!=NULL;i=i->next){
        printf("%d ", i->data);
    }
    printf("\n");
}