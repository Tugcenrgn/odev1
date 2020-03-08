/* Tuğçe Nur ERGEN 
  Bu program karmaşık sayılarla işlemler yapar.
  girilen değerleri karmaşık sayıya dönüştürür ve toplama çıkartma bölme işlemlerini uygular.
*/
#include <iostream>
#include <string.h>

using namespace std;
class ComplexNumber {
private:  
	double reel, imaginary;

public:
	void print(double a, double b) {  //ekrana karmasık sayıyı yazdırma fonksiyonu
		cout << a;
		if (b < 0) {  //sanal kısım 0'dan küçükse yazdırırken araya + koymasın
			cout<< b << "i"<<endl;
		}
		if (b >= 0) {  //sanal kısım 0'dan büyükse karmaşık sayıyı yazarken + koysun
			cout << "+" << b << "i"<<endl;
		}
	}
	ComplexNumber() {  //default constructor. ilk değerlere 0 atar
		reel = 0;
		imaginary = 0;
	}

	
	void setreel(int temp_reel) {  // set fonksiyonu kullanıcıdan alınan değeri private kısımdaki reel e atar
		reel = temp_reel;
	}

	void setimaginary(int temp_imaginary) {  //set fonksiyonu kullanıcıdan alınan sanal değeri private kısımdaki imaginary değişkenine atar
		imaginary = temp_imaginary;
	}

	int getreel() {  //get fonksiyonu private olan reel değere ulaşmayı sağlar
		return reel;
	}

	int getimaginary() {  //get fonksiyonu private olan sanal sayıya ulaşmayı sağlar
		return imaginary;
	}

	ComplexNumber(int integer) {   // converter constructor. yollanan integer değeri kamaşık sayının reel kısmına dönüştürür
		reel = integer;
		imaginary = 0;
		cout << "programcı tarafindan girilen tam sayi degerin karmasik sayi karsiligi:  ";
		print(reel, imaginary);
		cout << endl;
	}

	ComplexNumber(double reelnumber) {  // converter constructor. yollanan reel sayıyı karmaşık sayının gerçel kısmına koyar
		reel = reelnumber;
		imaginary = 0;
		cout << "programcı tarafindan girilen reel sayinin karmasik sayi karsiligi:   " ;
		print(reel, imaginary);
		cout << endl;
	}

	ComplexNumber(int a, int b) {  //constructor yollanan a ve b tam sayılarıyla karmaşık sayı oluşturur
		reel = a;
		imaginary = b;
		cout << "programcı tarafindan sirayla girilen sayilarin karmasik sayi olarak gosterimi:  ";
		print(reel, imaginary);
		cout << endl;
	}

	void Add(double gercel, double sanal) { //toplama fonksiyonu.  yollanan iki karmaşık sayıyı reel ve sanal kısımları ayrı ayrı olmak üzere toplar
		double toplam_reel = reel + gercel;
		double toplam_imaginary = imaginary + sanal;
		cout << "ikinci girdiginiz karmasik sayinin ilk karmasik sayi ile toplamı:  ";
		print(toplam_reel, toplam_imaginary); //ve yazdırma fonksiyonunu çağırarak bu değerleri karmaşık sayı formatında ekrana yazar
		cout << endl;
	}

	void Subtract(double gercel, double sanal) { //çıkartma fonksiyonu. iki karmaşık sayıyı reel ve sanal kısımları ayrı ayrı olacak şekilde çıkartma işlemi yapar.
		double fark_reel = reel - gercel;
		double fark_imaginary = imaginary - sanal;
		cout << "ikinci girdiginiz karmasik sayini ilk karmasik sayidan cikarimi:  ";
		print(fark_reel, fark_imaginary); //ve print fonksiyonunu çağırarak  karmaşık sayı formatında yazdırır
		cout << endl;
	}

