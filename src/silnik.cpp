#include <bits/stdc++.h>
#include "silnik.h"
using namespace std;
int MAX_DEPTH=4;
const int INF=600;
int gd(int a, int b, int c, int d) {
    if (a < 1 || a > 8 || b < 1 || b > 8 || c < 1 || c > 8 || d < 1 || d > 8) return false;
    return true;
}

int Szachownica::how_many() {
    int _cnt = 0;
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            if (p[i][j]) _cnt++;
        }
    }
    return _cnt;
}

int Szachownica::msc(int a, int b) {
    return p[a][b];
}

int Szachownica::ocena() {
    int res = 0;
    for (int a = 1; a <= 8; a++) {
        for (int b = 1; b <= 8; b++) {
            int z = p[a][b], pm = 0;
            if (!z) continue;
            else if (z == 1) pm = -1;
            else if (z == 2) pm = -5;
            else if (z == 3) pm = -3;
            else if (z == 4) pm = -3;
            else if (z == 5) pm = -9;
            else if (z == 6) pm = -90;
            else if (z == 7) pm = 1;
            else if (z == 8) pm = 5;
            else if (z == 9) pm = 3;
            else if (z == 10) pm = 3;
            else if (z == 11) pm = 9;
            else if (z == 12) pm = 90;
            res += pm;
        }
    }
    return res;
}

bool Szachownica::kto() {
    return tura;
}

void Szachownica::init() {
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            p[i][j] = 0;
        }
    }
    for (int i = 1; i <= 8; i++) {
        p[7][i] = 1; // pion biały
        p[2][i] = 7; // pion czarny
    }
    p[8][1] = p[8][8] = 2; // wieża biała
    p[8][2] = p[8][7] = 3; // skoczek biały
    p[8][3] = p[8][6] = 4; // goniec biały
    p[8][4] = 5;           // hetman biały
    p[8][5] = 6;           // król biały
    p[1][1] = p[1][8] = 8; // wieża czarna
    p[1][2] = p[1][7] = 9; // skoczek czarny
    p[1][3] = p[1][6] = 10; // goniec czarny
    p[1][4] = 11;           // hetman czarny
    p[1][5] = 12;           // król czarny
    tura = false;
    kb1 = 8, kb2 = 5;
    kc1 = 1, kc2 = 5;
    roszada1_1 = roszada1_2 = roszada2_1 = roszada2_2 = true;
}

bool Szachownica::kogo_bierek(int a, int b) {
    return p[a][b] > 6;
}

void Szachownica::move(int a, int b, int c, int d) {
    p[c][d] = p[a][b];
    p[a][b] = 0;
    if (p[c][d] == 6) {
        kb1 = c, kb2 = d;
    }
    if (p[c][d] == 12) {
        kc1 = c, kc2 = d;
    }
}

bool Szachownica::check_move(int a, int b, int c, int d, int tr) {
    if (!p[a][b] || kogo_bierek(a, b) != tr) return false;
    if (a == c && b == d) return false;
    if (p[c][d] && kogo_bierek(c, d) == tr) return false;
    if (p[a][b] == 1 || p[a][b] == 7) {
        int dr = (tr ? -1 : 1), pk = (tr ? 2 : 7);
        if (pk == a && c == a - 2 * dr && b == d && !p[a - dr][b] && !p[a - 2 * dr][b]) return true;
        else if (c == a - dr && b == d && !p[a - dr][b]) return true;
        else if (c == a - dr && (d == b - 1 || d == b + 1) && p[c][d]) return true;
    } else if (p[a][b] == 2 || p[a][b] == 8) {
        if (a == c) {
            int dr = (b > d ? -1 : 1);
            for (int i = b + dr;; i += dr) {
                if (i == d) return true;
                if (p[a][i]) break;
            }
        } else if (b == d) {
            int dr = (a > c ? -1 : 1);
            for (int i = a + dr;; i += dr) {
                if (i == c) return true;
                if (p[i][b]) break;
            }
        }
    } else if (p[a][b] == 3 || p[a][b] == 9) {
        int vr1 = abs(a - c), vr2 = abs(b - d);
        if ((vr1 == 2 && vr2 == 1) || (vr1 == 1 && vr2 == 2)) return true;
    } else if (p[a][b] == 4 || p[a][b] == 10) {
        if (abs(a - c) == abs(b - d)) {
            int dr1 = (a > c ? -1 : 1), dr2 = (b > d ? -1 : 1);
            int pm1 = a + dr1, pm2 = b + dr2;
            while (true) {
                if (pm1 == c && pm2 == d) return true;
                if (p[pm1][pm2]) break;
                pm1 += dr1, pm2 += dr2;
            }
        }
    } else if (p[a][b] == 5 || p[a][b] == 11) {
        if (a == c) {
            int dr = (b > d ? -1 : 1);
            for (int i = b + dr;; i += dr) {
                if (i == d) return true;
                if (p[a][i]) break;
            }
        } else if (b == d) {
            int dr = (a > c ? -1 : 1);
            for (int i = a + dr;; i += dr) {
                if (i == c) return true;
                if (p[i][b]) break;
            }
        }
        if (abs(a - c) == abs(b - d)) {
            int dr1 = (a > c ? -1 : 1), dr2 = (b > d ? -1 : 1);
            int pm1 = a + dr1, pm2 = b + dr2;
            while (true) {
                if (pm1 == c && pm2 == d) return true;
                if (p[pm1][pm2]) break;
                pm1 += dr1, pm2 += dr2;
            }
        }
    } else if (p[a][b] == 6 || p[a][b] == 12) {
        if (abs(a - c) < 2 && abs(b - d) < 2) return true;
    }
    return false;
}

