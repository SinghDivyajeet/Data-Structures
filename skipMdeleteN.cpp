//This program takes ipnut into a linkedlist, and then takes 
//two inputs M & N, and then it leaves the M nodes and 
// deletes the further N nodes till we reach at the end.
#include<bits/stdc++.h>
using namespace std;
#include "node.cpp" 
node *takeinput(){
	int data;
	cin>>data;
	node *head=NULL;
	node *tail=NULL;
	while(data!=-1){
		node *newnode=new node(data);
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
void print(node *head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}
node* skipMdeleteN(node *head,int M, int N){
	int m=M;
	int n=N;
	node *temp=head;
	while(temp!=NULL){
		m=M;
		n=N;
		while(temp!=NULL && (m-1)>0){
			cout<<temp->data<<"->";
			temp=temp->next;
			--m;
		}
		if(temp==NULL)
			return head;
		while(temp!=NULL && n>0){
			if(temp->next!=NULL){
				cout<<"("<<temp->next->data<<")"<<"->";
				temp->next=temp->next->next;
				temp=temp->next;
				--n;
			}
			else
				return head;
		}
		if(temp==NULL)
			return head;
	}
	
}
int main(int argc, char const *argv[])
{
	int M,N;
	node *head=takeinput();
	print(head);
	cin>>M>>N;
	head=skipMdeleteN(head,M,N);
	print(head);
	return 0;
}