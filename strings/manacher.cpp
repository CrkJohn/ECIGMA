char text[LEN];
int L[LEN], n;

int manacher() {
    int N, C=1, R=2, i=0, iMirror, start, end, diff;
    if(n == 0) return 0;
    N = 2*n + 1;
    L[0] = 0;
    L[1] = 1;
    int maxLPSLength = 0;
    int maxLPSCenterPosition = 0;
    start = end = diff = -1;
    loop(i,2,N){
        iMirror  = 2*C-i;
        L[i] = 0;
        diff = R - i;
        if(diff > 0) L[i] = min(L[iMirror], diff);
 
        while ( ((i + L[i]) < N && (i - L[i]) > 0) && 
            ( ((i + L[i] + 1) % 2 == 0) || 
            (text[(i + L[i] + 1)/2] == text[(i - L[i] - 1)/2] ))){
            L[i]++;
        }
        
        if(L[i] > maxLPSLength) {
            maxLPSLength = L[i];
            maxLPSCenterPosition = i;
        }

        if (i + L[i] > R) {
            C = i;
            R = i + L[i];
        }
    }
    return maxLPSLength;
}