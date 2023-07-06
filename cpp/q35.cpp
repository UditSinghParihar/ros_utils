/*
						11

				  2           13

			   1    9             57

				 3            25      90


*/


#include <bits/stdc++.h>

using namespace std;



struct Node{
	int data;
	struct Node *left;
	struct Node *right;

	Node(int value){
		this->data = value;
		this->left = nullptr;
		this->right = nullptr;
	}
};


void insert(int val, Node *root){
	Node *itr = root;
	Node *parent = nullptr;

	while(itr != nullptr){
		parent = itr;
		
		if(itr->data > val){
			itr = itr->left;
		}
		else{
			itr = itr->right;
		}
	}

	if(val > parent->data){
		parent->right = new Node(val);
	}
	else{
		parent->left = new Node(val);
	}
}


void traverse(Node *itr){
	// Inorder traversal
	if(itr == nullptr){
		return;
	}

	Node *leftChild = itr->left;
	Node *rightChild = itr->right;

	traverse(leftChild);
	printf("%d\n", itr->data);
	traverse(rightChild);	

}

void level_order(Node *A){
	queue<Node*> q;
	unordered_map<Node*, int> dist;

	q.push(A);
	dist[A] = 0;
	 
	while(!q.empty()){
		Node *node = q.front();
		  
		printf("Visited %d\n", node->data);
		q.pop();
		  
		Node *left = node->left;
		Node *right = node->right;

		dist[left] = dist[node]+1;
		dist[right] = dist[node]+1;

		if(left != nullptr){
			q.push(left);
		}

		if(right != nullptr){
			q.push(right);
		}		  
		  
	}

	// for(auto itr=dist.begin(); itr!=dist.end(); ++itr){
	// 	printf("%d at level: %d\n", itr->first->data, itr->second);
	// }

}

void heightTree(Node *A, int lvl, int &h){
    if(A != nullptr){
        h = max(h, lvl);
        
        heightTree(A->left, lvl+1, h);
        printf("Val: %d\n", A->data);
        heightTree(A->right, lvl+1, h);
    }    
}


int main(int argc, char *argv[]){
	vector<int> v{11, 2, 9, 13, 57, 25, 1, 90, 3};	

	Node *head = new Node(v[0]);


	for(int i=1; i<v.size(); ++i){
		insert(v[i], head);
	}

	// traverse(head);

	int h=0;
	heightTree(head, 0, h);


	// level_order(head);

	return 0;
}