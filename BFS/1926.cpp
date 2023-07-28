#include <iostream>
#include <queue>

using namespace std;
#define MAX_N 501
int board[MAX_N][MAX_N];  //  1�� �̵� ����
int row, col;

int bfs(int start_x, int start_y) {
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int area = 0;

    queue< pair<int, int> > Q;
    
    // ���� ��ġ push + �湮 ǥ��
    Q.push(make_pair(start_x, start_y));
    board[start_x][start_y] = 0; 
    area++;
    
    while(!Q.empty()) {
        int cur_x = Q.front().first;
        int cur_y = Q.front().second;
        Q.pop();

        for(int i=0; i<4; i++) {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];
            // �� ���� ���� ������� ���� �˻�
            if(next_x >= row || next_x < 0 || next_y >= col || next_y < 0) continue;
            if(board[next_x][next_y] != 1) continue;

            Q.push({next_x, next_y}); // Q.push(make_pair(next_x, next_y))
            board[next_x][next_y] = 0;
            area++;
        }
    }
    return area;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int pictures = 0;
    int big_picture_area = 0;
    cin >> row >> col;
    
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            int condition;
            cin >> condition;
            board[i][j] = condition;
        }
    }

    // for������ ���鼭 1�� ���� ã�´�.
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            if(board[i][j] == 1) {
                int picture_area = bfs(i,j);
                big_picture_area = big_picture_area>picture_area? big_picture_area : picture_area;
                pictures++;
            }
        }
    }

    cout << pictures << "\n";
    cout << big_picture_area << "\n";
    return 0;
}