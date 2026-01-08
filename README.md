#  Uzay Fiziği Deney Simülasyonu (AVP Projesi)

Bu proje, Güneş Sistemi'ndeki farklı gezegenlerin yerçekimi ivmelerini kullanarak çeşitli fizik deneylerini simüle eden bir C programıdır. Kullanıcı, seçtiği fiziksel deneyi 8 farklı gezegende (Merkür, Venüs, Dünya, Mars, Jüpiter, Satürn, Uranüs, Neptün) eş zamanlı olarak test edebilir.

##  Proje Özellikleri

* **Modüler Yapı:** Her fizik deneyi için ayrı fonksiyonlar kullanılmıştır.
* **Gezegen Verileri:** Proje, NASA verilerine yakın yerçekimi ivme değerlerini (g) içerir.
* **Pointer Kullanımı:** Hesaplamalarda dizi elemanlarına pointer aritmetiği ile erişilmiştir.
* **Hata Kontrolü:** Negatif değer girişleri otomatik olarak mutlak değere çevrilerek fiziksel hataların önüne geçilmiştir.

##  Simüle Edilen Deneyler

Program içerisinde aşağıdaki 9 farklı fiziksel senaryo hesaplanabilmektedir:

1. **Serbest Düşme Deneyi:** Belirli bir sürede cismin alacağı yolun hesabı.
2. **Yukarı Atış Deneyi:** Belirli bir ilk hızla atılan cismin çıkabileceği maksimum yükseklik.
3. **Ağırlık Deneyi:** Bir kütlenin farklı gezegenlerdeki ağırlık (Newton) karşılığı.
4. **Potansiyel Enerji Deneyi:** Belirli bir yükseklikteki cismin sahip olduğu kütleçekim potansiyel enerjisi.
5. **Hidrostatik Basınç Deneyi:** Sıvı içindeki derinliğe bağlı olarak oluşan basınç değeri.
6. **Arşimet Deneyi:** Sıvının cisme uyguladığı kaldırma kuvveti hesabı.
7. **Basit Sarkaç Deneyi:** Sarkacın ip uzunluğuna bağlı olarak salınım periyodu süresi.
8. **İp Gerilmesi Deneyi:** Statik durumda bir kütleyi tutan ipteki gerilme kuvveti.
9. **Asansör Deneyi:** İvmeli hareket eden bir asansör içindeki kütlenin "etkin ağırlık" değişimi.

##  Gezegen Veri Tablosu

Programda kullanılan yerçekimi ivmeleri (m/s²):

| Merkür | Venüs | Dünya | Mars | Jüpiter | Satürn | Uranüs | Neptün |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| 3.70 | 8.87 | 9.81 | 3.71 | 24.79 | 10.44 | 8.69 | 11.15 |

##  Kullanılan Teknolojiler

* **Dil:** C (C99 ve üzeri standartlar)
* **Kütüphaneler:** stdio.h, stdlib.h, math.h

##  Yazar
* **İsim:** Osman Buğra Yılmaz
* **Proje Tipi:** Algoritma ve Veri Yapıları (AVP) Dönem Projesi
