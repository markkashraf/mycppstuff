#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.141592653
#define endl "\n"
#define fori(a) for (long long i = 0; i < a; i++)
#define forj(a) for (long long j = 0; j < a; j++)
#define fork(a) for (long long k = 0; k < a; k++)
#define arrLength(a) sizeof(a) / sizeof(a[0])
#define sout(a) cout << a << '\n';
#define sign(a) ((a >= 0) ? true : false)
#define ssout(a, b) cout << a << b << '\n';
#define sum(a) (a * (a + 1)) / 2

void files()
{
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
}

void fast()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
ll sumOfDigits(ll x)
{
    ll sum = 0;
    while (x != 0)
    {
        sum += x % 10;
        x = x / 10;
    }
    return sum;
}
void printArry(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << '\n';
}
void printArry(vector<int> arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {

        cout << arr[i] << " ";
    }

    cout << arr[arr.size() - 1] << '\n';
}

ll sumArry(vector<ll> arr)
{
    ll sum = 0;
    fori(arr.size()) sum += arr[i];
    return sum;
}
void sort(vector<ll> &x)
{
    sort(x.begin(), x.end());
}
void sort(string &x)
{
    sort(x.begin(), x.end());
}
int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}
ll natSum(ll n)
{
    return n * (n + 1) / 2;
}

ll N = 10e4 + 100;
vector<bool> isPrime(N, true);

void primeNumbers()
{
    isPrime[0] = isPrime[1] = false;
    for (ll i = 2; i * i < N; i++)
    {
        if (isPrime[i])
        {
            for (ll j = i * i; j < N; j += i)

                isPrime[j] = false;
        }
    }
}

bool isIsomorphic(string s, string t)
{
    unordered_map<char, char> map;
    unordered_set<char> mapped;
    for (int i = 0; i < s.size(); i++)
    {
        if (map.find(s[i]) == map.end() && mapped.find(t[i]) == mapped.end())
        {
            map[s[i]] = t[i];
            mapped.insert(t[i]);
        }
        s[i] = map[s[i]];
    }

    return s == t;
}




 

int main()
{
    files();
    fast();





  


 
    
}
