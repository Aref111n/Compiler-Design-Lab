#include<bits/stdc++.h>
using namespace std;

vector<string>state, symbol ;
map<pair<string, char>, string> mp ;
map<string, int> f;

bool traverse(string state, string t, int pos, int len) {

    if(pos==len)
        return f[state];

    bool ac = 0;

    if(mp[{state, t[pos]}].size())
        ac = traverse(mp[{state, t[pos]}], t, pos+1, len) ;

    return ac ;
}

int main() {
    int n, m, q, x;

    cin >> n ;
    for(int i=0; i<n; i++) {
        string t ;
        cin >> t ;
        state.push_back(t) ;
        f[t]=0;
    }

    f[state[n-1]]=1 ;

    cin >> m ;
    for(int i=0; i<m; i++) {
        string t ;
        cin >> t ;
        symbol.push_back(t) ;
    }

    cin >> q ;
    for(int i=0; i<q; i++) {
        string a, b ;
        char ch ;
        cin >> a >> ch >> b ;
        mp[{a, ch}] = b ;
    }

    cin >> x ;
    for(int i=0; i<x; i++) {
        string v ;
        cin >> v ;
        int len = v.size() ;
        if(traverse(state[0], v, 0, v.size()))
            cout << "Accepted" << endl ;
        else
            cout << "Rejected" << endl ;
    }
}
