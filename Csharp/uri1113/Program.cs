using System;

namespace Csharp
{
    class Program
    {
        static void Main(string[] args)
        {
            String input = Console.ReadLine();
            int n1 = int.Parse (input.Split(" ")[0]);
            int n2 = int.Parse (input.Split(" ")[1]);

            while (n1 != n2)
            {
                if (n1 > n2)
                {
                   Console.WriteLine("Decrescente"); 
                }
                else
                {
                   Console.WriteLine("Crescente"); 
                }
                input = Console.ReadLine();
                n1 = int.Parse (input.Split(" ")[0]);
                n2 = int.Parse (input.Split(" ")[1]);

            }
        }
    }
}
