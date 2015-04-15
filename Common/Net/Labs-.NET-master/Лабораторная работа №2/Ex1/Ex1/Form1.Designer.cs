namespace Ex1
{
    partial class Form1
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
            this.components = new System.ComponentModel.Container();
            this.rb1 = new System.Windows.Forms.RadioButton();
            this.rb2 = new System.Windows.Forms.RadioButton();
            this.checkList1 = new System.Windows.Forms.CheckedListBox();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.btnSumm = new System.Windows.Forms.Button();
            this.lbSum1 = new System.Windows.Forms.Label();
            this.contextMenuStrip1 = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.addStrip = new System.Windows.Forms.ToolStripMenuItem();
            this.deleteStrip = new System.Windows.Forms.ToolStripMenuItem();
            this.groupBox1.SuspendLayout();
            this.contextMenuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // rb1
            // 
            this.rb1.AutoSize = true;
            this.rb1.Checked = true;
            this.rb1.Location = new System.Drawing.Point(23, 19);
            this.rb1.Name = "rb1";
            this.rb1.Size = new System.Drawing.Size(46, 17);
            this.rb1.TabIndex = 0;
            this.rb1.TabStop = true;
            this.rb1.Text = "1-10";
            this.rb1.UseVisualStyleBackColor = true;
            // 
            // rb2
            // 
            this.rb2.AutoSize = true;
            this.rb2.Location = new System.Drawing.Point(23, 42);
            this.rb2.Name = "rb2";
            this.rb2.Size = new System.Drawing.Size(52, 17);
            this.rb2.TabIndex = 1;
            this.rb2.TabStop = true;
            this.rb2.Text = "11-20";
            this.rb2.UseVisualStyleBackColor = true;
            // 
            // checkList1
            // 
            this.checkList1.FormattingEnabled = true;
            this.checkList1.Location = new System.Drawing.Point(12, 53);
            this.checkList1.Name = "checkList1";
            this.checkList1.Size = new System.Drawing.Size(120, 94);
            this.checkList1.TabIndex = 2;
            this.checkList1.SelectedIndexChanged += new System.EventHandler(this.checkList1_SelectedIndexChanged);
            this.checkList1.MouseDown += new System.Windows.Forms.MouseEventHandler(this.checkList1_MouseDown);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.rb1);
            this.groupBox1.Controls.Add(this.rb2);
            this.groupBox1.Location = new System.Drawing.Point(165, 53);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(200, 100);
            this.groupBox1.TabIndex = 3;
            this.groupBox1.TabStop = false;
            // 
            // btnSumm
            // 
            this.btnSumm.Location = new System.Drawing.Point(12, 179);
            this.btnSumm.Name = "btnSumm";
            this.btnSumm.Size = new System.Drawing.Size(75, 23);
            this.btnSumm.TabIndex = 4;
            this.btnSumm.Text = "Summ";
            this.btnSumm.UseVisualStyleBackColor = true;
            this.btnSumm.Click += new System.EventHandler(this.btnSumm_Click);
            // 
            // lbSum1
            // 
            this.lbSum1.AutoSize = true;
            this.lbSum1.Location = new System.Drawing.Point(12, 225);
            this.lbSum1.Name = "lbSum1";
            this.lbSum1.Size = new System.Drawing.Size(44, 13);
            this.lbSum1.TabIndex = 5;
            this.lbSum1.Text = "Сумма:";
            // 
            // contextMenuStrip1
            // 
            this.contextMenuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.addStrip,
            this.deleteStrip});
            this.contextMenuStrip1.Name = "contextMenuStrip1";
            this.contextMenuStrip1.Size = new System.Drawing.Size(108, 48);
            // 
            // addStrip
            // 
            this.addStrip.Name = "addStrip";
            this.addStrip.Size = new System.Drawing.Size(152, 22);
            this.addStrip.Text = "Add";
            this.addStrip.Click += new System.EventHandler(this.addStrip_Click);
            // 
            // deleteStrip
            // 
            this.deleteStrip.Name = "deleteStrip";
            this.deleteStrip.Size = new System.Drawing.Size(152, 22);
            this.deleteStrip.Text = "Delete";
            this.deleteStrip.Click += new System.EventHandler(this.deleteStrip_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(411, 261);
            this.Controls.Add(this.lbSum1);
            this.Controls.Add(this.btnSumm);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.checkList1);
            this.Name = "Form1";
            this.Text = "Lab2";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.contextMenuStrip1.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.RadioButton rb1;
        private System.Windows.Forms.RadioButton rb2;
        private System.Windows.Forms.CheckedListBox checkList1;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Button btnSumm;
        private System.Windows.Forms.Label lbSum1;
        private System.Windows.Forms.ContextMenuStrip contextMenuStrip1;
        private System.Windows.Forms.ToolStripMenuItem addStrip;
        private System.Windows.Forms.ToolStripMenuItem deleteStrip;
    }
}

