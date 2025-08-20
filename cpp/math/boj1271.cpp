#include <iostream>
#include <cstring>
using namespace std;

char* max(char* a, char* b) {
    for(int i=0; i<strlen(a); i++) {
        if(a[i] > b[i]) return a;
        if(a[i] < b[i]) return b;
    }
    return a;
}

void subtract(char *a, char *b) {
    for(int i=0; i<strlen(b); i++) {
        a[i] = a[i] - b[i] + '0';
        if(a[i] < '0') {
            a[i] += 10;
            a[i-1]--;
        }
    }
    for(int i=strlen(b)-1; i>=0; i--) {
        if(a[i] < '0') {
            a[i] += 10;
            a[i-1]--;
        }
    }
 }

void devideSubtract(char* a, char* b, char* r, int index) {
    r[index] = '0';

    while (a[index - 1] > '0' || max(a + index, b) == a + index ) { //index 앞 칸의 몫이 0이거나, a의 index위치가 b보다 클 때
        subtract(a + index, b);
        ++r[index];
    }
}

void devide(char* a, char* b, char* r) {
    int index = 0;
    int digit = strlen(a) - strlen(b);

    while(index <= digit) devideSubtract(a, b, r, index++);

    r[index] = '\0';
}

int main() {
    char a[1001];
    char b[1001];
    char r[1001];

    int ri = 0, ai = 0;
    cin>>a>>b;
    devide(a, b, r);

    while(r[ri] == '0') ri++;
    while(a[ai] == '0') ai++;

    if(r[0] == '\0') {
        r[0] = '0';
        r[1] = '\0';
    }

    if(a[ai] == '\0') ai--;
    if(r[ri] == '\0') ri--;     

    cout<<r+ri<<endl;
    cout<<a+ai<<endl;
}