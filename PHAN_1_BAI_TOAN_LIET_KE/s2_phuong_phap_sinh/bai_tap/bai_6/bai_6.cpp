// Nhập vào danh sách tên n người, in ra tất cả các cách sắp xếp n người đó vào một bàn (không phải bàn tròn), 
// chỉ là bàn thôi : )

// Cấu hình đầu:  1 2 3 4 5 6
// Câú hình cuối: 6 5 4 3 2 1

/*
Solution:
    Bài này chủ yếu nghĩ phải làm sao để có thể sinh ra được cấu hình tiếp theo từ cấu hình hiện tại thôi:
    - Thuật toán để sinh ra được cấu hình tiếp theo gọi là next permutation:
    B1: Tìm dãy không giảm dài nhất ở hậu tố (từ end về begin)
    B2: Tìm pivot (chính là phần tử đầu tiên từ phải về trái phá vỡ quy luật a[i] > a[i+1])
    B3: Duyệt mảng không giảm, tìm phần tử lớn hơn vừa đủ với pivot
    B4: Đổi pivot và phần tử tìm được
    B5: reverse mảng không giảm ===> nhằm đạt được cấu hình lớn hơn vừa đủ so với cấu hình vừa xét.
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<sstream>

using namespace std;

bool nextPermutation(vector<int>& a) {
    int n = a.size(), i, j;

    // tim mang khong tang suffix
    for (i = n - 2; i >= 0; i--) {
        if (a[i] < a[i + 1]) break;
    }

    // kiem tra xem la cau hinh cuoi chua?
    if (i < 0) {
        return false;
    }
    else {
        for (j = n - 1; j > i; j--) {
            if (a[j] > a[i]) break;
        }
        swap(a[j], a[i]);

        reverse(a.begin() + i + 1, a.end());
    }

    return true;
}

void printConfig(vector<int>& a, vector<string>& names, fstream& out){
    for (auto x:a){
        out << names[x]<< "   ";
    }
    out << endl;
}

int main(){
    fstream inFile("bai_6.inp"), outFile("bai_6.out");

    vector<string> names;
    string line;
    string name;

    while (getline(inFile, line)) {
        istringstream ss(line);
        string name;
        while (ss >> name) {
            names.push_back(name);
        }
    }
    inFile.close();
    sort(names.begin(), names.end());
    vector<int> a(names.size());

    for (int i = 0; i < a.size(); i++) {
        a[i] = i;
    }

    do {
        printConfig(a, names, outFile);
    }
    while (nextPermutation(a));

    outFile.close();

    return 0;
}