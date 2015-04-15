namespace graf
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
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.key = new System.Windows.Forms.NumericUpDown();
            this.add = new System.Windows.Forms.Button();
            this.remove = new System.Windows.Forms.Button();
            this.from = new System.Windows.Forms.NumericUpDown();
            this.to = new System.Windows.Forms.NumericUpDown();
            this.link = new System.Windows.Forms.Button();
            this.unlink = new System.Windows.Forms.Button();
            this.btnDepth = new System.Windows.Forms.Button();
            this.btnWidth = new System.Windows.Forms.Button();
            this.clear = new System.Windows.Forms.Button();
            this.prima = new System.Windows.Forms.Button();
            this.cost = new System.Windows.Forms.NumericUpDown();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.key)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.from)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.to)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.cost)).BeginInit();
            this.SuspendLayout();
            // 
            // pictureBox1
            // 
            this.pictureBox1.Location = new System.Drawing.Point(12, 12);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(452, 356);
            this.pictureBox1.TabIndex = 0;
            this.pictureBox1.TabStop = false;
            this.pictureBox1.Paint += new System.Windows.Forms.PaintEventHandler(this.pictureBox1_Paint);
            // 
            // key
            // 
            this.key.Location = new System.Drawing.Point(470, 12);
            this.key.Name = "key";
            this.key.Size = new System.Drawing.Size(158, 20);
            this.key.TabIndex = 1;
            // 
            // add
            // 
            this.add.Location = new System.Drawing.Point(470, 38);
            this.add.Name = "add";
            this.add.Size = new System.Drawing.Size(75, 23);
            this.add.TabIndex = 2;
            this.add.Text = "Add";
            this.add.UseVisualStyleBackColor = true;
            this.add.Click += new System.EventHandler(this.add_Click);
            // 
            // remove
            // 
            this.remove.Location = new System.Drawing.Point(553, 38);
            this.remove.Name = "remove";
            this.remove.Size = new System.Drawing.Size(75, 23);
            this.remove.TabIndex = 2;
            this.remove.Text = "Remove";
            this.remove.UseVisualStyleBackColor = true;
            this.remove.Click += new System.EventHandler(this.remove_Click);
            // 
            // from
            // 
            this.from.Location = new System.Drawing.Point(470, 171);
            this.from.Name = "from";
            this.from.Size = new System.Drawing.Size(158, 20);
            this.from.TabIndex = 3;
            // 
            // to
            // 
            this.to.Location = new System.Drawing.Point(470, 197);
            this.to.Name = "to";
            this.to.Size = new System.Drawing.Size(158, 20);
            this.to.TabIndex = 4;
            // 
            // link
            // 
            this.link.Location = new System.Drawing.Point(470, 249);
            this.link.Name = "link";
            this.link.Size = new System.Drawing.Size(75, 23);
            this.link.TabIndex = 5;
            this.link.Text = "Link";
            this.link.UseVisualStyleBackColor = true;
            this.link.Click += new System.EventHandler(this.link_Click);
            // 
            // unlink
            // 
            this.unlink.Location = new System.Drawing.Point(553, 249);
            this.unlink.Name = "unlink";
            this.unlink.Size = new System.Drawing.Size(75, 23);
            this.unlink.TabIndex = 5;
            this.unlink.Text = "Unlink";
            this.unlink.UseVisualStyleBackColor = true;
            this.unlink.Click += new System.EventHandler(this.unlink_Click);
            // 
            // btnDepth
            // 
            this.btnDepth.Location = new System.Drawing.Point(470, 67);
            this.btnDepth.Name = "btnDepth";
            this.btnDepth.Size = new System.Drawing.Size(75, 23);
            this.btnDepth.TabIndex = 6;
            this.btnDepth.Text = "Go Depth";
            this.btnDepth.UseVisualStyleBackColor = true;
            this.btnDepth.Click += new System.EventHandler(this.btnDepth_Click);
            // 
            // btnWidth
            // 
            this.btnWidth.Location = new System.Drawing.Point(553, 67);
            this.btnWidth.Name = "btnWidth";
            this.btnWidth.Size = new System.Drawing.Size(75, 23);
            this.btnWidth.TabIndex = 6;
            this.btnWidth.Text = "Go Width";
            this.btnWidth.UseVisualStyleBackColor = true;
            this.btnWidth.Click += new System.EventHandler(this.btnWidth_Click);
            // 
            // clear
            // 
            this.clear.Location = new System.Drawing.Point(553, 345);
            this.clear.Name = "clear";
            this.clear.Size = new System.Drawing.Size(75, 23);
            this.clear.TabIndex = 7;
            this.clear.Text = "clr";
            this.clear.UseVisualStyleBackColor = true;
            this.clear.Click += new System.EventHandler(this.clear_Click);
            // 
            // prima
            // 
            this.prima.Location = new System.Drawing.Point(553, 119);
            this.prima.Name = "prima";
            this.prima.Size = new System.Drawing.Size(75, 23);
            this.prima.TabIndex = 8;
            this.prima.Text = "Prima";
            this.prima.UseVisualStyleBackColor = true;
            this.prima.Click += new System.EventHandler(this.prima_Click);
            // 
            // cost
            // 
            this.cost.Location = new System.Drawing.Point(470, 223);
            this.cost.Name = "cost";
            this.cost.Size = new System.Drawing.Size(158, 20);
            this.cost.TabIndex = 9;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(640, 380);
            this.Controls.Add(this.cost);
            this.Controls.Add(this.prima);
            this.Controls.Add(this.clear);
            this.Controls.Add(this.btnWidth);
            this.Controls.Add(this.btnDepth);
            this.Controls.Add(this.unlink);
            this.Controls.Add(this.link);
            this.Controls.Add(this.to);
            this.Controls.Add(this.from);
            this.Controls.Add(this.remove);
            this.Controls.Add(this.add);
            this.Controls.Add(this.key);
            this.Controls.Add(this.pictureBox1);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.key)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.from)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.to)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.cost)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.NumericUpDown key;
        private System.Windows.Forms.Button add;
        private System.Windows.Forms.Button remove;
        private System.Windows.Forms.NumericUpDown from;
        private System.Windows.Forms.NumericUpDown to;
        private System.Windows.Forms.Button link;
        private System.Windows.Forms.Button unlink;
        private System.Windows.Forms.Button btnDepth;
        private System.Windows.Forms.Button btnWidth;
        private System.Windows.Forms.Button clear;
        private System.Windows.Forms.Button prima;
        private System.Windows.Forms.NumericUpDown cost;
    }
}

