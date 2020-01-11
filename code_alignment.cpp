#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<algorithm>
#include<string>
#include<sstream>
#include<vector>
#define LOCAL
using namespace std;

const int maxline = 1000;

int main() {
  vector<string> all_lines[maxline];

  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  string line;  
  int i = 0;
  //read in each lines
  while (getline(cin, line)) {
    stringstream ss(line);
    string word;
    while (ss >> word) 
      all_lines[i].push_back(word);
    i++;
  }

  vector<string> aligned(i, "");
  int p = 0; 
  size_t total_len = 0, max_len;
  int skips = 0;
  for (;;p++) {
    max_len = 0;
    skips = 0;
    for (int k = 0; k < i; k++) {
      if (all_lines[k].size() < p+1) {
        skips++;
        continue;
      }
      string next_word = all_lines[k][p];

      // set up the padding
      string padding("");
      if (total_len != 0)
        padding.insert(0, total_len - all_lines[k][p-1].length(), ' ');

      aligned[k] += padding + next_word;
      max_len = max(max_len, next_word.length()+1);
    }
    if (skips == i) break;
    total_len = max_len;
  }

  // print out the result
  for (int k = 0; k < i; k++) {
    cout << aligned[k] << "\n";
  }
}
