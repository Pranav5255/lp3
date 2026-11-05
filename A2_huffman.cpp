#include <bits/stdc++.h>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f, Node *l = nullptr, Node *r = nullptr) {
        ch = c; freq = f; left = l; right = r;
    }
};

// Min-heap: smallest frequency on top
struct Compare {
    bool operator()(Node *a, Node *b) {
        return a->freq > b->freq;
    }
};

// Go left = add "0", go right = add "1"
void printCodes(Node *root, string code) {
    if (root == nullptr)
        return;
    if (root->left == nullptr && root->right == nullptr) {   // leaf node
        cout << root->ch << " : " << (code == "" ? "0" : code) << "\n";
        return;
    }
    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

int main() {
    string text;
    cout << "Enter text: ";
    cin >> text;

    // 1. Count frequency of each character
    map<char, int> freq;
    for (char c : text)
        freq[c]++;

    // 2. Put every character in the min-heap
    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (auto p : freq)
        pq.push(new Node(p.first, p.second));

    // 3. Greedy step: repeatedly merge the two smallest nodes
    while (pq.size() > 1) {
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top(); pq.pop();
        pq.push(new Node('$', left->freq + right->freq, left, right));
    }

    // 4. Remaining node is the root of the Huffman tree
    cout << "Huffman Codes:\n";
    printCodes(pq.top(), "");
}
// Time complexity: O(n log n)
