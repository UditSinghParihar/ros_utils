/*
struct Ele{
public:
	int data;
	Ele *next;
	
	Ele(int data){
		this->data = data;
		this->next = nullptr;
	}


}


ptr->next = new Ele(5);

2 -> 4 -> 5 -> 1 -> 12

*/

#include <bits/stdc++.h>

using namespace std;


struct Node{
public:
	float data;
	Node *next;
	
public:
	Node(float val){
		this->data = val;
		this->next = nullptr;
	}


};


int main(int argc, char* argv[]){
	vector<float> v(5);
	v = {2, 4, 5, 1, 12};
	Node *head = new Node(v[0]);
	Node *itr = head;

	for(int i=1; i<v.size(); ++i){
		itr->next  = new Node(v[i]);
		itr = itr->next;
	}


	itr = head;
	while(itr != nullptr){
		printf("%f ", itr->data);
		itr = itr->next;
	}

	cout << "\n---Reversed---\n";


	Node *next = nullptr;
	Node *prev = nullptr;
	Node *cur = head;

	while(cur != nullptr){
		next = cur->next;		
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	head = prev;


	itr = head;
	while(itr != nullptr){
		printf("%f ", itr->data);
		itr = itr->next;
	}
	cout << endl;

	return 0;
}