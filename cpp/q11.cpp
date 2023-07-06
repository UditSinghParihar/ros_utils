/*
Given a non-negative number represented as an array of digits, add 1 to the number ( increment the number represented by the digits ).

The digits are stored such that the most significant digit is at the head of the list.

Problem Constraints
1 <= |A| <= 106
0 <= Ai <= 9
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> Solution::plusOne(vector<int> &A) {
    int n = A.size();
    int carry = 1;
    for(int i = n-1; i >= 0; i--){
        int sum = A[i] + carry;
        A[i] = sum % 10;
        carry = sum / 10;
    }
    if(carry){
        A.insert(A.begin(), carry);
    }
    while(A[0] == 0){
        A.erase(A.begin());
    }
    return A;
};
