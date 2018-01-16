typedef pair<large,large> ll;
large fv[SZ];

ll cycle(){
	large H,T,fH,fT,L=0;
	for(H=2,T=1,fH=f(f(L)),fT=f(L); fH!=fT;) {
      H+=2; T++; fH=f(f(fH)); fT=f(fT);
    }
	for(H=0,fH=L; fH!=fT;) {
      H++; T++; fH=f(fH); fT=f(fT);
    }
	for(T=H+1,fT=f(fH) ;fH!=fT;) { T++; fT=f(fT);}
	return ll(T,T-H); // (phase (mu),period (lamda))
}