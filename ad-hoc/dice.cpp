// index[0..5]
char moves[4]={'u','l','d','r'}; // Moves rolling in a table.
int nextt[6][6][4]; //next_top   = nextt[curr_top][curr_front][mov]
int nextf[6][6][4]; //next_front = nextf[curr_top][curr_front][mov]

void pre(){
  int t,f,m,sides[4],i;
  loop(t,0,6){
    sides[0] = t<3? (t+1)%3 : (7-t)%3; 
    sides[1] = t<3? (t+2)%3 : (6-t)%3;
    sides[2] = 5-sides[0]; sides[3] = 5-sides[1];
    loop(m,0,4) loop(f,0,4){
      nextt[t][sides[f]][m] = sides[(f+m)%4];
      nextf[t][sides[f]][m] = m==0? 5-t: m==2? t: sides[f];
    }
  }
}

