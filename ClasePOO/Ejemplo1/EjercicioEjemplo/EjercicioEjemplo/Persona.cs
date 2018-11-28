using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EjercicioEjemplo
{
    class Persona
    {
        public string nombre;
        public string apellido;
        private int edad;

        public Persona() { }

        public Persona(string nombre,string apellido, int edad) {
            this.apellido = apellido;
            this.nombre = nombre;
            this.edad = edad;
        }

        public void correr(int pasos) {
            Console.WriteLine("Nombre: {0}, Apellido {1}, corre {2} pasos", this.nombre, this.apellido, pasos);
            Console.ReadLine();
        }

        public static int sumarEdad(Persona per1,Persona per2) {
            int retorno = 0;
            retorno = per1.edad + per2.edad;
            return retorno;
        }
    }
}
