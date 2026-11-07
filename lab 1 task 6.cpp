#include <iostream>
using namespace std;
struct product{
	int productid;
	string name;
	float price;
	int quantity;
};
int main(){
	product p;
	float totalprice;
	cout<<"enter productid"<<endl;
	cin>>p.productid;
	cout<<"enter product name"<<endl;
	cin>>p.name;
	cout<<"enter product price"<<endl;
	cin>>p.price;
	cout<<"enter product quantity"<<endl;
	cin>>p.quantity;
	cout<<"product id"<<p.productid<<endl;
	cout<<"product name"<<p.name<<endl;
	cout<<"product price"<<p.price<<endl;
	cout<<"product quantity"<<p.quantity<<endl;
	return 0;	
}