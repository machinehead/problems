#include <vector>
#include <string>
#include <functional>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<string> strings = { "abc", "acb", "aaa", "bbb", "aca", "aba", "cba", "bca", "bac", "cab", "baa", "aab", "caa", "aac" };
typedef vector<int> Signature;

namespace std
{
    template<>
    struct hash<Signature>
    {
        typedef Signature argument_type;
        typedef std::size_t result_type;

        hash<int> val_hash_fn;
 
        result_type operator()(argument_type const& s) const
        {
            result_type result = 0;
            int i = 0;
            for (auto v: s) {
                result = result ^ (val_hash_fn(v) << i);
                ++i;
            }
            return result;
        }
    };
}

int main()
{
    unordered_map<Signature, vector<string>> s;
    for (const auto& ss: strings) {
        Signature sig(26, 0);
        for (char c: ss) {
            sig[c - 'a']++;
        }
        auto it = s.find(sig);
        if (it == s.end()) {
            s.emplace(sig, vector<string>({ ss }));
        } else {
            it->second.push_back(ss);
        }
    }
    for (auto& kv: s) {
        sort(kv.second.begin(), kv.second.end());
        for (const auto& ss: kv.second) {
            cout << ss << " ";
        }
        cout << endl;
    }
    return 0;
}