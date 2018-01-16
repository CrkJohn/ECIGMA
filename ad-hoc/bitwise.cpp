int fsb(int n){ return n&(-n);}  // first_set_bit(n)
int fsb(unsint n){ return n&((~n)-1);}  // first_set_bit(n)
( n & (-n) ) == n  <-->  n==0 || n=2^i || n=-2^i

large bitreverse(large n, int l){
	large m=0,i;
	loop(i,0,l) m=(m<<1)|((n>>i)&1);
	return m;
}
void bitprint(large n){ if(n>1) bitprint(n>>1);	printf("%d",n&1);	}