#include<iostream>
using namespace std;
int main(){
	int num=10;
	int*p=&num;
	int**pp=&p;
	cout<<"original value"<<num<<endl;
	**pp=50;
	cout<<"modify value"<<num<<endl;
	return 0;
}