/*
Write a maxDepth function to find maximum depth of a binary tree. What is the time and space complexity of your function. 

Given:


class Tree
{
    public Tree left;
    public Tree right;
}

int maxDepth(Tree head) {}
*/

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <unordered_set>

using namespace std;

// struct BinaryTreeNode {
//     typedef vector<BinaryTreeNode> Vector;

//     BinaryTreeNode()
//         : Left( 0 )
//         , Right( 0 )
//         , Parent( 0 )
//     {}

//     int Left;
//     int Right;
// };

int main()
{
    int N;
    cin >> N;
    // BinaryTreeNode::Vector(N + 1, 0);
    vector<list<int>> edgeList(N + 1, list<int>());

    while (--N) { // n-1 edges
        int a, b;
        cin >> a >> b;
        edgeList[a].push_back(b);
        edgeList[b].push_back(a);
    }

    deque<int> queue;
    unordered_set<int> visited;

    queue.push_back(1);
    queue.push_back(0);
    visited.insert(1);

    int depth = 0;

    while (!queue.empty()) {
        int cur = queue.front();
        queue.pop_front();
        if (cur == 0) {
            ++depth;
            if (!queue.empty())
                queue.push_back(0);
            continue;
        }
        visited.insert(cur);
        for (int v: edgeList[cur]) {
            if (visited.find(v) == visited.end())
                queue.push_back(v);
        }
    }
    cout << depth << endl;
    return 0;
}
