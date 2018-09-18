#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dos.h>
#include<time.h>
#include<iomanip.h>
#include<math.h>

#define PI 3.14159265



class account
{char acc_name[25];
char passw[25];
char sub_type[25];
char type[25];
char name[25];
int accno;
float balance;
int passb;
public:
int status;
long points;
int no_completed;
int no_tasks;
float spent;
void withdraw(float price);
void deposit(float price);
void read_d();
char bankname[25];
char* ret_name();
char* ret_passw();
char* ret_sub();
char* ret_type();
float ret_balance();
int ret_accno();
int ret_passb();
void assign(account X);

}A,T;

void intro();
int check_user(char name[],char pass[]);
int check_user(char name[]);
void login();
void addtask();
int overview();
void display_quotes();
void line();
void get_date();
void display_header();
int no_taskrec();
void completed();
void details();
void stats();
void calc();
int finance();
void mart();


void account::read_d()
{char spass[10],ch,sname[25];

 clrscr();
 display_header();

 gotoxy(10,5);
cout<<"Enter the name of the user:";
 gets(name);
 gotoxy(10,7);
 cout<<"Enter the account name:";
 gets(sname);
 if(check_user(sname)==1)
    {gotoxy(10,10);
     cout<<"USER NAME TAKEN!!! PLEASE RETYPE DETAILS... (press enter)";
     getch();

     read_d();
    }
 else
 {strcpy(acc_name,sname);

 gotoxy(10,9);
 cout<<"Enter the password:";
 gets(passw);
 gotoxy(10,11);
 cout<<"Retype the password for confirmation:";
 gets(spass);
 if(!strcmpi(spass,passw))
   {gotoxy(10,13);
 cout<<"Enter the user type (student/general):";
 gets(type);
 if((strcmpi(type,"student") && strcmpi(type,"general")))
    { gotoxy(10,15);
    cout<<"INVALID TYPE... PLEASE RETYPE DETAILS... (press enter)";
    getch();
    read_d();
    }
 gotoxy(10,15);
 cout<<"Enter the subscription type :";
 gotoxy(10,17);
cout<<"TYPE";
gotoxy(20,17);
cout<<"PRICE";
gotoxy(10,19);
cout<<"Yearly";
gotoxy(20,19);
cout<<"150kd";
gotoxy(10,20);
cout<<"Monthly";
gotoxy(20,20);
cout<<"15kd";
gotoxy(10,22);
 cout<<"(Enter any key if no subscription is required)";
 gotoxy(10,23);
 gets(sub_type);
 if(!(strcmpi(sub_type,"yearly"))||(!(strcmpi(sub_type,"monthly"))))
 {clrscr();
  gotoxy(12,8);
cout<<"We've teamed up with the major banks of Kuwait and have \n  collaborated to enable users to access the important features of their bank";
   gotoxy(25,10);
cout<<"account right from this app.";
gotoxy(20,12);
cout<<"We do not share this information with any";
gotoxy(18,13);
cout<<"organisation other than your respective bank.";

gotoxy(7,15);
 cout<<"You have to be a part of this service in order to make your payment";
 gotoxy(25,17);
 cout<<"Would you like to continue?(Y/N):";

 cin>>ch;
 if(ch=='y'||ch=='Y')
    {clrscr();
    ch='a';
    gotoxy(10,5);
     cout<<"Enter the bank name:";
     gets(bankname);
    gotoxy(10,7);
     cout<<"Enter the bank account number:";
     cin>>accno;
    gotoxy(10,9);
    cout<<"Enter the bank account password:";
    cin>>passb;
    gotoxy(10,11);
     cout<<"Enter the current balance:";
     cin>>balance;
     gotoxy(10,11);
     if(!(strcmpi(sub_type,"yearly")))
     {
     cout<<"\n\n AMOUNT TO BE PAID = 150 + tax";
     cout<<"\n\n TAX =30";
     }
     else
     {cout<<"\n\n AMOUNT TO BE PAID = 15 + tax";
     cout<<"\n\n TAX = 1";
     }
     cout<<"\n\n Confirm your payment (Y/N):";
     cin>>ch;
     int flag=0;
     if(ch=='y'||ch=='Y')
        { if(!(strcmpi(sub_type,"yearly")))
          { if(balance-180<0)
                cout<<"\n Insufficient funds";

             else
             flag=1;
           }
          else
              {if(balance-16<0)
                  cout<<"\n Insufficient funds";

               else
                 flag=2;
               }

        if(flag==1|| flag==2)
         {if(flag==1)
            balance-=180;
            else
            balance-=16;
          status=1;
          cout<<"\n Payment successful!";
          cout<<"\n current balance:"<<balance;
         cout<<"\n Press enter to proceed...";
         getch();
         clrscr();
         ofstream outfile("accounts.dat",ios::binary||ios::app);
         ofstream out(acc_name,ios::binary);
         out.close();
         outfile.write((char*)&A,sizeof(A));
         outfile.close();
         gotoxy(33,10);
           cout<<"PROCESSING...";
           sleep(1);
           gotoxy(36,12);
           cout<<".";
           sleep(1);
           cout<<" .";
           sleep(1);
           cout<<" .";
           sleep(2);

           clrscr();
         gotoxy(30,10);
         cout<<"ACCOUNT CREATED!!!";
         gotoxy(20,12);
         cout<<" Press Enter to return to login page";
         getch();
         login();
         }
         else
        { cout<<"\n Payment not made!";
         cout<<"\n Press enter to proceed...";
         getch();
         clrscr();
         ofstream outfile("accounts.dat",ios::binary||ios::app);
         ofstream out(acc_name,ios::binary);
         out.close();
         outfile.write((char*)&A,sizeof(A));
         outfile.close();
         gotoxy(33,10);
           cout<<"PROCESSING...";
           sleep(1);
           gotoxy(36,12);
           cout<<".";
           sleep(1);
           cout<<" .";
           sleep(1);
           cout<<" .";
           sleep(2);

           clrscr();
          gotoxy(30,10);
         cout<<"ACCOUNT CREATED!!!";
         gotoxy(20,12);
         cout<<"Press Enter to return to login page";
         getch();
          }

         }
     else
        {cout<<"\n Payment not made!";
         cout<<"\n Press enter to proceed...";
         getch();
         clrscr();
         ofstream outfile("accounts.dat",ios::binary||ios::app);
         ofstream out(acc_name,ios::binary);
         out.close();
         outfile.write((char*)&A,sizeof(A));
         outfile.close();
         gotoxy(33,10);
           cout<<"PROCESSING...";
           sleep(1);
           gotoxy(36,12);
           cout<<".";
           sleep(1);
           cout<<" .";
           sleep(1);
           cout<<" .";
           sleep(2);

           clrscr();
          gotoxy(30,10);
         cout<<"ACCOUNT CREATED!!!";
         gotoxy(20,12);
         cout<<"Press Enter to return to login page";
         getch();

         login();
         }
     }
 else
    {cout<<"\n Subscription cancelled!";
      cout<<"\n Press enter to proceed...";
         getch();
         clrscr();
         ofstream outfile("accounts.dat",ios::binary||ios::app);
         ofstream out(acc_name,ios::binary);
         out.close();

         outfile.write((char*)&A,sizeof(A));
         outfile.close();
         gotoxy(33,10);
           cout<<"PROCESSING...";
           sleep(1);
           gotoxy(36,12);
           cout<<".";
           sleep(1);
           cout<<" .";
           sleep(1);
           cout<<" .";
           sleep(2);

           clrscr();
         gotoxy(30,10);
         cout<<"ACCOUNT CREATED!!!";
         gotoxy(20,12);
         cout<<"Press Enter to return to login page";
         getch();
         login();
    }
 }
 else

     {  cout<<"\n Press enter to proceed...";
         getch();
         clrscr();
         ofstream outfile("accounts.dat",ios::binary||ios::app);
         ofstream out(acc_name,ios::binary);
         out.close();

         outfile.write((char*)&A,sizeof(A));
         outfile.close();
         gotoxy(33,10);
           cout<<"PROCESSING...";
           sleep(1);
           gotoxy(36,12);
           cout<<".";
           sleep(1);
           cout<<" .";
           sleep(1);
           cout<<" .";
           sleep(2);

           clrscr();
         gotoxy(30,10);
         cout<<"ACCOUNT CREATED!!!";
         gotoxy(20,12);
         cout<<"Press Enter to return to login page";
         getch();
         login();
         }

}
 else
 {gotoxy(10,13);
 cout<<"Passwords do no match!! Try again...";
  read_d();
 }
}
}

