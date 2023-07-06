/*
                 4
				/ 
       	  1 - 2 - 3 - 5
		/         | 
       0-8  ---   6-7


0 0
8 0
1 0
2 1
4 2
3 2
6 3
- 3, 8, 7

dfs(){
	unordered_map<int, int> visited;
	stack<int> st;
	st.push(source)
	visited.insert({source, source})

	while(st.empty()){
		int node = st.top()
		printf("Visit %d\n", node)
		st.pop()
		

		for(auto nbr:node){
			if(not visited){
				st.push(nbr)
				visited.insert(nbr, node)

			}
			
			if(nbr visited && nbr != nbr.parent){
				printf("cycle detected")
			}

		}

	}

}


cycle(){
	unordered_set<int> visited;



}


dfs(){
	0, 1, 2, 3, 5, 6, 7, 4, 8
}


dfs(){
	// stack for dfs

	stack<int> st;
	unordered_set<int> visited;

	st.push(start_node);

	while(!st.empty()){
		node = st.top()
		st.pop()

		for(auto nbh : adj[node]){
			st.push(nbh)
		}
	}
}



bfs(){
	// queue for bfs
	
	0
	1, 8
	2
	3, 4
	5, 6, 7

	queue<int> q;
	q.push(start_node)


	while(!q.empty()){
		node = q.front();
		q.pop();

		for(auto nbh : ajd[node]){
			q.push(nbh)
		}

	}

}

*/

// #include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
#include <stack>
#include <unordered_map>

using namespace std;


void bfs(int adj[][9], int V, int node){
	unordered_set<int> visited;

	queue<int> q;
	q.push(node);

	while(!q.empty()){
		int node = q.front();
		printf("Visited: %d\n", node);
		visited.insert(node);

		q.pop();

		for(int i=0; i<V; ++i){
			if(adj[node][i] == 1 && (visited.find(i) == visited.end())){
				q.push(i);
			}
		}
	}
}


void dfs_stack(int adj[][9], int V, int node){
	unordered_set<int> visited;

	stack<int> st;
	st.push(node);
	visited.insert(node);

	while(!st.empty()){
		int node = st.top();
		printf("Visited %d\n", node);

		st.pop();

		for(int i=0; i<V; ++i){
			if(adj[node][i] == 1 && (visited.find(i) == visited.end())){
				st.push(i);
				visited.insert(i);
			}
		}
	}

}

bool cycle(int adj[][9], int V){
	unordered_set<int> visited;
	unordered_map<int, int> parent;

	stack<int> st;
	st.push(0);
	parent[0] = 0;

	while(!st.empty()){
		int node = st.top();
		visited.insert(node);
		st.pop();

		for(int i=0; i<V; ++i){
			if(adj[node][i] == 1 && (visited.find(i) == visited.end())){
				st.push(i);
				parent[i] = node;
			}

			if(adj[node][i] == 1 && (visited.find(i) != visited.end()) && i!=parent[node] && i != node){
				printf("cycle found !! %d and %d\n", node, i);
				return true;
			}
		}
	}

	return false;
}


void dfs(int adj[][9], unordered_set<int> &visited, int V, int node){
	if(visited.find(node) != visited.end()){
		return ;
	}
	else{
		printf("Visited: %d\n", node);
		visited.insert(node);
		for(int i=0; i<V; ++i){
			if(adj[node][i] == 1){
				dfs(adj, visited, V, i);
			}
		}
	}
}

int main(int argc, char *argv[]){
	const int V = 9;
	

	//					0, 1, 2, 3, 4, 5, 6, 7, 8 
	int adj[V][V] = {{  1, 1, 0, 0, 0, 0, 0, 0, 1},
					{  	1, 1, 1, 0, 0, 0, 0, 0, 0},
					{	0, 1, 1, 1, 1, 0, 0, 0, 0},
					{	0, 0, 1, 1, 0, 1, 1, 0, 0},
					{	0, 0, 1, 0, 1, 0, 0, 0, 0},
					{	0, 0, 0, 1, 0, 1, 0, 0, 0},
					{	0, 0, 0, 1, 0, 0, 1, 1, 1},
					{	0, 0, 0, 0, 0, 0, 1, 1, 0},
					{	1, 0, 0, 0, 0, 0, 0, 0, 1}};


	unordered_set<int> visited;

	printf("\nDFS---\n");
	dfs(adj, visited, V, 0);

	printf("\nBFS---\n");
	bfs(adj, V, 0);

	printf("\nDFS STACK---\n");
	dfs_stack(adj, V, 0);

	printf("\nCycle---\n");
	cycle(adj, V);

	return 0;
}