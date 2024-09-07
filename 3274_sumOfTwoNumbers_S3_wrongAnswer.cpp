#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector <int> vec; 
    vector < pair < int, int > > pairVec;
    for(int i=0; i<n; i++) {
        int temp;
        cin>>temp;
        vec.push_back(temp);
    }
    int x;
    cin>>x;
    for(int i=0; i<n; i++) {
        for(
            int j=i; j<n; j++) {
            if(vec[i] + vec[j] == x) {
                pairVec.push_back(make_pair(i, j));
            }
        }
    }
    cout<<pairVec.size()<<"\n";
}
/* 
수열에 같은 수가 2개 이상 입력될 시 중복된 쌍을 예외처리하지 못함. 
vector와 pair만 이용해 구현하려면 if문에 pairVec안을 순회하며 동일한 쌍이 존재하는지 확인해야함.
시간복잡도가 이미 n^2에다가 쌍의 개수 * n만큼 늘어남. --> unordered_set을 이용하자.

vector, list, deque -> 순서가 있는 시퀀스 컨테이너
set map -> 연관 컨테이너: key값과 value값이 매치

set, multiset: 키 존재 확인 가능, 정렬된 상태 유지하는 트리구조(비교연산 오버로딩 가능)
map, multimap: 키 존재 확인, 키대응값 질의 가능, set보다 많은 메모리 차지
https://m.blog.naver.com/PostView.naver?blogId=webserver3315&logNo=221678909965&categoryNo=48&proxyReferer=&noTrackingCode=true
*/