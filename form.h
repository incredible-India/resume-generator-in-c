#include<windows.h>


#define ENTER 13
#define TAB 9
#define BKSP 8
#define ESC 27  //define all the micro for the buttons

void gotoxy(int,int);
void StdAsk(char [],char[],char[]);
void exitFn(void);
void showMenu(void);
void setcolor(int);
void mkhor(int,int,int,char);
void mkver(int,int,int,char);
void mkdig(int,int,int,char);
int checkValdation(char[],int,char[]);
void saveAsDataBase(char[],char[],char[],char[],char[],char[],char[],char[],char[],int,int,int);


typedef struct UserData
{
  char fname[50],lname[50],address[100],email[50],mobile[15],skills[100],fatherName[50];
  char city[50],state[50];
  int day,month,year;
}user;

void takeUserData(void)
{
    SYSTEMTIME t;
    GetSystemTime(&t);
    int isError;
    user data;
    extern int i,j;

//first name
    readData:
    system("cls");
fflush(stdin);

    setcolor(13);
 mkhor(22,4,37,'-');
   gotoxy(22,3);
    printf("Hit the Enter After Filling The Data");


    gotoxy(30,10);
    setcolor(6);
    printf("First Name : ");

    setcolor(7);
        fflush(stdin);
    gets(data.fname);

    isError=checkValdation(data.fname,2,"Name is too short Please Try another one");

    if(!isError)
    {
        goto readData;
    }


    //last  name
    readData1:


     gotoxy(30,14);
    setcolor(3);
    printf("last Name : ");
    setcolor(7);
    gets(data.lname);

    isError=checkValdation(data.lname,2," Last Name is too short Please Try another one");

    if(!isError)
    {
        system("cls");
           gotoxy(22,3);
    setcolor(12);
    printf("Hit the Enter After Filling The Data");
    mkhor(22,4,37,'-');
        goto readData1;
    }

  //father name

   readData7:
    system("cls");

   gotoxy(22,3);
    setcolor(13);
    printf("Hit the Enter After Filling The Data");
    mkhor(22,4,37,'-');

    gotoxy(30,10);
    setcolor(6);
    printf("Father Name : ");
    setcolor(7);
    gets(data.fatherName);

    isError=checkValdation(data.fatherName,2,"Name is too short Please Try another one");

    if(!isError)
    {
        goto readData7;
    }


//Email
    readData2:
        system("cls");

           gotoxy(22,3);
    setcolor(13);
    printf("Hit the Enter After Filling The Data");
    mkhor(22,4,37,'-');

     gotoxy(30,10);
    setcolor(6);
    printf("Email id : ");
    setcolor(7);
    gets(data.email);

    isError=checkValdation(data.email,11," Email is  invalid ");

    if(!isError)
    {
        goto readData2;
    }
//mobile number

    readData3:

     gotoxy(30,13);
    setcolor(6);
    printf("Mobile : ");
    setcolor(7);
        fflush(stdin);
    gets(data.mobile);

    isError=checkValdation(data.mobile,9,"Invalid Mobile Number");

    if(!isError)
    {
        system("cls");

           gotoxy(22,3);
    setcolor(15);
    printf("Hit the Enter After Filling The Data");
    mkhor(22,4,37,'-');

        goto readData3;
    }

    //city

    readData4:

     gotoxy(30,16);
    setcolor(3);
    printf("city : ");
    setcolor(7);
        fflush(stdin);
    gets(data.city);

    isError=checkValdation(data.city,2,"Invalid City Name ");

    if(!isError)
    {
        system("cls");

           gotoxy(22,3);
    setcolor(16);
    printf("Hit the Enter After Filling The Data");
    mkhor(22,4,37,'-');

        goto readData4;
    }

     //state

    readData5:

     gotoxy(30,18);
    setcolor(3);
    printf("State : ");
    setcolor(7);
        fflush(stdin);
    gets(data.state);

    isError=checkValdation(data.state,2,"Invalid State Name ");

    if(!isError)
    {
        system("cls");

        goto readData5;
    }

    //address

    readData9:
system("cls");

   gotoxy(22,3);
    setcolor(17);
    printf("Hit the Enter After Filling The Data");
    mkhor(22,4,37,'-');

     gotoxy(30,10);
    setcolor(3);
    printf("Address : ");
    setcolor(7);
        fflush(stdin);
    gets(data.address);

    isError=checkValdation(data.address,5,"Invalid Address ");

    if(!isError)
    {


        goto readData9;
    }

//skills

   readData10:

     gotoxy(30,13);
    setcolor(3);
    printf("Skills : ");
    setcolor(7);
        fflush(stdin);
    gets(data.skills);

    isError=checkValdation(data.skills,4,"Invalid Type ");

    if(!isError)
    {

system("cls");
   gotoxy(22,3);
    setcolor(17);
    printf("Hit the Enter After Filling The Data");
    mkhor(22,4,37,'-');
        goto readData10;
    }

    //date of birth

    readData12:
     system("cls");

        gotoxy(22,3);
    setcolor(18);
    printf("Hit the Enter After Filling The Data");
    mkhor(22,4,37,'-');

    setcolor(9);
    gotoxy(47,14);
    printf("DD/MM/YYYY");
      gotoxy(30,16);
    setcolor(3);
    printf("Date Of Birth : ");
    setcolor(7);
      fflush(stdin);
    scanf("%d/%d/%d",&data.day,&data.month,&data.year);

    if(data.day > 31 || data.day <=0 ||data.month <= 0 || data.month >=13 || data.year > t.wYear || data.year < 1950)
    {
         system("cls");
        gotoxy(40,12);
        setcolor(5);
        printf("Invalid Date Formate or Please check the Date or Month or Year");
         gotoxy(40,14);
          printf("Year should not be greater than current year and less than 1950 ");
                   gotoxy(40,16);
          printf("DD/MM/YYYY will be the formate. character  \' / \' is must after date and month.");
        setcolor(6);
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
                goto readData12;
            }else
            {
                printf("\a");
                goto datato;

            }
        }


    }


    // now its time to ask the user that we have to save the given data or not

    readFurry:

    fflush(stdin);
    system("cls");

        StdAsk("TAB : Menu","__Resume__Maker__","ESC : Exit");

  setcolor(11);
  mkhor(25,8,40,'-');
  mkhor(25,16,40,'-');
  mkver(25,8,8,'-');
   mkver(65,8,8,'-');



   gotoxy(30,10);
   setcolor(23);
   printf("Do You Want To Save Your Data ?");

     gotoxy(35,13);

   setcolor(6);

   printf("Y :- Yes");

      gotoxy(50,13);
   setcolor(25);

   printf("N :- NO");

   {

       char urChoice;

       urChoice =getch();

       if(urChoice == 'Y' || urChoice == 'y')
       {
         saveAsDataBase(data.fname,data.lname,data.fatherName,data.email,
                        data.mobile,data.city,data.address,data.state,data.skills,
                        data.day,data.month,data.year);

       }else if(urChoice == 'N' || urChoice =='n')
       {
            showMenu();
       }
        else if(urChoice == ESC)
       {
        exitFn();

       }else if(urChoice == TAB)
       {
        showMenu();

       }else

       {

        system("cls");
        gotoxy(40,12);
        setcolor(15);
        printf("Press \'Y\' for YES , \'N\' for NO And Escape for Exit..");
        getch();
        goto readFurry;

       }
   }

}
//saving the data with help of file handling..

