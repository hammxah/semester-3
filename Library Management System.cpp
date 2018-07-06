#include<iostream>
#include<conio.h>
#include<fstream>
#include<string>
#include<iomanip>
#include<stdlib.h>
#include<windows.h>
using namespace std;

void write_student();	
void display_all();	
void display_search(int);	
void modify_student(int);
void menu();

///////////////Admin class///////////////
class admin
{

private:
	char u_name[20];
	char u_pass[5];
public:
	void user()
	{
		cout<<"Enter user name :"<<endl;
		cin.getline(u_name,20);
		cin.ignore();

		cout<<"Enter user password :"<<endl;
		cin.getline(u_pass,5);
		cin.ignore();
	}
	void create_user()
	{
		ofstream ofile;
		ofstream oofile;
		ofile.open("name.txt",ios::out);
		oofile.open("pas.txt",ios::out);

		ofile.write((char*)&u_name,sizeof(u_name));
		oofile.write((char*)&u_pass,sizeof(u_pass));
		ofile.close();
		oofile.close();
	}
	void show_user()
	{

		ifstream name;
		ifstream pas;
		name.open("name.txt",ios::in);
		pas.open("pas.txt",ios::in|ios::app);
		name>>u_name;
		pas>>u_pass;

		cout<<"Name is : "<<u_name<<endl<<endl;
		cout<<"Password is : "<<u_pass<<endl<<endl;
	}
	void login()
	{
		char h_pass[5];
		fstream ifile;
		ifile.open("pas.txt",ios::in);
		ifile.read((char*)&h_pass,sizeof(h_pass));

		cout<<"Enter name :"<<endl;
		cin.getline(u_name,20);
		cin.ignore();
		cout<<"Enter password :"<<endl;
		cin.getline(u_pass,5);
		cin.ignore();

		bool check=false;
		int chk=0;
		for(int i=0;i<4;i++)
		{
			if(h_pass[i] == u_pass[i])
			{
				check=true;
				chk++;
				
			}
			else
			{
				check=false;
			}
		}
	
		if(check==true && chk==4)
		{
			
			char ch;
			while(1==1)
			{
				char ch;
				int num;

				cout<<endl;
				cout<<"\n\n\n\t ENTRY MENU"<<endl;
				cout<<"\n\n\t1) ENTER 1 FOR BOOK RECORD AND ENTRY(n0 space)"<<endl;
				cout<<"\n\n\t2) CREATE STUDENT RECORD(n0 space)"<<endl;
				cout<<"\n\n\t3) DISPLAY ALL STUDENTS RECORDS(n0 space)"<<endl;
				cout<<"\n\n\t4) SEARCH STUDENT RECORD(n0 space) "<<endl;
				cout<<"\n\n\t5) EXIT"<<endl<<endl;

				for(int i=0;i<80;i++) 
					cout<<"*";
				cout<<endl;
				cout<<"\n\n\tPlease Enter Your Choice (1-5) ";
				cin>>ch;


				switch(ch)
				{
				case '1':

					menu();
					system("cls");
					break;
				case '2':

					write_student(); 
					system("cls");
					break;
				case '3':

					display_all();
					system("cls");
					break;
				case '4':
					cout<<"\n\n\tPlease Enter The Student ID[DIGIT] ";
					cin>>num;
					display_search(num);
					system("cls");
					break;
				case '5':
					cout<<"Thanks for using LMS :-)"<<endl;
					system("pause");
					exit(1);
				default:
					cout<<"Wrong Input"<<endl;
				}
				cout<<"Do you want to continue Yes(Y) or No(N)"<<endl;
				cin>>ch;
				if(ch=='y' || ch=='Y'){
					continue;
				} else
				break;
				
			}	
			
		}
		
		else
		{
			cout<<"Not succeeded";
		}
	}
};



///////////////////Start Program/////
/////////////////student class//////
class student                                                                                          
{                                                                                                      
private:                                                                                              
	/////////data member////////                                                                                      

