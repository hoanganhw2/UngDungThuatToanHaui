#include <bits/stdc++.h>
using namespace std;
/*
Bài 4: Chiến lược quy hoạch động
Input:
- Cho một chiếc túi có kích thước s và một danh sách d gồm n chiếc điện thoại khác 
nhau, thông tin về mỗi điện thoại gồm nhãn hiệu, kích thước và giá bán.
Output:
- Tính x và a lần lượt là số lượng và danh sách những chiếc điện thoại trong danh sách 
d cần đưa vào chiếc túi để để được tổng giá bán lớn nhất mà không vượt quá kích thước 
s của chiếc túi.
Yêu cầu thực hiện
- Thiết kế thuật toán Q1 để tính và trả về x và a.
- Viết chương trình thực hiện:
- Khởi tạo n và danh sách d (5 ≤ n ≤ 10).
- Cài đặt hàm biểu diễn thuật toán Q1.
- Sử dụng thuật toán Q1 để tính và trả về x và a. Hiển thị kết quả (mỗi điện thoại hiển 
thị nhãn hiệu, giá bán).
*/
struct phone {
    string name;
    int size;
    int price;
    phone() : name(""), size(0), price(0) {}
    phone(string name, int size, int price) {
        this->name = name;
        this->size = size;
        this->price = price;
    }
};

void showTitle() {
    cout << setw(15) << "ten hang";
    cout << setw(15) << "kich thuoc";
    cout << setw(15) << "gia ban";
    cout << endl;
}

void showData(phone p) {
    cout << setw(15) << p.name;
    cout << setw(15) << p.size;
    cout << setw(15) << p.price;
    cout << endl;
}

void taoDs(vector<phone>& p) {
    phone p1("nokia", 21, 1200000); p.push_back(p1);
    phone p2("apple", 10, 1000000); p.push_back(p2);
    phone p3("samsung", 6, 950000); p.push_back(p3);
    phone p4("lg", 14, 650000); p.push_back(p4);
    phone p5("xiaomi", 8, 890000); p.push_back(p5);
}

void showDs(vector<phone> p) {
    showTitle();
    for (phone x : p) {
        showData(x);
    }
}

int Q1(vector<phone> p, int k, vector<vector<int>>& dp) {
    int n = p.size();
    for (int i = 0; i <= k; i++) dp[0][i] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j] = dp[i - 1][j]; 
            if (j >= p[i-1].size) {
                int tam = p[i-1].price + dp[i - 1][j - p[i-1].size];
                if (tam > dp[i][j]) {
                    dp[i][j] = tam; 
                }
            }
        }
    }
    return dp[n][k];
}

void result1(vector<phone> p, vector<phone>& result, vector<vector<int>> dp, int k) {
    int i = p.size();
    int j = k;
    while (i != 0) {
        if (dp[i][j] != dp[i - 1][j]) {
            result.push_back(p[i - 1]);
            j = j - p[i - 1].size;
        }
        i--;
    }
}

int main() {
    vector<phone> p, result;
    taoDs(p);
    showDs(p);
    int k, n = 5;
    cout << "nhap kich thuoc cua cai tui: ";
    cin >> k;
    vector<vector<int>> dp(n + 1, vector<int>(k + 1));
    cout  << Q1(p, k, dp) << endl;
    result1(p, result, dp, k);
    cout << "|-------------------------------|" << endl;
    showDs(result);
    return 0;
}

