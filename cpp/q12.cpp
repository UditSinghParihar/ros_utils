#include <bits/stdc++.h>

using namespace std;


int solution(const vector<int> &A){
	unordered_set<int> st;
    
    for(auto e : A){
        // auto it = find(st.begin(), st.end(), e);
        if(st.find(e) != st.end()){
            return *it;
        }
        
        st.insert(e);
    }
    
    return -1;
}

int main(int argc, char const *argv[]){
	std::vector<int> v{3, 4, 1, 4, 2};	

	int ans = solution(v);
	fprintf(stderr, "ans %d\n", ans);


	return 0;
}