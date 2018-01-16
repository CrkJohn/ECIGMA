ii vec[LIM];
ii hull[LIM];

bool angle_cmp(ii a, ii b){ return ccw(vec[0], a, b)>0;}
bool same(double a, double b){ return (fabs(a-b)<=1e-9);}

int GrahamScan(int n){
  int cont, i;
  ii curr, prev;
  stack<ii> S;
  FOR(i, 1, n){
    if(vec[i]<vec[0]){
      prev=vec[i];
      vec[i]=vec[0];
      vec[0]=prev;
    }
  }
  sort(vec+1, vec+n, angle_cmp);
  S.push(vec[0]); // put two starting vertices into stack S
  S.push(vec[1]);
  i = 2; // and start checking the rest
  while (i < n) { // note: N must be >= 3 for this method to work
    curr = S.top(); S.pop();
    prev = S.top(); S.push(curr); // trick to get the 2nd item from top of S
    if (ccw(prev, curr, vec[i])>0) { // if these 3 points make a left turn
      S.push(vec[i]); // accept
      i++;
    }
    else S.pop(); // otherwise pop this point until we have a left turn
  }
  cont=S.size();
  REV(i, S.size()-1, 0) { // from stack back to vector
    hull[i]=S.top();
    S.pop();
  }
  return cont;
}

//EASIER CONVEX HULL IMPLEMENTATION
//taken from the Stavropol University Notebook

bool operator <(ii a, ii b) { return a.x < b.x || (a.x == b.x && a.y < b.y); }
// Returns convex hull in counter-clockwise order.
// Note: the last point in the returned list is the same as the first one.
vector<ii> ConvexHull(vector<ii> P) {
  int n = P.size(), k = 0; vector<ii> H(2*n);
  sort(P.begin(), P.end());
  for (int i = 0; i < n; i++)
    { while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--; H[k++] = P[i]; }
  for (int i = n-2, t = k+1; i >= 0; i--)
    { while (k >= t && cross(H[k-2], H[k-1], P[i]) <= 0) k--; H[k++] = P[i]; }
  H.resize(k);
  return H;
}