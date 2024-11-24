#include<stdio.h>
#include<stdlib.h>

struct Node{
    int coef;
    int power;
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
        scanf("%d %d", &(ptr->coef), &(ptr->power));
    }

    Node* need_to_remove = head;
    head = head->next;
    free(need_to_remove);

    return head;
}

Node* add_link(Node* head1, Node* head2){
    Node* result = (Node*)malloc(sizeof(Node));
    result->next = NULL;
    Node* ptr = result; //ptr不能指向不存在的对象，不然不能操作，一直指向末尾
    Node* ptr1 = head1;
    Node* ptr2 = head2;

    for(;;){
        if(ptr1 == NULL || ptr2 == NULL){
            break;
        }

        ptr->next = (Node*)malloc(sizeof(Node));
        ptr = ptr->next;
        ptr->next = NULL;

        if(ptr1->power < ptr2->power){
            //printf("1: %d %d\n", ptr1->power, ptr2->power);
            ptr->coef = ptr1->coef;
            ptr->power = ptr1->power;

            ptr1 = ptr1->next;
        }else if(ptr1->power > ptr2->power){
            //printf("2: %d %d\n", ptr1->data, ptr2->data);
            ptr->coef = ptr2->coef;
            ptr->power = ptr2->power;

            ptr2 = ptr2->next;
        }else{
            //printf("3: %d \n", ptr1->data);
            ptr->coef = ptr1->coef + ptr2->coef;
            ptr->power = ptr1->power;

            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
    }

    for(;;){
        if(ptr1==NULL){
            break;
        }

        ptr->next = (Node*)malloc(sizeof(Node));
        ptr = ptr->next;
        ptr->next = NULL;

        ptr->coef = ptr1->coef;
        ptr->power = ptr1->power;

        ptr1 = ptr1->next;
    }

    for(;;){
        if(ptr2==NULL){
            break;
        }

        ptr->next = (Node*)malloc(sizeof(Node));
        ptr = ptr->next;
        ptr->next = NULL;

        ptr->coef = ptr2->coef;
        ptr->power = ptr2->power;

        ptr2 = ptr2->next;
    }

    Node* need_to_remove = result; //去掉表头
    result = result->next;
    free(need_to_remove);

    return result;
}

void print_link(Node* head){
    int count=0;
    for(Node* i = head;i!=NULL;i=i->next){
        if(i->coef!=0){
            count++;
        }
    }
    printf("%d\n", count);

    for(Node* i = head;i!=NULL;i=i->next){
        if(i->coef!=0){
            printf("%d %d\n", i->coef, i->power);
        }
    }
}

int main(){
    int n1, n2;
    scanf("%d", &n1);
    Node* head1 = creat_link(n1);

    scanf("%d", &n2);
    Node* head2 = creat_link(n2);

    Node* result = add_link(head1, head2);

    print_link(result);
}