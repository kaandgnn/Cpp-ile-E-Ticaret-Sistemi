#include <iostream>
#include <ctime>
#include <fstream>
#include <unistd.h>


#define ANAMENU 0
#define SISTEMEGIRISMENU 1
#define UYEKAYDIMENU 2
#define CIKISMENU 3
#define YONETICIGIRISIMENU 11
#define MUSTERIGIRISIMENU 12
#define GIRISGERIDONMENU 13
#define YONETICIKAYITMENU 21
#define KULLANICIKAYITMENU 22
#define KAYITGERIDONMENU 23
#define YONETICIMENU 110
#define MUSTERIMENU 120
#define YONETICIMENUURUNGIRIS 111
#define YONETICIMENUKURYEEKLE 112
#define YONETICIMENUSIKAYETONERI 113
#define YONETICIMENUKUPONMENU 114
#define YONETICIMENUFATURAGORUNTULE 115
#define YONETICIMENUCIKIS 116
#define MUSTERIMENUURUNARA 121
#define MUSTERIMENUSIPARISLER 122
#define MUSTERIMENUSIKAYETONERI 123
#define MUSTERIMENUSIFREDEGISTIR 124
#define MUSTERIMENUCIKIS 125
#define A42B4479_1D0A_4BD5_84A1_27B66FCF568D

using namespace std;

class kisi // kişi sınıfı
{
	protected:
		string ad_soyad;
		string telno;
	public:
		kisi()
		{

		}
		kisi(string ad_soyad, string telno)
		{
			this->ad_soyad = ad_soyad;
			this->telno = telno;
		}
		~kisi()
		{
		}
		void set_ad_soyad(string ad_soyad)
		{
			this->ad_soyad = ad_soyad;
		}
		void set_telno(string telno)
		{
			this->telno = telno;
		}
		string get_ad_soyad()
		{
			return ad_soyad;
		}
		string get_telno()
		{
			return telno;
		}
};

class kiyafet // kıyafet sınıfı
{
	protected:
		string kategori;
		string kiyafet_adi;
		string renk;
		string boyut;
		double fiyat;
	public:
		kiyafet()
		{

		}
		kiyafet(string kategori, string kiyafet_adi, string renk, string boyut, double fiyat) // kıyafet sınıfının kurucu fonksiyonu
		{
			this->kategori = kategori;
			this->kiyafet_adi = kiyafet_adi;
			this->renk = renk;
			this->boyut = boyut;
			this->fiyat = fiyat;
		}
		~kiyafet()
		{
		}
		string get_kiyafet_adi()
		{
			return this->kiyafet_adi;
		}
		string get_renk()
		{
			return this->renk;
		}
		string get_boyut()
		{
			return this->boyut;
		}
		double get_fiyat()
		{
			return this->fiyat;
		}
		string get_kategori()
		{
			return this->kategori;
		}
		void set_kiyafet_adi(string kiyafet_adi)
		{
			this->kiyafet_adi = kiyafet_adi;
		}
		void set_renk(string renk)
		{
			this->renk = renk;
		}
		void set_boyut(string boyut)
		{
			this->boyut = boyut;
		}
		void set_fiyat(double fiyat)
		{
			this->fiyat = fiyat;
		}
		void set_kategori(string kategori)
		{
			this->kategori = kategori;
		}
};

class sikayet // şikayet sınıfı
{
	private:
		string yazan;
		string sikayet_icerigi;
	public:
		sikayet()
		{

		}
		sikayet(string yazan, string sikayet_icerigi)
		{
			this->yazan = yazan;
			this->sikayet_icerigi = sikayet_icerigi;
		}
		~sikayet()
		{
		}
		void set_yazan(string yazan)
		{
			this->yazan = yazan;
		}
		void set_sikayet_icerigi(string sikayet_icerigi)
		{
			this->sikayet_icerigi = sikayet_icerigi;
		}
		string get_yazan()
		{
			return this->yazan;
		}
		string get_sikayet_icerigi()
		{
			return this->sikayet_icerigi;
		}
};

class yonetici: public kisi // yönetici sınıfı aynı zamanda kişi sınıfından miras alır
{
	private:
		string sifre;
	public:
		yonetici()
		{

		}
		yonetici(string ad_soyad, string telno, string sifre): kisi(ad_soyad, telno)
		{
			this->sifre = sifre;
		}
		~yonetici()
		{
		}
		void set_sifre(string sifre)
		{
			this->sifre = sifre;
		}
		string get_sifre()
		{
			return this->sifre;
		}
};

class zaman
{
	private:
		int saat;
		int dakika;
	public:
		zaman()
		{
			this->saat = 0;
			this->dakika = 0;
		}
		zaman(string z)
		{
			this->saat = stoi(z.substr(0, 2)); // substr fonksiyonu ile saati string olarak alıp int'e çeviriyoruz
			this->dakika = stoi(z.substr(3, 2)); // 3. indisten başlayarak 2 karakter al yani 10:30'un 3. indexi olan 3den başlayarak 2 karakter al yani 30'u al
		}
		~zaman()
		{
		}
		int get_saat()
		{
			return this->saat;
		}
		int get_dakika()
		{
			return this->dakika;
		}
		zaman operator+(const zaman &z) // + operatörünü overload ediyoruz
		{
			zaman toplam;
			toplam.saat = this->saat + z.saat;
			toplam.dakika = this->dakika + z.dakika;
			if(toplam.dakika >= 60)
			{
				toplam.dakika -= 60;
				toplam.saat++;
			}
			return toplam;
		}
};

class kullanici: public kisi // kullanıcı sınıfı aynı zamanda kişi sınıfından miras alır
{
	private:
		string kullanici_adi;
		string sifre;
		string eposta;
		string adres;
		string dogum_tarihi;
		string indirim_kodu;
	public:
		kullanici()
		{

		}
		kullanici(string ad_soyad, string telno, string kullanici_adi, string sifre, string eposta, string adres, string dogum_tarihi, string indirim_kodu): kisi(ad_soyad, telno)
		{
			this->kullanici_adi = kullanici_adi;
			this->sifre = sifre;
			this->eposta = eposta;
			this->adres = adres;
			this->dogum_tarihi = dogum_tarihi;
			this->indirim_kodu = indirim_kodu;
		}
		~kullanici()
		{
		}
		void set_kullanici_adi(string kullanici_adi)
		{
			this->kullanici_adi = kullanici_adi;
		}
		void set_sifre(string sifre)
		{
			this->sifre = sifre;
		}
		void set_eposta(string eposta)
		{
			this->eposta = eposta;
		}
		void set_adres(string adres)
		{
			this->adres = adres;
		}
		void set_dogum_tarihi(string dogum_tarihi)
		{
			this->dogum_tarihi = dogum_tarihi;
		}
		void set_indirim_kodu(string indirim_kodu)
		{
			this->indirim_kodu = indirim_kodu;
		}
		string get_kullanici_adi()
		{
			return this->kullanici_adi;
		}
		string get_sifre()
		{
			return this->sifre;
		}
		string get_eposta()
		{
			return this->eposta;
		}
		string get_adres()
		{
			return this->adres;
		}
		string get_dogum_tarihi()
		{
			return this->dogum_tarihi;
		}
		string get_indirim_kodu()
		{
			return this->indirim_kodu;
		}
};

