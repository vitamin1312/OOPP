using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Runtime.InteropServices;
using System.Runtime.Serialization;
using System.Text;
using System.Threading.Tasks;
using System.Xml;
using System.Xml.Serialization;

namespace Kushch_OOPP_lalb5
{
    [Serializable]
     public class mFile
    {
        public string? name { set; get; }

        public string? accessMode { set; get; }

        public string? description { set; get; }

        public int size { set; get; }

        public mFile() {}

        public mFile(string name, string accessMode, string description)
        {
            this.name = name;
            this.accessMode = accessMode;
            this.description = description;
            this.size = sizeof(int) 
                        + System.Text.Encoding.UTF8.GetByteCount(name) 
                        + System.Text.Encoding.UTF8.GetByteCount(accessMode)
                        + System.Text.Encoding.UTF8.GetByteCount(description);
        }

        public virtual void print()
        {
            Console.WriteLine("Name: " + name);
            Console.WriteLine("accessMode: : " + accessMode);
            Console.WriteLine("Description: " + description);
            Console.WriteLine("Size: " + size);
        }

        public virtual void read()
        {
            Console.WriteLine("Enter file name: ");
            this.name = Console.ReadLine();

            Console.WriteLine("Enter accessMode name: ");
            this.accessMode = Console.ReadLine();

            Console.WriteLine("Enter description name: ");
            this.description = Console.ReadLine();

            this.size = sizeof(int)
                        + System.Text.Encoding.UTF8.GetByteCount(name)
                        + System.Text.Encoding.UTF8.GetByteCount(accessMode)
                        + System.Text.Encoding.UTF8.GetByteCount(description);
        }

        public virtual void ToStream(DataContractSerializer ds, Stream stream)
        {
            ds.WriteObject(stream, this);
        }

        public virtual void FromStream(DataContractSerializer ds, Stream stream)
        {
            mFile f = (mFile) ds.ReadObject(stream);
            this.name = f.name;
            this.accessMode = f.accessMode;
            this.description = f.description;
        }
    }
}
