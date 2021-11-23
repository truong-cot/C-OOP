#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

// Class
class tamGiac {
	private:
		float a;
		float b;
		float c;
		
	public:
		float cv;
		float dt;
				
		tamGiac();
		tamGiac(float a, float b, float c);
		
		void nhap();
		void dieuKien();
		void show();
		void chuVi();
		void dienTich();
};

tamGiac::tamGiac() {
	this -> a = 0;
	this -> b = 0;
	this -> c = 0;
}

tamGiac::tamGiac(float a, float b, float c){
	this->a = a;
	this->b = b;
	this->c = c;
}

void tamGiac::nhap() {
	cout << "Nhap vao canh a: "; cin >> a;
	cout << "Nhap vao canh b: "; cin >> b;
	cout <<"Nhap vao canh c: "; cin >> c;
	
	if (a+b < c || a+c < b || b+c < c || a < 0 || b < 0 || c < 0){
		cout << "3 canh cua tam giac khong hop le!!!\nNhap lai!\n";
	}
}
/*
void tamGiac::dieuKien() {
	if (a+b < c || a+c < b || b+c < c || a < 0 || b < 0 || c < 0){
		cout << "3 canh cua tam giac khong hop le!!!\nNhap lai!";
	}
}
*/
void tamGiac::show() {
	cout << "Do dai 3 canh vua nhap la: " << a << " ," << b << " ," << c;
}

void tamGiac::chuVi() {
	cv = a+b+c;
	cout << "Chu vi tam giac la: " << cv << endl;
}

void tamGiac::dienTich() {
	float p = (a+b+c)/2;
	dt = sqrt(p*(p-a)*(p-b)*(p-c));
	cout << "\nDien tich tam giac la: " << dt << endl;
}

// Chuong trinh chinh
int main() {
	float cv;
	tamGiac s;
	s.nhap();
	//s.dieuKien();
	s.show();
	s.chuVi();
	//cout << "\nChu vi tam giac la: " << s.chuVi() << endl;
	
	s.dienTich();
	//cout << "Dien tich la: " << s.dienTich() << endl;
		
	cout << endl;
	return 0;
}

// Ham: 

