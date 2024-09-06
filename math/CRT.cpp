ll CRT(ll k, ll* a, ll* r) {
    ll n = 1, ans = 0;
    for (ll i = 1; i <= k; i++) {
        n = n * r[i];
    }
    for (ll i = 1; i <= k; i++) {
        ll m = n / r[i], b, y;
        exgcd(m, r[i], b, y);
        ans = (ans + a[i] * m * b % n) % n;
    }
    return (ans % n + n) % n;
}