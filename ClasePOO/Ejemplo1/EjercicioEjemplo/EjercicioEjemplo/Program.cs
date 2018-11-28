using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EjercicioEjemplo
{
    class Program
    {
        static void Main(string[] args)
        {
            Persona p1 = new Persona("Juan", "Perez",22);
            p1.correr(22);

            Persona p2 = new Persona("Mariana", "Cardozo", 20);
            int edades = Persona.sumarEdad(p1, p2);
            Console.WriteLine("La edad de las personas es : {0}",edades);
            Console.ReadLine();
        }
    }
}
