char s[sSZ], temp[sSZ];
int f[sSZ], ssz;

int booth(){
  // Returns first index of minimum
  // lexicographic rotation of s[0..ssz)
  // Uses char temp[0..ssz) and
  // int f[0..ssz) for computation
  int k=0, j, i;
  strcpy(temp, s); strcat(s, temp); SET(f, -1);
  loop(j, 1, 2*ssz){
    i=f[j-k-1];
    while(i!=-1 && s[j] != s[k+i+1]){
      if (s[j]<s[k+i+1]) k=j-i-1;
      i=f[i];
    }
    if (i==-1 && s[j] != s[k+i+1]){
      if (s[j]<s[k+i+1]) k=j-i-1;
      f[j-k]=-1;
    }
    else f[j-k]=i+1;
  }
  return k;
}
