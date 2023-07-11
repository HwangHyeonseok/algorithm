// 이스케이프 시퀀스 문제
#include <iostream>

using namespace std;

int main(void) {
    // 실행 속도를 빠르게 하기 위한 테크닉
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cout << "\\    /\\" << "\n"; // endl보다 \n이 더 빠르다.
    cout << " )  ( \')" << "\n";
    cout << "(  /  )" << "\n";
    cout << " \\(__)|" << "\n";
    return 0;
}