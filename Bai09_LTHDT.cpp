#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

//Class
class SinhVien
{
    private:
        int maSV;
        char ten[8];
        float diemTBC;
        static int stt;
    public:
        void nhap();
        void hien();
        static int laySL();
};

int SinhVien::stt = 10;

//===Chuong trinh chinh===
int main() {
    SinhVien *sv;
    int size = 1;
    sv = new SinhVien[size];
    while(true) {

        //Yeu cau cho thao tac tiep theo
        char thaoTac[1];
        cout << "1.[Them SV] 2.[Hien thi danh sach] 0.[Thoat]" << endl;
        cout << ">>> ";cin >> thaoTac;

        //Them sinh vien vao danh sach
        if (strcmp(thaoTac, "1")==0)
        {
            while(true)
            {
                char tiepTuc[1];

                //Tao mang trung gian de luu gia tri mang hien tai
                SinhVien *mSV = new SinhVien[size];
                for (int i = 0; i < size; i++)
                {
                    mSV[i] = sv[i];
                }

                //Cap phat them bo nho cho mang
                size++;
                sv = new SinhVien[size];

                //Sao chep du lieu ve mang moi
                for (int i = 0; i < size-1; i++)
                {
                    sv[i] = mSV[i];
                }

                //Nhap thong tin  sinh vien
                //sv[sv->laySL()].nhap();
                
                sv.nhap();

                cout << "1.[Tiep tuc] 0.[Thoat]" << endl;
                cout << ">>> ";cin >> tiepTuc;

                if (strcmp(tiepTuc, "0")==0)
                {
                    break;
                }

                //Xoa mang trung gian
                delete []mSV;
            }
        }
        else if (strcmp(thaoTac, "2")==0)
        {
            cout << "So luong sinh vien la: " << sv->laySL() << endl;
            cout << "Hien thi danh sach\n";
            for (int i = 0; i < sv->laySL(); i++)
            {
                cout << "\nStt: " << i+1;
                sv[i].hien();
            }
        }
        else if (strcmp(thaoTac, "0")==0)
        {
            break;
        }
    }

    //Xoa mang dong
    delete []sv;

    cout<<endl;
    return 0;
}

//===Dinh nghia ham===
void SinhVien::nhap()
{
    //Tang so stt len 1
    SinhVien::stt++;
    maSV = SinhVien::stt;

    //Nhap ten va diemTBC
    cout << "\nNhap ten sinh vien: ";
    cin >> ten;
    cout << "\nNhap diem trung binh cong: ";
    cin >> diemTBC;
}

void SinhVien::hien()
{
    cout << "\nMaSV: " << maSV;
    cout << "\nTenSV: " << ten;
    cout << "\nDiemTBC: " << diemTBC;
    cout << "\n-----------------------" << endl;
}

int SinhVien::laySL()
{
    return SinhVien::stt - 10;
}
