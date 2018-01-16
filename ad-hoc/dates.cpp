#define y first
#define m second.first
#define d second.second
typedef pair<int,int> ii;
typedef pair<int,ii> date;
int mdays[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int macum[13]={0,31,59,90,120,151,181,212,243,273,304,334,365};
int leaps(int y1,int y2){return y2/4-y2/100+y2/400-(y1/4-y1/100+y1/400);}

int days(date d0, date d1){ //Days from d0 to d1 (can be negative)
  // Warning: Months are [1..12] indexed.
  int between,flag=1;
  if(d0>d1) {flag=-1; swap(d0,d1);}
  between  = 365*(d1.y-d0.y) + macum[d1.m-1]-macum[d0.m-1]+d1.d-d0.d;
  between += leaps(d0.y-(ii(d0.m,d0.d)<=ii(2,29)),
               d1.y-(ii(d1.m,d1.d)<=ii(2,29)));
  return between*flag;
}
