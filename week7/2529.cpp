#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int k;
vector<char> sign;
bool visited[10];

string max_result = "";
string min_result = "";

void init()
{
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        char s;
        cin >> s;
        sign.push_back(s);
    }
}

void check_result(string cur)
{
    if (max_result == "" || cur > max_result)
    {
        max_result = cur;
    }

    if (min_result == "" || cur < min_result)
    {
        min_result = cur;
    }
}

void back_tracking(int num, int last_num, string cur)
{
    // 문자 완성
    if (cur.length() == k + 1)
    {
        check_result(cur);
        return;
    }

    for (int i = 0; i <= 9; i++)
    {
        // i를 이미 썼는가?
        if (!visited[i])
        {
            // 부등호에 맞는가?
            if (sign[num] == '>' && last_num > i)
            {
                visited[i] = true;
                back_tracking(num + 1, i, cur + char('0' + i));
            }
            else if (sign[num] == '<' && last_num < i)
            {
                visited[i] = true;
                back_tracking(num + 1, i, cur + char('0' + i));
            }
            visited[i] = false;
        }
    }
}

void print_result()
{
    cout << max_result << '\n';
    cout << min_result << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    init();
    for (int i = 0; i <= 9; i++)
    {
        string cur = "";
        visited[i] = true;
        back_tracking(0, i, cur + char('0' + i));
        visited[i] = false;
    }
    print_result();
    return 0;
}
