#include <bits/stdc++.h>
using namespace std;

struct bit {
    vector<int> a, arr;
    bit(int n) : a(n+1), arr(n) {}

    int sum(int k) {
        int s = 0;
        for (k++; k; k -= k&-k) s += a[k];
        return s;
    }

    void add(int k, int v) {
        arr[k] += v;
        for (k++; k < a.size(); k += k&-k) a[k] += v;
    }

    int sum(int a, int b) {
        if (a == 0) return sum(b);
        return sum(b) - sum(a-1);
    }

    void set(int k, int v) {
        add(k, v - arr[k]);
    }
};
