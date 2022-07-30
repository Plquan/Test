#include <iostream>
#include <string.h>
#include <conio.h>
#include <iomanip>
#include <fstream>
using namespace std;

typedef struct NS 
{
	int ng,th,nam;
	NS(int ng=1, int th=1, int nam=1990)
	{
		this->ng = ng;
		this->th = th;
		this->nam = nam;
	}
};

class CongTyX{
	protected:
		char manv[10];
		char ht[30];
		NS ng;
		char gt[5];
		char qq[30]; 
		NS nvct;
		int luong;
	public:
		static int tongsonv;
		CongTyX(char manv[10]="", char ht[30]="", NS ng=NS(), char gt[5]="Nam", char qq[30]="", NS nvct=NS(),int luong=0){
			strcpy(this->manv,manv);
			strcpy(this->ht,ht);
			this->ng = ng;
			strcpy(this->gt,gt);
			strcpy(this->qq,qq);
			this->nvct = nvct;
			this->luong = luong;
			tongsonv+=1;
		}
		friend istream& operator>>(istream& is, CongTyX &a){
			fflush(stdin);
			cout<<"Nhap ma nhan vien: ";is.getline(a.manv,10);
			fflush(stdin);
			cout<<"Nhap ho ten: ";is.getline(a.ht,30);
			cout<<"Nhap ngay sinh: ";is>>a.ng.ng>>a.ng.th>>a.ng.nam;
			fflush(stdin);
			cout<<"Nhap gioi tinh: ";is.getline(a.gt,5);
			fflush(stdin);
			cout<<"Nhap que quan: ";is.getline(a.qq,30);
			cout<<"Nhap ngay vao cong ty: ";is>>a.nvct.ng>>a.nvct.th>>a.nvct.nam;
			cout<<"Nhap luong: ";is>>a.luong;
			fflush(stdin);
			return is;
		}
		friend ifstream& operator>>(ifstream &ifs, CongTyX &a)
		{
			char c[2];
			ifs.getline(a.manv,10);
			ifs.getline(a.ht,30);
			ifs>>a.ng.ng>>a.ng.th>>a.ng.nam;
			ifs.getline(c,2);
			ifs.getline(a.gt,5);
			ifs.getline(a.qq,30);
			ifs>>a.nvct.ng>>a.nvct.th>>a.nvct.nam;
			ifs>>a.luong;
			return ifs;
		}
		friend ostream& operator<<(ostream& os, CongTyX &a){
			os<<left<<char(179)<<" "<<setw(8)<<strupr(a.manv)<<char(179)<<" "<<setw(28)<<strupr(a.ht)<<char(179)<<" ";
			if(a.ng.ng>9)os<<a.ng.ng<<"/";else os<<"0"<<a.ng.ng<<"/";
			if(a.ng.th>9)os<<a.ng.th<<"/";else os<<"0"<<a.ng.th<<"/";
			os<<setw(5)<<a.ng.nam<<char(179)<<" "<<setw(10)<<strupr(a.gt)<<char(179)<<" "<<setw(28)<<strupr(a.qq)<<char(179)<<" ";
			if(a.nvct.ng>9)os<<a.nvct.ng<<"/";else os<<"0"<<a.nvct.ng<<"/";
			if(a.nvct.th>9)os<<a.nvct.th<<"/";else os<<"0"<<a.nvct.th<<"/";
			os<<setw(5)<<a.nvct.nam<<char(179)<<" "<<setw(8)<<a.luong<<char(179)<<" ";
			return os;
		}
		friend ofstream& operator<<(ofstream& ofs, CongTyX &a)
		{
			ofs<<strupr(a.manv)<<endl<<strupr(a.ht)<<endl<<a.ng.ng<<" "<<a.ng.th<<" "<<a.ng.nam<<endl<<strupr(a.gt)<<endl<<strupr(a.qq)<<endl<<a.nvct.ng<<" "<<a.nvct.th<<" "<<a.nvct.nam<<" "<<a.luong;
			return ofs;
		}
		char* getManv(){
			return this->manv;
		}
		char* getHt(){
			return this->ht;
		}
		NS getNg(){
			return this->ng;
		}
		char* getGt(){
			return this->gt;
		}
		bool IsNull(){
			return strcmp(this->manv,"")==0;
		}
		bool operator>(const CongTyX &a)const {
			return strcmpi(this->ht,a.ht)>0;
		}
};

