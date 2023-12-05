using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NegrobovVALab5
{
    public static class Input
    {
        public static void check_range(uint value, uint min, uint max)
        {
            if (value >= min && value <= max)
            {
                return;
            }
            throw new ArgumentException($"Value not in range [{min}, {max}]");
        }

        public static uint get_uint_value(uint min, uint max)
        {
            while (true) {
                try
                {
                    uint value = Convert.ToUInt32(Console.ReadLine());
                    check_range(value, min, max);
                    return value;
                }
                catch (ArgumentException e)
                {
                    Console.WriteLine(e.Message);
                }
                catch (FormatException e)
                {
                    Console.WriteLine("Incorrect input data");
                }
            }
        }
    }
}
