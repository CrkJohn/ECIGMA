int notp[SZ];
vector<int> primes;
large Bound;

void sieve(int bound){
	large i,j;
	Bound=bound+1;
	memset(notp,0,sizeof(notp));
	notp[0]=notp[1]=1;
	for(i=2; i<=Bound; i++) if(!notp[i]){
		for(j=i*i; j<=Bound; j+=i) notp[j]=1;
		primes.push_back((int)i);
	}
}

large sumPF(large N){
	large idx=0, PF=primes[idx], ans=0;
	while(N!=1 && PF*PF<=N){
		while(N%PF==0) N/=PF, ans+=PF;
		PF = primes[++idx];
	}
	return N==1? ans: ans+N;
}