class NhanVienVanPhong : public CongTyX {
	private:
		char phong[20];
	public:
		NhanVienVanPhong(char manv[10]="", char ht[30]="", NS ng=NS(), char gt[5]="Nam", char qq[30]="", NS nvct=NS(),int luong=0, char phong[20]=""):CongTyX(manv,ht,ng,gt,qq,nvct,luong){
			strcpy(this->phong,phong);
		}
		friend istream& operator>>(istream& is, NhanVienVanPhong &a){
			is>>(CongTyX&)a;
			cout<<"Nhap phong: ";is.getline(a.phong,20);
			return is;
		}
		friend ifstream& operator>>(ifstream &ifs, NhanVienVanPhong &a)
		{
			char c[2];
			ifs>>(CongTyX&)a;
			ifs.getline(c,2);	
			ifs.getline(a.phong,20);	
			return ifs;
		}
		friend ostream& operator<<(ostream& os, NhanVienVanPhong &a){
			os<<(CongTyX&)a<<setw(18)<<strupr(a.phong)<<char(179);
			return os;
		}
		friend ofstream& operator<<(ofstream& ofs, NhanVienVanPhong &a)
		{
			ofs<<(CongTyX&)a<<endl<<strupr(a.phong);
			return ofs;
		}
};

class CongNhan : public CongTyX {
	private:
		int dmslsp;
		char ngaynghi[10];
	public:
		CongNhan(char manv[10]="", char ht[30]="", NS ng=NS(), char gt[5]="Nam", char qq[30]="", NS nvct=NS(),int luong=0, int dmslsp=0, char ngaynghi[10]=""):CongTyX(manv,ht,ng,gt,qq,nvct,luong){
			this->dmslsp = dmslsp;
			strcpy(this->ngaynghi,ngaynghi);
		}
		friend istream& operator>>(istream& is, CongNhan &a){
			is>>(CongTyX&)a;
			cout<<"Nhap dinh muc so luong san pham: ";cin>>a.dmslsp;
			if(!strcmpi(a.getGt(),"Nam"))
				strcpy(a.ngaynghi,"CHU NHAT");
			else
			{
				fflush(stdin);
				cout<<"Nhap ngay nghi: ";cin.getline(a.ngaynghi,10);
			}
			return is;
		}
		friend ifstream& operator>>(ifstream &ifs, CongNhan &a)
		{
			char c[2];
			ifs>>(CongTyX&)a>>a.dmslsp;
			ifs.getline(c,2);	
			ifs.getline(a.ngaynghi,10);
			return ifs;
		}
		friend ostream& operator<<(ostream& os, CongNhan &a){
			os<<(CongTyX&)a<<setw(8)<<a.dmslsp<<char(179)<<" "<<setw(10)<<strupr(a.ngaynghi)<<char(179);
			return os;
		}
		friend ofstream& operator<<(ofstream& ofs, CongNhan &a)
		{
			ofs<<(CongTyX&)a<<" "<<a.dmslsp<<endl<<strupr(a.ngaynghi);
			return ofs;
		}
};

class NhanVienChuyenDi{
	private:
		char manv[10];
		char ht[30];
		NS ng;
		char gt[5];
		NS ncd;		
	public:
		NhanVienChuyenDi(){
			
		}
		NhanVienChuyenDi(CongTyX a){
			strcpy(this->manv,a.getManv());
			strcpy(this->ht,a.getHt());
			this->ng = a.getNg();
			strcpy(this->gt,a.getGt());
		}
		friend istream& operator>>(istream& is, NhanVienChuyenDi &a){
			cout<<"Nhap ngay chuyen di: ";is>>a.ncd.ng>>a.ncd.th>>a.ncd.nam;
			fflush(stdin);
			return is;
		}
		friend ifstream& operator>>(ifstream &ifs, NhanVienChuyenDi &a)
		{
			char c[2];
			ifs.getline(a.manv,10);
			ifs.getline(a.ht,30);
			ifs>>a.ng.ng>>a.ng.th>>a.ng.nam;
			ifs.getline(c,2);
			ifs.getline(a.gt,5);
			ifs>>a.ncd.ng>>a.ncd.th>>a.ncd.nam;
			ifs.getline(c,2);
			return ifs;
		}
		friend ostream& operator<<(ostream& os, NhanVienChuyenDi &a){
			os<<left<<char(179)<<" "<<setw(8)<<strupr(a.manv)<<char(179)<<" "<<setw(28)<<strupr(a.ht)<<char(179)<<" ";
			if(a.ng.ng>9)os<<a.ng.ng<<"/";else os<<"0"<<a.ng.ng<<"/";
			if(a.ng.th>9)os<<a.ng.th<<"/";else os<<"0"<<a.ng.th<<"/";
			os<<setw(5)<<a.ng.nam<<char(179)<<" "<<setw(10)<<strupr(a.gt)<<char(179)<<" ";
			if(a.ncd.ng>9)os<<a.ncd.ng<<"/";else os<<"0"<<a.ncd.ng<<"/";
			if(a.ncd.th>9)os<<a.ncd.th<<"/";else os<<"0"<<a.ncd.th<<"/";
			os<<setw(5)<<a.ncd.nam<<char(179);
			return os;
		}
		friend ofstream& operator<<(ofstream& ofs, NhanVienChuyenDi &a)
		{
			ofs<<strupr(a.manv)<<endl<<strupr(a.ht)<<endl<<a.ng.ng<<" "<<a.ng.th<<" "<<a.ng.nam<<endl<<strupr(a.gt)<<endl<<a.ncd.ng<<" "<<a.ncd.th<<" "<<a.ncd.nam;
			return ofs;
		}
		bool IsNull(){
			return strcmp(this->manv,"")==0;
		}
};

