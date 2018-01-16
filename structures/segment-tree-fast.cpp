//http://codeforces.com/blog/entry/18051
int len,tlen;
large a[LEN],t[4*LEN];

void pre(){
  int i;
  for(tlen=1; tlen<len ; tlen<<=1);
  loop(i,0,len) t[tlen+i] = a[i];
  rev(i,tlen-1,1) t[i] = t[i<<1] + t[i<<1|1];
}

large query(int l, int r){
  large tl=0, tr=0;
  for(l+=tlen,r+=tlen; l<r; l>>=1,r>>=1){
    if(l&1) tl = tl + t[l++];
    if(r&1) tr = tr + t[--r];
  }
  return tl + tr;
}

void modify(int i, int x){
  for(t[i+=tlen]=x; i>1; i>>=1)
    t[i>>1]=t[i]+t[i^1];
}