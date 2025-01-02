#ifndef SOLUTION_H
#define SOLUTION_H
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
	void setZeroes(vector<vector<int>>& matrix);
	vector<int> spiralOrder(vector<vector<int>>& matrix);
	void rotate(vector<vector<int>>& matrix);
	bool searchMatrix(vector<vector<int>>& matrix, int target);
};
#endif
