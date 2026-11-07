#include <iostream>
using namespace std;
struct Student{
string name;
int rollno;
int marks;	
};
int main(){
Student s;
cout<<"enter name"<<endl;
cin>>s.name;
cout<<"enter roll no"<<endl;
cin>>s.rollno;
cout<<"enter marks"<<endl;
cin>>s.marks;
 cout<<"student name:"<<s.name<<endl;
 cout<<"student roll no:"<<s.rollno<<endl;
 cout<<"student marks:"<<s.marks <<endl;
 if(s.marks>=50)
 	cout<<"pass"<<endl;
else
cout<<"fail"<<endl;
 return 0;
}