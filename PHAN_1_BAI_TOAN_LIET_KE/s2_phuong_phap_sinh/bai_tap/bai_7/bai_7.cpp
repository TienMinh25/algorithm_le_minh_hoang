#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n;
    cout << "Nhập n: (Độ dài của mảng khi khởi tạo cho học sinh nam và học sinh nữ)";
    cin >> n;
    vector<string> males, females;

    for (int i = 0; i < n; i++) {
        cout << "Nhập tên của bạn nam: "<< endl;
        cin >> males[i];
        cout << "Nhập tên của bạn nữ: " << endl;
        cin >> females[i];
    }

    
    return 0;
}