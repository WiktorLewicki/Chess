#include <bits/stdc++.h>
#include "silnik.cpp"
using namespace std;
struct arr{
	int a;
	int b;
	int c;
	int d;
	int val;
};
struct ans{
	int a;
	int b;
	int c;
	int d;
};
arr dfs(Szachownica plansza, int depth, int pkt, int alpha, int beta){
	if(depth==6) return {0, 0, 0, 0, pkt};
	arr odp;
	odp.val=400;
	if(plansza.kto()) odp.val=-400;
	for(int a=8;a>=1;a--){
		for(int b=8;b>=1;b--){
			for(int c=8;c>=1;c--){
				for(int d=8;d>=1;d--){
					Szachownica tst=plansza;
					int pm=tst.ruch_gracza(a, b, c, d, 0);
					arr cp;
					if(!pm) continue;
					else if(pm==-1){
						if(!plansza.kto()) cp={a, b, c, d, -500};
						else cp={a, b, c, d, 500};
					}
					else{
						if(!plansza.kto()) cp=dfs(tst, depth+1, pkt-tst.punkty(), alpha, beta);
						else cp=dfs(tst, depth+1, pkt+tst.punkty(), alpha, beta);
					}
					if(!plansza.kto()&&cp.val<=alpha){
						return {0, 0, 0, 0, pkt};
					}
					else if(plansza.kto()&&cp.val>=beta){
						return {0, 0, 0, 0, pkt};
					}
					if(plansza.kto()&&cp.val>odp.val){
						alpha=cp.val;
						odp.val=cp.val;
						odp.a=a;
						odp.b=b;
						odp.c=c;
						odp.d=d;
					}
					else if(!plansza.kto()&&cp.val<odp.val){
						beta=cp.val;
						odp.val=cp.val;
						odp.a=a;
						odp.b=b;
						odp.c=c;
						odp.d=d;
					}
				}
			}
		}
	}
	return odp;
}
ans bot(Szachownica plansza){
	arr res=dfs(plansza, 0, 0, -400, 400);
	return {res.a, res.b, res.c, res.d};
}
