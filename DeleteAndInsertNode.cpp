#include<bits/stdc++.h>
using namespace std;
#include "node.cpp"

node* takeinput(){
	int data;
	cin>>data;
	node *head=NULL;
	node *tail=NULL;
	while(data!=-1){
		node *newnode= new node(data);
		if(head==NULL){
			head=newnode;
			tail=newnode;
		}
		else{
			tail->next=newnode;
			tail=newnode;
		}
		cin>>data;
	}
	return head;
}
node* deletenode(node* head,int i){
	int counter=0;
	node *temp=head;
	if(head==NULL)
		return head;
	if(i==0)
		return head->next;
	while(temp!=NULL && counter<i-1){
			temp=temp->next;
			counter++;
		}
		if(temp==NULL){
			return head;
		}
		if(temp->next!=NULL){
			temp->next=temp->next->next;
		}
		return head;
			
}
int length(node *head){
	node *temp=head;
	int count=0;
	if(temp==NULL)
		return 0;
	
	return 1+length(temp->next);
}
node* InsertNode(node *head, int index, int data){
	node *newnode=new node(data);
	node *bridge;
	node *temp=head;
	int counter=0;
	if(index==0){
		bridge=head;
		head=newnode;
		newnode->next=bridge;
	}
	else{
		while(counter < (index-1)){
			if(temp==NULL)
				return head;
			temp=temp->next;
			counter++;
		}
		bridge=temp->next;
		temp->next=newnode;
		newnode->next=bridge;	
	}
	
	return head;
}
void print(node *head){
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}
int main()
{	
	int index,data;
	node *head=takeinput();
	cout<<"Now Printing:"<<endl;
	print(head);
	cout<<"Enter Index to Delete:"<<endl;
	cin>>index;
	head=deletenode(head,index);
	print(head);
	cout<<"Enter index to insert a node:"<<endl;
	cin>>index;
	cout<<"Enter data to insert:"<<endl;
	cin>>data;
	head=InsertNode(head,index,data);
	print(head);
	return 0;
}