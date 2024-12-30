
#include "Solution.h"
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

/*给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积 (禁止使用 除法 /)。*/
vector<int> Solution::productExceptSelf(vector<int>& nums) {
    int len = nums.size();
    vector<int> left(len);
    vector<int> right(len);
    vector<int> ans(len);
    for (int i = 0; i < len; ++i) {
        if (i == 0) {
            left[i] = 1;
            right[len - 1 - i] = 1;
        }
        else {
            left[i] = left[i - 1] * nums[i - 1];
            right[len - 1 - i] = right[len - i] * nums[len - i];
        }
    }
    for (int i = 0; i < len; ++i) {
        ans[i] = left[i] * right[i];
    }
    return ans;
}

/*给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。
请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。*/
int Solution::firstMissingPositive(vector<int>& nums) {
    int len = nums.size();
    for (int i = 0; i < len; ++i) {
        if (nums[i] <= 0) {
            nums[i] = (len + 1);
        }
    }
    int y = 1;
    int j = -y;
    for (int i = 0; i < len; ++i) {
        int local = abs(nums[i]);
        if (local <= len) {
            nums[local - 1] = -abs(nums[local - 1]);
        }
    }
    for (int i = 0; i < len; ++i) {
        if (nums[i] > 0) {
            return (i + 1);
        }
    }
    return (len + 1);
}

/*给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 ,请使用原地算法*/
void Solution::setZeroes(vector<vector<int>>&matrix) {
    int r = matrix.size();
    int c = matrix[0].size();
    vector<bool> row(r);
    vector<bool> col(c);
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (matrix[i][j] == 0) {
                row[i] = true;
                col[j] = true;
            }
        }
    }
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (row[i] || col[j]) {
                matrix[i][j] = 0;
            }
        }
    }
}

/*给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素*/
vector<int> Solution::spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    int m = matrix.size();
    int n = matrix[0].size();
    if (matrix.empty() || m == 0 || n == 0)
        return ans;
    if (m == 1) {
        return matrix[0];
    }
    if (n == 1) {
        for (int i = 0; i < m; ++i) {
            ans.emplace_back(matrix[i][0]);
        }
        return ans;
    }
    int top = 0;
    int buttom = m - 1;
    int left = 0;
    int right = n - 1;
    int cnt = 0;
    while (cnt < m*n) {
        for (int c = left; c <= right; ++c) {
            ans.emplace_back(matrix[top][c]);
            cnt++;
        }
        if (cnt == m * n) break;
        for (int r = top + 1; r <= buttom; ++r) {
            ans.emplace_back(matrix[r][right]);
            cnt++;
        }
        if (cnt == m * n) break;
        for (int c = right - 1; c >= left; --c) {
            ans.emplace_back(matrix[buttom][c]);
            cnt++;
        }
        if (cnt == m * n) break;
        for (int r = buttom - 1; r >= top; --r) {
            if (r != top) {
                ans.emplace_back(matrix[r][left]);
                cnt++;
            }
            else {
                top++;
                left++;
                right--;
                buttom--;
            }
        }
        if (cnt == m * n) break;
    }
    return ans;
}