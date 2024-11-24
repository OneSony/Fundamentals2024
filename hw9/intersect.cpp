#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    Node* next;
};

Node* intersect(Node* head1, Node* head2){
    Node* result = (Node*)malloc(sizeof(Node));
    result->next = NULL;
    Node* ptr = result; //ptr不能指向不存在的对象，不然不能操作，一直指向末尾
    Node* ptr1 = head1;
    Node* ptr2 = head2;

    for(;;){
        if(ptr1 == NULL || ptr2 == NULL){
            break;
        }

        if(ptr1->data < ptr2->data){
            //printf("1: %d %d\n", ptr1->data, ptr2->data);
            ptr1 = ptr1->next;
        }else if(ptr1->data > ptr2->data){
            //printf("2: %d %d\n", ptr1->data, ptr2->data);
            ptr2 = ptr2->next;
        }else{
            //printf("3: %d \n", ptr1->data);
            ptr->next = (Node*)malloc(sizeof(Node));
            ptr = ptr->next;
            ptr->next = NULL;
            ptr->data = ptr1->data;

            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
    }

    Node* need_to_remove = result; //去掉表头
    result = result->next;
    free(need_to_remove);

    return result;
}

int main(){
    int n;
    Node* ptr;

    //head1
    scanf("%d", &n);
    Node* head1 = (Node*)malloc(sizeof(Node));
    head1->next = NULL;
    ptr = head1;

    scanf("%d", &(ptr->data));
    for(int i=1;i<n;i++){
        Node* current = (Node*)malloc(sizeof(Node));
        current->next = NULL;
        ptr->next = current;
        ptr = ptr->next;
        scanf("%d", &(ptr->data));
    }


    //head2
    scanf("%d", &n);
    Node* head2 = (Node*)malloc(sizeof(Node));
    head2->next = NULL;
    ptr = head2;

    scanf("%d", &(ptr->data));
    for(int i=1;i<n;i++){
        Node* current = (Node*)malloc(sizeof(Node));
        current->next = NULL;
        ptr->next = current;
        ptr = ptr->next;
        scanf("%d", &(ptr->data));
    }


    Node* result = (Node*)malloc(sizeof(Node));

    result = intersect(head1, head2);

    for(Node* i = result;i!=NULL;i=i->next){
        printf("%d ", i->data);
    }
    printf("\n");
}