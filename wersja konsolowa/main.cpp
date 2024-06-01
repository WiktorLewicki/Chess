#include <bits/stdc++.h>
#include "bot.cpp"

//silnik ukończony, został jeszcze do znacznej poprawy bot i napisanie interfejsu graficznego
//szacuję że wszystko będzie ukończone w max kilka dni
using namespace std;

int main(){
	Szachownica gra;
	gra.init();
	gra.print(1);
	while(!gra.mat()){
		if(gra.kto()==0){
			cout<<"Rusza sie gracz 1\n";
			int a, b, c, d;
			cin>>a>>b>>c>>d;
			gra.ruch_gracza(a, b, c, d, 1);
		}
		else{
			cout<<"Rusza sie gracz 2\n";
			ans rb=bot(gra);
			gra.ruch_gracza(rb.a, rb.b, rb.c, rb.d, 0);
			gra.print(1);
		}
	}
	if(gra.kto()==0) cout<<"Wygral gracz 2\n";
	else cout<<"Wygral gracz 1 \n";
	return 0;
}
