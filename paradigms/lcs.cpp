int flcs(int ahi, int bhi){ //call flcs(asz,bsz)
  if(lcs[ahi][bhi]==-1) return lcs[ahi][bhi];
  if(ahi==0 || bhi==0) lcs[ahi][bhi]=0;
  else if(A[ahi-1]==B[ahi-1]) lcs[ahi][bhi] = 1+flcs(ahi-1,bhi-1);
  else lcs[ahi][bhi] = max(flcs(ahi,bhi-1),flcs(ahi-1,bhi));
  return lcs[ahi][bhi];
}
