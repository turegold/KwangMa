#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string seq1, seq2;
int DP[1002][1002];

void init()
{
    cin >> seq1 >> seq2;
}

void LCS()
{
    for (int i = 1; i <= seq1.length(); i++)
    {
        for (int j = 1; j <= seq2.length(); j++)
        {
            // 같으면?
            if (seq1[i - 1] == seq2[j - 1])
            {
                DP[i][j] = DP[i - 1][j - 1] + 1;
            }
            // 다르면?
            else
            {
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
            }
        }
    }

    string result;
    int tar_i = seq1.length();
    int tar_j = seq2.length();
    while (DP[tar_i][tar_j] > 0)
    {
        // 같으면?
        if (seq1[tar_i - 1] == seq2[tar_j - 1])
        {
            result += seq1[tar_i - 1];
            tar_i--;
            tar_j--;
        }
        // 다르면?
        else
        {
            if (DP[tar_i - 1][tar_j] > DP[tar_i][tar_j - 1])
            {
                tar_i--;
            }
            else
            {
                tar_j--;
            }
        }
    }
    reverse(result.begin(), result.end());

    cout << DP[seq1.length()][seq2.length()] << '\n';
    cout << result << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    init();
    LCS();
    return 0;
}
