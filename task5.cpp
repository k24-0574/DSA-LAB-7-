#include <iostream>
using namespace std;

struct Node{
	int data;
	Node*next;
	Node(int val){
		data = val;
		next = nullptr;
	}
};

class LinkedList{
	Node* head;
	public:
	LinkedList(){
		head=nullptr;
	}
	void insert(int val){
		Node*newNode=new Node(val);
		if(!head) head=newNode;
		else{
			Node*temp=head;
			while(temp->next) temp=temp->next;
			temp->next=newNode;
		}
	}
	Node*getTail(Node*cur){
		while(cur && cur->next) cur=cur->next;
		return cur;
	}

	void swap(Node*a,Node*b){
		int temp=a->data;
		a->data=b->data;
		b->data=temp;
	}

	Node* partition(Node *head , Node*end, Node** newHead, Node** newEnd){
		Node*pivot=end;
		Node *prev=nullptr, *cur=head, *tail=pivot;

		while(cur!=pivot){
			if(cur->data<pivot->data){
				if(!(*newHead)) *newHead=cur;
				prev=cur;
				cur=cur->next;
			}
			else{
				if(prev) prev->next=cur->next;
				Node* temp=cur->next;
				cur->next =nullptr;
				tail->next =cur;
				tail=cur;
				cur=temp;
			}
		}

		if(!(*newHead)) *newHead=pivot;
		*newEnd=tail;
		return pivot;
	}

	Node*quickSortRecur(Node*head,Node*end){
		if(!head || head==end) return head;
		Node* newHead= nullptr, *newEnd= nullptr;

		Node* pivot = partition(head, end, &newHead, &newEnd);
		if(newHead!=pivot){
			Node*temp=newHead;
			while(temp->next!=pivot) temp=temp->next;
			temp->next=nullptr;
			newHead=quickSortRecur(newHead,temp);
			temp=getTail(newHead);
			temp->next=pivot;
		}

		pivot->next=quickSortRecur(pivot->next,newEnd);
		return newHead;
	}
	void quickSort(){
		head=quickSortRecur(head, getTail(head));
	}
	void print(){
		Node*temp=head;
		while(temp){
			cout<<temp->data;
			temp=temp->next;
			if(temp) cout<<" -> ";
		}
		cout<<endl;
	}
};

int main(){
	LinkedList list;
	list.insert(10);
	list.insert(7);
	list.insert(8);
	list.insert(9);
	list.insert(1);
	list.insert(5);
	list.insert(3);

	cout<<"Original: ";
	list.print();

	list.quickSort();
	cout<<"Sorted: ";
	list.print();
	
	return 0;
}
