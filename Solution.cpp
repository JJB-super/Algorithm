
#include "Solution.h"
using namespace std;
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

/*����һ���������� nums������ ���� answer ������ answer[i] ���� nums �г� nums[i] ֮�������Ԫ�صĳ˻� ��*/
vector<int> Solution :: productExceptSelf(vector<int>& nums) {

}