template <class T> class Node{
	public:
		T data;
		Node<T>* next;
		Node<T>* prev;
	public:
		Node<T>(T data){
			this->data = data;
			this->next = NULL;
			this->prev = NULL;
		}
		Node<T>& operator++(){
			*this = this->next;
			return *this;
		}
		bool operator>(const Node &a){
			return this->data>a.data;
		}
};

template <class T> class List{
	public:
		Node<T>* head;
		Node<T>* tail;
	public:
		List(){
			this->head = NULL;
			this->tail = NULL;
		}
		int Len(){
			Node<T> *PH = this->head;
			Node<T> *PT = this->tail;
			int i = 0;
			
			if(PH!=NULL)
				i = 1;
			while (PH != NULL)
		    {
		        if (PH == PT) 
					break;
		        PH = PH->next;
		        i++;
		        if (PH == PT) 
					break;
		        PT = PT->prev;
		        i++;
		    }
		    return i;
		}
		bool IsEmpty(){
			return this->head == NULL;
		}
		void InsertAtHead(T data){
			Node<T>* newNode = new Node<T>(data);
			
			if(this->head == NULL){
				this->head = newNode;
				this->tail = newNode;
				return;
			}
			
			this->head->prev = newNode;
			newNode->next = this->head;
			this->head = newNode;
		}
		void InsertAtTail(T data){
			Node<T>* newNode = new Node<T>(data);
			
			if(this->head == NULL){
				this->head = newNode;
				this->tail = newNode;
				return;
			}
			
			this->tail->next = newNode;
			newNode->prev = this->tail;
			this->tail = newNode;
		}
		void DeleteAtHead(){
			if(this->head == NULL)
				return;
			this->head = this->head->next;
			this->head->prev = NULL;
		}
		void DeleteAtTail(){
			if(this->head == NULL)
				return;
			this->tail = this->tail->prev;
			this->tail->next = NULL;
		}
		void DeleteNode(Node<T>* &p){
			Node<T> *left, *right;
			if(p == NULL)
				return;
			if(p == this->head)
				this->DeleteAtHead();
			else if(p == this->tail)
				this->DeleteAtTail();
			else{
				left = p->prev;
				right = p->next;
				left->next = right;
				right->prev = left;
			}
		}
		void Print(){
			Node<T>* temp = this->head;
			int i = 1;
			while(temp != NULL){
				cout<<char(179)<<" "<<setw(3)<<i++<<temp->data<<endl;
				temp = temp->next;
			}
		}
		void SortAlphaBet(){
			for(Node<T>* pHead = this->head; pHead->next != NULL; pHead = pHead->next)
				for(Node<T>* pNode = pHead->next; pNode != NULL; pNode = pNode->next)
					if(pHead->data>pNode->data)
					{
						T temp = pHead->data;
						pHead->data = pNode->data;
						pNode->data = temp;
					}	
		}
		void SearchByName(char *value){
			int i=1;
			for(Node<T>* pNode = this->head; pNode != NULL; pNode = pNode->next){
				if(strstr(strupr(pNode->data.getHt()),strupr(value))){
					cout<<char(179)<<" "<<setw(3)<<i++<<pNode->data<<endl;
				}
			}
		}
		Node<T>* SearchByID(char *value){
			for(Node<T>* pNode = this->head; pNode != NULL; pNode = pNode->next){
				if(!strcmpi(pNode->data.getManv(),value))
					return pNode;
			}
			return NULL;
		}
		void Write2File(ofstream &ofs){
			Node<T>* temp = this->head;
			while(temp != NULL){
				ofs<<temp->data<<endl;
				temp = temp->next;
			}
		}
};


