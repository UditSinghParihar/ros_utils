/*
			
			0-1-4-6-7
		   / /    \
		  2-3-5    8-9-10


0
1

*/


#include <bits/stdc++.h>

using namespace std;


void dfs(vector<vector<int>> &adj, unordered_set<int> &visited, int node){
	auto itr = visited.find(node);

	// Already found
	if(itr != visited.end()){
		;
	}
	// First time visiting
	else if(itr == visited.end()){
		visited.insert(node);
		printf("visited: %d\n", node);

		for(auto neighbour : adj[node]){
			dfs(adj, visited, neighbour);
		}
	}

}


int main(int argc, char *argv[]){
	int Nodes = 11;
	vector<vector<int>> adjacency_matrix(Nodes);
	adjacency_matrix[0] = {1, 2};
	adjacency_matrix[1] = {0, 3, 4};
	adjacency_matrix[2] = {0, 3};
	adjacency_matrix[3] = {1, 2, 5};
	adjacency_matrix[4] = {1, 6};
	adjacency_matrix[5] = {3};
	adjacency_matrix[6] = {4, 7, 8};
	adjacency_matrix[7] = {6};
	adjacency_matrix[8] = {6, 9};
	adjacency_matrix[9] = {8, 10};
	adjacency_matrix[10] = {10};


	for(int i=0; i<adjacency_matrix.size(); ++i){
		printf("%d: ", i);
		for(auto c:adjacency_matrix[i]){
			printf("%d ", c);
		}
		cout << endl;
	}

	unordered_set<int> visited;
	dfs(adjacency_matrix, visited, 0);

	return 0;

}