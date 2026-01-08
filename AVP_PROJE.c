#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* --- Fonksiyon Prototipleri --- */
void serbestDusme(double *g, double t, char *isim);
void yukariAtis(double *g, double v0, char *isim);
void agirlikDeneyi(double *g, double m, char *isim);
void potansiyelEnerji(double *g, double m, double h, char *isim);
void hidrostatikBasinc(double *g, double rho, double h, char *isim);
void arsimetKuvveti(double *g, double rho, double V, char *isim);
void basitSarkac(double *g, double L, char *isim);
void ipGerilmesi(double *g, double m, char *isim);
void asansorDeneyi(double *g, double m, double a, int tip, char *isim);

#define PI 3.14159265
#define GEZEGEN_SAYISI 8

double g_ivmeleri[GEZEGEN_SAYISI] = {
    3.7, 8.87, 9.81, 3.71,
    24.79, 10.44, 8.69, 11.15
};

const char *gezegenler[GEZEGEN_SAYISI] = {
    "Merkur", "Venus", "Dunya", "Mars",
    "Jupiter", "Saturn", "Uranus", "Neptun"
};


int main() {
    int secim;
    char isim[50];

    printf("Bilim insani adini giriniz: ");
    scanf(" %[^\n]", isim);

    do {
        printf("\n--- UZAY FIZIGI DENEY SIMULASYONU ---\n");
        printf("1. Serbest Dusme Deneyi\n");
        printf("2. Yukari Atis Deneyi\n");
        printf("3. Agirlik Deneyi\n");
        printf("4. Kutlecekimi Potansiyel Enerji Deneyi\n");
        printf("5. Hidrostatik Basinc Deneyi\n");
        printf("6. Arsimet Kaldirma Kuvveti Deneyi\n");
        printf("7. Basit Sarkac Deneyi\n");
        printf("8. Sabit Ip Gerilmesi Deneyi\n");
        printf("9. Asansor Deneyi\n");
        printf("-1. Cikis\nSecim: ");
        scanf("%d", &secim);

        double m, h, t, v0, rho, V, L, a;
        int tip;

        switch (secim) {

            case 1:
                printf("Sure (s): ");
                scanf("%lf", &t);
                t = (t < 0) ? -t : t;
                serbestDusme(g_ivmeleri, t, isim);
                break;

            case 2:
                printf("Ilk hiz (m/s): ");
                scanf("%lf", &v0);
                v0 = (v0 < 0) ? -v0 : v0;
                yukariAtis(g_ivmeleri, v0, isim);
                break;

            case 3:
                printf("Kutle (kg): ");
                scanf("%lf", &m);
                m = (m < 0) ? -m : m;
                agirlikDeneyi(g_ivmeleri, m, isim);
                break;

            case 4:
                printf("Kutle (kg): ");
                scanf("%lf", &m);
                printf("Yukseklik (m): ");
                scanf("%lf", &h);
                m = (m < 0) ? -m : m;
                h = (h < 0) ? -h : h;
                potansiyelEnerji(g_ivmeleri, m, h, isim);
                break;

            case 5:
                printf("Sivi yogunlugu (kg/m^3): ");
                scanf("%lf", &rho);
                printf("Derinlik (m): ");
                scanf("%lf", &h);
                rho = (rho < 0) ? -rho : rho;
                h   = (h   < 0) ? -h   : h;
                hidrostatikBasinc(g_ivmeleri, rho, h, isim);
                break;

            case 6:
                printf("Sivi yogunlugu (kg/m^3): ");
                scanf("%lf", &rho);
                printf("Batan hacim (m^3): ");
                scanf("%lf", &V);
                rho = (rho < 0) ? -rho : rho;
                V   = (V   < 0) ? -V   : V;
                arsimetKuvveti(g_ivmeleri, rho, V, isim);
                break;

            case 7:
                printf("Ip uzunlugu (m): ");
                scanf("%lf", &L);
                L = (L < 0) ? -L : L;
                basitSarkac(g_ivmeleri, L, isim);
                break;

            case 8:
                printf("Kutle (kg): ");
                scanf("%lf", &m);
                m = (m < 0) ? -m : m;
                ipGerilmesi(g_ivmeleri, m, isim);
                break;

            case 9:
                printf("Kutle (kg): ");
                scanf("%lf", &m);
                printf("Asansor ivmesi (m/s^2): ");
                scanf("%lf", &a);
                printf("1: Yukari ivmelenen\n2: Asagi ivmelenen\nSecim: ");
                scanf("%d", &tip);

                m = (m < 0) ? -m : m;
                a = (a < 0) ? -a : a;

                if (tip != 1 && tip != 2) {
                    printf("Gecersiz asansor secimi!\n");
                } else {
                    asansorDeneyi(g_ivmeleri, m, a, tip, isim);
                }
                break;

            case -1:
                printf("Program sonlandirildi.\n");
                break;

            default:
                printf("Gecersiz secim yaptiniz!\n");
        }

    } while (secim != -1);

    return 0;
}

