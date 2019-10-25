#include<fstream.h>
#include<conio.h>
#include<ctype.h>
#include<stdio.h>
class BOOK
{
 int bno;
 char bname[20],aname[20];
 public:
 void repor1()
 {
  cout<<bno<<bname<<aname<<endl;
 }
 void createbook()
 {
  cout<<"Enter book no."<<endl;
  cin>>bno;
  cout<<"Enter book name"<<endl;
  gets(bname);
  cout<<"Enter author name"<<endl;
  gets(aname);
 }
 void displaybook()
 {
 cout<<"The Book no. is :"<<bno<<endl;
 cout<<"The Name of the book is :"<<bname<<endl;
 cout<<"The Book's Author name is :"<<aname<<endl;
 }
 int rbno()
 {
 return bno;
 }
 char *rbname()
 {
 return bname;
 }
 char *raname()
 {
 return aname;
 }
};
class Student
{
 int admno;
 char name[20];
 int stbno;
 int token;
 public:
 void repot2()
 {
  cout<<admno<<name<<endl;
 }
 void createstudent()
 {
  cout<<"Enter Admission no. :"<<endl;
  cin>>admno;
  cout<<"Enter name:"<<endl;
  gets(name);
  token=0;
  stbno=0;
 }
 void showstudent()
 {
  cout<<"Your admission number is :"<<admno<<endl;
  cout<<"Name :"<<name<<endl;
  cout<<"The token number is :"<<token<<endl;
  if(token==1)
   cout<<"Book no. is :"<<stbno<<endl;
 }
 char *rsname()
 {
  return name;
 }
 int radmno()
 {
  return admno;
 }
 int rstbno()
 {
  return stbno;
 }
 int rtoken()
 {
  return token;
 }
 void Addtoken()
 {
  token=1;
 }
 void resettoken()
 {
  token=0;
 }
 void getsbno(int t)
 {
  stbno=t;
 }
};
int checkpass()
{
 char pass[40];
 fstream fil;
 fil.open('Password.txt',ios::in);
 char password[80];
 fil.getline(password,80);
 char ch;int i=0;
 do
 {
  ch=fil.get();
  cout<<'*';
  pass[i++]=ch;
 }while(ch!=13);
 pass[i-1]='\0';
 if(strcmp(password,pass)==0)
   return 1;
 else
   return 0;
 }
}
fstream F,F1;
Book b;
Student s;
void writebook()
{
 char ch;
 F.open("Book.dat",ios::out|ios::app);
 do
 {
   clrscr();
   b.createbook();
   F.write((char*)&b,sizeof(b));
   cout<<"Do you want to add more? : (Y/N)";
   cin>>ch;
 }while ( ch=='Y'|| ch=='y' );
 F.close();
}
void writestudent()
{
 char ch;
 F.open("Student.dat",ios::out|ios::app);
 do
 {
   s.createstudent();
   F.write((char*)&s,sizeof(s));
   cout<<"Do you want to add more?:  (Y/N)";
   cin>>ch;
 }while(ch=='y'||ch=='Y');
 F.close();
}
void showbook(char n[])
{
 cout<<"BOOK DETAILS";
 int flag=0;
 F.open("Book.dat",ios::in);
 while(F.read((char*)&b,sizeof(b)));
 {
  if(strcmpi(b.rbname(),n)==0)
  {
   b.displaybook();
   flag=1;
  }
 }
 F.close();
 if(flag==0)
 cout<<"No book found";
 getch();
}
void Displaystudent(char n[])
{
 cout<<"  Student Details" ;
 int flag=0;
 F.open("student.dat",ios::in);
 while(F.read((char*)&s,sizeof(S)))
 {
  if(strcmpi(s.rsname(),n)==0)
  {
   s.showstudent();
   flag=1;
  }
 }
 F.close();
 if(flag==0)
	cout<<"No book found";
	getch();
}
void deletestudent()
{
 char n[6];
 clrscr();
 cout<<"Delete student record";
 cout<<" Enter admno no. of the student whose record is to be deleted";
 cin>>n;
 F.open("Student.dat",ios::in|ios::out);
 fstream F2;
 F2.open("Temp.dat"ios::out);
 F2.seekg(ios::key);
 while(F.read((char*)&s,sizeof(s)));
 {
  if(strcmpi(b.rsname(),n)!=0);
  {
   F2.write((char*)&s,sizeof(s))
  }
  F2.close()
  Fclose();
 rename("Student.dat");
 rename("Temp.dat","Student.dat");
 cout<<"Delete";
getch();
}
void deletebook()
{
 char n[6];
 clrscr();
 cout<<"Delete Book";
 cout<<" Enter book no. for the book which is to be deleted";
 cin>>n;
 F.open("Book.dat",ios::in|ios::out);
 fstream F2;
 F2.open("Temp.dat"ios::out);
 F2.seekg(ios::key);
 while(F.read((char*)&b,sizeof(b)));
 {
  if(strcmpi(b.rbname(),n)!=0);
  {
   F2.write((char*)&b,sizeof(b))
  }
  F2.close()
  Fclose();
 rename("Book.dat");
 rename("Temp.dat","book.dat");
 cout<<"Delete";
getch();
}
void displayallstudents()
{
 clrscr();
 F.open("Student.dat",ios::in);
 if(!F)
 {
  cout<<"error"<<endl;
  getch();
  return();
 }
 cout<<"Student list :"<<endl;
 cout<<"Admission No. :"<<endl;
 cout<<"Name         :" <<endl;
 cout<<"Book Issued  :" <<endl;
 while(F.read((char*)&s,sizeof(s)))
 {
  s.report2();
 }
 F.close();
 getch();
}
void displayallbooks()
{
 clrscr();
 F.open("Book.dat",ios::in);
 if(!F)
 {
  cout<<"error"<<endl;
  getch();
  return();
 }
 cout<<"Book list :"<<endl;
 cout<<"Book No. :"<<endl;
 cout<<"Book Name         :" <<endl;
 cout<<"Book Author  :" <<endl;
 while(F.read((char*)&b,sizeof(b)))
 {
  b.report1();
 }
 F.close();
 getch();
}
