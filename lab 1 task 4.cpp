#include <iostream>
using namespace std;
int main(){
   int a,b,temp;
   cout<<"enter two values:"<<endl;
   cin>>a>>b;
   cout<<"before swaping"<<endl;
   cout<<"a="<< a<<endl;
   cout<<"b="<<b<<endl;
   int *p1=&a;
   int *p2=&b;
   
   temp=*p1;
   *p1=*p2;
   *p2=temp;
 cout<<"after swaping" <<endl; 
   cout<<"a="<< a<<endl;
   cout<<"b="<<b<<endl;
   return 0;
}