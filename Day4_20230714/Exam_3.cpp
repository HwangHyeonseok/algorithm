// #시뮬레이션-길찾기 #BFS 기반 지식 #랜덤 함수(srand, rand) #문자열 파싱 #숫자<->문자열 변환 스킬
// 체감 난이도 : S1~S2

// 남은 시간 : 52분 34초 -> 18분 58초 (약 33분~34분 소요)
// 8*8 2차원 행렬에서 나이트가 이동할 수 있는 경우의 수를 구하시오.
// 단, 함정이 랜덤으로 주어지고, 함정이 있는 곳으로는 이동할 수 없다.
// 나이트가 이동을 하려 할 때 이동하는 곳이 함정이라면 
// -> 이동 가능 경우 수에서 -1하고, 함정 회피 횟수를 +1 해준다.

// 입력 : c2 
// 출력 : {이동 가능경우 수}번 이동할 수 있습니다. (함정 {함정 회피 횟수}회 회피!)

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int board[8][8]; // 보드판 (전역이므로 모두 0으로 초기화 -> 0은 방문하지 않음, 2는 함정)
int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    srand((unsigned int)time(NULL)); // 랜덤 시드 부여
    string cur_str_location; // 입력받은 현재 위치
    int cur_x; // 현재 x 위치 (열)
    int cur_y; // 현재 y 위치 (행)

    // 함정 위치 정하기(랜덤) - 함정은 중복없이 6개를 만들어야 한다.
    for(int i=0; i<6; i++) { 
        int bomb_location_x; // 함정 위치
        int bomb_location_y; // 함정 위치
        bomb_location_x = rand() % 8;
        bomb_location_y = rand() % 8;

        // 이미 있는 함정인 경우 다시 함정 위치를 선정한다.
        if(board[bomb_location_y][bomb_location_x] == 2) {
            i--;
            continue;
        }
        
        board[bomb_location_y][bomb_location_x] = 2; // 함정 위치로 선택한다.
    }


    cin >> cur_str_location; // 현재 위치를 입력받는다.
    
    // 문자열의 위치 -> int형의 위치로 변환하기 위한 코드 (인덱스 형태)
    // cur_x, cur_y 이 구해졌다.
    for(int i=0; i<2; i++) {
        if(i==0) {
            cur_x = cur_str_location[i]-'a';
        }
        else if(i==1) {
            cur_y = cur_str_location[i]-'1';
        }
    } 

    
    // 나이트가 이동할 수 있는 모든 경우의 수를 시뮬레이션을 통해 이동하여 결과값을 출력한다.
    
    int answer = 0; // 이동 가능 경우 수 
    int bomb_move = 0; // 함정 회피 횟수

    // 나이트의 이동 구현 배열
    int move_x[8] = {2,-2,-1,1,2,1,-1,-2};
    int move_y[8] = {-1,-1,-2,-2,1,2,2,1};


    for(int i=0; i<8; i++) {
        int later_x = cur_x + move_x[i];
        int later_y = cur_y + move_y[i];
        
        // 이동할 수 없는 곳으로 이동한 경우(맵 범위를 벗어난 경우)
        if(later_x < 0 || later_x > 7 || later_y < 0 || later_y > 7) {
            continue;
        }

        // 함정을 밟은 경우
        if(board[later_y][later_x] == 2) {
            bomb_move++;
            continue;
        }

        // 정상적인 경로로 이동한 경우
        answer++;
    }
    
    cout << answer << "번 이동할 수 있습니다. (함정 " << bomb_move << "회 회피!)";
    return 0;
}

// 자체 제작 test case
//입력 : c2 -> 5번 이동할 수 있습니다. (함정 1회 회피!) -> 통과
//입력 : d4 -> 7번 이동할 수 있습니다. (함정 1회 회피!) -> 통과
//입력 : d4 -> 8번 이동할 수 있습니다. (함정 0회 회피!) -> 통과
//입력 : a1 -> 2번 이동할 수 있습니다. (함정 0회 회피!) -> 통과