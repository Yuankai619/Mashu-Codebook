#include <iostream>
#include <chrono>
#include <random>
#include <unordered_map>
#include <ctime>

// 使用到的內建函式宣告
// #include <x86intrin.h> // 這個頭檔案可能在某些系統中需要用來使用 __builtin_* 函式

using namespace std;

// 定義隨機數生成器
mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());

// 隨機數生成函式
int randint(int lb, int ub) {
    return uniform_int_distribution<int>(lb, ub)(gen);
}

// 計時器宏
// #define SECs ((double)clock().count())

// 自訂哈希函式的結構體
struct Type{
    int x;
    string y;
    bool operator==(const Type &other) const {
        return (x == other.x && y == other.y);
    }
};
struct hashs{
    size_t operator()(const Type &o) const {
        return ((hash<int>()(o.x)^(hash<string>()(o.y)<<1))>>1);
    }
};
// 測試函式
void test_misc() {
    vector<int> vec(10);
    iota(vec.begin(), vec.end(), 4
    );
    cout << "iota 函式測試: ";
    for (int i : vec) cout << i << " ";
    // 測試隨機數生成
    int lb = 1, ub = 10;
    cout << "隨機數生成（範圍 " << lb << " 到 " << ub << "）: " << randint(lb, ub) << endl;

    // 測試計時器
    // double start_time = SECs;
    // int a=0;
    // for (int i = 0; i < 1000000000; ++i)
    //     a+=randint(0,100)%INT16_MAX;// 模擬一些運算
    // double end_time = SECs;
    // cout << "運算時間: " << (end_time - start_time) << " 秒" << endl;

    // 測試自訂哈希函式
    unordered_map<Type,int,hashs> mapa;
    Type key1 = (Type){1, "2"};
    Type key2 = (Type){3, "4"};
    mapa[key1] = 100;
    mapa[key2] = 200;
    cout << "Key (1,2) 的值: " << mapa[key1] << endl;
    cout << "Key (3,4) 的值: " << mapa[key2] << endl;

    // 測試內建函式
    long long x = 0b101111; // 45
    cout << "__builtin_popcountll: " << __builtin_popcountll(x) << " (二進位有 " << __builtin_popcountll(x) << " 個 1)" << endl;
    cout << "__builtin_clzll: " << __builtin_clzll(x) << " (左起第一個 1 前面有 " << __builtin_clzll(x) << " 個 0)" << endl;
    cout << "__builtin_parityll: " << __builtin_parityll(x) << " (1 的個數的奇偶性: " << (__builtin_parityll(x) ? "奇數" : "偶數") << ")" << endl;

    long long a = 1000000000000;
    long long b = 100000000000000000;
    long long result;
    bool overflow = __builtin_mul_overflow(a, b, &result);
    cout << "乘法溢位測試: " << (overflow ? "溢位發生" : "沒有溢位") << ", 結果: " << result << endl;
}

int main() {
    test_misc();
    return 0;
}
