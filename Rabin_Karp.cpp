#include <bits/stdc++.h>
using namespace std;

int main() {
    string text, pattern;
    cout << "Enter text: ";
    getline(cin, text);
    cout << "Enter pattern: ";
    getline(cin, pattern);

    int n = text.size();
    int m = pattern.size();

    int base = 256;
    int mod  = 101;

    int pHash = 0;
    int tHash = 0;
    int h = 1;

    for (int i = 0; i < m - 1; i++)
        h = (h * base) % mod;

    for (int i = 0; i < m; i++) {
        pHash = (base * pHash + pattern[i]) % mod;
        tHash = (base * tHash + text[i]) % mod;
    }

    for (int i = 0; i <= n - m; i++) {

        if (pHash == tHash) {
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match) cout << "Pattern found at index " << i << endl;
        }

        if (i < n - m) {
            tHash = (base * (tHash - text[i] * h) + text[i + 1 + m - 1]) % mod;

            if (tHash < 0) tHash += mod;
        }
    }

    return 0;
}