class kurye: public kisi // kurye sınıfı aynı zamanda kişi sınıfından miras alır
{
	private:
		zaman *dagitim_bitisler;
		int *siparis_numaralari;
	public:
		kurye()
		{

		}
		kurye(string ad_soyad, string telno, zaman *dagitim_bitisler, int *siparis_numaralari): kisi(ad_soyad, telno)
		{
			this->dagitim_bitisler = dagitim_bitisler;
			this->siparis_numaralari = siparis_numaralari;
		}
		~kurye()
		{
		}
};

int no = 0;

class siparis: public kiyafet // sipariş sınıfı aynı zamanda kıyafet sınıfından miras alır
{
	private:
		int siparis_no;
		double siparis_tutari;
		zaman *siparis_tarihi;
		zaman *teslimat_tarihi;
		string adres;
		string kullanici;
		string kurye_no;
		string durum;
	public:
		siparis()
		{
			siparis_no = no;
			no++;
		}
		~siparis()
		{
		}
		void set_siparis_no(int siparis_no)
		{
			this->siparis_no = siparis_no;
		}
		void set_siparis_tutari(double siparis_tutari)
		{
			this->siparis_tutari = siparis_tutari;
		}
		void set_siparis_tarihi(zaman *siparis_tarihi)
		{
			this->siparis_tarihi = siparis_tarihi;
		}
		void set_teslimat_tarihi(zaman *teslimat_tarihi)
		{
			this->teslimat_tarihi = teslimat_tarihi;
		}
		void set_adres(string adres)
		{
			this->adres = adres;
		}
		void set_kullanici(string kullanici)
		{
			this->kullanici = kullanici;
		}
		void set_kurye_no(string kurye_no)
		{
			this->kurye_no = kurye_no;
		}
		int get_siparis_no()
		{
			return this->siparis_no;
		}
		double get_siparis_tutari()
		{
			return this->siparis_tutari;
		}
		zaman *get_siparis_tarihi()
		{
			return this->siparis_tarihi;
		}
		zaman *get_teslimat_tarihi()
		{
			return this->teslimat_tarihi;
		}
		string get_adres()
		{
			return this->adres;
		}
		string get_kullanici()
		{
			return this->kullanici;
		}
		string get_kurye_no()
		{
			return this->kurye_no;
		}
		string get_durum()
		{
			return this->durum;
		}
		void set_durum(string durum)
		{
			this->durum = durum;
		}
};

