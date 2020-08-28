#include<kootty.h>

class budget
{
	public:
		char day[6];
		char month[6];
		char year[6];
		char details[30];
		long money;

		void getdata()
		{
			clrscr();
			struct date d;
			getdate(&d);
			itoa(d.day,day,10);
			itoa(d.mon,month,10);
			itoa(d.year,year,10);
			cout<<"\n\n\n\n\n\n\n\n\n";
			cout<<"\n\t\t ษออออออออออออออออออออออออออออออออออออออออออป";
			cout<<"\n\t\t บ              INSERT DATA                 บ";
			cout<<"\n\t\t บ                                          บ";
			cout<<"\n\t\t บ TODAY'S DATE:                            บ";
			cout<<"\n\t\t บ SPENT MONEY :                            บ";
			cout<<"\n\t\t ศออออออออออออออออออออออออออออออออออออออออออผ";
			gotoxy(34,14);
			cout<<day<<"/"<<month<<"/"<<year;
			gotoxy(34,15);
			cin>>money;
			clrscr();
			cout<<"\n\n\n\n\n\n\n\n\n";
			cout<<"\n\t\t ษออออออออออออออออออออออออออออออออออออออออออป";
			cout<<"\n\t\t บ              INSERT DATA                 บ";
			cout<<"\n\t\t บ                                          บ";
			cout<<"\n\t\t บ TODAY'S DATE:                            บ";
			cout<<"\n\t\t บ SPENT MONEY :                            บ";
			cout<<"\n\t\t บ DETAILS :                                บ";
			cout<<"\n\t\t ศออออออออออออออออออออออออออออออออออออออออออผ";
			gotoxy(34,14);
			cout<<day<<"/"<<month<<"/"<<year;
			gotoxy(34,15);
			cout<<money;
			gotoxy(30,16);
			gets(details);
		}
		char* retday()
		{
			return day;
		}
		char* retmonth()
		{
			return month;
		}
		char* retyear()
		{
			return year;
		}
};

//**************GLOBAL DECLEARATION*****************************************
fstream file;
budget b;
//**************************************************************************
void insert()
{
	clrscr();
	char ch;
	file.open("budget.dat",ios::out|ios::app);
	do
	{
		b.getdata();
		file.write((char*)&b,sizeof(b));
		cout<<"\n\n\t\t DO YOU WANT TO ENTER MORE (y/n): ";
		ch=getche();
		delay(500);
	}while(ch=='y'||ch=='Y');
	file.close();
}
void displayday()
{
	clrscr();
	long sum=0;
	int flag=0;
	char d[3];
	cout<<"\n\n\n\n\n\n\n\n\n";
	cout<<"\n\t\t ษออออออออออออออออออออออออออออออออออออออออออป";
	cout<<"\n\t\t บ              TOTAL SPENT                 บ";
	cout<<"\n\t\t บ                                          บ";
	cout<<"\n\t\t บ ENTER DATE:                              บ";
	cout<<"\n\t\t ศออออออออออออออออออออออออออออออออออออออออออผ";
	gotoxy(32,14);
	cin>>d;
	file.open("budget.dat",ios::in);
	while(file.read((char*)&b,sizeof(b)))
	{

		if(strcmpi(b.retday(),d)==0)
		{
		       sum+=b.money;
		       flag=1;
		}
	}
	file.close();
	if(flag==0)
	cout<<"\n\n\t\t  NO DATA FOUND ON THAT DAY!!!";
	else
	{
		clrscr();
		cout<<"\n\n\n\n\n\n\n\n\n";
		cout<<"\n\t\t ษออออออออออออออออออออออออออออออออออออออออออป";
		cout<<"\n\t\t บ              TOTAL SPENT                 บ";
		cout<<"\n\t\t บ                                          บ";
		cout<<"\n\t\t บ ENTER DATE:                              บ";
		cout<<"\n\t\t บ MONEY SPENT:                             บ";
		cout<<"\n\t\t ศออออออออออออออออออออออออออออออออออออออออออผ";
		gotoxy(32,14);
		cout<<d;
		gotoxy(33,15);
		cout<<sum;

	}
	getch();
}
void displaymonth(char m[])
{
	long sum=0;
	int flag=0;
	file.open("budget.dat",ios::in);
	while(file.read((char*)&b,sizeof(b)))
	{
		if(strcmpi(b.retmonth(),m)==0)
		{
			sum+=b.money;
			flag=1;
		}
	}
	file.close();
	if(flag==0)
	cout<<"NO DATA FOUND ON THAT MONTH!!!";
	else
	cout<<"\n THROUGHOUT THE MONTH:- "<<sum;
	getch();
}
void displayyear(char y[])
{
	long sum=0;
	int flag=0;
	file.open("budget.dat",ios::in);
	while(file.read((char*)&b,sizeof(b)))
	{
		if(strcmpi(b.retyear(),y)==0)
		{
			sum+=b.money;
		}
	}
	file.close();
	if(flag==0)
	cout<<"NO DATA FOUND ON THAT YEART";
	else
	cout<<"\n THROUGHOUT THE YEAR:- "<<sum;
	getch();
}
void display()
{
	cout<<b.day<<"/"<<b.month<<"/"<<b.year<<setw(20)<<b.money<<setw(25)<<b.details<<'\n';
}
void disstatement()
{
	clrscr();
	file.open("budget.dat",ios::in);
	if(!file)
	{
		cout<<"FILE NOT FOUND!!!";
		getch();
		return;
	}
	cout<<"=========================================================================\n";
	cout<<"   DATE"<<setw(20)<<"\t  MONEY"<<setw(25)<<"\tDETAILS\n";
	cout<<"=========================================================================\n";
	while(file.read((char*)&b,sizeof(b)))
	{
		display();
	}
	file.close();
	getch();
}
void main()
{
	textcolor(10);
	clrscr();
	char ch2;
	cout<<"\n\n\n\n\n";
	cout<<"\n\t\t ษอออออออออออออออออออออออออออออออออออออออออป ";
	cout<<"\n\t\t บ              BUDGET MENU                บ ";
	cout<<"\n\t\t บ                                         บ ";
	cout<<"\n\t\t บ 1.INSERT A DATA                         บ ";
	cout<<"\n\t\t บ 2.DISPLAY TOTAL SPENT IN SPECIFIC DAY   บ ";
	cout<<"\n\t\t บ 3.DISPLAY TOTAL SPENT IN SPECIFIC MONTH บ ";
	cout<<"\n\t\t บ 4.DISPLAY TOTAL SPENT IN SPECIFIC YEAR  บ ";
	cout<<"\n\t\t บ 5.DISPLAY ALL RECORDS                   บ ";
	cout<<"\n\t\t บ 6.EXIT TO WINDOWS                       บ ";
	cout<<"\n\t\t ศอออออออออออออออออออออออออออออออออออออออออผ\n ";
	cout<<"\n\t\t     PLEASE ENTER YOUR CHOICE (1-6): ";
	ch2=getche();
	delay(500);
	switch (ch2)
	{
		case '1': insert();
			  break;
		case '2': displayday();
			  break;
		case '3': char m[2];
			  cout<<"\nFOR WHICH MONTH:- ";
			  cin>>m;
			  displaymonth(m);
			  break;
		case '4': char y[4];
			  cout<<"\nFOR WHICH YEAR:- ";
			  cin>>y;
			  displayyear(y);
			  break;
		case '5': disstatement();
			  break;
		case '6':exit(0);
		default: cout<<"\a";
	}
	main();
}























