using System;

namespace NegrobovVALab5
{
    [Serializable]
    public class NegrobovSSSPresident : NegrobovSSSMember
    {
        uint experience;

        public override output()
        {
            Console.WriteLine("-----------------------------------------");
            Console.WriteLine("President");
            base.output();
            Console.WriteLine("experience: ", experience);
            Console.WriteLine("-----------------------------------------");

        }

        public override input()
        {
            base.input();
            Console.Write("Input experience: ");
            experience = Convert.ToUInt32(Console.ReadLine("Input "));
        }
    }

}
