void gotoxy(int,int);
void setcolor(int);
void seeDemo(void);
void ReadDataResumes(void);
void mkver(int,int,int,char);//make the vertical line
void mkhor(int,int,int,char);//make the horizontal line
void mkdig(int,int,int,char);//make the diagonal line
void exitFn(void);//for the exit Function
void StdAsk(char[],char[],char[]);
void DeleteMyResume(void);//delete all the resume records

void intro(void)
{
 extern int i,j;
 char introWord[20] ="Resume Generator";
 char IntroWord[35]="Make Your Awesome Profile";
SetConsoleTitle("Resume Maker :- Himanshu Sharma");
 system("cls");
gotoxy(30,10);
 for(i=0;i<=strlen(introWord);i++)
 {
     setcolor(11);
     printf("%c",introWord[i]);
     Sleep(120);


 }

gotoxy(50,15);
 for(i=0;i<=strlen(IntroWord);i++)
 {
     setcolor(22);
     printf("%c",IntroWord[i]);
     Sleep(120);


 }

gotoxy(30,11);
 for(i=0;i<=strlen(IntroWord);i++)
 {
       setcolor(11);
     printf("-");

 }
gotoxy(50,16);
 for(i=0;i<=strlen(IntroWord);i++)
 {
       setcolor(22);
     printf("-");

 }


}

void showMenu(void)
{
    SYSTEMTIME CurrentTime;
    GetSystemTime(&CurrentTime);
    SetConsoleTitle("Resume Maker :- Menu");
    ReadAgain:
    system("cls");
    gotoxy(40,8);
    setcolor(6);
    printf("1 : Make New Resume");

        gotoxy(40,10);
    setcolor(9);
    printf("2 : Get All Resumes");

      gotoxy(40,12);
    setcolor(44);
    printf("3 : Delete All Resumes");

     gotoxy(40,14);
    setcolor(26);
    printf("4 :  See Demo");

    gotoxy(40,16);
    setcolor(46);
    printf("5 :  Exit");

    setcolor(13);
    mkhor(0,24,75,'_');
    printf("Resume Maker  \t %d/%d/%d",CurrentTime.wDay,CurrentTime.wMonth,CurrentTime.wYear);


{
    char __choice;

    __choice =getch();

    if(__choice == '1')
    {

     takeUserData();

    }else if(__choice == '2')
    {
        ReadDataResumes();

    }else if(__choice == '3')
    {

    DeleteMyResume();

    }
    else if(__choice == '4')
    {

        seeDemo();
    }


    else if(__choice == '5')
    {
    exitFn();
    }
    else
    {
        printf("\a");
        goto ReadAgain;
    }
    return;

}



}
