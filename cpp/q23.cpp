#include <bits/stdc++.h>

using namespace std;



int strStr(const string A, const string B) {
    if(A.length() == 0 || B.length()  == 0){
        return -1;
    }
    
    for(int idx=0; idx<A.size(); ++idx){
        if(A[idx] != B[0]){
            continue ;
        }    
    
        bool matched = false;
        int end = 0;
        for(int i=idx, j=0; i<A.size() && j<B.size(); ++i, ++j){
            if(A[i] == B[j]){
                matched = true;
                end = i;
            }
            else{
                matched = false;
                break;
            }
        }
        
        if(matched && end-idx+1 == B.length()){
            return idx;
        }
    }
    
    return -1;
}


int main(int argc, char const *argv[]){
    const string str1("bbaabbbbbaabbaabbbbbbabbbabaabbbabbabbbbababbbabbabaaababbbaabaaaba");
    const string str2("babaaa");

    fprintf(stderr, "Answer %d\n", strStr(str1, str2));

    return 0;
}