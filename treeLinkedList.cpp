//implemetation of a search tree as a doubly linked list in C++
#include <iostream>
#include <list>
#include <queue>

using namespace std;

struct Node{
	int data;
	Node* parent;
	Node* left;
	Node* right;
};

Node* newNode(int data){
	Node* newN = new Node;
	newN->data = data;
	newN->left=NULL;
	newN->right=NULL;
	newN->parent=NULL;
	return newN;
}

void add(int data, Node* root){
	Node* parent =root;
	while (true){
		if (data>parent->data){
			if (parent->right!=NULL)
				parent = parent->right;
			else
				break;
		}
		else if (data < parent->data){
			if (parent->left!=NULL)
				parent = parent->left;
			else
				break;
		}
		else{
			cout<<"node with value " <<data<< " already exists"<<'\n';
			return;
		}
	}
	Node* newN=newNode(data); 
	
	newN->parent=parent;
	if (data > parent->data){
		parent->right=newN;
	}
	else{
		parent->left=newN;
	}
}

void remove(int data, Node* root){
	Node* toDelete = root;
	while (true){
		if (toDelete->data < data){
			if (toDelete->right!=NULL)
				toDelete = toDelete->right;
			else{
			cout<<"node "<<data<<" is not in the tree"<<'\n';return;}
		}
		else if (toDelete->data > data){
			if (toDelete->left!=NULL)
				toDelete = toDelete->left;
			else{
			cout<<"node "<<data<<" is not in the tree"<<'\n';return;}
		}
		else if (toDelete->data==data){
			break;
		}
	}
	
	Node* help;
	
	//case 1: the to-be-deleted element is a leaf
	if (toDelete->left==NULL && toDelete->right==NULL){
		help=toDelete->parent;
		if ((help->left)->data==data){
			help->left=NULL;
		}
		else{
			help->right=NULL;
		}
		cout<<"deleting node "<<data<<'\n';
		delete toDelete;
		return;	
	}
	//case 2: to be deleted node has one child
	if (toDelete->left==NULL ^ toDelete->right==NULL){
		if (toDelete->left==NULL){
			help=toDelete->parent;
			(toDelete->right)->parent=help;
			if ((help->left)->data==data){
				(toDelete->parent)->left=toDelete->right;
			}
			else {
				(toDelete->parent)->right=toDelete->right;
			}
		}
		if (toDelete->right==NULL){
			help=toDelete->parent;
			(toDelete->left)->parent=help;
			if ((help->left)->data==data){
				(toDelete->parent)->left=toDelete->left;
			}
			else {
				(toDelete->parent)->right=toDelete->left;
			}
		}
		cout<<"deleting node "<<data<<'\n';
		delete toDelete;
		return;	
	}

}


void prettyPrint(Node* node){ 
	queue <Node*> q;
	q.push(node);
	while (q.size()){
		Node* n = q.front();
		q.pop();
		cout<<n->data<<" ";
		if (n->left!=NULL){
			q.push(n->left);
		}	
		if (n->right!=NULL){
			q.push(n->right);
		}
	}
	cout<<"\n";
}
   	

int main(){
	Node* root=newNode(5);
	add(3,root);
	add(6,root);
	add(2,root);
	add(8,root);
	add(4,root);
	add(7,root);
	add(2,root);
	prettyPrint(root);
	remove(2,root);
	prettyPrint(root);
	remove(3,root);
	prettyPrint(root);
}