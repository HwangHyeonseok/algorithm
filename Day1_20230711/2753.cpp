// 연도가 4의 배수이면서, 100의 배수가 아닐 때 또는 400의 배수일 때 => 윤년
// 윤년이 될 조건
// 1. 연도가 4의 배수이면서 100의 배수가 아니다.
// 2. 400의 배수이다.

#include <iostream>

using namespace std;

int main(void ) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int year  = 0;

    cin >> year;
    if((year % 4 == 0 && year % 100 !=0) || year % 400 == 0) {
        cout << "1";
    }
    else {
        cout << "0";
    }
    
    return 0;
}