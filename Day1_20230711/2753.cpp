// ������ 4�� ����̸鼭, 100�� ����� �ƴ� �� �Ǵ� 400�� ����� �� => ����
// ������ �� ����
// 1. ������ 4�� ����̸鼭 100�� ����� �ƴϴ�.
// 2. 400�� ����̴�.

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