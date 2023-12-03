using System.Runtime.CompilerServices;
using System.Runtime.Serialization.Formatters.Binary;
using System.Runtime.Serialization.Formatters.Soap;
using System.Xml;

namespace Kushch_OOPP_lalb5
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int commandIndex = -1;

            Catalog files = new Catalog();

            while (commandIndex != 0)
            {
                printMenu();
                Console.WriteLine("Enter command index (from 1 to 6): ");
                commandIndex = Convert.ToInt32(Console.ReadLine());

                switch (commandIndex) 
                {
                    case 0:
                        return;

                    case 1:
                        mFile file = new mFile();
                        file.read();
                        files.add(file);
                        break;

                    case 2:
                        mFile doc = new Document();
                        doc.read();
                        files.add(doc);
                        break;
                        
                    case 3:
                        files.print();
                        break;

                    case 4:
                        files.LoadBinary();
                        break;

                    case 5:
                        files.StoreBinary();
                        break;

                    case 6:
                        files.clear();
                        break;
                }
            }
        }

        static void printMenu()
        {
            Console.WriteLine("1: Add new file to catalog");
            Console.WriteLine("2: Add new document to catalog");
            Console.WriteLine("3: Show all file from catalog");
            Console.WriteLine("4: Read list of files from file stream");
            Console.WriteLine("5: Save catalog to file");
            Console.WriteLine("6: Clear catalog\n");
        }
    }
}