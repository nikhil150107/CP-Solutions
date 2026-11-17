/*_       _________ _                _________ _
( (    /|\__   __/| \    /\|\     /|\__   __/( \
|  \  ( |   ) (   |  \  / /| )   ( |   ) (   | (
|   \ | |   | |   |  (_/ / | (___) |   | |   | |
| (\ \) | |   | |   |   _ (  |  ___  |   | |   | |
| | \   | |   | |   |  ( \ \ | (   ) |   | |   | |
| )  \  |___) (___|  /  \ \| )   ( |___) (___| (____/\
|/    )_)\_______/|_/    \/|/     \|\_______/(_______/
*/

#include <bits/stdc++.h>
using namespace std;

//----------------- Type Definitions -------------------
#define int long long
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define vpi vector<pii>
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ff first
#define ss second

//----------------- Fast IO -------------------
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

//----------------- Constants -------------------
const int MOD = 1e9 + 7;
const int INF = 1e18;
const int N = 1e6 + 10;

vector<bool> is_prime(N, true);
vi primes;

void sieve()
{
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i < N; ++i)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j < N; j += i)
                is_prime[j] = false;
        }
    }
    for (int i = 2; i < N; i++)
    {
        if (is_prime[i])
            primes.pb(i);
    }
}

vector<ll> findMultiplesInRange(ll n, ll l, ll r)
{
    vector<ll> ans;
    for (ll i = 1; i <= n; ++i)
    {
        ll x = ((l + i - 1) / i) * i;
        if (x > r)
            return {};
        ans.pb(x);
    }
    return ans;
}

vector<ll> generateDistribution(ll n, ll s, ll r)
{
    vector<ll> result;
    ll max_val = s - r;
    result.push_back(max_val);

    ll parts = n - 1;
    for (int i = 0; i < parts; ++i)
        result.push_back((r + i) / parts);

    return result;
}

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n == 2 || n == 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

ll firstMultipleGE(ll x, ll k)
{
    return ((x + k - 1) / k) * k;
}

ll firstMultipleInRange(ll l, ll r, ll k)
{
    ll m = firstMultipleGE(l, k);
    return (m <= r ? m : -1);
}

ll ceilDiv(ll a, ll b)
{
    return (a + b - 1) / b;
}

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}

int countDivisibleByAAndB(int n, int a, int b)
{
    int lcm_ab = lcm(a, b);
    return n / lcm_ab;
}

int binpow(int a, int b)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

int m_add(int a, int b)
{
    return (a % MOD + b % MOD) % MOD;
}

int m_sub(int a, int b)
{
    return (a % MOD - b % MOD + MOD) % MOD;
}

int m_mul(int a, int b)
{
    return ((a % MOD) * (b % MOD)) % MOD;
}

int m_pow(int base, int exp)
{
    int res = 1;
    base %= MOD;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

int m_inv(int n)
{
    return m_pow(n, MOD - 2);
}

int m_div(int a, int b)
{
    return m_mul(a, m_inv(b));
}

int xor_1_to_n(int n)
{
    if (n % 4 == 0)
        return n;
    if (n % 4 == 1)
        return 1;
    if (n % 4 == 2)
        return n + 1;
    return 0;
}

ll odd(ll k)
{
    if (k == 0)
        return 0;
    return k >> __builtin_ctzll(k);
}

ll oddop(ll k)
{
    return (k == 0) ? 0 : __builtin_ctzll(k);
}

int countBits(int n)
{
    return __builtin_popcountll(n);
}

int getBit(int n, int i)
{
    return (n >> i) & 1;
}

void setBit(int &n, int i)
{
    n |= (1LL << i);
}

void clearBit(int &n, int i)
{
    n &= ~(1LL << i);
}

#define dbg(x) cerr << #x << " = " << x << "\n";

//----------------- Solve Function -------------------
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    int l = 0, r = n - 1;
    vector<bool> vis(26, false);
    int ans = 0;
    while (l <= r)
    {
        for (int i = min(s[l] - 'a', s[r] - 'a') + 1; i <= (max(s[l] - 'a', s[r] - 'a')); i++)
        {
            if (!vis[i])
            {
                vis[i] = true;
                ans++;
            }
        }
        l++;
        r--;
    }
    cout << ans;
}

/*
Gloden Rules:-
solutions are simple
proofs are simple
implementations are simple
*/

//----------------- Main Function -------------------
int32_t main()
{
    fastio;
    int t;
    cin >> t;
    while (t--)
    {
        solve();

        cout << endl;
    }
    return 0;
}