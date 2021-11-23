#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;

class NGUOI
	{
		public:
			char ht[25],cmt[25],qq[25];
			int tuoi;
		public:
			NGUOI()
				{
					strcpy(ht,"");
					tuoi=0;
					strcpy(cmt,"");
					strcpy(qq,"");
					
				}
			NGUOI(NGUOI& x)
				{
					strcpy(this->ht,x.ht);
					this->tuoi=x.tuoi;
					strcpy(this->cmt,x.cmt);
					strcpy(this->qq,x.qq);
				}
			~NGUOI(){}
			friend istream& operator >> (istream& in,NGUOI& x)
				{
					in.ignore();
					cout<<"Nhap Ho Ten: ";in.getline(x.ht,25);
					cout<<"Nhap So CMT: ";in.getline(x.cmt,25);
					cout<<"Nhap Que Quan: ";in.getline(x.qq,25);
					cout<<"Nhap Tuoi: ";in>>x.tuoi;
				}
			friend ostream& operator << (ostream& ou,NGUOI& x)
				{
					ou<<x.ht<<setw(15)<<x.tuoi<<setw(15)<<x.cmt<<setw(15)<<x.qq;
				}
		
	};
class CTBD:public NGUOI
	{
		private:
			char vt[25];
			int sb;
		public:
			CTBD()
				{
					strcpy(vt,"");
					sb=0;
				}	
			CTBD(CTBD& y)
				{
					strcpy(this->vt,y.vt);
					this->sb=y.sb;
				}
			~CTBD(){}
			friend istream& operator >> (istream& in, CTBD& y)
				{
					in>>(NGUOI&)y;
					in.ignore();
					cout<<"Nhap Vi Tri: ";in.getline(y.vt,25);
					cout<<"Nhap So Ban Thawng: ";in>>y.sb;
				}
			friend ostream& operator << (ostream& ou, CTBD& y)
				{
					ou<<(NGUOI&)y<<setw(15)<<y.vt<<setw(15)<<y.sb;
				}
			int phucap()
				{
					if (tuoi>30) return 5;
						else if (tuoi>20) return 3;
							else return 2;
				}	
			float operator > (CTBD& y)
				{
					 return sb>=y.sb;
				}
			int operator == (char*s)
				{
					return strcmp(ht,s)==0;
				}				
	};
	
	
void xuat()
{
cout<<"\nHo Ten"<<setw(15)<<"Tuoi"<<setw(15)<<"So CMT"<<setw(15)<<"Que Quan"<<setw(15)<<"Vi Tri"<<setw(15)<<"So BT"<<setw(20)<<"Phu Cap"<<endl;	
}	

void Menu() 
{
	cout << "=================MENU================\n";
	cout << "1. Kiem tra co trung so CMT hay khong!\n";
	cout << "2. D/S sap xep tang dan theo so ban thang!\n";
	cout << "3. Tim cau thu co Phu cap nho nhat!\n";
	cout << "4. Tim cau thu theo ten duoc nhap!\n";
	cout << "5. Them cau thu vao cuoi d/s\n";
	cout << "6. Them cau thu vao vi tri k\n";
	cout << "7. Sua tt cau thu theo so CMT\n";
	cout << "8. Xoa cau thu theo so CMT\n";
	cout << "9. Thoat!!!\n";
	cout << "=====================================\n";
}
int ChonMenu()
{
	int ni = 0;
	cout << "\n\nMoi chon menu: ";
	cin >> ni;
	if (ni > 0 || ni < 10)
		return ni;
	else return ChonMenu();
}

