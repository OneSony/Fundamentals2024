#include<stdio.h>
int maze[5][5];
struct Dot{
    int x;
    int y;
};

int main(){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            scanf("%d", &maze[i][j]);
        }
    }

    Dot queue[30];
    Dot parent[5][5];
    int len=0;

    queue[0].x = 0;
    queue[0].y = 0;

    len++;

    while(len>0){
        Dot head = queue[0];

        for(int i=0;i<len-1;i++){
            queue[i]=queue[i+1];
        }

        len--;

        //上
        if(head.x-1>=0 && maze[head.x-1][head.y]==0){
            queue[len].x = head.x-1;
            queue[len].y = head.y;
            len++;
            maze[head.x-1][head.y]=-1; //走过
            parent[head.x-1][head.y].x = head.x;
            parent[head.x-1][head.y].y = head.y;

            //printf("%d %d\n", head.x-1, head.y);

            if(head.x-1==4 && head.y==4){
                break;
            }
        }
        
        if(head.x+1<5 && maze[head.x+1][head.y]==0){
            queue[len].x = head.x+1;
            queue[len].y = head.y;
            len++;
            maze[head.x+1][head.y]=-1; //走过
            parent[head.x+1][head.y].x = head.x;
            parent[head.x+1][head.y].y = head.y;

            //printf("%d %d\n", head.x+1, head.y);

            if(head.x+1==4 && head.y==4){
                break;
            }
        //下
        }
        
        if(head.y-1>=0 && maze[head.x][head.y-1]==0){
            queue[len].x = head.x;
            queue[len].y = head.y-1;
            len++;
            maze[head.x][head.y-1]=-1; //走过
            parent[head.x][head.y-1].x = head.x;
            parent[head.x][head.y-1].y = head.y;

            //printf("%d %d\n", head.x, head.y-1);

            if(head.x==4 && head.y-1==4){
                break;
            }
        //左
        }
        
        if(head.y+1<5 && maze[head.x][head.y+1]==0){
            queue[len].x = head.x;
            queue[len].y = head.y+1;
            len++;
            maze[head.x][head.y+1]=-1; //走过
            parent[head.x][head.y+1].x = head.x;
            parent[head.x][head.y+1].y = head.y;

            //printf("%d %d\n", head.x, head.y+1);

            if(head.x==4 && head.y+1==4){
                break;
            }
        //右
        }
    }

    Dot print_quene[30];
    int print_len=0;

    Dot print = queue[len-1];
    while(1){
        print_quene[print_len] = print;
        print_len++;
        print = parent[print.x][print.y];

        if(print.x==0 && print.y==0){
            print_quene[print_len] = print;
            break;
        }
    }

    for(int i=print_len;i>=0;i--){
        printf("(%d, %d)\n", print_quene[i].x, print_quene[i].y);
    }

}