using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Şirket
{
    class Calisan
    {
        private string elemanAdi;

        public string ElemanAdi
        {
            get { return elemanAdi; }
            set { elemanAdi = value; }
        }
        private string elemanUnvan;

        public string ElemanUnvan
        {
            get { return elemanUnvan; }
            set { elemanUnvan = value; }
        }
        private DateTime isGirisZamani;

        public DateTime IsGirisZamani
        {
            get { return isGirisZamani; }
            set { isGirisZamani = value; }
        }
        private Firma sirket;

        public Firma Sirket
        {
            get { return sirket; }
            set { sirket = value; }
        }
        
        public void SirketBilgisiGoster()
        {
            Console.WriteLine("Eleman Adi : "+ElemanAdi+"  Unvani : "+ElemanUnvan+"  Ise giris zamani : "+IsGirisZamani);
            Console.WriteLine(Sirket.FirmaBilgisiOku());

        }

    }
}
