// #���ڿ� �Ľ� # int -> string ���� �ٲٴ� ��ũ��
#include<iostream>
#include<string>

using namespace std;

int main(int argc, char** argv)
{
	int N;
    cin >> N;
    
    for(int i=1; i<=N; i++) {
        string str_num = to_string(i); // int -> string ��ȯ
        bool printnum = true; // �ڼ��� ġ�� ���� ��� -> ���� ��� ����
        int digit = str_num.size(); // �ڸ��� ���ϱ�
        for(int j=0; j<digit; j++) { // �� �ڸ����� 3,6,9�� ���ԵǾ� �ִ��� ��
            if(str_num[j] == '3' || str_num[j] == '6' || str_num[j] == '9') { // �ڼ� ġ��
                cout << "-";
                printnum = false;
            }
        }
        
        if(printnum == true) cout << i;
        
        cout << " ";
        
    }
	return 0;
}