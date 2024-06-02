//Autor: Wiktor Lewicki
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


int MAX_DEPTH=4;
const int INF=600;
vector<ans> moves(Szachownica plansza){
	vector<ans> res1, res2;
	int last=plansza.ocena();
    for(int a=1;a<=8;a++){
        for(int b=1;b<=8;b++){
            for(int c=8;c>=1;c--){
                for(int d=8;d>=1;d--){
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
            if(!plansza.kto()) cur.val=-500;
            else cur.val=500;
        }
        else if(plansza_test.pat()){
            if(plansza.kto()){
                if(plansza.ocena()>=0) cur.val=-3;
                else cur.val=3;
            }
            else{
                if(plansza.ocena()>0) cur.val=3;
                else cur.val=-3;
            }
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
            break;
		}
	}
	return best;
}
ans bot(Szachownica plansza){
    int pm=plansza.how_many();
    if(pm<=16) MAX_DEPTH=5;
    if(pm<=8) MAX_DEPTH=6;
	arr res=dfs(plansza, 0, 0, -INF, INF);
	return {res.a, res.b, res.c, res.d};
}