void saveAsDataBase(char fname[],char lname[],char fathername[],char email[],char mobile[],char city[],char address[],
                    char state[],char skills[],int day,int month,int year)
                    {

                       char FirstName[50];

                            time_t ct;
                            time(&ct);
                            SetConsoleTitle("Final Data -Resume Generator Himanshu");


                       FILE *fp;

                    char* resume= "Resumes";



                         fflush(stdin);

                         mkdir(resume);


                        fflush(stdin);

                        //now saving the data inside the txt file
                        fp=fopen("Resumes\\Alldata.txt","a");

                        fprintf(fp," on %s",ctime(&ct));
                        fprintf(fp,"\n--------------------------------\n");
                        fprintf(fp," Name : %s %s\n",fname,lname);
                        fprintf(fp,"--------------------------------\n");
                        fprintf(fp,"First Name : %s\n",fname);
                        fprintf(fp,"Last Name : %s\n",lname);
                        fprintf(fp,"Father Name : %s\n",fathername);
                        fprintf(fp,"Email : %s\n",email);
                        fprintf(fp,"Mobile : %s\n",mobile);
                        fprintf(fp,"DOB : %d/%d/%d",day,month,year);
                        fprintf(fp,"\nAddress : %s\n",address);
                        fprintf(fp,"City : %s\n",city);
                        fprintf(fp,"State : %s\n",state);
                        fprintf(fp,"Skills : %s\n",skills);
                        fprintf(fp,"\n--------------------------------\n");
                        fprintf(fp,"Finish");
                        fprintf(fp,"\n--------------------------------\n\n");



                        fclose(fp);

                        //we will show the formate to the user
                        biodata:
                        system("cls");

                            setcolor(193);
                        mkhor(10,3,70,'-');
                        mkhor(10,25,70,'-');
                        mkver(10,3,22,'-');
                        mkver(80,3,22,'-');

                        setcolor(193);
                        gotoxy(38,4);
                        printf("Resume Generator");
                        setcolor(193);
                        mkhor(10,5,70,'-');

                        setcolor(7);
                        gotoxy(15,6);
                        printf("Name : ");
                        setcolor(26);
                        printf(" %s %s",strupr(fname),strupr(lname));



                          setcolor(193);
                        mkhor(10,7,70,'-');
                           setcolor(7);
                        gotoxy(15,8);
                        printf("Father`s Name : ");
                        setcolor(26);
                        printf(" %s",strupr(fathername));


                              setcolor(193);
                          mkhor(10,9,70,'-');
                           setcolor(7);
                        gotoxy(15,10);
                        printf("Mobile : ");
                        setcolor(26);
                        printf(" %s",mobile);


                          setcolor(193);
                         mkhor(10,11,70,'-');
                           setcolor(7);
                        gotoxy(15,12);
                        printf("City : ");
                        setcolor(26);
                        printf(" %s",strupr(city));


                          setcolor(193);
                         mkhor(10,13,70,'-');
                           setcolor(7);
                        gotoxy(15,14);
                        printf("State : ");
                        setcolor(26);
                        printf(" %s",strupr(state));


                          setcolor(193);
                        mkhor(10,15,70,'-');
                           setcolor(7);
                        gotoxy(15,16);
                        printf("Address : ");
                        setcolor(26);
                        printf(" %s",strupr(address));


                              setcolor(193);
                           mkhor(10,17,70,'-');
                           setcolor(7);
                        gotoxy(15,18);
                        printf("Skills : ");
                        setcolor(187);
                        printf(" %s",strupr(skills));


                          setcolor(193);
                        mkhor(10,19,70,'-');
                           setcolor(7);
                        gotoxy(15,20);
                        printf("DOB: ");
                        setcolor(26);
                        printf(" %d/%d/%d",day,month,year);


                             setcolor(193);
                            mkhor(10,21,70,'-');
                           setcolor(7);
                        gotoxy(15,22);
                        printf("Email : ");
                        setcolor(190);
                        printf(" %s",email);

                         StdAsk("TAB : Menu","__Resume__Maker__","ESC : Exit");

                         {
                             char options;

                             options=getch();

                             if(options == TAB)
                             {
                                 showMenu();

                             }else if(options == ESC)
                             {

                                 exitFn();

                             }else
                             {
                                 goto biodata;
                             }
                         }


                    }

