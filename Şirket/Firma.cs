using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Şirket
{
    class Firma
    {
        private string firmaAdi;

        public string FirmaAdi
        {
            get { return firmaAdi; }
            set { firmaAdi = value; }
        }
        private int calisanSayisi;

        public int CalisanSayisi
        {
            get { return calisanSayisi; }
            set { calisanSayisi = value; }
        }
        private string sehir;

        public string Sehir
        {
            get { return sehir; }
            set { sehir = value; }
        }
        
        public string FirmaBilgisiOku()
        {
            return "Firma Adi : "+FirmaAdi+"  Calisan sayisi : "+CalisanSayisi+"  Sehir : "+Sehir;
        }
        
    }
}
