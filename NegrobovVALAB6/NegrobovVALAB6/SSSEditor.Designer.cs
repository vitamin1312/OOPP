namespace NegrobovVALAB6
{
    partial class SSSEditor
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.LBMemNames = new System.Windows.Forms.ListBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.TBName = new System.Windows.Forms.TextBox();
            this.TBGroup = new System.Windows.Forms.TextBox();
            this.TBRate = new System.Windows.Forms.TextBox();
            this.TBExp = new System.Windows.Forms.TextBox();
            this.BAddMember = new System.Windows.Forms.Button();
            this.BDelMember = new System.Windows.Forms.Button();
            this.BEditData = new System.Windows.Forms.Button();
            this.openFileDialog1 = new System.Windows.Forms.OpenFileDialog();
            this.saveFileDialog1 = new System.Windows.Forms.SaveFileDialog();
            this.BAddPres = new System.Windows.Forms.Button();
            this.BSaveMembers = new System.Windows.Forms.Button();
            this.BLoadMembers = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // LBMemNames
            // 
            this.LBMemNames.FormattingEnabled = true;
            this.LBMemNames.ItemHeight = 16;
            this.LBMemNames.Location = new System.Drawing.Point(16, 15);
            this.LBMemNames.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.LBMemNames.Name = "LBMemNames";
            this.LBMemNames.Size = new System.Drawing.Size(248, 340);
            this.LBMemNames.TabIndex = 0;
            this.LBMemNames.SelectedIndexChanged += new System.EventHandler(this.LBMemNames_SelectedIndexChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(295, 38);
            this.label1.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(44, 16);
            this.label1.TabIndex = 1;
            this.label1.Text = "Name";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(295, 71);
            this.label2.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(44, 16);
            this.label2.TabIndex = 2;
            this.label2.Text = "Group";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(295, 105);
            this.label3.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(36, 16);
            this.label3.TabIndex = 3;
            this.label3.Text = "Rate";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(295, 138);
            this.label4.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(75, 16);
            this.label4.TabIndex = 4;
            this.label4.Text = "Experience";
            // 
            // TBName
            // 
            this.TBName.Location = new System.Drawing.Point(431, 30);
            this.TBName.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.TBName.Name = "TBName";
            this.TBName.Size = new System.Drawing.Size(132, 22);
            this.TBName.TabIndex = 5;
            this.TBName.TextChanged += new System.EventHandler(this.TBName_TextChanged);
            // 
            // TBGroup
            // 
            this.TBGroup.Location = new System.Drawing.Point(431, 63);
            this.TBGroup.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.TBGroup.Name = "TBGroup";
            this.TBGroup.Size = new System.Drawing.Size(132, 22);
            this.TBGroup.TabIndex = 6;
            this.TBGroup.TextChanged += new System.EventHandler(this.TBGroup_TextChanged);
            // 
            // TBRate
            // 
            this.TBRate.Location = new System.Drawing.Point(431, 96);
            this.TBRate.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.TBRate.Name = "TBRate";
            this.TBRate.Size = new System.Drawing.Size(132, 22);
            this.TBRate.TabIndex = 7;
            this.TBRate.TextChanged += new System.EventHandler(this.TBRate_TextChanged);
            // 
            // TBExp
            // 
            this.TBExp.Location = new System.Drawing.Point(431, 129);
            this.TBExp.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.TBExp.Name = "TBExp";
            this.TBExp.Size = new System.Drawing.Size(132, 22);
            this.TBExp.TabIndex = 8;
            this.TBExp.TextChanged += new System.EventHandler(this.TBExp_TextChanged);
            // 
            // BAddMember
            // 
            this.BAddMember.Location = new System.Drawing.Point(299, 198);
            this.BAddMember.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.BAddMember.Name = "BAddMember";
            this.BAddMember.Size = new System.Drawing.Size(124, 28);
            this.BAddMember.TabIndex = 9;
            this.BAddMember.Text = "Add member";
            this.BAddMember.UseVisualStyleBackColor = true;
            this.BAddMember.Click += new System.EventHandler(this.BAddMember_Click);
            // 
            // BDelMember
            // 
            this.BDelMember.Location = new System.Drawing.Point(299, 256);
            this.BDelMember.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.BDelMember.Name = "BDelMember";
            this.BDelMember.Size = new System.Drawing.Size(124, 28);
            this.BDelMember.TabIndex = 10;
            this.BDelMember.Text = "Delete";
            this.BDelMember.UseVisualStyleBackColor = true;
            this.BDelMember.Click += new System.EventHandler(this.BDelMember_Click);
            // 
            // BEditData
            // 
            this.BEditData.Location = new System.Drawing.Point(444, 256);
            this.BEditData.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.BEditData.Name = "BEditData";
            this.BEditData.Size = new System.Drawing.Size(120, 28);
            this.BEditData.TabIndex = 11;
            this.BEditData.Text = "Edit";
            this.BEditData.UseVisualStyleBackColor = true;
            this.BEditData.Click += new System.EventHandler(this.BEditData_Click);
            // 
            // openFileDialog1
            // 
            this.openFileDialog1.FileName = "openFileDialog1";
            // 
            // BAddPres
            // 
            this.BAddPres.Location = new System.Drawing.Point(444, 198);
            this.BAddPres.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.BAddPres.Name = "BAddPres";
            this.BAddPres.Size = new System.Drawing.Size(120, 28);
            this.BAddPres.TabIndex = 12;
            this.BAddPres.Text = "Add president\r\n";
            this.BAddPres.UseVisualStyleBackColor = true;
            this.BAddPres.Click += new System.EventHandler(this.BAddPres_Click);
            // 
            // BSaveMembers
            // 
            this.BSaveMembers.Location = new System.Drawing.Point(339, 338);
            this.BSaveMembers.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.BSaveMembers.Name = "BSaveMembers";
            this.BSaveMembers.Size = new System.Drawing.Size(100, 28);
            this.BSaveMembers.TabIndex = 13;
            this.BSaveMembers.Text = "Save";
            this.BSaveMembers.UseVisualStyleBackColor = true;
            this.BSaveMembers.Click += new System.EventHandler(this.BSaveMembers_Click);
            // 
            // BLoadMembers
            // 
            this.BLoadMembers.Location = new System.Drawing.Point(464, 338);
            this.BLoadMembers.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.BLoadMembers.Name = "BLoadMembers";
            this.BLoadMembers.Size = new System.Drawing.Size(100, 28);
            this.BLoadMembers.TabIndex = 14;
            this.BLoadMembers.Text = "Load";
            this.BLoadMembers.UseVisualStyleBackColor = true;
            this.BLoadMembers.Click += new System.EventHandler(this.BLoadMembers_Click);
            // 
            // SSSEditor
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(591, 382);
            this.Controls.Add(this.BLoadMembers);
            this.Controls.Add(this.BSaveMembers);
            this.Controls.Add(this.BAddPres);
            this.Controls.Add(this.BEditData);
            this.Controls.Add(this.BDelMember);
            this.Controls.Add(this.BAddMember);
            this.Controls.Add(this.TBExp);
            this.Controls.Add(this.TBRate);
            this.Controls.Add(this.TBGroup);
            this.Controls.Add(this.TBName);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.LBMemNames);
            this.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.Name = "SSSEditor";
            this.Text = "SSSEditor";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ListBox LBMemNames;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox TBName;
        private System.Windows.Forms.TextBox TBGroup;
        private System.Windows.Forms.TextBox TBRate;
        private System.Windows.Forms.TextBox TBExp;
        private System.Windows.Forms.Button BAddMember;
        private System.Windows.Forms.Button BDelMember;
        private System.Windows.Forms.Button BEditData;
        private System.Windows.Forms.OpenFileDialog openFileDialog1;
        private System.Windows.Forms.SaveFileDialog saveFileDialog1;
        private System.Windows.Forms.Button BAddPres;
        private System.Windows.Forms.Button BSaveMembers;
        private System.Windows.Forms.Button BLoadMembers;
    }
}

