// DFS ��� ���� ����
#include <iostream>
#include <vector>
#include <string.h> // memset �޼��� ����� ���� ���̺귯��
using namespace std;
#define MAX_N 10 // �ִ� 10 * 10�� ��

int Graph[MAX_N][MAX_N];
int point, edge; // ������ ����

int Visited[MAX_N]; // �� ������ �湮�� �Ǿ����� üũ�ϴ� �迭

// dfs ��� ����
void dfs(int node) {
    // 1. �湮 ó�� �� ���
    Visited[node] = 1;
    cout << node << " ";

    // 2. ���� ��� Ž��
    for (int next = 0; next < point; next++) {
        // ���� ����� ���� - ������ �湮�� ���� ���� ���� ���� ������ �Ǿ� �־�� �Ѵ�.
        if ((Visited[next] == 0) && (Graph[next][node] == 1))
            dfs(next);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin >> point >> edge;
    // ������ ���� ���� �Է�
    for (int i = 0; i < edge; i++) {
        int start, end;
        cin >> start >> end;
        Graph[start][end] = Graph[end][start] = 1; // 3�� 5�� ����Ȱų�, 5�� 3�� ����Ȱų� ���� �ṉ̀� ����
    }

    dfs(0); // root ��� 0

    return 0;
}