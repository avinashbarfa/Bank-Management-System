// STAR BANKING MANAGEMENT SYSYTEM
#include<stdio.h>
#include<iomanip.h>
#include<conio.h>
#include<fstream.h>
#include<iostream.h>
#include<stdlib.h>
#include<dos.h>
#include<string.h>

fstream curr;
fstream file;
char found;

class account
{
		int acc_no;
	public: char cust_name[20];
		int damount,mob,age;
		char acc_type[10];
		int acco()
		{
			return acc_no;
		}
		void getdata();
		void display();
		void display1();
		void display2();
		void open();
		void read();
		void search();
		void modify();
		void deleted();
		void dep(int);
		void draw(int x);
		void deposit();
		void withdraw();
		void condition();
		void pass();
		void end();
		int retdeposit() const;
}c;
void account::getdata()
{
	system("cls");
	textcolor(YELLOW);
	gotoxy(33,2);
	cprintf(" $ STAR NATIONL BANK $ ");
	gotoxy(30,3);
	cprintf("* OPEN ACCOUNT * ");
	gotoxy(1,4);
	cprintf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	textcolor(WHITE);
	gotoxy(14,6);
	cout<<"Enter Account Holder's name : ";
	gotoxy(14,8);
	cout<<"Allot the Account No. : ";
	gotoxy(14,10);
	cout<<"Account Type ";
	gotoxy(14,12);
	cout<<"Mobile No. :";
	gotoxy(14,14);
	cout<<"Age :";
	gotoxy(14,16);
	cout<<"Deposit Money :";
	gotoxy(50,6);
	cin>>cust_name;
	gotoxy(50,8);
	cin>>acc_no;
	gotoxy(50,10);
	cin>>acc_type;
	gotoxy(50,12);
	cin>>mob;
	gotoxy(50,14);
	cin>>age;
	gotoxy(50,16);
	cin>>damount;
	gotoxy(20,18);
	cout<<"YOUR ACCOUNT HAS BEEN SUCCESFULLY CREATED"<<endl;
	getch();
}
void account::display()
{

	system("cls");
	gotoxy(17,12);
	textcolor(YELLOW);
	cprintf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	gotoxy(25,14);
	textcolor(RED);
	cprintf(" * WELCOME TO THE STAR BANK * ");
	gotoxy(17,16);
	textcolor(YELLOW);
	cprintf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	getch();
}
void account::display1()
{
	cout<<setw(5)<<acc_no<<setw(20)<<cust_name<<setw(22)<<acc_type<<setw(23)<<mob<<endl;
}
void account::display2()
{
	gotoxy(15,8);
	textcolor(YELLOW);
	cprintf("* Account Detail *");
	gotoxy(1,9);
	cprintf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	cout<<"Account Number : "<<acc_no<<endl;
	cout<<"Account Holder's Name : "<<cust_name<<endl;
	cout<<"Account Type : "<<acc_type<<endl;
	cout<<"Mobile Number : "<<mob<<endl;
	cout<<"Age : "<<age<<endl;
	cout<<"Total Amount : "<<damount<<endl;
	getch();


}
void account::open()
{
	char ans;
	curr.open("bankdata.txt",ios::in | ios::out | ios::app);
	ans='y';
	while(ans=='y')
	{
		c.getdata();
		curr.write((char*)&c,sizeof(c));
		textcolor(WHITE);
		gotoxy(20,21);
		cout<<"DO you want to enter more record(y/n) : ";
		cin>>ans;
	}
	curr.close();
}
void account::read()
{
	system("cls");
	curr.open("bankdata.txt",ios::in);
	//curr.seekg(0);
	gotoxy(30,2);
	textcolor(YELLOW);
	cprintf("* ACCOUNT SUMMARY *");
	gotoxy(2,3);
	textcolor(GREEN);
	cprintf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	gotoxy(2,4);
	cout<<"ACC. NO\tCUSTOMER NAME\t\tACC. TYPE\t\tContact No.";
	gotoxy(2,5);
	cprintf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	while(curr.read((char*)&c,sizeof(c)))
	{
		if(curr.eof())
		break;
		c.display1();
	}
	curr.close();
	getch();
}
void account::search()
{
	int p,found='n';
	system("cls");
	gotoxy(30,1);
	textcolor(YELLOW);
	cprintf("* STAR BANK *");
	gotoxy(30,2);
	textcolor(YELLOW);
	cprintf("* SEARCH *");
	gotoxy(1,3);
	cprintf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	gotoxy(15,7);
	cout<<"Enter the Account No to be searched : "<<endl;
	curr.open("bankdata.txt",ios::out | ios::in);
	gotoxy(55,7);
	cin>>p;
	cout<<"Searching...";
	delay(800);
	while(!curr.eof())
	{
		curr.read((char*)&c,sizeof(c));
		if(c.acco()==p)
		{
			c.display2();
			found='y';
			break;
		}
	}
	if(found=='n')
	cout<<"Account No Does Not Exist"<<endl;
	curr.close();
	getch();
}
void account::modify()
{
	found='n';
	int pos,t;
	system("cls");
	curr.open("bankdata.txt",ios::out | ios::in);
	gotoxy(30,2);
	textcolor(YELLOW);
	cprintf("* MODIFICATION *");
	gotoxy(14,6);
	cout<<"Enter the Account No to be searched :"<<endl;
	gotoxy(50,6);
	cin>>t;
	while(!curr.eof())
	{
		pos=curr.tellg();
		curr.read((char*)&c,sizeof(c));
		if(c.acco()==t)
		{
			c.getdata();
			curr.seekg(pos);
			curr.write((char*)&c,sizeof(c));
			found='y';
			break;
		}
	}
	if(found=='n')
	cout<<"Account No Does Not Exist"<<endl;
	curr.close();
	getch();
}
void account::deleted()
{
	int p;
	system("cls");
	curr.open("bankdata.txt",ios::in);
	file.open("temp.txt",ios::out);
	gotoxy(30,2);
	textcolor(YELLOW);
	cprintf("* DELETE ACCOUNT *");
	gotoxy(12,4);
	cout<<"Enter the Account No to be searched : "<<endl;
	gotoxy(55,4);
	cin>>p;
	found='n';
	char confirm='n';
	while(curr.read((char*)&c,sizeof(c)))
	{
		if(c.acco()==p)
		{
			display2();
			found='y';
			cout<<"\n\nAre you sure you want to delete record(y/n) :";
			cin>>confirm;
			if(confirm=='n')
				file.write((char*)&c,sizeof(c));

		}
		else
				file.write((char*)&c,sizeof(c));
	}
	if(found=='n')
	cout<<"Account No Does Not Exist"<<endl;
	curr.close();
	file.close();
	remove("bankdata.txt");
	rename("temp.txt","bankdata.txt");
	getch();
}

