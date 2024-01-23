#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define PI 3.141592653
#define endl "\n"
#define fori(a, b) for (long long i = a; i < b; i++)
#define forj(a, b) for (long long j = a; j < b; j++)
#define fork(a, b) for (long long k = a; k < b; k++)
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
void printArry(vector<ll> &arr)
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
    fori(0, arr.size()) sum += arr[i];
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
bool isPalindrome(string s)
{
    ll n = s.size();
    for (ll i = 0; i < n / 2; i++)
    {
        if (s[i] != s[n - 1 - i])
        {
            return false;
        }
    }
    return true;
}
bool check()
{
    return true;
}

ll countBits(ll num)
{
    ll count = 0;

    while (num)
    {
        if (num % 2 == 1)
            count++;
        num = num >> 1;
    }

    return count;
}

ll checkBit(ll num, ll bit)
{
    return num & (1 << bit);
}

int main()
{

    files();
    fast();
    int x = 3;
    int y = 4;
    vector<int> arr = {4,5,6,7};
    cout << x+y;
}
