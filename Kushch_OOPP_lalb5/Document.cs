using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.Text;
using System.Threading.Tasks;
using System.Xml;

namespace Kushch_OOPP_lalb5
{

    [Serializable]
    public class Document : mFile
    {

        public string? owner { set; get; }

        public string? lastChangeData { set; get; }

        public Document()
            : base()
        {}

        public Document(string name, string accessMode, string description, string owner)
            : base(name, accessMode, description)
        {
            this.owner = owner;
            this.size += System.Text.Encoding.UTF8.GetByteCount(description);

            lastChangeData = DateTime.Now.ToString("h:mm::ss tt");
        }

        public override void print()
        {
            base.print();
            Console.WriteLine("Owner: " + owner);
            Console.WriteLine("Last data change: " + lastChangeData);
        }

        public override void read()
        {
            base.read();

            Console.WriteLine("Enter file owner: ");
            owner = Console.ReadLine();
            lastChangeData = DateTime.Now.ToString("h:mm::ss tt");
        }

        public override void ToStream(DataContractSerializer ds, Stream stream)
        {
            ds.WriteObject(stream, this);
        }

        public override void FromStream(DataContractSerializer ds, Stream stream)
        {
            base.FromStream(ds, stream);
            Document doc = (Document) ds.ReadObject(stream);
            this.owner = doc.owner;
            this.lastChangeData = doc.lastChangeData; 
        }
    }
}
