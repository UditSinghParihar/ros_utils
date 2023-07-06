/*

1 2 3 4 5

1 + 2 = 3
3 + 3 = 6 
4 + 5 = 9
6 + 9 = 15

3 + 6 + 9 + 15

1 2 -> 3

3, 3, 4, 5

3 3 -> 6

4 5 6 

4 5 -> 9

6 9
6 9 -> 15

*/


#include <bits/stdc++.h>

using namespace std;


int main(int argc, char const *argv[]){
	// priority queue in smaller element on the top of the queue
	priority_queue<int, vector<int>, greater<int>> pq;

	vector<int> v{1, 2, 3};

	for(int i=0; i<v.size(); ++i)
		pq.push(v[i]);

	
	int sum = 0;
	while(pq.size() > 1){
		int x = pq.top();
		pq.pop();
		int y = pq.top();
		pq.pop();

		sum += x+y;

		pq.push(x+y);
	}


	printf("min sum %d\n", sum);

	return 0;
}