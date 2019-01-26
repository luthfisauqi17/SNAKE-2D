#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <windows.h>

using namespace std;
bool gameOver;
const int width=20;
const int height=20;
int x,y,fruitX,fruitY,score,score2,hscore;
int tailX[100], tailY[100];
int nTail;
int menu;
char flag;
enum eDirection {STOP=0, LEFT, RIGHT, UP, DOWN};
eDirection dir;

void menus()
{
    cout<<"-------------------------------"<<endl;
    cout<<"\tOooo SNAKE 2D oooO"<<endl;
    cout<<"\n1. PLAY"<<endl;
    cout<<"2. HOW TO PLAY"<<endl;
    cout<<"3. DEVELOPER profile"<<endl;
    cout<<"4. QUIT"<<endl;
    cout<<"\t\tmade by: luthfi"<<endl;
    cout<<"-------------------------------"<<endl;
    cout<<"\n Select something"<<endl;
}



void howTo()
{
    cout<<"CONTROLS: "<<endl;
    cout<<"Press 'w' to move UP"<<endl;
    cout<<"Press 'a' to move LEFT"<<endl;
    cout<<"Press 'd' to move RIGHT"<<endl;
    cout<<"Press 's' to move DOWN"<<endl;
    cout<<"\nGAME SYSTEMS: "<<endl;
    cout<<" Oooo  <- THIS IS YOU"<<endl;
    cout<<"F is food. if you eat the F you will get 10 points score"<<endl;
    cout<<"DO NOT EAT YOURSELF"<<endl;
    cout<<"Try to eat as much as you can\n~~~GOOD LUCK~~~"<<endl;
}



void devProfile()
{
    cout<<"PROFILE:"<<endl;
    cout<<"Name: Luthfi Syauqi Magesta"<<endl;
    cout<<"StdID: 001201800027"<<endl;
    cout<<"github: luthfisauqi17"<<endl;
    cout<<"\"Hello World\""<<endl;
}



void setup()
{
    gameOver = false;
    dir = STOP;
    x = width/2;
    y = height/2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}



void draw()
{
    system("cls");
    for(int i=0; i<width+2; i++){
        cout<<"#";
    }
    cout<<endl;
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            if(j==0){
                cout<<"#";
            }

            if(i == y&&j == x){
                cout<<"O";
            }
            else if(i == fruitY&&j == fruitX){
                cout<<"F";
            }
            else
            {
                bool print = false;
                for (int k = 0; k<nTail; k++)
                {
                    if(tailX[k]==j && tailY[k]==i)
                    {
                        cout<<"o";
                        print = true;
                    }
                }
                if(!print)
                    cout<<" ";
            }

            if(j==width-1){
                cout<<"#";
            }
        }
        cout<<endl;
    }

    for(int i=0; i<width+2; i++){
        cout<<"#";
    }
    cout<<endl;
    cout<<"Score: "<<score<<endl;
    cout<<endl;
    cout<<"CONTROLS: "<<endl;
    cout<<"Press 'w' to move UP"<<endl;
    cout<<"Press 'a' to move LEFT"<<endl;
    cout<<"Press 'd' to move RIGHT"<<endl;
    cout<<"Press 's' to move DOWN"<<endl;
}



void input()
{
    if(_kbhit()){
        switch(_getch()){
        case 'a':dir = LEFT;
                break;
        case 'w':dir = UP;
                break;
        case 'd':dir = RIGHT;
                break;
        case 's':dir = DOWN;
                break;
        case 'x':gameOver=true;
                break;
        }
    }
}



void logic()
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for(int i=1;i<nTail;i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch(dir){
        case LEFT:x--;
            break;
        case UP:y--;
            break;
        case RIGHT:x++;
            break;
        case DOWN:y++;
            break;
        default: break;
    }
    /*if(x>width-1 || x<0 || y>height-1 || y<0) {
        gameOver = true;
    }*/

    if(x>=width) x=0;
    else if(x<0) x= width-1;

    if(y>=width) y=0;
    else if(y<0) y= width-1;

    for(int i=0;i<nTail;i++){
        if (tailX[i] == x && tailY[i] == y){
            gameOver = true;
            cout<<"\nGAME OVER"<<endl;
        }
    }
    if(x==fruitX && y==fruitY){
        score+=10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }
}



int main()
{
    menus();
    int choice;
    cin>>choice;
    switch(choice){
        case 1: setup();
                while(!gameOver)
                {
                    draw();
                    input();
                    logic();
                    Sleep(10);
                }
                break;
        case 2: howTo();
                break;
        case 3: devProfile();
                break;
        case 4: cout<<"EXITING THE GAME....\n DONE "<<endl;
                cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
                return 0;
                break;
        default: cout<<"INCORRECT INPUT.."<<endl;
                 cout<<"press ANY key"<<endl;
                 cin>>flag;
                 system("cls");
                 return main();
    }
    cout<<"\nBACK TO THE MENU?(y/n)"<<endl;
    cin>>flag;
    if(flag=='y'||flag=='Y'){
        system("cls");
        return main();
    }else
    {
        cout<<"You want to try again?"<<endl;
        cin>>flag;
        if(flag=='y'||flag=='Y')
        {
            cout<<"You have to go back to the menu, and select PLAY"<<endl;
            cout<<"Press any key to go back to the menu"<<endl;
            cin>>flag;
            system("cls");
            return main();
        }
        else {
            system("cls");
            return main();
        }
    };
}
