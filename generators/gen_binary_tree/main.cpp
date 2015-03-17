/*
Input: argv[1] = N, number of nodes

Outputs a binary tree in the following format:
N - number of nodes
a b: N times, edge from a to b

1 <= a, b <= N
Node 1 is the root of the tree.
*/

#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    if (argc < 2) {
        cerr << "Number of vertices should be provided as a command line argument." << endl;
        return 1;
    }
    int N = atoi(argv[1]);
    cout << N << endl;
    for (int i = 2; i <= N; ++i) {
        cout << i / 2 << " " << i << endl;
    }
    return 0;
}
