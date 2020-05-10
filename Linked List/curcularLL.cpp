#include <iostream>

using namespace std;

class node{
public:
	int data;
	node* next;

	node(int data){
		this->data = data;
	}
};

void pushHead(node*&head, int data){

	node* n = new node(data);
	node* temp = head;
	n->next = head;

	if(head!=NULL){
		while(temp->next!=head){
			temp = temp->next;
		}
		temp->next = n;
	}
	else{
		n->next = n;
	}

	head = n;
}

void pushTail(node*&head, int data){

	node* n = new node(data);
	node* temp = head;

	if(head!=NULL){
		while(temp->next!=head){
			temp = temp->next;
		}
		temp->next = n;
		n->next = head;
	}
	else{
		head = n;
		n->next = head;
	}

}

void print(node* head){
	node* temp = head;
	while(temp->next!=head){
		cout<<temp->data<<"->";
		temp = temp->next;
	}
	cout<<temp->data<<"->";
	cout<<endl;
}

ostream& operator<<(ostream& is, node* head){
	print(head);
	return is;
}

node* getNode(node*head, int data){
	node* temp = head;
	while(temp->next!=head){
		if(temp->data==data){
			return temp;
		}
		temp = temp->next;
	}

	return NULL;
}

void deleteNode(node*&head, int data){
	node* del = getNode(head, data);

	if(del==NULL){
		cout<<"Node not present in LL!";
		return;
	}

	if(head==del){
		head = del->next;
	}

	node* temp = head;
	while(temp->next!=del){
		temp = temp->next;
	}

	temp->next = del->next;
	delete del;
	return;
}

int main(){

	node* head = NULL;

	pushTail(head, 1);
	pushTail(head, 2);
	pushTail(head, 3);
	pushHead(head, 0);

	deleteNode(head, 5);

	cout<< head;

	return 0;
}