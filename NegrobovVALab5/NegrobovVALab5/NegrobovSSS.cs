using System;
using System.Collections.Generic;
using System.IO;
using System.Xml;
using System.Xml.Linq;
using System.Xml.Serialization;
using static System.Net.WebRequestMethods;

namespace NegrobovVALab5
{

    public class NegrobovSSS
    {

        public string store_file { get; set; } = "data.xml";

        public List<NegrobovSSSMember> members = new List<NegrobovSSSMember>();

        public NegrobovSSS() { }

        
        public void Add(NegrobovSSSMember member)
        {
            members.Add(member);
        }

        public void Print()
        {
            if (members.Count == 0)
            {
                Console.WriteLine("There is no members in SSS");
                return;
            }

            foreach (var member in members)
            {
                member.output();
            }
        }

        public void Clear()
        {
            members.Clear();
        }

        public void SerializeData()
        {
            try
            {
                var xs = new XmlSerializer(typeof(List<NegrobovSSSMember>), new[] { typeof(NegrobovSSSMember), typeof(NegrobovSSSPresident) });
                using (Stream fs = new FileStream(store_file, FileMode.Create))
                {
                    xs.Serialize(fs, members);
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Can't write to file {store_file}");
            }
        }

        public void DeserializeData()
        {
            var xs = new XmlSerializer(typeof(List<NegrobovSSSMember>), new[] { typeof(NegrobovSSSMember), typeof(NegrobovSSSPresident) });
            try
            {
                using (Stream fs = new FileStream(store_file, FileMode.Open))
                {
                    members = xs.Deserialize(fs) as List<NegrobovSSSMember>;
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Can't open file {store_file}");
            }
        }
    }
}
