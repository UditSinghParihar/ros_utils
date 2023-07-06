#include<bits/stdc++.h>

using namespace std;


/*
1, 2, 1, 3, 4, 3



*/

vector<int> dNums(vector<int> &A, int B) {
    int size = A.size();
    if(B > size){
        return vector<int> ();
    }
    
    vector<int> ans;
    unordered_map<int, int> counts;
    
    for(int j=0; j<B; ++j){
        counts[A[j]] += 1;
    }
    ans.push_back(counts.size());
    
    for(int i=1; i<size-B+1; ++i){
        int st = i;
        
        counts[A[i-1]] -= 1;
        if(counts[A[i-1]] == 0){
        	counts.erase(A[i-1]);
        }

        counts[A[st+B-1]] += 1; 
        
       
        ans.push_back(counts.size());
    }
    
    return ans;
}


int main(int argc, char const *argv[]){
	vector<int> v{1, 2, 1, 3, 4, 3};
	int B = 3;

    unordered_set<int> visited;


    for(auto itr=v.begin(); itr!=v.end(); ++itr){
        // printf("%d\n", *itr);
        visited.insert(*itr);
    }

    visited.erase(visited.find(3));

    for(auto itr=visited.begin(); itr!=visited.end(); ++itr){
        printf("%d\n", *itr);
        // visited.insert(*itr)
    }

	// auto ans = dNums(v, B);

	// for(auto e : ans){
	// 	printf("%d ", e);
	// }
	// cout << endl;


	return 0;
}