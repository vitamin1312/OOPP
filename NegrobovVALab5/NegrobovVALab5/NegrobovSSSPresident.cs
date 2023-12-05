using System;
using System.IO;
using System.Runtime.Serialization;


namespace NegrobovVALab5
{
    [Serializable]
    public class NegrobovSSSPresident : NegrobovSSSMember
    {
        public uint experience;

        public NegrobovSSSPresident()
        : base ()
        { }

        public override void output()
        {
            Console.WriteLine("-----------------------------------------");
            Console.WriteLine("President");
            base.output();
            Console.WriteLine($"Experience: {experience}");
            Console.WriteLine("-----------------------------------------");
        }

        public override void input()
        {
            base.input();
            Console.Write("Input experience: ");
            experience = Input.get_uint_value(min_rate, max_rate);
        }
    }
}
