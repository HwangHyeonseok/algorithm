// long int 는 4바이트 자료형
// long long int 는 8바이트 자료형, long long long int 는 12바이트 자료형 이라고 생각.
// 즉, 자료형 'long' 키워드가 하나 붙을 때마다 4N 바이트의 자료형이 된다. (N은 long 키워드의 개수)

#include <iostream>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int bytes;
    cin >> bytes;
    
    while(bytes >= 4) {
        bytes -= 4;
        cout << "long ";
    }
    cout << "int";
    return 0;
}