//Ho ten: Le Tuan Tu
//MaSV: 653321
//Lop: K65CNPMA
//De:
/*
B�i 21(lthdtbai21.cpp): T�nh tong 2 ma tran nguy�n: Cmxn = Amxn + Bmxn. Ma tran Amxn doc trong
tep van ban "matran-A.txt", ma tran Bmxn doc trong tep van ban "matran-B.txt".
�ua c�c ma tran ra m�n h�nh theo dinh dang h�ng, cot.
Y�u cau th�m:
1) Su dung to�n tu nhap >> de doc v�o ma tran tu tep;
2) Su dung to�n tu xuat << de dua ma tr?n ra m�n h�nh theo dinh dang h�ng, cot;
3) Su dung to�n tu + de cong 2 ma tran v� tra ve ma tran tong;
4) C� the tu dong khoi tao k�ch thuoc bang 0.
*/

#include<iostream>
#include<fstream>
#include<stdio.h>

using namespace std;

//Khai bao lop doi tuong ma tran
class MaTran
{
    private:
        enum {size=10};
        int a[size][size];
        int m,n;

    public:
        MaTran();
        MaTran operator+(MaTran &mt2);

        //Ham ban
        friend ifstream& operator>>(ifstream &fin,MaTran &mt);
        friend ostream& operator<<(ostream &cout,MaTran &mt);
};

//===chuong trinh chinh===
int main()
{

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
MaTran::MaTran()
{

}

MaTran MaTran::operator+(MaTran &mt2)
{

}

//Ham ban
ifstream& operator>>(ifstream &fin,MaTran &mt)
{	
	for(int i = 1; i <= mt.m; i++){
		for(int j = 1; j <= mt.n; j++){
		}
	}
    return fin;
}

ostream& operator<<(ostream &cout,MaTran &mt)
{

    return cout;
}

