#include <bits/stdc++.h>
#define size 100009


using namespace std;

typedef long long large;
large segmentTree[4 * size];
large a[size];
large lazy[4 * size];

void updateSegmentTreeRangeLazy(int startRange, int endRange,int delta, int low, int high, int pos) {
        if(low > high)return;
        //make sure all propagation is done at pos. If not update tree
        //at pos and mark its children for lazy propagation.
        if (lazy[pos] != 0) {
            segmentTree[pos] += lazy[pos]*(high-low+1);
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
            segmentTree[pos] += delta*(high-low+1);
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
        segmentTree[pos] =  segmentTree[2*pos+1] + segmentTree[2*pos+2];
}

large rangeMinimumQueryLazy(int qlow, int qhigh,int low, int high, int pos) {
        if(low > high)return 0;
        //make sure all propagation is done at pos. If not update tree
        //at pos and mark its children for lazy propagation.
        if(qlow > high || qhigh < low)return 0;

        if (lazy[pos] != 0) {
            segmentTree[pos] += lazy[pos]*(high-low+1);
            if (low != high) { //not a leaf node
                lazy[2*pos+1] += lazy[pos];
                lazy[2*pos+2] += lazy[pos];
            }
            lazy[pos] = 0;
        }
        //no overlap
        //total overlap
        if(qlow <= low && qhigh >= high)return segmentTree[pos];
        //partial overlap
        int mid = (low+high)/2;
        return rangeMinimumQueryLazy(qlow, qhigh,low, mid,2*pos + 1) + rangeMinimumQueryLazy(qlow, qhigh,mid+1, high, 2*pos+2);
}





int main(){
    int ntc;
    freopen("HQ.txt","r",stdin);
    int type,p,q,delta;
    scanf("%d",&ntc);
    while(ntc--){
        int len,lines;
        scanf("%d %d",&len,&lines);
        memset(segmentTree,0,sizeof(segmentTree));

        memset(lazy,0,sizeof(lazy));
        for(int i = 0 ; i < lines;i++){
            scanf("%d %d %d",&type,&p,&q);
            if(type==0){
                scanf("%d",&delta);
                updateSegmentTreeRangeLazy(p-1,q-1,delta,0,len-1,0);
            }else{
                printf("%lld\n",rangeMinimumQueryLazy(p-1,q-1,0,len-1,0));
            }

        }
    }
    return 0;
}
