#include <bits/stdc++.h>
using namespace std;

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
            dp[i][j] = dp[i - 1][j]; // Assume not taking item i-1
            if (j >= p[i-1].size) {
                int tam = p[i-1].price + dp[i - 1][j - p[i-1].size];
                if (tam > dp[i][j]) {
                    dp[i][j] = tam; // Take item i-1
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
    cout << "Maximum price: " << Q1(p, k, dp) << endl;
    result1(p, result, dp, k);
    cout << "Selected phones:" << endl;
    showDs(result);
    return 0;
}

