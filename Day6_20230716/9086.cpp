// ���ڿ� ù ���ڿ� ������ ���� ���

#include <iostream>
#include <string>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int input_word; // �Է¹��� �ܾ� ��
    
    cin >> input_word;

    for(int i=0; i<input_word; i++) {
        string word;
        cin >> word;
        cout << word[0] << word[word.length()-1] << "\n";
    }
    
    return 0;
}