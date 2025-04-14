#include "template.cpp"

struct bit {
    vi ft;
    bit(int m) : ft(m + 1) {}

    // build from array (O(m + n) vs O(m*log m) if you loop-update)
    bit(vi& a) : ft(a.size()) {
        int m = a.size() - 1;
        for (int i = 1; i <= m; i++) {
            ft[i] += a[i];
            if (i + lsone(i) <= m) ft[i + lsone(i)] += ft[i];
        }
    }

    int rsq(int j) {
        int out = 0;
        for (; j; j -= lsone(j)) out += ft[j];
        return out;
    }

    int rsq(int i, int j) { return rsq(j) - rsq(i - 1); }

    void update(int i, int v) {
        for (; i < ft.size(); i += lsone(i)) ft[i] += v;
    }
};

struct rupq {
    bit bit;
    rupq(int m): bit(m) {}

    void update(int i, int j, int v) {
        bit.update(i, v);
        bit.update(j + 1, -v);
    }

    int query(int i) { return bit.rsq(i); }
};

struct rurq {
    rupq rupq;
    bit purq;

    rurq(int m) : rupq(m), purq(m) {}

    void update(int i, int j, int v) {
        rupq.update(i, j, v);
        purq.update(i, v * (i - 1));
        purq.update(j + 1, -v * j);
    }

    int rsq(int j) { return rupq.query(j) * j - purq.rsq(j); }
    int rsq(int i, int j) { return rsq(j) - rsq(i - 1); }
};
