#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAXN = 2e7;

struct ist {
    int cnt;
    struct ist *lChild, *rChild;
    int sm;
    int leftmost, rightmost;
    bool propagated;
    ist(int left, int right) {
        leftmost = left;
        rightmost = right;
        propagated=false;
        recalc();
    }
    void recalc() {
        if(!propagated)
            sm=0;
        else
            sm=lChild->sm+rChild->sm;
    }
    
    void makekids() {
        int mid=(leftmost+rightmost)/2;
        if(propagated)
            return;
        propagated=true;
        lChild=new ist(leftmost, mid);
        rChild= new ist(mid + 1, rightmost);
    }
    
    void upd(int pos) {
        
        if(leftmost==rightmost) {
            sm=1;
            return;
        }
        makekids();
        if(pos<=lChild->rightmost)
            lChild->upd(pos);
        else
            rChild->upd(pos);
        recalc();
    }
    int qry(int l, int r) {
        if(l>rightmost||r<leftmost)
            return 0;
        else if(l <= leftmost && r >= rightmost)
            return sm;
        makekids();
        return lChild->qry(l,r)+rChild->qry(l,r);
    }
};
int main() {
    ist segtree(1,int(1e9));
    cout << segtree.qry(1, 5) << "\n";
    segtree.upd(3);
    cout << segtree.qry(1, 5) << "\n";
    segtree.upd(17);
    cout << segtree.qry(1, 5) << "\n";
    cout << segtree.qry(1, 20) << "\n";
    segtree.upd(349275256);
    cout << segtree.qry(1, int(1e9)) << "\n";
    cout << segtree.qry(1, int(1e2)) << "\n";
}