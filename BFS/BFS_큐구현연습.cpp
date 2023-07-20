#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;
#define MAX_N 10
int Graph[MAX_N][MAX_N]; // �̿��� : 0, ���� : 1
int edge, node;

void bfs(int root) {
    queue<int> q; // BFS ������ ���� ���� ť
    int visited[MAX_N]; // �̹湮 : 0, �湮 : 1
    memset(visited, 0, sizeof(visited));

    // root ��� �湮 ó��
    q.push(root);
    visited[root] = 1;
    
    while(!q.empty()) {
        // �湮ó�� + ��� ó��
        int cur_node = q.front();
        q.pop();

        cout << cur_node << " ";

        // ���� ��� Ž�� - 1) ������ �湮�� ���� ���� 2) ������ ���
        for(int next=0; next<node; next++) {
            if (visited[next] == 0 && Graph[cur_node][next] != 0) {
            // ���� �� ��尡 �׻� ���� �湮�Ǳ� ������ ������ ��带 �ٽ� enqueue �� ������ ����.
                visited[next] = 1;
                q.push(next);
            }

        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    cin >> node >> edge;
     // ���� ���� ����
    for(int i=0; i<edge; i++) 
    {
        int start, end;
        cin >> start >> end;
        Graph[start][end] = Graph[end][start] = 1;
    }

    bfs(0); // root��� : 0
    return 0;
}