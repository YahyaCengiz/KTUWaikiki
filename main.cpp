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
	cout << "Modüllerden birini seçerek işleminize devam edebilirsiniz." << endl;
	cout << "[1] Sisteme giriş.\n" << "[2] Yeni üye kayıt.\n"<< "[3] Çıkış." << endl;

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
		cout << "Başarıyla çıktınız." << endl;
		break;
	default:
		cout << "Hatalı seçim yaptınız, lütfen tekrar deneyiniz." << endl;
		start();
		break;
	}

}

void MainMenu::GirisMenu()
{
	ktuWaikikiText();
	int selection;
	cout << "Giriş yapmak istediğiniz modülü seçiniz.\n" << "[1] Müşteri girişi.\n" << "[2] Yönetici girişi." << endl;
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
		cout << "Hatalı seçim yaptınız, lütfen tekrar deneyiniz." << endl;
		GirisMenu();
		break;
	}
}

void MainMenu::MusteriGirisMenu()
{
	string kullaniciAdi, sifre, k, s, tel, tc;
    int ctr = 0;
	ktuWaikikiText();
	cout << "Kullanıcı adınızı giriniz: ";
	cin >> kullaniciAdi;
	cout << "Şifrenizi giriniz: ";
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
	cout << "Adınız: "; cin >> ad;
	cout << "Soyadınız: "; cin >> soyad;
	cout << "Doğum Tarihiniz: "; cin >> dogumTarihi;
	cout << "Adresiniz: "; cin >> adres;
	cout << "Telefon Numaranız: "; cin >> telNo;
	cout << "Mail Adresiniz: "; cin >> mail;
	//mail adresi kontrol edilecek;
	cout << "Bir kullanıcı adı belirleyiniz: "; cin >> kullaniciAdi;
	cout << "Bir şifre adı belirleyiniz: "; cin >> sifre;

	ofstream txt("kullanici.txt", ios::app);
	txt << kullaniciAdi << " " << sifre << endl;

	cout << "\nKayıt başarılı, keyifli alışverişler." << endl;
	MusteriGirisMenu();
}

void MainMenu::YoneticiGirisMenu()
{
	ktuWaikikiText();
	cout << "Yönetici şifresini giriniz." << endl;
}

int main()
{
	//türkçe karakterleri kullannmak için
	setlocale(LC_ALL, "Turkish");
	MainMenu mainMenu;
	mainMenu.start();
	return 0;
}
