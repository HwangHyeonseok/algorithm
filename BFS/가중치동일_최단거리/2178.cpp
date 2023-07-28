// BFS - �ִܰŸ�

#include <iostream>
#include <queue>

using namespace std;

#define MAX_N 101 // �ִ� ũ�� 100
int row, col;
int Board[MAX_N][MAX_N]; // �̵� ���� : 1

void bfs(int start_x, int start_y) {
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};
    queue< pair<int, int> > Q;
    
    // ù ��ġ push + �湮 ó��
    Q.push(make_pair(start_x, start_y));
    Board[start_x][start_y] = 2; // movecount �� ĥ���ش�. (ó���� 2�� ĥ�����Ƿ� ���������� ���� �̵��Ÿ����� 1�� ���ش�.)

    while(!Q.empty()) {
        int cur_x = Q.front().first;
        int cur_y = Q.front().second;
        Q.pop();

        for(int i=0; i<4; i++) {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];
            // �� ���� ������ �������� ���� �˻�
            if(next_x >= row || next_x < 0 || next_y >= col || next_y < 0) continue;
            if(Board[next_x][next_y] != 1) continue;

            Q.push({next_x, next_y});
            Board[next_x][next_y] = Board[cur_x][cur_y]+1;
        }
    }
    cout << Board[row-1][col-1] - 1;
}

int main(void) {
    //ios_base::sync_with_stdio(false); cin.tie(nullptr); // [�����Ʈ] C�� C++ ����� ������ ȥ���Ͽ� ��� �� �� ������ ����ϸ� �ȵȴ�.
    cin >> row >> col;
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            int condition;
            scanf("%1d", &condition);
            Board[i][j] = condition;
        }
    }
    
    bfs(0,0);

    return 0;
}