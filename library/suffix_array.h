class SuffixArray {
public:
    struct Entry {
        int nr[2], p;
        
        bool operator<(const Entry& o) {
            return nr[0] == o.nr[0] ? (nr[1] < o.nr[1]) : (nr[0] < o.nr[0]);
        }
    };
    
    vector<int> P; // P[i] - rank of ith suffix
    vector<int> I; // I[i] - origin of suffix with ith rank
    vector<int> LCP; // LCP[i] - lcp bw suffixes with ranks i, i+1
    
    SuffixArray(const string& s) 
        : P(s.size(), 0)
    {
        vector<Entry> L(s.size());
        vector<int> Pn(s.size(), 0);
            
        for (int i = 0; i < s.size(); ++i)
            P[i] = s[i] - 'A';
            
        int stp = 1;
        for (int cnt = 1; cnt >> 1 < s.size(); ++stp, cnt <<= 1)
        {
            vector<int>& Pcur = (stp % 2 == 1) ? Pn : P;
            vector<int>& Pprev = (stp % 2 == 1) ? P : Pn;
            
            for (int i = 0; i < s.size(); ++i) {
                L[i].nr[0] = Pprev[i];
                L[i].nr[1] = i + cnt < s.size() ? Pprev[i + cnt] : -1;
                L[i].p = i;
            }
            sort(L.begin(), L.end());
            for (int i = 0; i < s.size(); ++i)
                Pcur[L[i].p] = i > 0 && L[i].nr[0] == L[i - 1].nr[0] && L[i].nr[1] == L[i - 1].nr[1] ?
                    Pcur[L[i - 1].p] : i;
        }
            
        if (stp % 2 == 0) {
            copy(Pn.begin(), Pn.end(), P.begin());
        }

        I.resize(L.size());
        transform(L.begin(), L.end(), I.begin(), [](const Entry& e) { return e.p; });
            
        LCP.resize(P.size(), 0);
        int lcp = 0;
        for (int i = 0; i < P.size(); ++i) {
            if (P[i] == P.size() - 1) {
                continue;
            }
            for (int x = i + lcp, y = I[P[i] + 1] + lcp; x < P.size() && y < P.size() && s[x] == s[y]; ++x, ++y, ++lcp) {
            }
            LCP[P[i]] = lcp;
            lcp = max(lcp - 1, 0);
        }
    }
};
