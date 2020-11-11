// C++ code to print all anagrams together 
#include <bits/stdc++.h>
using namespace std;

void solver(vector<string> my_list)
{
	
	// Inner hashmap counts frequency
	// of characters in a string.
	// Outer hashmap for if same
	// frequency characters are present in
	// in a string then it will add it to
	// the vector.
	map<map<char, int>, vector<string>> my_map;
	
	// Loop over all words
	for(string str : my_list)
	{
		
		// Counting the frequency of the
		// characters present in a string
		map<char, int> temp_map;
		vector<string> temp_my_list;
		for(int i = 0; i < str.length(); ++i) 
		{
			++temp_map[str[i]];
		}
		
		// If the same frequency of chanracters
		// are alraedy present then add that
		// string into that arraylist otherwise
		// created a new arraylist and add that
		// string
		auto it = my_map.find(temp_map);
		if (it != my_map.end())
		{
			it->second.push_back(str);
		}
		else
		{
			temp_my_list.push_back(str);
			my_map.insert({ temp_map, temp_my_list });
		}
	}
	
	// Stores the result in a vector
	vector<vector<string>> result;

	for(auto it = my_map.begin();
			it != my_map.end(); ++it)
	{
		result.push_back(it->second);
	}

	for(int i = 0; i < result.size(); ++i) 
	{
		cout << "[";
		for(int j = 0; j < result[i].size(); ++j) 
		{
			cout << result[i][j] << ", ";
		}
		cout << "]";
	}
}

// Driver code
int main()
{
	vector<string> my_list = { "cat", "dog", "ogd",
							"god", "atc" };
	solver(my_list);
	return 0;
}

// This code is contributed by 
// Apurba Kumar Gorai(coolapurba05)
