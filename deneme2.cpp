/* Tuğçe Nur ERGEN
   4 girişli menüsü olan ve seçeneğe göre fonksiyon çağırarak istenen şekli ekrana basan program
*/
#include <iostream>

using namespace std;

void duzucgen(int y);
void tersucgen(int z);
void elmas(int t);
int hata1(int x);
int hata2();


int main()
{
	int a;
	cout << "Programa hosgeldiniz. Lutfen cizmek istediginiz sekli seciniz." << endl;
	cout << " 1:DUZ UCGEN \n 2:TERS UCGEN \n 3:ELMAS \n 4:CIKIS" << endl;
	cin >> a;

	if (a == 1) {
		cout << "DUZ UCGEN CIZIMI" << endl;
		int boyut = hata1(3);
	  duzucgen(boyut);
	}

	if (a == 2) {
		cout << "TERS UCGEN CIZIMI" << endl;
		int boyut = hata2();
		tersucgen(boyut);
	}

	if (a == 3) {
		cout << "ELMAS CIZIMI" << endl;
		int boyut = hata1(5);
		elmas(boyut);
	}

	if (a == 4) {
		cout << "Program sonlandiriliyor.";
		return 0;
	}
}

int hata1(int x) {  //sadece for döbgüsü kullanarak yapılan, düz üçgen ve elmas için ayrı parametrelerle çağırılan hata fonksiyonu
	int boyut;
	for (int i = 0; i < 3; i++) { //sınırlarımıza uygun değer girmezse diye 3 tane hakkı olacak şekilde döngü oluşturuyorum.
		cout << "cizmek istediginiz seklin boyutunu giriniz (boyut " << x << " ile 15 arasinda ve tek sayi olmalidir.):" << endl;
		cin >> boyut;
		if (boyut < x || boyut > 15 || (boyut % 2) == 0) { //burada kullanıcıdan alacağımızüçgen boyutu için sınırlar koyuyoruz.
			if (i != 2) {
				cout << "istenilen degerler arasinda bir sayi girmelisiniz kalan hakkiniz: [[ " << 2 - i << " ]]" << endl; //kullanıcı istenilen değerler arasında bir sayı girmemişse uyarı veriliyor ve döngü başa dönüp kullanıcıdan tekrar  boyut istiyor.
				continue;
			}
			else {
				cout << "3 hakkiniz bitti, program sonlaniyor." << endl; //3 hakkın sonunda program sonlanıyor.
			}
		}
		else break; //eğer kullanıcı sınırlarımıza uygun değerler girmişse 3 hak dögüsüne son veriliyor ve fonksiyona devam ediliyor.
	}
	return boyut;
}

int hata2() {  //sadece while döngüsü kullanarak yapılan hata fonksiyonu
	int boyut;
	int i = 0;
	while (i < 3) { //sınırlarımıza uygun değer girmezse diye 3 tane hakkı olacak şekilde döngü oluşturuyorum.
		cout << "cizmek istediginiz ucgenin boyutunu giriniz (boyut 3 ile 15 arasında ve tek sayi olmalidir.):" << endl;
		cin >> boyut;
		if (boyut < 3 || boyut > 15 || (boyut % 2) == 0) { //burada kullanıcıdan alacağımızüçgen boyutu için sınırlar koyuyoruz.
			if (i != 2) {
				cout << "istenilen degerler arasinda bir sayi girmelisiniz kalan hakkiniz:[[ " << 2 - i <<" ]]" << endl; //kullanıcı istenilen değerler arasında bir sayı girmemişse uyarı veriliyor ve döngü başa dönüp kullanıcıdan tekrar  boyut istiyor.
				i++;
				continue;
			}
			else {
				cout << "3 hakkiniz bitti, program sonlaniyor." << endl; //3 hakkın sonunda program sonlanıyor.
			}
		}
		else break; //eğer kullanıcı sınırlarımıza uygun değerler girmişse 3 hak dögüsüne son veriliyor ve fonksiyona devam ediliyor.
		i++;
	}
 
	return boyut;
}



void duzucgen(int boyut) { //sadece for kullan


			//buraya üçgeni çizdirmeyi yazıyoruz.
	int bosluk = boyut / 2; //bosluk diye bir değişken oluşturdum. bu değişken her satırda basılacak boşluk sayısını belirleyecek. ilk satırda üçgenin boyutunun integer olarak 2ye bölümünün sonucu kadar boşluk konulacağını fark ediyoruz.
	int yildiz = 1; //ilk satırda 1 yıldız basılacağından yıldızın giriş değerini  1 olarak belirliyoruz.
		for (int i = 0; i < boyut / 2 + 1; i++) { //bu döngü üçgenimizin yüksekliğini yani satır sayısını belrliyor. girilen boyutun integer olarak yarısından 1 fazla yüksekliğe sahip olduğunu gördüğümüzden böyle bir sınır belirliyoruz.
			for (int j = 0; j < bosluk; j++) { //bu döngü her satırda basılacak boşlukları hallediyor.
				cout << " ";
			}

			for (int j = 0; j < yildiz; j++) { //bu döngü her satırda basılacak yıldızları hallediyor.
				cout << "*";
			}
			cout << endl; // satırdaki boşluk ve yıldız basma işi bittiğinde bir alt satıra geçiyoruz.
			bosluk--; //boşluk sayısını bir azaltıyoruz çünkü her satırda basılacak boşluk sayısı bir azalıyor.
			yildiz += 2; //her satırda basılacak yıldız sayısı 2 artıyor. ve döngü alt satırdan devam ediyor...
	}  
		}
		
	


void tersucgen(int boyut) { //sadece while kullan
	
	
	//buraya üçgeni çizdirmeyi yazıyoruz.
	int bosluk=0;
	int yildiz=boyut;
	int l=0, j=0, k=0;

	while (l < boyut / 2 + 1) {

		while (j < bosluk) {
			cout << " ";
			j++;
		}

		while ( k < yildiz) {
			cout << "*";
			k++;
		}
		cout << endl;
		bosluk++;
		yildiz -= 2;
		l++;
		k = 0; //döngü başa dönerken j ve k değerlerini sıfırlamamız gerek. for döngüsünde böyle bir şeye gerek yoktu çünkü sayaç içerisinde int j=0 şeklinde tanımlıyorduk ama while döngüsünde sıfırlayark döndürmezsek döngü hatalı çalışır.
		j = 0;
	
	}

	
}

void elmas(int boyut) {
	
	
	duzucgen(boyut); //bu fonksiyonda sadece diğer iki fonksiyonu sırayla çağırdık ve istenen şekil oluştu.
	tersucgen(boyut);

}
