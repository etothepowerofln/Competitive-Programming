#include <iostream>
using namespace std;
int n, m, d, k;
long long A[501], B[501], tmp[501];

void multiply(long long array[]) {
    for(int j = 1; j <= n; ++j) {
        tmp[j] = 0;
        for(int y = 1; y <= n; ++y) tmp[j] += array[y]*B[y>=j? y-j+1:y-j+1+n];
    }
    for(int j = 1; j <= n; j++) array[j] = tmp[j]%m;
}

int main() {
    freopen("cell.in", "r", stdin);
    scanf("%d%d%d%d", &n, &m, &d, &k);
    for(int i = 1; i <= n; ++i) scanf("%lld", &A[i]);
    B[1] = 1; for(int i = 1; i <= d; ++i) B[i+1] = B[n+1-i] = 1;
    while(k) {
        if(k & 1) multiply(A);
        multiply(B);
        k >>= 1;
    }
    freopen("cell.out", "w", stdout);
    for(int t = 1; t < n; ++t) fprintf(stdout, "%lld ", A[t]);
    fprintf(stdout, "%lld", A[n]);
    fflush(stdout);
    return 0;
}