	int s_id;                                                                                             
	char  s_name[20];                                                                                     
	char issue_book[20];                                                                                  
	char return_date[20];                                                                                 
	char s_dept[20];                                                                                      

public:         
	////////////////function member......  
	////////Student Gett Data//////                                                                                    
	void getdata()                                                                                       
	{               

		system("color d");
	    system("color 70");
		cout<<"Enter the student name[no space]"<<endl;                                                                 
		cin>>s_name;                                                                               
		cin.ignore();                                                                                        
		cout<<"Enter the student id[digit]"<<endl;                                                                                                                                                     
		cin>>s_id;                                                                                            
		cin.ignore();                                                                                        
		cout<<"Enter the student issue book[no space]"<<endl;                                                                                                                                                   
		cin>>issue_book;                                                                           
		cin.ignore();                                                                                        
		cout<<"Enter the student issue return book date[no space]"<<endl;                                                                                                                                      
		cin>>return_date;                                                                          
		cin.ignore();                                                                                        
		cout<<"Enter the student department[no space]"<<endl;                                                                                                                                              
		cin>>s_dept ;                                                                              
		cin.ignore();

	}     
	//////////////////////ID   Return////                                                                                              
	int getid()                                                                                           
	{                                                                                                     
		return s_id;                                                                                         
	}  
	///////////////////Student Show Data////                                                                                                   
	void showdata()                                                                                      
	{ 
		
		for(int i=0;i<80;i++) 
			cout<<"*";
		cout<<endl;                                                                                             
		cout<<"Student name"<<"\t"<<s_name<<endl;                                                             
		cout<<"Student Id"<<"\t"<<s_id<<endl;                                                                 
		cout<<"Student issue book"<<"\t"<<issue_book<<endl;                                                   
		cout<<"Student returns book date"<<"\t"<<return_date<<endl;                                           
		cout<<"Student department "<<"\t"<<s_dept<<endl;                                                      
		for(int i=0;i<80;i++) 
			cout<<"*";
		cout<<endl;

	}                                                                                                     
};
////////////////////class book////////
class book
{

private:
	int isbn ;
	char book_name[50];
	char author_name[50];
public:

	////////////////// getter seter of book isbn//////////////////////	

	void set_isbn(int isb)////////seter
	{
		isbn=isb;
		ofstream out;
		out.open("ISBN.txt",ios::app);
		out<<isbn<<endl;
		out.close();
	}

	int get_isbn()///////////getter
	{
		return isbn;
	}

	/////////////////getter setter of book name/////////////

	void set_bookname(char *bn)////////seter
	{

		int i=0;
		while(bn[i]!='\0')
		{
			book_name[i]=bn[i];	
			i++;
		}

		book_name[i]='\0';
		ofstream out;
		out.open("book name.txt",ios::app) ;
		out<<book_name<<endl;  
		out.close();

	}

	char* get_bookname()///////////getter
	{
		return book_name;
	}
	////////////////////getter setter of author naem///////////


	void set_aname(char *an)/////////seter
	{
		int i=0;
		while(an[i]!='\0')
		{
			author_name[i]=an[i];
			i++;	
		}

		author_name[i]='\0';
		ofstream out;
		out.open("author name.txt",ios::app) ;
		out<<author_name<<endl;

	}

	char* get_aname()///////////////getter/////////////////
	{
		return author_name;
	}

}; 

void showallbook()
{
	
	char nameBook1[50];
	ifstream fi;
	if(!fi)
		cout<<"File not open";
	fi.open("book name.txt",ios::in|ios::out);
	while(!fi.eof())
	{
		fi>>nameBook1;
		cout<<nameBook1<<endl<<endl;
	}
}
//////////////////////ending show all book function//////////////

////////////////////////starting all record show functio//////////

