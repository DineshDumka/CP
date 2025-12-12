struct segtree{
    int n;
    vector<int>seg;

    segtree(int n){
        this->n = n;
        seg.assign(4*n , 0);
    }

    int combine(int a, int b){
        return a + b;
    }

    void build(vector<int>&a , int ind , int l, int r){
        if(l==r){
            seg[ind] = a[l];
            return;
        }
        int mid = (l+r)/2;
        build(a, ind*2, l, mid);
        build(a, ind*2 + 1,mid + 1 , r);

        seg[ind] = combine(seg[ind*2] , seg[ind*2 + 1]);
    }

    void update(int pos, int val, int ind,  int l , int r){
        if(l==r ){
            seg[ind] = val;
            return;
        }
        int mid = (l+r)/2;
        if(pos <= mid) update(pos, val , ind*2, l , mid);
        else update(pos, val , ind*2 + 1,mid+1, r);

        seg[ind] = combine(seg[ind*2] , seg[ind*2 + 1]);
    }

    int query(int ind, int l, int r, int ql, int qr){
        if(qr < l || r < ql) return 0;
        if(l>=ql && r<=qr) return seg[ind];

        int mid = (l+r)/2;
        int left = query(ind*2, l ,mid , ql , qr);
        int right = query(ind*2 + 1,mid+1 ,r,  ql , qr);
        return combine(left , right);
    }
};
