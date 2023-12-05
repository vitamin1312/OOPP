using System;
using System.IO;
using System.Runtime.Serialization;

namespace NegrobovVALab5
{
	[Serializable]
    public class NegrobovSSSMember
    {

        public string name;
        public string group;
        public uint rate;

        protected uint min_rate = 0;
        protected uint max_rate = 100;


        public NegrobovSSSMember() { }


        public virtual void output()
        {
            Console.WriteLine("-----------------------------------------");
            Console.WriteLine($"Name: {name}");
            Console.WriteLine($"Group: {group}");
            Console.WriteLine($"Name: {rate}");
            Console.WriteLine("-----------------------------------------");
        }


        public virtual void input()
        {
            Console.Write("Input name: ");
            name = Console.ReadLine();

            Console.Write("Input group: ");
            group = Console.ReadLine();

            Console.Write("Input rate: ");
            rate = Input.get_uint_value(min_rate, max_rate);
        }
    }
}
