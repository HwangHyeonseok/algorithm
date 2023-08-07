// 구현 + 문자열 - 배열 인덱스 활용

#include <iostream>
#include <string>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    string s;
    cin >> s;

    int i = 0;
    
    while(i < s.length()/2) {
        if(s[i] != s[s.length()-i-1]) {
            cout << "0";
            return 0;
        }
        i = i+1;
    }

    cout << "1";
    return 0;
}