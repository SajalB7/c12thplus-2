/****************************************************************************
 ****************************************************************************
	Project on:-

			INDIAN STORES LTD.
		      ----------------------

					-< SAJAL BANSAL & PRAKHAR PRAKASH>
*****************************************************************************
*************************************************************************** */


/***************************************************************************
		Accounts	Password
	 1.	admin		pass
	 2.	user           	code
*************************************************************************** */


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

//////////////////////Extra Functions/////////////////////////////////////
void displist()
{
	cout<<"\nList:-";
	cout<<"\n1.Iron Rollers";
	cout<<"\n2.Tungsten Filaments";             //displaying order list
	cout<<"\n3.Plastic Bottles";
	cout<<"\n4.Magnetic fillings\n\n";
}
void adminf();

void screen()                            //To display loading screen
{
	cout<<setw(605)<<"INDIAN STORES LTD.";
	cout<<setw(80)<<"------------------";
	cout<<setw(195)<<"-by <Sajal Bansal & Prakhar Prakash>";
	cout<<setw(611)<<"Press any key to continue:";
	getch();
	clrscr();
}

/////////////////////////////////////////////////////////////////////////////

/////////////////////////class stocks///////////////////////////////////////

class stocks
{
	int mno;
	float quan;
	public:
	void show();
	void create();
	void add();
	void plus(int,float);
	void minus(int,float);
	float retquan(int);
}s1;
void stocks::show()                   // admin end - displays stock file
{
	ifstream f1;
	int assign;
	f1.open("Stock.dat",ios::binary);
	if(!f1)
	{
		cout<<"\nFile does not exist\n";
		for(float i =0;i<100000;i++);
	}
	else
	{
		while(f1.read((char*) &s1, sizeof(s1)))
		{

			 cout<<"\nMaterial id : "<<s1.mno;
			 switch(s1.mno)
			 {
				case 1 :
				cout<<"\nMaterial name : Iron";
				cout<<"\nMaterial quantity available : "<<s1.quan<<" Iron rollers\n";
				break;
				case 2 :
				cout<<"\nMaterial name : Tungsten";
				cout<<"\nMaterial quantity available : "<<s1.quan<<" Tungsten filament packs\n";
				break;
				case 3 :
				cout<<"\nMaterial name : Plastic";
				cout<<"\nMaterial quantity available: "<<s1.quan<<" Plastic bottles\n";
				break;
				case 4 :
				cout<<"\nMaterial name : Magnetic";
				cout<<"\nMaterial quantity available: "<<s1.quan<<" Kgs manetic fillings\n";
				break;
			  }
		}
      }
      f1.close();
}

void stocks::create()
{
	ofstream f1;
	char ans1 = 'y';
	cout<<"Enter the data for the stocks file\n\n";
	f1.open("Stock.dat",ios::binary|ios::app);
	displist();
	do
	{
		cout<<"\nEnter the material number\n";
		cin>>s1.mno;
		cout<<"Enter the material quantity\n";
		cin>>s1.quan;
		f1.write((char*) &s1, sizeof(s1));
		cout<<"Do you wish to enter more??\n";
		cin>>ans1;
	 }while(ans1=='y');
	 f1.close();
}

void stocks::add()                        //to add stocks
{
	int a;
	stocks s1;
	float b;
	long pos;
	displist();
	cout<<"Enter the material no you wish to add\n";
	cin>>a;
	cout<<"Enter the quantity you wish to add\n";
	cin>>b;
	fstream f1;
	f1.open("Stock.dat",ios::binary|ios::in|ios::out);
	pos = f1.tellg();
	while(f1.read((char*) &s1,sizeof(s1)))
	{
		if(s1.mno==a)
		{
			f1.seekg(pos);
			s1.quan+=b;
			f1.write((char*) &s1,sizeof(s1));
		 }
	}
	f1.close();
}

float stocks::retquan(int a)
{
	float b;
	ifstream f1;
	f1.open("Stock.dat",ios::binary);
	while(f1.read((char*)&s1,sizeof(s1)))
	{
		if(s1.mno == a)
		{
			b = s1.quan;
			break;
		}
	}
	f1.close();
	return b;
}

