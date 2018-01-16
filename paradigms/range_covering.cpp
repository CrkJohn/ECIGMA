int solve(){
	int i,j,k,ans=0;
	if(l==0||w==0) return 0;
	if(s.size()==0) return -1;
	sort(s.begin(),s.end());
	if(0<s[0].x) return -1;
	for(j=k=i=0; j<s.size() && s[j].x<=0; j++) if(s[j].y>s[k].y) k=j;
	i=k; ans++;
	while(s[i].y<l && i<s.size()){
		for(j=k=i; j<s.size() && s[j].x<=s[i].y; j++) if(s[j].y>s[k].y) k=j;
		if(k==i) break;
		ans++;
		i=k;
	}
	if(s[i].y<l) return -1;
	return ans;
}