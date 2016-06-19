using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            string taille;
            string continuer = "O";
            Console.Write("Taille du graphe :");
            taille = Console.ReadLine();

            string[] listeSommets = new string[int.Parse(taille)];
            string[,] tableauGraphe = new string[int.Parse(taille), int.Parse(taille)];
            
            for (int i = 0; i<int.Parse(taille); i++)
            {
                Console.Write("nom du sommet" + i + " : ");
                listeSommets[i] = Console.ReadLine();
            }

            Console.Clear();

            Console.Write("liste des sommet : ");
            for (int i = 0; i < int.Parse(taille); i++)
            {
                Console.Write(listeSommets[i] + " ");
            }

            while (continuer == "O")
            {
                int i = 0;
                int j = 0;
                string lettre;
                Console.Write("nom du sommet : ");
                lettre = Console.ReadLine();
                for (int k = 0; k < int.Parse(taille); k++)
                {
                    if (listeSommets[k] == lettre)
                    {
                        i = k;
                    }
                }
                Console.Write("Vers nom du sommet : ");
                lettre = Console.ReadLine();
                for (int k = 0; k < int.Parse(taille); k++)
                {
                    if (listeSommets[k] == lettre)
                    {
                        j = k;
                    }
                }
                tableauGraphe[i, j] = "1";

                Console.WriteLine("nouveau chemin ? (O/N): ");
                continuer = Console.ReadLine();
            }
            for (int i = 0; i < int.Parse(taille);i++)
            {
                for (int j = 0; j < int.Parse(taille); i++)
                {
                    Console.Write(tableauGraphe[i,j]);
                }
            }
        }
    }
}
