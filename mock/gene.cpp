#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node{
    char base[3];
    Node* next;
};

void add(Node* head, char* base){
    Node* ptr = head;
    Node* first_last = NULL;
    Node* second_last = NULL; 
    for(;;){
        if(ptr->next == NULL){
            break;
        }
        ptr = ptr->next;
        second_last = first_last;
        first_last = ptr;
    }

    ptr->next = (Node*)malloc(sizeof(Node));
    ptr = ptr->next;
    ptr->next = NULL;
    strcpy(ptr->base, base);

    if(first_last!=NULL && second_last!=NULL){

        //最后3个ptr, first, seconde
        if(strcmp(ptr->base, "TA")==0 && strcmp(first_last->base, "TA")==0 && strcmp(second_last->base, "TA")==0){
            strcpy(ptr->base, "CG");
            strcpy(first_last->base, "CG");
            strcpy(second_last->base, "CG");
        }else if(strcmp(ptr->base, first_last->base)!=0 && strcmp(ptr->base, second_last->base)!=0 && strcmp(first_last->base, second_last->base)!=0){
            if(strcmp(ptr->base, "CG")!=0 && strcmp(first_last->base, "CG")!=0 && strcmp(second_last->base, "CG")!=0){
                strcpy(ptr->base, "GC");
                strcpy(first_last->base, "GC");
                strcpy(second_last->base, "GC");
            }
        }
    }
}

void select(Node* head, int index, char* base){
    Node* ptr = head;
    for(int i=1;i<=index;i++){
        ptr = ptr->next;
        //此时ptr是index=i
    }
    strcpy(ptr->base, base);
}

void cut(Node* head, int index){
    Node* ptr = head;
    Node* parent;
    for(int i=1;i<=index;i++){
        parent = ptr;
        ptr = ptr->next;
        //此时ptr是index=i
    }
    parent->next = ptr->next;
    delete(ptr);
}

void order(Node* head, int start_index, int end_index){
    Node* ptr = head;
    Node* parent;

    for(int i=1;i<=start_index;i++){
        parent = ptr;
        ptr = ptr->next;
        //此时ptr是index=i
    }
    Node* start = parent;

    int len=end_index-start_index+1;

    for(int i=0;i<len-1;i++){
        Node* ptr = start;
        Node* ptr_next = ptr->next;
        for(int j=0;j<len-1;j++){
            //printf("%s %s\n", ptr->next->base, ptr_next->next->base);
            //if(strcmp(ptr->next->base, ptr_next->next->base)>0){
            if(ptr->next->base[0] > ptr_next->next->base[0]){
                Node* last_one = ptr_next->next->next;
                ptr->next = ptr_next->next;
                ptr_next->next->next = ptr_next;
                ptr_next->next = last_one;
            }
            ptr = ptr->next;
            ptr_next = ptr->next;
        }
    }

}

void print(Node* head){
    Node* ptr = head;
    for(int i=1;;i++){
        if(ptr->next == NULL){
            break;
        }
        ptr = ptr->next;
        printf("%s\n", ptr->base);
    }
}

int main(){

    Node* head = (Node*)malloc(sizeof(Node));
    head->next = NULL;

    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        char action[10];
        scanf("%s", action);

        if(strcmp("ADD", action)==0){
            char base[3];
            scanf("%s", base);
            add(head, base);
            //print(head);
        }else if(strcmp("SELECT", action)==0){
            int index;
            char base[3];
            scanf("%d %s", &index, base);
            select(head, index, base);
            //print(head);
        }else if(strcmp("CUT", action)==0){
            int index;
            scanf("%d", &index);
            cut(head, index);
            //print(head);
        }else if(strcmp("ORDER", action)==0){
            int start, end;
            scanf("%d %d", &start, &end);
            order(head, start, end);
            //print(head);
        }
    }
    print(head);
}