#include <iostream>
#include <locale.h>
#include <fstream>
#include <ctime>
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
        void urun_ekleme();
        void kurye_ekleme();
        void sikayet_okuma();
        void kupon_tanimlama();
        void fatura_goruntuleme();

	private:

};

class Zaman
{
public:
	int getSaat() {
		return saat;
	}
	int getDakika() {
		return dakika;
	}
	void setSaat(int a) {
		saat = a;
	}
	void setDakika(int a) {
		dakika = a;
	}
private:
	int saat, dakika;
};

class Kisi
{
public:
	void setAd(string a) {
		ad = a;
	}
	void setSoyad(string a) {
        soyad = a;
	}
	void setTelNo(string a) {
		telno = a;
	}


private:
	string ad, soyad, telno;
};

class Kiyafet
{
public:
	string getKategori() {
		return kategori;
	}
	string getKiyafetAdi() {
		return kiyafet_adi;
	}
	string getBoyut() {
		return boyut;
	}
	string getRenk() {
		return renk;
	}
	double getFiyat() {
		return fiyat;
	}

	void setKategori(string a) {
		kategori = a;
	}
	void setKiyafetAdi(string a) {
		kiyafet_adi = a;
	}
	void setBoyut(string a) {
		boyut = a;
	}
	void setRenk(string a) {
		renk = a;
	}
	void setFiyat(double a) {
		fiyat = a;
	}


private:
	string kategori, kiyafet_adi, boyut, renk;
	double fiyat;
};

class Siparis : public Kiyafet
{
public:
	int getSiparisNo() {
		return siparis_no;
	}
	double getSiparisFiyat() {
		return siparis_fiyat;
	}
	Zaman getSiparisBaslangic() {
		return siparis_baslangic;
	}
	Zaman getSiparisBitis() {
		return siparis_bitis;
	}

	void setSiparisNo(int a) {
		siparis_no = a;
	}
	void setSiparisFiyat(double a) {
		siparis_fiyat = a;
	}
	void setSiparisBaslangic(Zaman a) {
		siparis_baslangic = a;
	}
	void setSiparisBitis(Zaman a) {
		siparis_bitis = a;
	}

private:
	int siparis_no;
	double siparis_fiyat;
	Zaman siparis_baslangic;
	Zaman siparis_bitis;
};

class Kullanici : public Kisi
{
public:
	string getKullaniciAdi() {
		return kullanici_adi;
	}
	string getEposta() {
		return eposta;
	}
	string getAdresIlce() {
		return adres_ilce;
	}
	string getSifre() {
		return sifre;
	}
	string getIndirimKodu() {
		return indirim_kodu;
	}
	string getDTarihi() {
		return dtarihi;
	}

	void setKullaniciAdi(string a) {
		kullanici_adi = a;
	}
	void setEposta(string a) {
		eposta = a;
	}
	void setAdresIlce(string a) {
		adres_ilce = a;
	}
	void setSifre(string a) {
		sifre = a;
	}
	void setIndirimKodu(string a) {
		indirim_kodu = a;
	}
	void setDTarihi(string a) {
		dtarihi = a;
	}
private:
	string kullanici_adi, eposta, adres_ilce, sifre, indirim_kodu, dtarihi;
};

class Kurye : public Kisi
{
public:
	Zaman getDagitimBitisler() {
		return dagitim_bitisler;
	}
	int getSiparisNumaralari() {
		return siparisnumralari;
	}

	void setDagitimBitisler(Zaman a) {
		dagitim_bitisler = a;
	}
	void setSiparisNumaralari(int a) {
		siparisnumralari = a;
	}


private:
	Zaman dagitim_bitisler;
	int siparisnumralari;
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
    case 2:
        kurye_ekleme();
        break;
    case 3:
        sikayet_okuma();
    default:
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

void MainMenu::kurye_ekleme()
{
    Kurye kurye;
    string kurye_adi, kurye_soyadi, kurye_telno;
    fstream txt("kuryeler.txt",ios::app);
    cout << "Kurye Adi: " << endl;
    cin >> kurye_adi;
    cout << "Kurye Soyadi: " << endl;
    cin >> kurye_soyadi;
    cout << "Kurye Telefon Numarasi: " << endl;
    cin >> kurye_telno;
    txt << kurye_adi << " " << kurye_soyadi << " " << kurye_telno << " " << "0" << " " << "0" << endl;
    cout << "Basariyla Eklendi" << endl;
    cout << "Devam etemk icin Enter'a basin." << endl;
    cin >> select;
    switch(select)
    {
		case 1: YoneticiMenu();
    	default: YoneticiMenu();
    }
  // Burayı tekrardan yazmak gerek.
    // Kişi Sınıfından ad soyad bilgilerini ayrı ayrı almamız gerek. Ayrıca Txt yazdırma işi tamam ama kurye objesine değer gönderirken sıkıntı çıktı.
    // Kuryelerin gidiş geliş saatleri txt'ye kaydedilecek.Adam ol

}

void MainMenu::sikayet_okuma()
{
    ifstream txt("sikayet.txt");
    string text;
    text = txt.get();
    cout << text;
}

int main()
{
	//türkçe karakterleri kullannmak için
	setlocale(LC_ALL, "Turkish");
	MainMenu mainMenu;
	mainMenu.start();
	return 0;
}
