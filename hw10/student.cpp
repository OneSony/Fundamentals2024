#include<stdio.h>
#include<stdlib.h>
 
//带表头

struct Node{
    int id;
    char name[50];
    char gender[50];
    int score;
    Node* next;
    int rank;
};

Node* create_link(int n){
    Node* head = (Node*)malloc(sizeof(Node));
    head->next = NULL;
    Node* ptr = head;
    for(int i=0;i<n;i++){
        ptr->next = (Node*)malloc(sizeof(Node));
        ptr = ptr->next;

        ptr->next = NULL;
        scanf("%d %s %s %d", &(ptr->id), ptr->name, ptr->gender, &(ptr->score));
    }

    return head;
}

void sort_link(Node* head){

    for(;;){
        bool swap_flag = 0;

        for(Node* i=head, *j = i->next; j->next != NULL; i = i->next, j = i->next){
            //printf("i:%d j:%d\n", i->next->score, j->next->score);
            if(i->next->score < j->next->score || ((i->next->score == j->next->score) && i->next->id > j->next->id)){
                //swap i->next, j->next
                i->next = j->next;
                j->next = j->next->next;
                i->next->next = j;
                swap_flag = 1;
            }
        }

        if(swap_flag == 0){
            break;
        }
    }


    //同等位次按最高计算rank 
    int rank=0;
    int last_score=-1;
    int same_score_count = 0;
    for(Node* i=head->next; i != NULL; i = i->next){
        if(i->score == last_score){
            i->rank = rank;
            same_score_count++;
        }else{
            rank = rank + same_score_count + 1;
            same_score_count = 0;
            last_score = i->score;

            i->rank = rank;
        }
    }

    //同等位次按最低计算rank
    /*
    int last_rank = 0;
    int last_score = head->next->score;
    int same_score_count = 0;
    Node* last_node = head->next;
    for(Node* i=head->next; i != NULL; i = i->next){
        if(i->score == last_score){
            same_score_count++;
        }else{
            //给前面的排名
            for(;last_node != i;last_node = last_node->next){
                last_node->rank = last_rank + same_score_count;
            }
            

            last_rank = last_rank + same_score_count;
            same_score_count = 1;
            last_score = i->score;
            last_node = i;
        }
    }
    for(;last_node != NULL;last_node = last_node->next){
        last_node->rank = last_rank + same_score_count;
    }
    */
}

void remove_node(Node* head, int rank){
    Node* ptr;
    for(ptr = head; ptr->next != NULL;){
        if(ptr->next->rank > rank){
            break;
        }

        if(ptr->next->rank == rank){
            Node* need_to_remove = ptr->next;
            ptr->next = need_to_remove->next;
            free(need_to_remove);
            continue;
        }

        ptr = ptr->next;
    }
}

void print_link(Node* head){
    for(Node* i=head->next; i != NULL; i = i->next){
        //printf("%d %d %s %s %d\n", i->rank, i->id, i->name, i->gender, i->score);
        printf("%d %s %s %d\n", i->id, i->name, i->gender, i->score);
    }
}

int main(){
    int m;
    scanf("%d", &m);

    Node* head = create_link(m);
    sort_link(head);

    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        int rank;
        scanf("%*[^ ] %d", &rank);
        //printf("::%d\n", rank);
        remove_node(head, rank);
        //print_link(head);
    }

    print_link(head);
}