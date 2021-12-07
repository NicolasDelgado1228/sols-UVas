#include <bits/stdc++.h>
using namespace std;


struct SuffixAutomaton {
  vector<map<char,int>> edges; // edges[i]  : the labeled edges from node i
  vector<int> link;            // link[i]   : the parent of i
  vector<int> length;          // length[i] : the length of the longest string in the ith class
  int last;                    // the index of the equivalence class of the whole string


  SuffixAutomaton(string &s) {
    // add the initial node
    edges.push_back(map<char,int>());
    link.push_back(-1);
    length.push_back(0);
    last = 0;

    for(int i=0;i<s.size();i++) {
      // construct r
      edges.push_back(map<char,int>());
      length.push_back(i+1);
      link.push_back(0);
      int r = edges.size() - 1;

      // add edges to r and find p with link to q
      int p = last;
      while(p >= 0 && edges[p].find(s[i]) == edges[p].end()) {
        edges[p][s[i]] = r;
        p = link[p];
      }
      if(p != -1) {
        int q = edges[p][s[i]];
        if(length[p] + 1 == length[q]) {
          // we do not have to split q, just set the correct suffix link
          link[r] = q;
        } else {
          // we have to split, add q'
          edges.push_back(edges[q]); // copy edges of q
          length.push_back(length[p] + 1);
          link.push_back(link[q]); // copy parent of q
          int qq = edges.size()-1;
          // add qq as the new parent of q and r
          link[q] = qq;
          link[r] = qq;
          // move short classes pointing to q to point to q'
          while(p >= 0 && edges[p][s[i]] == q) {
            edges[p][s[i]] = qq;
            p = link[p];
          }
        }
      }
      last = r;
    }
  }
};

void rev(string &str){ reverse(str.begin(), str.end());}

int match

int solve(vector<string> &strings){
    int i, n = string.size(), ans, len = strings[0].length();
    ans = n*len;
    for(i = 0 ; i < n-1 ; i++){
        string str = strings[i]; rev(str);
        SuffixAutomaton sa = SuffixAutomaton(str);

    }
}

int main(){
    int i, len, n, cases;
    cin >> cases;
    while(cases--){
        cin >> len >> n;
        vector<int> strs;
        for(i = 0 ; i < n ; i++){
            string inp;
            cin >> inp;
            strs.push_back(inp);
        }
    }
    return 0;
}
