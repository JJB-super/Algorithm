#pragma once
#include <iostream>
#include <string>
#include<unordered_map>
#include <vector>
#include<algorithm>
using namespace std;
class Solution
{
public:
	string minWindow(string s, string t);
	int maxSubArray(vector<int>& nums);
	vector<vector<int>> merge(vector<vector<int>>& intervals);
	void rotate(vector<int>& nums, int k);
	vector<int> productExceptSelf(vector<int>& nums);
	int firstMissingPositive(vector<int>& nums);
};

