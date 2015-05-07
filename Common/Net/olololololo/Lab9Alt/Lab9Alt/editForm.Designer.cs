namespace Lab9Alt {
    partial class EditForm {
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
            this.editBtn = new System.Windows.Forms.Button();
            this.firstNameText = new System.Windows.Forms.TextBox();
            this.lastNameText = new System.Windows.Forms.TextBox();
            this.calendar = new System.Windows.Forms.MonthCalendar();
            this.SuspendLayout();
            // 
            // editBtn
            // 
            this.editBtn.Location = new System.Drawing.Point(227, 357);
            this.editBtn.Name = "editBtn";
            this.editBtn.Size = new System.Drawing.Size(75, 23);
            this.editBtn.TabIndex = 0;
            this.editBtn.Text = "Изменить";
            this.editBtn.UseVisualStyleBackColor = true;
            this.editBtn.Click += new System.EventHandler(this.editBtn_Click);
            // 
            // firstNameText
            // 
            this.firstNameText.Location = new System.Drawing.Point(196, 135);
            this.firstNameText.Name = "firstNameText";
            this.firstNameText.Size = new System.Drawing.Size(166, 20);
            this.firstNameText.TabIndex = 1;
            // 
            // lastNameText
            // 
            this.lastNameText.Location = new System.Drawing.Point(196, 94);
            this.lastNameText.Name = "lastNameText";
            this.lastNameText.Size = new System.Drawing.Size(166, 20);
            this.lastNameText.TabIndex = 2;
            // 
            // calendar
            // 
            this.calendar.Location = new System.Drawing.Point(196, 179);
            this.calendar.Name = "calendar";
            this.calendar.TabIndex = 3;
            // 
            // EditForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(573, 406);
            this.Controls.Add(this.calendar);
            this.Controls.Add(this.lastNameText);
            this.Controls.Add(this.firstNameText);
            this.Controls.Add(this.editBtn);
            this.Name = "EditForm";
            this.Text = "Редактирование";
            this.Load += new System.EventHandler(this.EditForm_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button editBtn;
        private System.Windows.Forms.TextBox firstNameText;
        private System.Windows.Forms.TextBox lastNameText;
        private System.Windows.Forms.MonthCalendar calendar;
        public int studentId;
    }
}