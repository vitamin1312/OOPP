using System;


namespace NegrobovVALab5
{
	[Serializable]
    public class NegrobovSSSMember
    {

        string name;
        string group;
        uint rate;

        uint min_rate = 0;
        uint max_rate = 100;


        public virtual void output()
        {
            Console.WriteLine("-----------------------------------------");
            Console.WriteLine("Name: ", name);
            Console.WriteLine("Group: ", group);
            Console.WriteLine("Rate: ", rate);
            Console.WriteLine("-----------------------------------------");
            Console.WriteLine();
        }


        public virtual void input()
        {
            Console.Write("Input name: ");
            name = Console.ReadLine();

            Console.Write("Input group: ");
            group = Console.ReadLine();

            Console.Write("Input group: ");
            group = Convert.ToUInt32(Console.ReadLine());
        }
    }
}