/* --- DENEY FONKSIYONLARI --- */

void serbestDusme(double *g, double t, char *isim) {
    printf("\n%s isimli bilim insaninin Serbest Dusme Deneyi Sonuclari:\n", isim);
    for (int i = 0; i < GEZEGEN_SAYISI; i++) {
        double h = 0.5 * (*(g + i)) * t * t;
        printf("%s gezegeninde alinan yol: %.2f metre\n", gezegenler[i], h);
    }
}

void yukariAtis(double *g, double v0, char *isim) {
    printf("\n%s isimli bilim insaninin Yukari Atis Deneyi Sonuclari:\n", isim);
    for (int i = 0; i < GEZEGEN_SAYISI; i++) {
        double h = (v0 * v0) / (2 * (*(g + i)));
        printf("%s gezegeninde maksimum yukseklik: %.2f metre\n", gezegenler[i], h);
    }
}

void agirlikDeneyi(double *g, double m, char *isim) {
    printf("\n%s isimli bilim insaninin Agirlik Deneyi Sonuclari:\n", isim);
    for (int i = 0; i < GEZEGEN_SAYISI; i++) {
        printf("%s gezegeninde agirlik: %.2f Newton\n", gezegenler[i], m * (*(g + i)));
    }
}

void potansiyelEnerji(double *g, double m, double h, char *isim) {
    printf("\n%s isimli bilim insaninin Potansiyel Enerji Deneyi Sonuclari:\n", isim);
    for (int i = 0; i < GEZEGEN_SAYISI; i++) {
        printf("%s gezegeninde Ep: %.2f Joule\n", gezegenler[i], m * (*(g + i)) * h);
    }
}

void hidrostatikBasinc(double *g, double rho, double h, char *isim) {
    printf("\n%s isimli bilim insaninin Hidrostatik Basinc Deneyi Sonuclari:\n", isim);
    for (int i = 0; i < GEZEGEN_SAYISI; i++) {
        printf("%s gezegeninde basinc: %.2f Pascal\n", gezegenler[i], rho * (*(g + i)) * h);
    }
}

void arsimetKuvveti(double *g, double rho, double V, char *isim) {
    printf("\n%s isimli bilim insaninin Arsimet Deneyi Sonuclari:\n", isim);
    for (int i = 0; i < GEZEGEN_SAYISI; i++) {
        printf("%s gezegeninde kaldirma kuvveti: %.2f Newton\n",
               gezegenler[i], rho * (*(g + i)) * V);
    }
}

void basitSarkac(double *g, double L, char *isim) {
    printf("\n%s isimli bilim insaninin Basit Sarkac Deneyi Sonuclari:\n", isim);
    for (int i = 0; i < GEZEGEN_SAYISI; i++) {
        printf("%s gezegeninde periyot: %.2f saniye\n",
               gezegenler[i], 2 * PI * sqrt(L / (*(g + i))));
    }
}

void ipGerilmesi(double *g, double m, char *isim) {
    printf("\n%s isimli bilim insaninin Ip Gerilmesi Deneyi Sonuclari:\n", isim);
    for (int i = 0; i < GEZEGEN_SAYISI; i++) {
        printf("%s gezegeninde ip gerilmesi: %.2f Newton\n",
               gezegenler[i], m * (*(g + i)));
    }
}

void asansorDeneyi(double *g, double m, double a, int tip, char *isim) {
    printf("\n%s isimli bilim insaninin Asansor Deneyi Sonuclari:\n", isim);
    for (int i = 0; i < GEZEGEN_SAYISI; i++) {
        double N = (tip == 1)
                 ? m * ((*(g + i)) + a)
                 : m * ((*(g + i)) - a);

        printf("%s gezegeninde etkin agirlik: %.2f Newton\n", gezegenler[i], N);
    }
    return 0;
}


