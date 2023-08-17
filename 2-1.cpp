//2-1
#include <iostream>
using namespace std;

int n;
int a[1000];

int f(int x)
{
    int ret = 0;
    for (; x; x &= x - 1) ret++;
    return ret;
}

int g(int x)
{
    return x & -x;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++)
        cout << f(a[i]) + g(a[i]) << ' ';
    cout << endl;
    return 0;
}