void account::assign(account X)
{strcpy(acc_name,X.ret_name());
 strcpy(passw,X.ret_passw());
 strcpy(sub_type,X.ret_sub());
 strcpy(type,X.ret_type());
 balance=X.ret_balance();
 strcpy(bankname,X.bankname);
 passb=X.passb;
 accno=X.ret_accno();
 points=X.points;
 no_completed=X.no_completed;
 no_tasks=X.no_tasks;
 spent=X.spent;
 }

 void account::withdraw(float price)
 {if(balance-price<0)
     {cout<<"\n INSUFFICIENT FUNDS";
     }
 else

  {balance-=price;
  spent+=price;
  }
 }

 void account::deposit(float price)
 {balance+=price;
 }



 char* account::ret_name()
 {return(acc_name);
 }
char* account::ret_sub()
 {return(sub_type);
 }
 char* account::ret_passw()
 {
  return(passw);
 }

 char* account::ret_type()
 {
  return(type);
 }

 float account::ret_balance()
 { return(balance);
 }

 int account::ret_passb()
 {return(passb);
 }

 int account::ret_accno()
 {return(accno);
 }

struct file_acc
{ char tasks[150];
  char type[25];
  char due_date[11];
  int priority;
  char sidenotes[250];
  int status;
}S;

struct item
{ int code;
 char name[25];
 char type[25];
 float price;
}I;

struct quotes
{ char quo[150];
  char by[25];
};


