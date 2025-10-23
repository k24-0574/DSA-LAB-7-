#include<iostream>
#include<cmath>
#include<string>
using namespace std;

struct Node{
	string name;
	int score;
	Node* next;
	Node(string n,int s){
		name=n;
		score=s;
		next=nullptr;
	}
};
class LinkedList{
	Node* head;
	int getMax(){
		int mx=0;
		Node* t=head;
		while(t){
			if(t->score>mx) mx=t->score;
			t=t->next;
		}
		return mx;
	}
	int getDigit(int num,int place){
		return (num/(int)pow(10,place))%10;
	}
	Node*countingSort(Node*head,int place){
		Node* bhead [10]={nullptr};
		Node* t[10]={nullptr};
		Node*x=head;
		while(x){
			int d=getDigit(x->score,place);
			Node*n=x->next;
			x->next=nullptr;
			if(! bhead [d])   bhead [d]=t[d]=x;
			else{
				t[d]->next=x;
				t[d]=x;
			}
			x=n;
		}
		Node*h=nullptr;
		Node*end=nullptr;
		for(int i=0;i<10;i++){
			if( bhead [i]){
				if(!h){
					h= bhead [i];
					end=t[i];
				}
				else{
					end->next= bhead [i];
					end=t[i];
				}
			}
		}
		return h;
	}
	public:
	LinkedList(){
		head=nullptr;
	}
	~LinkedList(){
		Node*temp1=head, *temp2;
		while(temp1){
			temp2 =temp1->next;
			delete temp1;
			temp1=temp2;
		}
	}
	void addNode(string n,int s){
		Node *newnode=new Node(n,s);
		if(!head){
			head=newnode;
			return;
		}
		Node*t=head;
		while(t->next) t=t->next;
		t->next=newnode;
	}

	void display(){
		Node*t=head;
		while(t){
			cout<<t->name<<" "<<t->score<<endl;
			t=t->next;
		}
	}
	void radixSort(){
		if(!head||!head->next)return;
		int m=getMax();
		int d;
		if(m==0) d=1;
		else d=(int)log10(m)+1;

		for(int p=0;p<d;p++) head=countingSort(head,p);
	}

	void deleteRecord(string n,int s){
		Node*t=head;
		Node*p=nullptr;
		while(t){
			if(t->name==n&&t->score==s){
				if(p)p->next=t->next;
				else head=t->next;
				delete t;
				cout<<"Record deleted!\n";
				return;
			}
			p=t;
			t=t->next;
		}
		cout<<"Record not found.\n";
	}
};
int main(){
	LinkedList l;
	l.addNode("Ayan",90);
	l.addNode("Zameer",60);
	l.addNode("Sara",70);
	l.addNode("Sohail",30);
	l.addNode("Ahmed",20);

	cout<<"Before:"<<endl;
	l.display();

	l.radixSort();
	cout<<endl<<"After:"<<endl;
	l.display();

	return 0;
}
