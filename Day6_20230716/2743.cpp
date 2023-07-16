// 문자열 길이 구하기

#include <iostream>
#include <string>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); 

    string word;
    cin >> word;
    
    cout << word.length();
    return 0;
}