class Veri // veri sınıfı
{
	private:
		kullanici *kullanicilar;
		yonetici *yoneticiler;
		kurye *kuryeler;
		siparis *siparisler;
		kiyafet *kiyafetler;
		sikayet *sikayetler;
		int kullanici_sayisi;
		int yonetici_sayisi;
		int kurye_sayisi;
		int siparis_sayisi;
		int kiyafet_sayisi;
		int sikayet_sayisi;
	public:
		Veri()
		{
			kullanicilar = NULL; // başlangıçta verilerin tutulacağı değişkenlerin değerleri NULL olarak atanır
			yoneticiler = NULL;
			kuryeler = NULL;
			siparisler = NULL;
			kiyafetler = NULL;
			sikayetler = NULL;
			kullanici_sayisi = 0; // başlangıçta verilerin tutulacağı değişkenlerin değerleri 0 olarak atanır
			yonetici_sayisi = 0;
			kurye_sayisi = 0;
			siparis_sayisi = 0;
			kiyafet_sayisi = 0;
			sikayet_sayisi = 0;
		}
		~Veri() // veri sınıfının yıkıcı fonksiyonu ve yıkarken uyguladığı işlemler
		{
			delete [] kullanicilar;
			delete [] yoneticiler;
			delete [] kuryeler;
			delete [] siparisler;
			delete [] kiyafetler;
			delete [] sikayetler;
		}
		void kullanicilariOku(void) // kullanıcıları okuyan fonksiyon
		{
			fstream dosya;

			dosya.open("kullanicilar.txt"); // kullanicilar.txt dosyasını açar
			string line;
			while(getline(dosya, line)) // dosyadaki her bir satırı okur
			{
				if (line.substr(0, 9) == "kullanici") // satırın başındaki kullanıcı kelimesini kontrol eder
					kullanici_sayisi++;
				else if (line.substr(0, 8) == "yonetici") // satırın başındaki yönetici kelimesini kontrol eder
					yonetici_sayisi++;
				else if (line.substr(0, 6) == "kurye:") // satırın başındaki kurye kelimesini kontrol eder
					kurye_sayisi++;
			}
			dosya.close();
			kullanicilar = new kullanici[kullanici_sayisi]; // kullanıcıların tutulacağı dizi oluşturulur
			yoneticiler = new yonetici[yonetici_sayisi]; // yöneticilerin tutulacağı dizi oluşturulur
			kuryeler = new kurye[kurye_sayisi]; // kuryelerin tutulacağı dizi oluşturulur
			dosya.open("kullanicilar.txt");
			int i = 0;
			int j = 0;
			int k = 0;
			while (getline(dosya, line)) // dosyadaki her satırı okur
			{
				if (line.substr(0, 9) == "kullanici")
				{
					line.erase(0, 10); // kullanıcı kelimesini siler
					string token = line.substr(0, line.find(":")); // satırı : karakterine göre bölerek token değişkenine atar
					kullanicilar[i].set_kullanici_adi(token); // kullanıcı adını kullanıcı sınıfındaki kullanıcı adı değişkenine atar
					line.erase(0, token.length() + 1); // satırı kullaıcı adından sora kalan kısmı siler
					token = line.substr(0, line.find(":")); // satırı : karakterine gçre bölerek token değişkenine atar
					kullanicilar[i].set_sifre(token); // şifreyi kullanıcı sınıfındaki şifre değişkenine atar
					line.erase(0, token.length() + 1); // satırı şifreden sonra kalan kısmı siler
					token = line.substr(0, line.find(":")); // satırı : karakterine göre bölerek token değişkenine atar
					kullanicilar[i].set_eposta(token); // eposta adresini kullanıcı sınıfındaki eposta değişkenine atar
					line.erase(0, token.length() + 1); // satırı epostadan sonra kalan kısmı siler
					kullanicilar[i].set_adres(token); // adresi kullanıcı sınıfındaki adres değişkenine atar
					line.erase(0, token.length() + 1); // satırı adresden sonra kalan kısmı siler
					token = line.substr(0, line.find(":")); // satırı : karakterine göre bölerek token değişkenine atar
					kullanicilar[i].set_dogum_tarihi(token); // doğum tarihini kullanıcı sınıfındaki doğum tarihi değişkenine atar
					line.erase(0, token.length() + 1); // satırı doğum tarihinden sonra kalan kısmı siler
					token = line.substr(0, line.find(":")); // satırı : karakterine göre bölerek token değişkenine atar
					kullanicilar[i].set_indirim_kodu(token); // indirimkodunu kullanıcı sınıfındaki indirim kodu değişkenine atar
					line.erase(0, token.length() + 1); // satırı indirim kodundan sonra kalan kısmı siler
					token = line.substr(0, line.find(":")); // satırı : karakterine göre bölerek token değişkenine atar
					kullanicilar[i].set_ad_soyad(token); // ad soyadı kullanıcı sınıfındaki ad soyad değişkenine atar
					line.erase(0, token.length() + 1); // satırı ad soyaddan sonra kalan kısmı siler
					token = line.substr(0, line.find(":")); // satırı : karakterine göre bölerek token değişkenine atar
					kullanicilar[i].set_telno(token); // telefon numarasını kullanıcı sınıfındaki telefon numarası değişkenine atar
					line.erase(0, token.length() + 1); // satırı telefon numarasından sonra kalan kısmı siler
					i++; // kullanıcı sayısını arttırır
				}
				else if (line.substr(0, 8) == "yonetici")
				{
					line.erase(0, 9); // yonetici kelimesini siler
					string token = line.substr(0, line.find(":")); // satırı : karakterine göre bölerek token değişkenine atar
					yoneticiler[j].set_sifre(token); // şifreyi yönetii sınıfındaki şifre değişkenine atar
					line.erase(0, token.length() + 1); // satırı şifreden sonra kalan kısmı siler
					token = line.substr(0, line.find(":")); // satırı : karakterine göre bölerek token değişkenine atar
					yoneticiler[j].set_ad_soyad(token); // ad soyadı yönetici sınıfındaki ad soyad değişkenine atar
					line.erase(0, token.length() + 1); // satırı ad soyaddan sonra kalan kısmı siler
					token = line.substr(0, line.find(":")); // satırı : karakterine göre bölerek token değişkenine atar
					yoneticiler[j].set_telno(token); // telefon numarasını yönetici sınıfındaki telefon numarası değişkenine atar
					line.erase(0, token.length() + 1); // satırı telefon numarasından sonra kalan kısmı siler
					j++; // yönetici sayısını arttırır
				}
				else if (line.substr(0, 6) == "kurye:")
				{
					line.erase(0, 7); // kurye: kelimesini siler
					string token = line.substr(0, line.find(":")); // satırı : karakterine göre bölerek token değişkenine atar
					kuryeler[k].set_ad_soyad(token); // ad soyadı kurye sınıfındaki ad soyad değişkenine atar
					line.erase(0, token.length() + 1); // satırı ad ssoyaddan sonra kalan kısmı siler
					token = line.substr(0, line.find(":")); // satırı: karakterine göre bölerek token değişkenine atar
					kuryeler[k].set_telno(token); // telefon numarasını kurye sınıfındaki telefon numarası değişkenine atar
					line.erase(0, token.length() + 1); // satırı telefon numarasından sonra kalan kısmı siler
					k++; // kurye sayısını arttırır
				}
			}
			dosya.close();
		}
		void kiyafetleriOku()
		{
			fstream dosya;
			dosya.open("kiyafetler.txt");
			string line;
			while (getline(dosya, line)) // dosyadaki satırları okur ve kıyafet sayısını bulur
			{
				kiyafet_sayisi++;
			}
			dosya.close();
			kiyafetler = new kiyafet[kiyafet_sayisi]; // kiyafet sınıfından kiyafetler dizisi oluşturur
			dosya.open("kiyafetler.txt");
			int i = 0;
			while (getline(dosya, line))
			{
				string token = line.substr(0, line.find(":")); // satırı : karakterine göre bölerek token değişkenine atar
				kiyafetler[i].set_kiyafet_adi(token); // kıyafet adını kıyafet sınıfındaki kıyafet adı değişkenine atar
				line.erase(0, token.length() + 1); // satırı kıyafet adından sonra kalan kısmı siler
				token = line.substr(0, line.find(":")); // satırı : karakterine göre bölerek token değişkenine atar
				kiyafetler[i].set_fiyat(stod(token)); // fiyatı kıyafet sınıfındaki fiyat değişkenine atar
				line.erase(0, token.length() + 1); // satırı fiyattan sonra kalan kısmı siler
				token = line.substr(0, line.find(":")); // satırı : karakterine göre bölerek token değişkenine atar
				kiyafetler[i].set_kategori(token); // kategoriyi kıyafet sınıfındaki kategori değişkenine atar
				line.erase(0, token.length() + 1); // satırı kategoriden sonra kalan kısmı siler
				token = line.substr(0, line.find(":")); // satırı : karakterine göre bölerek token değişkenine atar
				kiyafetler[i].set_boyut(token); // boyutu kıyafet sınıfındaki boyut değişkenine atar
				line.erase(0, token.length() + 1); // satırı boyuttan sonra kalan kısmı siler
				token = line.substr(0, line.find(":")); // satırı : karakterine göre bölerek token değişkenine atar
				kiyafetler[i].set_renk(token); // rengi kıyafet sınıfındaki renk değişkenine atar
				line.erase(0, token.length() + 1); // satırı renginden sonra kalan kısmı siler
				i++; // kıyafet sayısını arttırır
			}
			dosya.close();
		}
		void sikayetleriOku()
		{
			fstream dosya;
			dosya.open("sikayetoneri.txt");
			string line;
			while (getline(dosya, line))
			{
				sikayet_sayisi++;
			}
			dosya.close();
			sikayetler = new sikayet[sikayet_sayisi]; // sikayet sınıfından sikayetler dizisi oluşturur
			dosya.open("sikayetoneri.txt");
			int i = 0;
			while (getline(dosya, line))
			{
				string token = line.substr(0, line.find(":")); // satırı : karakterine göre bölerek token değişkenine atar
				sikayetler[i].set_yazan(token); // yazanı sikayet sınıfındaki yazan değişkenine atar
				line.erase(0, token.length() + 1); // satırı yazandan sonra kalan kısmı siler
				token = line.substr(0, line.find(":")); // satırı : karakterine göre bölerek token değişkenine atar
				sikayetler[i].set_sikayet_icerigi(token); // sikayet icerigini sikayet sınıfındaki sikayet icerigi değişkenine atar
				line.erase(0, token.length() + 1); // satırı sikayet iceriginden sonra kalan kısmı siler
				i++;
			}
			dosya.close();
		}
		void siparisleriOku()
		{
			fstream dosya;
			dosya.open("siparisler.txt");
			string line;
			while (getline(dosya, line))
			{
				siparis_sayisi++;
			}
			dosya.close();
			siparisler = new siparis[siparis_sayisi]; // siparis sınıfından siparisler dizisi oluşturur
			dosya.open("siparisler.txt");
			int i = 0;
			while (getline(dosya, line))
			{
				string token = line.substr(0, line.find(":")); // satırı ':' karakterine göre bölerek token değişkenine atar
				siparisler[i].set_kullanici(token); // kullanıcıyı siparis sınıfındaki kullanıcı değişkenine atar
				line.erase(0, token.length() + 1); // satırı kullanıcıdan sonra kalan kısmı siler
				token = line.substr(0, line.find(":"));
				siparisler[i].set_fiyat(stod(token)); // fiyatı siparis sınıfındaki fiyat değişkenine atar
				line.erase(0, token.length() + 1); // satırı fiyattan sonra kalan kısmı siler
				token = line.substr(0, line.find(":"));
				zaman *z1 = new zaman(token); // zaman sınıfından z1 nesnesi oluşturur
				siparisler[i].set_siparis_tarihi(z1); // siparis tarihini siparis sınıfındaki siparis tarihi değişkenine atar
				line.erase(0, token.length() + 1);
				token = line.substr(0, line.find(":"));
				zaman *z2 = new zaman(token); // zaman sınıfından z2 nesnesi oluşturur
				siparisler[i].set_teslimat_tarihi(z2); // teslimat tarihini siparis sınıfındaki teslimat tarihi değişkenine atar
				line.erase(0, token.length() + 1);
				token = line.substr(0, line.find(":"));
				siparisler[i].set_adres(token); // adresi siparis sınıfındaki adres değişkenine atar
				line.erase(0, token.length() + 1); // satırı adresden sonra kalan kısmı siler
				token = line.substr(0, line.find(":"));
				siparisler[i].set_kiyafet_adi(token); // kiyafet adını siparis sınıfındaki kiyafet adı değişkenine atar
				line.erase(0, token.length() + 1);
				token = line.substr(0, line.find(":"));
				siparisler[i].set_kurye_no(token); // kurye noyu siparis sınıfındaki kurye no değişkenine atar
				line.erase(0, token.length() + 1);
				token = line.substr(0, line.find(":"));
				siparisler[i].set_durum(token); // durumu siparis sınıfındaki durum değişkenine atar
				line.erase(0, token.length() + 1);
				i++;
			}
			dosya.close();
		}
		void oku() // tüm dosyaları okuyan fonksiyon
		{
			kullanicilariOku();
			kiyafetleriOku();
			sikayetleriOku();
			siparisleriOku();

		}
		int get_kullanici_sayisi(void)
		{
			return kullanici_sayisi;
		}
		int get_yonetici_sayisi(void)
		{
			return yonetici_sayisi;
		}
		kullanici *get_kullanicilar(void)
		{
			return kullanicilar;
		}
		yonetici *get_yoneticiler(void)
		{
			return yoneticiler;
		}
		kurye *get_kuryeler(void)
		{
			return kuryeler;
		}
		kiyafet *get_kiyafetler(void)
		{
			return kiyafetler;
		}
		siparis *get_siparisler(void)
		{
			return siparisler;
		}
		int get_siparis_sayisi(void)
		{
			return siparis_sayisi;
		}
		int get_kiyafet_sayisi(void)
		{
			return kiyafet_sayisi;
		}
		int get_kurye_sayisi(void)
		{
			return kurye_sayisi;
		}
		sikayet *get_sikayetler(void)
		{
			return sikayetler;
		}
		int get_sikayet_sayisi(void)
		{
			return sikayet_sayisi;
		}
		void indirim_kodu_tanimla(string kullanciAdi, string indirimKodu)
		{
			for (int i = 0; i < kullanici_sayisi; i++) // kullanıcıları dolaşır
			{
				if (kullanicilar[i].get_kullanici_adi() == kullanciAdi) // kullanıcı adı eşleşirse
				{
					kullanicilar[i].set_indirim_kodu(indirimKodu); // indirim kodunu kullanıcıya atar
					break;
				}
			}
			fstream dosya;
			dosya.open("kullanicilar.txt", ios::out | ios::trunc);
			string line;
			for (int i = 0; i < kullanici_sayisi; i++) // kullanıcıları dolaşır
			{
				dosya << "kullanici:" <<
				kullanicilar[i].get_kullanici_adi() << ":" <<
				kullanicilar[i].get_sifre() << ":" <<
				kullanicilar[i].get_eposta() << ":" <<
				kullanicilar[i].get_adres() << ":" <<
				kullanicilar[i].get_dogum_tarihi() << ":" <<
				kullanicilar[i].get_indirim_kodu() <<  ":" <<
				kullanicilar[i].get_ad_soyad() << ":" <<
				kullanicilar[i].get_telno() <<
				endl;
			}
			for (int i = 0; i < yonetici_sayisi; i++)
			{
				dosya << "yonetici:" << yoneticiler[i].get_sifre() << ":" << yoneticiler[i].get_ad_soyad() << ":" << yoneticiler[i].get_telno() << endl;
			}
			for (int i = 0; i < kurye_sayisi; i++)
			{
				dosya << "kurye:" << kuryeler[i].get_ad_soyad() << ":" << kuryeler[i].get_telno() << endl;
			}
			dosya.close();
		}
		void yonetici_ekle(string ad_soyad, string telno, string sifre)
		{
			ofstream dosya; // dosya işlemleri için ofstream nesnesi oluşturulur. ofstream dosyaya yazı yazmamızı sağlar.
			dosya.open("kullanicilar.txt", ios::app);
			dosya << "yonetici:" << sifre << ":" << ad_soyad << ":" << telno << endl; // dosyaya yonetici:şifre:ad_soyad:telno şeklinde yazar
			dosya.close();
		}
		void kullanici_ekle(string kullanici_adi, string email, string sifre, string adres, string dogum_tarihi, string ad_soyad, string telno)
		{
			ofstream dosya;
			dosya.open("kullanicilar.txt", ios::app);
			dosya << "kullanici:" << kullanici_adi << ":" << email << ":" << sifre << ":" << adres << ":" << dogum_tarihi << ":" << "0" << ":" << ad_soyad << ":" << telno << endl;
			dosya.close();
		}
		void kiyafet_ekle(string kiyafet_adi, double fiyat, string kategori, string renk, string boyut)
		{
			ofstream dosya;
			dosya.open("kiyafetler.txt", ios::app);
			dosya << kiyafet_adi << ":" << fiyat << ":" << kategori << ":" << renk << ":" << boyut << endl;
			dosya.close();
		}
		void kurye_ekle(string ad_soyad, string telno)
		{
			ofstream dosya;
			dosya.open("kullanicilar.txt", ios::app);
			dosya << "kurye:" << ad_soyad << ":" << telno << endl;
			dosya.close();
		}
		void siparisVer(string urunNo, kullanici *k, zaman z)
		{
			fstream dosya;
			char *line = new char[10];
			char *line2 = new char[10];
			zaman z2("02.00");
			sprintf(line,"%02d.%02d", z.get_saat(), z.get_dakika()); // saat dakika formatına çevirir
			sprintf(line2,"%02d.%02d", (z + z2).get_saat(), (z + z2).get_dakika()); // saat dakika formatına çevirir
			dosya.open("siparisler.txt", ios::app);
			dosya << k->get_kullanici_adi() << ":"
			<< kiyafetler[stoi(urunNo) - 1].get_fiyat() << ":"
			<< line  << ":"
			<< line2 << ":"
			<< k->get_adres() << ":"
			<< kiyafetler[stoi(urunNo) - 1].get_kiyafet_adi() << ":"
			<< "0" << ":"
			<< "Yolda"
			<< endl; // dosyaya sipariş bilgilerini yazar
			delete[] line; // bellekten line'i siler
			dosya.close();
		}
		//point
		void sikayetEkle(string sikayet, kullanici *k)
		{
			fstream dosya;
			dosya.open("sikayetoneri.txt", ios::app);
			dosya << k->get_kullanici_adi() << ":" << sikayet << endl;
			dosya.close();
		}
		void sifreDegistir(string sifre, kullanici *k)
		{
			fstream dosya;
			dosya.open("kullanicilar.txt", ios::out | ios::trunc);
			string line;
			for (int i = 0; i < kullanici_sayisi; i++)
			{
				if (kullanicilar[i].get_kullanici_adi() == k->get_kullanici_adi())
				{
					kullanicilar[i].set_sifre(sifre);
				}
				dosya << "kullanici:" <<
				kullanicilar[i].get_kullanici_adi() << ":" <<
				kullanicilar[i].get_sifre() << ":" <<
				kullanicilar[i].get_eposta() << ":" <<
				kullanicilar[i].get_adres() << ":" <<
				kullanicilar[i].get_dogum_tarihi() << ":" <<
				kullanicilar[i].get_indirim_kodu() <<  ":" <<
				kullanicilar[i].get_ad_soyad() << ":" <<
				kullanicilar[i].get_telno() <<
				endl;
			}
			for (int i = 0; i < yonetici_sayisi; i++)
			{
				dosya << "yonetici:" << yoneticiler[i].get_sifre() << ":" << yoneticiler[i].get_ad_soyad() << ":" << yoneticiler[i].get_telno() << endl;
			}
			for (int i = 0; i < kurye_sayisi; i++)
			{
				dosya << "kurye:" << kuryeler[i].get_ad_soyad() << ":" << kuryeler[i].get_telno() << endl;
			}
			dosya.close();
		}
};

