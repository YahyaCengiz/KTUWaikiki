#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <locale.h>
#include <fstream>
#include <string>
#include <istream>
#include <sstream>
#include <stdio.h>
#include <io.h>
#include <conio.h>
#include <ctime>
#include <stdlib.h>

using namespace std;

inline void cls() { system("CLS"); cout << "\t\t\tKTU Waikiki\n\n"; }

class Zaman
{
public:
	Zaman operator + (Zaman a)
	{
		Zaman kurye_donus;

		if (this->dakika + a.dakika >= 60)
		{
			a.saat++;
			kurye_donus.dakika = (this->dakika + a.dakika) - 60;
		}
		else
			kurye_donus.dakika = this->dakika + a.dakika;

		if (this->saat + a.saat >= 24)
		{
			kurye_donus.saat = this->saat + a.saat - 24;
		}
		else
			kurye_donus.saat = this->saat + a.saat;

		return kurye_donus;

	}

	time_t getSaat() {
		return saat;
	}

	time_t getDakika() {
		return dakika;
	}

	void setSaat(time_t a) {
		saat = a;
	}

	void setDakika(time_t a) {
		dakika = a;
	}

private:
	int saat, dakika;
};


ostream& operator << (ostream& out, Zaman zaman)
{
	out << zaman.getSaat() << ":";
	if (zaman.getDakika() < 10)
		out << "0" << zaman.getDakika();
	else
		out << zaman.getDakika();
	return out;
}


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
	string getAd() {
		return ad;
	}
	string getSoyad() {
		return soyad;
	}
	string getTelNo() {
		return telno;
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
	string getIsim()
	{
		return isim;
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
	void setIsim(string a)
	{
		isim = a;
	}


	ostream& operator<<(ostream& os) {
		os << getIsim() << " " << getKategori() << " " << getBoyut() << "Beden " << getRenk() << " " << getFiyat() << "TL" << endl;
		return os;
	}

private:
	string kategori, kiyafet_adi, boyut, renk, isim;
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

	void FiyatEkle(double a) {
		siparis_fiyat += a;
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


class MainMenu
{
public:
	void start();
	void GirisMenu();
	bool Selection(string& s, int a);
	void MusteriGirisMenu();
	void MusteriKayitMenu();
	void KategoriMenu();
	void MusteriMenu();
	void SifreDegistirMenu();
	void YoneticiGirisMenu();
	void SikayetOneriMenu();
	void YoneticiMenu();
	void urun_ekleme();
	void kurye_ekleme();
	void sikayet_okuma();
	void kupon_tanimlama();
	void SiparisTakipMenu();
	void UrunSecimMenu(string);
	void AlisverisiBitir();
	bool MailVerification(string mail);
	void PasswordMasking(string& password);
	bool PasswordVerification(string password);
	bool DateVerification(string date);
	void fatura_goruntuleme();
	Kullanici kullanici;
	Kurye kurye_gonderme();
	Siparis siparis;
	int sepetBoyutu = 0;
	Kiyafet sepet[20];
	Zaman simdi;
	time_t now = time(0);
	tm* ltm = localtime(&now);

	int SepetFiyati();

private:

};


class Yonetici : public Kisi
{
public:
	string ad = "-";
	string soyad = "-";
	string dogum = "-";
	string adres = "-";
	string tel = "-";
	string mail = "-";
	string kod = "-";
	Yonetici(string s, string y = "admin")
	{
		yoneticiAdi = y;
		sifre = s;
		setAd(ad);
		setSoyad(soyad);
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
	string selection = "0";
	cls();
	cout << "Modullerden birini secerek isleminize devam edebilirsiniz." << endl;
	cout << "[1] Sisteme giris.\n" << "[2] Yeni uye kayit.\n" << "[3] Cikis." << endl;

	
	while (!Selection(selection, 3))
	{
		Selection(selection, 3);
	}
	
	switch (stoi(selection))
	{
	case 1:
		GirisMenu();
		break;
	case 2:
		MusteriKayitMenu();
		break;
	case 3:
		cls();
		cout << "Basariyla ciktiniz." << endl;
		return;
		break;
	default:
		cout << "Hatali secim yaptiniz, lutfen tekrar deneyiniz." << endl;
		start();
		break;
	}

}


void MainMenu::GirisMenu()
{
	cls();
	string selection = "0";
	cout << "Giris yapmak istediginiz modulu seciniz.\n" << "[1] Musteri girisi.\n" << "[2] Yonetici girisi.\n[3] Geri don." << endl;
	
	while (!Selection(selection, 3))
	{
		Selection(selection, 3);
	}
	

	switch (stoi(selection))
	{
	case 1:
		MusteriGirisMenu();
		break;
	case 2:
		YoneticiGirisMenu();
		break;
	case 3:
		start();
		break;
	default:
		cout << "Hatali secim yaptiniz, lutfen tekrar deneyiniz." << endl;
		GirisMenu();
		break;
	}
}

bool MainMenu::Selection(string& s, int a) {
	char ch;
	ch = _getch();
	while (ch != 13) //character 13 is enter
	{
		if (ch == 8) {
			if (s.empty() == false)
			{
				cout << '\b' << " " << '\b';
				s.pop_back();
			}
			ch = _getch();
			continue;
		}
		s.push_back(ch);
		cout << ch;
		ch = _getch();
	}
	
	if (stoi(s) < 1 && stoi(s) > a) {
		return false;
	}
	else {
		return true;
	}
		
}


void MainMenu::MusteriGirisMenu()
{
	string kullaniciAdi, sifre, k, s, tel, mail, ad, soyad, adres, dogum, kod;
	int ctr = 0;
	string selection = "0";
	cls();
	cout << "Kullanici adinizi giriniz: ";
	cin >> kullaniciAdi;
	cout << "Sifrenizi giriniz: ";
	PasswordMasking(sifre);
	ifstream txt("kullanici.txt");


	while (txt >> k >> s >> ad >> soyad >> dogum >> adres >> tel >> mail >> kod) {
		if (k == kullaniciAdi && s == sifre) {
			ctr = 1;
			break;
		}
	}
	txt.close();
	if (ctr == 1) {
		this->kullanici.setAd(ad);
		this->kullanici.setSoyad(soyad);
		this->kullanici.setAdresIlce(adres);
		this->kullanici.setDTarihi(dogum);
		this->kullanici.setEposta(mail);
		this->kullanici.setSifre(sifre);
		this->kullanici.setKullaniciAdi(k);
		this->kullanici.setIndirimKodu(kod);
		MusteriMenu();
	}
	else
	{
		std::cout << "\nGiris basarisiz.\n\n[1] Tekrar dene.\n[2] Cikis." << endl;
		while (!Selection(selection, 2))
		{
			Selection(selection, 2);
		}
		switch (stoi(selection))
		{
		case 1:
			MusteriGirisMenu();
			break;
		case 2:
			start();
			break;
		}
	}
}


void MainMenu::MusteriKayitMenu()
{
	//değerler müşteri classına geçirilecek
	string ad, soyad, telNo, kullaniciAdi, sifre, mail, dogumTarihi, kod = "0000000";
	int adres;

	cls();
	cout << "Adiniz: "; cin >> ad;
	cout << "Soyadiniz: "; cin >> soyad;
	cout << "Dogum Tarihiniz (gg.aa.yyyy): ";
	cin >> dogumTarihi;
	while (true)
	{
		if (DateVerification(dogumTarihi)) {
			break;
		}
		else
		{
			cout << "Dogum tarihinizi gecerli bir sekilde giriniz (gg.aa.yyyy): ";
			cin >> dogumTarihi;
		}
	}
	cout << "Adresiniz: " << endl;
	cout << "[1] Ortahisar \n[2] Akcaabat \n[3] Vakfikebir \n[4] Besikduzu \n[5] Yomra \n[6] Arsin \n[7] Arakli " << endl;
	cin >> adres;
	cout << "Telefon Numaraniz: "; cin >> telNo;
	cout << "Mail Adresiniz: ";
	while (true)
	{
		cin >> mail;
		if (MailVerification(mail))
		{
			break;
		}
		else
		{
			cout << "Mail adresiniz hatali, lutfen tekrar deneyiniz: ";
		}
	}
	//mail adresi kontrol edilecek;
	cout << "Bir kullanici adi belirleyiniz: "; cin >> kullaniciAdi;
	cout << "Bir sifre belirleyiniz: ";
	PasswordMasking(sifre);
	while (true)
	{
		if (!PasswordVerification(sifre)) {
			sifre = "";
			cout << "\nSifre yeterince guclu degil. Yeniden deneyiniz: ";
			PasswordMasking(sifre);
		}
		else
		{
			break;
		}
	}

	ofstream txt("kullanici.txt", ios::app);
	txt << kullaniciAdi << " " << sifre << " " << ad << " " << soyad << " " << dogumTarihi << " " << adres << " " << telNo << " " << mail << " " << kod << endl;
	cls();
	cout << "\nKayit basarili, keyifli alisverisler." << endl;
	txt.close();
	string selection = "0";
	cout << "\n[1] Giris yap.\n" << endl;
	while (!Selection(selection, 1))
	{
		Selection(selection, 1);
	}
	switch (stoi(selection))
	{
	case 1:
		MusteriGirisMenu();
		break;
	default:
		break;
	}
}


void MainMenu::MusteriMenu()
{
	cls();
	string selection = "0";
	cout << "Giris yapmak istediginiz modulu seciniz.\n" << "[1] Kategorileri goster.\n" << "[2] Siparis takip.\n"
		<< "[3] Sikayet/Oneri.\n" << "[4] Sifre Degistir.\n" << "[5] Cikis \n" << endl;
	while (!Selection(selection, 5))
	{
		Selection(selection, 5);
	}
	cls();
	switch (stoi(selection))
	{
	case 1:
		KategoriMenu();
		break;
	case 2:
		SiparisTakipMenu();
		break;
	case 3:
		SikayetOneriMenu();
		break;
	case 4:
		SifreDegistirMenu();
		break;
	case 5:
		start();
	default:
		break;
	}
}


void MainMenu::SikayetOneriMenu() {
	cls();
	string mesaj;
	cout << "Mesajinizi giriniz: ";
	cin.ignore();
	getline(cin, mesaj);
	ofstream txt("sikayet.txt", ios::app);
	txt << "[Yazan:" << kullanici.getKullaniciAdi() << "] " << mesaj << endl;
	txt.close();
	cout << "Mesajiniz basariyla gonderildi.\n" << endl;
	string selection = "0";
	cout << "Bir modul secerek isleminize devam edebilirsiniz.\n\n[1] Menuye don.\n" << endl;
	while (!Selection(selection, 1))
	{
		Selection(selection, 1);
	}
	switch (stoi(selection))
	{
	case 1:
		MusteriMenu();
		break;
	default:
		break;
	}
}


void MainMenu::YoneticiGirisMenu()
{
	cls();
	Yonetici yonetici("password");
	string yoneticiSifre, y, s, ad, soyad, dogum, adres, tel, mail, kod;
	int ctr = 0;
	ifstream txt("kullanici.txt", ios::in);

	cout << "Yonetici sifresini giriniz." << endl;
	PasswordMasking(yoneticiSifre);
	while (txt >> y >> s >> ad >> soyad >> dogum >> adres >> tel >> mail >> kod) {
		if (y == "admin" && s == "password") {
			ctr = 1;
			break;
		}
	}
	txt.close();
	fstream txt2("kullanici.txt", ios::app);
	if (ctr == 1 && yoneticiSifre == "password") {
		cout << "Giris Yapildi..." << endl;
		YoneticiMenu();
	}
	else {
		txt2 << "admin" << " " << "password" << " " << "-" << " " << "-" << " " << "-" << " " << "-" << " " << "-" << " " << "-" << " " << "-" << endl;
		txt2.close();
	}

	txt.open("kullanici.txt", ios::in);
	while (txt >> y >> s >> ad >> soyad >> dogum >> adres >> tel >> mail >> kod)
	{
		if (y == "admin" && yoneticiSifre == "password")
		{
			YoneticiMenu();
		}
	}

	txt.close();
}


void MainMenu::kurye_ekleme()
{
	cls();
	Kurye kurye;
	string kurye_adi, kurye_soyadi, kurye_telno;
	//int select;
	//char a;
	fstream txt("kuryeler.txt", ios::app);
	cout << "Kurye Adi: " << endl;
	cin >> kurye_adi;
	cout << "Kurye Soyadi: " << endl;
	cin >> kurye_soyadi;
	cout << "Kurye Telefon Numarasi: " << endl;
	cin >> kurye_telno;
	txt << kurye_adi << " " << kurye_soyadi << " " << kurye_telno << " " << "0" << " " << "0" << endl;
	cout << "Basariyla Eklendi" << endl;
	YoneticiMenu();
	// Burayı tekrardan yazmak gerek.
	  // Kişi Sınıfından ad soyad bilgilerini ayrı ayrı almamız gerek. Ayrıca Txt yazdırma işi tamam ama kurye objesine değer gönderirken sıkıntı çıktı.
	  // Kuryelerin gidiş geliş saatleri txt'ye kaydedilecek.Adam ol

}


void MainMenu::YoneticiMenu()
{
	string selection = "0";
	cls();
	cout << "Modullerden birini secerek isleminize devam edebilirsiniz." << endl;
	cout << "\n";
	cout << "[1] Urun Ekleme.\n" << "[2] Kurye Ekleme.\n" << "[3] Sikayet Oneri Okuma.\n" << "[4] Indirim Kodu Tanimlama.\n" << "[5] Fatura Goruntuleme.\n" << "[6] Cikis.\n" << endl;
	while (!Selection(selection, 6))
	{
		Selection(selection, 6);
	}
	switch (stoi(selection))
	{
	case 1:
		urun_ekleme();
		break;
	case 2:
		kurye_ekleme();
		break;
	case 3:
		sikayet_okuma();
		break;
	case 4:
		kupon_tanimlama();
		break;
	case 5:
		fatura_goruntuleme();
	case 6:
		start();
		break;
	default:
		break;
	}

}


void MainMenu::urun_ekleme()
{
	cls();
	ofstream urunler("urunler.txt", ios::app);
	string kategori, fiyat, boyut, renk, isim;
	int kategori_secim, renk_secim, boyut_secim;
	//elbise, tisort, pantolon, gomlek, etek, ayakkabi, kategori_secim;
	cout << "Urunun Kategorisi : \n [1] Elbise \n [2] Tisort \n [3] Pantolon \n [4] Gomlek \n [5] Etek \n [6] Ayakkabi" << endl;
	cin >> kategori_secim;
	cout << "Urunun Ismi : " << endl;
	cin.ignore();
	getline(cin, isim);

	for (int i = 0; i < isim.length(); i++)
	{
		if (isim[i] == ' ')
		{
			isim[i] = '_';
		}
	}
	
	switch (kategori_secim)
	{
	case 1:
		kategori = "Elbise";
		break;
	case 2:
		kategori = "Tisort";
		break;
	case 3:
		kategori = "Pantolon";
		break;
	case 4:
		kategori = "Gomlek";
		break;
	case 5:
		kategori = "Etek";
		break;
	case 6:
		kategori = "Ayakkabi";
		break;
	default:
		cout << "Lutfen gecerli bir kategori secin." << endl;
		urun_ekleme();
	}

	if (kategori != "Ayakkabi")
	{
		cout << "Urunun Fiyati : " << endl;
		cin >> fiyat;
		cout << "Urunun Boyutu : \n [1] S Beden \n [2] M Beden \n [3] L Beden \n [4] XL Beden \n [5] XXL Beden " << endl;
		cin >> boyut_secim;
		switch (boyut_secim)
		{
		case 1:
			boyut = "S";
			break;
		case 2:
			boyut = "M";
			break;
		case 3:
			boyut = "L";
			break;
		case 4:
			boyut = "XL";
			break;
		case 5:
			boyut = "XXL";
			break;
		default:
			boyut = "Hata";
			break;
		}

		cout << "Urunun Rengi : " << endl;
		cout << " [1] Mavi \n [2] Kirmizi \n [3] Siyah \n [4] Beyaz \n [5] Yesil " << endl;
		cin >> renk_secim;
		switch (renk_secim)
		{
		case 1:
			renk = "Mavi";
			break;
		case 2:
			renk = "Kirmizi";
			break;
		case 3:
			renk = "Siyah";
			break;
		case 4:
			renk = "Beyaz";
			break;
		case 5:
			renk = "Yesil";
			break;
		default:
			renk = "Hata";
			break;
		}
		urunler << isim << " " << kategori << " " << fiyat << " " << boyut << " " << renk << "\n";
	}
	else if (kategori == "Ayakkabi")
	{
		cout << "Urunun Fiyati : " << endl;
		cin >> fiyat;
		cout << "Urunun Numarasi : " << endl;
		cin >> boyut_secim;
		while (boyut_secim < 30 || boyut_secim > 46)
		{
			cout << "Lutfen Gecerli Bir Sayi Giriniz." << endl;
			cin >> boyut_secim;
		}
		cout << "Urunun Rengi : " << endl;
		cout << " [1] Mavi \n [2] Kirmizi \n [3] Siyah \n [4] Beyaz \n [5] Yesil " << endl;
		cin >> renk_secim;
		switch (renk_secim)
		{
		case 1:
			renk = "Mavi";
			break;
		case 2:
			renk = "Kirmizi";
			break;
		case 3:
			renk = "Siyah";
			break;
		case 4:
			renk = "Beyaz";
			break;
		case 5:
			renk = "Yesil";
			break;
		default:
			renk = "Hata";
			break;
		}
		urunler << isim << " " << kategori << " " << fiyat << " " << boyut_secim << " " << renk << "\n";
	}
	else
		cout << "Hata!" << endl;

	urunler.close();
	cout << "Basariyla Eklendi..." << endl;
	cout << "Bir modul secerek isleminize devam edebilirsiniz." << endl;
	cout << "[1] Menuye Don\n" << endl;
	
	string selection = "0";
	while (!Selection(selection, 1)) {
		Selection(selection, 1);
	}

	switch (stoi(selection))
	{
	case 1:
		YoneticiMenu();
		break;
	default:
		break;
	}
}


void MainMenu::sikayet_okuma()
{
	cls();
	ifstream txt("sikayet.txt");
	string text;
	auto index = 0;
	while (getline(txt, text))
	{
		cout << "[" << ++index << "] " << text << endl;
	}
	string selection = "0";
	cout << "\n\nBir modul secerek isleminize devam edebilirsiniz.\n" << endl;
	cout << "[1] Menuye don." << endl;
	while (!Selection(selection, 1))
	{
		Selection(selection, 1);
	}
	switch (stoi(selection))
	{
	case 1:
		YoneticiMenu();
	default:
		break;
	}
}


void MainMenu::kupon_tanimlama()
{
	cls();
	cout << "Kupon tanimlanacak kullanici adini giriniz: ";
	string hangikullanici; cin >> hangikullanici;
	cout << "7 haneli kupon kodunu giriniz: ";
	string yenikod; cin >> yenikod;

	string k, s, ad, soyad, dogum, adres, tel, mail, kod;
	fstream txt("./kullanici.txt");
	string text;
	size_t pos = 0;
	while (txt >> k >> s >> ad >> soyad >> dogum >> adres >> tel >> mail >> kod)
	{
		//kod uzunlugu belirli olmali
		if (k == hangikullanici)
		{
			txt.seekp(pos);
			txt << k << " " << s << " " << ad << " " << soyad << " " << dogum << " " << adres << " " << tel << " " << mail << " " << yenikod << endl;
			pos += k.length() + s.length() + ad.length() + soyad.length() + dogum.length() + adres.length() + tel.length() + mail.length() + yenikod.length() + 8;
		}
		else
		{
			pos += k.length() + s.length() + ad.length() + soyad.length() + dogum.length() + adres.length() + tel.length() + mail.length() + kod.length() + 8;
		}
	}

	cout << "Kupon tanimlandi." << endl;
	cout << "Bir modul secerek isleminize devam edebilirsiniz." << endl;
	cout << "[1] Menuye Don\n" << endl;
	string selection = "0";
	while (!Selection(selection, 1)) {
		Selection(selection, 1);
	}
	switch (stoi(selection))
	{
	case 1:
		YoneticiMenu();
		break;
	default:
		break;
	}
	
	txt.close();
}


bool MainMenu::MailVerification(string mail)
{
	if (mail.find("@") != string::npos && mail.find(" ") == string::npos && (mail.find(".com") != string::npos || mail.find(".net") != string::npos || mail.find(".org") != string::npos))
	{
		return true;
	}
	else
	{
		return false;
	}
}


void MainMenu::PasswordMasking(string& password)
{
	char ch;
	ch = _getch();
	while (ch != 13) //character 13 is enter
	{
		if (ch == 8) {
			if (password.empty() == false)
			{
				cout << '\b' << " " << '\b';
				password.pop_back();
			}
			ch = _getch();
			continue;
		}
		password.push_back(ch);
		cout << '*';
		ch = _getch();
	}
}


bool MainMenu::PasswordVerification(string password)
{
	bool hasUpper = false;
	bool hasLower = false;
	bool hasDigit = false;
	bool hasSpecial = false;
	for (int i = 0; i < password.length(); i++)
	{
		if (isupper(password[i]))
		{
			hasUpper = true;
		}
		else if (islower(password[i]))
		{
			hasLower = true;
		}
		else if (isdigit(password[i]))
		{
			hasDigit = true;
		}
		else if (ispunct(password[i]))
		{
			hasSpecial = true;
		}
	}
	if (hasUpper && hasLower && hasDigit && hasSpecial)
	{
		return true;
	}
	else
	{
		return false;
	}
}


bool MainMenu::DateVerification(string date)
{
	if (date.length() != 10)
	{
		return false;
	}
	else
	{
		if (date[2] != '.' || date[5] != '.')
		{
			return false;
		}
		else
		{
			string day = date.substr(0, 2);
			string month = date.substr(3, 2);
			string year = date.substr(6, 4);
			if (stoi(day) > 31 || stoi(day) < 1 || stoi(month) > 12 || stoi(month) < 1 || stoi(year) > 2022 || stoi(year) < 1900)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
	}
}


void MainMenu::KategoriMenu() {
	cls();
	string selection = "0";
	cout << "Kategorilerden birini secerek isleminize devam edebilirsiniz." << endl;
	cout << "\n";
	cout << "[1] Elbise.\n" << "[2] Tisort.\n" << "[3] Pantolon.\n" << "[4] Gomlek.\n" << "[5] Etek.\n" << "[6] Ayakkabi.\n" << "[7] Geri Don.\n" << endl;
	
	while (!Selection(selection, 7))
	{
		Selection(selection, 7);
	}
	
	switch (stoi(selection))
	{
	case 1:
		UrunSecimMenu("Elbise");
		break;
	case 2:
		UrunSecimMenu("Tisort");
		break;
	case 3:
		UrunSecimMenu("Pantolon");
		break;
	case 4:
		UrunSecimMenu("Gomlek");
		break;
	case 5:
		UrunSecimMenu("Etek");
		break;
	case 6:
		UrunSecimMenu("Ayakkabi");
		break;
	case 7:
		MusteriMenu();
		break;
	default:
		break;
	}
}


void MainMenu::UrunSecimMenu(string kategori) {
	cls();
	string selection = "0";
	string kategoria, fiyat, boyut, renk, isim;
	cout << "Bir " << kategori << " secerek isleminize devam edebilirsiniz." << endl;
	cout << "Su anki sepet tutariniz: " << SepetFiyati() << "TL" << endl;
	cout << "\n";
	ifstream uruntxt("urunler.txt");
	string text;
	int index = 0;
	Kiyafet kiyafet[100] = { Kiyafet() };
	string isimler;
	bool yazdirisim = true;
	while (uruntxt >> isim >> kategoria >> fiyat >> boyut >> renk)
	{
		yazdirisim = true;
		//cout << "[" << index << "]" << fiyat << "TL " << boyut << "Beden " << renk << endl;
		if (kategoria == kategori) {
			kiyafet[index].setIsim(isim);
			kiyafet[index].setKategori(kategoria);
			kiyafet[index].setFiyat(stoi(fiyat));
			kiyafet[index].setBoyut(boyut);
			kiyafet[index].setRenk(renk);
			index++;

			if (isimler.find(isim) != std::string::npos) {
				yazdirisim = false;
			}
			if (yazdirisim) {
				isimler += isim;
				cout << "[" << index << "] " << isim << endl;
			}
			
		}
	}
	uruntxt.close();
	if (index == 0) {
		cout << "Bu kategoride hic urun yok." << endl;
		cout << "[1] Kategori Secimine Don\n" << "[2] Menuye Don\n" << endl;
		
		while (!Selection(selection, 2))
		{
			Selection(selection, 2);
		}
		
		switch (stoi(selection))
		{
		case 1:
			KategoriMenu();
			break;
		case 2:
			MusteriMenu();
			break;
		default:
			cout << "default";
			break;
		}
	}
	else {
		int a;
		cout << "\n";

		selection = "0";
		while (!Selection(selection, index))
		{
			Selection(selection, index);
		}

		a = stoi(selection);
		string yisim = kiyafet[a - 1].getIsim();
		cout << "\nBeden seciniz: " << endl;
		index = 0;
		ifstream uruntxt2("urunler.txt");

		string boyutlar = " ";
		bool yazdirboyutlar = true;
		while (uruntxt2 >> isim >> kategoria >> fiyat >> boyut >> renk)
		{
			yazdirboyutlar = true;
			//cout << "[" << index << "]" << fiyat << "TL " << boyut << "Beden " << renk << endl;
			if (yisim == isim) {
				kiyafet[index].setIsim(isim);
				kiyafet[index].setKategori(kategoria);
				kiyafet[index].setFiyat(stoi(fiyat));
				kiyafet[index].setBoyut(boyut);
				kiyafet[index].setRenk(renk);
				index++;
				
				if (boyutlar.find(" " + boyut + " ") != std::string::npos) {
					yazdirboyutlar = false;
				}
				
				if (yazdirboyutlar) {
					boyutlar += " " + boyut + " ";
					cout << "[" << index << "] " << boyut << endl;
				}

			}
		}
		cout << "[" << index + 1 << "] Menuye Don." << endl;
		uruntxt2.close();
		selection = "0";
		while (!Selection(selection, index+1))
		{
			Selection(selection, index);
		}
		
		a = stoi(selection);
		
		if (a == index + 1) KategoriMenu();
		
		string yboyut = kiyafet[a - 1].getBoyut();

		cout << "\nRenk seciniz: " << endl;
		index = 0;
		ifstream uruntxt3("urunler.txt");

		bool mavi = false, kirmizi = false, siyah = false, beyaz = false, yesil = false;
		while (uruntxt3 >> isim >> kategoria >> fiyat >> boyut >> renk)
		{
			//cout << "[" << index << "]" << fiyat << "TL " << boyut << "Beden " << renk << endl;
			if (yisim == isim && yboyut == boyut) {
				if (renk == "Mavi" && !mavi) {
					kiyafet[index].setIsim(isim);
					kiyafet[index].setKategori(kategoria);
					kiyafet[index].setFiyat(stoi(fiyat));
					kiyafet[index].setBoyut(boyut);
					kiyafet[index].setRenk(renk);
					index++;
					cout << "[" << index << "] " << renk << endl;
					mavi = true;
				}
				else if (renk == "Kirmizi" && !kirmizi) {
					kiyafet[index].setIsim(isim);
					kiyafet[index].setKategori(kategoria);
					kiyafet[index].setFiyat(stoi(fiyat));
					kiyafet[index].setBoyut(boyut);
					kiyafet[index].setRenk(renk);
					index++;
					cout << "[" << index << "] " << renk << endl;
					kirmizi = true;
				}
				else if (renk == "Siyah" && !siyah) {
					kiyafet[index].setIsim(isim);
					kiyafet[index].setKategori(kategoria);
					kiyafet[index].setFiyat(stoi(fiyat));
					kiyafet[index].setBoyut(boyut);
					kiyafet[index].setRenk(renk);
					index++;
					cout << "[" << index << "] " << renk << endl;
					siyah = true;
				}
				else if (renk == "Beyaz" && !beyaz) {
					kiyafet[index].setIsim(isim);
					kiyafet[index].setKategori(kategoria);
					kiyafet[index].setFiyat(stoi(fiyat));
					kiyafet[index].setBoyut(boyut);
					kiyafet[index].setRenk(renk);
					index++;
					cout << "[" << index << "] " << renk << endl;
					beyaz = true;
				}
				else if (renk == "Yesil" && !yesil) {
					kiyafet[index].setIsim(isim);
					kiyafet[index].setKategori(kategoria);
					kiyafet[index].setFiyat(stoi(fiyat));
					kiyafet[index].setBoyut(boyut);
					kiyafet[index].setRenk(renk);
					index++;
					cout << "[" << index << "] " << renk << endl;
					yesil = true;
				}
			}
		}

		cout << "[" << index + 1 << "] Menuye Don." << endl;
		
		uruntxt3.close();
		selection = "0";
		while (!Selection(selection, index))
		{
			Selection(selection, index);
		}
		

		a = stoi(selection);
		if (a == index + 1) KategoriMenu();
		
		sepet[sepetBoyutu] = kiyafet[stoi(selection) - 1];
		sepetBoyutu++;
		cls();
		cout << "Urununuz sepete eklendi. Anlik sepet tutari: " << SepetFiyati() << "TL\n" << endl;
		cout << "Devam etmek icin bir islem seciniz." << endl;
		cout << "[1] Alisverise devam et.\n[2] Alisverisi bitir.\n" << endl;
		
		selection = "0";
		while (!Selection(selection, 2))
		{
			Selection(selection, 2);
		}
		switch (stoi(selection))
		{
		case 1:
			KategoriMenu();
			break;
		case 2:
			AlisverisiBitir();
			break;
		default:
			cout << "default";
			break;
		}
	}
}


int MainMenu::SepetFiyati() {
	int toplam = 0;
	for (int i = 0; i < sepetBoyutu; i++)
		toplam += sepet[i].getFiyat();
	return toplam;
}


void MainMenu::AlisverisiBitir() {
	cls();
	string selection = "0";
	string ilce;
	bool indirim = false;

	if (kullanici.getIndirimKodu() != "0000000") {
		cout << "Indirim kodunuz " << kullanici.getIndirimKodu() << " kullanildi ve fiyatta %15 indirim yapildi." << endl;
		indirim = true;
	}

	if (kullanici.getAdresIlce() == "1")
	{
		ilce = "Ortahisar";
	}
	else if (kullanici.getAdresIlce() == "2")
	{
		ilce = "Akcaabat";
	}
	else if (kullanici.getAdresIlce() == "3")
	{
		ilce = "Vakfikebir";
	}
	else if (kullanici.getAdresIlce() == "4")
	{
		ilce = "Besikduzu";
	}
	else if (kullanici.getAdresIlce() == "5")
	{
		ilce = "Yomra";
	}
	else if (kullanici.getAdresIlce() == "6")
	{
		ilce = "Arsin";
	}
	else if (kullanici.getAdresIlce() == "7")
	{
		ilce = "Arakli";
	}
	else
		ilce = "Hata!";

	int tutar;

	if (indirim) {
		tutar = SepetFiyati() - (SepetFiyati() * 0.15);
	}
	else{
		tutar = SepetFiyati();
	}
	
	cout << "Satin aldiginiz urunler: " << endl;
	for (int i = 0; i < sepetBoyutu; i++)
		cout << "\t" << sepet[i].getIsim() << " " << sepet[i].getKategori() << " " << sepet[i].getBoyut() << "Beden " << sepet[i].getRenk() << " " << sepet[i].getFiyat() << "TL" << endl;
	cout << "Toplam tutar: " << tutar << "TL" << endl;
	cout << "Urunlerin gonderilecegi adres: " << ilce << endl;
	ofstream faturatxt("fatura.txt", ios::app);
	string urunler = "";
	auto kurye = kurye_gonderme();
	auto zaman = kurye.getDagitimBitisler();
	for (int i = 0; i < sepetBoyutu; i++) {
		urunler += "\\t" + sepet[i].getIsim() + " " + sepet[i].getKategori() + " " + sepet[i].getBoyut() + "Beden " + sepet[i].getRenk() + " " + to_string(sepet[i].getFiyat()) + "TL\\n";
	}

	if (!indirim) {
		faturatxt << "Alisverisi yapan: " << kullanici.getKullaniciAdi() << "\\nAlinan urunler: \\n" << urunler << "Gonderilecek adres: " << kullanici.getAdresIlce() << " Toplam fiyat: " << tutar << "\\n" << "Gonderilen kurye: \\n\\t " << kurye.getAd() << " " << kurye.getSoyad() << "\\n\\t" << "Telefon numarasi: " << kurye.getTelNo() << "\\n\\t" << "Teslim saati: " << zaman << "\\n\\n" << endl;
	}
	else {
		faturatxt << "Alisverisi yapan: " << kullanici.getKullaniciAdi() << "\\nAlinan urunler: \\n" << urunler << "Gonderilecek adres: " << kullanici.getAdresIlce() << " Toplam fiyat: " << tutar << "TL (" << kullanici.getIndirimKodu() << " koduyla %15 indirim uygulandi.)" << "\\n" << "Gonderilen kurye: \\n\\t " << kurye.getAd() << " " << kurye.getSoyad() << "\\n\\t" << "Telefon numarasi: " << kurye.getTelNo() << "\\n\\t" << "Teslim saati: " << zaman << "\\n\\n" << endl;
		kullanici.setIndirimKodu("0");
	}

	if (indirim) {
		string kullaniciAdi, sifre, k, s, tel, mail, ad, soyad, adres, dogum, kod;
		ifstream i("kullanici.txt");
		ofstream o("temp.txt");
		kullanici.setIndirimKodu("0000000");
		while (i >> k >> s >> tel >> mail >> ad >> soyad >> adres >> dogum >> kod)
		{
			if (k == kullanici.getKullaniciAdi())
			{
				o << k << " " << s << " " << tel << " " << mail << " " << ad << " " << soyad << " " << adres << " " << dogum << " " << kullanici.getIndirimKodu() << endl;
			}
			else
			{
				o << k << " " << s << " " << tel << " " << mail << " " << ad << " " << soyad << " " << adres << " " << dogum << " " << kod << endl;
			}
		}
		i.close();
		o.close();
		remove("kullanici.txt");
		rename("temp.txt", "kullanici.txt");
	}
	
	faturatxt.close();
	sepetBoyutu = 0;
	cout << "Bir modul secerek isleminize devam edebilirsiniz.\n" << endl;
	cout << "[1] Menuye Don\n" << endl;
	
	while (!Selection(selection, 1))
	{
		Selection(selection, 1);
	}
	
	switch (stoi(selection))
	{
	case 1:
		MusteriMenu();
		break;
	default:
		break;
	}

}


void MainMenu::SiparisTakipMenu() {
	cls();
	string selection = "0";
	cout << "Siparisleriniz: \n" << endl;
	ifstream faturatxt("fatura.txt");
	string text;
	int index = 0;

	while (getline(faturatxt, text))
	{
		auto pos = text.find("Alisverisi yapan: " + kullanici.getKullaniciAdi() + "\\");
		//cout << pos << endl;
		if (pos == 0) {
			cout << "[" << index + 1 << "]" << endl;
			size_t position;
			while ((position = text.find("\\n")) != std::string::npos) {
				text.replace(position, 2, "\n");
			}
			while ((position = text.find("\\t")) != std::string::npos) {
				text.replace(position, 2, "\t");
			}
			cout << text << endl;
			index++;
		}
	}
	faturatxt.close();
	cout << "\n";
	cout << "Bir modul secerek isleminize devam edebilirsiniz.\n[1] Ana Menuye Don\n" << endl;
	
	while (!Selection(selection, 1))
	{
		Selection(selection, 1);
	}
	
	switch (stoi(selection))
	{
	case 1:
		MusteriMenu();
		break;
	default:
		break;
	}

}


void MainMenu::fatura_goruntuleme() {
	cls();
	string selection = "0";
	cout << "Siparisler: \n" << endl;
	ifstream faturatxt("fatura.txt");
	string text;
	int index = 0;

	while (getline(faturatxt, text))
	{
		cout << "[" << index + 1 << "]" << endl;
		size_t position;
		while ((position = text.find("\\n")) != std::string::npos) {
			text.replace(position, 2, "\n");
		}
		while ((position = text.find("\\t")) != std::string::npos) {
			text.replace(position, 2, "\t");
		}
		cout << text << endl;
		index++;
	}
	faturatxt.close();
	cout << "\n";
	cout << "Bir modul secerek isleminize devam edebilirsiniz" << endl;
	cout << "[1] Menuye Don\n" << endl;

	while (!Selection(selection, 1))
	{
		Selection(selection, 1);
	}
	switch (stoi(selection))
	{
	case 1:
		YoneticiMenu();
		break;
	default:
		break;
	}
}


Kurye MainMenu::kurye_gonderme()
{
	string adres;
	Zaman adres_zaman;
	Kurye kurye; //bu kurye return edilecek

	int position = 0;

	simdi.setDakika(ltm->tm_min);
	simdi.setSaat(ltm->tm_hour);

	string kurye_ad, kurye_soyad, kurye_tel, kurye_donus_saati, kurye_donus_dakikasi;

	adres = kullanici.getAdresIlce();

	if (adres == "1" || adres == "Ortahisar")
	{
		adres_zaman.setSaat(0);
		adres_zaman.setDakika(35);
	}
	else if (adres == "2" || adres == "Akçaabat")
	{
		adres_zaman.setSaat(0);
		adres_zaman.setDakika(50);
	}
	else if (adres == "3" || adres == "Vakfıkebir")
	{
		adres_zaman.setSaat(1);
		adres_zaman.setDakika(30);
	}
	else if (adres == "4" || adres == "Beşikdüzü")
	{
		adres_zaman.setSaat(1);
		adres_zaman.setDakika(50);
	}
	else if (adres == "5" || adres == "Yomra")
	{
		adres_zaman.setSaat(0);
		adres_zaman.setDakika(55);
	}
	else if (adres == "6" || adres == "Arsin")
	{
		adres_zaman.setSaat(1);
		adres_zaman.setDakika(20);
	}
	else if (adres == "7" || adres == "Araklı")
	{
		adres_zaman.setSaat(1);
		adres_zaman.setDakika(40);
	}
	else
		cout << "Hata" << endl;


	ifstream kurye_txt("kuryeler.txt");
	ofstream temp("temp.txt");

	Zaman sifir;
	sifir.setSaat(999);
	sifir.setDakika(999);
	Kurye encabuk;
	encabuk.setDagitimBitisler(sifir);
	int ctr = 0;
	bool isSent = false;
	while (kurye_txt >> kurye_ad >> kurye_soyad >> kurye_tel >> kurye_donus_saati >> kurye_donus_dakikasi)
	{
		if (kurye_donus_saati == "0" && kurye_donus_dakikasi == "0" && !isSent)
		{
			isSent = true;
			ctr++;
			Zaman kurye_donus_zamani;
			kurye_donus_zamani = simdi + adres_zaman;
			kurye.setAd(kurye_ad);
			kurye.setSoyad(kurye_soyad);
			kurye.setTelNo(kurye_tel);
			kurye.setDagitimBitisler(kurye_donus_zamani);

			temp << kurye_ad << " " << kurye_soyad << " " << kurye_tel << " " << kurye_donus_zamani.getSaat() << " " << kurye_donus_zamani.getDakika() << endl;

		}
		else
		{
			temp << kurye_ad << " " << kurye_soyad << " " << kurye_tel << " " << kurye_donus_saati << " " << kurye_donus_dakikasi << endl;
		}
	}


	if (ctr != 0) {
		kurye_txt.close();
		temp.close();
		remove("kuryeler.txt");
		rename("temp.txt", "kuryeler.txt");
		cout << "Kurye gonderildi. Tahmini varis zamani: " << kurye.getDagitimBitisler() << endl;
		return kurye;
	}
	else {
		temp.close();
		kurye_txt.close();
		remove("temp.txt");
		ifstream txt("kuryeler.txt");
		int ctr2 = 0;
		while (txt >> kurye_ad >> kurye_soyad >> kurye_tel >> kurye_donus_saati >> kurye_donus_dakikasi)
		{
			if ((stoi(kurye_donus_saati) < encabuk.getDagitimBitisler().getSaat() || (stoi(kurye_donus_saati) == encabuk.getDagitimBitisler().getSaat() && stoi(kurye_donus_dakikasi) < encabuk.getDagitimBitisler().getDakika())))
			{
				ctr2++;
				encabuk.setAd(kurye_ad);
				encabuk.setSoyad(kurye_soyad);
				encabuk.setTelNo(kurye_tel);
				sifir.setSaat(stoi(kurye_donus_saati));
				sifir.setDakika(stoi(kurye_donus_dakikasi));
				encabuk.setDagitimBitisler(sifir + adres_zaman);
			}
		}
		if (ctr2 != 0) {
			txt.close();
			ifstream txt2("kuryeler.txt");
			//cout << ctr2 << "dddd" << endl;
			ofstream temp2("temp2.txt");
			while (txt2 >> kurye_ad >> kurye_soyad >> kurye_tel >> kurye_donus_saati >> kurye_donus_dakikasi)
			{
				if (kurye_ad == encabuk.getAd()) {
					temp2 << kurye_ad << " " << kurye_soyad << " " << kurye_tel << " " << encabuk.getDagitimBitisler().getSaat() << " " << encabuk.getDagitimBitisler().getDakika() << endl;
				}
				else
				{
					temp2 << kurye_ad << " " << kurye_soyad << " " << kurye_tel << " " << kurye_donus_saati << " " << kurye_donus_dakikasi << endl;
				}
			}
			temp2.close();
			txt2.close();
			remove("kuryeler.txt");
			rename("temp2.txt", "kuryeler.txt");
			cout << "Kurye yola cikti, tahmini donus saati : " << encabuk.getDagitimBitisler() << endl;
			return encabuk;
		}
		else {
			cout << "Uygun kurye yok." << endl;
		}
	}


}


void MainMenu::SifreDegistirMenu() {
	cls();
	ofstream out("temp.txt");
	ifstream in("kullanici.txt");
	string ys;
	cout << "Yeni sifrenizi giriniz: ";
	PasswordMasking(ys);
	while (true)
	{
		if (!PasswordVerification(ys)) {
			ys = "";
			cout << "\nSifre yeterince guclu degil. Yeniden deneyiniz: ";
			PasswordMasking(ys);
		}
		else
		{
			break;
		}
	}
	string k, s, ad, soyad, dt, adres, tel, mail, kod;
	while (in >> k >> s >> ad >> soyad >> dt >> adres >> tel >> mail >> kod)
	{
		if (k == kullanici.getKullaniciAdi()) {
			out << k << " " << ys << " " << ad << " " << soyad << " " << dt << " " << adres << " " << tel << " " << mail << " " << kod << endl;
		}
		else {
			out << k << " " << s << " " << ad << " " << soyad << " " << dt << " " << adres << " " << tel << " " << mail << " " << kod << endl;
		}
	}
	kullanici.setSifre(ys);
	out.close();
	in.close();
	remove("kullanici.txt");
	rename("temp.txt", "kullanici.txt");
	cls();
	cout << "Sifreniz basariyla degistirildi.\n" << endl;
	cout << "Bir modul secerek isleminize devam edebilirsiniz." << endl;
	cout << "[1] Menuye Don\n" << endl;
	
	string selection = "0";
	while (!Selection(selection, 1))
	{
		Selection(selection, 1);
	}
	switch (stoi(selection))
	{
	case 1:
		MusteriMenu();
		break;
	default:
		break;
	}
}


int main()
{
	MainMenu mainMenu;
	mainMenu.start();
	return 0;
}
