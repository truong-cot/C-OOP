 /*Bài 16(lthdtbai16.cpp): Đọc vào bán kính và màu nền (Xanh, Đỏ, Tím, Vàng) của n hình tròn
 từ tệp văn bản "hinhtron.txt". Đưa ra màn hình bán kính, màu nền, diện tích và chu vi
 của các hình tròn. Tính tổng diện tích và chu vi của n hình tròn.
 Đếm số lượng hình tròn có nền màu Xanh, Đỏ, Tím, Vàng.
*/

#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>

using namespace std;

//Khai báo lớp
class HinhTron
{
    private:
        float r;
        char mauNen[6];

    public:
        void thietLapBanKinh(float r);
        void thietLapMauNen(const char *mauNen);
        void hien();
        float tinhDT();
        float tinhCV();
        int layMaMau();
};

//===chuong trinh chinh===
int main()
{
    //Tao doi tuong tep vao
    ifstream fin("hinhtron.txt");

    //Khai bao bien
    int n;
    float r,tongCV=0,tongDT=0;
    char mauNen[6];
    int dem[4] = {0};
    char dayMau[4][6] = {"Xanh","Đỏ","Tím","Vàng"};

    //Doc vao so luong hinh tron tu tep
    fin>>n;

    //Tao mang dong n doi tuong hinh tron
    HinhTron *dsht = new HinhTron[n];

    //Doc thong tin cua n hinh tron tu tep vao cac doi tuong hinh tron
    for(int i=0;i<n;i++)
    {
        //Doc ban kinh va mau nen tu tep
        fin>>r>>mauNen;

        //Dua ban kinh va mau nen vao doi tuong
        dsht[i].thietLapBanKinh(r);
        dsht[i].thietLapMauNen(mauNen);

        //Dua ra thong tin ve hinh tron
        cout<<"Hình tròn thứ "<<i+1<<": ";
        dsht[i].hien();
        cout<<"\n";

        //Tinh tong chu vi va dien tich
        tongCV +=dsht[i].tinhCV();
        tongDT +=dsht[i].tinhDT();

        //dem so luong hinh tron theo tung mau nen
        dem[dsht[i].layMaMau()]++;
    }


    printf("\nTổng chu vi của %d hình tròn là: %0.1f",n,tongCV);
    printf("\nTổng diện diện tích của %d hình tròn là: %0.1f",n,tongDT);
    printf("\nSố lượng hình tròn theo các màu là: \n");
    for(int i=0;i<4;i++)
    {
        cout<<dayMau[i]<<": "<<dem[i]<<endl;
    }

    //huy mang dong
    delete [] dsht;

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
void HinhTron::thietLapBanKinh(float r)
{
    this->r = r;
}

void HinhTron::thietLapMauNen(const char *mauNen)
{
    strcpy(this->mauNen,mauNen);
}

void HinhTron::hien()
{
    printf("Hình tròn có:");
    printf("\n\tBán kính: %0.1f",r);
    printf("\n\tMàu nền: %s",mauNen);
    printf("\n\tDiện tích: %0.1f",3.14*r*r);
    printf("\n\tChu vi : %0.1f",2*3.14*r);
}

float HinhTron::tinhDT()
{
    return 3.14*r*r;
}

float HinhTron::tinhCV()
{
    return 2*3.14*r;
}

int HinhTron::layMaMau()
{
    if(strcasecmp(mauNen,"Xanh")==0) return 0;
    if(strcasecmp(mauNen,"Đỏ")==0) return 1;
    if(strcasecmp(mauNen,"Tím")==0) return 2;
    if(strcasecmp(mauNen,"Vàng")==0) return 3;
}
