#include <bits/stdc++.h>
using namespace std;
int gd(int a, int b, int c, int d){//sprawdzanie czy na planszy
	if(a<1||a>8||b<1||b>8||c<1||c>8||d<1||d>8) return false;
	return true;
}
vector<array<int, 4>> history;
class Szachownica{
	public:///////////////////////////////
	int p[9][9];
	int kb1, kb2, kc1, kc2;
	bool tura, roszada1_1, roszada1_2, roszada2_1, roszada2_2;
	public:
	void print(){//czytanie planszy
		system("cls");
		cout<<"  ";
		for(int i=1;i<=8;i++){
			cout<<"  "<<i<<" ";
		}
		cout<<"\n";
		string pm="  +---+---+---+---+---+---+---+---+\n";
		for(int i=1;i<=8;i++){
			cout<<pm;
			cout<<i<<" ";
			for(int j=1;j<=8;j++){
				if(p[i][j]<10) cout<<"| "<<p[i][j]<<" ";
				else cout<<"|"<<p[i][j]<<" ";
			}
			cout<<"|\n";
		}
		cout<<pm;
	}
	void init(){//przygotowanie planszy
		for(int i=1;i<=8;i++){
			for(int j=1;j<=8;j++){
				p[i][j]=0;
			}
		}
		for(int i=1;i<=8;i++){
			p[7][i]=1;//pion biały
			p[2][i]=7;//pion czarny
		}
		p[8][1]=p[8][8]=2;//wieża biała
		p[8][2]=p[8][7]=3;//skoczek biały
		p[8][3]=p[8][6]=4;//goniec biały
		p[8][4]=5;//hetman biały
		p[8][5]=6;//król biały
		p[1][1]=p[1][8]=8;//wieża czarna
		p[1][2]=p[1][7]=9;//skoczek czarny
		p[1][3]=p[1][6]=10;//goniec czarny
		p[1][4]=11;//hetman czarny
		p[1][5]=12;//król czarny
		
		
		tura=false;
		kb1=8, kb2=5;
		kc1=1, kc2=5;
		roszada1_1=roszada1_2=roszada2_1=roszada2_2=true;
	}
	bool kogo_bierek(int a, int b){//kogo bierek
		if(p[a][b]<=6) return 0;
		else return 1;
	}
	void move(int a, int b, int c, int d){//zrobienie ruchu
		p[c][d]=p[a][b];
		p[a][b]=0;
		if(p[c][d]==6){
			kb1=c, kb2=d;
		}
		if(p[c][d]==12){
			kc1=c, kc2=d;
		}
	}
	bool check_move(int a, int b, int c, int d, int tr){//sprawdzenie legalności ruchu nie patrząc na zasady typu szach
		if(!p[a][b]||kogo_bierek(a, b)!=tr) return false;
		if(a==c&&b==d) return false;
		if(p[c][d]&&kogo_bierek(c, d)==tr) return false;
		if(p[a][b]==1||p[a][b]==7){//pionek
			int dr=1, pk=7;
			if(tr){
				dr=-1;
				pk=2;
			}
			if((pk==2||pk==7)&&c==a-2*dr&&b==d&&!p[a-1*dr][b]&&!p[a-2*dr][b]) return true;
			else if(c==a-1*dr&&b==d&&!p[a-1*dr][b]) return true;
			else if(c==a-1*dr&&(d==b-1||d==b+1)&&p[c][d]) return true;
		}
		else if(p[a][b]==2||p[a][b]==8){//wieża
			if(a==c){
				int dr=1;
				if(b>d) dr=-1;
				for(int i=b+dr;;i+=dr){
					if(i==d) return true;
					if(p[a][i]) break;
				}
			}
			else if(b==d){
				int dr=1;
				if(a>c) dr=-1;
				for(int i=a+dr;;i+=dr){
					if(i==c) return true;
					if(p[i][b]) break;
				}
			}
		}
		else if(p[a][b]==3||p[a][b]==9){//skoczek
			int vr1=abs(a-c), vr2=abs(b-d);
			if((vr1==2&&vr2==1)||(vr1==1&&vr2==2)) return true;
		}
		else if(p[a][b]==4||p[a][b]==10){//goniec
			if(abs(a-c)==abs(b-d)){
				int dr1=1, dr2=1;
				if(a>c) dr1=-1;
				if(b>d) dr2=-1;
				int pm1=a+dr1, pm2=b+dr2;
				while(true){
					if(pm1==c&&pm2==d) return true;
					if(p[pm1][pm2]) break;
					pm1+=dr1, pm2+=dr2;
				}
			}
		}
		else if(p[a][b]==5||p[a][b]==11){//hetman
			if(a==c){
				int dr=1;
				if(b>d) dr=-1;
				for(int i=b+dr;;i+=dr){
					if(i==d) return true;
					if(p[a][i]) break;
				}
			}
			else if(b==d){
				int dr=1;
				if(a>c) dr=-1;
				for(int i=a+dr;;i+=dr){
					if(i==c) return true;
					if(p[i][b]) break;
				}
			}
			if(abs(a-c)==abs(b-d)){
				int dr1=1, dr2=1;
				if(a>c) dr1=-1;
				if(b>d) dr2=-1;
				int pm1=a+dr1, pm2=b+dr2;
				while(true){
					if(pm1==c&&pm2==d) return true;
					if(p[pm1][pm2]) break;
					pm1+=dr1, pm2+=dr2;
				}
			}
		}
		else if(p[a][b]==6||p[a][b]==12){
			if(abs(a-c)<2&&abs(b-d)<2) return true;
		}
		return false;
	}
	bool pod_atakiem(int a, int b){//czy pole pod atakiem
		for(int i=1;i<=8;i++){
			for(int j=1;j<=8;j++){
				if(p[i][j]&&kogo_bierek(i, j)!=tura&&check_move(i, j, a, b, !tura)){
					return true;
				}
			}
		}
		return false;
	}
	bool szach(){//czy teraz jest szach
		if(!tura) return pod_atakiem(kb1, kb2);
		else return pod_atakiem(kc1, kc2);
	}
	bool spr(int a, int b, int c, int d){// czy po tym ruchu dalej jestem pod szachem
		int sv=p[c][d];
		move(a, b, c, d);
		int zp=szach();
		move(c, d, a, b);
		p[c][d]=sv;
		return zp;
	}
	bool mat(){//czy koniec gry
		if(!szach()) return false;
		for(int i=1;i<=8;i++){
			for(int j=1;j<=8;j++){
				for(int k=1;k<=8;k++){
					for(int l=1;l<=8;l++){
						if(check_move(i, j, k, l, tura)){
							if(!spr(i, j, k, l)) return false;
						}
					}
				}
			}
		}
		return true;
	}
	bool roszada(int a, int b, int c, int d){//roszada
		if(szach()) return false;
		if(a==8&&b==5&&c==8&&d==3){
			if(roszada1_1&&!p[8][4]&&!p[8][3]&&!p[8][2]&&!pod_atakiem(8, 5)&&!pod_atakiem(8, 4)&&!pod_atakiem(8, 3)){
				roszada1_1=roszada1_2=false;
				return true;
			}
		}
		if(a==8&&b==5&&c==8&&d==7){
			if(roszada1_2&&!p[8][6]&&!p[8][7]&&!pod_atakiem(8, 5)&&!pod_atakiem(8, 6)&&!pod_atakiem(8, 7)){
				roszada1_1=roszada1_2=false;
				return true;
			}
		}
		if(a==1&&b==5&&c==1&&d==3){
			if(roszada2_1&&!p[1][4]&&!p[1][3]&&!p[1][2]&&!pod_atakiem(1, 5)&&!pod_atakiem(1, 4)&&!pod_atakiem(1, 3)){
				roszada2_1=roszada2_2=false;
				return true;
			}
		}
		if(a==1&&b==5&&c==1&&d==7){
			if(roszada2_2&&!p[1][6]&&!p[1][7]&&!pod_atakiem(1, 5)&&!pod_atakiem(1, 6)&&!pod_atakiem(1, 7)){
				roszada2_1=roszada2_2=false;
				return true;
			}
		}
		return false;
	}
	void zamiana_pionka(int a, int b){
		cout<<"PODAJ NA CO ZAMIENIC PIONKA:\n";
		cout<<"1->Wieza\n";
		cout<<"2->Skoczek\n";
		cout<<"3->Goniec\n";
		cout<<"4->DAMA\n";
		int nw;
		cin>>nw;
		p[a][b]=nw+1+6*tura;
	}
	int ruch_gracza(int a, int b, int c, int d){
		history.push_back({a, b, c, d});
		if(a==0&&b==0&&c==0&&d==0){
			for(auto v : history){
				cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<" "<<v[3]<<"\n";
			}
			_sleep(100000);
			exit(0);
		}
		if(!gd(a, b, c, d)){
			print();
			cout<<"Pole poza plansza\n";
			return 0;
		}
		if(!p[a][b]||kogo_bierek(a, b)!=tura){
			print();
			cout<<"Tu nie ma twojego pionka\n";
			return 0;
		}
		if(roszada(a, b, c, d)){//roszada-dobry ruch
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
			print();
			tura=!tura;
			if(mat()) return -1;
			return 1;
		}
		else if(check_move(a, b, c, d, tura)){//dobry ruch, bez roszady
			if(spr(a, b, c, d)){
				print();
				cout<<"Nie mozesz zrobic takiego ruchu bo jestes/bedziesz pod szachem\n";
				return 0;
			}
			if(roszada1_1&&((a==8&&b==1)||(c==8&&d==1))) roszada1_1=false;
			if(roszada1_2&&((a==8&&b==8)||(c==8&&d==8))) roszada1_2=false;
			if(a==8&&b==5) roszada1_1=roszada1_2=false;
			if(roszada2_1&&((a==1&&b==1)||(c==1&&d==1))) roszada2_1=false;
			if(roszada2_2&&((a==1&&b==8)||(c==1&&d==8))) roszada2_2=false;
			if(a==1&&b==5) roszada2_1=roszada2_2=false;
			
			move(a, b, c, d);
			print();
			if(c==1&&p[c][d]==1) zamiana_pionka(c, d);
			if(c==8&&p[c][d]==7) zamiana_pionka(c, d);
			print();
			tura=!tura;
			if(mat()) return -1;
			return 1;
		}
		else{//zły ruch
			print();
			cout<<"nie mozesz zrobic takiego ruchu\n";
			return 0;
		}
	}
};
int main(){
	Szachownica gra;
	gra.init();
	gra.print();
	while(!gra.mat()){
		if(gra.tura==0) cout<<"Rusza sie gracz 1\n";
		else cout<<"Rusza sie gracz 2\n";
		cout<<"Podaj pole pionka x1, y1, i pole docelowe x2, y2\n";
		int a, b, c, d;
		cin>>a>>b>>c>>d;
		gra.ruch_gracza(a, b, c, d);
	}
	if(gra.tura==0) cout<<"Wygral gracz 2\n";
	else cout<<"Wygral gracz 1 \n";
	
	return 0;
}