bool Szachownica::pod_atakiem(int a, int b) {
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            if (p[i][j] && kogo_bierek(i, j) != tura && check_move(i, j, a, b, !tura)) {
                return true;
            }
        }
    }
    return false;
}

bool Szachownica::szach() {
    if (!tura) return pod_atakiem(kb1, kb2);
    else return pod_atakiem(kc1, kc2);
}

bool Szachownica::spr(int a, int b, int c, int d) {
    int sv = p[c][d];
    move(a, b, c, d);
    int zp = szach();
    move(c, d, a, b);
    p[c][d] = sv;
    return zp;
}

bool Szachownica::mat() {
    if (!szach()) return false;
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            for (int k = 1; k <= 8; k++) {
                for (int l = 1; l <= 8; l++) {
                    if (check_move(i, j, k, l, tura)) {
                        if (!spr(i, j, k, l)) return false;
                    }
                }
            }
        }
    }
    return true;
}

bool Szachownica::pat() {
    for (int a = 1; a <= 8; a++) {
        for (int b = 1; b <= 8; b++) {
            if (!p[a][b] || kogo_bierek(a, b) != tura) continue;
            for (int c = 1; c <= 8; c++) {
                for (int d = 1; d <= 8; d++) {
                    if (check_move(a, b, c, d, tura) && !spr(a, b, c, d)) return false;
                }
            }
        }
    }
    return true;
}

bool Szachownica::roszada(int a, int b, int c, int d) {
    if (szach()) return false;
    if (a == 8 && b == 5 && c == 8 && d == 3) {
        if (roszada1_1 && !p[8][4] && !p[8][3] && !p[8][2] && !pod_atakiem(8, 5) && !pod_atakiem(8, 4) && !pod_atakiem(8, 3)) {
            roszada1_1 = roszada1_2 = false;
            return true;
        }
    }
    if (a == 8 && b == 5 && c == 8 && d == 7) {
        if (roszada1_2 && !p[8][6] && !p[8][7] && !pod_atakiem(8, 5) && !pod_atakiem(8, 6) && !pod_atakiem(8, 7)) {
            roszada1_1 = roszada1_2 = false;
            return true;
        }
    }
    if (a == 1 && b == 5 && c == 1 && d == 3) {
        if (roszada2_1 && !p[1][4] && !p[1][3] && !p[1][2] && !pod_atakiem(1, 5) && !pod_atakiem(1, 4) && !pod_atakiem(1, 3)) {
            roszada2_1 = roszada2_2 = false;
            return true;
        }
    }
    if (a == 1 && b == 5 && c == 1 && d == 7) {
        if (roszada2_2 && !p[1][6] && !p[1][7] && !pod_atakiem(1, 5) && !pod_atakiem(1, 6) && !pod_atakiem(1, 7)) {
            roszada2_1 = roszada2_2 = false;
            return true;
        }
    }
    return false;
}

void Szachownica::zamiana_pionka(int a, int b) {
    p[a][b] = 5 + 6 * (!tura);
}

void Szachownica::nadaj_moc(int a, int b, int moc) {
    p[a][b] = moc + 1;
}

int Szachownica::ruch_gracza(int a, int b, int c, int d, bool show){
	if(!gd(a, b, c, d)){
		return 0;
	}
	if(!p[a][b]||kogo_bierek(a, b)!=tura){
		return 0;
	}
	if(roszada(a, b, c, d)){
		if(a==8&&b==5&&c==8&&d==3){
			move(8, 5, 8, 3);
			move(8, 1, 8, 4);
		}
		if(a==8&&b==5&&c==8&&d==7){
			move(8, 5, 8, 7);
			move(8, 8, 8, 6);
		}
		if(a==1&&b==5&&c==1&&d==3){
			move(1, 5, 1, 3);
			move(1, 1, 1, 4);
		}
		if(a==1&&b==5&&c==1&&d==7){
			move(1, 5, 1, 7);
			move(1, 8, 1, 6);
		}
		tura=!tura;
		if(mat()) return -1;
		return 1;
	}
	else if(check_move(a, b, c, d, tura)){
		if(spr(a, b, c, d)){
			return 0;
		}
		if(roszada1_1&&((a==8&&b==1)||(c==8&&d==1))) roszada1_1=false;
		if(roszada1_2&&((a==8&&b==8)||(c==8&&d==8))) roszada1_2=false;
		if(a==8&&b==5) roszada1_1=roszada1_2=false;
		if(roszada2_1&&((a==1&&b==1)||(c==1&&d==1))) roszada2_1=false;
		if(roszada2_2&&((a==1&&b==8)||(c==1&&d==8))) roszada2_2=false;
		if(a==1&&b==5) roszada2_1=roszada2_2=false;
		move(a, b, c, d);
        tura=!tura;
        if(c==1&&p[c][d]==1){
            if(!show) zamiana_pionka(c, d);
            else return 2;
        }
        if(c==8&&p[c][d]==7){
            if(!show) zamiana_pionka(c, d);
            else return 2;
        }
		if(mat()) return -1;
		return 1;
	}
    else return 0;
}
vector<ans> moves(Szachownica plansza){
    vector<ans> res1, res2;
    int last=plansza.ocena();
    if(plansza.how_many()<20){
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
    }
    else{
        for(int a=8;a>=1;a--){
            for(int b=8;b>=1;b--){
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
    }
    random_shuffle(res2.begin(), res2.end());
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
