			     //CIRCULAR QUEUE

#include<iomanip.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>

struct student
	{                          //structure
	int rno;
	char name[20];
	float marks;
	};

const int size=3;

class queue
{
		int front;
		int rear;
		student ar[size];
		public:
		queue()                         //class
			{
			front=-1;
			rear=-1;
			}
		void insert();
		void remove();
		void show();
};


void queue::insert()
{
	if( (front==0 && rear==size-1) || front==rear+1 )
	{
		cout<<"\nOverflow";
		return;
	}

	else if(rear==-1)
	{
		front=0;
		rear=0;
	}

	else if(rear==size-1)
	{
		rear=0;
	}

	else
	{
		rear++;
	}

	cout<<"\nEnter roll no.=";
	cin>>ar[rear].rno;
	cout<<"\nEnter name=";
	gets(ar[rear].name);
	cout<<"\nEnter marks=";
	cin>>ar[rear].marks;
}


void queue::remove()
{
	if(front==-1)                             //Deletion in queue
	{
		cout<<"\nUnderflow";
		return;
	}

	else
	{
		cout<<"\n Node Deleted.";
		cout<<"\n THE DELETED NODE IS :-";
		cout<<"\n Roll no.="<<ar[front].rno;
		cout<<"\n Name="<<ar[front].name;
		cout<<"\n Marks="<<ar[front].marks;
		cout<<endl;
		if(front==rear)
		{
			front=-1;
			rear=-1;
		}

		else if(front==size-1)
		{
			front=0;
		}

		else
			front++;
	}
}

void queue :: show()
{
						      //Displaying Queue
	if(front==-1)
	{
		cout<<"\nQueue is empty";
		return;
	}

	else
	{
		if(front<=rear)
		{
			for(int i=front;i<=rear;i++)
			{
				cout<<"\n Roll no.="<<ar[i].rno;
				cout<<"\n Name="<<ar[i].name;
				cout<<"\n Marks="<<ar[i].marks;
				cout<<endl;
			}
		}

		else
		{
			for(int i=front;i<size;i++)
			{
				cout<<"\n Roll no.="<<ar[i].rno;
				cout<<"\n Name="<<ar[i].name;
				cout<<"\n Marks="<<ar[i].marks;
				cout<<endl;
			}

			for(i=0;i<=rear;i++)
			{
				cout<<"\n Roll no.="<<ar[i].rno;
				cout<<"\n Name="<<ar[i].name;
				cout<<"\n Marks="<<ar[i].marks;
				cout<<endl;
			}
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












































