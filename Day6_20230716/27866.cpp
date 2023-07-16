// #¹®ÀÚ¿­
#include <iostream>
#include <string>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    string word;
    int index;

    cin >> word;
    cin >> index;
    
    cout << word[index-1];
    return 0;
}