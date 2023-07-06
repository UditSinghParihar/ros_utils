/*
Longest increasing subsequence

10, 22, 9, 33, 21, 50, 41, 60, 80


10 - 1
10, 22 - 

3 10 2 11

3 - 1
3 10 - 2
3 10 2 - 2
3 10 2 11 - 3
3 10 2 11 5 - 3
3 10 2 11 5 7 - 4


3 10 2 8

3 10 2 - 2
3 10 2 8 - 2



lis_end(arr, i) = 1 + lis_end(arr, j) ; j < i && a[j] < a[i]


lis(v, lengths, n){
	
}


main(){
	vector<int> v{10, 22, 9, 33, 21, 50, 41, 60, 80};
	vector<int> lengths(v.size(), 1); // {val, length of longest subsequence ending at i}
	
	lis(v, lengths, v.size());

	return *max_element(v.begin(), v.end());
}




*/