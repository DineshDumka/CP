// 1-indexed Fenwick Tree
struct Fenwick {
    int n;
    vector<long long> bit;

    Fenwick(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    // add val to index i
    void update(int i, long long val) {
        while (i <= n) {
            bit[i] += val;
            i += (i & -i);
        }
    }

    // sum from 1 to i
    long long query(int i) {
        long long sum = 0;
        while (i > 0) {
            sum += bit[i];
            i -= (i & -i);
        }
        return sum;
    }
};
