#include <iostream>
#include <vector>
using namespace std;

void cantor(int n, vector<char> str) {
    if(find(str.begin(), str.end(), '-')!=str.end()) {
        vector<char> tempStr1(str.size()/3, '-');
        vector<char> tempStr2(str.size()/3, ' ');
        vector<char> tempStr3 = tempStr1;
    }
    else {
        vector<char> tempStr1(str.size()/3, ' ');
        vector<char> tempStr2 = tempStr1;
        vector<char> tempStr3 = tempStr1;
    }

    if(tempStr1.size() != 1) {
        cantor(n-1, tempStr1);
        cantor(n-1, tempStr2);
        cantor(n-1, tempStr3);
    }
    else {
        cout<<tempStr1[0]<<tempStr2[0]<<tempStr3[0];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<char> str;
    for(int i=0; i<pow(3, n); i++) {
        char c = '-';
        str.push_back(c);
    }

    cantor(n, str);
}