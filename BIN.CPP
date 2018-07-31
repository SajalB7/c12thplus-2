#include <iostream.h>
#include <conio.h>
#include <fstream.h>
#include <stdlib.h>
#include <iomanip.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <process.h>
#include <ctype.h>

class employee
{
	int eid;
	char ename[25],post[20],dept[10];
	double salary;

	public:
	void getdata();
	void show();
	int retid()
	{
		return eid;
	}
	char* retdept()
	{
		 return dept;
	}
};

////////////////////////////////////////////////////////////////////////////
void employee::getdata()
{
	double s;

	cout<<endl<<"Enter record:-";
	cout<<"\nID=";
	cin>>eid;
	cout<<"\nEmployee Name:";
	gets(ename);
	cout<<"Employee's Post:";
	gets(post);
	cout<<"Employee's Department:";
	gets(dept);
	cout<<"Salary:";
	cin>>s;
	while(s!=salary)
	{
		if(s>0)
			salary=s;
		else
		{
			cout<<"\nInvalid";
			cout<<"\nProgram Terminating....";
			for(float q=0;q<10000000;q++);
			exit(1);

		}
	}
}

void employee::show()                                   //displaying data
{
	cout<<endl<<endl<<"-----------------------------------------------------------------";
	cout<<endl<<setw(5)<<eid<<setw(20)<<ename<<setw(15)<<post<<setw(15)<<dept<<setw(10)<<salary;
}


/////////////////////////////////////////////////////////////////////////////

void create()
	{
	ofstream fout;
	fout.open("file.dat",ios::binary|ios::app);
	employee e;
	char ch;
	ch='y';
	while(ch=='y')
	{
		e.getdata();
		fout.write((char*)&e,sizeof(e));
		cout<<"\nDo you want to add more records(y/n)";
		cin>>ch;
	}
	fout.close();
}


void display()
{
	ifstream fin;
	fin.open("file.dat",ios::binary);
	employee e;
	int c=0;
	if(!fin)
	{
		cout<<"File does not Exist";
		for(float i=0;i<10000000;i++);
		exit(1);
	}

	else
	{
		cout<<endl<<endl<<setw(5)<<"ID"<<setw(20)<<"Name"<<setw(15)<<"Post"<<setw(15)<<"Department"<<setw(10)<<"Salary";
		while(fin.read((char*)&e,sizeof(e)))
		{
				c++;
				e.show();
				cout<<endl;
		}
		if(c==0)
		{
			cout<<"\nFile is empty";
		}
	}
	fin.close();

}


void Delete()
{
	ifstream fin;
	fin.open("file.dat",ios::binary);
	ofstream fout;
	fout.open("temp.dat",ios::binary|ios::app);
	int id;
	cout<<"\nEnter Employee ID to be deleted ";
	cin>>id;
	employee e;
	int f=0;

	while( fin.read((char*)&e,sizeof(e)) )
	{
	 if(e.retid()!=id)
		{
		fout.write((char*)&e,sizeof(e));
		}
	 else
		f=1;
	}



	if(f==0)
	cout<<"\nRecord not found";

	fin.close();
	fout.close();
	remove("file.dat");
	rename("temp.dat","file.dat");

	if(f==1)
	{
		if(!fin)
			cout<<"File is Empty";
		else
		{
			cout<<"\nRecord No. "<<id<<" deleted.";
			cout<<"\nThe File now contains :-";
			cout<<endl<<setw(5)<<"ID"<<setw(20)<<"Name"<<setw(15)<<"Post"<<setw(15)<<"Department"<<setw(10)<<"Salary";
			fin.open("file.dat",ios::binary);
			while(fin.read((char*)&e,sizeof(e)))
				e.show();
			cout<<endl;
		}
	fin.close();
	}
}

void modify()
{
	fstream f;
	f.open("file.dat",ios::binary|ios::in|ios::out);
	int id,pos,k=0;
	cout<<"Enter ID that is to be updated ";
	cin>>id;
	employee e;
	while(!f.eof())
	{
		pos=f.tellg();
		f.read((char*)&e,sizeof(e));
		if(e.retid()==id)
		{
			f.seekg(pos);
			e.getdata();
			f.write((char*)&e,sizeof(e));
			cout<<"\nUpdated";
			k++;
			
		}
	}
	if(k==0)
	cout<<"Record does not exist";
	f.close();
}

void searchid()
{
    int id;
	cout<<"\nEnter ID ";
	cin>>id;
	ifstream fin;
	fin.open("file.dat",ios::binary);
	employee e;
	if(!fin)
	{
		cout<<"Cannot open file";
		for(float i=0;i<1000000;i++);
		exit(1);
	}

	int t=0;
	while(fin.read((char*)&e,sizeof(e)))
	{
		if(e.retid()==id)
		{
			t=1;
			cout<<endl<<setw(5)<<"ID"<<setw(20)<<"Name"<<setw(15)<<"Post"<<setw(15)<<"Department"<<setw(10)<<"Salary";
			e.show();

		}
	}
	if(t==0)
		cout<<"\nRecord not found";

	fin.close();
}

void searchdept()
{
	char str[20];
	cout<<"\nEnter Department ";
	gets(str);
	ifstream fin;
	fin.open("file.dat",ios::binary);
	employee e;
	if(!fin)
	{
		cout<<"Cannot open file";
		for(float i=0;i<1000000;i++);
		exit(1);
	}
	cout<<endl<<setw(5)<<"ID"<<setw(20)<<"Name"<<setw(15)<<"Post"<<setw(15)<<"Department"<<setw(10)<<"Salary";

	int t=0;
	while(fin.read((char*)&e,sizeof(e)))
	{
		if(strcmpi(e.retdept(),str)==0)
		{
			t=1;
			e.show();

		}
	}
	if(t==0)
		cout<<"\nRecord not found";

	fin.close();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
void emp()                                       //admin end-HR Department
{
	char opt,ch,Dept[50];
	clrscr();
	do
	{
		cout<<setw(50)<<"\n********Menu********\n";
		cout<<endl<<"Enter your option";
		cout<<endl<<"1. Add a new record";
		cout<<endl<<"2. Search record from employee id";
		cout<<endl<<"3. Display all employee";
		cout<<endl<<"4. Update record of an employee";
		cout<<endl<<"5. Delete record of particular employee";
		cout<<endl<<"6. Search record by department";
		cout<<endl<<"7. Exit from the program"<<endl;
		cout<<"********************"<<endl;
		cin>>opt;
		switch(opt)
		{
			case'1':create();
				break;
			case'2':searchid();
				break;
			case'3':display();
				break;
			case'4':modify();
				break;
			case'5':Delete();
				break;
			case'6':searchdept();
				break;
			case'7':exit(0);

			default:cout<<"Invalid Choice";
		}
	cout<<"\nDo you want to continue..?(y/n)";
	cin>>ch;
	}while(ch=='y'||ch=='Y');
	getch();
}
/////////////////////////////////////////////////////////////////
void main()                               //Main Function
{
 clrscr();
 void screen();
 cout<<endl<<setw(125)<<"WELCOME\n\n";
 emp();
 getch();
}
