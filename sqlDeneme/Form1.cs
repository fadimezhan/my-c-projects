using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace sqlDeneme
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'denemeDataSet.tblKisiler' table. You can move, or remove it, as needed.
            this.tblKisilerTableAdapter.Fill(this.denemeDataSet.tblKisiler);

        }

        VeritabaniIslemleri vt = new VeritabaniIslemleri();

        private void button1_Click(object sender, EventArgs e)
        {
            vt.kayitEkle("insert into tblKisiler(Isim,Soyisim,Numara) values('Masal','Hikaye',1453)");
            MessageBox.Show("Eklendi! ");
            dataGridView1.DataSource = vt.getDataTable("select Id,Isim,Soyisim,Numara from tblKisiler");
        }

        private void button2_Click(object sender, EventArgs e)
        {
            string silinecek =dataGridView1.SelectedRows[0].Cells[0].Value.ToString();
            vt.kayitEkle("delete from tblKisiler where Id='"+silinecek+"'");
            MessageBox.Show("Silindi!");
            dataGridView1.DataSource = vt.getDataTable("select Id,Isim,Soyisim,Numara from tblKisiler");
        }

        private void textBoxAra_TextChanged(object sender, EventArgs e)
        {
            //gridde isme göre arar...
            dataGridView1.DataSource = vt.getDataTable("select * from tblKisiler where Isim like'%" + textBoxAra.Text + "%'");
        }

        private void button3_Click(object sender, EventArgs e)
        {
            string guncel = dataGridView1.SelectedRows[0].Cells[0].Value.ToString();
           // vt.kayitEkle("select from tblKisiler where Id='" + guncel + "'");

            if (textBox2.Text!=null)
                vt.kayitEkle("update tblKİsiler set Isim='"+textBox2.Text+"' where Id= '"+guncel+"'");
           
            else if (textBox3.Text!=null)
                vt.kayitEkle("update tblKİsiler set Soyisim='" + textBox3.Text + "' where Id= '" + guncel + "' ");
            
            else if(textBox4.Text!=null)
                vt.kayitEkle("update tblKİsiler set Numara= " + textBox4.Text + " where Id= '" + guncel + "' ");

            MessageBox.Show("Güncellendi! ");
            dataGridView1.DataSource = vt.getDataTable("select Id,Isim,Soyisim,Numara from tblKisiler");
        }
    }
}
