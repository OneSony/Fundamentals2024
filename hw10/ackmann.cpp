#include<stdio.h>

int ackmann(int x, int y){
    if(x == 0){
        return y + 1;
    }else if(y == 0){
        return ackmann(x - 1, 1);
    }else{
        return ackmann(x - 1, ackmann(x, y - 1));
    }
}


int main(){
    int x, y;
    scanf("%d %d", &x, &y);
    printf("%d\n", ackmann(x, y));
}