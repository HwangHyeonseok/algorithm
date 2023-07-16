// 문자열 첫 글자와 마지막 글자 출력

#include <iostream>
#include <string>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int input_word; // 입력받을 단어 수
    
    cin >> input_word;

    for(int i=0; i<input_word; i++) {
        string word;
        cin >> word;
        cout << word[0] << word[word.length()-1] << "\n";
    }
    
    return 0;
}