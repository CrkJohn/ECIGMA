int sliding_min(){ // gets the min of s[i..i+n) for every i
	int ans=INFINITY,i,l;
	priority_queue<ii,deque<ii>,greater<ii> > q;
	loop(i,0,n) q.push(ii(s[i],i));
	loop(i,0,ssz+1-n){
		while(q.top().y < i) q.pop();
		l=q.top().x;
        // at this point, l = min( s[i..i+n) )
		ans=min(ans,l);
		q.push(ii(lcp[i+n],i+n));
	}
    return ans;
}