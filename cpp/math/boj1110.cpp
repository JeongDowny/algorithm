#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, result = 0, temp = 0, count = 0;
    cin >> n;

    if (n < 10)
    {
        temp = n * 10 + n;
        count++;
    }
    else
    {
        temp = n;
    }

    while (n != result)
    {
        result = (temp % 10) * 10 + ((temp / 10) + (temp % 10)) % 10;
        temp = result;
        count++;
    }
    cout << count;
}