#include <bits/stdc++.h>

using namespace std;


class Solution{
public:
	void print(const vector<vector<char>> &grid){
		int cols = grid[0].size();
		int rows = grid.size();

		fprintf(stderr, "%d %d\n", rows, cols);

		for(int i=0; i<rows; ++i){
			for(int j=0; j<cols; ++j){
				fprintf(stderr, "%c ", grid[i][j]);
			}
			fprintf(stderr, "\n");
		}
	}

	void dfs(vector<vector<char>> &grid, int i, int j){
		int cols = grid[0].size();
		int rows = grid.size();

		if(i<0 || j<0 || i>=rows || j>=cols)
			return ;

		if(grid[i][j] == '0')
			return ;
		
		
		grid[i][j] = '0';

		dfs(grid, i, j+1);
		dfs(grid, i, j-1);
		dfs(grid, i+1, j);
		dfs(grid, i-1, j);

		return ;

	}

	int numIslands(vector<vector<char>>& grid) {
        int cols = grid[0].size();
        int rows = grid.size();
        int counter = 0;

        print(grid);

        for(int i=0; i<rows; ++i){
            for(int j=0; j<cols; ++j){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    counter += 1;
                }
            }
        }

        print(grid);

        return counter;
    }

};


int main(int argv, char** argc){
	vector<vector<char>> v(4);

	v[0] = vector<char>{'1', '1', '0', '0'};
	v[1] = vector<char>{'1', '0', '0', '1'};
	v[2] = vector<char>{'1', '1', '0', '1'};
	v[3] = vector<char>{'1', '0', '1', '0'};

	Solution obj;

	// obj.print(v);


	int answer = obj.numIslands(v);
	fprintf(stderr, "Answer: %d\n", answer);

	return 0;
}