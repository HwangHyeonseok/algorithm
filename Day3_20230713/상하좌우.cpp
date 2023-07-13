// 키워드 : #문자열 파싱(parsing), #길찾기 시뮬레이션

// 문제 : 모험가 A가 N의 공간에서 계획서에 따라 이동하는 경우, 최종 도착하는 좌표의 (X, Y)를 출력하시오.
// 참고 : N X N의 2차원 행렬, 모험가의 시작 좌표는 1, 1
// 참고 : 시뮬레이션 유형 - 제시하는 요구사항에 따라 단계별로 수행
// (단, 공간 밖의 이동은 무시한다.)

// U는 up, D는 down, R은 right, L은 left

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main(void) {
    int N; // 맵의 크기는 N*N
    int cur_x = 1; int cur_y = 1; // 초기 위치
    string str;
    string Buffer;
    vector<string> directions; // 방향들을 저장해놓는 벡터

    cin >> N; // 맵의 크기를 정한다.
    cin.ignore(); // 버퍼 제거(엔터 버퍼)

    getline(cin, str); // 방향을 입력 받는다.
    istringstream ss(str); // ss 스트림에 문자열을 넣어준다.

    // 입력받은 방향의 문자열 파싱을 진행한다.
    // ss 스트림에서 빈 칸을 만날 때까지를 Buffer에 저장한다.
    while(getline(ss, Buffer, ' ')) {
        directions.push_back(Buffer);
    }

    for(int i=0; i<directions.size(); i++) {
        if(directions[i] == "U") { // Up 입력 시
            if(cur_y > 1)
                cur_y += -1;
        }
        else if(directions[i] == "D") { // Down 입력 시
            if(cur_y < N)
                cur_y += +1;
        }
        else if(directions[i] == "L") { // Left 입력 시
            if(cur_x > 1)
                cur_x += -1;
        }
        else if(directions[i] == "R") { // Right 입력 시
            if(cur_x < N)
                cur_x += +1;
        }
    }



    cout << cur_y << " " << cur_x;

    return 0;
}