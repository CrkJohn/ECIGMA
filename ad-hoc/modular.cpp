large MOD=1000000007;
large mulmod(large a, large b){
  large ans=0; a%=MOD; b%=MOD;
  while (a!=0){
    if(a&1) ans=(ans+b)%MOD; a>>=1; b=(b<<1)%MOD; }
  return ans;
}
//bigMod computes (a^n)%MOD in log(n)
large bigMod(large a, large n){
	if (n==0) return 1;
	if (n==1) return a%MOD;
	large t=bigMod(a, n/2);
	t=mulmod(t, t);
	if (n&1) t=mulmod(t, (a%MOD));
	return t
}