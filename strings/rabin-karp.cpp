large h[SZ];
large hashit(char* t, int tsz, int len, large* h){
	int i; large Base=257,Mod=7778777,poow=1;
	loop(i,0,len) poow = (Base*poow) % Mod;
	h[0]=0;	loop(i,0,len)	h[0] = (Base*h[0] + t[i])%Mod;
	loop(i,0,tsz-len) h[i+1] = (Base*h[i] + Mod - poow*t[i]%Mod + t[i+len]) % Mod;
	return h[0];
}

void findp(char* p, int psz, char* t, int tsz){
	large key=hashit(p,psz,psz,h); int i;
	hashit(a,tsz,psz,h);
	loop(i,0,tsz-psz+1) if(key==h[i]) printf("Match at %d.\n",i);
}

int main(){ // finds b in a
	scanf("%s",a); scanf("%s",b);
	findp(a,strlen(b),a,strlen(a));
	return 0;
}
