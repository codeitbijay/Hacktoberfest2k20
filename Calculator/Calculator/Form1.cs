using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Calculator
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            float num1, num2;

            num1 = float.Parse(txtnumber1.Text);
            num2 = float.Parse(txtnumber2.Text);

            lblequal.Text = (num1+num2).ToString();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            float num1, num2;

            num1 = float.Parse(txtnumber1.Text);
            num2 = float.Parse(txtnumber2.Text);

            lblequal.Text = (num1 - num2).ToString();
        }

        private void multimark_Click(object sender, EventArgs e)
        {
            float num1, num2;

            num1 = float.Parse(txtnumber1.Text);
            num2 = float.Parse(txtnumber2.Text);

            lblequal.Text = (num1 * num2).ToString();
        }

        private void dividemark_Click(object sender, EventArgs e)
        {
            float num1, num2;

            num1 = float.Parse(txtnumber1.Text);
            num2 = float.Parse(txtnumber2.Text);

            lblequal.Text = (num1 / num2).ToString();
        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            lblequal.Text = "";
        }
    }
}
