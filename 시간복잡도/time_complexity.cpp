// 시간 복잡도 측정하기

// 1) ctime 라이브러리르 추가한다.
// 2) time_t 객체를 만들어준다. (start, end)
// 3) 현재 시간을 담는다. 
// 4) 프로그램 소스코드를 작성한다.
// 5) 프로그램 소스코드를 실행하고 난 나중 시간을 담는다.
// 6) ( 종료 시간 - 시작 시간 ) / CLOCKS_PER_SEC 을 한다.

// Ex. 결과 : 16.35 이면, 프로그램 실행이 16.35초 걸렸다는 의미이다.
#include <iostream> 
#include <ctime> // 1)

using namespace std;

int main(void) {
    time_t start, end; // 2)
    double time;
    int sum = 0;

    start = clock(); // 시간 측정 시작

    for (int i = 0; i < 100000; i++) {
        for (int j = 0; j < 100000; j++) {
            sum += i * j;
        }
    }

    end = clock(); // 시간 측정 종료
    double result = (double)(end - start) / CLOCKS_PER_SEC ; // 종료 시간 - 시작 시간 = 걸린 시간
    cout << result;
    return 0;
}