void showall()
{
	
	int isbb;
	char nameBook1[50],authorname[50];

	ifstream fi;
	ifstream fi1;
	ifstream fi2;
	cout<<setw(15)<<"ISBN"<<setw(15)<<"Book Name"<<setw(15)<<"Author"<<endl<<endl;
	
	if(!fi&&!fi1&&fi2)
		cout<<" File not open";
	fi.open("book name.txt",ios::in);
	fi1.open("author name.txt",ios::in);
	fi2.open("ISBN.txt",ios::in);
	while(!fi.eof())
	{
		fi>>nameBook1;
		fi1>>authorname;
		fi2>>isbb;
		cout<<setw(15)<<isbb<<setw(15)<<nameBook1<<setw(15)<<authorname<<endl<<endl;
	}

	fi.close();
	fi1.close();
	fi2.close();

}	
/////////////////////////////////////starting search books////////////////
void search_book()
{
	
	int isbb,n;
	int i=0;
	int j=0;
	char nameBook1[50],authorname[50];
	char name[50];
	cout<<endl<<"Enter ISBN for search : ";
	cin>>n;

	ifstream fi;
	ifstream fi1;
	ifstream fi2;
	cout<<setw(15)<<"ISBN"<<setw(15)<<"Book Name"<<setw(15)<<"Author"<<endl<<endl;
	
	if(!fi&&!fi1&&!fi2)
		cout<<" File not open";
	fi.open("book name.txt",ios::in);
	fi1.open("author name.txt",ios::in);
	fi2.open("ISBN.txt",ios::in);
	while(!fi.eof())
	{
		
		fi>>nameBook1;
		fi1>>authorname;
		fi2>>isbb;
		if(isbb==n)
		{
			i++;
			cout<<setw(15)<<isbb<<setw(15)<<nameBook1<<setw(15)<<authorname<<endl<<endl;
		}

	}

	if(i==0)
	{
		cout<<endl<<"Record Not Found"<<endl<<endl;
	}
	else
	{
		cout<<endl<<"Record Found"<<endl<<endl;
	}


	fi.close();
	fi1.close();
	fi2.close();
	
}

void menu()
{

	book b;
	int is_bn1,is_bn2;
	char nameBook1[50],*nameBook2;
	char nameAuthor1[50],* nameAuthor2;	
	char x;
	
	////////for reaption of code////

	cout<<"******************************************************************"<<endl;

	cout<<"\t\t\tWELCOME TO BOOK RECORD SECTION"<<endl;

	cout<<"******************************************************************\n\n"<<endl;



	do{


		cout<<endl;
		cout<<"\tPress 1 to Enter New Record"<<endl<<endl;
		cout<<"\tPress 2 to See All Books"<<endl<<endl;
		cout<<"\tPress 3 to See All Record"<<endl<<endl;
		cout<<"\tPress 4 to Search Book"<<endl<<endl;

		int n;

		cin>>n;

		cout<<endl<<endl<<endl;

		switch(n)
		{
		case 1:
			///////////// entering  book isbn//////////////////////

			cout<<endl<<endl<<"\tEnter Book ISBN Number (only integers)";
			cin>>is_bn1;
			cin.ignore();
			b.set_isbn(is_bn1);

			/////////////enting book name //////////////////////////

			cout<<endl<<"\tEnter Book Name(do not use space,use - for space )";
			cin.getline(nameBook1,50);
			cin.ignore();
			b.set_bookname(nameBook1);

			//////////////////entring aouther name ///////////////////

			cout<<endl<<"\tEnter book Author (do not use space,use - for space )"; 
			cin.getline(nameAuthor1,50);
			cin.ignore();
			b.set_aname(nameAuthor1);
			///////////////////////////////////////////////////////////////////

			///////////////////////getting isbn number///////////////////

			is_bn2=b.get_isbn();

			/////////////////////getting book name////////////////////////////

			nameBook2=b.get_bookname();

			////////////////////getting authore name/////////////////////////

			nameAuthor2=b.get_aname();

			///////////////////////////////////////////////////////
			cout<<endl<<"\tYou Enter This ISBN Number :"<<is_bn2<<endl<<endl;
			cout<<"\tYou Enter This Book Name :"<<nameBook2<<endl<<endl;
			cout<<"\tYou Enter This Author Number :"<<nameAuthor2<<endl<<endl<<endl;
			cout<<"Your record is save"<<endl<<endl<<endl;

			/////////////////////////////////ending 1 case///////////////////////////
			break;    
			/////////////////////////////////starting case2///////////////////////
		case 2:
			showallbook();
			break;
			///////////////////////////////starting case 3//////////////////////
		case 3:
			showall();
			break;	
			//////////////////////////starting case 4///////////////////////////
		case 4:
			search_book();
			break;
		default:
			cout<<"Wrong Input"<<endl<<endl;
			cout<<"\tPress Y To Restart Program And N to close the progeam"<<endl;
			cin>>x;
		}
	}while(x=='y'||x=='Y');
	cout<<"\n\nThanks for using LMS! :-)";
	getche();
	exit(0);
	return ;
}

