
#include "Solution.h"
using namespace std;
/*给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" */
string Solution :: minWindow(string s, string t)
{
    int n = s.size();
    int m = t.size();
    if (n < m) return "";
    int totalLetters = 58;
    int r = m;
    bool flag = false;
    int minStrLen = n+1;
    unordered_map<int, int> record;

    int sLetters[58] = { 0 };
    int tLetters[58] = { 0 };
    for (int i = 0; i < m; ++i) {
        ++tLetters[t[i] - 'A'];
        ++sLetters[s[i] - 'A'];
    }
    for (int l = 0; l < r; ++l) {
        for (int i = 0; i < totalLetters; ++i) {
            if (sLetters[i] < tLetters[i]) {
                flag = true;
                break;
            }
            if (i == totalLetters - 1) {
                if (minStrLen > r - l) {
                    minStrLen = r - l;
                    record[r - l] = l;
                }
                flag = false;
            }
        }
        while (flag && r < n) {
            ++sLetters[s[r++] - 'A'];
            for (int i = 0; i < totalLetters; ++i) {
                if (sLetters[i] < tLetters[i]) {
                    break;
                }
                if (i == totalLetters - 1) {
                    if (minStrLen > r - l) {
                        minStrLen = r - l;
                        record[r-l] = l;
                    }
                    flag = false;
                }
            }
        }
        if (flag && r >= n) {
            if (record.empty()) {
                return "";
            }
            else {
                break;
            }
        }
        --sLetters[s[l] - 'A'];
    }
    return s.substr(record[minStrLen], minStrLen);
}

/*给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和;
  子数组是数组中的一个连续部分*/
int Solution::maxSubArray(vector<int>& nums)
{
    int len = nums.size();
    vector<int> record(len);
    int max = INT32_MIN;
    for (int i = 0; i < len; ++i) {
        if (i == 0) {
            record[i] = nums[i];
        }
        else {
            record[i] = nums[i] > (record[i - 1] + nums[i]) ? nums[i] : (record[i - 1] + nums[i]);
        }
        max = max > record[i] ? max : record[i];
    }
    return max;
}

/*以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。
请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。*/
vector<vector<int>> Solution::merge(vector<vector<int>>& intervals) 
{
    if (intervals.size() <= 1) return intervals;
    vector<vector<int>> res;
    sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
        if (a.front() == b.front())
            return a.back() < b.back();
        return a.front() < b.front();
        });
    int lMark = intervals[0].front();
    int rMark = intervals[0].back();
    vector<vector<int>> mem = intervals;
    for (int i = 0; i < intervals.size(); ++i) {
        if (i > 0) {
            if ((lMark <= mem[i].front()) && ((rMark >= mem[i].back()))) {
                
            }
            else if ((rMark <= mem[i].back()) && ((rMark >= mem[i].front()))) {
                rMark = mem[i].back();
            }
            else {
                vector<int> temp = { lMark, rMark };
                res.emplace_back(temp);
                lMark = mem[i].front();
                rMark = mem[i].back();
            }
            if (i == mem.size() - 1) {
                vector<int> temp = { lMark, rMark };
                res.emplace_back(temp);
            }
        }
    }
    return res;
}

/*给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。(向右循环移位)*/
void Solution :: rotate(vector<int>& nums, int k) {
    int len = nums.size();
    int n = k % len;
    vector<int> rd(len);
    for (int i = 0; i < len; ++i) {
        rd[(i + n) % len] = nums[i];
        int j = 0;
    }
    nums = rd;
}

/*给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积 。*/
vector<int> Solution :: productExceptSelf(vector<int>& nums) {

}