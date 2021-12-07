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


#define RB(x) (x<n?r[x]:0)
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

int bin_low(string &p, string &t, vi &sa){
	int lo = 0, hi = sa.size(), mid, idx;
	while(lo+1 < hi){

		mid = (lo+hi)>>1;
		idx = sa[mid];
		string suffix = split(t, idx, len(t));
		if(len(suffix) > len(p)){
			suffix.clear();
			suffix = split(t, idx, idx+len(p));	
		}


		if(suffix <= p) lo = mid;
		else hi = mid;
	}
	return lo;
}

int bin_up(string &p, string &t, vi &sa){
	int lo = -1, hi = sa.size()-1, mid, idx;
	while(lo+1 < hi){

		mid = (lo+hi)>>1;
		idx = sa[mid];
		string suffix = split(t, idx, len(t));
		if(len(suffix) > len(p)){
			suffix.clear();
			suffix = split(t, idx, idx+len(p));	
		}

		if(suffix >= p) hi = mid;
		else lo = mid;
	}
	return hi;
}

vector<int> suffix_array_construction(string s) {
    s += "$";
    vector<int> sorted_shifts = sort_cyclic_shifts(s);
    sorted_shifts.erase(sorted_shifts.begin());
    return sorted_shifts;
}

pair<string,int> solve(string &t){
	vector<int> sa = suffix_array_construction(t);
	vector<int> lcp = lcp_construction(t, sa);
	pair<int,int> maxim = {0,-1};
	int i, n, idx, occurrences = 0;
	string str = "";

	//fore(i, 0, sa.size()) cout << sa[i] << ". "<< split(t, sa[i], len(t)) << endl;

	fore(i, 0, lcp.size())
		if(lcp[i] > maxim.fst)
			maxim = {lcp[i], i};
	 
	idx = sa[maxim.snd];
	n = maxim.fst;
	fore(i, idx, idx+n) str.push_back(t[i]);

	occurrences = bin_low(str, t, sa) - bin_up(str, t, sa)+1;
	return {str, occurrences};

}

int main(){
    int cases, i;
    cin >> cases;
    while(cases--){
        string str;
        cin >> str;
        pair<string, int> ans = solve(str);
		if(ans.fst == "") cout << "No repetitions found!" << endl;
		else cout << ans.fst << " " << ans.snd << endl;
    }
    return 0;
}