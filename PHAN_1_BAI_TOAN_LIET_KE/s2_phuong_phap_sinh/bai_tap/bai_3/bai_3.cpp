// Hãy liệt kê các dãy nhị phân có độ dài n mà trong đó cụm chữ số "01" xuất hiện đúng 2 lần
/*
Solution:
    - Sinh nhị phân như thường, thêm đoạn mã để kiểm tra xem trong dãy vừa sinh có cụm chữ số "01" 
    xuất hiện 2 lần không?
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>

using namespace std;

bool checkBinary(vector<int>& s) {
    int count = 0;
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] == 0 && s[i+1] == 1) {
            count++;
        }
    }
    if (count == 2) return true;
    return false;
}

void printResult(vector<int>& s, fstream& out) {
    for (int i = 0; i < s.size(); i++) {
        out << s[i] << " ";
    }
    out << "\n";
}

int main() {
    fstream inFile("bai_3.inp");
    fstream outFile("bai_3.out");

    int num;
    inFile >> num;
    inFile.close();

    vector<int> array(num, 0);
    int i = num - 1;
    do {
        i = num - 1;
        if (checkBinary(array)) printResult(array, outFile);
        while (i >= 0 && array[i] != 0) i--;
        array[i] = 1;
        for (int j = i + 1; j < array.size(); j++) array[j] = 0; 
    }
    while (i >= 0);

    outFile.close();
    return 0;
}