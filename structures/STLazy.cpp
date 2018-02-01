#include <bits/stdc++.h>


using namespace std;

typedef vector<int> vi;

const int LIM = 1e4;
int segmentTree[4*LIM],lazy[4*LIM];

void updateSegmentTreeRangeLazy( int startRange, int endRange,int delta, int low, int high, int pos) {
        if(low > high)return;
        //make sure all propagation is done at pos. If not update tree
        //at pos and mark its children for lazy propagation.
        if (lazy[pos] != 0) {
            segmentTree[pos] += lazy[pos];
            if (low != high) { //not a leaf node
                lazy[2 * pos + 1] += lazy[pos];
                lazy[2 * pos + 2] += lazy[pos];
            }
            lazy[pos] = 0;
        }
        //no overlap condition
        if(startRange > high || endRange < low)return;
        //total overlap condition
        if(startRange <= low && endRange >= high) {
            segmentTree[pos] += delta;
            if(low != high) {
                lazy[2*pos + 1] += delta;
                lazy[2*pos + 2] += delta;
            }
            return;
        }
        //otherwise partial overlap so look both left and right.
        int mid = (low + high)/2;
        updateSegmentTreeRangeLazy(startRange, endRange,delta, low, mid, 2*pos+1);
        updateSegmentTreeRangeLazy(startRange, endRange,delta, mid+1, high, 2*pos+2);
        segmentTree[pos] = min(segmentTree[2*pos + 1], segmentTree[2*pos + 2]);
}

int rangeMinimumQueryLazy(int qlow, int qhigh,int low, int high, int pos) {
        if(low > high)return INT_MAX;
        //make sure all propagation is done at pos. If not update tree
        //at pos and mark its children for lazy propagation.
        if (lazy[pos] != 0) {
            segmentTree[pos] += lazy[pos];
            if (low != high) { //not a leaf node
                lazy[2 * pos + 1] += lazy[pos];
                lazy[2 * pos + 2] += lazy[pos];
            }
            lazy[pos] = 0;
        }
        //no overlap
        if(qlow > high || qhigh < low)return INT_MAX;
        //total overlap
        if(qlow <= low && qhigh >= high)return segmentTree[pos];
        //partial overlap
        int mid = (low+high)/2;
        return min(rangeMinimumQueryLazy(qlow, qhigh,low, mid, 2 * pos + 1), rangeMinimumQueryLazy(qlow, qhigh,mid+1, high, 2*pos+2));
}



int rangeMinimumQuery(int low,int high,int qlow,int qhigh,int pos){
        if(qlow <= low && qhigh >= high)return segmentTree[pos];
        if(qlow > high || qhigh < low)return INT_MAX;
        int mid = (low+high)/2;
        return min(rangeMinimumQuery(low, mid, qlow, qhigh, 2*pos + 1),rangeMinimumQuery(mid+1,high,qlow,qhigh,2*pos+2));
}

void constructMinSegmentTree(vi &input, int low, int high,int pos){
        if(low == high){
            segmentTree[pos] = input[low];
            return;
        }
        int mid = (low + high)/2;
        constructMinSegmentTree(input, low, mid, 2 * pos + 1);
        constructMinSegmentTree(input, mid + 1, high, 2 * pos + 2);
        segmentTree[pos] = min(segmentTree[2*pos+1], segmentTree[2*pos+2]);
}


void createSegmentTree(vi &input){
        int len = input.size();
        for(int i=0; i < 4*len; i++)segmentTree[i] = INT_MAX;
        memset(lazy,0,sizeof lazy);
        constructMinSegmentTree(input, 0, len - 1, 0);
        return;
}



int main(){


    return 0;
}
