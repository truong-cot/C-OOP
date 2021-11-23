#include <iostream>
#include <math.h>

using namespace std;

// Khai bao lop:
class SoPhuc {
	private:
		float a; // Phan thuc cua so phuc
		float b; // Phan ao cua so phuc
		
	public:
		SoPhuc(); // Khai bao contructor 0 tham so
		SoPhuc(float a, float b);
		void operator>>(SoPhuc a);
		void hienthi();
		
		// Ham tinh tong tra ve so phuc
		SoPhuc tong(SoPhuc p1, SoPhuc p2);
};

// Chuong trinh chinh 
int main(void) {
	SoPhuc a1, a2, a;
	cout << "Nhap vao so phuc a1: " << endl;
	operator>>a1;
	cout << "So phuc a1 la: ";
	a1.hienthi();
	
	cout << "\n\nNhap vao so phuc a2: " << endl;
	operator>>a2;
	cout << "So phuc a2 la: ";
	a2.hienthi();
	
	// Tinh tong
	a = a.tong(a1, a2);
	cout << "\n\nTong cua 2 so phuc a1 + a2 la: ";
	a.hienthi();
	
	cout << endl;
	return 0;
}

// Dinh nghia ham:
SoPhuc::SoPhuc() {
	this->a = 0;
	this->b = 0;
}

SoPhuc::SoPhuc(float a, float b) {
	this->a = a;
	this->b = b;
}

void SoPhuc::operator>>(SoPhuc a) {
	cout << "Nhap vao phan thuc: ";
	cin >> a;
	cout << "Nhap vao phan ao: ";
	cin >> b;
}

SoPhuc SoPhuc::tong(SoPhuc p1, SoPhuc p2) {
	SoPhuc p;
	p.a = p1.a + p2.a;
	p.b = p1.b + p2.b;
	return p;
	
}


void SoPhuc::hienthi() {
	if(b < 0) {
		cout << a << " - " << -b << "j";
	}
	else {
		cout << a << " + " << b << "j";
	}
}
