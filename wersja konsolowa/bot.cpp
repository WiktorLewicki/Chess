//Autor: Wiktor Lewicki
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


const int MAX_DEPTH=5;
const int INF=400;
vector<ans> moves(Szachownica plansza){
	vector<ans> res1, res2;
	int last=plansza.ocena();
	for(int a=1;a<=8;a++){
		for(int b=1;b<=8;b++){
			for(int c=1;c<=8;c++){
				for(int d=1;d<=8;d++){
					Szachownica pomocnicza=plansza;
					int pm=pomocnicza.ruch_gracza(a, b, c, d, 0);
					if(!pm) continue;
					if(pomocnicza.ocena()!=last) res1.push_back({a, b, c, d});
					else res2.push_back({a, b, c, d});
				}
			}
		}
	}
	for(auto v : res2) res1.push_back(v);
	return res1;
}
arr dfs(Szachownica plansza, int depth, int pkt, int alpha, int beta){
	if(depth==MAX_DEPTH) return {0, 0, 0, 0, pkt};
	arr best;
	best.val=INF;
	if(plansza.kto()) best.val=-INF;
	vector<ans> ruchy=moves(plansza);
	for(auto v : ruchy){
		int a=v.a, b=v.b, c=v.c, d=v.d;
		Szachownica plansza_test=plansza;
		int pm=plansza_test.ruch_gracza(a, b, c, d, 0);
		arr cur;
		if(pm==-1){
			if(!plansza.kto()) cur={a, b, c, d, -500};
			else cur={a, b, c, d, 500};
		}
		else cur=dfs(plansza_test, depth+1, plansza_test.ocena(), alpha, beta);
		if(plansza.kto()&&cur.val>best.val){
			alpha=cur.val;
			best.val=cur.val;
			best.a=a;
			best.b=b;
			best.c=c;
			best.d=d;
		}
		else if(!plansza.kto()&&cur.val<best.val){
			beta=cur.val;
			best.val=cur.val;
			best.a=a;
			best.b=b;
			best.c=c;
			best.d=d;
		}
		if(beta<=alpha){
			return best;
		}
	}
	return best;
}
ans bot(Szachownica plansza){
	arr res=dfs(plansza, 0, 0, -INF, INF);
	return {res.a, res.b, res.c, res.d};
}
