/*
1. （Josephus 问题） 有 n 个人围成一个圈，依次标号 0 至 n - 1。
    从 0 号开始，依次 0 , 1 , 0 , 1 … 交替报数，
    报到 1 的人会离开，直至圈中只剩下一个人。
    求最后剩下人的编号。
*/
#include <iostream>

using namespace std;

const int MAXN = 1000000;
int F[MAXN];

int main() {
    int n;
    cin >> n;
    int i = 0, p = 0, c = 0;
    while (/*1->*/c < n-1/*<-1*/) {
        if (F[i] == 0) {
            if (/*2->*/p/*<-2*/) {
                F[i] = 1;
                /*3->*/c++/*<-3*/;
            }
            /*4->*/p^=1/*<-4*/;
        }
        /*5->*/i = (i+1) % n/*<-5*/;
    }
    int ans = -1;
    for (i = 0; i < n; i++)
        if (F[i] == 0)
            ans = i;
    cout << ans << endl;
}
/*
参考答案：
c < n-1
p
c++
p^=1
i = (i+1) % n
*/