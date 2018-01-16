---------------Check pending---------------------------
---------------Comments pending------------------------
void increase(int i, int delta){
	for (; i < sz; i |= i + 1) tree[i] += delta;
}

int sum(int ind){
	int sum = 0;
	while (ind>=0){
		sum += tree[ind];
		ind &= ind + 1;
		ind--;
	}
	return sum;
}

int getsum(int left, int right){
	return sum(right) - sum(left-1);
}

