using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text;
using System.Threading.Tasks;
using System.Xml;
using System.Xml.Serialization;

namespace Kushch_OOPP_lalb5
{
    [Serializable]
    internal class Catalog
    {
        private List<mFile> files = new List<mFile>();


        public Catalog() { }


        public void add(mFile file) => files.Add(file);


        public void clear() => files.Clear();


        public int getSize() => files.Count;


        public void print()
        {
            foreach (var file in files)
            {
                file.print();
                Console.WriteLine();
            }
        }


        public mFile get(int i) => files[i];


        public void remove(int i) => files.RemoveAt(i);

        
        public void StoreBinary()
        {
            var xs = new XmlSerializer(typeof(List<mFile>), new[] { typeof(mFile), typeof(Document) });
            using (Stream fs = new FileStream("file.xml", FileMode.OpenOrCreate))
            {
                xs.Serialize(fs, files);
            }
        }

        public void LoadBinary()
        {
            var xs = new XmlSerializer(typeof(List<mFile>), new[] { typeof(mFile), typeof(Document) });
            using (Stream fs = new FileStream("file.xml", FileMode.OpenOrCreate))
            {
                files = xs.Deserialize(fs) as List<mFile>;
            }
        }
    }
}
