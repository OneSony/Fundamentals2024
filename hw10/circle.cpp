#include<stdio.h>
#include<stdlib.h>

struct Node {
    int id;
    Node* next;
};


Node* create_link(int n){
    Node* head = (Node*)malloc(sizeof(Node));
    head->next = NULL;
    Node* ptr = head;

    for(int i=1; i<=n; i++){
        ptr->next = (Node*)malloc(sizeof(Node));
        ptr = ptr->next;
        ptr->next = NULL;
        ptr->id = i;
    }

    ptr->next = head->next;

    Node* need_to_remove = head;
    head = head->next;
    free(need_to_remove);
    return head;
}

int main(){
    int n,m;
    scanf("%d %d", &n, &m);

    Node* ptr = create_link(n);

    for(;;){
        if(ptr->next == ptr){
            break;
        }

        for(int i=0;i<m-1;i++){
            ptr = ptr->next;
        }

        //printf("%d\n", ptr->id);

        Node* find_parent_ptr = ptr;
        for(;;){
            if(find_parent_ptr->next == ptr){
                break;
            }
            find_parent_ptr = find_parent_ptr->next;
        }
        Node* parent = find_parent_ptr;
        parent->next = ptr->next;

        Node* need_to_remove = ptr;
        ptr = ptr->next;

        free(need_to_remove);
    }

    printf("%d\n", ptr->id);
}