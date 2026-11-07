#include <iostream>
using namespace std;
int main(){
	int array[10];
	int num;
	cout<<"enter 10 integers"<<endl;
	for(int i=1;i<=10;i++){
		cin>> array[i];
	
	if(array[i]<0)
		cout<<"number is negative"<<endl;
	else if(array[i]>0)
		cout<<"number is positive"<<endl;
	else
		cout<<"number is zero"<<endl;
		
}
		return 0;
}