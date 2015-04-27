using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Şirket
{
    class Program
    {
        static void Main(string[] args)
        {
            Firma firma1 = new Firma();
            firma1.FirmaAdi = "Pamukkale";
            firma1.CalisanSayisi = 1000;
            firma1.Sehir = "Denizli";

            Calisan kisi1 = new Calisan();
            kisi1.ElemanAdi = "Fadime";
            kisi1.ElemanUnvan = "Bilgisayar Muhendisi";
            kisi1.IsGirisZamani = DateTime.Now;

            kisi1.Sirket = firma1; //iki sinifi bagladik.
            kisi1.SirketBilgisiGoster();

        }
    }
}
