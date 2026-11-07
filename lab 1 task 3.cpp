#include <iostream>
using namespace std;
int main(){
	int num1,num2;
	cout<<"enter two numbers:"<<endl;
	int *p1= &num1;
	cout<<"value before swaping : " <<num1<<endl;
    int *p2= &num2;
	cout<<"value after swaping :  " <<num2 <<endl;
	return 0;
}