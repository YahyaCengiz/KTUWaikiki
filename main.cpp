#include <iostream>
#include <locale.h>
#include <fstream>
using namespace std;

class MainMenu
{
	public:
		void ktuWaikikiText() {
			cout << "\t\t\tKTU Waikiki\n\n";
		}
		void start();
		void GirisMenu();
		void MusteriGirisMenu();
		void MusteriKayitMenu();
		void YoneticiGirisMenu();
		void YoneticiMenu();
        // urun_ekleme(); kurye_ekleme(); sikayet_okuma(); kod_tanimlama(); fatura_goruntuleme();
        void urun_ekleme();
        void kurye_ekleme();
        void sikayet_okuma();
        void kod_tanimlama();
        void fatura_goruntuleme();

	private:

};

class Yonetici
{
public:
    Yonetici(string s,string y="admin")
    {
        yoneticiAdi = y;
        sifre = s;
    }
    string getYoneticiAdi()
    {
        return yoneticiAdi;
    }
    string getSifre()
    {
        return sifre;
    }
    string ad="-";
    string soyad = "-";
    string dogum = "-";
    string adres = "-";
    string tel = "-";
    string mail = "-";
    string kod = "-";

private:
    string sifre;
    string yoneticiAdi;
};


void MainMenu::start()
{
	int selection;
	ktuWaikikiText();
	cout << "Modullerden birini secerek isleminize devam edebilirsiniz." << endl;
	cout << "[1] Sisteme giris.\n" << "[2] Yeni uye kayit.\n"<< "[3] Cikis." << endl;

	cin >> selection;
	system("CLS");
	switch (selection)
	{
	case 1:
		GirisMenu();
		break;
	case 2:
		MusteriKayitMenu();
		break;
	case 3:
		ktuWaikikiText();
		cout << "Basariyla ciktiniz." << endl;
		break;
	default:
		cout << "Hatali secim yaptiniz, lutfen tekrar deneyiniz." << endl;
		start();
		break;
	}

}

void MainMenu::GirisMenu()
{
	ktuWaikikiText();
	int selection;
	cout << "Giris yapmak istediginiz modulu seciniz.\n" << "[1] Musteri girisi.\n" << "[2] Yonetici girisi." << endl;
	cin >> selection;
	system("CLS");

	switch (selection)
	{
	case 1:
		MusteriGirisMenu();
		break;
	case 2:
		YoneticiGirisMenu();
		break;
	default:
		cout << "Hatali secim yaptiniz, lutfen tekrar deneyiniz." << endl;
		GirisMenu();
		break;
	}
}

void MainMenu::MusteriGirisMenu()
{
	string kullaniciAdi, sifre, k, s, tel, mail, ad, soyad, adres, dogum,kod;
    int ctr = 0;
	ktuWaikikiText();
	cout << "Kullanici adinizi giriniz: ";
	cin >> kullaniciAdi;
	cout << "Sifrenizi giriniz: ";
	cin >> sifre;
	ifstream txt("kullanici.txt");

	while(txt >> k >> s >> ad >> soyad >> dogum >> adres >> tel >> mail >> kod ){
        if(k == kullaniciAdi && s == sifre){
            ctr = 1;
            break;
        }
	}
	txt.close();
	if(ctr == 1){
        cout << "giris yapildi" << endl;
        cout << "telno: " << tel << " mail: " << mail << endl;
	}else{
        cout << "olmadi " << ctr;
	}
}

void MainMenu::MusteriKayitMenu()
{
	//değerler müşteri classına geçirilecek
	string ad, soyad, telNo, kullaniciAdi, sifre, mail, adres, dogumTarihi,kod="0";

	ktuWaikikiText();
	cout << "Adiniz: "; cin >> ad;
	cout << "Soyadiniz: "; cin >> soyad;
	cout << "Dogum Tarihiniz: "; cin >> dogumTarihi;
	cout << "Adresiniz: "; cin >> adres;
	cout << "Telefon Numaraniz: "; cin >> telNo;
	cout << "Mail Adresiniz: "; cin >> mail;
	//mail adresi kontrol edilecek;
	cout << "Bir kullanici adi belirleyiniz: "; cin >> kullaniciAdi;
	cout << "Bir sifre belirleyiniz: "; cin >> sifre;

	ofstream txt("kullanici.txt", ios::app);
	txt << kullaniciAdi << " " << sifre << " " << ad << " " << soyad << " " << dogumTarihi << " " << adres << " " << telNo << " " << mail << " " << kod << endl;

	cout << "\nKayit basarili, keyifli alisverisler." << endl;
	MusteriGirisMenu();
}


void MainMenu::YoneticiGirisMenu()
{
	ktuWaikikiText();
    Yonetici yonetici("password");
	string yoneticiSifre,y,s,ad,soyad,dogum,adres,tel,mail,kod;
	fstream txt("kullanici.txt",ios::app);
	txt << yonetici.getYoneticiAdi() << " " << yonetici.getSifre() << " " << yonetici.ad << " " << yonetici.soyad << " " <<yonetici.dogum << " "  << yonetici.adres << " " << yonetici.tel << " " << yonetici.mail << " " << kod << endl;

	txt.close();

	cout << "Yonetici sifresini giriniz." << endl;
	cin >> yoneticiSifre;

    txt.open("kullanici.txt",ios::in);
    while(txt >> y >> s >> ad >> soyad >> dogum >> adres >> tel >> mail)
    {
        if(y == yonetici.getYoneticiAdi() && s == yoneticiSifre)
        {
            cout << "Yonetici sistemine hos geldiniz..." << endl;
            YoneticiMenu();
        }
        else
        {
            if(txt.eof() == true)
            {
                cout << "Yanlis sifre girdiniz..." << endl;
                MainMenu();
            }
            else
                continue;
        }
    }

}

void MainMenu::YoneticiMenu()
{
    int selection;
    system("CLS");
    cout << "Modullerden birini secerek isleminize devam edebilirsiniz." << endl;
    cout << "\n";
	cout << "[1] Urun Ekleme.\n" << "[2] Kurye Ekleme.\n"<<"[3] Sikayet Oneri Okuma.\n"<<"[4] Indirim Kodu Tanimlama.\n"<<"[5] Fatura Goruntuleme.\n"<<"[6] Cikis.\n"<<endl;
    cin >> selection;
    switch(selection)
    {
    case 1:
        urun_ekleme();
        break;

    }
}

void MainMenu::urun_ekleme()
{
    ofstream urunler("urunler.txt",ios::app);
    string urun,kategori,fiyat,boyut,renk;
    cout << "Eklenecek Urun : " << endl;
    cin >> urun;
    cout << "Urunun Kategorisi : " << endl;
    cin >> kategori;
    cout << "Urunun Fiyati : " << endl;
    cin >> fiyat;
    cout << "Urunun Boyutu : " << endl;
    cin >> boyut;
    cout << "Urunun Rengi : " << endl;
    cin >> renk;
    urunler << urun << " " << kategori << " " << fiyat << " " << boyut << " " << renk << "\n" ;

    urunler.close();
    cout << "Basariyla Eklendi..." << endl;
    YoneticiMenu();
}

int main()
{
	//türkçe karakterleri kullannmak için
	setlocale(LC_ALL, "Turkish");
	MainMenu mainMenu;
	mainMenu.start();
	return 0;
}
