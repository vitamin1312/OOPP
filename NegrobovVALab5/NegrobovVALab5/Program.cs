using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;

namespace NegrobovVALab5
{
    internal class Program
    {

        static void do_command(uint choice, NegrobovSSS sss)
        {
            if (choice == 1) {
                NegrobovSSSMember member = new NegrobovSSSMember();
                member.input();
                sss.Add(member);
            }
            else if (choice == 2) {
                NegrobovSSSPresident president = new NegrobovSSSPresident();
                president.input();
                sss.Add(president);
            }
            else if (choice == 3) { sss.Print(); }
            else if (choice == 4) { sss.DeserializeData(); }
            else if (choice == 5) { sss.SerializeData(); }
            else if (choice == 6) { sss.Clear(); }
        }

        static void Main(string[] args)
        {
            NegrobovSSS sss = new NegrobovSSS();
            uint choice = 0;

            while (true)
            {
                Console.WriteLine("1: add member");
                Console.WriteLine("2: add president");
                Console.WriteLine("3: print members");
                Console.WriteLine("4: get members from file");
                Console.WriteLine("5: write members to file");
                Console.WriteLine("6: clear all members");
                Console.WriteLine("0: exit");
                Console.Write("-> ");

                choice = Input.get_uint_value(0, 6);
                if (choice == 0) break;
                do_command(choice, sss);
            }
        }
    }
}
