/*
Input: 
 * argv[1] = N, number of integers
 * argv[2] = m, minimal value
 * argv[3] = M, maximal value

Outputs a random integer list:
N - number of integers
i1 i2 i3 ... iN - N random integers

m <= ik <= M
*/

#include <iostream>
#include <random>

using namespace std;

int main(int argc, char* argv[])
{
    if (argc < 4) {
        cerr << "Number of integers and min/max values should be provided as command line arguments." << endl;
        return 1;
    }
    const int N = atoi(argv[1]);
    const int m = atoi(argv[2]);
    const int M = atoi(argv[3]);

    cout << N << endl;

    std::mt19937 gen;
    std::uniform_int_distribution<int> dist(m, M);

    for (int n = 0; n < N; ++n) {
        cout << dist(gen);
        if (n < N - 1) {
            cout << " ";
        }
    }
    cout << endl;
    return 0;
}
