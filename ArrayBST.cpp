#include<iostream>
using namespace std;
#include "ArrayBST.h"
ArrayBST::ArrayBST(){
	for(int i=0;i<MAX_SIZE;i++){
		this->element[i]=0;
	}	
}
ArrayBST::~ArrayBST(){}
void ArrayBST::add(int data){
	if(this->element[1]==0){
		element[1]=data;
	}
	else{
		for(int i=1;i<MAX_SIZE;){
			if(data<this->element[i]){
				i=2*i;
				cout<<"Left side :\t"<<i<<endl;
			}
			else{
				i=2*i+1;
				cout<<"Right side :\t"<<i<<endl;
			}
			if(this->element[i]==0){
				this->element[i]=data;
				cout<<"Inserted on "<<i<<endl;
				break;
			}
		}
	}
}
int ArrayBST::search(int data){
	for(int i=1;i<MAX_SIZE;){
		if(this->element[i]==data){
			cout<<"Required number "<<data<<" is found in index "<<i<<" of the tree\n";
			return i;
		}
		else if (data<this->element[i]){
				i=2*i;
			}
		else{
				i=2*i+1;
			}
	}
	cout<<"Required number "<<data<<"  is not found in the tree\n";
	return 0;
}
void ArrayBST::preorder(){
	int i=1;
	int j=0;						
	int k=0;						
	int l=0;						
	while(i<MAX_SIZE && i>0){
		if(j!=1){
			cout<<this->element[i]<<" ";
			k=0;
			l=0;
		}
		if(2*i<MAX_SIZE && this->element[2*i]!=0 && k!=1){
			i=2*i;
			j=0;
			l=0;
		}
		else if (2*i+1<MAX_SIZE && this->element[2*i+1]!=0 && l!=1){
			i=2*i+1;
			j=0;
			k=0;
		}
		else{
			if(i%2!=0){					
				l=1;
			}
			else{
				l=0;
			}
			i=int(i/2);
			j=1;
			k=1;
		}	
		}	
	}
int ArrayBST:: min(int i){
		while(i<MAX_SIZE){
			if(this->element[2*i]!=0 && 2*i<MAX_SIZE){
				i=2*i;
			}
			else{
				break;
			}
		}
		return this->element[i];
}
int ArrayBST:: max(int i){
		while(i<MAX_SIZE){
			if(this->element[2*i+1]!=0 && 2*i+1<MAX_SIZE){
				i=2*i+1;
			}
			else{
				break;
			}
		}
		return this->element[i];
}
int ArrayBST::left_child(int i){
	if(this->element[2*i]!=0 && 2*i<MAX_SIZE)
		return 2*i;
	else
		return 0;
}
int ArrayBST::right_child(int i){
	if(this->element[2*i+1]!=0 && (2*i+1)<MAX_SIZE)
		return 2*i+1;
	else
		return 0;
}

void ArrayBST::inorder(int i){				
	if(this->element[i]!=0 && i>0){
		inorder(left_child(i));
		cout<<this->element[i]<<" ";
		inorder(right_child(i));
	}

}

void ArrayBST::delete_node(int data){	
	int index=search(data);
	if(index!=0){							
		if(left_child(index)==0 && right_child(index)==0){			
			this->element[index]=0;
		}
		else if(left_child(index)!=0 && right_child(index)!=0){  
			while(right_child(index)!=0){
				int j=right_child(index);	
				int value=min(j);			 
				int index1=search(value);
				this->element[index]=value;		
				index=index1;
				if(right_child(index)==0){
					this->element[index]=0;					
				}
			}
		}
		else if(left_child(index)!=0){			
			while(left_child(index)!=0){
				int j=left_child(index);
				int value=max(j);
				int index1=search(value);
				this->element[index]=value;
				index=index1;
				if(left_child(index)==0){
					this->element[index]=0;			
				}
			}
		}
		else{								
			while(right_child(index)!=0){
				int j=right_child(index);
				int value=min(j);
				int index1=search(value);
				this->element[index]=value;
				index=index1;
				if(right_child(index)==0){
					this->element[index]=0;			
				}
			}
		}
	 }
}

int main(){
	ArrayBST a;
	a.add(19);
	a.add(9);
	a.add(25);
	a.add(7);
	a.add(36);
	a.add(13);
	a.add(21);
	a.add(28);
	a.add(3);
	a.add(8);
	cout<<endl;
	for(int i=0;i<MAX_SIZE;i++){
		cout<<a.element[i]<<",";
	}
	cout<<endl;
	cout<<"The required preorder traversal is ";
	a.preorder();
	cout<<endl;
	a.search(25);
	a.search(58);
	cout<<"The minimum value in the BST is "<<a.min()<<endl;
	cout<<"The maximum value in the BST is "<<a.max()<<endl;
	cout<<endl;
	cout<<"The required inorder traversal is ";
	a.inorder();
	cout<<endl;
	a.delete_node(7);
	cout<<endl;
	for(int i=0;i<MAX_SIZE;i++){
		cout<<a.element[i]<<",";
	}
	cout<<endl;
	a.inorder();
	cout<<endl;
	a.delete_node(9);
	cout<<endl;
	for(int i=0;i<MAX_SIZE;i++){
		cout<<a.element[i]<<",";
	}
	cout<<endl;
	a.inorder();
	cout<<endl;
	a.delete_node(25);
	cout<<endl;
	for(int i=0;i<MAX_SIZE;i++){
		cout<<a.element[i]<<",";
	}
	cout<<endl;
	a.inorder();
	cout<<endl;
	a.delete_node(7);
	cout<<endl;
	return 0;
}



