#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define len(t) t.length()
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;
typedef vector<int> vi;

class RMQ{
public:
    vector<vector<int>> sparse;
    RMQ(vector<int> &arr){
        int n = arr.size(), k = ((int)log2(arr.size()))+1;
        for(int i = 0 ; i < n ; i++) sparse.push_back(vector<int>(k,0));

        for (int i = 0; i < n; i++) sparse[i][0] = arr[i];

        for (int j = 1; (1 << j) <= n; j++) {
            for (int i = 0; (i + (1 << j) - 1) < n; i++) {
                if (sparse[i][j - 1] < sparse[i + (1 << (j - 1))][j - 1])
                    sparse[i][j] = sparse[i][j - 1];
                else
                    sparse[i][j] = sparse[i + (1 << (j - 1))][j - 1];
            }
        }
    }

    int query(int L, int R){
        int j = (int)log2(R - L + 1);
        if (sparse[L][j] <= sparse[R - (1 << j) + 1][j]) return sparse[L][j];
        else return sparse[R - (1 << j) + 1][j];
    }
};


vector<int> sort_cyclic_shifts(string const& s) {
    int n = s.size();
    const int alphabet = 256;
	vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i-1];
    for (int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i-1]])
            classes++;
        c[p[i]] = classes - 1;
    }
	vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}

vector<int> suffix_array_construction(string s) {
    s += "$";
    vector<int> sorted_shifts = sort_cyclic_shifts(s);
    sorted_shifts.erase(sorted_shifts.begin());
    return sorted_shifts;
}

vector<int> lcp_construction(string const& s, vector<int> const& p) {
    int n = s.size();
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++)
        rank[p[i]] = i;
    int k = 0;
    vector<int> lcp(n-1, 0);
    for (int i = 0; i < n; i++) {
        if (rank[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = p[rank[i] + 1];
        while (i + k < n && j + k < n && s[i+k] == s[j+k])
            k++;
        lcp[rank[i]] = k;
        if (k)
            k--;
    }
    return lcp;
}

string split(string &t, int lo, int hi){
	string ans = "";
	fore(i, lo, hi) ans.pb(t[i]);
	return ans;
}

pair<int,vi> lcs(string &t, vi &color, int n){
    vi sa = suffix_array_construction(t), lcp = lcp_construction(t, sa), indexes;
    RMQ rmq = RMQ(lcp);
    map<int,int> colorCnt; 
    int lo = n, hi = n, ans = 0, k = (n/2)+1, colors = 0, lcs_; //[lo,hi]
    fore(i, 0, sa.size()){ 
        if(i < sa.size()-1) cout << lcp[i] << " -> ";
        cout << sa[i] << ". "<< split(t, sa[i], len(t)) << ", color = " << color[sa[i]] << endl;
    }

    fore(hi, n, sa.size()){
        if(colorCnt[color[sa[hi]]] == 0) colors++;
        colorCnt[color[sa[hi]]]++;

        while(colors >= k and lo != hi){
            lcs_ = rmq.query(lo, hi-1);
            if(lcs_ == ans and lcs_ != 0) indexes.pb(sa[lo]);
            else if(lcs_ > ans){
                ans = lcs_;
                indexes.clear();
                indexes.pb(sa[lo]);
            }
            colorCnt[color[sa[lo]]]--;
            if(colorCnt[color[sa[lo]]] == 0) colors--;
            lo++;
        }
    }
    return {ans, indexes};
}


int main(){
    int n, first = 1;
    while(1){
        cin >> n;
        if(n == 0) break;
        if(n == 1){
            string t;
            cin >> t;
            cout << t << endl;
            continue;
        }
        string t;
        vi color;
        fore(i, 0, n){
            string temp;
            cin >> temp;
            fore(j, 0, len(temp)){ t.pb(temp[j]);color.pb(i);}
            t.pb('$'); color.pb(i);
        }
        /*
        fore(i, 0, color.size()) cout << color[i] << " ";
        cout << endl;
        */

        pair<int,vi> answers = lcs(t, color, n);
        if(not first) cout << "\n";
        first = 0;
        if(answers.fst == 0) cout << "?" << endl;
        else{
            set<string> ans;
            fore(i, 0, answers.snd.size()){
                ans.insert(split(t, answers.snd[i], answers.snd[i]+answers.fst));
            }
            set<string>::iterator it = ans.begin();
                for(it ; it != ans.end() ; it++) cout << *it << endl;
        }
    }

    return 0;
}