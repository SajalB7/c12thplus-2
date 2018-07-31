			     //PROGRAM ON DYNAMIC STACK

#include<iostream.h>
#include<conio.h>
#include<stdio.h>

  struct plane
  {
   int airno;
   char name[20];
   float bill;
   plane *next;
  };

  class stack
  {
    plane *top;
   public:
    stack()
    {
       top=NULL;
    }
    void push();
    void pop();
    void show();
  };

 void stack ::push()
 {
   plane *p=new plane;
   cout<<"Enter Airplane No=";
   cin>>p->airno;
   cout<<"Enter Name=";
   gets(p->name);
   cout<<"Enter Bill=";
   cin>>p->bill;
   p->next=NULL;
    if(top==NULL)
     {
	top=p;
     }
    else
     {
	p->next=top;
	top=p;
     }
 }

 void stack ::pop()
  {
   if(top==NULL)
    {
	cout<<"Underflow\n";
	return;
    }
    else
     {
       plane *p=top;
       top=top->next;
       cout<<"\nNode Deleted";
       cout<<"\nThe Deleted Node is=";
       cout<<"\nAirplane No="<<p->airno;
       cout<<"\nName="<<p->name;
       cout<<"\nBill="<<p->bill<<"\n";
       delete p;
     }
  }

 void stack::show()
  {
    if(top==NULL)
     {
       cout<<"\nStack is Empty";
       return;
     }
   else
    {
     plane *p=top;
     while(p!=NULL)
      {
       cout<<"\nAirplane No="<<p->airno;
       cout<<"\nName="<<p->name;
       cout<<"\nBill="<<p->bill;
       p=p->next;
      }
    }
  }

 void main()
  {
   int ch;
   char choice;
   stack s1;
   clrscr();
   do
    {
	cout<<"\nEnter 1 to add element in the stack";
	cout<<"\nEnter 2 to delete element from the stack";
	cout<<"\nEnter 3 to show the stack\n";
	cin>>ch;
	if(ch==1)
	    s1.push();
	else if(ch==2)
	    s1.pop();
	else if(ch==3)
	    s1.show();
	cout<<"\n Do you want to continue(y/n)\n";
	cin>>choice;
    }while(choice=='y');

   getch();

}