class Kontrol
{
	public:
		bool emailKontrol(string email, Veri *veri)
		{
			if (email.find("@") == string::npos || email.find(".") == string::npos) // @ veya . yoksa
			{
				cout << "Email adresi gecersizdir." << endl;
				return false;
			}
			for (int i = 0; i < veri->get_kullanici_sayisi(); i++)
			{
				if (veri->get_kullanicilar()[i].get_eposta() == email) // email adresi daha önce kullanılmışsa
				{
					cout << "Bu email adresi daha once kullanilmistir." << endl;
					return false;
				}
			}
			return true;
		}
		bool sifreKontrol(string sifre)
		{
			bool buyuk_harf = false;
			bool kucuk_harf = false;
			bool rakam = false;
			bool ozel_karakter = false;
			string normalHarfler = "abcdefghijklmnopqrstuvwxyz" "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 "; // sifrede kullanılacak harfler
			for (int i = 0; i < sifre.length(); i++)
			{
				if (sifre[i] >= 'A' && sifre[i] <= 'Z')
					buyuk_harf = true;
				if (sifre[i] >= 'a' && sifre[i] <= 'z')
					kucuk_harf = true;
				if (sifre[i] >= '0' && sifre[i] <= '9')
					rakam = true;
				size_t special = sifre.find_first_not_of(normalHarfler);
      			if (special != string::npos) // sifrede özel karakter varsa
         			ozel_karakter = true;
			}
			if (kucuk_harf && buyuk_harf && rakam && ozel_karakter && sifre.length() >= 8)
				return true;
			else
				return false;
		}
		bool kullaniciAdiKontrol(string kullanici_adi, Veri *veri)
		{
			for (int i = 0; i < veri->get_kullanici_sayisi(); i++)
			{
				if (veri->get_kullanicilar()[i].get_kullanici_adi() == kullanici_adi) // kullanıcı adı daha önce kullanılmışsa
				{
					cout << "Bu kullanici adi daha once kullanilmistir." << endl;
					return false;
				}
			}
			return true;
		}
		bool dogumTarihiKontrol(string dogum_tarihi)
		{
			if (dogum_tarihi.find("/") == string::npos) // / yoksa
			{
				cout << " Dogum tarihi gecersizdir." << endl;
				return false;
			}
			return true;
		}
		bool yoneticiSifreKontrol(string sifre, Veri *veri, kisi **giris)
		{
			for (int i = 0; i < veri->get_yonetici_sayisi(); i++)
			{
				if (veri->get_yoneticiler()[i].get_sifre() == sifre) // yonetici sifresi dogruysa
				{
					*giris = &veri->get_yoneticiler()[i];
					return true;
				}
			}
			cout << "Yonetici sifresi gecersizdir." << endl;
			return false;
		}
		bool kullaniciKontrol(string kullanici_adi, string sifre, Veri *veri, kisi **giris)
		{
			for (int i = 0; i < veri->get_kullanici_sayisi(); i++)
			{
				if (veri->get_kullanicilar()[i].get_kullanici_adi() == kullanici_adi && veri->get_kullanicilar()[i].get_sifre() == sifre)
				{
					*giris = &veri->get_kullanicilar()[i];
					return true;
				}

			}
			cout << "Kullanici adi veya sifre gecersizdir." << endl;
			return false;
		}
		bool kategoriKontrol(string kategori)
		{
			if (kategori != "Elbise"
			&& kategori != "Tisort"
			&& kategori != "Pantolon"
			&& kategori != "Gomlek"
			&& kategori != "Etek"
			&& kategori != "Ayakkabi")
			{
				cout << "Lutfen gecerli bir kategori giriniz." << endl;
				cout << "Elbise" << endl;
				cout << "Tisort" << endl;
				cout << "Pantolon" << endl;
				cout << "Gomlek" << endl;
				cout << "Etek" << endl;
				cout << "Ayakkabi" << endl;
				return false;
			}
			return true;
		}
};

