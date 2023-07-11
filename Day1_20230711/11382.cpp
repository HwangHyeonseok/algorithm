// int형 범위 : 약 21억
// int형 범위를 초과할 우려가 있으므로 long long int 을 사용한다.

#include <iostream>
#include <math.h>

using namespace std;

int main(void) {
    // 코드 실행 속도를 높여주기 위한 테크닉
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    long long int a,b,c;
    long long int answer;
    cin >> a >> b >> c;
    answer = a+b+c;
    cout << answer;
    return 0;
}