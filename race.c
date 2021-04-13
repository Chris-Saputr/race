/* Christian Saputro
 * March 26, 2021
 * To design and implement functions to process pointers.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function prototype
int randomNumbers(int);
void ticker(void);
void printArena(int hareStart, int turtleStart);
int winner(int hareStart, int turtleStart);
int hareMove(void);
int turtleMove(void);

int main(){
    //random number using time
    srand(time(0));

    //starts at 1
    int hareStart = 1;
    int turtleStart = 1;
    int whoWins = 0;

    printf("BANG!!!!!!!\n");
    ticker();
    printf("AND THEY ARE OFF!!!\n");
    ticker();
    printArena(hareStart, turtleStart);
    ticker();

    while(whoWins == 0){
        sleep(1);//pauses the timer so it slows down to make it readable

        hareStart += hareMove();
        turtleStart += turtleMove();

        //if statement to place if the hare and tortoise are under 1 because strictly starts at 1
        if(hareStart < 1){
            hareStart = 1;
        }
        if(turtleStart < 1){
            turtleStart = 1;
        }

        printArena(hareStart, turtleStart);

        whoWins = winner(hareStart, turtleStart);
        ticker();
    }
    return 0;
}
//random number generator for the movements
int randomNumbers(int max){
    return rand()%max;
}
//this function is for the pauses between each timers
void ticker(){
    clock_t start;
    int pauseTimer = 1000;

    start = clock();//uses the clock function with real time
    while(clock() < start + pauseTimer);
}

void printArena(int hareStart, int turtleStart){
    //arena or box maximum is 70
    for(int i = 1; i <=70; i++){
        printf("=");//prints the arena or the box
    }
    printf("\n");

    for(int i = 1; i < hareStart; i++){
        printf(" ");
    }
    if(hareStart == turtleStart){ //if hare is with tortoise, tortoise snaps hare
        printf("OUCH!!!!!\n");
    }
    else{
        printf("H\n");
    }

    for(int i = 1; i <= turtleStart; i++){
        printf(" ");
    }
    printf("T\n");

    for(int i = 1; i <=70; i++){//closes the arena to make it a track, so it is more readable
        printf("=");
    }
    printf("\n");
}

int winner(int hareStart, int turtleStart){
    if(hareStart >= 70 && turtleStart >= 70){
        printf("We have a tie!\n");
        return 1;
    }
    else if(hareStart >= 70){
        printf("Hare Wins! (Gross)\n");
        return 1;
    }
    else if(turtleStart >= 70){
        printf("Tortoise Wins! (Congratulations)\n");
        return 1;
    }
    else{
        return 0;
    }
}

int hareMove(){

    int randomNumber = rand()%1000; //randomize the movement of the hare

    if(randomNumber >= 800){//hare sleep
        return 0;
    }
    else if(randomNumber >= 600){ // big hop
        return 9;
    }
    else if(randomNumber >= 500){ //big slip
        return -12;
    }
    else if(randomNumber >= 200){ //small hop
        return 1;
    }
    else{   //small slip
        return -2;
    }
}
int turtleMove(){
    int randomNumber = rand()%1000; //randomize the tortoise movement

    if(randomNumber >= 500){//fast plod
        return 3;
    }
    else if(randomNumber >= 200){ //slip
        return -6;
    }
    else{ //slow plod
        return 1;
    }
}