using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejercicio2
{
    class Numero
    {
        private double numero;

        public void setNumero(string numero) {
            this.numero = ValidarNumeroString(numero);
        }

        public Numero(string numero) {
            this.numero = ValidarNumeroString(numero);
        }

        public Numero(double numero) {
            this.numero = numero;
        }

        private double ValidarNumeroString(string numero) {
            double retorno;
            if (!double.TryParse(numero, out retorno))
            {
                retorno = 0;
            }
            return retorno;
        }

        public static double Sumar(Numero n1, Numero n2) {
            double resultado = n1.numero + n2.numero;
            return resultado;
        }


    }
}
