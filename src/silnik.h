// Autor: Wiktor Lewicki
#ifndef SILNIK_H
#define SILNIK_H
#include <bits/stdc++.h>
using namespace std;
int gd(int a, int b, int c, int d); // Sprawdzanie czy na planszy

class Szachownica {
private:
    int p[9][9];
    int kb1, kb2, kc1, kc2;
    bool roszada1_1, roszada1_2, roszada2_1, roszada2_2;
    bool tura;

public:
    int how_many();
    int msc(int a, int b);
    int ocena();
    bool kto();
    void init(); // Przygotowanie planszy
    bool kogo_bierek(int a, int b); // Czyj pionek znajduje się na danym polu
    void move(int a, int b, int c, int d); // Wykonanie ruchu
    bool check_move(int a, int b, int c, int d, int tr); // Sprawdzanie legalności ruchu
    bool pod_atakiem(int a, int b); // Czy pole jest pod atakiem
    bool szach(); // Czy obecna sytuacja to szach
    bool spr(int a, int b, int c, int d); // Sprawdzanie, czy po ruchu król jest w szachu
    bool mat(); // Czy obecna sytuacja to mat
    bool pat(); // Czy obecna sytuacja to pat
    bool roszada(int a, int b, int c, int d); // Obsługa roszady
    void zamiana_pionka(int a, int b); // Zamiana pionka na hetmana
    void nadaj_moc(int a, int b, int moc); // Nadanie mocy figurom
    int ruch_gracza(int a, int b, int c, int d, bool show); // Obsługa ruchu gracza
};
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
vector<ans> moves(Szachownica plansza);
arr dfs(Szachownica plansza, int depth, int pkt, int alpha, int beta);
ans bot(Szachownica plansza);
#endif
