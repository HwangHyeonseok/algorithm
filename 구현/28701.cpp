// 구현 - 일반 연산자 구현
#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N;
    int sum = 0;
    int sum3 = 0;
    cin >> N;

    for(int i=1; i<=N; i++) {
        sum += i;
    }
    
    for(int i=1; i<=N; i++) {
        sum3 = sum3 + (i*i*i);
    }

    cout << sum << "\n";
    cout << sum*sum << "\n";
    cout << sum3 << "\n";

    return 0;
}