// https://pintia.cn/problem-sets/994805342720868352/problems/994805415005503488
#include <bits/stdc++.h>
using namespace std;
bool isprime(int x) {
    if (x <= 1) return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return false;
    return true;
}
int main() {
    int prime[50000], len = 0;
    for (int i = 2; i <= 50000; i++)
        if (isprime(i)) prime[len++] = i;
    int n;
    scanf("%d", &n);
    printf("%d=", n);
    if (n == 1) {
        printf("1");
        return 0;
    }
    int sqr = (int)sqrt(n * 1.0), flag = 0;
    for (int i = 0; i < len && prime[i] <= sqr; i++) {
        if (n == 1) break;
        if (n % prime[i] == 0) {
            int k = 0;
            while (n % prime[i] == 0) {
                k++;
                n /= prime[i];
            }
            if (flag) printf("*");
            flag = 1;
            printf("%d", prime[i]);
            if (k > 1) printf("^%d", k);
        }
    }
    if (n != 1) printf("%s%d", flag ? "*" : "", n);
    return 0;
}

/*
#include <cmath>
#include <cstdio>
const int maxn = 20000;
int prime[maxn], pNum = 0;
struct factor {
    int x, cnt;
} fac[10];

bool isPrime(int x) {
    if (x == 1) return false;
    int sqr = (int)sqrt(x * 1.0);
    for (int i = 2; i <= sqr; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

void findPrime() {
    for (int i = 1; i < maxn; i++) {
        if (isPrime(i)) {
            prime[pNum++] = i;
        }
    }
}

int main() {
    findPrime();
    int n, num = 0;
    scanf("%d", &n);
    if (n == 1)
        printf("1=1\n");
    else {
        printf("%d=", n);
        int sqr = (int)sqrt(
            1.0 *
            n);  // 关键步骤,
                 // 质数因子要么比n的开方数小要么仅存在一个大于其开方数的质数因子
        for (int i = 0; i < pNum && prime[i] <= sqr; i++) {
            if (n % prime[i] == 0) {
                fac[num].x = prime[i];
                fac[num].cnt = 0;
                while (n % prime[i] == 0) {
                    fac[num].cnt++;
                    n /= prime[i];
                }
                num++;
            }
            if (n == 1) break;
        }
        if (n != 1) {
            fac[num].x = n;
            fac[num++].cnt = 1;
        }
        for (int i = 0; i < num; i++) {
            if (i > 0) printf("*");
            printf("%d", fac[i].x);
            if (fac[i].cnt > 1) {
                printf("^%d", fac[i].cnt);
            }
        }
    }
    return 0;
}
*/