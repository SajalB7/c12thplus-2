
#include<iostream.h>
#include<conio.h>
#include<stdio.h>

struct student
{
	int rno;
	char name[20];
	float marks;
};

const int size=3;

class stack
{
	int top;
	student ar[size];
	public :
	stack()
	{
		top=-1;
	}

	void push();
	void pop();
	void show();
};

void stack::push()
{
	if(top==size-1)
	{
		cout<<"\nOverflow";
		return;
	}

	else
	{
		top++;
		cout<<"Enter roll no.";
		cin>>ar[top].rno;
		cout<<"Enter name:";
		gets(ar[top].name);
		cout<<"Enter marks:";
		cin>>ar[top].marks;
	}
}

void stack::pop()
{
	if(top==-1)
	{
		cout<<"Underflow";
		return;
	}

	else
	{
	cout<<"The deleted node is:-";
	cout<<"\n Roll no. :"<<ar[top].rno;
	cout<<"\n Name:"<<ar[top].name;
	cout<<"\n Marks:"<<ar[top].marks;
	top--;
	}
}

void stack::show()
{
	if(top==-1)
	{
		cout<<"\nStack is Empty";
		return;
	}

	else
	{
		for(int i=top;i>=0;i--)
		{
			cout<<"\n roll no. :"<<ar[i].rno;
			cout<<"\n name:"<<ar[i].name;
			cout<<"\n marks:"<<ar[i].marks;
		}
	}
}

void main()
{
	clrscr();
	stack s1;
	int ch;
	char choice;
	do
	{
		cout<<"\nEnter your choice:-";
		cout<<"\n enter 1 to push";
		cout<<"\n enter 2 to pop";
		cout<<"\n enter 3 to show";
		cin>>ch;

		if(ch==1)
		{
			s1.push();
		}
		else if(ch==2)
		{
			s1.pop();
		}
		else if(ch==3)
		{
			s1.show();
		}

		cout<<"\n do you want to continue(y/n) :";
		cin>>choice;

	}while(choice=='y'||choice=='Y');

	getch();
}