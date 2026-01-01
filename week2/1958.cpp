#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string seq1;
string seq2;
string seq3;

int DP[102][102][102];
void init()
{
    cin >> seq1 >> seq2 >> seq3;
}

void LCS()
{

    for (int i = 1; i <= seq1.length(); i++)
    {
        for (int j = 1; j <= seq2.length(); j++)
        {
            for (int k = 1; k <= seq3.length(); k++)
            {

                // 같으면
                if (seq1[i - 1] == seq2[j - 1] && seq2[j - 1] == seq3[k - 1])
                {
                    DP[i][j][k] = DP[i - 1][j - 1][k - 1] + 1;
                }

                // 다르면
                else
                {
                    DP[i][j][k] = max({DP[i - 1][j][k], DP[i][j - 1][k], DP[i][j][k - 1]});
                }
            }
        }
    }

    cout << DP[seq1.length()][seq2.length()][seq3.length()] << '\n';
}

int main()
{
    init();
    LCS();
    return 0;
}