void main()
{int ch;
int y;

gotoxy(33,10);
cout<<" WELCOME TO";
gotoxy(35,12);
cout<<" DONE!";
gotoxy(20,14);
cout<<"A task management solution from SERF inc.";
gotoxy(27,18);
cout<<"PRESS ANY KEY TO CONTINUE...";
getch();

 while(1)
 { intro();
  if(!strcmpi(T.ret_type(),"general"))
  {
do
{ clrscr();
  display_header();
  get_date();

  cout<<"\t POINTS :"<<T.points ;
 line();
  gotoxy(36,8);
  cout<<"Welcome";
  gotoxy(33,10);
  cout<<"1.Overview";
  gotoxy(33,11);
  cout<<"2.Add task";
  gotoxy(33,12);
  cout<<"3.Completed";
  gotoxy(33,13);
  cout<<"4.Calculator";
  gotoxy(33,14);
  cout<<"5.Finance";
  gotoxy(33,15);
  cout<<"6.View Statistics";
  gotoxy(33,16);
  cout<<"7.Mart";
  gotoxy(33,17);
  cout<<"8.View account details";
  gotoxy(33,18);
  cout<<"9.Logout";
  gotoxy(1,21);
   line();
  display_quotes();
  line();

  gotoxy(28,19);
  cout<<" Enter the choice:";
  cin>>ch;

  switch(ch)
  {case 1: y=overview();break;
   case 2:addtask();break;
   case 3:completed();break;
   case 4:calc();break;
   case 5:y=finance();break;
   case 6:stats();break;
   case 7:mart();break;
   case 8:details();break;
   case 9:{clrscr();
           gotoxy(33,10);
           cout<<"LOGGING OUT";
           sleep(1);
           gotoxy(36,12);
           cout<<".";
           sleep(1);
           cout<<" .";
           sleep(1);
           cout<<" .";
           sleep(2);

           clrscr();
           gotoxy(34,12);

           cout<<"SUCCESSFUL";
           sleep(1);
           break;
          }
  default:cout<<"\n Invalid Choice!";
  }

  clrscr();
  }
  while(ch!=9);

  }

 else
     {
     do
{
      clrscr();
  display_header();
  get_date();
 line();
  gotoxy(36,8);
  cout<<"Welcome";
  gotoxy(33,10);
  cout<<"1.Overview";
  gotoxy(33,11);
  cout<<"2.Add task";
  gotoxy(33,12);
  cout<<"3.Completed";
  gotoxy(33,13);
  cout<<"4.Calculator";
  gotoxy(33,14);
  cout<<"5.View Statistics";
  gotoxy(33,15);
  cout<<"6.View Account details";
  gotoxy(33,16);
  cout<<"7.Logout";
  gotoxy(1,21);
   line();
  display_quotes();
  line();

  gotoxy(28,19);
  cout<<" Enter the choice:";
  cin>>ch;

  switch(ch)
  {case 1: y=overview();break;
   case 2:addtask();break;
   case 3:completed();break;
   case 4:calc();break;
   case 5:stats();break;
   case 6:details();break;
   case 7:{clrscr();
           gotoxy(33,10);
           cout<<"LOGGING OUT";
           sleep(1);
           gotoxy(36,12);
           cout<<".";
           sleep(1);
           cout<<" .";
           sleep(1);
           cout<<" .";
           sleep(2);

           clrscr();
           gotoxy(34,12);

           cout<<"SUCCESSFUL";
           sleep(1);
           break;
          }
  default:cout<<"\n Invalid Choice!";
  }

  clrscr();
  }
  while(ch!=7);

  }


     }
 }



 void intro()
 {
  int ch;
 clrscr();
 gotoxy(25,8);
 cout<<" Do you already have an account";
 gotoxy(25,9);
 cout<<" or would you like to create one?";
 gotoxy(18,13);
 cout<<"1. Yes I have one. Take me to login screen";
 gotoxy(18,14);
 cout<<"2. I don't have one, but lets go ahead and make one";
 gotoxy(28,16);
 cout<<" Press 3 if you wish to exit ";
 gotoxy(33,19);

 cout<<" Enter the choice:";
 cin>>ch;

 switch(ch)
 {case 1:{
          login(); break;
         }
  case 2:A.read_d(); break;
  case 3: exit(0);
 default:{ cout<<"\n INVALID!!!";
           cout<<"\n PRESS ANY KEY TO CONTINUE!!!";
           getch();
           intro();
          }
 }
}

 void display_quotes()
{ static int i=random(10);
  quotes q;
  ifstream infile("quotes.dat",ios::binary);
  if(i>10)
    i=0;

  infile.seekg(i++*sizeof(q));

  infile.read((char*)&q,sizeof(q));
  cout<<" "<<q.quo;
  cout<<" -->"<<q.by;
}


void line()
{ cout<<"\n";
for(int i=0;i<80;i++)
    cout<<"-";
}

void get_date()
{ char buf[150],c[50];
 time_t raw;
 struct tm * cur;
 time(&raw);
 cur=localtime(&raw);
 strftime(buf,150,"Current date and time : %a, %d %b %Y, %I:%M%p",cur);

 cout<<" "<<buf;
 }

int check_user(char name[],char pass[])
{ int flag=0;
 ifstream infile("accounts.dat",ios::binary);
  infile.seekg(0);
 while(infile.read((char*)&A,sizeof(A)))
 { if(!strcmpi(name,A.ret_name()))
      { if(!strcmpi(pass,A.ret_passw()))
           flag=1;

      }
 }
 infile.close();

 return(flag);
 }