void stocks::minus(int a,float b)
{
	fstream f1;
	long pos;
	f1.open("Stock.dat",ios::binary|ios::in|ios::out);
	pos = f1.tellg();
	while(f1.read((char*)&s1, sizeof(s1)))
	{
		if(s1.mno==a)
		{
			s1.quan = s1.quan - b;
			f1.seekg(pos);
			f1.write((char*) &s1,sizeof(s1));
		}
	}
	f1.close();
}
void stocks::plus(int a,float b)
{
	fstream f1;
	long pos;
	f1.open("Stock.dat",ios::binary|ios::in|ios::out);
	pos = f1.tellg();
	while(f1.read((char*)&s1, sizeof(s1)))
	{
		if(s1.mno==a)
		{
			s1.quan +=b;
			f1.seekg(pos);
			f1.write((char*) &s1,sizeof(s1));
		}
	}
	f1.close();
}
//////////////////////////End of class stocks ///////////////////////////////////

////////////////////////////////class order//////////////////////////////////
class order
{
	int orid;
	int ormno;
	float quan;
	public :
	void create();
	void show();
	void cancel(int);
	void place(int,int,float);
	float retquan(int);
	int test(int);
	int retno(int);
	int retoid()
	{
		return orid;
	}
	order()
	{
	    orid = 0;
	 }
}o1;
////////////////////////////////////////////////////////////////////////////

int generate()                     //To generate order id serial-wise
{
	  long tid=0;
	  ifstream f;
	  order e;
	  f.open("Orderlist.dat",ios::binary);
	  while(f.read((char*)&e,sizeof(e)))
		tid=e.retoid();
	  f.close();
	  tid++;
	  return tid;
}
////////////////////////////////////////////////////////////////////////////
void order::cancel(int a)
{
	fstream f1;
	fstream f2;
	f1.open("orderlist.dat",ios::binary|ios::in|ios::out);
	f2.open("Temp.dat",ios::binary|ios::in|ios::out);
	while(f1.read((char*)&o1,sizeof(o1)))
	{
		if(o1.orid!= a)
		{
			f2.write((char*)&o1,sizeof(o1));
		}
	}
	f1.close();
	f2.close();
	remove("Orderlist.dat");
	rename("Temp.dat","Orderlist.dat");
}
void order::place(int a,int b, float c)
{
	ofstream f1;
	f1.open("Orderlist.dat",ios::binary|ios::app);
	o1.orid = a;
	o1.ormno = b;
	o1.quan = c;
	f1.write((char*)&o1, sizeof(o1));
	f1.close();
}
float order::retquan(int a)
{
	ifstream f1;
	float b;
	f1.open("Orderlist.dat",ios::binary);
	while(f1.read((char*)&o1, sizeof(o1)))
	{
		if(o1.orid == a)
		{
			b = o1.quan;
		}
	 }
	 f1.close();
	 return b;
}
int order::retno(int a)
{
	ifstream f1;
	int b;
	f1.open("Orderlist.dat",ios::binary);
	while(f1.read((char*)&o1, sizeof(o1)))
	{
		if(o1.orid == a)
		{
			b = o1.ormno;
		}
	 }
	 f1.close();
	 return b;
}
int order::test(int a)
{
	int flag = 0;
	ifstream f1;
	f1.open("Orderlist.dat",ios::binary);
	while(f1.read((char*)&o1, sizeof(o1)))
	{
		if(o1.orid == a)
		{
			flag = 1;
			break;
		}
	 }
	 f1.close();
	 return flag;
}
void order::show()                //admin end - displays order list
{
       ifstream f6;
       f6.open("Orderlist.dat",ios::binary);
       while(f6.read((char*) &o1, sizeof(o1)))
       {
	    cout<<"\nOrder ID : "<<o1.orid;
	    cout<<"\nOrder Material number : "<<o1.ormno;
	    switch(o1.ormno)
	    {
		case 1 :
		cout<<"\nOrder Material name : Iron Rollers";
		cout<<"\nOrder Material quantity : "<<o1.quan<<" Iron Rollers\n";
		break;
		case 2 :
		cout<<"\nOrder Material name : Tungsten Filaments";
		cout<<"\nOrder Material quantity : "<<o1.quan<<" Tungsten filaments\n";
		break;
		case 3 :
		cout<<"\nOrder Material name : Plastic Bottles";
		cout<<"\nOrder Material quantity : "<<o1.quan<<" Plastic bottles\n";
		break;
		case 4 :
		cout<<"\nOrder Material name : Magnetic fillings";
		cout<<"\nOrder Material quantity : "<<o1.quan<<" kgs of magnetic fillings\n";
		break;
	    }
       }
       f6.close();
}
//////////////////////////End of class order/////////////////////////////////