void TaoMenu()
{
	system("cls");
	char yc0[100]="CHUONG TRINH QUAN LY NHAN VIEN CONG TY X:";
	char yc1[100]="[1] Danh sach toan bo nhan vien cong ty";
	char yc2[100]="[2] Danh sach nhan vien van phong theo ten";
	char yc3[100]="[3] Danh sach cong nhan theo ten";
	char yc4[100]="[4] Tim kiem nhan vien theo ten";
	char yc5[100]="[5] Them nhan vien moi";
	char yc6[100]="[6] Chinh sua thong tin nhan vien";
	char yc7[100]="[7] Xoa nhan vien";
	char yc8[100]="[8] Danh sach nhan vien da chuyen di";
	char yc9[100]="[9] Them nhan vien chuyen di";
	char yc10[100]="[0] Ket thuc!!!";
	cout<<right<<"\n\n\n";
	cout<<setw(29)<<char(201);for(int i=1;i<60;i++)cout<<char(205); cout<<char(187)<<endl;
	cout<<setw(29)<<char(186)<<setw(60)<<char(186)<<endl;
	cout<<setw(29)<<char(186)<<setw(45)<<yc0<<setw(15)<<char(186)<<endl;
	cout<<setw(29)<<char(186)<<setw(60)<<char(186)<<endl;
	cout<<setw(29)<<char(186)<<setw(11+strlen(yc1))<<yc1<<setw(49-strlen(yc1))<<char(186)<<endl;
	cout<<setw(29)<<char(186)<<setw(11+strlen(yc2))<<yc2<<setw(49-strlen(yc2))<<char(186)<<endl;
	cout<<setw(29)<<char(186)<<setw(11+strlen(yc3))<<yc3<<setw(49-strlen(yc3))<<char(186)<<endl;
	cout<<setw(29)<<char(186)<<setw(11+strlen(yc4))<<yc4<<setw(49-strlen(yc4))<<char(186)<<endl;
	cout<<setw(29)<<char(186)<<setw(11+strlen(yc5))<<yc5<<setw(49-strlen(yc5))<<char(186)<<endl;
	cout<<setw(29)<<char(186)<<setw(11+strlen(yc6))<<yc6<<setw(49-strlen(yc6))<<char(186)<<endl;
	cout<<setw(29)<<char(186)<<setw(11+strlen(yc7))<<yc7<<setw(49-strlen(yc7))<<char(186)<<endl;
	cout<<setw(29)<<char(186)<<setw(11+strlen(yc8))<<yc8<<setw(49-strlen(yc8))<<char(186)<<endl;
	cout<<setw(29)<<char(186)<<setw(11+strlen(yc9))<<yc9<<setw(49-strlen(yc9))<<char(186)<<endl;
	cout<<setw(29)<<char(186)<<setw(11+strlen(yc10))<<yc10<<setw(49-strlen(yc10))<<char(186)<<endl;
	cout<<setw(29)<<char(186)<<setw(60)<<char(186)<<endl;
	cout<<setw(29)<<char(200);for(int i=1;i<60;i++)cout<<char(205); cout<<char(188)<<endl;
	cout<<"\n\n\n";
	cout<<"\n\n\t\t\t\t\tNhap lua chon: ";
}

void HeadingCongTy()
{
	int x = 123;
	for(int i=0;i<=x;i++)
	{
		if(i==0)
			cout<<char(218);
		else if(i==x)
			cout<<char(191);
		else if(i==5 || i==15 || i==45 || i==58 || i==70 || i==100 || i==113)
			cout<<char(194);
		else
			cout<<char(196);
	}
	cout<<endl;
	cout<<left<<char(179)<<setw(4)<<"STT"<<char(179)<<setw(9)<<" MA NV"<<char(179)<<setw(29)<<" HO TEN"<<char(179)<<setw(12)<<" NGAY SINH"<<char(179)<<setw(11)<<" GIOI TINH"<<char(179)<<setw(29)<<" QUE QUAN"<<char(179)<<setw(12)<<" NGAY VAO"<<char(179)<<setw(9)<<" LUONG"<<char(179)<<endl;
	for(int i=0;i<=x;i++)
	{
		if(i==0)
			cout<<char(195);
		else if(i==x)
			cout<<char(180);
		else if(i==5 || i==15 || i==45 || i==58 || i==70 || i==100 || i==113)
			cout<<char(197);
		else
			cout<<char(196);
	}
	cout<<endl;
}

void FootingCongTy()
{
	int x = 123;
	for(int i=0;i<=x;i++)
	{
		if(i==0)
			cout<<char(192);
		else if(i==x)
			cout<<char(217);
		else if(i==5 || i==15 || i==45 || i==58 || i==70 || i==100 || i==113)
			cout<<char(193);
		else
			cout<<char(196);
	}
	cout<<"\n\n\n";
}

