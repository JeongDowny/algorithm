#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    int wordCount = 0;
    bool isWord = false;
    getline(cin, s);

    for(int i=0; i<s.size()+1; i++) {
        if(isWord == true) {
            if(s[i] == ' ' || s[i] == '\0') {
                isWord = false;
                wordCount++;
            }
        }
        else {
            if(s[i] != ' ' ) {
                isWord = true;
            }
        }
    }
    cout<<wordCount<<'\n';
}