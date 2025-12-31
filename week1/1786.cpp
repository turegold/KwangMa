#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string str1;
string str2;
int result;
vector<int> res_arr;

void init()
{
    getline(cin, str1);
    getline(cin, str2);
}

vector<int> failure(string S)
{
    vector<int> fail(S.size(), 0);
    int j = 0; // 중복 개수

    for (int i = 1; i < S.size(); i++)
    {
        // 다를 경우
        while (j > 0 && S[i] != S[j])
        {
            j = fail[j - 1];
        }

        // 같을 경우
        if (S[i] == S[j])
        {
            fail[i] = ++j;
        }
    }

    return fail;
}

void KMP()
{
    vector<int> fail = failure(str2);
    int j = 0; // 중복 개수
    for (int i = 0; i < str1.size(); i++)
    {
        // 다를 경우
        while (j > 0 && str1[i] != str2[j])
        {
            j = fail[j - 1];
        }

        // 같을 경우
        if (str1[i] == str2[j])
        {
            ++j;
        }

        // 다 찾은 경우
        if (j == str2.size())
        {
            result++;
            res_arr.push_back(i - str2.size() + 2);
        }
    }
}

void print_result()
{
    cout << result << '\n';
    for (auto r : res_arr)
    {
        cout << r << ' ';
    }
    cout << '\n';
}

int main()
{
    init();
    KMP();
    print_result();
    return 0;
}
