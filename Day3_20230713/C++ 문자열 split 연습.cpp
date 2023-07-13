// ���ڿ� �Ľ� ����
// ���� refernce : https://roadtosuccess.tistory.com/84
// ���� 
//   1) istringstream

//     - ���ڿ� ������ parsing �� �� ����մϴ�.

//   2) ostringstream

//     - ���ڿ� format�� �����Ͽ� ������ �� ����մϴ�.

//   3) sstringstream

//     - ���ڿ����� ���� ���ϴ� �ڷ����� �����͸� ������ �� ����մϴ�.
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    string str; // �Է¹޴� ���ڿ�
    vector<string> v; // ���ҵ� ���ڿ��� �ִ� ����
    string Buffer;
    
    getline(cin, str); 
    istringstream ss(str); // str�� ���ڿ��� �Ľ�
    

    while(getline(ss, Buffer, ' ')) { // ss ��Ʈ�� �������� ����(' ')������ �Է����� �޾� Buffer�� �����Ѵ�. (�ٸ� ���ڵ� ����)
        v.push_back(Buffer); 
    }
    
    for(int i=0; i<v.size(); i++) {
        cout << v[i] << "\n";
    }


    return 0;
}