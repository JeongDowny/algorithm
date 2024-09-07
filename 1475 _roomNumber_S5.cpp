#include <iostream>
using namespace std;

int setNeed(int num) {
    int arr[10] = {0};
    int n = 0;
    auto n = 0;
    for(int i=num; i>0; i/=10) {
        if(i%10==6 || i%10==9) {
            if(arr[6]<arr[9]) {
                arr[6]++;
            }
            else if(arr[6]>arr[9]) {
                arr[9]++;
            }
            else {
                arr[i%10]++;
            }
        }
        else {
            arr[i%10]++;
        }
    }

    for(int i=0; i<10; i++) {
        if(arr[i]>n) {
            n = arr[i];
        }
    }

    return n;
}

int main() {
    int n;
    cin>>n;
    cout<<setNeed(n)<<endl;
}