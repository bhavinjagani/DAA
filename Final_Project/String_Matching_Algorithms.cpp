#include <iostream>
#include <vector>
#include <string>
#include <chrono> 

using namespace std;

vector<int> naiveStringMatch(const string &text, const string &pattern) {
    int n = text.length();
    int m = pattern.length();
    vector<int> matches;

    for (int i = 0; i <= n - m; i++) {
        bool match = true;
        for (int j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            matches.push_back(i);
        }
    }

    return matches;
}
long long computeHash(const string &str, int base, int mod) {
    long long hash = 0;
    for (char c : str) {
        hash = (hash * base + c) % mod;
    }
    return hash;
}

vector<int> rabinKarp(const string &text, const string &pattern, int base = 256, int mod = 101) {
    int n = text.length();
    int m = pattern.length();
    vector<int> result;

    if (m > n) return result; 

    long long patternHash = computeHash(pattern, base, mod);
    long long currentHash = computeHash(text.substr(0, m), base, mod);

    long long highestBase = 1;
    for (int i = 0; i < m - 1; i++) {
        highestBase = (highestBase * base) % mod;
    }

    for (int i = 0; i <= n - m; i++) {
 
        if (patternHash == currentHash) {
            if (text.substr(i, m) == pattern) {
                result.push_back(i);
            }
        }

      
        if (i < n - m) {
            currentHash = (currentHash - text[i] * highestBase) % mod; 
            currentHash = (currentHash * base + text[i + m]) % mod;    
            if (currentHash < 0) currentHash += mod;                  
        }
    }
    return result;
}

vector<vector<int>> buildTransitionTable(const string &pattern, const string &alphabet) {
    int m = pattern.length();
    vector<vector<int>> transitionTable(m + 1, vector<int>(alphabet.size(), 0));

    for (int state = 0; state <= m; state++) {
        for (size_t i = 0; i < alphabet.size(); i++) {
            char currentChar = alphabet[i];
            if (state < m && pattern[state] == currentChar) {
                transitionTable[state][i] = state + 1;
            } else {
                string prefix = pattern.substr(0, state) + currentChar;
                for (int ns = min(m, state + 1); ns > 0; ns--) {
                    if (prefix.substr(prefix.size() - ns) == pattern.substr(0, ns)) {
                        transitionTable[state][i] = ns;
                        break;
                    }
                }
            }
        }
    }
    return transitionTable;
}

vector<int> finiteAutomataMatch(const string &text, const string &pattern, const string &alphabet) {
    int n = text.length();
    int m = pattern.length();
    vector<int> matches;

    vector<vector<int>> transitionTable = buildTransitionTable(pattern, alphabet);

    int state = 0;
    for (int i = 0; i < n; i++) {
        size_t charIndex = alphabet.find(text[i]);
        if (charIndex != string::npos) {
            state = transitionTable[state][charIndex];
            if (state == m) {
                matches.push_back(i - m + 1);
            }
        } else {
            state = 0; 
        }
    }

    return matches;
}
vector<int> buildLPS(const string &pattern) {
    int m = pattern.length();
    vector<int> lps(m, 0);
    int length = 0; 
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}
vector<int> knuthMorrisPratt(const string &text, const string &pattern) {
    int n = text.length();
    int m = pattern.length();
    vector<int> lps = buildLPS(pattern); 
    vector<int> matches;

    int i = 0;
    int j = 0; 

    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == m) {
            matches.push_back(i - j); 
            j = lps[j - 1]; 
        } else if (i < n && text[i] != pattern[j]) {
            if (j != 0) {
                j = lps[j - 1]; 
            } else {
                i++;
            }
        }
    }

    return matches;
}
void benchmark(const string &text, const string &pattern,int Algo) {
   switch (Algo)
   {
   case 1:
   {
    auto start1 = chrono::high_resolution_clock::now(); 
    naiveStringMatch(text, pattern);
    auto end1 = chrono::high_resolution_clock::now(); 
    chrono::duration<double> elapsed1 = end1 - start1;
    cout << "Time taken: " << elapsed1.count() << " seconds" << endl;
    break;
   }
   case 2:
   {
    auto start2 = chrono::high_resolution_clock::now(); 
    rabinKarp(text, pattern);
    auto end2 = chrono::high_resolution_clock::now(); 
    chrono::duration<double> elapsed2 = end2 - start2;
    cout << "Time taken: " << elapsed2.count() << " seconds" << endl;
    break;
   }
   case 3:
   {
    string alphabet = "ab";
    auto start3 = chrono::high_resolution_clock::now(); 
    finiteAutomataMatch(text, pattern,alphabet);
    auto end3 = chrono::high_resolution_clock::now(); 
    chrono::duration<double> elapsed3 = end3 - start3;
    cout << "Time taken: " << elapsed3.count() << " seconds" << endl;
    break;
    }
    case 4:
   {
    auto start2 = chrono::high_resolution_clock::now(); 
    knuthMorrisPratt(text, pattern);
    auto end2 = chrono::high_resolution_clock::now(); 
    chrono::duration<double> elapsed2 = end2 - start2;
    cout << "Time taken: " << elapsed2.count() << " seconds" << endl;
    break;
   }
   }
    
}

int main() {

    string text = string(100000, 'a') + "b";
    string pattern = string(1000, 'a');    
    cout<<"------------------100k Character String---------------------"<<endl;
    cout << "Naïve_String_Matching_Algorithm:" << endl;
    benchmark(text, pattern,1);

    cout << "Rabin-Karp_Algorithm:" << endl;
    benchmark(text, pattern,2);

    cout << "Finite automata:" << endl;
    benchmark(text, pattern,3);

    cout << "KnuthMorrisPratt:" << endl;
    benchmark(text, pattern,4);

    text = string(100, 'a');
    pattern = "aaaaa";
cout<<"------------------100 Character String---------------------"<<endl;
    cout << "Naïve_String_Matching_Algorithm:" << endl;
    benchmark(text, pattern,1);

    cout << "Rabin-Karp_Algorithm:" << endl;
    benchmark(text, pattern,2);

    cout << "Finite automata:" << endl;
    benchmark(text, pattern,3);

    cout << "KnuthMorrisPratt:" << endl;
    benchmark(text, pattern,4);

    text = "xydcbaabbxyzabbabcxyeqweasdzxxweertvczxqw";
    pattern = "abbab";

    cout<<"------------------Random Character String---------------------"<<endl;
    
    cout << "Naïve_String_Matching_Algorithm:" << endl;
    benchmark(text, pattern,1);

    cout << "Rabin-Karp_Algorithm:" << endl;
    benchmark(text, pattern,2);

    cout << "Finite automata:" << endl;
    benchmark(text, pattern,3);

    cout << "KnuthMorrisPratt:" << endl;
    benchmark(text, pattern,4);

    return 0;
}
