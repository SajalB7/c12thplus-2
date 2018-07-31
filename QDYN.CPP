			     //DYNAMIC QUEUE

#include<iomanip.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>

struct ticket
{                          //structure
	int tno;
	char pname[20];
	float amount;
	ticket *next;
};

class queue
{
	ticket *front;
	ticket *rear;
	public:
	queue()                         //class
	{
		front=NULL;
		rear=NULL;
	}
	void insert();
	void remove();
	void show();
};


void queue::insert()
{
	ticket *p=new ticket;
	cout<<"\n Enter Ticket no.= ";          //Insertion in queue
	cin>>p->tno;
	cout<<" Enter Name= ";
	gets(p->pname);
	cout<<" Enter Amount= ";
	cin>>p->amount;
	p->next=NULL;

	if(rear==NULL)
	{
		front=p;
		rear=p;
	}

	else
	{
		rear->next=p;
		rear=p;
	}
}


void queue::remove()
{

	if(front==NULL)                             //Deletion in queue
	{
		cout<<"\nUnderflow";
		return;
	}

	else
	{
		ticket *p=front;
		cout<<"\n THE DELETED NODE IS ";
		cout<<"\n Ticket no.="<<front->tno;
		cout<<"\n Passenger name="<<front->pname;
		cout<<"\n Amount="<<front->amount;
		cout<<endl;
		if(front==rear)
		{
			front=NULL;
			rear=NULL;
		}

		else
		{
			front=front->next;
			delete p;
		}
	}
}


void queue :: show()
{
						      //Displaying Queue
	if(front==NULL)
	{
		cout<<"\nQueue is empty";
		return;
	}

	else
	{
		ticket *p=front;

		while(p!=NULL)
		{
			cout<<"\n Ticket no.= "<<p->tno;
			cout<<"\n Passenger Name="<<p->pname;
			cout<<"\n Amount = "<<p->amount;
			cout<<endl;
			p=p->next;
		}
		cout<<endl;
	}
}


void main()
{
	int ch;
	char choice;
	queue q1;
	clrscr();

	cout<<setw(40)<<"Welcome\n";
	cout<<setw(40)<<"-------\n";
	do
	{
		cout<<"\nEnter your choice:-";
		cout<<"\n1.Insert";
		cout<<"\n2.Delete";
		cout<<"\n3.Display ";
		cout<<"\n4.Quit\n"<<endl;
		cin>>ch;

		switch(ch)
		{
			case 1: q1.insert();
				break;
			case 2: q1.remove();
				break;
			case 3: q1.show();
				break;
			case 4: exit(0);

			default:cout<<"\nWrong Choice";
		}

		cout<<"\nDo you want to continue?(y/n) ";
		cin>>choice;
		cout<<endl;
	}while(choice=='y'||choice=='Y');
	getch();
}













































