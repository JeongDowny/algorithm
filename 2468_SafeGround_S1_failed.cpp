#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> graph[100001];
vector<int> safelist;
vector<int> map[100001];
bool visited[100001];

void reset(int size) {
    safelist.clear();
    for(int i=0; i<size*size; i++) {
        graph[i].clear();
        visited[i] = false; 
    }
}

void isside(int n1, int n2, int m)
{
    if (n1 - 1 == n2 || n1 + 1 == n2)
    {
        if (!(((n1 + 1) % m == 0 && n2 % m == 0) || (n1 % m == 0 && (n2 + 1) % m == 0)))
        {
            graph[n1].push_back(n2);
            graph[n2].push_back(n1);
        }
    }

    if (n1 - m == n2 || n1 + m == n2)
    {
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }
}

void bfs(int start)
{
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = 0; i < graph[x].size(); i++) {
            int y = graph[x][i];
            if (!visited[y])
            {
                q.push(y);
                visited[y] = true;
            }
        }
    }
}

int safeGround(int size, int rain) {
    int count = 0;

    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++) {
            if(map[j][i] > rain) {
                safelist.push_back(j+i*size);
            }
        }
    }

    for(int i=0; i<safelist.size(); i++) {
        for(int j=0; j<safelist.size(); j++) {
            isside(safelist[i], safelist[j], size);
        }
    }

    while(safelist.size() != 0) {
        bfs(safelist.front());
        count++;
    }
    
    reset(size);

    return count;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int size;
    cin>>size;
    if(size<2 || size>100) return 0;

    int bign = 0;
    int smalln;
    int result = 0;

    for(int i=0; i<size; i++) {
        vector<int> temp;
        for(int j=0; j<size; j++) {
            int n;
            cin>>n;
            map[i].push_back(n);
        }
    }

    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            if(map[i][j] > bign) bign = map[i][j];
        }
    }

    smalln = bign;

    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            if(map[i][j] < smalln) smalln = map[i][j];
        }
    }

    for(int i=smalln; i<bign; i++) {
        int temp = safeGround(size ,i);
        if(result < temp) result = temp;
    }
    cout<<result;
}