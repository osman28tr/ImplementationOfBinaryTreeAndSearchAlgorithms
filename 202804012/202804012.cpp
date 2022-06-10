#include <iostream>
using namespace std;
#include <chrono>
#include <stdlib.h>
#include<stack>
#include<queue>

#define UZUNLUK 68	
int dizi1[] = { 1064,1065,1066,1067,1068,1069,1070,1071,1072,1073,1074,1075,1076,1077,1078,1079,1080,1081,1082,1083,2001,2002,2003,2004,2013,2014,2015,3001,3002,3003,3004,3005,3006,3007,3008,3009,3010,3011,3012,3013,3014,3015,3016,3017,3018,3019,3020,3021,3022,3023,3024,3025,3026,3027,3028,3029,3030,3031,3032,3033,3034,3035,3036,3037,3038,3039,3040,3041 };	
int dizi2[] = { 3041,3040,3039,3038,3037,3036,3035,3034,3033,3032,3031,3030,3029,3028,3027,3026,3025,3024,3023,3022,3021,3020,3019,3018,3017,3016,3015,3014,3013,3012,3011,3010,3009,3008,3007,3006,3005,3004,3003,3002,3001,2015,2014,2013,2004,2003,2002,2001,1083,1082,1081,1080,1079,1078,1077,1076,1075,1074,1073,1072,1071,1070,1069,1068,1067,1066,1065,1064 };	
int dizi3[] = { 3039,1074,3010,1082,3016,3005,3008,3014,3015,3023,3025,2002,3021,3035,1077,1065,1069,1073,3011,2004,3020,3001,3030,1076,1081,3031,3040,1071,3013,3029,3036,3027,3033,1070,3038,1068,1080,3037,2014,3003,3007,1072,1066,1083,2015,2003,3018,3024,3034,3009,3012,3019,3028,1078,3017,2001,1079,3041,1067,2013,3026,1064,3004,3022,3006,1075,3032,3002 };	

struct Dugum {		
	int veri; 		
	Dugum* sag;		
	Dugum* sol;  	
};
struct IkiliSiralamaAgaci {	
	Dugum* kok;			
	void agacKur(int*);	
	void agacKur(int veri, Dugum* aktifDugum); 
	void agacKapat();
	void agacBosalt(Dugum* p); 
	void preOrder(Dugum* aktifDugum); 
};

bool DFS(Dugum*, int);	
bool BFS(Dugum*, int);