	void Divide(double gercel, double sanal) {  //bölme fonksiyonu. karmaşık sayıları bölmek normal bölme gibi yapılamadığından uzun  bir yolla bölme yaptım.
		double m, ni, li, k, gecicipayreel, gecicipaysanal, gecicipaydareel, gecicipaydasanal,reelsonuc,sanalsonuc;//kullanacağım değişkenleri tanımladım
		 /* Burada reel ve imaginary adlı değişkenler ilk girilen karmaşık sayıya ait veriler. gercel ve sanal adlı değişkenler ise ikinci girilen karmaşık sayıya ait veriler
		 yani reel ve imaginarynin ait olduğu karmaşık sayı bölünen, gerçel ve sanalın ait olduğu karmaşık sayı bölendir
		 karmaşık sayılarda dbölme işlemi bölen sayının eşleniğiyle pay ve paydanın çarpılması yoluyla bulunur.
		 burda sanal değerin işaretinin - ile çarpılması gercel+sanal(i) formatındaki karmaşık sayı bölenimizin eşleniğini almak olacaktır.
		 bu yüzden eşlenik adında bir fonskyion oluşturarak sanal değeri - ile çarptım. ve elde ettiğim eşlenik değer ile pay ve paydayı teker teker çarptım*/
		m = reel * gercel;   
		ni = reel * Eslenik(sanal);
		li = imaginary * gercel;
		k = -(imaginary * Eslenik(sanal));
		gecicipayreel = m + k; //buradad pay(bölünen) olan karmaşık sayının reel kısmını
		gecicipaysanal = ni + li;//burda ise pay olan karmaşık sayının sanal kısını tutuyoruz
		//paydaya gectik
		m = gercel * gercel;  
		ni = gercel * Eslenik(sanal);
		li = sanal * gercel;
		k = -(sanal * Eslenik(sanal));
		gecicipaydareel = m + k;  //burada payda(bölen) olan karmaşık sayının reel kısmını
		gecicipaydasanal = ni + li; //burda ise payda olan karmaşık sayının sanal kısmını tutuyoruz.
		//reel ve sanal kısımı ayrı ayrı bölüyoruz.
		reelsonuc = gecicipayreel / gecicipaydareel; //bölme sonucu oluşan reel kısmı burada
		sanalsonuc= gecicipaysanal / gecicipaydasanal; //bölme sonucu oluşan sanal kısmı ise burada tutuyoruz
		 
		cout << "ikinci girdiginiz karmasik sayinin ilk karmasik sayiya bolumu:  ";
		print(reelsonuc, sanalsonuc);
		cout << endl;
	}

	double Eslenik(double b) {
		return -b;
	}

};



int main()
{
	ComplexNumber number;  //karmaşıksayı sınıfımızdan number adında bir nesne oluşturuyoruz.
	double x, y, publicreel, publicsanal;
	cout << "ilk karmasik sayinizin reel kismini griniz:  "; //kullanıcıdan ilk karmaşık sayı için giriş istiyoruz
	cin >> x;
	cout << endl << "ilk karmasik sayinizin sanal kismini giriniz:  ";
	cin >> y;
	number.setreel(x); //aldığımız değerleri private olan verilerimize atamak için set fonksiyonlarını kullanıyoruz
	number.setimaginary(y);
	publicreel = number.getreel(); // get fonksiyonunu kullanarak private verilerimize ulaşıyoruz.
	publicsanal = number.getimaginary();
	cout << "girdiginiz karmasik sayi...:";  //girilen karmaşık sayıyı ekrana yazdırıyoruz
	number.print(publicreel, publicsanal);

	ComplexNumber(3);   // burada ise kullanıcıdan herhangi bir bilgi almadan kendi girdiğim verileri constructorlara yollayarak karmaşık sayı formatına dönüştürüyorum
	ComplexNumber(-4, -8);
	ComplexNumber(9.27);


	double reel2, sanal2;
	cout << "islem yapacaginiz 2. karmasik sayinin reel kisminigiriniz:  ";  // ikinci karmaşık sayı hakkındaki verileri alıyoruz.
	cin >> reel2;
	cout << endl << "islem yapacaginiz 2. karmasik sayinin sanal kismini giriniz:  ";
	cin >> sanal2;

	number.Add(reel2, sanal2);  //aldığımız verileri add fonksiyonuna yolluyoruz. ilk karmaşık sayıyla ikinciyi topluyoruz.
	number.Subtract(reel2, sanal2); //aldığımız verileri subtract fonksiyonuna yolluyoruz. ilk karmaşık sayıdan ikinciyi çıkartıyoruz.
	number.Divide(reel2, sanal2);  //aldığımız verileri divide fonksiyonuna yolluyoruz. ilk karmaşık sayıyı ikinciye bçlüyoruz.

	return 0;
}