int check_user(char name[])
{ int flag=0;
 ifstream infile("accounts.dat",ios::binary);
 infile.seekg(0);
 while(infile.read((char*)&A,sizeof(A)))
 { if(!strcmpi(name,A.ret_name()))
      flag=1;
 }
 infile.close();

 return(flag);
 }

 void login()
{char saccn[25],spass[25];
         clrscr();
         gotoxy(35,5);
         cout<<" LOGIN ";
         gotoxy(30,10);
         cout<<"Enter Username: ";
         gets(saccn);
         gotoxy(30,11);
        cout<<"Enter Password: ";
        gets(spass);
 if(check_user(saccn,spass)==1)
    { clrscr();
    gotoxy(33,10);
           cout<<"LOGGING IN";
           sleep(1);
           gotoxy(36,12);
           cout<<".";
           sleep(1);
           cout<<" .";
           sleep(1);
           cout<<" .";
           sleep(2);

           clrscr();
           gotoxy(32,12);

           cout<<"ACCESS GRANTED";
           sleep(1);

     ifstream infile("accounts.dat",ios::binary);
 infile.seekg(0);
 while(infile.read((char*)&A,sizeof(A)))
 { if(!strcmpi(saccn,A.ret_name()))
     { T.assign(A);
      infile.close();
      break;}
 }

    }
 else
    {gotoxy(22,15);
    cout<<"INCORRECT USER NAME OR PASSWORD!!!";
    getch();
     login();
    }
 }

 void addtask()
 {
 ofstream outfile(T.ret_name(),ios::binary|ios::app);
  clrscr();
  display_header();
 ifstream infile("accounts.dat",ios::binary);
 ofstream out("temp.dat",ios::binary);

  char name[25];
               strcpy(name,T.ret_name());


  char ch;
  do
  {
  cout<<"\n Enter the task:\n";
  gets(S.tasks);
  cout<<"\n Enter the type (Homework, tests, extra, chores...):\n";
  gets(S.type);
  cout<<"\n Does your task have a due date(Y/N)?";
  cin>>ch;
  if(ch=='Y'||ch=='y')
     {cout<<"\n Enter the due date (Enter as dd mm yyyy):";
     gets(S.due_date);
      }
   cout<<"\n Enter the priority (1 to 5, where 1 is relaxed and 5 is urgent):";
   cin>>S.priority;
   cout<<"\n Do you wish to add any side notes?";
   cin>>ch;
   if(ch=='Y'||ch=='y')
       {cout<<"\n Notes:\n";
       gets(S.sidenotes);}

       S.status=0;
   outfile.write((char*)&S,sizeof(S));



               while(infile.read((char*)&A,sizeof(A)))
                    { if(!strcmpi(name,A.ret_name()))
                         {A.no_tasks+=1;
                         T.no_tasks=A.no_tasks;
                         }
                      out.write((char*)&A,sizeof(A));
                    }
                infile.close();
                out.close();

                remove("accounts.dat");
                rename("temp.dat","accounts.dat");
   cout<<"\n Do you want to add more tasks(Y/N):";
   cin>>ch;
  }
  while(ch=='y'||ch=='Y');

   outfile.close();

 }

 int overview()
 {
 do
 {ifstream infile(T.ret_name(),ios::binary);
 clrscr();
 int flag=0;
 display_header();
  cout<<"\n All tasks\n";
 gotoxy(2,7);
 cout<<"TASKS";
 gotoxy(40,7);
 cout<<"TYPE";
 gotoxy(55,7);
 cout<<"DUE DATE";
 gotoxy(65,7);
 cout<<"PRIORITY";

int x=8;

 while(infile.read((char*)&S,sizeof(S)))
 { if(S.status!=1)
  {gotoxy(2,x);
  cout<<S.tasks;
  gotoxy(40,x);
  cout<<S.type;
  gotoxy(55,x);
  cout<<S.due_date;
  gotoxy(65,x);
  cout<<S.priority;
  x++;
  }
 }
 line();
 infile.close();
 cout<<"\n USE ARROW KEYS TO NAVIGATE";
 cout<<"\n PRESS C TO CHECK OFF";
 cout<<"\n PRESS A TO VIEW ADDITIONAL DETAILS";
 cout<<"\n PRESS D TO DELETE";
 cout<<"\n PRESS R TO EXIT";
 int m=0;
  int n=no_taskrec();
  x=8;
 char c;

 gotoxy(1,x);

 c=getch();
  switch(c)
  { case 72: { if(m>0)
                  {
                   gotoxy(4,--x);
                   --m;
                   }
               break;
             }
    case 80: { if(m<n-1)
                  {
                   gotoxy(4,++x);
                   ++m;
                  }
               break;
             }
    case 'r':
    case 'R':return(0);
    case 'C':
    case 'c': {ifstream infile(T.ret_name(),ios::binary);
               ofstream outfile("temp.dat",ios::binary);
               int i=0;
               while(infile.read((char*)&S,sizeof(S)))
               {if(S.status!=1)
                  {if(i==m)
                    {S.status=1;


                     i++;
                    }
                  }
               outfile.write((char*)&S,sizeof(S));
               }
               infile.close();
               outfile.close();

               remove(T.ret_name());
               rename("temp.dat",T.ret_name());

               infile.open("accounts.dat",ios::binary);
               outfile.open("temp.dat",ios::binary);

               char name[25];
               strcpy(name,T.ret_name());

               while(infile.read((char*)&A,sizeof(A)))
                    { if(!strcmpi(name,A.ret_name()))
                         { A.points+=200;
                           A.no_completed+=1;
                           T.points=A.points;
                           T.no_completed=A.no_completed;
                         }
                      outfile.write((char*)&A,sizeof(A));
                    }
                infile.close();
                outfile.close();

                remove("accounts.dat");
                rename("temp.dat","accounts.dat");


               }break;
    case 'a':
    case 'A':{ ifstream infile(T.ret_name(),ios::binary);
               int i=0;
               clrscr();

                display_header();

               while(infile.read((char*)&S,sizeof(S)))
               {if(S.status!=1)
                   {if(i==m)
                      {gotoxy(2,7);
                      cout<<"TASK:"<<S.tasks;
                      gotoxy(2,9);
                      cout<<"\nTYPE:"<<S.type;
                      gotoxy(2,11);
                      cout<<"\nDUE DATE:"<<S.due_date;
                      gotoxy(2,13);
                      cout<<"\nPRIORITY:"<<S.priority;
                      gotoxy(2,15);
                      cout<<"\nSIDENOTES:"<<S.sidenotes;
                      line();
                      break;
                      }
                   }
               }
              infile.close();

              cout<<"\n\n PRESS ANY KEY TO RETURN";
              getch();

             }
  case 'd':
  case 'D':{
             ifstream infile(T.ret_name(),ios::binary);
             ofstream outfile("temp.dat",ios::binary);
               int i=0;
               clrscr();

                display_header();
              cout<<"\n\n DO YOU REALLY WISH TO DELETE THE ITEM(Y/N):";
              char c;
              cin>>c;
              if(c=='y'||c=='Y')
                {
                 while(infile.read((char*)&S,sizeof(S)))
                     {if(S.status!=1)
                         {if(i!=m)
                              {outfile.write((char*)&S,sizeof(S));
                                  i++;
                              }
                         }
                     else
                       {
                          outfile.write((char*)&S,sizeof(S));

                       }


                       }
                     
               infile.close();
               outfile.close();
               char co[25];
               strcpy(co,T.ret_name());
               remove(T.ret_name());
               rename("temp.dat",co);

              cout<<"\n\n ITEM DELETED!!!";

            }
            else
              cout<<"\n\n ITEM NOT DELETED!!!";
            cout<<"\n\n Press any key to continue...";
            getch();
            }

  }


  }while(1);


}


 void display_header()
 {  gotoxy(20,2);
  cout<<"DONE! - a unique task management solution ";
   gotoxy(15,3);
  cout<<"SERF inc., Infinite Loop, Cupertino, CA 95014, USA" ;
   line();

 }

 int no_taskrec()
 {
  ifstream infile(T.ret_name(),ios::binary);
  int n=0;

  while(infile.read((char*)&S,sizeof(S)))
  { if(S.status!=1)
    n++;
  }


  return(n);

 }

