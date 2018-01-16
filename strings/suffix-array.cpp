int gap,len,pos[SZ],tmp[SZ],sa[SZ],lcp[SZ];

bool gapcmp(int i, int j){
	if(pos[i]!=pos[j]) return pos[i]<pos[j];
  i+=gap, j+=gap;
  return (i<len && j<len)? pos[i]<pos[j] : i>j;
}

void suffixArray(char* t,int* sa, int tsz){
	int i,j,k=0;
	if(tsz<=1){ sa[0]=lcp[0]=0; return; }
	loop(i,0,tsz) sa[i]=i,pos[i]=t[i];
	len=tsz, gap=1, tmp[tsz-1]=tmp[0]=1;
	while(tmp[tsz-1]<tsz){
		sort(sa,sa+tsz,gapcmp);
		loop(i,1,tsz) tmp[i]=tmp[i-1]+ gapcmp(sa[i-1],sa[i]);
		loop(i,0,tsz) pos[sa[i]]=tmp[i];
		gap<<=1;
	}
	// Optional for LCP:
	loop(i,0,tsz) if (pos[i]!=tsz){
		j=sa[pos[i]];
		while(t[i+k] == t[j+k])	++k;
		lcp[pos[i]-1] = k;
		if(k)--k;
	}//Caution: LCP is valid in range [0, tsz-1)
}