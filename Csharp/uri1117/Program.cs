using System;

namespace uri1117
{
    class Program
    {
        static void Main(string[] args)
        {
            double n1 = Convert.ToDouble (Console.ReadLine());
            
            while (n1<0 || n1>10)
            {
                Console.WriteLine ("nota invalida");
                n1 = Convert.ToDouble (Console.ReadLine()); 
            }

            double n2 = Convert.ToDouble (Console.ReadLine());     

            while (n2<0 || n2>10)
            {
                Console.WriteLine ("nota invalida");
                n2 = Convert.ToInt32 (Console.ReadLine());
            }

            double media = (n1 + n2) / 2;
            Console.WriteLine ("media = " + media.ToString ("0.##"));
        }
    }
}
