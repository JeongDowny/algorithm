#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    int t, m;
    cin>>t;
    for(int i=0; i<t; i++) {
        cin>>m;
        multiset<int> setArr;
        vector<int> vecArr;
        for(int j=0; j<m; j++) {
            int n;
            cin>>n;
            setArr.insert(n);
            if(
                j%2==0) {
                vector<int> vecTemp(setArr.begin(), setArr.end());
                vecArr.insert(vecArr.end(), vecTemp[j/2]);
            }
        }
        cout<<(m+1)/2<<"\n";
        for(int j=0; j<vecArr.size(); j++) {
            cout<<vecArr[j]<<" ";
            if(j%9==0 && j!=0) {
                cout<<"\n";
            }
        }
        cout<<"\n";
    }
}