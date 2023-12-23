using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace NegrobovVALAB6
{

    [StructLayout(LayoutKind.Sequential, CharSet = CharSet.Ansi)]
    struct ClassInfo
    {
        [MarshalAs(UnmanagedType.U1)]
        public byte isBaseClass;

        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 50)]
        public string name;

        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 50)]
        public string group;

        [MarshalAs(UnmanagedType.U4)]
        public uint rate;

        [MarshalAs(UnmanagedType.U4)]
        public uint experience;
    }


    public partial class SSSEditor : Form
    {

        string libPath = "";

        StringBuilder storageFile = new StringBuilder("real_data");

        [DllImport("SSSClasses", CharSet = CharSet.Ansi)]
        static extern void GetClassInfo_(ref ClassInfo st, int i);


        [DllImport("SSSClasses", CharSet = CharSet.Ansi)]
        static extern void SetClassInfo(ref ClassInfo st, int i);


        [DllImport("SSSClasses", CharSet = CharSet.Ansi)]
        static extern int GetSssSize();


        [DllImport("SSSClasses", CharSet = CharSet.Ansi)]
        static extern void Erase(int i);


        [DllImport("SSSClasses", CharSet = CharSet.Ansi)]
        static extern void AddMember();


        [DllImport("SSSClasses", CharSet = CharSet.Ansi)]
        static extern void AddPresident();


        [DllImport("SSSClasses", CharSet = CharSet.Ansi)]
        static extern void GetFromFile(StringBuilder fileName);


        [DllImport("SSSClasses", CharSet = CharSet.Ansi)]
        static extern void LoadToFile(StringBuilder fileName);

        ClassInfo info;
        int currentIndex;

        public SSSEditor()
        {
            InitializeComponent();
        }

        private void updateLBMemNames()
        {
            LBMemNames.Items.Clear();
            int size = GetSssSize();

            for (int i = 0; i < size; ++i)
            {
                GetClassInfo_(ref info, i);
                LBMemNames.Items.Add(info.name);
            }
        }


        private void BAddMember_Click(object sender, EventArgs e)
        {
            AddMember();
            updateLBMemNames();
            LBMemNames.SelectedIndex = LBMemNames.Items.Count - 1;
            currentIndex = LBMemNames.SelectedIndex;
        }

        private void BSaveMembers_Click(object sender, EventArgs e)
        {
            LoadToFile(new StringBuilder("test.dat"));
        }

        private void BLoadMembers_Click(object sender, EventArgs e)
        {
            GetFromFile(new StringBuilder("test.dat"));
            updateLBMemNames();
        }

        private void BAddPres_Click(object sender, EventArgs e)
        {
            AddPresident();
            updateLBMemNames();
            LBMemNames.SelectedIndex = LBMemNames.Items.Count - 1;
            currentIndex = LBMemNames.SelectedIndex;
        }

        private void BEditData_Click(object sender, EventArgs e)
        {
            currentIndex = LBMemNames.SelectedIndex;
            if (currentIndex == -1)
                return;
            SetClassInfo(ref info, currentIndex);
            updateLBMemNames();
            LBMemNames.SelectedIndex = currentIndex;
        }

        private void BDelMember_Click(object sender, EventArgs e)
        {
            currentIndex = LBMemNames.SelectedIndex;
            int tmp = currentIndex;
            if (currentIndex == -1)
                return;
            Erase(currentIndex);
            LBMemNames.Items.RemoveAt(currentIndex);
            currentIndex = tmp;
            if (LBMemNames.Items.Count == 0)
            {
                currentIndex = -1;
                return;
            }
            if (currentIndex == LBMemNames.Items.Count)
            {
                LBMemNames.SelectedIndex = LBMemNames.Items.Count - 1;
                currentIndex = LBMemNames.SelectedIndex;
            }
            else
            {
                LBMemNames.SelectedIndex = currentIndex;
                currentIndex = LBMemNames.SelectedIndex;
            }
        }

        private void TBName_TextChanged(object sender, EventArgs e)
        {
            info.name = TBName.Text;
        }

        private void TBGroup_TextChanged(object sender, EventArgs e)
        {
            info.group = TBGroup.Text;
        }

        private void TBRate_TextChanged(object sender, EventArgs e)
        {
            try
            {
                info.rate = Convert.ToUInt32(TBRate.Text);
            }
            catch (Exception ex) {
                info.rate = 0;
            }

        }

        private void TBExp_TextChanged(object sender, EventArgs e)
        {
            try
            {
                info.experience = Convert.ToUInt32(TBExp.Text);
            }
            catch (Exception ex)
            {
                info.experience = 0;
            }
        }

        private void LBMemNames_SelectedIndexChanged(object sender, EventArgs e)
        {
            currentIndex = LBMemNames.SelectedIndex;
            if (currentIndex == -1)
            {
                ClearTable();
                return;
            }
            GetClassInfo_(ref info, currentIndex);

            TBName.Text = info.name;
            TBGroup.Text = info.group;
            TBRate.Text = Convert.ToString(info.rate);


            if (info.isBaseClass == 1)
            {
                TBExp.Text = String.Empty;
                TBExp.Enabled = false;
            }
            else
            {
                TBExp.Enabled = true;
                TBExp.Text = Convert.ToString(info.experience);
            }
        }
 

        private void ClearTable()
        {
            TBName.Text = String.Empty;
            TBGroup.Text = String.Empty;
            TBRate.Text = String.Empty;
            TBExp.Text = String.Empty;
            TBExp.Enabled = false;
        }
    }
}
