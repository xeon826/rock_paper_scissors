#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
char displayMenu();
int outcome(char, int);
int main() {
    string r;
    int c, counter=0;

    srand(time(NULL));
    string rps[]={"rock","paper","scissors"};
    while(++counter){
        c=rand()%3;
        switch(outcome(displayMenu(), c)){
            case -1: cout << "NPC chose " << rps[c] << ", player one wins.";
                     break;
            case 0: cout << "NPC chose " << rps[c] << ", player two wins..";
                    break;
            default:cout << "NPC chose " << rps[c] << ", it's a draw.";
        }
        cout << "You have played " << counter << " times";

    } 

    return 0;
}

char displayMenu() {
    string player="";
    while(1) {
        cout << "You can choose either [r]ock, [p]aper, or [s]cissors";
        cin >>player;
        switch (player[0]) {
            case 'r':cout << "You have chosen rock, are you sure? (y/n)";
                     break;
            case 'p':cout << "You have chosen paper, are you sure? (y/n)";
                     break;
            case 's':cout << "You have chosen scissors, are you sure? (y/n)";
                     break;
            default: cout << "Please choose r for rock, p for paper, or s for scissors.";
                     continue;
                     break;
        }
        char n;
        cin >> n;
        if(n!='y')
            continue;
        else
            break;
    }
    return player[0];
}
int outcome(char a, int c) {
    int r;
    switch (a) {
        case 'r':r=0;
                 break;
        case 'p':r=1;
                 break;
        default:r=2;
    }
    int result=
        (r==0)?(c==0)?1:(c==1)?0:-1:(r==1)?(c==0)?-1:(c==1)?(1):0:(c==0)?0:(c==1)?-1:1;

    return result;
}
