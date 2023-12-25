// Lấy danh sách tên từ file bai_4.inp. Liệt kê tất cả các cách chọn ra đúng k người trong số n người đó, k là nhập vào

/*
Giải pháp:
    - Hãy xem như là đang sinh ra 1 mảng gồm chập k của n số, với n bắt đầu có thể là 0, 1, 2, 3, ..., n - 1
    - Mapping tên trong mảng và value trong mảng được sinh ( value này dùng làm index trong mảng chứa tên)
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<sstream>

using namespace std;

void printConfig(vector<string>& names, vector<int>& position, fstream& out) {
    for (int i = 0; i < position.size(); i++) {
        out << names[position[i]] << " ";
    }
    out << endl;
}

void sinhToHop(vector<string>& names, int k, fstream& output){
    int n = names.size() - 1;
    // cau hinh dau tien
    vector<int> position(k);
    for (int i = 0; i < position.size(); i++) {
        position[i] = i;
    }

    int i = k - 1;
    do {
        i = k - 1;
        printConfig(names, position, output);
        while ( i >= 0 && position[i] == n - k + i + 1) i--;
        position[i] = position[i] + 1;
        for (int j = i + 1; j < k; j++) {
            position[j] = position[j - 1] + 1;
        }
    } while ( i >= 0);


}

int main() {
    fstream inFile("bai_4.inp"), outFile("bai_4.out");
    int k;
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
    cout<<names.size();
    inFile.close();

    cout << "Nhập số k bạn muốn: (Nhỏ hơn " << names.size() << " )"<<endl;
    cin >> k;

    sort(names.begin(), names.end());

    sinhToHop(names, k, outFile);
    outFile.close();

    return 0;
}