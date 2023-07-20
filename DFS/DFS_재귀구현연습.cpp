#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define MAX_N 10

int Graph[MAX_N][MAX_N]; // ���� ���� ������ ���� �迭
int node, edge; // ��� ����, ���� ����
int visited[MAX_N]; // ���� �湮 ���� üũ
void dfs(int root) {
    // �湮 ó��
    visited[root] = 1;
    cout << root << " ";

    // ���� ��� Ž��
    for(int next=0; next<node; next++) {
        // ���� ��尡 �� ���� : 1) ������ �湮�� ���� ���� ��� 2) ���� ���� ������ �Ǿ� �ִ� ���
        if(visited[next] != 0 || Graph[next][root] != 1)
            continue;
        // ��������� ���� ��忡 ����
        dfs(next);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin >> node >> edge;

    // ��� ���� ����
    for(int i=0; i<edge; i++) {
        int start, end;
        cin >> start >> end;
        Graph[start][end]  = Graph[end][start] = 1;
    }

    dfs(0); // ���� ���(root ���) : 0
    return 0;
}