void HeadingNhanVienVanPhong()
{
	int x = 143;
	for(int i=0;i<=x;i++)
	{
		if(i==0)
			cout<<char(218);
		else if(i==x)
			cout<<char(191);
		else if(i==5 || i==15 || i==45 || i==58 || i==70 || i==100 || i==113 || i==123)
			cout<<char(194);
		else
			cout<<char(196);
	}
	cout<<endl;
	cout<<left<<char(179)<<setw(4)<<"STT"<<char(179)<<setw(9)<<" MA NV"<<char(179)<<setw(29)<<" HO TEN"<<char(179)<<setw(12)<<" NGAY SINH"<<char(179)<<setw(11)<<" GIOI TINH"<<char(179)<<setw(29)<<" QUE QUAN"<<char(179)<<setw(12)<<" NGAY VAO"<<char(179)<<setw(9)<<" LUONG"<<char(179)<<setw(19)<<" PHONG"<<char(179)<<endl;
	for(int i=0;i<=x;i++)
	{
		if(i==0)
			cout<<char(195);
		else if(i==x)
			cout<<char(180);
		else if(i==5 || i==15 || i==45 || i==58 || i==70 || i==100 || i==113 || i==123)
			cout<<char(197);
		else
			cout<<char(196);
	}
	cout<<endl;
}

void FootingNhanVienVanPhong()
{
	int x = 143;
	for(int i=0;i<=x;i++)
	{
		if(i==0)
			cout<<char(192);
		else if(i==x)
			cout<<char(217);
		else if(i==5 || i==15 || i==45 || i==58 || i==70 || i==100 || i==113 || i==123)
			cout<<char(193);
		else
			cout<<char(196);
	}
	cout<<"\n\n\n";
}

void HeadingCongNhan()
{
	int x = 145;
	for(int i=0;i<=x;i++)
	{
		if(i==0)
			cout<<char(218);
		else if(i==x)
			cout<<char(191);
		else if(i==5 || i==15 || i==45 || i==58 || i==70 || i==100 || i==113 || i==123 || i==133)
			cout<<char(194);
		else
			cout<<char(196);
	}
	cout<<endl;
	cout<<left<<char(179)<<setw(4)<<"STT"<<char(179)<<setw(9)<<" MA NV"<<char(179)<<setw(29)<<" HO TEN"<<char(179)<<setw(12)<<" NGAY SINH"<<char(179)<<setw(11)<<" GIOI TINH"<<char(179)<<setw(29)<<" QUE QUAN"<<char(179)<<setw(12)<<" NGAY VAO"<<char(179)<<setw(9)<<" LUONG"<<char(179)<<setw(9)<<" DINH MUC"<<char(179)<<setw(11)<<" NGAY NGHI"<<char(179)<<endl;
	for(int i=0;i<=x;i++)
	{
		if(i==0)
			cout<<char(195);
		else if(i==x)
			cout<<char(180);
		else if(i==5 || i==15 || i==45 || i==58 || i==70 || i==100 || i==113 || i==123 || i==133)
			cout<<char(197);
		else
			cout<<char(196);
	}
	cout<<endl;
}

void FootingCongNhan()
{
	int x = 145;
	for(int i=0;i<=x;i++)
	{
		if(i==0)
			cout<<char(192);
		else if(i==x)
			cout<<char(217);
		else if(i==5 || i==15 || i==45 || i==58 || i==70 || i==100 || i==113 || i==123 || i==133)
			cout<<char(193);
		else
			cout<<char(196);
	}
	cout<<"\n\n\n";
}

void HeadingChuyenDi()
{
	int x = 83;
	for(int i=0;i<=x;i++)
	{
		if(i==0)
			cout<<char(218);
		else if(i==x)
			cout<<char(191);
		else if(i==5 || i==15 || i==45 || i==58 || i==70)
			cout<<char(194);
		else
			cout<<char(196);
	}
	cout<<endl;
	cout<<left<<char(179)<<setw(4)<<"STT"<<char(179)<<setw(9)<<" MA NV"<<char(179)<<setw(29)<<" HO TEN"<<char(179)<<setw(12)<<" NGAY SINH"<<char(179)<<setw(11)<<" GIOI TINH"<<char(179)<<setw(12)<<" NGAY CHUYEN"<<char(179)<<endl;
	for(int i=0;i<=x;i++)
	{
		if(i==0)
			cout<<char(195);
		else if(i==x)
			cout<<char(180);
		else if(i==5 || i==15 || i==45 || i==58 || i==70)
			cout<<char(197);
		else
			cout<<char(196);
	}
	cout<<endl;
}

void FootingChuyenDi()
{
	int x = 83;
	for(int i=0;i<=x;i++)
	{
		if(i==0)
			cout<<char(192);
		else if(i==x)
			cout<<char(217);
		else if(i==5 || i==15 || i==45 || i==58 || i==70)
			cout<<char(193);
		else
			cout<<char(196);
	}
	cout<<"\n\n\n";
}

int CongTyX::tongsonv = 0;

