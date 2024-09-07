#include <iostream>
#include <string>
using namespace std;

int main() {
    int num, n1, n2, n3;
    int arr[10] = {0};
    
    cin>>n1;
    cin>>n2;
    cin>>n3;
    num = n1 * n2 * n3;
    for(int i=num; i>0; i/=10) {
        arr[i%10]++;
    }
    for(int i=0; i<10; i++) {
        cout<<arr[i]<<endl;
    }
}