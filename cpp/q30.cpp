/*
5 -> 3 -> 1 -> 10 -> 2

prev = 5
cur = 3
next = 1

5 <- 3 <- 1 <- 10 <- 2 


// reverse
cur->next = prev




*/



#include <bits/stdc++.h>

using namespace std;


struct Node{
public: 
	int data;
	Node *next;

public:
	Node(int data){
		this->data = data;
		this->next = nullptr;
	}
};


int main(int argc, const char *argv[]){
	vector<int> v{5, 3, 1, 10, 2};

	Node *head = new Node(v[0]);
	Node *itr = head;

	for(int i=1; i<v.size(); ++i){
		itr->next = new Node(v[i]);
		itr = itr->next;
	}


	itr = head;
	while(itr != nullptr){
		printf("Data: %d\n", itr->data);
		itr = itr->next;
	}


	Node *cur = head->next;
	Node *prev = head;
	prev->next = nullptr;

	while(cur != nullptr){
		Node *next = cur->next;

		// Reversing direction
		cur->next = prev;

		// Moving next step
		prev = cur;
		cur = next;
	}


	head = prev;

	itr = head;
	printf("\n---\n");
	while(itr != nullptr){
		printf("Data: %d\n", itr->data);
		itr = itr->next;
	}


	return 0;
}