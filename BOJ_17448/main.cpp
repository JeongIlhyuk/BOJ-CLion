#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
static const int MOD = 1000000007;

// fast exponentiation mod
int64 modexp(int64 a, int64 e=MOD-2) {
    int64 r=1;
    while(e) {
        if(e&1) r = (r*a)%MOD;
        a = (a*a)%MOD;
        e >>= 1;
    }
    return r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<int64> A(N);
    for(int i=0;i<N;i++) cin >> A[i];

    // sort by descending absolute value
    sort(A.begin(), A.end(),
         [&](int64 x, int64 y){
           return llabs(x) > llabs(y);
         });

    // t = how many we pick with cost-1 actions
    int t = min(N, K);

    // prefix product of abs(A[i]) mod, and count negatives
    int64 Pabs = 1;
    int negCnt = 0;
    for(int i=0;i<t;i++){
        int64 v = llabs(A[i])%MOD;
        Pabs = (Pabs * v) % MOD;
        if(A[i]<0) negCnt++;
    }
    // sign if all action1 => each contributes a factor -1,
    // so overall sign = (-1)^{ t + negCnt } * absProduct
    bool positive = ((t + negCnt) % 2 == 0);

    // if already positive, done
    if(positive){
        cout << Pabs << "\n";
        return 0;
    }

    // gather candidates for swap in the "cost1-only" world
    // in S = A[0..t-1]:
    //   smallest-abs negative  => negMinAbs
    //   smallest-abs positive  => posMinAbs
    // in R = A[t..]:
    //   largest-abs positive   => posNextAbs
    //   largest-abs negative   => negNextAbs

    int64 negMinAbs = -1, posMinAbs = -1;
    for(int i=t-1;i>=0;i--){
        if(A[i]<0 && negMinAbs<0)
            negMinAbs = llabs(A[i]);
        if(A[i]>0 && posMinAbs<0)
            posMinAbs = llabs(A[i]);
        if(negMinAbs>0 && posMinAbs>0) break;
    }

    int64 posNextAbs = -1, negNextAbs = -1;
    for(int i=t;i<N
