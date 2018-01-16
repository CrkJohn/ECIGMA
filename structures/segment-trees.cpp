int a[LEN],tree[2*LEN],Lo[2*LEN],Hi[2*LEN],Ind[LEN];

#define PA(i) (((i)-1)/2)
#define L(i) (2*(i)+1)
#define R(i) (2*(i)+2)

int f(int a, int b){ return max(a,b);}

void build(int i,int lo,int hi){
	Lo[i]=lo; Hi[i]=hi;
	if(hi-lo==1) Ind[lo]=i,tree[i]=a[lo];
	else{
		build(L(i),lo,(lo+hi)/2);
		build(R(i),(lo+hi)/2,hi);
		tree[i] = f(tree[L(i)],tree[R(i)]);
	}
}

int query(int i, int lo,int hi){ //pre: lo[i] <= lo <= hi <= hi[i]
	if(Hi[i]-Lo[i]==1 || Hi[i]==hi&&Lo[i]==lo) return tree[i];
	int mid=(Lo[i]+Hi[i])/2;
	if(lo>=mid) return query(R(i),lo,hi);
	if(hi<=mid) return query(L(i),lo,hi);
	return f(query(L(i),lo,mid), query(R(i),mid,hi));
}

void update(int i,int v){
	a[i]=v;	i=Ind[i]; tree[i]=v;
	for(i=PA(i);i>=0;i=PA(i)) tree[i]=f(tree[L(i)],tree[R(i)]);
}