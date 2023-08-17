//2-3
#include <iostream>
using namespace std;

const int n = 100000;
const int N = n + 1;

int m;
int a[N], b[N], c[N], d[N];
int f[N], g[N];

void init()
{
    f[1] = g[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!a[i]) {
            b[m++] = i;
            c[i] = 1, f[i] = 2;
            d[i] = 1, g[i] = i + 1;
        }
        for (int j = 0; j < m && b[j] * i <= n; j++) {
            int k = b[j];
            a[i * k] = 1;
            if (i % k == 0) {
                c[i * k] = c[i] + 1;
                f[i * k] = f[i] / c[i * k] * (c[i * k] + 1);
                d[i * k] = d[i];
                g[i * k] = g[i] * k + d[i];
                break;
            }
            else {
                c[i * k] = 1;
                f[i * k] = 2 * f[i];
                d[i * k] = g[i];
                g[i * k] = g[i] * (k + 1);
            }
        }
    }
}

int main()
{
    init();

    int x;
    cin >> x;
    cout << f[x] << ' ' << g[x] << endl;
    return 0;
}