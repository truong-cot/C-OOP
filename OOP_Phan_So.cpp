#include <iostream>
#include <math.h>

using namespace std;

// Khai bao lop
class PS {
	private:
		int tuso;
		int mauso;
		
	public:
		PS();
		PS(int tuso, int mauso);
		
		void nhap();
		void hien();
		
		PS tinhtong(PS a1, PS a2);
		
		int ucln(int tuso, int mauso);
		
		PS rutgon();
};

// CHuong trinh chinh
int main(void) {
	PS p1, p2, tong;
	cout << "Nhap vao phan so thu 1: " << endl;
	p1.nhap();
	
	cout << "Phan so vua nhap la: " ;
	p1.hien();
	
	cout << "\nNhap vao phan so thu 2: " << endl;
	p2.nhap();
	
	cout << "Phan so vua nhap la: " ;
	p2.hien();
	
	tong = tong.tinhtong(p1, p2);
	cout << "\nPhan so thu 1 + phan so thu 2 = " ;
	tong.hien();
	
	cout << "\nPhan so tong sau khi rut gon la: ";
	tong.rutgon();
	tong.hien();
	
	cout << endl;
	return 0;
}

// Dinh nghia ham
PS::PS() {
	this->tuso = 0;
	this->mauso = 0;
}

PS::PS(int tuso, int mauso) {
	this->tuso = tuso;
	this->mauso = mauso;
}

void PS::nhap() {
	cout << "Nhap vao tu so: ";
	cin >> tuso;
	cout << "Nhap vao mau so: ";
	cin >> mauso;
}

void PS::hien() {
	if(mauso < 0){
		tuso = tuso*(-1);
		mauso = mauso*(-1);
		cout << tuso << "/" << mauso << endl;
	}
	else {
		cout << tuso << "/" << mauso << endl;
	}
}

PS PS::tinhtong(PS a1, PS a2) {
	PS tg;
	tg.tuso = a1.tuso*a2.mauso + a2.tuso*a1.mauso;
	tg.mauso = a1.mauso*a2.mauso;
	return tg;
}

int PS::ucln(int tuso, int mauso) {
	if(tuso < 0){
		tuso = tuso*(-1);
	}
	if(mauso < 0){
		mauso = mauso*(-1);
	}
	for(int i= min(tuso, mauso); i > 0; i--) {
		if(tuso % i == 0 && mauso % i == 0){
			return i;
		}
	}
}

PS PS::rutgon() {
			int t = ucln(tuso, mauso);
			tuso = tuso/t;
			mauso = mauso/t;
		}
