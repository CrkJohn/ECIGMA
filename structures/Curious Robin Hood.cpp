#include<bits/stdc++.h>
#define pb push_back

using namespace std;
typedef vector<int> vi;

int segmentTree[400005],op;
int f(int i , int j){return i+j;}

int RMQ(int low,int high,int qlow,int qhigh,int pos){
        if(qlow <= low && qhigh >= high)return segmentTree[pos];
        if(qlow > high || qhigh < low)return 0;
        int mid = (low+high)/2;
        return f(RMQ(low, mid, qlow, qhigh, 2*pos + 1),RMQ(mid+1,high,qlow,qhigh,2*pos+2));
}

void updateSegmentTreeF(int index, int delta, int low, int high, int pos){
        //if index to be updated is less than low or higher than high just return.
        if(index < low || index > high){return;}
        //if low and high become equal, then index will be also equal to them and update
        //that value in segment tree at pos
        if(low == high){
			segmentTree[pos] += delta;
            return;
        }
        //otherwise keep going left and right to find index to be updated
        //and then update current tree position if min of left or right has
        //changed.
        int mid = (low + high)/2;
        updateSegmentTreeF(index, delta, low, mid, 2 * pos + 1);
        updateSegmentTreeF(index, delta, mid + 1, high, 2 * pos + 2);
        segmentTree[pos] = f(segmentTree[2*pos+1], segmentTree[2*pos + 2]);
}


void updateSegmentTree(vi &input,int index, int delta, int length){
		input[index] += delta;
        updateSegmentTreeF(index, delta, 0,length - 1, 0);
}

void constructMinSegmentTree(vi &input,int low, int high,int pos){
        if(low == high){
            segmentTree[pos] = input[low];
            return;
        }
        int mid = (low + high)/2;
        constructMinSegmentTree(input , low, mid, 2 * pos + 1);
        constructMinSegmentTree(input , mid + 1, high, 2 * pos + 2);
        segmentTree[pos] = f(segmentTree[2*pos+1],  segmentTree[2*pos+2]);
}

void createSegmentTree(vi &input){
        int len = input.size();
        for(int i=0; i < 4*len; i++)segmentTree[i] = 0;
        constructMinSegmentTree(input,0, len - 1, 0);
        return;
}

int main(){
	//freopen("hood.txt","r",stdin);
	int ntc ,ind,val;
	vi input;
	scanf("%d",&ntc);
	for(int tc = 1 ; tc<=ntc;tc++){
		input.clear();
        printf("Case %d:\n",tc);
        int lon , query , num;
        scanf("%d %d",&lon,&query);
        for(int n = 0 ; n<lon;n++){
            scanf("%d",&num);input.pb(num);
        }
        createSegmentTree(input);
        int len = input.size();
        int poor = 0 ;
        //puts("Constuct terminate");
		for(int q = 0 ; q < query ;q++){
			scanf("%d %d",&op,&ind);
			if(op == 1){
				poor = input[ind];
				printf("%d\n",poor);
				updateSegmentTree(input,ind,-input[ind],len);
				input[ind] = 0;
			}else if(op == 2) {
					scanf("%d",&val);
					updateSegmentTree(input,ind,val,len);
			}else{
				scanf("%d",&val);
				printf("%d\n",RMQ(0,len-1,ind,val,0));
			}
		}
	}
    return 0;
}
