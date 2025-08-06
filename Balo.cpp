/*
    Input: Dòng đầu ghi 2 số N và W. N Dòng tiếp theo ghi lần lượt w và v
    Ouput: Dòng 1 ghi giá trị lớn nhất, dòng 2 là '1' or '0' thể hiện các vật được chọn
    Trong đó: w là khối lượng đồ vật, v là giá trị đồ vật
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solveProblem(const int &iN, const int &iW, const vector<int> &vecW, const vector<int> &vecV, vector<vector<int>> &vecDP)
{
    for (int i = 1 ; i <= iN ; i++)
    {
        for (int j = 1 ; j <= iW ; j++)
        {
            vecDP[i][j] = vecDP[i - 1][j];
            if (j > vecW[i])
                vecDP[i][j] = max(vecDP[i][j], vecV[i] + vecDP[i - 1][j - vecW[i]]);
        }
    }
}

void printResult(const int &iN, int iW, const vector<int> &vecW, const vector<int> &vecV, const vector<vector<int>> &vecDP)
{
    int iMaxValue = vecDP[iN][iW];
    cout << iMaxValue << endl;
    vector<int> vecResult;
    for (int i = iN ; i >= 1 ; i--)
    {
        if (vecDP[i - 1][iW - vecW[i]] == iMaxValue - vecV[i])
        {
            vecResult.push_back(1);
            iW -= vecW[i];
            iMaxValue -= vecV[i];
        }
        else
            vecResult.push_back(0);
    }
    for (int j = vecResult.size() - 1 ; j >= 0 ; j--)
        cout << vecResult[j] << " ";
}

int main()
{
    int iN, iW;
    cin >> iN >> iW;
    vector<int> vecW(iN + 1), vecV(iN + 1);
    for (int i = 1 ; i <= iN ; i++)
        cin >> vecW[i] >> vecV[i];
    vector<vector<int>> vecDP(iN + 1, vector<int>(iW + 1, 0));
    
    solveProblem(iN, iW, vecW, vecV, vecDP);
    printResult(iN, iW, vecW, vecV, vecDP);
    return 0;
}