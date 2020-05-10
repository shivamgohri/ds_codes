#include <iostream>

using namespace std;


class node{

public:
	int data;
	node* next;

	node(int d){
		data = d;
		next = NULL;
	}
};

bool searchRecursive(node* head, int key){
	if(head==NULL){
		return false;
	}

	if(head->data==key){
		return true;
	}
	else{
		return searchRecursive(head->next, key);
	}
}

void insertAtHead( node*& head, int data ){
	node* n = new node(data);
	n->next = head;
	head = n;
}

void insertAtTail(node*&head, int data){

	if(head==NULL){
		head = new node(data);
		return;
	}

	node* temp = head;
	while(temp->next!=NULL){
		temp = temp -> next;
	}

	node* n = new node(data);
	temp->next = n;
}

void insertInMiddle( node*&head, int data, int p){

	p--;
	node* temp = head;
	while(p--){
		temp = temp->next;
	}

	node* n = new node(data);
	n->next = temp->next;
	temp->next = n;
}

void deleteAtHead(node*&head){
	if(head==NULL){
		return;
	}
	node* temp = head;
	head = head->next;
	delete temp;
}

void deleteAtTail(node*&head){
	if(head==NULL){
		return;
	}
	node* temp = head;
	while(temp->next->next!=NULL){
		temp = temp->next;
	}
	node* a = temp->next;
	temp->next = NULL;
	delete a;
}

void deleteAtMiddleKey(node*& head, int key){
	if(head==NULL){
		return;
	}
	node* temp = head;
	while(temp->next->data!=key){
		temp = temp->next;
	}
	node* d = temp->next;
	node* a = temp->next->next;
	temp->next = a;
	delete d;
}

void deleteAtMiddlePosition(node*& head, int pos){
	if(head==NULL){
		return;
	}

	if(pos==1){
		deleteAtHead(head);
	}

	pos -= 2;
	node* temp = head;
	while(pos--){
		temp = temp ->next;
	}

	node* d = temp->next;
	temp->next = temp->next->next;
	delete d;
}

void print( node* head ){

	node* temp = head;

	while(temp!=NULL){
		cout<< temp->data <<"->";
		temp = temp->next;
	}

	return;
}

void buildList(node*&head){

	int n;
	cin>>n;

	while(n!=-1){
		insertAtTail(head, n);
		cin>>n;
	}

	return;
}

istream& operator>>(istream& is, node*& head){        //return type is because we want to do cascading eg. cin>>head>>head;
	buildList(head);
	return is;
}

ostream& operator<<(ostream& os, node*head){
	print(head);
	return os;
}

void reverse(node*&head){
	node* current = head;
	node* prev = NULL;

	while(current!=NULL){
		node* temp = current->next;
		current->next = prev;
		prev = current;
		current = temp;
		head = prev;
	}
}

node* midPoint(node* head){

	if(head==NULL || head->next==NULL){
		return head;
	}

	node* slow = head;
	node* fast = head->next;

	while( (fast!=NULL) && (fast->next!=NULL) ){
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;
}

node* reverseRecursive(node* head){

	if(head->next==NULL || head==NULL){
		return head;
	}

	node* small = reverseRecursive(head->next);
	node* current = head;
	current->next->next = current;
	current->next = NULL;
	return small;
}

node* kLast(node*head, int k){

	if(head==NULL){
		return NULL;
	}

	node* slow = head;
	node* fast = head;

	int temp = k;
	while(temp--){
		fast = fast->next;
	}

	while(fast!=NULL){
		slow = slow->next;
		fast = fast->next;
	}

	return slow;
}

node* merge(node* head1, node* head2){

	if(head1==NULL){
		return head2;
	}
	else if(head2==NULL){
		return head1;
	}

	node* c;

	//compare
	if( head1->data<head2->data ){
		c = head1;
		c->next = merge(head1->next, head2);
	}
	else{
		c = head2;
		c->next = merge(head1, head2->next);
	}

	return c;
}

node* mergeSort(node* head){

	if(head==NULL || head->next==NULL){
		return head;
	}

	node* slow = head;
	node* fast = head->next;

	while(fast!=NULL && fast->next!=NULL){
		fast = fast->next->next;
		slow = slow->next;
	}

	node* a = slow;
	slow = slow->next;

	a->next = NULL;

	node* first = mergeSort(head);
	node* second = mergeSort(slow);

	return merge(first, second);
}

bool detectCycle(node* head){

	node* slow = head;
	node* fast = head;

	while( fast!=NULL && fast->next!=NULL ){
		fast = fast->next->next;
		slow = slow->next;

		if(fast==slow){
			return true;
		}
	}

	return false;
}


int main(){

	// node* head = NULL;

	// insertAtHead(head, 5);
	// insertAtHead(head, 4);
	// insertAtHead(head, 3);
	// insertAtHead(head, 1);

	// print(head);
	// cout<<endl;

	// insertInMiddle(head, 2, 1);

	// print(head);
	// cout<<endl;

	// insertAtTail(head, 6);

	// print(head);
	// cout<<endl;

	// node* head = NULL;

	// buildList(head);
	// print(head);

	node* head1 = NULL;
	node* head2 = NULL;

	cin>> head1 ;

	cout<< mergeSort(head1);




	return 0;
}