void completed()
{

   ifstream infile(T.ret_name(),ios::binary);

   clrscr();

 display_header();
 cout<<"\n COMPLETED TASKS\n";
 line();
 gotoxy(2,9);
 cout<<"TASKS";
 gotoxy(40,9);
 cout<<"TYPE";
 gotoxy(55,9);
 cout<<"DUE DATE";
 gotoxy(65,9);
 cout<<"PRIORITY";

 int x=10;

 while(infile.read((char*)&S,sizeof(S)))
 { if(S.status==1)
  {gotoxy(2,x);
  cout<<S.tasks;
  gotoxy(40,x);
  cout<<S.type;
  gotoxy(55,x);
  cout<<S.due_date;
  gotoxy(65,x);
  cout<<S.priority;
  x++;
  }
 }

line();
        infile.close();
cout<<"\n Press any key to return";
getch();
}


void calc()
{ clrscr();
display_header();


double X, Y;
double resultPow, resultSin, resultCos;
char userChoice;
cout<<"\n\n";
cout << "**********************************" << endl;
cout << "* 1 - Add *" << endl;
cout << "* 2 - Subtract *" << endl;
cout << "* 3 - Multiply *" << endl;
cout << "* 4 - Divide *" << endl;
cout << "* 5 - Raise X to the power Y *" << endl;
cout << "* 6 - Sine ( X ) *" << endl;
cout << "* 7 - Cosine ( X ) *" << endl;
cout << "* *" << endl;

cout << "**********************************" << endl;
char ch='y' ;
while(ch=='y'||ch=='Y')
{

cout << "\n Enter First Number : ";
cin >> X;

cout << "\n Enter Option Number : ";
cin >> userChoice;



resultSin = sin (X*PI/180);

resultCos = cos (X*PI/180);





switch(userChoice)
{
case '1':
cout << "\n Enter Second Number : ";
cin >> Y;
cout << "\n The Result is " << "#### " << (X + Y) << " ####" << endl;
break;

case '2':
cout << "\n Enter Second Number : ";
cin >> Y;
cout << "\n The Result is " << "#### " << (X - Y) << " ####" << endl;
break;

case '3':
cout << "\n Enter Second Number : ";
cin >> Y;
cout << "\n The Result is " << "#### " << (X * Y) << " ####" << endl;
break;

case '4':
cout << "\n Enter Second Number : ";
cin >> Y;
cout << "\n The Result is " << "#### " << (X / Y) << " ####" << endl;
break;

case '5':
cout << "\n Enter Second Number : ";
cin >> Y;
resultPow = pow (X,Y);
cout << "\n\n Answer = " << "#### " << resultPow << " ####" << endl;
break;

case '6':
cout << "\n\n Answer = " << "#### " << resultSin << " ####" << endl;
break;

case '7':
cout << "\n\n Answer = " << "#### " << resultCos << " ####" << endl;
break;
}
cout << "Do you wish to continue? (y/n): ";
cin >> ch;
}
}


