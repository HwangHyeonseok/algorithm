// 문자열 파싱 연습
// 참고 refernce : https://roadtosuccess.tistory.com/84
// 참고 
//   1) istringstream

//     - 문자열 포맷을 parsing 할 때 사용합니다.

//   2) ostringstream

//     - 문자열 format을 조합하여 저장할 때 사용합니다.

//   3) sstringstream

//     - 문자열에서 내가 원하는 자료형의 데이터를 추출할 때 사용합니다.
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    string str; // 입력받는 문자열
    vector<string> v; // 분할된 문자열을 넣는 벡터
    string Buffer;
    
    getline(cin, str); 
    istringstream ss(str); // str의 문자열을 파싱
    

    while(getline(ss, Buffer, ' ')) { // ss 스트림 변수에서 공백(' ')까지를 입력으로 받아 Buffer에 저장한다. (다른 문자도 가능)
        v.push_back(Buffer); 
    }
    
    for(int i=0; i<v.size(); i++) {
        cout << v[i] << "\n";
    }


    return 0;
}