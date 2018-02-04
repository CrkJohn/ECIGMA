#include <bits/stdc++.h>
#define size 100009


using namespace std;

typedef long long large;
large segmentTree[4 * size];
large lazy[4 * size];

void updateSegmentTreeRangeLazy(large startRange, large endRange,large delta, large low, large high, large pos) {
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
        large mid = (low + high)/2;
        updateSegmentTreeRangeLazy(startRange, endRange,delta, low, mid, 2*pos+1);
        updateSegmentTreeRangeLazy(startRange, endRange,delta, mid+1, high, 2*pos+2);
        segmentTree[pos] =  segmentTree[2*pos+1] + segmentTree[2*pos+2]; 
}

large rangeMinimumQueryLazy(large qlow, large qhigh,large low, large high, large pos) {
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
        large mid = (low+high)/2;
        
        return  rangeMinimumQueryLazy(qlow, qhigh,low, mid,2*pos + 1) + rangeMinimumQueryLazy(qlow, qhigh,mid+1, high, 2*pos+2);;
}





int main(){
    large ntc;
    //freopen("HQ.txt","r",stdin);
    large type,p,q,delta;
    scanf("%lld",&ntc);
    while(ntc--){
        large len,lines;
        scanf("%lld %lld",&len,&lines);
        memset(segmentTree,0,sizeof(segmentTree));
        memset(lazy,0,sizeof(lazy));
        for(large i = 0 ; i < lines;i++){
            scanf("%lld %lld %lld",&type,&p,&q);
            if(type==0){
            	//printf("%lld %lld %lld\n",type,p,q);
                scanf("%lld",&delta);
                updateSegmentTreeRangeLazy(p-1,q-1,delta,0,len-1,0);
            }else{
                printf("%lld\n",rangeMinimumQueryLazy(p-1,q-1,0,len-1,0));
            }

        }
    }
    return 0;
}
