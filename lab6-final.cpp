#include<bits/stdc++.h>
using namespace std;

string start, terminal ;
map<pair<string, char>, vector<string>> mp ;
map<string, int> f;

bool traverse(string state, string t, int pos, int len) {
    if(pos==len)
        return state==terminal;

    bool ac = 0;

    if(mp[{state, t[pos]}].size()) {
        for(auto it: mp[{state, t[pos]}]) {
            ac = traverse(it, t, pos+1, len) ;
            if(ac==1)
                break;
        }
    }

    if(ac==0) {
        if(mp[{state, 'e'}].size()) {
            for(auto it: mp[{state, 'e'}]) {
                ac = traverse(it, t, pos, len) ;
                if(ac==1)
                    break;
            }
        }
    }

    return ac ;
}

int main() {
    cin >> start ;
    cin >> terminal ;

    int q;
    cin >> q ;
    for(int i=0; i<q; i++) {
        string a, b ;
        char ch ;
        cin >> a >> ch >> b ;
        mp[{a, ch}].push_back(b) ;
    }

    int x ;
    cin >> x ;
    for(int i=0; i<x; i++) {
        string v ;
        cin >> v ;
        int len = v.size() ;
        if(traverse(start, v, 0, v.size()))
            cout << "Accepted" << endl ;
        else
            cout << "Rejected" << endl ;
    }
}