//////////////////////////class employee////////////////////////////////////

class employee
{
	int eid;
	char ename[25],post[20],dept[10];
	double salary;

	public:
	void getdata(int);
	void getdata1(int);      		//for modify() only
	void show();
	int retid()
	{
		return eid;
	}
	char* retdept()
	{
		 return ename;
	}
};

//////////////////////////////////////////////////////////////////////////
long generateeid(int temp)                      //To generate id serial wise
{
	if(temp==0)
	{
		long tid=0;
		ifstream f;
		employee e;
		f.open("employee.dat",ios::binary);

		while(f.read((char*)&e,sizeof(e)))
			tid=e.retid();

		f.close();
		tid++;
		return tid;
	}

	else
	{
		long tid=0;
		ifstream f;
		employee e;
		f.open("employee.dat",ios::binary);

		while(f.read((char*)&e,sizeof(e)))
			tid=e.retid();

		f.close();
		for(int k=0;k<temp;k++)
			tid++;
		return tid;
	}
}
////////////////////////////////////////////////////////////////////////////
void employee::getdata(int t)
{
	double s;
	eid=generateeid(t);
	cout<<endl<<"Enter record:-";
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

void employee::getdata1(int t)                //For modify() only
{
	double s;
	eid=t;
	cout<<endl<<"Enter details:-";
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
			for(float q=0;q<1000000;q++);
			exit(1);
		}
	}
}

void employee::show()                                   //To display data
{
	cout<<endl<<endl<<"-----------------------------------------------------------------";
	cout<<endl<<setw(5)<<eid<<setw(20)<<ename<<setw(15)<<post<<setw(15)<<dept<<setw(10)<<salary;
}


/////////////////////////////////////////////////////////////////////////////

void create()
	{
	int t=0;
	ofstream fout;
	fout.open("employee.dat",ios::binary|ios::app);
	employee e;
	char ch;
	ch='y';
	while(ch=='y')
	{
		if(t==0)
		{
			e.getdata(t);
			t++;
			fout.write((char*)&e,sizeof(e));
			cout<<"\nDo you want to add more records(y/n)";
			cin>>ch;
		}
		else
		{
			t++;

			e.getdata(t);
			fout.write((char*)&e,sizeof(e));
			cout<<"\nDo you want to add more records(y/n)";
			cin>>ch;
		}
    }
	fout.close();
}