int main()
	{
		int m,n;
		int tam=0;
		int pos=0;
		int xoa=0;
		int kq=0;
		char ten[25];
		char cmthu[25];
		char cmthu2[25];
		CTBD temp;
		NGUOI *x;
		cout<<"Nhap so luong NGUOI: ";cin>>n;
		x=new NGUOI[n];
		for (int i=0;i<n;i++)
			{
				cout<<"\nNhap so luong NGUOI thu "<<i+1<<" la: "<<endl;
				cin>>x[i];
			}
		cout<<"\nHo Ten"<<setw(15)<<"Tuoi"<<setw(15)<<"So CMT"<<setw(15)<<"Que Quan"<<endl;	
		for (int i=0;i<n;i++)
			{
				cout<<x[i]<<endl;
			}
		
		CTBD *b;
		cout<<"\nNhap so luong CTBD: ";cin>>m;
		b=new CTBD[m];
		for (int i=0;i<m;i++)
			{
				cout<<"\nNhap so luong CTBD thu "<<i+1<<" la: "<<endl;
				cin>>b[i];
			}
		xuat();	
		for (int i=0;i<m;i++)
			{
				cout<<b[i]<<setw(20)<<b[i].phucap()<<endl;
			}
	Menu();	
	while (true)
	{	
		int chon = ChonMenu();
	switch (chon)
	{
	case 1:
		cout<<"------------------------------------------------------"<<endl;
		for (int i=0;i<m-1;i++)
			for (int j=i+1;j<m;j++)
					if (strcmp(b[i].cmt,b[j].cmt)==0) kq=1;
			if (kq==1)	
			cout<<"Co so CMT trung nhau!"<<endl;
			else cout<<"Khong co so CMT trung nhau!"<<endl; 
		break;		
	case 2:
		cout<<"------------------------------------------------------"<<endl;
		cout<<"\n Sap xep CTBD theo thu tu tang dan cua ban thang la: "<<endl;
		xuat ();		
		for (int i = 0; i < m - 1; i++) 
		for (int j = 0; j < m - i - 1; j++) 
			if ((b[j]) > (b[j + 1])) 
				// swap
			{
				temp=b[j];
				b[j]=b[j+1];
				b[j+1]=temp;
				
			}
		for (int i=0;i<m;i++)
			{
				cout<<b[i]<<setw(20)<<b[i].phucap()<<endl;
			}	
		
		break;
	case 3:
		cout<<"Cau thu co phu cap nho nhat la:";
		int min=b[0].phucap();
		for (int i=1;i<m;i++)
			{
				if (b[i].phucap()<=min) 
					{
						min=b[i].phucap();
						tam=i;
					}
			}
			xuat ();	
		cout<<endl;	
		cout<<b[tam]<<setw(20)<<b[tam].phucap()<<endl;	
		break;
	case 4:
	cout<<"------------------------------------------------------"<<endl;
	cout<<"Nhap ten cau thu can tim:";cin.ignore();cin.getline(ten,25);
	xuat ();	
		for (int i=0;i<m;i++)
			{
			if (b[i]==ten)
			cout<<b[i]<<setw(20)<<b[i].phucap()<<endl;
			}	
		break;
	case 5:
		cout<<"------------------------------------------------------"<<endl;
		CTBD *h=new CTBD[0];
		cout<<"Nhap cau thu can them: "<<endl;
		m=m+1;
		cin>>b[m-1];
		xuat ();	
		for (int i=0;i<m;i++)
			cout<<b[i]<<setw(20)<<b[i].phucap()<<endl;
		break;
	case 6:
	cout<<"------------------------------------------------------"<<endl;
		CTBD *k=new CTBD[0];
		
		cout<<"Nhap Vi tri can them: ";cin>>pos;
		m=m+1;
		for(int i = m; i > pos; i--)
			{
        		b[i] = b[i-1];
    		}
		cout<<"Nhap cau thu can them: "<<endl;cin>>b[pos];
		xuat ();	
   		for (int i=0;i<m;i++)
			cout<<b[i]<<setw(20)<<b[i].phucap()<<endl; 
		break;
	case 7:
		cout<<"------------------------------------------------------"<<endl;
		cout<<"Nhap CMT cau thu can sua tt:";cin.ignore();cin.getline(cmthu,25);
		for (int i=0;i<m;i++)
			{
			if (strcmp(b[i].cmt,cmthu)==0)
				{
					cout<<"Nhap TT can sua:"<<endl<<"An 'Enter' de bat dau nhap tt";cin>>b[i];
				}
			
			}
		cout<<"\nD/s sau khi sua la:"<<endl;
		xuat ();	
		for (int i=0;i<m;i++)
			cout<<b[i]<<setw(20)<<b[i].phucap()<<endl;		
		break;
	case 8:
		cout<<"------------------------------------------------------"<<endl;
		cout<<"Nhap CMT cau thu can xoa tt:";cin.ignore();cin.getline(cmthu2,25);
		for (int i=0;i<m;i++)
			{
			if (strcmp(b[i].cmt,cmthu2)==0)
				xoa=i;
			}
		cout<<"\nD/s sau khi sua la:"<<endl;
		for(int i = xoa; i < m - 1; i++)
				b[i] = b[i+1];
			m=m-1; 
		xuat ();	
		for (int i=0;i<m;i++)
			cout<<b[i]<<setw(20)<<b[i].phucap()<<endl;		
		break;			
	case 9:
		cout << "Thoat!!!\n";
		exit(1);
		break;
	}
	}
	return 0;
}
