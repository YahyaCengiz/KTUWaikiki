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

	private:

};


void MainMenu::start()
{
	int selection;
	ktuWaikikiText();
	cout << "Modullerden birini secerek isleminize devam edebilirsiniz." << endl;
	cout << "[1] Sisteme giris.\n" << "[2] Yeni uye kayit.\n"<< "[3] Cikis." << endl;

	cin >> selection;
	system("CLS");
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

	while(txt >> k >> s >> tel >> tc){
        if(k == kullaniciAdi && s == sifre){
            ctr = 1;
            break;
        }
	}
	txt.close();
	if(ctr == 1){
        cout << "giris yapildi" << endl;
        cout << "telno: " << tel << " tcno: " << tc << endl;
	}else{
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
	cout << "Yonetici sifresini giriniz." << endl;
}

int main()
{
	//türkçe karakterleri kullannmak için
	setlocale(LC_ALL, "Turkish");
	MainMenu mainMenu;
	mainMenu.start();
	cout << "1";
	return 0;
}
