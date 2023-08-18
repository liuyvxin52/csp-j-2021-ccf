/*
2. （矩形计数） 平面上有 n 个关键点，求有多少个四条边都和 x 轴或者 y 轴平行的矩形，
    满足四个顶点都是关键点。
    给出的关键点可能有重复，但完全重合的矩形只计一 次。
*/
#include <iostream>

using namespace std;

struct point {
    int x, y, id;
};

bool equals(point a, point b) {
    return a.x == b.x && a.y == b.y;
}

bool cmp(point a, point b) {
    return /*1->*/a.x != b.x ? a.x < b.x : a.y < b.y/*<-1*/;
}

void sort(point A[], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 1; j < n; j++)
            if (cmp(A[j], A[j - 1])) {
                point t = A[j];
                A[j] = A[j - 1];
                A[j - 1] = t;
            }
}

int unique(point A[], int n) {
    int t = 0;
    for (int i = 0; i < n; i++)
        if(/*2->*/t == 0 || !equals(A[i], A[t - 1])/*<-2*/)
            A[t++] = A[i];
    return t;
}

bool binary_search(point A[], int n, int x, int y) {
    point p;
    p.x = x;
    p.y = y;
    p.id = n;
    int a = 0, b = n - 1;
    while (a < b) {
        int mid = /*3->*/(a + b) >> 1/*<-3*/;
        if (/*4->*/cmp(A[mid], p)/*<-4*/)
            a = mid + 1;
        else
            b = mid;
    }
    return equals(A[a], p);
}

const int MAXN = 1000;
point A[MAXN];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i].x >> A[i].y;
        A[i].id = i;
    }
    sort(A, n);
    n = unique(A, n);
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (/*5->*/A[i].x < A[j].x && A[i].y < A[j].y/*<-5*/ && binary_search(A, n, A[i].x, A[j].y) && binary_search(A, n, A[j].x, A[i].y)) {
                ans++;
            }
    cout << ans << endl;

    return 0;
}
/*
参考答案：
a.x != b.x ? a.x < b.x : a.y < b.y
t == 0 || !equals(A[i], A[t - 1])
(a + b) >> 1
cmp(A[mid], p)
A[i].x < A[j].x && A[i].y < A[j].y
*/