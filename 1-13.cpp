//1-13
solve(n)
    if (n<=1) return 1; 
    else if (n>=5) return n*solve(n-2);
    else return n*solve(n-1);
/*
则调用solve(7)得到的返回结果为（ ）。
A、105
B、840
C、210
D、420
参考答案：C
非可运行文件，请自行编写剩余部分
*/