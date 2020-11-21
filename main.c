/* Project Starting Date : 2/11/2020 Himanshu Sharma B.E ,
Project Finished : 4/11/2020 */

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<dir.h>
 #include<time.h>
#include"form.h"//taking information of User
#include<windows.h>//gotoxy,date is define inside that header file
#include"__intro.h"//intro of the programe  d

#define ENTER 13
#define TAB 9
#define BKSP 8
#define ESC 27  //define all the micro for the buttons

void gotoxy(int,int);//for the changing coordinate of x and y

void mkhor(int,int,int,char);//for the horizontal line
void setcolor(int);//for the changing the color of text
void showMenu(void);//it will show the option for the User
int i,j;//for the loop global variable
int main(int a,char* args[])
{
void (*p)();
p=intro;
SetConsoleTitle("Resume Maker :- Himanshu Sharma");
p();
Sleep(150);
showMenu();

getch();
}

void gotoxy(int a,int b)
{
  COORD x;
  x.X=a;
  x.Y=b;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),x);

}
void setcolor(int ForgC)
{
     WORD wColor;


     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;


     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {

          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}

void mkver(int x,int y,int howMuch,char ch)
{

    extern int i,j;
    for(i=0;i<howMuch;i++)
    {

        gotoxy(x,y);
        printf("%c",ch);
        ++y;
    }
    return;
}
void mkhor(int x,int y,int howMuch,char ch)
{

    extern int i,j;
    for(i=0;i<howMuch;i++)
    {

        gotoxy(x,y);
        printf("%c",ch);
        ++x;
    }
    return;
}
void mkdig(int x,int y,int howMuch,char ch)
{

    extern int i,j;
    for(i=0;i<howMuch;i++)
    {

        gotoxy(x,y);
        printf("%c",ch);
        ++x;
        ++y;
    }
    return;
}

void exitFn(void)
{
    SetConsoleTitle("Resume Maker :- Himanshu Sharma");
    system("cls");
    system("color 71");
    gotoxy(40,12);
    printf("Thanx For Visiting Us");
    getch();
    exit(0);
}
void StdAsk(char first[],char second[],char third[])
{

    mkhor(4,28,strlen(first),'-');
    setcolor(166);
    gotoxy(4,27);
    printf("%s",first);

    setcolor(4);
    mkhor(40,28,strlen(second),'-');
    gotoxy(40,27);
    printf("%s",second);

    setcolor(3);
     mkhor(78,28,strlen(third),'-');
    gotoxy(78,27);

    printf("%s",third);

}

int checkValdation(char data[],int sizeOfData,char message[])
{
    if(strlen(data)<=sizeOfData)
    {
        system("cls");
        gotoxy(40,12);
        setcolor(5);
        printf("%s",message);

        StdAsk("TAB : Menu","BKSP : <- GO Back","ESC : Exit");
        {
               char choice;
                datato:

            choice =getch();
            if(choice == TAB)
            {
                showMenu();
            }else if(choice == ESC)
            {
                exitFn();

            }
            else if(choice ==BKSP)
            {
                return 0;
            }else
            {
                printf("\a");
                goto datato;

            }
        }


    }else
    {

        return 1;
    }

}
