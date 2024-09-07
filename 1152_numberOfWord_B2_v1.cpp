#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    int count = 0;
    getline(cin, s, '\n');
    if(s.size() == 1) {
        if(s[0] == ' ') {
            cout<<0<<'\n';
            return 0;
        }
        else {
            cout<<1<<'\n';
            return 0;
        }
    }
    for(int i=0; i<s.size(); i++) {
        if(s[i] == ' ') {
            if(i!=0 && i!=s.size()-1) {
                count++;
            }
        }
    }
    cout<<count+1<<'\n';
}