student s1;
////////////////////write student file/////////                                                                                                  
void write_student()
{
	
	student s1;
	ofstream outfile;
	outfile.open("student.txt",ios::binary|ios::app);
	s1.getdata();
	outfile.write((char*)&s1,sizeof(s1));
	outfile.close();
	cin.ignore();
	getch();

}	
/////////////////////display write student file////
void display_all()
{
	
	student s1;
	ifstream infile;
	infile.open("student.txt",ios::binary);
	if(!infile)
	{
		cout<<"File opening error";
		getch();
		return;
	}
	cout<<"\n\n\n\t\tDISPLAY ALL DATA !!!\n\n";
	while(infile.read((char*)&s1,sizeof(s1)))
	{
		s1.showdata();
		cout<<"\n\n====================================\n";
	}
	infile.close();
	getch();

}	
///////////////////display search file///////////////
void display_search(int n)
{
	
	student s1;
	ifstream infile;
	infile.open("student.txt",ios::binary);
	if(!infile)
	{
		cout<<"File opening error";
		getch();
		return;
	}

	int found=0;
	while(infile.read((char*)&s1,sizeof(s1)))
	{
		if(s1.getid()==n)
		{
			s1.showdata();
			found=1;
		}
	}
	infile.close();
	if(found==0)
		cout<<"\n\nRecord not exist";
	getch();

}


//////////////////////  MAIN  ////////////////
int main()
{
	
	admin obj;
	int n=0;
	

	system("color b");
	system("color 70");
	for(int i=0;i<=80;i++)
	{
		cout<<"*";	
	}
	cout<<endl;
	cout<<"\t\t\t";Sleep(200);cout<<"W";Sleep(200);cout<<"E";Sleep(200);cout<<"L";Sleep(200);cout<<"C";Sleep(200);cout<<"O";Sleep(200);cout<<"M";Sleep(200);cout<<"E";Sleep(200);
	cout<<" T";Sleep(200);cout<<"O";Sleep(200);
	cout<<" L";Sleep(200);cout<<"I";Sleep(200);cout<<"B";Sleep(200);cout<<"R";Sleep(200);cout<<"A";Sleep(200);cout<<"R";Sleep(200);cout<<"Y";Sleep(200);
	cout<<" M";Sleep(200);cout<<"A";Sleep(500);cout<<"N";Sleep(200);cout<<"A";Sleep(200);cout<<"G";Sleep(200);cout<<"E";Sleep(200);cout<<"M";Sleep(200);cout<<"E";Sleep(200);cout<<"N";Sleep(200);cout<<"T";Sleep(200);
	cout<<" S";Sleep(200);cout<<"Y";Sleep(200);cout<<"S";Sleep(200);cout<<"T";Sleep(200);cout<<"E";Sleep(200);cout<<"M"<<endl;

	for(int i=0;i<=80;i++)
	{
	
		cout<<"*";	
	}
	cout<<endl;
	
	while(1==1)
	{
	cout<<endl<<endl<<"\t1. For Create New Account :"<<endl;
	cout<<endl<<"\t2. For Login :"<<endl;
	cout<<endl<<"\t3. To Exit."<<endl;
	cin>>n;
	cin.ignore();
	switch(n)
	{  
	case 1:

		system("color b");
		system("color 80");
		obj.user();
		obj.create_user();
		cout<<"Account is succefully created :"<<endl<<endl;
		obj.show_user();
		break;
	case 2:

		system("color b");
		system("color 70");
		obj.login();

		break;
	case 3:
		cout<<endl<<"Thanks for using LMS! :-)";
		getch();
		exit(1);
	default:
		cout<<endl<<"Wrong Input";
		getch();
	}
	}

	getch();
	return 0;	
}
