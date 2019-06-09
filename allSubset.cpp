

#include <bits/stdc++.h> 
using namespace std; 
 
vector<string> split(const string &s, char delim) 
{ 
	vector<string> elems; 
	stringstream ss(s); 
	string item; 
	while (getline(ss, item, delim)) 
		elems.push_back(item); 

	return elems; 
} 


int printPowerSet(int arr[], int n) 
{ 
	vector<string> list; 

	/* Run counter i from 000..0 to 111..1*/
	for (int i = 0; i < (int) pow(2, n); i++) 
	{ 
		string subset = ""; 

		// consider each element in the set 
		for (int j = 0; j < n; j++) 
		{ 
			// Check if jth bit in the i is set. If the bit 
			// is set, we consider jth element from set 
			if ((i & (1 << j)) != 0) 
				subset += to_string(arr[j]) + "|"; 
		} 

		// if subset is encountered for the first time 
		// If we use set<string>, we can directly insert 
		if (find(list.begin(), list.end(), subset) == list.end()) 
			list.push_back(subset); 
	} 

	// consider every subset 
	for (string subset : list) 
	{ 
		// split the subset and print its elements 
		vector<string> arr = split(subset, '|'); 
		for (string str: arr) 
			cout << str << " "; 
		cout << endl; 
	} 
} 

// Driver code 
int main() 
{ 
	int arr[] = { 1,2,3,5,6,7,8,9,10,11,12,13,14,15,16,17,18 }; 
	int n = sizeof(arr)/sizeof(arr[0]); 

	printPowerSet(arr, n); 

	// return 0; 
} 