//delete mt resumes
void DeleteMyResume(void)
{
    FILE *openFile;


    int checkStatus;

    mydatar:

    system("cls");

    setcolor(146);
    mkhor(10,5,80,'*');
    mkhor(10,15,80,'*');
    mkver(10,5,10,'*');
    mkver(90,5,10,'*');


    setcolor(195);

    gotoxy(27,8);
    printf("Do you really want to delete all recoreds ? ");

      setcolor(190);

    gotoxy(28,10);
    printf("( Once you deleted. you can \'Recover\' it.)");

     gotoxy(36,13);

   setcolor(6);

   printf("Y :- Yes");

      gotoxy(52,13);
   setcolor(25);

   printf("N :- NO");

        StdAsk("TAB : Menu","__Resume__Maker__","ESC : Exit");

        {
            char deleteOrNot ;

            deleteOrNot =getch();

            if(deleteOrNot == TAB)
            {
                showMenu();

            }else if(deleteOrNot == ESC)
            {
                exitFn();

            }else if(deleteOrNot == 'y' || deleteOrNot =='Y')
            {

                checkStatus =remove("Resumes\\Alldata.txt");

                if(!checkStatus)
                {
                    SetConsoleTitle("Deleted Successfully");
                     system("cls");
                     mkdig(40,5,30,'*');
                     mkdig(41,5,29,'*');
                       mkdig(42,5,28,'*');
                         mkdig(43,5,27,'*');
                           mkdig(44,5,26,'*');
                    gotoxy(40,12);
                    setcolor(123);
                    printf("Successfully Deleted All Records.. ");
                    getch();
                    showMenu();

                }else
                {
                     SetConsoleTitle("Already Deleted");
                     system("cls");
                     mkdig(40,5,20,'*');
                     mkdig(41,5,21,'*');
                       mkdig(42,5,22,'*');
                         mkdig(43,5,23,'*');
                           mkdig(44,5,24,'*');
                    gotoxy(40,12);
                    setcolor(124);
                    printf("Files Already have been deleted...");
                    getch();
                    showMenu();
                }


            }else if(deleteOrNot == 'n' || deleteOrNot =='N')
            {
                    showMenu();

            }else
            {

                  system("cls");
    gotoxy(40,12);
        setcolor(15);
        printf("Press \'Y\' for YES , \'N\' for NO And Escape for Exit..");
        getch();
        goto mydatar;

            }

        }


}