int main(int argc, char *argv[])
{
	int i,j,m;
	List<CongTyX> listNhanVienCongTy;
	List<NhanVienVanPhong> listNhanVienVanPhong;
	List<CongNhan> listCongNhan;
	List<NhanVienChuyenDi> listNhanVienChuyenDi;
	
	
	//================ Doc File ================//
	ifstream ifs1("NhanVienVanPhong.txt",ios::in);
	while(!ifs1.eof()){
		NhanVienVanPhong tmp;
		ifs1>>tmp;
		if(tmp.IsNull())
			continue;
		listNhanVienVanPhong.InsertAtTail(tmp);
		listNhanVienCongTy.InsertAtTail(tmp);
	}
	ifs1.close();
	ifstream ifs2("CongNhan.txt",ios::in);
	while(!ifs2.eof()){
		CongNhan tmp;
		ifs2>>tmp;
		if(tmp.IsNull())
			continue;
		listCongNhan.InsertAtTail(tmp);
		listNhanVienCongTy.InsertAtTail(tmp);
	}
	ifs2.close();
	ifstream ifs3("NhanVienChuyenDi.txt",ios::in);
	while(!ifs3.eof()){
		NhanVienChuyenDi tmp;
		ifs3>>tmp;
		if(tmp.IsNull())
			continue;
		listNhanVienChuyenDi.InsertAtTail(tmp);
	}
	ifs3.close();
	//================ Doc File ================//
	
	
	
	//================ Main Loop ================//
	while(1)
	{
		TaoMenu();
		cin>>m;
		switch(m){
			case 1://Danh sach toan bo nhan vien cong ty X
			{
				system("cls");
				cout<<"\n\n\n\t\t\t\t\t\t\tDANH SACH NHAN VIEN CONG TY\n\n\n";
				HeadingCongTy();
				listNhanVienCongTy.Print();
				FootingCongTy();
				system("pause");
				break;
			}
			case 2://Danh sach nhan vien van phong theo ten
			{
				system("cls");
				cout<<"\n\n\n\t\t\t\t\t\t\tDANH SACH NHAN VIEN VAN PHONG THEO TEN\n\n\n";
				listNhanVienVanPhong.SortAlphaBet();
				HeadingNhanVienVanPhong();
				listNhanVienVanPhong.Print();
				FootingNhanVienVanPhong();
				system("pause");
				break;
			}
			case 3://Danh sach cong nhan theo ten
			{
				system("cls");
				cout<<"\n\n\n\t\t\t\t\t\t\tDANH SACH CONG NHAN THEO TEN\n\n\n";
				listCongNhan.SortAlphaBet();
				HeadingCongNhan();
				listCongNhan.Print();
				FootingCongNhan();
				system("pause");
				break;
			}
			case 4://Tim kiem nhan vien theo ten
			{
				system("cls");
				char tenct[30];
				fflush(stdin);
				cout<<"\n-------------------------------------------\n";
				cout<<"Nhap ten nhan vien can tim: ";cin.getline(tenct,30);
				cout<<"-------------------------------------------\n\n\n";
				HeadingCongTy();
				listNhanVienCongTy.SearchByName(tenct);
				FootingCongTy();
				system("pause");
				break;
			}
			case 5://Them nhan vien moi
			{
				system("cls");
				char luachon[10];
				cout<<"Nhap thong tin cho nhan vien moi:";
				cout<<"\n------------------------------------------\n";
				do{
					cout<<"(1. Nhan vien van phong/2. Cong nhan): ";
					fflush(stdin);
					cin.getline(luachon,10);	
				}while(strcmp(luachon,"1")!=0 && strcmp(luachon,"2")!=0);
				cout<<endl;
				if(!strcmp(luachon,"1"))
				{
					NhanVienVanPhong tmp;
					cin>>tmp;
					listNhanVienVanPhong.InsertAtTail(tmp);
					listNhanVienCongTy.InsertAtTail((CongTyX)tmp);
					ofstream ofs("NhanVienVanPhong.txt",ios::app);
					ofs<<tmp<<endl;
					ofs.close();
				}
				else
				{
					CongNhan tmp;
					cin>>tmp;
					listCongNhan.InsertAtTail(tmp);
					listNhanVienCongTy.InsertAtTail((CongTyX)tmp);
					ofstream ofs("CongNhan.txt",ios::app);
					ofs<<tmp<<endl;
					ofs.close();
				}
				cout<<"\n------------------------------------------\n";
				cout<<"\t- Nhap thanh cong!!!\n\n\n";
				system("pause");
				break;
			}
			case 6://Chinh sua thong tin nhan vien
			{
				system("cls");
				char tenct[30];
				fflush(stdin);
				cout<<"\n-------------------------------------------\n";
				cout<<"Nhap ma nhan vien can sua thong tin: ";cin.getline(tenct,30);
				cout<<"-------------------------------------------\n\n\n";
				Node<NhanVienVanPhong>* tmp1 = listNhanVienVanPhong.SearchByID(tenct);
				if(tmp1!=NULL){
					HeadingNhanVienVanPhong();
					cout<<char(179)<<" "<<setw(3)<<"1"<<tmp1->data<<endl;
					FootingNhanVienVanPhong();
					cout<<"\n\n\nNhap thong tin moi:";
					cout<<"\n------------------------------------------\n";
					cin>>tmp1->data;
					cout<<"\n------------------------------------------\n";
					Node<CongTyX>* tmp = listNhanVienCongTy.SearchByID(tenct);
					tmp->data = tmp1->data;
					ofstream ofs("NhanVienVanPhong.txt",ios::out);
					listNhanVienVanPhong.Write2File(ofs);
					ofs.close();
					cout<<"\t- Cap nhat thanh cong!!!";
				}
				else{
					Node<CongNhan>* tmp2 = listCongNhan.SearchByID(tenct);
					if(tmp2!=NULL){
						HeadingCongNhan();
						cout<<char(179)<<" "<<setw(3)<<"1"<<tmp2->data<<endl;
						FootingCongNhan();
						cout<<"\n\n\nNhap thong tin moi:";
						cout<<"\n------------------------------------------\n";
						cin>>tmp2->data;
						cout<<"\n------------------------------------------\n";
						Node<CongTyX>* tmp = listNhanVienCongTy.SearchByID(tenct);
						tmp->data = tmp2->data;
						ofstream ofs("CongNhan.txt",ios::out);
						listCongNhan.Write2File(ofs);
						ofs.close();
						cout<<"\t- Cap nhat thanh cong!!!";
					}
					else
						cout<<"\n\n\n\t\t\t[!] Khong tim thay nhan vien [!]";
				}
				cout<<"\n\n\n";
				system("pause");
				break;
			}
			case 7://Xoa nhan vien
			{
				system("cls");
				char tenct[30],xn[2],tenNV[30];
				fflush(stdin);
				cout<<"\n-------------------------------------------\n";
				cout<<"Nhap ma nhan vien can xoa: ";cin.getline(tenct,30);
				cout<<"-------------------------------------------\n\n\n";
				Node<NhanVienVanPhong>* tmp1 = listNhanVienVanPhong.SearchByID(tenct);
				if(tmp1!=NULL){
					HeadingNhanVienVanPhong();
					cout<<char(179)<<" "<<setw(3)<<"1"<<tmp1->data<<endl;
					FootingNhanVienVanPhong();
					strcpy(tenNV,strupr(tmp1->data.getHt())); 
					do{
						cout<<"\n=> Xac nhan xoa nhan vien "<<tenNV<<"?(Y/N): ";
						fflush(stdin);cin.getline(xn,2);
					}while(strcmpi(xn,"y")!=0 && strcmpi(xn,"n")!=0);
					if(strcmpi(xn,"y")==0)
					{
						listNhanVienVanPhong.DeleteNode(tmp1);
						Node<CongTyX>* tmp = listNhanVienCongTy.SearchByID(tenct);
					 	listNhanVienCongTy.DeleteNode(tmp);
						ofstream ofs("NhanVienVanPhong.txt",ios::out);
						listNhanVienVanPhong.Write2File(ofs);
						ofs.close();
						cout<<"\n=> Xoa thanh cong nhan vien khoi danh sach!!!";
					}
				}
				else{
					Node<CongNhan>* tmp2 = listCongNhan.SearchByID(tenct);
					if(tmp2!=NULL){
						HeadingCongNhan();
						cout<<char(179)<<" "<<setw(3)<<"1"<<tmp2->data<<endl;
						FootingCongNhan();
						strcpy(tenNV,strupr(tmp2->data.getHt())); 
						do{
							cout<<"\n=> Xac nhan xoa nhan vien "<<tenNV<<"?(Y/N): ";
							fflush(stdin);cin.getline(xn,2);
						}while(strcmpi(xn,"y")!=0 && strcmpi(xn,"n")!=0);
						if(strcmpi(xn,"y")==0)
						{
							listCongNhan.DeleteNode(tmp2);
							Node<CongTyX>* tmp = listNhanVienCongTy.SearchByID(tenct);
						 	listNhanVienCongTy.DeleteNode(tmp);
							ofstream ofs("CongNhan.txt",ios::out);
							listCongNhan.Write2File(ofs);
							ofs.close();
							cout<<"\n=> Xoa thanh cong nhan vien khoi danh sach!!!";
						}
					}
					else
						cout<<"\n\n\n\t\t\t[!] Khong tim thay nhan vien [!]";
				}
				cout<<"\n\n\n";
				system("pause");
				break;
			}
			case 8://Danh sach nhan vien da chuyen di
			{
				system("cls");
				cout<<"\n\n\n\t\t\tDANH SACH NHAN VIEN DA CHUYEN DI\n\n\n";
				HeadingChuyenDi();
				listNhanVienChuyenDi.Print();
				FootingChuyenDi();
				system("pause");
				break;
			}
			case 9://Them nhan vien chuyen di
			{
				system("cls");
				char tenct[30],xn[2],tenNV[30];
				fflush(stdin);
				cout<<"\n-------------------------------------------\n";
				cout<<"Nhap ma nhan vien chuyen di: ";cin.getline(tenct,30);
				cout<<"-------------------------------------------\n\n\n";
				Node<NhanVienVanPhong>* tmp1 = listNhanVienVanPhong.SearchByID(tenct);
				if(tmp1!=NULL){
					HeadingNhanVienVanPhong();
					cout<<char(179)<<" "<<setw(3)<<"1"<<tmp1->data<<endl;
					FootingNhanVienVanPhong();
					strcpy(tenNV,strupr(tmp1->data.getHt())); 
					do{
						cout<<"\n=> Xac nhan nhan vien "<<tenNV<<" chuyen di?(Y/N): ";
						fflush(stdin);cin.getline(xn,2);
					}while(strcmpi(xn,"y")!=0 && strcmpi(xn,"n")!=0);
					if(strcmpi(xn,"y")==0)
					{
						listNhanVienVanPhong.DeleteNode(tmp1);
						Node<CongTyX>* tmp = listNhanVienCongTy.SearchByID(tenct);
						NhanVienChuyenDi nvcd(tmp->data);
						cin>>nvcd;
						listNhanVienChuyenDi.InsertAtTail(nvcd);
						ofstream ofs1("NhanVienChuyenDi.txt",ios::app);
						ofs1<<nvcd<<endl;
						ofs1.close();
					 	listNhanVienCongTy.DeleteNode(tmp);
						ofstream ofs("NhanVienVanPhong.txt",ios::out);
						listNhanVienVanPhong.Write2File(ofs);
						ofs.close();
						cout<<"\n=> Cap nhat thanh cong!!!";
					}
				}
				else{
					Node<CongNhan>* tmp2 = listCongNhan.SearchByID(tenct);
					if(tmp2!=NULL){
						HeadingCongNhan();
						cout<<char(179)<<" "<<setw(3)<<"1"<<tmp2->data<<endl;
						FootingCongNhan();
						strcpy(tenNV,strupr(tmp2->data.getHt())); 
						do{
							cout<<"\n=> Xac nhan nhan vien "<<tenNV<<" chuyen di?(Y/N): ";
							fflush(stdin);cin.getline(xn,2);
						}while(strcmpi(xn,"y")!=0 && strcmpi(xn,"n")!=0);
						if(strcmpi(xn,"y")==0)
						{
							listCongNhan.DeleteNode(tmp2);
							Node<CongTyX>* tmp = listNhanVienCongTy.SearchByID(tenct);
							NhanVienChuyenDi nvcd(tmp->data);
							cin>>nvcd;
							listNhanVienChuyenDi.InsertAtTail(nvcd);
							ofstream ofs1("NhanVienChuyenDi.txt",ios::app);
							ofs1<<nvcd<<endl;
							ofs1.close();
						 	listNhanVienCongTy.DeleteNode(tmp);
							ofstream ofs("CongNhan.txt",ios::out);
							listCongNhan.Write2File(ofs);
							ofs.close();
							cout<<"\n=> Cap nhat thanh cong!!!";
						}
					}
					else
						cout<<"\n\n\n\t\t\t[!] Khong tim thay nhan vien [!]";
				}
				cout<<"\n\n\n";
				system("pause");
				break;
			}
			case 0://Ket thuc
			{
				system("cls");
				cout<<right<<"\n\n\n";
				cout<<setw(29)<<char(201);for(int i=1;i<60;i++)cout<<char(205); cout<<char(187)<<endl;
				cout<<setw(29)<<char(186)<<setw(60)<<char(186)<<endl;
				cout<<setw(29)<<char(186)<<setw(60)<<char(186)<<endl;
				cout<<setw(29)<<char(186)<<setw(42)<<"KET THUC CHUONG TRINH!!!"<<setw(18)<<char(186)<<endl;
				cout<<setw(29)<<char(186)<<setw(60)<<char(186)<<endl;
				cout<<setw(29)<<char(186)<<setw(60)<<char(186)<<endl;
				cout<<setw(29)<<char(200);for(int i=1;i<60;i++)cout<<char(205); cout<<char(188)<<endl;
				cout<<"\n\n\n";
				return 0;
			}
		}
	}
	//================ Main Loop ================//
	
	
	return 0;
}