class Menu
{
	private:
		int menu;
		kisi *giris;
		Veri *veri;
		Kontrol kontrol;
		zaman z;
		void anaMenu()
		{
			string line;
			cout << "\t\tKiyafet Sepeti" << endl;
			cout << "1. Sisteme giris" << endl;
			cout << "2. Uye kaydi" << endl;
			cout << "3. Cikis" << endl;
			getline(cin, line);
			menu = stoi(line);

		}
		void sistemeGirisMenu()
		{
			string line;
			cout << "\t\tSisteme giris" << endl;
			cout << "1. Yonetici girisi" << endl;
			cout << "2. Musteri girisi" << endl;
			cout << "3. Geri don" << endl;
			getline(cin, line); // getline ile string olarak alıyoruz
			menu = 10 + stoi(line); // stringi int e çeviriyoruz
		}
		void uyeKaydiMenu()
		{
			string line;
			cout << "\t\tUye kaydi" << endl;
			cout << "Uyelik tipi seciniz: " << endl;
			cout << "1. Yonetici" << endl;
			cout << "2. Kullanici" << endl;
			cout << "3. Geri don" << endl;
			getline(cin, line);
			menu = 20 + stoi(line);
		}
		void cikisMenu()
		{
			cout << "Cikis Yapiliyor..." << endl;
			exit(0);
		}
		void yoneticiKayitMenu()
		{
			string ad_soyad;
			string telno;
			string yoneticiSifresi;
			string line;
			cout << "\t\tYonetici kaydi" << endl;
			cout << "Ad ve soyad giriniz: ";
			getline(cin, ad_soyad);
			cout << "Telefon numarasi giriniz: ";
			getline(cin, telno);
			cout << "Yonetici sifresi giriniz: ";
			getline(cin, yoneticiSifresi);
			while (!(kontrol.sifreKontrol(yoneticiSifresi))) // sifre kontrol fonksiyonu false dönerse
			{
				yoneticiSifresi = "";
				cout << "Sifre en az 8 karakterden olusmalidir." << endl;
            	cout << "Sifre en az 1 kucuk harf, 1 buyuk harf, 1 sayi ve 1 ozel karakterden olusmalidir." << endl;
            	cout << "Sifre: ";
            	cin >> yoneticiSifresi;
			}
			veri->yonetici_ekle(ad_soyad, telno, yoneticiSifresi);
			delete veri;
			veri = new Veri();
			veri->oku();
			menu = ANAMENU;
		}
		void kullaniciKayitMenu()
		{
			string ad_soyad;
			string telno;
			string email;
			string sifre;
			string adres;
			string kullaniciAdi;
			string dogumTarihi;
			string line;
			cout << "\t\tKullanici kaydi" << endl;
			cout << "Ad ve soyad giriniz: ";
			getline(cin, ad_soyad);
			cout << "Telefon numarasi giriniz: ";
			getline(cin, telno);
			cout << "Email giriniz: ";
			getline(cin, email);
			while (kontrol.emailKontrol(email, veri) == false)
			{
				cout << "Email giriniz: ";
				getline(cin, email);
			}
			cout << "Sifre giriniz: ";
			getline(cin, sifre);
			cout << "Adres giriniz: ";
			getline(cin, adres);
			cout << "Kullanici adi giriniz: ";
			getline(cin, kullaniciAdi);
			while (kontrol.kullaniciAdiKontrol(kullaniciAdi, veri) == false)
			{
				cout << "Kullanici adi giriniz: ";
				getline(cin, kullaniciAdi);
			}
			cout << "Dogum tarihi giriniz: ";
			getline(cin, dogumTarihi);
			while (kontrol.dogumTarihiKontrol(dogumTarihi) == false)
			{
				cout << "Dogum tarihi giriniz: ";
				getline(cin, dogumTarihi);
			}
			veri->kullanici_ekle(kullaniciAdi, sifre, email, adres, dogumTarihi, ad_soyad, telno);
			delete veri;
			veri = new Veri();
			veri->oku();
			menu = ANAMENU;
		}
		void yoneticiGirisiMenu()
		{
			int deneme = 0;
			cout << "\t\tYonetici girisi" << endl;
			cout << "Yonetici sifresi giriniz: " << endl;
			string sifre;
			getline(cin, sifre);
			while (kontrol.yoneticiSifreKontrol(sifre, veri, &giris) == false)
			{
				cout << "Yonetici sifresi giriniz: " << endl;
				getline(cin, sifre);
				deneme++;
				if (deneme == 2)
				{
					cout << "3 kere yanlis sifre girdiniz. Ana menuye donuluyor..." << endl;
					menu = ANAMENU;
					sleep(2);
					return ;
				}
			}
			menu = YONETICIMENU;
		}
		void musteriGirisiMenu()
		{
			int deneme = 0;
			cout << "\t\tMusteri girisi" << endl;
			cout << "Kullanici adi giriniz: " << endl;
			string kullaniciAdi;
			getline(cin, kullaniciAdi);
			cout << "Sifre giriniz: " << endl;
			string sifre;
			getline(cin, sifre);
			while (kontrol.kullaniciKontrol(kullaniciAdi, sifre, veri, &giris) == false)
			{
				cout << "Kullanici adi giriniz: " << endl;
				getline(cin, kullaniciAdi);
				cout << "Sifre giriniz: " << endl;
				getline(cin, sifre);
				deneme++;
				if (deneme == 2)
				{
					cout << "3 kere yanlis sifre girdiniz. Ana menuye donuluyor..." << endl;
					menu = ANAMENU;
					sleep(2);
					return ;
				}
			}
			menu = MUSTERIMENU;
		}
		void yoneticiMenu()
		{
			cout << "\t\tYonetici Menu" << endl;
			cout << "--------------------------" << endl;
			cout << giris->get_ad_soyad() << " olarak giris yaptiniz." << endl;
			cout << "--------------------------" << endl;
			cout << "1. Urun girisi yap" << endl;
			cout << "2. Sisteme kurye ekle" << endl;
			cout << "3. Sikayet ve onerileri oku" << endl;
			cout << "4. Kullaniciya indirim kodu tanimla" << endl;
			cout << "5. Siparis Faturalarini goruntule" << endl;
			cout << "6. Cikis" << endl;
			string secim;
			getline(cin, secim);
			menu = YONETICIMENU + stoi(secim);
		}
		void musteriMenu()
		{
			cout << "\t\tMusteri Menu" << endl;
			cout << "--------------------------" << endl;
			cout << giris->get_ad_soyad() << " olarak giris yaptiniz." << endl;
			cout << "--------------------------" << endl;
			cout << "1. Urunleri goruntule" << endl;
			cout << "2. Siparis takip" << endl;
			cout << "3. Sikayet ve oneriler" << endl;
			cout << "4. Sifre degistir" << endl;
			cout << "5. Cikis" << endl;
			string secim;
			getline(cin, secim);
			menu = MUSTERIMENU + stoi(secim);
		}
		void urunGirisiMenu()
		{
			cout << "\t\tUrun girisi yap" << endl;
			cout << "--------------------------" << endl;
			cout << "Urun adi giriniz: " << endl;
			string ad;
			getline(cin, ad);
			cout << "\nUrun fiyati giriniz: " << endl;
			string fiyat;
			getline(cin, fiyat);
			cout << endl << "Elbise" << endl;
			cout << "Tisort" << endl;
			cout << "Pantolon" << endl;
			cout << "Gomlek" << endl;
			cout << "Etek" << endl;
			cout << "Ayakkabi" << endl;
			cout << "\nYukaridaki kategorilerden bir tanesini giriniz" << endl;
			string kategori;
			getline(cin, kategori);
			while (kontrol.kategoriKontrol(kategori) == false)
			{
				cout << kategori << " kategorisi bulunmamaktadir." << endl;
				cout << "Urun kategorisi giriniz: " << endl;
				getline(cin, kategori);
			}
			cout << "\nUrun boyutu giriniz: " << endl;
			string boyut;
			getline(cin, boyut);
			cout << "\nUrun rengi giriniz: " << endl;
			string renk;
			getline(cin, renk);
			veri->kiyafet_ekle(ad, stod(fiyat), kategori, boyut, renk);
			delete veri;
			veri = new Veri();
			veri->oku();
			menu = YONETICIMENU;
		}
		void kuryeEkle()
		{
			string ad_soyad, telno;
			cout << "Kurye adi ve soyadi giriniz: " << endl;
			getline(cin, ad_soyad);
			cout << "Kurye telefon numarasi giriniz: " << endl;
			getline(cin, telno);
			veri->kurye_ekle(ad_soyad, telno);
			delete veri;
			veri = new Veri();
			veri->oku();
			menu = YONETICIMENU;
		}
		void sikayetleriOku()
		{
			for (int i = 0; i < veri->get_sikayet_sayisi(); i++)
			{
				cout << veri->get_sikayetler()[i].get_yazan() << " " << veri->get_sikayetler()[i].get_sikayet_icerigi() << endl;
			}
			cout << "--------------------------" << endl;
			cout << "Geri donmek icin bir tusa basiniz." << endl;
			string secim;
			getline(cin, secim);
			menu = YONETICIMENU;														// buralar menüler, menülerde gezerken burda recursive yapıyorsunuz sürekli. Recursive = özyinelemeli
		}
		void indirimKoduTanimla()
		{
			string kullaniciAdi, indirimKodu;
			cout << "Kullanici adi giriniz: " << endl;
			getline(cin, kullaniciAdi);
			cout << "Indirim kodu giriniz: " << endl;
			getline(cin, indirimKodu);
			veri->indirim_kodu_tanimla(kullaniciAdi, indirimKodu);
			menu = YONETICIMENU;
		}
		void siparisleriGoruntule()
		{
			cout << "\t\tSiparisler" << endl;
			for (int i = 0; i < veri->get_siparis_sayisi(); i++)
			{
				cout << "--------------------------" << endl;
				cout << "Siparis No: " << veri->get_siparisler()[i].get_siparis_no()
				<< endl << "Siparis Tarihi: " << veri->get_siparisler()[i].get_siparis_tarihi()->get_saat()
				<< "." << veri->get_siparisler()[i].get_siparis_tarihi()->get_dakika()
				<< endl << "Teslim Tarihi: " << veri->get_siparisler()[i].get_teslimat_tarihi()->get_saat()
				<< "." << veri->get_siparisler()[i].get_teslimat_tarihi()->get_dakika()
				<< endl << "Kullanici: " << veri->get_siparisler()[i].get_kullanici()
				<< endl << "Adres: " << veri->get_siparisler()[i].get_adres()
				<< endl << "Fiyat: " << veri->get_siparisler()[i].get_fiyat()
				<< endl << "Kiyafet Adi: " << veri->get_siparisler()[i].get_kiyafet_adi()
				<< endl << "Kurye No: " << veri->get_siparisler()[i].get_kurye_no()
				<< endl << "Durum: " << veri->get_siparisler()[i].get_durum() << endl;
				cout << "--------------------------" << endl;
			}
			cout << "Geri donmek icin 1'e basiniz." << endl;
			string secim;
			getline(cin, secim);
			if (secim == "1")
				menu = YONETICIMENU;
		}
		void cikis()
		{
			menu = ANAMENU;
			giris = NULL;
		}
		void urunSec()
		{
			for (int i = 0; i < veri->get_kiyafet_sayisi(); i++)
			{
				cout << "--------------------------" << endl;
				cout << i + 1 << ". Kiyafet Adi: " << veri->get_kiyafetler()[i].get_kiyafet_adi() << endl;
				cout << "Fiyat: " << veri->get_kiyafetler()[i].get_fiyat() << endl;
				cout << "Kategori: " << veri->get_kiyafetler()[i].get_kategori() << endl;
				cout << "Renk: " << veri->get_kiyafetler()[i].get_renk() << endl;
				cout << "Boyut: " << veri->get_kiyafetler()[i].get_boyut() << endl;
				cout << "--------------------------" << endl;
			}
			cout << "Siparis etmek istediginiz urunun numarasini giriniz." << endl;
			cout << "Geri donmek icin 0'a basiniz." << endl;
			string secim;
			getline(cin, secim);
			if (secim == "0")
			{
				menu = MUSTERIMENU;
				return ;
			}
			veri->siparisVer(secim, (kullanici *)giris, this->z);
			delete veri;
			veri = new Veri();
			veri->oku();
			menu = MUSTERIMENU;
		}
		void siparisTakip()
		{
			for (int i = 0; i < veri->get_siparis_sayisi(); i++)
			{
				kullanici *k = (kullanici *)giris;
				if (veri->get_siparisler()[i].get_kullanici() == k->get_kullanici_adi())
				{
					cout << "--------------------------" << endl;
					cout << "Siparis No: " << veri->get_siparisler()[i].get_siparis_no()
					<< endl;
					printf("Siparis Tarihi: %02d:%02d\n",
					veri->get_siparisler()[i].get_siparis_tarihi()->get_saat(),
					veri->get_siparisler()[i].get_siparis_tarihi()->get_dakika());
					printf("Teslim Tarihi: %02d:%02d\n",
					veri->get_siparisler()[i].get_teslimat_tarihi()->get_saat(),
					veri->get_siparisler()[i].get_teslimat_tarihi()->get_dakika());
					cout << "Kullanici: " << veri->get_siparisler()[i].get_kullanici()
					<< endl << "Adres: " << veri->get_siparisler()[i].get_adres()
					<< endl << "Fiyat: " << veri->get_siparisler()[i].get_fiyat()
					<< endl << "Kiyafet Adi: " << veri->get_siparisler()[i].get_kiyafet_adi()
					<< endl << "Kurye No: " << veri->get_siparisler()[i].get_kurye_no()
					<< endl << "Durum: " << veri->get_siparisler()[i].get_durum() << endl;
					cout << "--------------------------" << endl;
				}
			}
			cout << "Geri donmek icin 1'e basiniz." << endl;
			string secim;
			getline(cin, secim);
			if (secim == "1")
				menu = MUSTERIMENU;
		}
		void sikayetEkle()
		{
			cout << "Sikayetinizi giriniz." << endl;
			string sikayet;
			getline(cin, sikayet);
			veri->sikayetEkle(sikayet, (kullanici *)giris);
			delete veri;
			veri = new Veri();
			veri->oku();
			menu = MUSTERIMENU;
		}
		void sifreDegistir()
		{
			string sifre;
			cout << "Degistirmek istediginiz sifreyi giriniz." << endl;
			getline(cin, sifre);
			veri->sifreDegistir(sifre, (kullanici *)giris);
			delete veri;
			veri = new Veri();
			veri->oku();
			menu = MUSTERIMENU;
		}
	public:
		Menu()
		{
			menu = ANAMENU;
		}
		Menu (Veri *veri)
		{
			this->veri = veri;
			menu = ANAMENU;
			this->giris = NULL;
		}
		~Menu()
		{

		}
		void getMenu()
		{
			#ifdef _WIN32
				system("cls"); //windows 32 bit için
			#elif __linux__
				system("clear"); //linux için
			#elif _WIN64
				system("cls"); //windows 64 bit için
			#endif
			time_t t = time(NULL);
			string zaman1 = ctime(&t);
			zaman1 = zaman1.substr(zaman1.find(":") - 2, 5);
			cout << zaman1 << endl;
			this->z = zaman(zaman1);
			switch (menu)
			{
				case ANAMENU:
					anaMenu();
					break;
				case SISTEMEGIRISMENU:
					sistemeGirisMenu();
					break;
				case UYEKAYDIMENU:
					uyeKaydiMenu();
					break;
				case CIKISMENU:
					cikisMenu();
					break;
				case YONETICIGIRISIMENU:
					yoneticiGirisiMenu();
					break;
				case MUSTERIGIRISIMENU:
					musteriGirisiMenu();
					break;
				case GIRISGERIDONMENU:
					menu = ANAMENU;
					anaMenu();
					break;
				case YONETICIKAYITMENU:
					yoneticiKayitMenu();
					break;
				case KULLANICIKAYITMENU:
					kullaniciKayitMenu();
					break;
				case KAYITGERIDONMENU:
					menu = ANAMENU;
					anaMenu();
					break;
				case YONETICIMENU:
					yoneticiMenu();
					break;
				case MUSTERIMENU:
					musteriMenu();
					break;
				case YONETICIMENUURUNGIRIS:
					urunGirisiMenu();
					break;
				case YONETICIMENUKURYEEKLE:
					kuryeEkle();
					break;
				case YONETICIMENUSIKAYETONERI:
					sikayetleriOku();
					break;
				case YONETICIMENUKUPONMENU:
					indirimKoduTanimla();
					break;
				case YONETICIMENUFATURAGORUNTULE:
					siparisleriGoruntule();
					break;
				case YONETICIMENUCIKIS:
					cikis();
					break;
				case MUSTERIMENUURUNARA:
					urunSec();
					break;
				case MUSTERIMENUSIPARISLER:
					siparisTakip();
					break;
				case MUSTERIMENUSIKAYETONERI:
					sikayetEkle();
					break;
				case MUSTERIMENUSIFREDEGISTIR:
					sifreDegistir();
					break;
				case MUSTERIMENUCIKIS:
					cikis();
					break;
			}
		}

};

int main(void)
{
	Veri *veri = new Veri(); //veri dosyasını okuyan nesne
	veri->oku(); //veri dosyasını oku fonksiyonu
	Menu menu(veri); //menü nesnesi
	while (true)
	{
		menu.getMenu();
	}
	return (0);
}
