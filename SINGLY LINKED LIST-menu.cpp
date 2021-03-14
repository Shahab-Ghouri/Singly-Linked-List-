// OBAID ULLAH SHAHAB GHOURI
//	SINGLY LINKED LIST


#include <iostream>
using namespace std;
class node{
	public:
		int data;
		node *next;
};

class LinkedList{
	public:
		node *head,*tail;
		
		// Default constructor
		LinkedList(){
			this->head = NULL;
			this->tail = NULL;
		}
		
		// INSERTION
		void insert_at_last(int n){
			// creating a new node
			node *temp = new node;
			temp->data = n;
			temp->next = NULL;
			if(head == NULL){		// it means there is no linked list
				head = temp;
				tail = temp;
			}
			else{
				tail->next = temp;
				tail = temp;
			}
		}
		
		void insert_at_front(int n){
			node *temp = new node;
			temp->data = n;
				temp->next = head; 
				head = temp;
		}
		
		void insert_at_any_position(int n,int pos){
			node *temp = new node;
			temp->data = n;
			temp->next = NULL;
			node *curr,*prev;
			curr = head;
			for(int i=0; i<pos-1; i++){
				prev = curr;
				curr = curr->next;
			}
			prev->next = temp;
			temp->next = curr;
		}
//		******************************************

		// DELETING
		
		void delete_at_front(){
			node *temp;
			temp = head;
			head = temp->next;
			temp = NULL;
			delete temp;
		}
		
		void delete_at_last(){
			node *temp;
			node *ptr;
			temp = head;
			while(temp->next!=tail){
				temp = temp->next;
			
			}
			ptr = temp->next;
			temp->next = NULL;
			tail = ptr;
		}
		
		void delete_at_any_position(int pos){
			
			node *curr,*prev;
			curr = head;
			for(int i=0; i<pos-1; i++){
				prev = curr;
				curr = curr->next;
			}
			prev->next = curr->next;
			curr->next = NULL;
			delete curr;
			
		}
//		******************************************
		void display(){
			node *temp;
			temp = head;
			if(head == NULL)
			cout<<" There is no element in the list!!"<<endl;
			while(temp!=NULL){
				cout<<temp->data<<" ";
				temp = temp->next;
			}
		}
		
//			******************************************

			// MAXIMUMM
			
			int maximum(){
				node *temp;
				temp = head;
				int max = 0;
				while(temp!=NULL){
					if(max < temp->data)
						max = temp->data;
					
					temp = temp->next;	
					
				}
				return max;
			}
//				******************************************
			// MEAN
			
			int mean(){
				node *temp;
				temp=head;
				int sum=0,count=0;
				
				while(temp->next!=NULL){
					sum+=temp->data;
					count++;
					temp = temp->next;
				}
				
				return sum/count;
				
				
			}
			
//				******************************************

			//  SORTING
			
			void sorting(){
				node *curr;
				int a;
				node *temp;
				curr = head;
				
			while(curr->next!= NULL){
				temp = head;
				while(temp->next!=NULL){
					if(temp->data > temp->next->data){
						 a = temp->data;
						 temp->data = temp->next->data;
						 temp->next->data = a;
					}
					temp = temp->next;
				}
				curr = curr->next;
			}
				display();
			}
//			******************************************

//			Reversing
 
			void reverse(){
				node *temp;
				node *curr,*prev;
				curr = head;
				while(curr!=NULL){
					temp = curr->next;
					curr->next = prev;
					prev = curr;
					curr = temp;
				}
				head = prev;
			}
//			******************************************	
	
 
	
	
};

main(){
	LinkedList obj;
	int ch,val,pos;
	while(1){
		system("cls");
	cout<<"1-	Traverse()\n2-	insertAtFront()\n3-	insertAtEnd()\n4-	insertAtPosition()\n5-	DeleterFirst()\n6-	DeleteEnd()\n7-	DeletePosition\n8-	Maximum()\n9-	Mean()\n10-	Sort()\n11-	ReverseSLL()"<<endl;
	cout<<" Enter Your choice : ";cin>>ch;
	if(ch==0)
	exit(1);
		switch(ch){
			case 1:
				cout<<endl<<"\n ELEMENTS IN LINKED LIST ARE : "<<endl;
				obj.display();
				cout<<endl;
				cout<<" Press Any key To continue..."<<endl;
				fflush(stdin);
				cin.get();	// to hold the screen
				break;
			case 2:
				cout<<"\n INSERT AT FRONT : \n Value : ";cin>>val;
				obj.insert_at_front(val);	
				cout<<" Press Any key To continue..."<<endl;
				fflush(stdin);
				cin.get();	// to hold the screen
				break;
			case 3:
				cout<<"\n INSERT AT LAST : \n Value : ";cin>>val;
				obj.insert_at_last(val);	
				cout<<" Press Any key To continue..."<<endl;
				fflush(stdin);
				cin.get();	// to hold the screen
				break;
				
			case 4:
				cout<<"\n Insert At Any Position : \n Value : ";cin>>val;
				cout<<" Position : ";cin>>pos;
				obj.insert_at_any_position(val,pos);	
				cout<<" Press Any key To continue..."<<endl;
				fflush(stdin);
				cin.get();	// to hold the screen
				break;
				
			case 5:
				cout<<"\n Delete At First :";
				obj.delete_at_front();
				cout<<endl<<endl<<" Node has been Successfully Deleted..."<<endl<<endl;	
				cout<<" Press Any key To continue..."<<endl;
				fflush(stdin);
				cin.get();	// to hold the screen
				break;
				
			case 6:
				cout<<"\n Delete At Last :";
				obj.delete_at_last();
				cout<<endl<<endl<<" Node has been Successfully Deleted..."<<endl<<endl;	
				cout<<" Press Any key To continue..."<<endl;
				fflush(stdin);
				cin.get();	// to hold the screen
				break;
				
			case 7:
				cout<<"\n Delete At Any Position :";
				cout<<" Enter Position : ";cin>>pos;
				obj.delete_at_any_position(pos);
				cout<<endl<<endl<<" Node has been Successfully Deleted..."<<endl<<endl;	
				cout<<" Press Any key To continue..."<<endl;
				fflush(stdin);
				cin.get();	// to hold the screen
				break;
			
			case 8:
				cout<<"\n Maximum Number in the List : "<<obj.maximum()<<endl;
				cout<<" Press Any key To continue..."<<endl;
				fflush(stdin);
				cin.get();	// to hold the screen
				break;
			case 9:
				cout<<"\n Mean of List : "<<obj.mean()<<endl;
				cout<<" Press Any key To continue..."<<endl;
				fflush(stdin);
				cin.get();	// to hold the screen
				break;	
			
			case 10:
				cout<<"\n Sorted Linked List is : "<<endl;
				obj.sorting();
				cout<<" Press Any key To continue..."<<endl;
				fflush(stdin);
				cin.get();	// to hold the screen
				break;
				
			case 11:
				cout<<"\n Reversed Linked List is : "<<endl;
				obj.reverse();
				obj.display();
				cout<<" Press Any key To continue..."<<endl;
				fflush(stdin);
				cin.get();	// to hold the screen
				break;	
						
		}
	
	}
}
