#include <bits/stdc++.h>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = NULL;
    }
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};


void generate(Node* root, string code, map<char, string>& codes) {
    if (!root) return;


    if (!root->left && !root->right) {
        codes[root->ch] = code;
        return;
    }

    generate(root->left, code + "0", codes);
    generate(root->right, code + "1", codes);
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;


    map<char, int> freq;
    for (char c : s) freq[c]++;


    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (auto it : freq)
        pq.push(new Node(it.first, it.second));

    while (pq.size() > 1) {
        Node* a = pq.top(); pq.pop();
        Node* b = pq.top(); pq.pop();

        Node* merged = new Node('\0', a->freq + b->freq);
        merged->left = a;
        merged->right = b;

        pq.push(merged);
    }

    Node* root = pq.top();

    map<char, string> codes;
    generate(root, "", codes);

    cout << "\nHuffman Codes:\n";
    for (auto it : codes)
        cout << it.first << " : " << it.second << endl;

    string encoded = "";
    for (char c : s)
        encoded += codes[c];

    cout << "\nEncoded string: " << encoded << endl;

    return 0;
}