void account::dep(int x)
{
	damount+=x;
}

int account::retdeposit() const
{
	return damount;
}

void account::draw(int x)
{
	damount-=x;
}
void account::deposit()
{
	int amt,p;
	system("cls");
	curr.open("bankdata.txt",ios::in | ios::out);
	gotoxy(30,2);
	textcolor(YELLOW);
	cprintf("* DEPOSIT AMOUNT *");
	gotoxy(12,4);
	cout<<"Enter the Account No : "<<endl;
	gotoxy(45,4);
	cin>>p;
	found='n';
	char confirm='n';
	while(curr.read((char*)&c,sizeof(c)))
	{

		if(c.acco()==p)
		{
			display2();
			{
				cout<<"\n\n\tTO DEPOSITE AMOUNT ";
				cout<<"\n\nEnter The amount to be deposited : ";
				cin>>amt;
				c.dep(amt);
			}
			int pos=(-1)*(sizeof(c));
			curr.seekp(pos,ios::cur);
			curr.write((char*)&c,sizeof(c));
			cout<<"\n\n\t Record Updated";
			found='y';
	       }
	 }
	if(found=='n')
	cout<<"Account No Does Not Exist"<<endl;
	curr.close();
	getch();
}

void account::withdraw()
{
	int amt,p;
	system("cls");
	curr.open("bankdata.txt",ios::in | ios::out);
	gotoxy(30,2);
	textcolor(YELLOW);
	cprintf("* WITHDRAW AMOUNT *");
	gotoxy(12,4);
	cout<<"Enter the Account No : "<<endl;
	gotoxy(45,4);
	cin>>p;
	found='n';
	char confirm='n';
	while(curr.read((char*)&c,sizeof(c)))
	{

		if(c.acco()==p)
		{
			display2();
			{
				cout<<"\n\n\t TO WITHDRAW AMOUNT ";
				cout<<"\n\nEnter The amount to be withdraw : ";
				cin>>amt;
				int bal=c.retdeposit()-amt;
				c.draw(amt);
			}
			int pos=(-1)*(sizeof(c));
			curr.seekp(pos,ios::cur);
			curr.write((char*)&c,sizeof(c));
			cout<<"\n\n\t Record Updated";
			found='y';
	       }
	 }
	if(found=='n')
	cout<<"Account No Does Not Exist"<<endl;
	curr.close();
	getch();
}
void account::condition()
{
while(2)
	{
		int opt;

		{
		system("cls");
		textcolor(YELLOW);
		gotoxy(33,2);
		cprintf(" DUPLICATE BANK ");
		gotoxy(30,3);
		cprintf("$$ ACCOUNT MANAGMENT $$");
		gotoxy(1,4);
		cprintf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
		gotoxy(15,6);
		textcolor(LIGHTBLUE);
		gotoxy(20,8);
		cprintf(" 1. TO ADD ACCOUNT HOLDER.");
		gotoxy(20,10);
		cprintf(" 2. TO DISPLAY DATA OF ALL ACCOUNT HOLDERS.");
		gotoxy(20,12);
		cprintf(" 3. MODIFY ACCOUNT HOLDERS DETAIL.");
		gotoxy(20,14);
		cprintf(" 4. SEARCH ACCOUNT HOLDERS.");
		gotoxy(20,16);
		cprintf(" 5. DELETE DATA.");
		gotoxy(20,18);
		cprintf(" 6. DEPOSIT MONEY.");
		gotoxy(20,20);
		cprintf(" 7. Withdraw Money.");
		gotoxy(20,22);
		cprintf(" 8. Exit");
		gotoxy(36,24);
		textcolor(CYAN);
		cprintf("ENTER CHOOSE : ");
		cin>>opt;
			switch(opt)
			{
				case 1: c.open();
						break;

				case 2: c.read();
						break;

				case 3:	c.modify();
						break;

				case 4: c.search();
						break;

				case 5: c.deleted();
						break;

				case 6: c.deposit();
						break;

				case 7: c.withdraw();
						break;

				case 8: c.end();
			}
		}
    }
}
void account::end()
{
 system("cls");
 textcolor(RED);
 gotoxy(30,14);
 cprintf("-- THANK YOU --");
 gotoxy(28,16);
 cprintf("SEE YOU AGAIN");
 getch();
 exit(0);
}
main()
{
	c.display();
	c.condition();
}
