 #include<iostream.h>
 #include<graphics.h>
 #include<stdio.h>
 #include<conio.h>
 #include<stdlib.h>
 #include<string.h>
 #include<fstream.h>
 #include<ctype.h>
 #include<dos.h>
 fstream of;

void graph()
{
do{
for(int i=0;i<15;i++)
{

if(kbhit())
 break;
setbkcolor(BLACK);
settextstyle(3,0,4);
outtextxy(265,70,"WELCOME");
delay(200);
outtextxy(315,140,"TO");
delay(200);
outtextxy(150,210,"BANK MANAGEMENT SYSTEM");
setcolor(i);
settextstyle(3,0,2);
outtextxy(205,400,"  Press any key to continue...");
 }
}while(!kbhit());
getch();
 }



void password()
{
 char ch,b;int i=0;
 char user[30],pass[30],u[30]="admin",p[30]="admin";
   printf("\n\t\t\t**********************************");
   printf("\n\t\t\tWELCOME TO BANK MANAGEMENT SYSTEM");
   printf("\n\t\t\t**********************************");
printf("\n\n\n\n\n\t\t\t\tEnter username:");
gets(user);
printf("\n\t\t\t\tEnter password:");

 while((ch=getch())!=13)
  {
       if(ch==8)
     {if(i==0) continue;
     printf("\b \b");i--;continue;
     }
    printf("%c",'*');
    pass[i]=ch;
    i++;
  }
    pass[i]='\0';
    clrscr();
if(stricmp(user,u)==0&&stricmp(pass,p)==0) printf("Login successful\n");
else
{
do
{ textcolor(0);
	 textbackground(11);
clrscr();
printf("\b\t\t\tLogin unsuccessful\n\n\n\n");
cout<<"\t\t\tPress L to Login||Press E to Exit ";
cin>>b;
if(b=='E')
{exit(0);
}
if(b=='L')
{ textcolor(0);
	 clrscr();
password();
}
}
while(b!='E'& b!='L');
}
}

    class bank
    {
     public:

     char ano[6],act[1];
     long double balance;
     char name[30],adrs[30];
     public:
     void create()
     { 	 cout<<"\n\tENTER YOUR NAME :  ";
	 gets(name);
	 cout<<"\n\tENTER ACCOUNT NO." ;
	 cin>>ano;
	 cout<<"\n\tENTER YOUR ADDRESS : ";
	 gets(adrs);
	 cout<<"\n\tSAVING / CURRENT ACCOUNT ??(S/C) : ";
	 cin>>act;
	 cout<<"\n\tENTER THE AMOUNT OF MONEY : NRs.  ";
	 cin>>balance;
	 cout<<"\n\tYOUR ACCOUNT HAS BEEN CREATED :-)";
     }

     void deposit()
     {  long double amt;
	cout<<"\n\tEnter amount to deposit";
	cin>>amt;
	balance+=amt;
	cout<<"\n\tNew balance is Nrs.: "<<balance;
     }

     void withdraw()
     {  long double amt;

		cout<<"\n\tEnter amount to withdraw";
		cin>>amt;

		if((balance-amt)>=0)
		  {
		    balance-=amt;
		     cout<<"\n\tNew balance is Nrs.: "<<balance;
		}

		else
		    cout<<"\n\tWithdrawl denied !! Insufficient balance";

     }

     void twith(long double amt)
	{
		if((balance-amt)>=0)
		  {
		     balance-=amt;
		     cout<<"\n\t\tAmount transferred";

		}

		else
		    cout<<"\n\tTransfer denied !! Insufficient balance";

	}

     void tdep(long double amt)
     {
	 balance+=amt;

     }


     void search()
     {   cout<<"\n\t\tNAME :  "<<name;
	 cout<<"\n\t\tACCOUNT No.:"<<ano;
	 cout<<"\n\t\tADDRESS : "<<adrs;
	 cout<<"\n\t\tACCOUNT TYPE : "<<act;
	 cout<<"\n\t\tAMOUNT : NRs.  "<<balance;
     }
     void display()
     {   cout<<"\n\n NAME :  "<<name;
	 cout<<"\tACCOUNT No.:"<<ano;
	 cout<<"\tADDRESS : "<<adrs;
	 cout<<"\tACCOUNT TYPE : "<<act;
	 cout<<"\tAMOUNT : NRs. "<<balance;
     }
     void modify()
     {
       cout<<"\n\n\tModify address : ";
       cin>>adrs;
       cout<<"\n\tModify account type :";
       cin>>act;
     }
     char* return_ano()
     {return ano;
     }
    };

