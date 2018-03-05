#include<bits/stdc++.h>
using namespace std;
#include "node.cpp"
node* takeinput(){
	int data;
	cin>>data;
	node* head=NULL;
	node* tail=NULL;
	while(data!=-1){
		node *newnode = new node(data);
		if(head==NULL){
			head=newnode;
			tail=newnode;
		}
		else{
			tail->next=newnode;
			tail=tail->next;
		}
		cin>>data;
	}
	return head;
}
void print(node* head){
	node *temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
node* swap_node(node* head, int m, int n){
	int counter=0;
	node *temp=head;
	node *hook1=NULL;
	node *hook2=NULL;
	node *swap1=NULL;
	node *swap2=NULL;
	node *swap_next1=NULL;
	node *swap_next2=NULL;
	
	if(m==0){
		hook1=head;
		swap1=head;
		swap_next1=head->next;
	}
	else{
		while(counter!=(m-1)){
		temp=temp->next;
		counter++;
		}

		hook1=temp;
		swap1=temp->next;
		swap_next1=temp->next->next;	
	}
	
	while(counter!=(n-1)){
		temp=temp->next;
		counter++;
	}
	hook2=temp;
	swap2=temp->next;
	swap_next2=temp->next->next;
	if(hook1==head)
		head=swap2;
	else
		hook1->next=swap2;
	swap2->next=swap_next1;
	
	hook2->next=swap1;
	swap1->next=swap_next2;

	return head;
}
int main()
{
	int m,n;
	node *head=takeinput();
	print(head);
	cin>>m>>n;
	head=swap_node(head,m,n);
	print(head);
	return 0;
}