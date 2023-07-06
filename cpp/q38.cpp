#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int nearZero(vector<vector<int>> &mat, int i, int j, map<pair<int, int>, int> &visit){
        int rows = mat.size(), cols = mat[0].size();

        if(i<0 || j<0 || i>=rows || j>=cols){
            return 10000;
        }

        auto itr = visit.find({i, j});
        if(itr != visit.end()){
            return visit[{i, j}];
        }     
        else{
            if(mat[i][j] == 0){
                visit.insert({{i, j}, 0});
                return 0; 
            }
            int val = 1 + min({nearZero(mat, i+1, j, visit),
                                nearZero(mat, i, j+1, visit),
                                nearZero(mat, i-1, j, visit),
                                nearZero(mat, i, j-1, visit)});
            
            visit.insert({{i, j}, val});
            return val;
            
        }
        
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();
        vector<vector<int>> ans(rows, vector<int>(cols));

        map<pair<int, int>, int> visit;
        for(int i=0; i<rows; ++i){
            for(int j=0; j<cols; ++j){
                int val = nearZero(mat, i, j, visit);

                ans[i][j] = val;
            }
        }

        if(visit.find({2,1}) != visit.end())
        	printf("Value of %d\n", visit[{2,1}]);
        
        return ans;
    }
};


int main(int argc, char const *argv[]){
	vector<vector<int>> mat{{0,0,0},
							{0,1,0},
							{1,1,1}};

	Solution sol;
	auto ans = sol.updateMatrix(mat);

	for(auto r:ans){
		for(auto c:r){
			printf("%d ", c);
		}
		cout << endl;
	}



	
	return 0;
}