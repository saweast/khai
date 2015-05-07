namespace Lab9Alt {
    partial class Form1 {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing) {
            if (disposing && (components != null)) {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent() {
            this.cbxStudents = new System.Windows.Forms.ComboBox();
            this.lastNameText = new System.Windows.Forms.TextBox();
            this.firstNameText = new System.Windows.Forms.TextBox();
            this.birthDateText = new System.Windows.Forms.TextBox();
            this.addBtn = new System.Windows.Forms.Button();
            this.deleteBtn = new System.Windows.Forms.Button();
            this.editBtn = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // cbxStudents
            // 
            this.cbxStudents.FormattingEnabled = true;
            this.cbxStudents.Location = new System.Drawing.Point(87, 88);
            this.cbxStudents.Name = "cbxStudents";
            this.cbxStudents.Size = new System.Drawing.Size(246, 21);
            this.cbxStudents.TabIndex = 0;
            this.cbxStudents.DropDown += new System.EventHandler(this.cbxStudents_DropDown);
            this.cbxStudents.SelectedIndexChanged += new System.EventHandler(this.cbxStudents_SelectedIndexChanged);
            // 
            // lastNameText
            // 
            this.lastNameText.Location = new System.Drawing.Point(573, 89);
            this.lastNameText.Name = "lastNameText";
            this.lastNameText.ReadOnly = true;
            this.lastNameText.Size = new System.Drawing.Size(188, 20);
            this.lastNameText.TabIndex = 1;
            // 
            // firstNameText
            // 
            this.firstNameText.Location = new System.Drawing.Point(573, 142);
            this.firstNameText.Name = "firstNameText";
            this.firstNameText.ReadOnly = true;
            this.firstNameText.Size = new System.Drawing.Size(188, 20);
            this.firstNameText.TabIndex = 2;
            // 
            // birthDateText
            // 
            this.birthDateText.Location = new System.Drawing.Point(573, 198);
            this.birthDateText.Name = "birthDateText";
            this.birthDateText.ReadOnly = true;
            this.birthDateText.Size = new System.Drawing.Size(188, 20);
            this.birthDateText.TabIndex = 3;
            // 
            // addBtn
            // 
            this.addBtn.Location = new System.Drawing.Point(135, 352);
            this.addBtn.Name = "addBtn";
            this.addBtn.Size = new System.Drawing.Size(75, 23);
            this.addBtn.TabIndex = 4;
            this.addBtn.Text = "Добавить студента";
            this.addBtn.UseVisualStyleBackColor = true;
            this.addBtn.Click += new System.EventHandler(this.addBtn_Click);
            // 
            // deleteBtn
            // 
            this.deleteBtn.Location = new System.Drawing.Point(258, 352);
            this.deleteBtn.Name = "deleteBtn";
            this.deleteBtn.Size = new System.Drawing.Size(75, 23);
            this.deleteBtn.TabIndex = 5;
            this.deleteBtn.Text = "Удалить";
            this.deleteBtn.UseVisualStyleBackColor = true;
            this.deleteBtn.Click += new System.EventHandler(this.deleteBtn_Click);
            // 
            // editBtn
            // 
            this.editBtn.Location = new System.Drawing.Point(396, 352);
            this.editBtn.Name = "editBtn";
            this.editBtn.Size = new System.Drawing.Size(103, 23);
            this.editBtn.TabIndex = 6;
            this.editBtn.Text = "Редактировать";
            this.editBtn.UseVisualStyleBackColor = true;
            this.editBtn.Click += new System.EventHandler(this.editBtn_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(910, 426);
            this.Controls.Add(this.editBtn);
            this.Controls.Add(this.deleteBtn);
            this.Controls.Add(this.addBtn);
            this.Controls.Add(this.birthDateText);
            this.Controls.Add(this.firstNameText);
            this.Controls.Add(this.lastNameText);
            this.Controls.Add(this.cbxStudents);
            this.Name = "Form1";
            this.Text = "Студенты";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ComboBox cbxStudents;
        private System.Windows.Forms.TextBox lastNameText;
        private System.Windows.Forms.TextBox firstNameText;
        private System.Windows.Forms.TextBox birthDateText;
        private System.Windows.Forms.Button addBtn;
        private System.Windows.Forms.Button deleteBtn;
        private System.Windows.Forms.Button editBtn;
    }
}

