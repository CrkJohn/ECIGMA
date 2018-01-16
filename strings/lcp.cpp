int lcp[tSZ],plcp[tSZ],phi[tSZ];

void computelcp() { // CP3
	int l=0,i;
	phi[s[0]] = -1; // default value
	loop(i,1,tsz) phi[s[i]] = s[i-1];	// remember which suffix is behind this suffix
	loop(i,0,tsz) {	// compute Permuted lcp in O(n)
		if (phi[i] == -1) { plcp[i] = 0; continue; }	// special case
		while (t[i + l] == t[phi[i] + l]) l++;	// L will be increased max n times
		plcp[i] = l;
		l = max(l-1, 0);	// L will be decreased max n times
	}
	loop(i,1,tsz) lcp[i] = plcp[s[i]];	// put the permuted lcp back to the correct position
}