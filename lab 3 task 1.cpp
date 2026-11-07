#include <iostream>
using namespace std;
class product{
public:
    string name;
    string code;
    float price;
};
void display(){
}
int main() {
    int n;
    cout<<"enter number of product"<<endl;
    cin>>n;
    product* products = new product[n];
    for(int i=0;i<n;i++){
        cout<<"enter details"<<endl;
        cout<<"name"<<endl;
        cin>>products[i].name;
        cout<<"code"<<endl;
        cin>>products[i].code;
        cout<<"price"<<endl;
        cin>>products[i].price;
    }
    cout<<"product details"<<endl;
    for(int i=0;i<n;i++){
        cout<<"name"<<products[i].name;
        cout<<"code"<<products[i].code;
        cout<<"price"<<products[i].price;
    }
    delete[]products;
    return 0;
}