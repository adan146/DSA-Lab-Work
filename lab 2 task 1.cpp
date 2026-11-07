#include<iostream>;
using namespace std;
int main(){
int arr[10];
int odd , even;
cout<<"enter 10 numbers"<<endl;
for(int i=0 ;i<10 ;i++){
	cin >> arr[i];	
}
int*p=arr;
for (int i=0 ; i<10 ; i++){
	if(*p % 2 ==0)
 even++;
	else
 odd++;
	*p++;
}
cout<<"even ="<<even<<endl;
cout<<"Odd ="<<odd<<endl;			
	return 0;
}