void details()
{
clrscr();
char ch;
display_header();

cout<<"\n\n ACCOUNT DETAILS:";
cout<<"\n Account name:"<<T.ret_name();
cout<<"\n Password:"<<T.ret_passw();
cout<<"\n Subscription Type:"<<T.ret_sub();
cout<<"\n User Type:"<<T.ret_type();
line();

if(!strcmpi(T.ret_type(),"general"))
{cout<<"\n\n BANK DETAILS";
cout<<"\n Bankname:"<<T.bankname;
cout<<"\n Bank Account number:"<<T.ret_accno();
cout<<"\n Balance:"<<T.ret_balance();
cout<<"\n PASSWORD:"<<T.ret_passb();
}

cout<<"\n\n\n POINTS:"<<T.points;

cout<<"\n\n\n PRESS U TO UPDATE BALANCE";
cout<<"\n PRESS ANY OTHER KEY TO RETURN"; ch=getch();
switch(ch)
{ case 'U':
  case 'u':{clrscr();
            display_header();
             cout<<"\n\n BALANCE UPDATION";
             cout<<"\n\n Enter the amount to be added:";
             float add;
             cin>>add;
             ifstream infile("accounts.dat",ios::binary);
               ofstream outfile("temp.dat",ios::binary);

               char name[25];
               strcpy(name,T.ret_name());

               while(infile.read((char*)&A,sizeof(A)))
                    { if(!strcmpi(name,A.ret_name()))
                         { A.deposit(add);
                          T.deposit(add);
                         }
                      outfile.write((char*)&A,sizeof(A));
                    }
                infile.close();
                outfile.close();
                remove("accounts.dat");
                rename("temp.dat","accounts.dat");

               cout<<"\n\nBALANCE UPDATED!!!!";

               cout<<"\n\n PRESS ANY KEY TO RETURN";
               getch();
               }

}

}

void stats()
{clrscr();
display_header();
cout<<"\n USER STATS \n";

ifstream infile("accounts.dat",ios::binary);
char name[25];
strcpy(name,T.ret_name());
while(infile.read((char*)&A,sizeof(A)))
{ if(!strcmpi(name,A.ret_name()))
    { cout<<"\n\n No of task completed:"<<A.no_completed;
     cout<<"\n No of tasks created:"<<A.no_tasks;

     if(!strcmpi(A.ret_type(),"general"))
        {cout<<"\n\n BANK STATS";
        cout<<"\n Total balance:"<<A.ret_balance();
        cout<<"\n Total money spent:"<<A.spent;
        }
    break;
   }
}

infile.close();
cout<<"\n Enter any key to continue...";
getch();
}


 int finance()
 {char ch;
 do
 {clrscr();
 display_header();

gotoxy(25,7);
cout<<"WELCOME TO FINANCE by SERF.inc";
gotoxy(23,9);
cout<<"Make bill payments right from the app";


int n=2;

gotoxy(30,13);
cout<<"Electricity bill";
gotoxy(30,14);
cout<<"Water bill";
gotoxy(30,15);
line();
cout<<"\n\n USE ARROW KEYS TO NAVIGATE";
cout<<"\n PRESS C TO ENTER PAYMENT MODE";
cout<<"\n PRESS R TO RETURN TO HOMEPAGE";

int x=13;
 int m=0;
 char c;
 gotoxy(29,x);
 do
 {
 c=getch();
  switch(c)
  { case 72: { if(m>0)
                  {
                   gotoxy(29,--x);
                   --m;
                   }
               break;
             }
    case 80: { if(m<n-1)
                  {
                   gotoxy(29,++x);
                   ++m;
                  }
               break;
             }
    case 'r':
    case 'R':return(0);
    case 'c':
    case 'C':{if(m==0)
                {clrscr();
                 display_header();
                 gotoxy(30,7);
                 cout<<"Electricity Bill";
                 gotoxy(2,9);
                 cout<<"AMOUNT TO BE PAID: 300KD";
                 gotoxy(2,11);
                 cout<<" Enter P TO PAY, any other alphabet to cancel:";
                 cin>>ch;
                 if(ch=='p'||ch=='P')
                    { ifstream infile("accounts.dat",ios::binary);
               ofstream outfile("temp.dat",ios::binary);

               char name[25];
               strcpy(name,T.ret_name());

               while(infile.read((char*)&A,sizeof(A)))
                    { if(!strcmpi(name,A.ret_name()))
                         { A.withdraw(300);
                          T.withdraw(300);
                          A.spent+=300;
                          A.spent=T.spent;
                         }
                      outfile.write((char*)&A,sizeof(A));
                    }
                infile.close();
                outfile.close();

                remove("accounts.dat");
                rename("temp.dat","accounts.dat");
                cout<<"\n\n BILL PAID";
                cout<<"\n\n PRESS ANY KEY TO CONTINUE:";
                getch();
                finance();
                    }
                      else
                          finance();
                    }
                else
                   if(m==1)
                     { clrscr();
                 display_header();
                 gotoxy(30,7);
                 cout<<"Water Bill";
                 gotoxy(2,9);
                 cout<<"AMOUNT TO BE PAID: 200KD";
                 gotoxy(2,11);
                 cout<<" Enter P TO PAY, any other alphabet  to cancel:";
                 cin>>ch;
                 if(ch=='p'||ch=='P')
                    { ifstream infile("accounts.dat",ios::binary);
               ofstream outfile("temp.dat",ios::binary);

               char name[25];
               strcpy(name,T.ret_name());

               while(infile.read((char*)&A,sizeof(A)))
                    { if(!strcmpi(name,A.ret_name()))
                         { A.withdraw(200);
                          T.withdraw(200);

                         }
                      outfile.write((char*)&A,sizeof(A));
                    }
                infile.close();
                outfile.close();

                remove("accounts.dat");
                rename("temp.dat","accounts.dat");
                cout<<"\n\n BILL PAYED";
                cout<<"\n\n PRESS ANY KEY TO CONTINUE:";
                getch();
                finance();

                    }
                    else
                        finance();

                     }
                      break; }

  }

  }while(1);

 }while(7);


}


