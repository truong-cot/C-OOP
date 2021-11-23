#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

// Khai bao lop
class Diem {
	private:
		int tungDo;
		int hoanhDo;
		
	public:
		//Diem();
		//Diem(int tungDo, int hoangDo);
		friend istream& operator>>(istream &cin, Diem &p);
		friend ostream& operator<<(istream &cout, Diem &p);
		//float tinhKhoangCach(Diem a);
		
};

// Chuong trinh chinh
int main(void) {
	Diem A, B;
	//float kc;
	// Nhap vao 2 diem
	cout << "Nhap vao diem A: " << endl;
	cin>>A;
	cout << "Diem A vua nhap co toa do: ";
	//cout<<A; 
	
	cout << "\n\nNhap vao diem B: " << endl;
	cin>>B;
	cout << "Diem B vua nhap co toa do: ";
	//cout<<B;
	
	//kc = A.tinhKhoangCach(B);
	//cout << "\n\nKhoang cach giua 2 diem A va B la: " << kc ;
	
	cout << endl;
	return 0;
}

// Dinh nghia ham
/*
Diem::Diem(){
	this->tungDo = 0;
	this->hoanhDo = 0;
}

Diem::Diem(int tungDo, int hoangDo){
	this->tungDo = tungDo;
	this->hoanhDo = hoangDo;
}
*/
istream& operator>>(istream &cin, Diem &p) {
	cout << "Nhap vao tung do: ";
	cin >> p.tungDo;
	
	cout << "Nhap vao hoanh do: ";
	cin >> p.hoanhDo;
	
	return cin;
}
/*
float Diem::tinhKhoangCach(Diem a) {
	float khoangCach;
	khoangCach = sqrt((tungDo - a.tungDo)*(tungDo - a.tungDo) + (hoanhDo - a.hoanhDo)*(hoanhDo - a.hoanhDo));
	return khoangCach;
}
*/
ostream& operator<<(ostream &cout, Diem &p) {
	cout << "(" << p.tungDo << " , " << p.hoanhDo  << ")";
	
	return cout;
}
