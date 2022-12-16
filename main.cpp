#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <locale.h>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <istream>
#include <sstream>
#include <stdio.h>
#include <io.h>
#include <conio.h>
#include <ctime>

using namespace std;

inline void cls() { system("CLS"); }

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


	ostream& operator<<(ostream& os) {
		os << getKategori() << " " << getBoyut() << "Beden " << getRenk() << " " << getFiyat() << "TL" << endl;
		return os;
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
	void KategoriMenu();
	void MusteriMenu();
	void YoneticiGirisMenu();
	void YoneticiMenu();
	void urun_ekleme();
	void kurye_ekleme();
	void sikayet_okuma();
	void kupon_tanimlama();
	void SiparisTakipMenu();
	void UrunSecimMenu(string);
	void AlisverisiBitir();
	bool MailVerification(string mail);
	void fatura_goruntuleme();
	Kullanici kullanici;
	Siparis siparis;
	int sepetBoyutu = 0;
	Kiyafet sepet[20];
	//void SepeteEkle(Kiyafet);
	
	int SepetFiyati();

private:

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
	string ad = "-";
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
	cout << "[1] Sisteme giris.\n" << "[2] Yeni uye kayit.\n" << "[3] Cikis." << endl;

	cin >> selection;
	cls();
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
	cls();


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
	string kullaniciAdi, sifre, k, s, tel, mail, ad, soyad, adres, dogum, kod;
	int ctr = 0;
	ktuWaikikiText();
	cout << "Kullanici adinizi giriniz: ";
	cin >> kullaniciAdi;
	cout << "Sifrenizi giriniz: ";
	cin >> sifre;
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
	else {
		cout << "olmadi " << ctr;
	}
}

