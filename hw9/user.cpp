#include<stdio.h>
#include<stdlib.h>

struct Node{
    int id;
    Node* next;
};

Node* creat_link(int n){

    Node* head = (Node*)malloc(sizeof(Node));
    head->next = NULL;
    Node* ptr = head; //指向尾部

    for(int i=0;i<n;i++){
        ptr->next = (Node*)malloc(sizeof(Node));
        ptr = ptr->next;
        ptr->next = NULL;
        scanf("%d", &(ptr->id));
    }

    Node* need_to_remove = head;
    head = head->next;
    free(need_to_remove);

    return head;
}

Node* add_node(Node* head, int id){

    if(head->id > id){
        Node* new_head = (Node*)malloc(sizeof(Node));
        new_head->id = id;
        new_head->next = head;
        head = new_head;
        return head;
    }

    Node* i;
    for(i = head;;i=i->next){
        if(i->next == NULL || i->next->id > id){
            break;
        }
    }

    Node* tmp = i->next;
    i->next = (Node*)malloc(sizeof(Node));
    i = i->next;
    i->id = id;
    i->next = tmp;
    return head;
}

Node* remove_node(Node* head, int id){

    if(head->id == id){
        Node* new_head = head->next;
        free(head);
        head = new_head;
        return head;
    }

    Node* i;
    for(i = head;;i=i->next){
        if(i->next == NULL || i->next->id == id){
            break;
        }
    }

    if(i->next == NULL){
        return head;
    }

    Node* need_to_free = i->next;
    i->next=need_to_free->next;
    free(need_to_free);

    return head;
}

void print_link(Node* head){
    for(Node* i = head;i!=NULL;i=i->next){
        printf("%d\n", i->id);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    Node* head = creat_link(n);

    int m;
    scanf("%d", &m);
    int id, op;
    for(int i=0;i<m;i++){
        scanf("%d %d", &id, &op);
        if(op==0){
            head = remove_node(head, id);
        }else if(op==1){
            head = add_node(head, id);
        }
    }

    print_link(head);
}