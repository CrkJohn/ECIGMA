int t[SZ],b[SZ],tsz,bsz;
int prev[SZ],bindex[SZ],llis[SZ];
int lisAt[SZ];

void lis_log(){ // n log n
  int i,j; bsz=0;
  loop(i,0,tsz){
    j=lower_bound(b,b+bsz,t[i]);  // see docs.
    bsz += j==bsz;
    b[j]=t[i];
    // optional calculus to get lis list:
    bindex[j] = i;
    prev[i] = j==0?-1:bindex[j-1];
    // optional calculus for length of a lis ending at i:
    lisAt[i] = j+1;
  }
}

void prev2llis(){ // build lis indices list:
  int i,j=bsz;
  for(i=bindex[bsz-1]; i!=-1; i=prev[i]) llis[--j]=i;
}

void lis_2(){ // n*n
  int i,j; bsz=0; loop(i,0,tsz) len[i] = 1;
  loop(i,0,tsz) loop(j,0,i)
    if(t[j]<t[i] && len[j]+1 > len[i]) len[i] = len[j]+1;    
}
