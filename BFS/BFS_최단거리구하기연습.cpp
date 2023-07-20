#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
#define MAX_N 10

int Graph[MAX_N][MAX_N];
int n;

struct Point {
    int pos_x;
    int pos_y;
    int distance; // �Ÿ�
};

int bfs(int start_x, int start_y, int target_x, int target_y) {
    // �̵� ���� �����¿�
    int move_x[4] = {0, 0, -1, 1};
    int move_y[4] = {-1, 1, 0,0 };
    
    queue<Point> locations; // ��ġ���� ���� ť

    if(start_y == target_y && start_x == target_x) return 0; // ���� ��ġ���� ���� ��ġ�� ���� ���

    // �ʱ� ��ġ ó�� - �湮ó�� + push
    Graph[start_x][start_y] = 1;
    locations.push({start_x, start_y, 0});

    while(!locations.empty()) {
        int cur_x = locations.front().pos_x;
        int cur_y = locations.front().pos_y;
        int dist = locations.front().distance;

        locations.pop();
        
        // �������� �����ߴ��� Ȯ��
        if(cur_x == target_x && cur_y == target_y)
            return dist;

        for(int next = 0; next < 4; next++) {
            int next_x = cur_x + move_x[next];
            int next_y = cur_y + move_y[next];
            // ���� ��ġ�� �̵��� ������ ���� 1) �� ���� ���� 2) �湮�� ���� ���� ��ġ 3) ����� ��ġ
            if(next_x >= n || next_x < 0 || next_y >=n || next_y <0) continue; // 1)
            if(Graph[next_x][next_y] != 0) continue; // 2)

            // �湮 ó�� �� push
            Graph[next_x][next_y] = 1;
            locations.push({next_x, next_y, dist+1});
        }
    }
    return -1; // ������ (���� ã�� �� ����)
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    // �� ũ�� �Է�
    cin >> n;
    // ���� ���� �Է� (�̵� ���� : 0, ��(�̵� �Ұ�) : 1)
    for(int i=0; i<n; i++) { // y
        for(int j=0; j<n; j++) { // x
            int condition;
            cin >> condition;
            Graph[i][j] = condition;
        }
    }
    int start_x, start_y; // ���� ��ġ (x,y)
    int target_x, target_y; // ���� ��ġ (x,y)
    int answer = 0; // �̵� Ƚ��
    cin >> start_x >> start_y >> target_x >> target_y;
    
    answer = bfs(start_x, start_y, target_x, target_y);
    cout << answer;

    return 0;
}