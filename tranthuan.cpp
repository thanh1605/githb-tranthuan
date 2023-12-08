#include<bits/stdc++.h>
using namespace std;
class NhanVien{
	protected:
		string ten, sex;
		int ns;
		long long luong;
	public:
		NhanVien(){ }
		NhanVien(string ten, int ns, string sex, long long luong) : ten(ten), ns(ns), sex(sex), luong(luong){ }
		friend istream& operator >> (istream &in, NhanVien& );
		friend ostream& operator << (ostream &out, NhanVien );
		string getname(){
			return ten;
		}
};
istream& operator >> (istream &in, NhanVien& a){
	cout << "Nhap ten: " ; in >> a.ten;
	cout << "Nhap nam sinh: "; in >> a.ns; in.ignore();
	cout << "Nhap gioi tinh: "; in>>a.sex;
	cout << "Nhap luong: "; in >> a.luong; in.ignore();
	return in;	
} 
ostream& operator << (ostream &out, NhanVien a){
	out << "Ten: " << a.ten << endl;
	out << "Nam sinh: "<<a.ns << endl;
	out << "Gioi tinh: " << a.sex << endl;
	out << "Luong: " << a.luong << endl;
	return out;	
}
class LapTrinhVien : public NhanVien{
	private:
		string nn;
	public:
		LapTrinhVien(){ }
		LapTrinhVien(string ten, int ns, string sex, long long luong, string nn) : NhanVien(ten,ns,sex,luong), nn(nn){ }
		friend istream& operator >> (istream &in, LapTrinhVien &);
		friend ostream& operator << (ostream &out, LapTrinhVien );
};
istream& operator >> (istream &in, LapTrinhVien &b){
	in >> (NhanVien&)b;
	cout << "Nhap ngon ngu lap trinh: "; in>>b.nn;
	return in;
}
ostream& operator << (ostream &out, LapTrinhVien b){
	out << (NhanVien)b;
	out << "Ngon ngu lap trinh: "<< b.nn<< endl;
	return out;
}
class KiemThuVien : public NhanVien{
	private:
		string cm;
	public:
		KiemThuVien(){ }
		KiemThuVien(string ten, int ns, string sex, long long luong, string cm) : NhanVien(ten,ns,sex,luong), cm(cm){ }
		friend istream& operator >> (istream &in, KiemThuVien &c);
		friend ostream& operator << (ostream &out, KiemThuVien c);
};
istream& operator >> (istream &in, KiemThuVien &c){
	in >> (NhanVien&)c;
	cout << "Nhap chuyen mon: "; in>>c.cm;
	return in;
}
ostream& operator << (ostream &out, KiemThuVien c){
	out << (NhanVien)c;
	out << "Chuyen mon: " << c.cm << endl;
	return out;
}


int main(){
	int n;
	NhanVien *nv;
	LapTrinhVien ds[100];
	KiemThuVien danhsach[100];
	do{
	cout<<"Nhap so luong nhanvien: ";cin>>n;
	}while(n<=0||n>=100);
	int lc;
	int demX=0,demY=0;
	while(1){
	cout<<"1 la nhap\n";
	cout<<"2 la in\n";
	cout<<"3 la timkiem\n";
	cout<<"0 la thoat\n";
		cout<<"Nhap lua chon: ";
		cin>>lc;
		if(lc==1){
			for(int i=0;i<n;i++){
				int ok;
				cout<<"1 la nhap Laptrinhvien\n";
				cout<<"2 la nhap Kiemthuvien\n";
				cin>>ok;
				if(ok==1){
					cin>>ds[demX];
					demX++;
				}
				if(ok==2){
					cin>>danhsach[demY];
					demY++;
				}
			}
		}
		if(lc==2){
			int ok;
			for(int i=0;i<n;i++){
				cout<<"1 la nhap Laptrinhvien\n";
				cout<<"2 la nhap Kiemthuvien\n";
				cin>>ok;
				if(ok==1){
					for(int j=0;j<demX;j++){
						cout<<ds[j];
					}
				}
				if(ok==2){
					for(int j=0;j<demY;j++){
						cout<<danhsach[j];
					}
				}
			}
		}
		if(lc==3){
			string name;
			cout<<"Nhap ten muon tim: ";
			fflush(stdin); getline(cin,name);
			for(int i=0;i<demX;i++){
				if(name==ds[i].getname()||name==danhsach[i].getname()){
					cout<<"co trong\n";
				}else{
					cout<<"Khong co trong\n";
				}
			}
		}
		if(lc==0){
			break;
		}
	}
	return 0;
}



hahahahahaaha
huhuhu