void ReadDataResumes(void)
{
    FILE *__fileopen ;
    char datareading;

    __fileopen =fopen("Resumes\\Alldata.txt","r");

    if(__fileopen == NULL)
    {
            SetConsoleTitle("Error 404");
            system("cls");
                     mkdig(40,5,15,'*');
                     mkdig(41,5,16,'*');
                       mkdig(42,5,17,'*');
                         mkdig(43,5,18,'*');
                           mkdig(44,5,19,'*');
        gotoxy(40,12);
        setcolor(35);
        printf("File Not Found..");
        getch();
        showMenu();


    }
    system("cls");
    setcolor(125);
     SetConsoleTitle("All Resumes :-Resume Generator");

    while(!feof(__fileopen))
    {
       datareading=fgetc(__fileopen);
        printf("%c",datareading);
    }
    fclose(__fileopen);

    getch();
    showMenu();

}

void seeDemo(void)
{
    demogeting:
    system("cls");

                            setcolor(193);
                        mkhor(10,3,70,'-');
                        mkhor(10,25,70,'-');
                        mkver(10,3,22,'-');
                        mkver(80,3,22,'-');

                        setcolor(193);
                        gotoxy(38,4);
                        printf("Resume Generator");
                        setcolor(193);
                        mkhor(10,5,70,'-');

                        setcolor(7);
                        gotoxy(15,6);
                        printf("Name : ");
                        setcolor(26);
                        printf(" Himanshu Sharma ");



                          setcolor(193);
                        mkhor(10,7,70,'-');
                           setcolor(7);
                        gotoxy(15,8);
                        printf("Father`s Name : ");
                        setcolor(26);
                        printf("S.K Sharma ");


                              setcolor(193);
                          mkhor(10,9,70,'-');
                           setcolor(7);
                        gotoxy(15,10);
                        printf("Mobile : ");
                        setcolor(26);
                        printf(" 9506891090  8604470501 ");


                          setcolor(193);
                         mkhor(10,11,70,'-');
                           setcolor(7);
                        gotoxy(15,12);
                        printf("City : ");
                        setcolor(26);
                        printf(" Ghazipur ");


                          setcolor(193);
                         mkhor(10,13,70,'-');
                           setcolor(7);
                        gotoxy(15,14);
                        printf("State : ");
                        setcolor(26);
                        printf(" Uttar Pradesh ");


                          setcolor(193);
                        mkhor(10,15,70,'-');
                           setcolor(7);
                        gotoxy(15,16);
                        printf("Address : ");
                        setcolor(26);
                        printf("Near Railway Station Rai Colony Ghazipur");


                              setcolor(193);
                           mkhor(10,17,70,'-');
                           setcolor(7);
                        gotoxy(15,18);
                        printf("Skills : ");
                        setcolor(187);
                        printf("C, Python,Web Development (Full Stack) ");


                          setcolor(193);
                        mkhor(10,19,70,'-');
                           setcolor(7);
                        gotoxy(15,20);
                        printf("DOB: ");
                        setcolor(26);
                        printf("15/06/2000 ");


                             setcolor(193);
                            mkhor(10,21,70,'-');
                           setcolor(7);
                        gotoxy(15,22);
                        printf("Email : ");
                        setcolor(190);
                        printf("himanshu399231@gmail.com");

                         StdAsk("TAB : Menu","__Resume__Maker__","ESC : Exit");

                         {
                             char options;

                             options=getch();

                             if(options == TAB)
                             {
                                 showMenu();

                             }else if(options == ESC)
                             {

                                 exitFn();

                             }else
                             {
                                 goto demogeting;
                             }
                         }


}
