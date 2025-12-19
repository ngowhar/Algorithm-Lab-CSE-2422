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

map<char, int> freqMap;
map<char, string> codeMap;

void generateCodes(Node* root, string code) {
    if (!root) return;

    if (root->ch != '$') {
        codeMap[root->ch] = code;
        cout << root->ch << " : " << code << endl;
    }

    generateCodes(root->left, code + "0");
    generateCodes(root->right, code + "1");
}

int main() {
    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    priority_queue<Node*, vector<Node*>, Compare> pq;

    for (int i = 0; i < n; i++) {
        char ch;
        int freq;
        cout << "Enter character and frequency: ";
        cin >> ch >> freq;

        freqMap[ch] = freq;
        pq.push(new Node(ch, freq));
    }

    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* newNode = new Node('$', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    cout << "\nHuffman Codes:\n";
    generateCodes(pq.top(), "");

    int totalFixedBits = 0;
    int totalHuffmanBits = 0;

    int fixedBitsPerChar = ceil(log2(n));

    for (auto it : freqMap) {
        char ch = it.first;
        int freq = it.second;

        totalFixedBits += freq * fixedBitsPerChar;
        totalHuffmanBits += freq * codeMap[ch].length();
    }

    cout << "\nFixed length bits per character = "
         << fixedBitsPerChar << endl;

    cout << "Total bits needed (Fixed Length Coding) = "
         << totalFixedBits << endl;

    cout << "Total bits used (Huffman Coding) = "
         << totalHuffmanBits << endl;

    cout << "Total bits reduced = "
         << totalFixedBits - totalHuffmanBits << endl;

    return 0;
}




