#include<bits/stdc++.h>


using namespace std;
//const int LIM = 1e5;
int segmentTree[400005];
int rangeMinimumQuery(int low,int high,int qlow,int qhigh,int pos){
        if(qlow <= low && qhigh >= high)return segmentTree[pos];
        if(qlow > high || qhigh < low)return INT_MAX;
        int mid = (low+high)/2;
        return min(rangeMinimumQuery(low, mid, qlow, qhigh, 2*pos + 1),rangeMinimumQuery(mid+1,high,qlow,qhigh,2*pos+2));
}

void constructMinSegmentTree(vector<int> &input, int low, int high,int pos){
        if(low == high){
            segmentTree[pos] = input[low];
            return;
        }
        int mid = (low + high)/2;
        constructMinSegmentTree(input, low, mid, 2 * pos + 1);
        constructMinSegmentTree(input, mid + 1, high, 2 * pos + 2);
        segmentTree[pos] = min(segmentTree[2*pos+1], segmentTree[2*pos+2]);
}


void createSegmentTree(vector<int> &input){
        int len = input.size();
        for(int i=0; i < 4*len; i++)segmentTree[i] = INT_MAX;
        constructMinSegmentTree(input, 0, len - 1, 0);
        return;
}

int main(){
	/*https://vjudge.net/problem/LightOJ-1082*/ 
        int cases,n;
        scanf("%d",&cases);
        for(int ntc = 1 ;  ntc<=cases;ntc++){
                int lon , query;
                scanf("%d %d",&lon,&query);
                vector<int> v;
                for(int i = 0 ; i< lon ; i++){
                        scanf("%d",&n);
                        v.push_back(n);
                }
                createSegmentTree(v);
                int qlow, qhigh;
                printf("Case %d:\n",ntc);
                for(int q = 0 ; q<query;q++){
                        scanf("%d %d",&qlow,&qhigh);
                        printf("%d\n",rangeMinimumQuery(0,lon-1,qlow-1,qhigh-1,0));
                }
        }
        return 0;
}
