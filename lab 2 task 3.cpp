#include <iostream>
using namespace std;
class Node
{
	public:
	int data;
	Node*next;
	};
	int main(){
		Node n1,n2,n3;
		n1.data=90;
		n2.data=30;
		n3.data=10;
		n1.next=&n2;
		n2.next=&n3;
		n3.next= NULL;
		Node*p= &n1;
		while(p!=NULL)
		{
			cout<< p->data <<""<<endl;
			p=p->next;
		}
		return 0;
	}