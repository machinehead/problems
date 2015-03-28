#include <vector>
#include <iostream>

using namespace std;

typedef vector<int> IV;

IV sum_int(IV a, const IV& b)
{
    int carry = 0;
    int i = 0;
    for (; i < b.size(); ++i) {
        int t = a[a.size() - i - 1] + b[b.size() - i - 1] + carry;
        a[a.size() - i - 1] = t % 10;
        carry = t / 10;
    }
    while (carry && i < a.size()) {
        int t = a[a.size() - i - 1] + carry;
        a[a.size() - i - 1] = t % 10;
        carry = t / 10;
        ++i;
    }
    if (carry) {
        a.insert(a.begin(), carry);
    }
    return a;
}

IV sum(const IV& a, const IV& b)
{
    if(a.size() >= b.size()) {
        return sum_int(a, b);
    } else {
        return sum_int(b, a);
    }
}

IV as_vec(int a)
{
    IV result;
    for (auto c: to_string(a)) {
        result.push_back(c - '0');
    }
    return result;
}

template<class T>
ostream& operator<<(ostream& os, const vector<T>& vec)
{
    for(auto v: vec) {
        os << v << " ";
    }
    os << endl;
    return os;
}

int main() 
{
    for (int i = 0; i < 1000; ++i) {
        for (int j = 0; j < 1000; ++j) {
            IV a = as_vec(i);
            IV b = as_vec(j);
            IV c = sum(a, b);
            cout << a << b << c << endl;
        }
    }
    return 0;
}