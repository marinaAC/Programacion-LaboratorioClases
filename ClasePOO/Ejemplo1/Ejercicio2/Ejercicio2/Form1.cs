using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Ejercicio2
{
    public partial class formCalculadora : Form
    {
        public formCalculadora()
        {
            InitializeComponent();
        }

        private void txtUno_TextChanged(object sender, EventArgs e)
        {

        }

        private void btnSumar_Click(object sender, EventArgs e)
        {
            string numero1 = this.txtUno.Text;
            string numero2 = this.txtDos.Text;
            Numero n1 = new Numero(numero1);
            Numero n2 = new Numero(numero2);
            double resultado = Numero.Sumar(n1, n2);
            this.txtResultado.Text = resultado.ToString();
        }

        private void btnBorrar_Click(object sender, EventArgs e)
        {
            this.txtUno.Text = null;
            this.txtDos.Text = null;
            this.txtResultado.Text = null;
        }
    }
}
