// https://www.acmicpc.net/problem/1541

// #���ڿ� -> ���� �Ľ�, #���ڿ� #�׸��� �˰���

// ���� �ּҰ� �Ƿ��� - ��ȣ�� ���� ���ķδ� ��� ���ڿ� ���� �Է��� - ������ ���ָ� �ȴ�.
// ex ) 55-50+40 �̸�, 55-(50+40) = -35 (��, -�� ���� 50�� 40 ���ڴ� ��ȣ ���� ���� ��� ���̳ʽ� ó��)
// ex ) 55+30+20-30+40+70 �̸�, -������ 30,40,70 ���ڿ� ���� ��� - ���� ó��
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    string cal; // �Է¹��� ����
    string s_num="";
    bool minus = false; // minus�� �����ϴ��� ����
    int last_index = 0;
    int answer = 0;
    cin >> cal;

    for(int i=0; i<cal.size(); i++) {
        if(cal[i] == '-' || cal[i] == '+') {
            // ���ڿ� -> ���� �Ľ�
            for(int j = last_index; j < i; j++) {
                s_num += cal[j];
            }
            last_index = i+1;
        }
        // ���ڰ� �������Ƿ� ���� ó��
        if(s_num != "") {
            if(minus == true) answer -= stoi(s_num);
            else if(minus == false) answer += stoi(s_num);
        }

        s_num ="";
        if(cal[i] == '-') minus = true;
    }

    // ������ ���� ó��
    for(int i=last_index; i<cal.size(); i++) {
        s_num += cal[i];
    }
    if(minus == true) answer -= stoi(s_num);
    else answer += stoi(s_num);

    cout << answer;

    return 0;
}