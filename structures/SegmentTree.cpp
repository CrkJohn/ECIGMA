#include<bits/stdc++.h>


using namespace std;
const int LIM = 1e8;

int segmentTree[LIM],input[LIM];
int len;

unsigned int nextPowerOf2(unsigned int n){
	n = n - 1;
	while (n & n - 1)n = n & n - 1;
	return n << 1;
}


int rangeMinimumQuery(int low,int high,int qlow,int qhigh,int pos){
		if(qlow <= low && qhigh >= high)return segmentTree[pos];
        if(qlow > high || qhigh < low)return INT_MAX;
        int mid = (low+high)/2;
        return min(rangeMinimumQuery(low, mid, qlow, qhigh, 2*pos + 1),rangeMinimumQuery(mid+1,high,qlow,qhigh,2*pos+2));
}


void updateSegmentTreeRange(int startRange, int endRange, int delta, int low, int high, int pos) {
        if(low > high || startRange > high || endRange < low )return;
        if(low == high) {
            segmentTree[pos] += delta;
            return;
        }

        int middle = (low + high)/2;
        updateSegmentTreeRange(startRange, endRange, delta, low, middle, 2 * pos + 1);
        updateSegmentTreeRange(startRange, endRange, delta, middle + 1, high, 2 * pos + 2);
        segmentTree[pos] = min(segmentTree[2*pos+1], segmentTree[2*pos+2]);
}


void constructMinSegmentTree(vector<int> input, int low, int high,int pos){
        if(low == high){
            segmentTree[pos] = input[low];
            return;
        }
        int mid = (low + high)/2;
        constructMinSegmentTree(input, low, mid, 2 * pos + 1);
        constructMinSegmentTree(input, mid + 1, high, 2 * pos + 2);
        segmentTree[pos] = min(segmentTree[2*pos+1], segmentTree[2*pos+2]);
}


void createSegmentTree(vector<int> input){
        //if input len is pow of 2 then size of
        //segment tree is 2*len - 1, otherwise
        //size of segment tree is next (pow of 2 for len)*2 - 1.
        len = input.size();
        //while(input[len])len++;
        int nextPowOfTwo = nextPowerOf2((unsigned)len);
        int segmentTree[nextPowOfTwo*2-1];
        for(int i=0; i < nextPowOfTwo*2-1; i++){
            segmentTree[i] = INT_MAX;
        }
        constructMinSegmentTree(input, 0, (nextPowOfTwo*2-1) - 1, 0);
        return;
}

int main(){
	unsigned int numero;
	int _A[] = {1,2,3,4,5,6};
	vector<int> v(_A,_A+sizeof(_A)/sizeof(int));
	createSegmentTree(v);
	printf("%d\n",len);
    printf("%d",rangeMinimumQuery(0,5,0,3,0));
	return 0;
}
