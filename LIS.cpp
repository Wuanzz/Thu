/*
    Input: Dòng đầu tiên là N, dòng 2 gồm N phần tử mảng A (không trùng nhau)
    Ouput: In ra độ dài dãy con tăng dần dài nhất
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solveProblem(const int &n, const vector<int> &vecArr)
{
    int iMaxLen = 1; // Độ dài dãy nhỏ nhất thỏa đk là 1
    vector<int> vecLength(n, 1); 
    /*
        vecLength[i]: Độ dài của dãy con tăng dần, kết thúc ở chỉ số i
        vecLength[i] = max(vecLength[i], vecLength[j] + 1)
    */
    for (int i = 1 ; i < n ; i++)
    {
        for (int j = 0 ; j < i ; j++)
        {
            if (vecArr[i] > vecArr[j])
            {
                vecLength[i] = max(vecLength[i], vecLength[j] + 1);
                iMaxLen = max(iMaxLen, vecLength[i]);
            }
        }
    }
    return iMaxLen;
}   

int main()
{
    int n;
    vector<int> vecArr;
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        int x;
        cin >> x;
        vecArr.push_back(x);
    }
    cout << solveProblem(n, vecArr) << endl;
    return 0;
}