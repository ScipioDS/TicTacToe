#include <stdio.h>
#include <ctype.h>1
#include <stdlib.h>

//prints board
void printb(char n[3][3]){
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%c ",n[i][j]);
        }
        printf("\n");
    }
}

//resets board
void clear(char n[3][3]){
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            n[i][j]='*';
        }
    }
}

//checks if spot is free
int check(char n[3][3], int y, int x){
    if(n[y][x]=='*')
        return 1;
    else
        return 0;
}

//checks if win condition is met
int win(char n[3][3]){
    //horizontal & vertical
    for (int i = 0; i < 3; ++i) {
        if(isalpha(n[i][0]) && n[i][0]==n[i][1] && n[i][1]==n[i][2]){
            return 1;
        }
        if(isalpha(n[0][i]) && n[0][i]==n[1][i] && n[1][i]==n[2][i]){
            return 1;
        }
    }
    //diagonals
    if(isalpha(n[0][0]) && n[0][0]==n[1][1] && n[1][1]==n[2][2]){
        return 1;
    }
    else if(isalpha(n[0][2]) && n[0][2]==n[1][1] && n[1][1]==n[2][0]){
        return 1;
    }
    else
        return 0;
}

int main() {

    //variables
char n[3][3];
clear(n);
int ans,x,y,mvc=0,flag=1;

//looping game
while(1){

    //prints board
    printb(n);

    //input
    if(flag){
        printf("Input location of X\n");
        flag=0;
        scanf("%d %d",&y,&x);
        if(check(n,y,x)){
            n[y][x]='X';
            mvc++;
        }

    }
    else{
        printf("Input location of O\n");
        flag=1;
        scanf("%d %d",&y,&x);
        if(check(n,y,x)){
            n[y][x]='O';
            mvc++;
        }
    }

    //win condition checker / continue choose
    if(win(n)){
        printb(n);
        if(flag){
            printf("O WINS\n");
        }
        else{
            printf("X WINS\n");
        }
        printf("Play again? 1 for yes, 0 for no \n");
        scanf("%d",&ans);
        if(ans){
            clear(n);
            continue;
        }
        else{
            return 0;
        }
    }

    //edgecase draw
    else if(mvc==9) {
        printb(n);
        printf("DRAW\n");
        printf("Play again? 1 for yes, 0 for no \n");
        scanf("%d",&ans);
        if(ans){
            clear(n);
            continue;
        }
        else{
            return 0;
        }
    }
}
}