int main()
{
	int agacTur;
	IkiliSiralamaAgaci* ikiliSiralamaAgaci = new IkiliSiralamaAgaci();
	cout << "Arama yapacaginiz agaci seciniz (1,2,3):" << endl;
	cin >> agacTur;
	if (agacTur == 1) {
		int aramaYontem, deger;
		ikiliSiralamaAgaci->agacKur(dizi1);

		cout << "Agac " << agacTur << " icin arama yontemini seciniz (DFS:1, BFS:2):" << endl;
		cin >> aramaYontem;

		if (aramaYontem == 1) {
			cout << "Agac " << agacTur << " uzerinde DFS ile arayacaginiz degeri giriniz:" << endl;
			cin >> deger;
			auto begin1 = std::chrono::high_resolution_clock::now();
			
			DFS(ikiliSiralamaAgaci->kok, deger);

			auto end1 = std::chrono::high_resolution_clock::now();
			auto elapsed1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - begin1);
			cout << " Gecen Sure = > " << elapsed1.count() << " nano-saniye" << endl;
			ikiliSiralamaAgaci->agacKapat();
		}
		else {
			cout << "Agac " << agacTur << " uzerinde BFS ile arayacaginiz degeri giriniz:" << endl;
			cin >> deger;
			auto begin1 = std::chrono::high_resolution_clock::now();

			BFS(ikiliSiralamaAgaci->kok, deger);

			auto end1 = std::chrono::high_resolution_clock::now();
			auto elapsed1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - begin1);
			cout << " Gecen Sure = > " << elapsed1.count() << " nano-saniye" << endl;

			ikiliSiralamaAgaci->agacKapat();
		}
	}
	else if (agacTur == 2) {
		int aramaYontem, deger;
		ikiliSiralamaAgaci->agacKur(dizi2);
		
		cout << "Agac " << agacTur << " icin arama yontemini seciniz (DFS:1, BFS:2):" << endl;
		cin >> aramaYontem;

		if (aramaYontem == 1) {
			cout << "Agac " << agacTur << " uzerinde DFS ile arayacaginiz degeri giriniz:" << endl;
			cin >> deger;
			auto begin1 = std::chrono::high_resolution_clock::now();
			
			DFS(ikiliSiralamaAgaci->kok, deger);

			auto end1 = std::chrono::high_resolution_clock::now();
			auto elapsed1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - begin1);
			cout << " Gecen Sure = > " << elapsed1.count() << " nano-saniye" << endl;
			ikiliSiralamaAgaci->agacKapat();
		}
		else {
			cout << "Agac " << agacTur << " uzerinde BFS ile arayacaginiz degeri giriniz:" << endl;
			cin >> deger;
			auto begin1 = std::chrono::high_resolution_clock::now();

			BFS(ikiliSiralamaAgaci->kok, deger);

			auto end1 = std::chrono::high_resolution_clock::now();
			auto elapsed1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - begin1);
			cout << " Gecen Sure = > " << elapsed1.count() << " nano-saniye" << endl;

			ikiliSiralamaAgaci->agacKapat();
		}
	}
	else {
		int aramaYontem, deger;
		ikiliSiralamaAgaci->agacKur(dizi3);
		
		cout << "Agac " << agacTur << " icin arama yontemini seciniz (DFS:1, BFS:2):" << endl;
		cin >> aramaYontem;

		if (aramaYontem == 1) {
			cout << "Agac " << agacTur << " uzerinde DFS ile arayacaginiz degeri giriniz:" << endl;
			cin >> deger;
			auto begin1 = std::chrono::high_resolution_clock::now();
			
			DFS(ikiliSiralamaAgaci->kok, deger);

			auto end1 = std::chrono::high_resolution_clock::now();
			auto elapsed1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - begin1);
			cout << " Gecen Sure = > " << elapsed1.count() << " nano-saniye" << endl;
			ikiliSiralamaAgaci->agacKapat();
		}
		else {
			cout << "Agac " << agacTur << " uzerinde BFS ile arayacaginiz degeri giriniz:" << endl;
			cin >> deger;
			auto begin1 = std::chrono::high_resolution_clock::now();

			BFS(ikiliSiralamaAgaci->kok, deger);

			auto end1 = std::chrono::high_resolution_clock::now();
			auto elapsed1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - begin1);
			cout << " Gecen Sure = > " << elapsed1.count() << " nano-saniye" << endl;

			ikiliSiralamaAgaci->agacKapat();
		}
	}
	return 0;
}
void IkiliSiralamaAgaci::agacKur(int* array) {
	Dugum* yeni1;
	bool eklendi = false;
	if (kok == NULL) {
		yeni1 = new Dugum();
		yeni1->sag = NULL;
		yeni1->sol = NULL;
		yeni1->veri = *(array);
		kok = yeni1;
		for (int i = 1; i < UZUNLUK; i++)
		{
			agacKur(*(array + i), kok);
		}
		return;
	}
}
void IkiliSiralamaAgaci::agacKur(int veri, Dugum* aktifDugum) {
	if (aktifDugum->veri > veri) {
		if ((aktifDugum->sol) != NULL) {
			agacKur(veri, aktifDugum->sol);
		}
		else
		{
			aktifDugum->sol = new Dugum();
			aktifDugum->sol->veri = veri;
		}
	}
	else if (aktifDugum->veri < veri) {
		if (aktifDugum->sag) {
			agacKur(veri, aktifDugum->sag);
		}
		else {
			aktifDugum->sag = new Dugum();
			aktifDugum->sag->veri = veri;
		}
	}
	else
		return;
}
void IkiliSiralamaAgaci::agacKapat() {
	agacBosalt(kok);
}
void IkiliSiralamaAgaci::agacBosalt(Dugum* p) {
	if (p) {
		if (p->sol != NULL) {
			agacBosalt(p->sol);
			p->sol = NULL;
		}
		if (p->sag != NULL) {
			agacBosalt(p->sag);
			p->sag = NULL;
		}
		delete p;
	}
}
void IkiliSiralamaAgaci::preOrder(Dugum* aktifDugum) {
	if (aktifDugum) {
		cout << aktifDugum->veri << " " << endl;
		preOrder(aktifDugum->sol);
		preOrder(aktifDugum->sag);
	}
}

bool DFS(Dugum* agackok, int deger) {
	Dugum* p;
	stack<Dugum*>yigin;
	yigin.push(agackok);
	while (!yigin.empty())
	{
		p = yigin.top();
		yigin.pop();
		
		if (deger==p->veri)
		{
			cout << "Sonuc=> Veri Bulundu" << endl;
			return true;
		}
		if (p->sag) {
			yigin.push(p->sag);
		}
		if (p->sol) {
			yigin.push(p->sol);
		}
	}
}
bool BFS(Dugum* agackok, int deger) {
	Dugum* p;
	queue<Dugum*>kuyruk;
	kuyruk.push(agackok);
	while (!kuyruk.empty())
	{
		p = kuyruk.front();
		kuyruk.pop();

		if (deger == p->veri)
		{
			cout << "Sonuc=> Veri Bulundu" << endl;
			return true;
		}
		if (p->sag) {
			kuyruk.push(p->sag);
		}
		if (p->sol) {
			kuyruk.push(p->sol);
		}
	}
}


