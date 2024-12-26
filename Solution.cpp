
#include "Solution.h"
/*����һ���ַ��� s ��һ���ַ��� t ������ s �к��� t �����ַ�����С�Ӵ������ s �в����ں��� t �����ַ����Ӵ����򷵻ؿ��ַ��� "" */
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

/*����һ���������� nums �������ҳ�һ���������͵����������飨���������ٰ���һ��Ԫ�أ�������������;
  �������������е�һ����������*/
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

/*������ intervals ��ʾ���ɸ�����ļ��ϣ����е�������Ϊ intervals[i] = [starti, endi] ��
����ϲ������ص������䣬������ һ�����ص����������飬��������ǡ�ø��������е��������� ��*/
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

/*����һ���������� nums���������е�Ԫ��������ת k ��λ�ã����� k �ǷǸ�����(����ѭ����λ)*/
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

/*����һ���������� nums������ ���� answer ������ answer[i] ���� nums �г� nums[i] ֮�������Ԫ�صĳ˻� (��ֹʹ�� ���� /)��*/
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

/*����һ��δ������������� nums �������ҳ�����û�г��ֵ���С����������
����ʵ��ʱ�临�Ӷ�Ϊ O(n) ����ֻʹ�ó����������ռ�Ľ��������*/
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

/*����һ�� m x n �ľ������һ��Ԫ��Ϊ 0 �����������к��е�����Ԫ�ض���Ϊ 0 ,��ʹ��ԭ���㷨*/
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

/*����һ�� m �� n �еľ��� matrix ���밴�� ˳ʱ������˳�� �����ؾ����е�����Ԫ��*/
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