fstream fp;
bank b;
void write_act()
{char ch;
 fp.open("newbank.dat",ios::out|ios::app);

 b.create();
   fp.write((char*)&b,sizeof(bank));
   fp.close();
  }
  void display_spc(char n[])
  {
   cout<<"\n\t\t*******ACCOUNT DETAILS********\n";
   int flag=0;
   fp.open("newbank.dat",ios::in);
   while(fp.read((char*)&b,sizeof(bank)))
   {
   if((strcmpi(b.return_ano(),n)==0))
    {b.search();
    flag=1;
    }
   }
   fp.close();
   if (flag==0)
     cout<<"\n\t\tAccount does not exist";
     getch();
    }

 void modify_account()
 {char n[6];
  int found=0;
  clrscr();
  cout<<"\n\t\t*******MODIFY ACCOUNT RECORD*******";
  cout<<"\n\tEnter your account number";
  cin>>n;
  fp.open("newbank.dat",ios::in|ios::out);
  while(fp.read((char*)&b,sizeof(bank)) && found==0)
  {
   if(strcmpi(b.return_ano(),n)==0)
   { b.search();
    b.modify();
    int pos=-1*sizeof(b);
    fp.seekp(pos,ios::cur);
    fp.write((char*)&b,sizeof(bank));
    cout<<"\n\t\tAccount updated";
    found=1;
   }
  }
  fp.close();
  if(found==0)
  cout<<"\n\t\tRecord not found";
  getch();
  }

  void display_all()
   {
     clrscr();
     fp.open("newbank.dat",ios::in);
     if(!fp)
     {
      cout<<"\n\t\tFile could not open";
      getch();
      return;
     }
     cout<<"\n\t\tACCOUNT LIST\n";
     while(fp.read((char*)&b,sizeof(bank)))
     {
      b.display();
     }
     fp.close();
     getch();
   }

  void dep()
  { char n[6];
  int found=0;
  clrscr();
  cout<<"\n\t*****DEPOSIT AMOUNT*****";
  cout<<"\n\tEnter your account number";
  cin>>n;
  fp.open("newbank.dat",ios::in|ios::out);
  while(fp.read((char*)&b,sizeof(bank)) && found==0)
  {
   if(strcmpi(b.return_ano(),n)==0)
   {
    b.deposit();
    int pos=-1*sizeof(b);
    fp.seekp(pos,ios::cur);
    fp.write((char*)&b,sizeof(bank));
    found=1;
   }
  }
  fp.close();
  if(found==0)
  cout<<"\n\t\tRecord not found";
  getch();
  }

   void with()

     {
	char n[6];
	 int found=0;
	 clrscr();
	cout<<"\n\t*****WITHDRAW AMOUNT*****";
       cout<<"\n\tEnter your account number";
       cin>>n;
      fp.open("newbank.dat",ios::in|ios::out);
      while(fp.read((char*)&b,sizeof(bank)) && found==0)
    {
     if(strcmpi(b.return_ano(),n)==0)
   {
    b.withdraw();
    int pos=-1*sizeof(b);
    fp.seekp(pos,ios::cur);
    fp.write((char*)&b,sizeof(bank));
    found=1;
   }
  }
  fp.close();
  if(found==0)
  cout<<"\n\t\tRecord not found";
  getch();
  }

  void del()
  { int found=0;
    char n[6];
    clrscr();
    cout<<"\n\t\t\t********DELETE ACCOUNT*********";
    cout<<"\n\n\tEnter account number of your account to delete: ";
    cin>>n;
    fp.open("newbank.dat",ios::in|ios::out) ;
    fstream fp2;
    fp2.open("Temp.dat",ios::out) ;
    fp.seekg(0,ios::beg);
    while(fp.read((char*)&b,sizeof(bank)))
    {
     if(strcmpi(b.return_ano(),n)!=0)
      {
       fp2.write((char*)&b,sizeof(bank));

      }
      else
	 found=1;
    }
       fp2.close();
       fp.close();
       remove("newbank.dat");
       rename("Temp.dat","newbank.dat");
       if(found==1)
       cout<<"\n\t\tAccound Deleted";
       else
       cout<<"\n\t\tAccount not found";
      getch();
  }

  void transfer()
  {   char s[6],r[6];
      int found=0;
      long double x;
      clrscr();
      cout<<"\n\t\t\t******TRANSFER AMOUNT********";
      cout<<"\n\tEnter account number of sender";
      cin>>s;
      cout<<"\n\tEnter amount to transfer: ";
      cin>>x;
      cout<<"\n\tEnter account number of receiver";
      cin>>r;
	  fp.open("newbank.dat",ios::in|ios::out);
      while(fp.read((char*)&b,sizeof(bank)) && found==0)
    {
     if(strcmpi(b.return_ano(),s)==0)
   {
    b.twith(x);
    int pos=-1*sizeof(b);
    fp.seekp(pos,ios::cur);
    fp.write((char*)&b,sizeof(bank));
    found=1;
   }
  }
  fp.close();
  if(found==0)
  {
  cout<<"\n\t\tSender account not found";
  }
  found=2;
      fp.open("newbank.dat",ios::in|ios::out);
      while(fp.read((char*)&b,sizeof(bank)) && found==2)
    {
     if(strcmpi(b.return_ano(),r)==0)
   {
    b.tdep(x);
    int pos=-1*sizeof(b);
    fp.seekp(pos,ios::cur);
    fp.write((char*)&b,sizeof(bank));
    found=3;
   }
  }
  fp.close();
  if(found==2)
  cout<<"\n\t\tReceiver account not found";
  getch();


  }

  void main()
  {      int gd=DETECT,gm;
	 initgraph(&gd,&gm,"..\\bgi");
	 graph();
	     closegraph();
	     password();
	int index;
	do
	{

    cout<<"\n\n\tPRESS 1 TO CREATE ACCOUNT\n"<<"\tPRESS 2 TO DEPOSITE AMOUNT\n"<<"\tPRESS 3 TO WITHDRAW AMOUNT \n"<<"\tPRESS 4 TO SEARCH ACCOUNT \n"<<"\tPRESS 5 TO MODIFY ACCOUNT \n"<<"\tPRESS 6 TO TRANSFER AMOUNT\n"<<"\tPRESS 7 TO DELETE ACCOUNT\n"<<"\tPress 8 TO DISPLAY ALL ACCOUNTS\n"<<"\tPRESS 9 TO EXIT\n";
    cout<<"\tYour option......";
    cin>>index;
    switch(index)
    { case 1: clrscr();
	      write_act();
	      break;
     case 2:

	    dep();
	      break;

     case 3:
	       with();
	      break;
     case 4:
	     clrscr();
	     char no[6];
	     cout<<"\n\tEnter your account number";
	     cin>>no;
	     display_spc(no);
	    break;
     case 5:
	      clrscr();
	      modify_account();
	      break;
     case 6:
	   transfer();
	   break;
     case 7:
	  del();
	 break;
     case 8:
	    clrscr();
	    cout<<"******ALL ACCOUNTS*******";
	    display_all();
	  break;
    }
  }
  while(index!=9);
  }