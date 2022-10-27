#include <iostream>
#include <fstream>
#include <typeinfo>
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
	void setAdSoyad(string a) {
		ad_soyad = a;
	}
	void setTelNo(string a) {
		telno = a;
	}
	

private:
	string ad_soyad, telno;
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

class Siparis : Kiyafet
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

class Kullanici : Kisi
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

class Kurye : Kisi
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
	Yonetici(string s, string y = "admin")
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

private:
	string sifre;
	string yoneticiAdi;
};


void MainMenu::start()
{
	int selection;
	ktuWaikikiText();
	cout << "Modullerden birini secerek isleminize devam edebilirsiniz." << endl;
	cout << "[1] Sisteme giris.\n" << "[2] Yeni uye kayit.\n" << "[3] Cikis." << endl;

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
	string kullaniciAdi, sifre, k, s, tel, tc;
	int ctr = 0;
	ktuWaikikiText();
	cout << "Kullanici adinizi giriniz: ";
	cin >> kullaniciAdi;
	cout << "Sifrenizi giriniz: ";
	cin >> sifre;
	ifstream txt("kullanici.txt");

	while (txt >> k >> s >> tel >> tc) {
		if (k == kullaniciAdi && s == sifre) {
			ctr = 1;
			break;
		}
	}
	txt.close();
	if (ctr == 1) {
		cout << "giris yapildi" << endl;
		cout << "telno: " << tel << " tcno: " << tc << endl;
	}
	else {
		cout << "olmadi " << ctr;
	}
}

void MainMenu::MusteriKayitMenu()
{
	//değerler müşteri classına geçirilecek
	string ad, soyad, telNo, kullaniciAdi, sifre, mail, adres, dogumTarihi;

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
	txt << kullaniciAdi << " " << sifre << endl;

	cout << "\nKayit basarili, keyifli alisverisler." << endl;
	MusteriGirisMenu();
}


void MainMenu::YoneticiGirisMenu()
{
	ktuWaikikiText();
	Yonetici yonetici("password");
	string yoneticiSifre, y, s;
	fstream txt("kullanici.txt", ios::app);
	txt << yonetici.getYoneticiAdi() << " " << yonetici.getSifre() << endl; // "admin password" seklinde kullanici.txt'ye kayıt yaptı.
	txt.close();


	cout << "Yonetici sifresini giriniz." << endl;
	cin >> yoneticiSifre;

	txt.open("kullanici.txt", ios::in);
	while (txt >> y >> s)
	{
		if (y == yonetici.getYoneticiAdi() && s == yoneticiSifre)
		{
			cout << "Yonetici sistemine hos geldiniz..." << endl;
			break; // break yerine yonetici paneli acilacak.
		}
		else
		{
			if (txt.eof() == true)
			{
				cout << "Yanlis sifre girdiniz..." << endl;
				MainMenu();
			}
			else
				continue;
		}
	}

}

int main()
{
	static Kiyafet k;
	MainMenu mainMenu;
	mainMenu.start();
	return 0;
}