void display()
{
	ifstream fin;
	fin.open("employee.dat",ios::binary);
	employee e;
	int c=0;
	if(!fin)
	{
		cout<<"File does not Exist";
		for(float i=0;i<1000000;i++);
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
	fin.open("employee.dat",ios::binary);
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
	remove("employee.dat");
	rename("temp.dat","employee.dat");

	if(f==1)
	{
		if(!fin)
			cout<<"File is Empty";
		else
		{
			cout<<"\nRecord No. "<<id<<" deleted.";
			cout<<"\nThe File now contains :-";
			cout<<endl<<setw(5)<<"ID"<<setw(20)<<"Name"<<setw(15)<<"Post"<<setw(15)<<"Department"<<setw(10)<<"Salary";
			fin.open("employee.dat",ios::binary);
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
	f.open("employee.dat",ios::binary|ios::in|ios::out);
	int id,pos,k=0;
	cout<<"Enter ID that is to be updated ";
	cin>>id;
	employee e;
	while(!f.eof())
	{
		pos=f.tellg();
		f.read((char*)&e,sizeof(e));
		if(e.retid()==id)
		{	f.seekp(pos);
			e.getdata1(id);
			f.write((char*)&e,sizeof(e));
			cout<<"\nUpdated";
			k++;
			break;
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
	fin.open("employee.dat",ios::binary);
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

/////////////////////////End of employee//////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
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
		cout<<endl<<"6. Back to Main Menu";
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
			case'6':adminf();
			case'7':exit(0);

			default:cout<<"Invalid Choice";
		}
	cout<<"\nDo you want to continue..?(y/n)";
	cin>>ch;
	}while(ch=='y'||ch=='Y');
	getch();
}

/////////////////////////////////////////////////////////////////////////////

void stock()                       //admin end-Stocks department
{
	clrscr();
	char ch5='y';
	int ch6;
	stocks s1;
	while(ch5=='y')
	{
		cout<<"\n*******Menu*******\nEnter your choice\n";
		cout<<"1.See stocks\n";
		cout<<"2.Add stocks\n";
		cout<<"3.Create stock file\n";
		cout<<"4.Back to previous menu\n";
		cout<<"5.Exit\n";
		cin>>ch6;
		switch(ch6)
		{
			case 1:s1.show();
				break;
			case 2:s1.add();
				break;
			case 3:s1.create();
				break;
			case 4:adminf();
				break;
			case 5:exit(0);
			default:continue;
		}
	}
}



//////////////****************Menu for USER***************///////////////////
void userf()
{
	clrscr();
	char ch5='y';
	int ch6,a,c,d,e;
	float b,f;
	order o1;
	stocks s1;
	while(ch5=='y')
	{
		cout<<"\n*******Menu*******\nEnter your choice\n";
		cout<<"1.Place a new order\n";
		cout<<"2.Cancel an existing order\n";
		cout<<"3.Exit\n";
		cin>>ch6;
		switch(ch6)
		{
			case 1: displist();
				cout<<"Enter the material number of the item";
				cout<<" you want ?\n";
				cin>>a;
				cout<<"Enter the quantity of the material";
				cout<<" you wish to include?\n";
				cin>>b;
				if(b>=s1.retquan(a))
				{
					cout<<"Sorry insufficient materials";
					cout<<"\nTry again later\n";
				}
				else
				{
					c = generate();
					o1.place(c,a,b);
					s1.minus(a,b);
					cout<<"Order with order id "<<c;
					cout<<" placed successfully!!\n";
				}
				break;
			case 2:
				cout<<"Enter the order id of the order you";
				cout<<" wish to cancel\n";
				cin>>d;
				e = o1.test(d);
				if(e==0)
				{
					cout<<"No such order found!!!";
					cout<<"\nPlease try again later!!";
				}
				else
				{
					e = o1.retno(d);
					f = o1.retquan(d);
					o1.cancel(d);
					s1.plus(e,f);
					cout<<"Order cancelled ";
					cout<<"successfully\n";
				}
				break;
			case 3:exit(0);

			default: continue;
	  }
     }
}
/////////////////////////////////////////////////////////////////////////////


//////////////***************Menu for Admin****************///////////////////

void adminf()
{
	clrscr();
	char opt,ch;
	order o3;

	do
	{
		cout<<setw(50)<<"\n********Menu********\n";
		cout<<endl<<"Enter your option";
		cout<<endl<<"1. Review Stocks";
		cout<<endl<<"2. See Orders list";
		cout<<endl<<"3. HR Department";
		cout<<endl<<"4. Exit from the program"<<endl;
		cout<<"********************"<<endl;
		cin>>opt;
		switch(opt)
		{
			case'1':stock();
				break;
			case'2':o3.show();
				break;
			case'3':emp();
				break;
			case'4':exit(0);
				break;
			default:cout<<"Invalid Choice!!\n";
		}

		cout<<"\nDo you want to continue..?(y/n)";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	getch();
}
///////////////////////////////////////////////////////////////////////////////



///////////////***********//Funtion for Password//**********//////////////////

void pass()
{
	char username[5];
	char password[6];
	cout<<"Enter Username : ";
	gets(username);

	cout<<"Enter Password : ";           //to enter password
	for(int j=0;j<4;j++)
	{
		password[j]=getch();
		cout<<"*";
	}

	//for admin
	if (strcmpi(username,"admin")==0 && strcmpi(password,"pass")==0)
	{
		cout << "\n Correct!!!" << endl;
		adminf();
	}

	//for user
	else if (strcmpi(username,"user")==0 && strcmpi(password,"code")==0 )
	{
		cout << "\n Correct!!!" << endl;
		userf();
	}

	else
	{
		cout << "\nInvalid login details" << endl;
	}

}

//***************************Main Function********************************//
void main()
{
 clrscr();
 screen();
 cout<<endl<<setw(125)<<"WELCOME\n\n";
 pass();
 getch();
}