void mart()
{


int ch,code,no[10],i=0,x;
char c;
do
{clrscr();
display_header();
 gotoxy(25,7);
 cout<<"Welcome to MART, an initiative by SERF and Amazon";
 gotoxy(10,9);
 cout<<"Choose a category, add to shooping cart, PURCHASE !!!";
 gotoxy(10,10);
 cout<<"You may purchase a maximum of 10 items at a time";

 gotoxy(30,13);
 cout<<"1.Electronics";
 gotoxy(30,14);
 cout<<"2.Garments";
 gotoxy(30,15);
 cout<<"3.Groceries";
 gotoxy(30,16);
 cout<<"4.Stationary";
 gotoxy(30,17);
 cout<<"5.View shopping cart";
 gotoxy(30,18);
 cout<<"6.Make Payment";
 gotoxy(30,19);
 cout<<"7.EXIT";
 gotoxy(30,21);


 cout<<"Enter the choice:";

 cin>>ch;

 switch(ch)
 {
  case 1: { clrscr();
            display_header();
            gotoxy(40,7);
            ifstream infile("items.dat",ios::binary);
            cout<<"ELECTRONICS";

            gotoxy(2,9);
            cout<<"Code";
            gotoxy(6,9);
            cout<<"Item";
            gotoxy(65,9);
            cout<<"Price";

              x=11;
            while(infile.read((char*)&I,sizeof(I)))
             { if(!strcmpi(I.type,"electronics"))

              { gotoxy(2,x);
               cout<<I.code;

               gotoxy(6,x);
               cout<<I.name;

               gotoxy(65,x);
               cout<<I.price;

               x=x+2;
              }

             }



             cout<<"\n\n Enter the code:";
             cin>>code;

             cout<<"\n Do you wish to add this item in the cart";
             cin>>c;

             if(c=='y'||c=='Y')
               {
                no[i++]=code;
                cout<<"\n ITEM ADDED TO CART";

                }
            else
               {cout<<"\n ITEM NOT ADDED TO CART";
               }
           break;
           infile.close();
           }
case 2: { clrscr();
            display_header();
            gotoxy(40,7);
            ifstream infile("items.dat",ios::binary);
            cout<<"GARMENTS";

            gotoxy(2,9);
            cout<<"Code";
            gotoxy(6,9);
            cout<<"Item";
            gotoxy(65,9);
            cout<<"Price";

              x=11;
            while(infile.read((char*)&I,sizeof(I)))
             { if(!strcmpi(I.type,"garments"))

              { gotoxy(2,x);
               cout<<I.code;

               gotoxy(6,x);
               cout<<I.name;

               gotoxy(65,x);
               cout<<I.price;
                  x=x+2;
              }

             }



             cout<<"\n\n Enter the code:";
             cin>>code;

             cout<<"\n Do you wish to add this item in the cart";
             cin>>c;

             if(c=='y'||c=='Y')
               {
                no[i++]=code;
                cout<<"\n ITEM ADDED TO CART";

                }
            else
               {cout<<"\n ITEM NOT ADDED TO CART";
               }
           break;
           infile.close();
           }
case 3: {clrscr();
            display_header();
            gotoxy(40,7);
            ifstream infile("items.dat",ios::binary);
            cout<<"GROCERIES";

            gotoxy(2,9);
            cout<<"Code";
            gotoxy(6,9);
            cout<<"Item";
            gotoxy(65,9);
            cout<<"Price";

              x=11;
            while(infile.read((char*)&I,sizeof(I)))
             { if(!strcmpi(I.type,"groceries"))

              { gotoxy(2,x);
               cout<<I.code;

               gotoxy(6,x);
               cout<<I.name;
               gotoxy(65,x);
               cout<<I.price;
                  x=x+2;
              }

             }
               cout<<"\n\n Enter the code:";
             cin>>code;

             cout<<"\n Do you wish to add this item in the cart";
             cin>>c;

             if(c=='y'||c=='Y')
               {
                no[i++]=code;
                cout<<"\n ITEM ADDED TO CART";

                }
            else
               {cout<<"\n ITEM NOT ADDED TO CART";
               }
           break;
           infile.close();
           }

case 4:{    clrscr();
            display_header();
            gotoxy(40,7);
            ifstream infile("items.dat",ios::binary);
            cout<<"STATIONARY";

            gotoxy(2,9);
            cout<<"Code";
            gotoxy(6,9);
            cout<<"Item";
            gotoxy(65,9);
            cout<<"Price";

              x=11;
            while(infile.read((char*)&I,sizeof(I)))
             { if(!strcmpi(I.type,"stationary"))

              { gotoxy(2,x);
               cout<<I.code;

               gotoxy(6,x);
               cout<<I.name;
               gotoxy(65,x);
               cout<<I.price;
                  x=x+2;
              }

             }
               cout<<"\n\n Enter the code:";
             cin>>code;

             cout<<"\n Do you wish to add this item in the cart";
             cin>>c;

             if(c=='y'||c=='Y')
               {
                no[i++]=code;
                cout<<"\n ITEM ADDED TO CART";

                }
            else
               {cout<<"\n ITEM NOT ADDED TO CART";
               }
           break;
           infile.close();
           }
case 5:{clrscr();
        display_header();
        gotoxy(40,7);
        cout<<"SHOPPING CART";


        ifstream infile("items.dat",ios::binary);
          gotoxy(2,9);
            cout<<"Code";
            gotoxy(6,9);
            cout<<"Item";
            gotoxy(65,9);
            cout<<"Price";
         x=11;
        while(infile.read((char*)&I,sizeof(I)))
         { for(int j=0;j<=i;j++)
               {if(I.code==no[j])
                   {gotoxy(2,x);
               cout<<I.code;

               gotoxy(6,x);
               cout<<I.name;
               gotoxy(65,x);
               cout<<I.price;
                  x=x+2;}
                  }
         }

         cout<<"\n\n WRONGLY ENTERED ITEM CODES WON'T BE DISPLAYED";
         line();

         cout<<"\n\n Do you wish to delete any item:";
         cin>>c;
         if(c=='y'||c=='Y')
            { int flag=0;
            cout<<"\n Enter the item code of the item:";
            cin>>code;

            for(int j=0;j<=i;j++)
            {if(no[j]==code)
                {flag=1;
                for(int k=j;k<i-1;k++)
                     {  no[k]=no[k+1];
                     }
                  i=i-1;
                  j=j-1;
                }
            }
            if(flag==1)
            cout<<"\n\n ITEM REMOVED";
            else
            cout<<"\n\n ITEM DOES NOT EXIST IN SHOPPING LIST";

           }

        cout<<"\n\n PRESS ANY KEY TO CONTINUE";
        getch();
        break;
        }
case 6:{float price;
        clrscr();
        display_header();
        cout<<"\n\n PRESS ANY KEY TO INITIATE PAYMENT PROCESS";
        getch();

        ifstream infile("items.dat",ios::binary);
        while(infile.read((char*)&I,sizeof(I)))
            {
             for(int j=0;j<=i;j++)
                { if(I.code==no[j])
                    price+=I.price;
                }
            }
            infile.close();
         cout<<"\n\n AMOUNT :"<<price;
         cout<<"\n\n TAX = 10% of price";
         cout<<"\n\n NET AMOUNT :"<<(price+(price*10/100.00));
         cout<<"\n\n CONFIRM PAYMENT(Y/N):";
         cin>>c;

         if(c=='y'||c=='Y')
           {  infile.open("accounts.dat",ios::binary);
               ofstream outfile("temp.dat",ios::binary);

               char name[25];
               strcpy(name,T.ret_name());

               while(infile.read((char*)&A,sizeof(A)))
                    { if(!strcmpi(name,A.ret_name()))
                         { A.withdraw(price);
                          T.withdraw(price);
                          A.spent+=price;
                          A.spent=T.spent;
                         }
                      outfile.write((char*)&A,sizeof(A));
                    }
                infile.close();
                outfile.close();

                remove("accounts.dat");
                rename("temp.dat","accounts.dat");
                sleep(1);
                cout<<"\n\n AMOUNT PAID";

                cout<<"\n\n PRESS ANY KEY TO CONTINUE";
                getch();
             }
         else
            { cout<<"\n\n PRESS ANY KEY TO CONTINUE";
                getch();
            }
        break;

        }
}

}while(ch<7);

}















