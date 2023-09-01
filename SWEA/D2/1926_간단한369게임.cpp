// #문자열 파싱 # int -> string 으로 바꾸는 테크닉
#include<iostream>
#include<string>

using namespace std;

int main(int argc, char** argv)
{
	int N;
    cin >> N;
    
    for(int i=1; i<=N; i++) {
        string str_num = to_string(i); // int -> string 변환
        bool printnum = true; // 박수를 치지 않은 경우 -> 숫자 출력 가능
        int digit = str_num.size(); // 자릿수 구하기
        for(int j=0; j<digit; j++) { // 한 자리마다 3,6,9가 포함되어 있는지 비교
            if(str_num[j] == '3' || str_num[j] == '6' || str_num[j] == '9') { // 박수 치기
                cout << "-";
                printnum = false;
            }
        }
        
        if(printnum == true) cout << i;
        
        cout << " ";
        
    }
	return 0;
}