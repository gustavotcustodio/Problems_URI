using System;

namespace uri2896
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = Convert.ToInt32 (Console.ReadLine());

            for (int i = 0; i < n; i++)
            {
                String input = Console.ReadLine();
                int N = Convert.ToInt32 (input.Split(" ")[0]);
                int K = Convert.ToInt32 (input.Split(" ")[1]);

                int n_bottles = N / K;
                n_bottles += N % K;

                Console.WriteLine (n_bottles);
            }
        }
    }
}
