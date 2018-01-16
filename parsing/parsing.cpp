typedef vector<char*> vs;

vs splitstrip(char* s, char c){
	int i,tok=1,sp=0;
	vs l;
	for(i=0;s[i];i++){
		if(s[i]==c) tok=1,s[sp]=0;
		else if(s[i]!=' '){ sp=i+1; if(tok)l.pushb(s+i),tok=0; }
		else if(s[sp]!=' ') sp=i;
	}
	if(i>0 && s[i-1]=='\n') s[i-1]=0;
	return l;
}

void rmchar(char* s,char a){
	int i=0,j=0;
	while(s[i]){
		if(s[i]!=a) s[j++]=s[i];
		i++;
	}
	s[j]=0;
}

large tonum(char* s){
	int i; large n=0;
    i=!isdigit(s[0]);
    while(s[i]) n=10*n+s[i++]-'0';
    return (s[0]=='-')? -n:n;
}