void MainMenu::MusteriKayitMenu()
{
	//değerler müşteri classına geçirilecek
	string ad, soyad, telNo, kullaniciAdi, sifre, mail, dogumTarihi, kod = "0";
	int adres;

	ktuWaikikiText();
	cout << "Adiniz: "; cin >> ad;
	cout << "Soyadiniz: "; cin >> soyad;
	cout << "Dogum Tarihiniz: "; cin >> dogumTarihi;
	cout << "Adresiniz: " << endl;
	cout << "[1] Ortahisar \n[2] Akcaabat \n[3] Vakfikebir \n[4] Besikduzu \n[5] Yomra \n[6] Arsin \n[7] Arakli " << endl;
	cin >> adres;
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

void MainMenu::MusteriMenu()
{
	cls();
	ktuWaikikiText();
	int selection;
	cout << "Giris yapmak istediginiz modulu seciniz.\n" << "[1] Kategorileri goster.\n" << "[2] Siparis takip.\n"
		<< "[3] Sikayet/Oneri.\n" << "[4] Sifre Degistir.\n" << endl;
	cin >> selection;
	cls();
	switch (selection)
	{
	case 1:
		KategoriMenu();
		break;
	case 2:
		SiparisTakipMenu();
		break;
	default:
		break;
	}
}


void MainMenu::YoneticiGirisMenu()
{
	ktuWaikikiText();
	Yonetici yonetici("password");
	string yoneticiSifre, y, s, ad, soyad, dogum, adres, tel, mail, kod;
	int ctr = 0;
	fstream txt("kullanici.txt", ios::in);

	cout << "Yonetici sifresini giriniz." << endl;
	cin >> yoneticiSifre;
	while (txt >> y >> s >> ad >> soyad >> dogum >> adres >> tel >> mail >> kod) {
		if (y == "admin" && s == "password") {
			ctr = 1;
			break;
		}
	}
	txt.close();
	txt.open("kullanici.txt", ios::app);
	if (ctr == 1 && yoneticiSifre == "password") {
		cout << "Giris Yapildi..." << endl;
		YoneticiMenu();
	}
	else {
		txt << "admin" << " " << "password" << " " << "-" << " " << "-" << " " << "-" << " " << "-" << " " << "-" << " " << "-" << " " << "-" << endl;
		txt.close();
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
	ktuWaikikiText();
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
	txt << kurye_adi << " " << kurye_soyadi << " " << kurye_telno << endl;
	cout << "Basariyla Eklendi" << endl;
	YoneticiMenu();
	// Burayı tekrardan yazmak gerek.
	  // Kişi Sınıfından ad soyad bilgilerini ayrı ayrı almamız gerek. Ayrıca Txt yazdırma işi tamam ama kurye objesine değer gönderirken sıkıntı çıktı.
	  // Kuryelerin gidiş geliş saatleri txt'ye kaydedilecek.Adam ol

}


void MainMenu::YoneticiMenu()
{
	int selection;
	cls();
	cout << "Modullerden birini secerek isleminize devam edebilirsiniz." << endl;
	cout << "\n";
	cout << "[1] Urun Ekleme.\n" << "[2] Kurye Ekleme.\n" << "[3] Sikayet Oneri Okuma.\n" << "[4] Indirim Kodu Tanimlama.\n" << "[5] Fatura Goruntuleme.\n" << "[6] Cikis.\n" << endl;
	cin >> selection;
	switch (selection)
	{
	case 1:
		urun_ekleme();
		break;
	case 2:
		kurye_ekleme();
		break;
	case 3:
		sikayet_okuma();
	case 4:
		kupon_tanimlama();
	}

}

void MainMenu::urun_ekleme()
{
	ofstream urunler("urunler.txt", ios::app);
	string kategori, fiyat, boyut, renk;
	int kategori_secim;
	//elbise, tisort, pantolon, gomlek, etek, ayakkabi, kategori_secim;
	cout << "Urunun Kategorisi : \n [1] Elbise \n [2] Tisort \n [3] Pantolon \n [4] Gomlek \n [5] Etek \n [6] Ayakkabi" << endl;
	cin >> kategori_secim;
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
	cout << "Urunun Fiyati : " << endl;
	cin >> fiyat;
	cout << "Urunun Boyutu : " << endl;
	cin >> boyut;
	cout << "Urunun Rengi : " << endl;
	cin >> renk;
	urunler << kategori << " " << fiyat << " " << boyut << " " << renk << "\n";

	urunler.close();
	cout << "Basariyla Eklendi..." << endl;
	YoneticiMenu();
}


void MainMenu::sikayet_okuma()
{
	ifstream txt("sikayet.txt");
	string text;
	while (txt)
	{
		text = txt.get();
		cout << text;
	}
	int select;
	cout << "\n\nDevam etmek icin 1'e bas." << endl;
	cin >> select;
	switch (select)
	{
	case 1:
		YoneticiMenu();
	default:
		break;
	}
}



void MainMenu::kupon_tanimlama()
{
	cls(); ktuWaikikiText();
	cout << "Kupon tanimlanacak kullanici adini giriniz: ";
	string hangikullanici; cin >> hangikullanici;
	cout << "Kupon kodunu giriniz: ";
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
	
	txt.close();
}

bool MainMenu::MailVerification(string mail) {
	if (mail.find("@") != string::npos && mail.find(".com") != string::npos)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void MainMenu::KategoriMenu() {
	cls();
	int selection;
	cout << "Kategorilerden birini secerek isleminize devam edebilirsiniz." << endl;
	cout << "\n";
	cout << "[1] Elbise.\n" << "[2] Tisort.\n" << "[3] Pantolon.\n" << "[4] Gomlek.\n" << "[5] Etek.\n" << "[6] Ayakkabi.\n" << "[7] Geri Don.\n" << endl;
	cin >> selection;
	switch (selection)
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
	int selection;
	string kategoria, fiyat, boyut, renk;
	cout << "Bir " << kategori << " secerek isleminize devam edebilirsiniz." << endl;
	cout << "Su anki sepet tutariniz: " << SepetFiyati() << "TL" << endl;
	cout << "\n";
	ifstream uruntxt("urunler.txt");
	string text;
	int index = 0;
	Kiyafet kiyafet[10] = { Kiyafet() };
	while (uruntxt >> kategoria >> fiyat >> boyut >> renk)
	{
		//cout << "[" << index << "]" << fiyat << "TL " << boyut << "Beden " << renk << endl;
		if (kategoria == kategori) {
			kiyafet[index].setKategori(kategoria);
			kiyafet[index].setFiyat(stoi(fiyat));
			kiyafet[index].setBoyut(boyut);
			kiyafet[index].setRenk(renk);
			index++;
			cout << "[" << index << "] " << boyut << "Beden " << renk << " " << fiyat << "TL " << endl;
		}
	}
	uruntxt.close();
	if (index == 0) {
		cout << "Bu kategoride hic urun yok." << endl;
		cout << "[1] Kategori Secimine Don\n" << "[2] Ana Menuye Don\n" << endl;
		cin >> selection;
		switch (selection)
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
		cout << "\n";
		cin >> selection;
		sepet[sepetBoyutu] = kiyafet[selection - 1];
		sepetBoyutu++;
		cls();
		cout << "Urununuz sepete eklendi. Anlik sepet tutari: " << SepetFiyati() << "TL\n" << endl;
		cout << "Devam etmek icin bir islem seciniz." << endl;
		cout << "[1] Alisverise devam et.\n[2] Alisverisi bitir.\n" << endl;
		cin >> selection;
		switch (selection)
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
	int selection;
	cout << "Satin aldiginiz urunler: " << endl;
	for (int i = 0; i < sepetBoyutu; i++)
		cout << "\t" << sepet[i].getKategori() << " " << sepet[i].getBoyut() << "Beden " << sepet[i].getRenk() << " " << sepet[i].getFiyat() << "TL" << endl;
	cout << "Toplam tutar: " << SepetFiyati() << "TL" << endl;
	cout << "Urunlerin gonderilecegi adres: " << kullanici.getAdresIlce() << endl;
	ofstream faturatxt("fatura.txt", ios::app);
	string urunler = "";
	for (int i = 0; i < sepetBoyutu; i++) {
		urunler += "\\t" + sepet[i].getKategori() + " " + sepet[i].getBoyut() + "Beden " + sepet[i].getRenk() + " " + to_string(sepet[i].getFiyat()) + "TL\\n";
	}
	faturatxt << "Alisverisi yapan: " << kullanici.getKullaniciAdi() << "\\nAlinan urunler: \\n" << urunler << "Gonderilecek adres: " << kullanici.getAdresIlce() << " Toplam fiyat: " << SepetFiyati() << "\\n\\n" << endl;
	//kurye gonderilecek
	//siparis takip fonksiyonu yazilacak
	cin >> selection;
	sepetBoyutu = 0;
	cls();
	MusteriMenu();
	
}

void MainMenu::SiparisTakipMenu() {
	cls();
	int selection;
	cout << "Siparisleriniz: \n" << endl;
	ifstream faturatxt("fatura.txt");
	string text;
	int index = 0;
	
	while (getline(faturatxt, text))
	{
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
	cout << "Bir modul secerek isleminize devam edebilirsiniz.\n[1] Ana Menuye Don\n" << endl;
	cin >> selection;
	switch (selection)
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
	////Simdiki Zaman Icin Bir Zaman Objesi Olusturduk
	//Zaman zaman;
	//time_t now = time(0);
	//tm* ltm = localtime(&now);
	//zaman.setDakika(ltm->tm_min);
	//zaman.setSaat(ltm->tm_hour);

	//// Kurye'nin Gidis-Gelis Zamani
	//Zaman kurye_zaman;
	//kurye_zaman.setSaat(12);
	//kurye_zaman.setDakika(50);

	//// Kurye'nin Donus Zamani
	//Zaman kurye_donus;
	//kurye_donus = zaman + kurye_zaman;

	MainMenu mainMenu;
	mainMenu.start();
	return 0;
}