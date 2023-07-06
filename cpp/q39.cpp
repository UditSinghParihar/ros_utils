/*
l,b 


1 x 2 -> 3
1 x 3 -> 2
2 x 3 -> 1


7 x 8 -> 9
7 x 9 -> 8
8 x 9 -> 7


435 x 345 -> 567
435 x 567 -> 345
345 x 567 -> 435

3 x Number of boxes


map<pair<int, int>, int> mp;


2,3   	->    10,12
    4,5 -> 8,9




*/

#include <bits/stdc++.h>

using namespace std;


struct Box{
	int l;
	int b;
	int h;

	Box(int l, int b, int h){
		this->l = l;
		this->b = b;
		this->h = h;
	}
};


int maxHeight(vector<Box> &boxes, unordered_map<int, int> &mp){
	for(int i=0; i<boxes.size(); ++i){

	}
}


int main(int argc, char *argv[]){
	Box b1(9, 8, 7);
	Box b2(1, 2, 3);
	Box b3(435, 345, 567);

	vector<Box> boxes(b1, b2, b3);

	unordered_map<int, int> mp;
	int ans = maxHeight(boxes);




	return 0;
}