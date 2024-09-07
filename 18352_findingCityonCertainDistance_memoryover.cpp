#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, k, x; //도시n개, 도로m개, 최단거리k, 출발도시x
priority_queue<int, vector<int>, greater<int>> pq;

void dijkstra(vector<int> graph[], vector<int> nodes, int start) {
    pq.push(start);
    nodes[start] = 0;

    while(!pq.empty()) {
        int t = pq.top();
        pq.pop();

        for(int i=0; i<graph[t].size(); i++) {
            int y = graph[t][i];
            pq.push(y);

            if(nodes[y]==-1 || nodes[y]>nodes[t]+1) {
                nodes[y] = nodes[t] + 1;
            }
            
        }
    }

    bool found = false;
    for(int i=1; i<n+1; i++) {
        if(nodes[i] == k) {
            pq.push(i);
            found = true;
        }
    }
    if(!found) {
        cout<<-1;
    }
    while(!pq.empty()) {
        cout<<pq.top()<<'\n';
        pq.pop();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m>>k>>x;

    vector<int> graph[n+1];
    vector<int> nodes(n+1, -1);

    for(int i=0; i<m; i++) {
        int temp1, temp2;
        cin>>temp1>>temp2;
        graph[temp1].push_back(temp2);
    }
    dijkstra(graph, nodes, x);
}