
namespace KondrikovOOPP6
{
    partial class AddDialog
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
            this.scholarshipText = new System.Windows.Forms.TextBox();
            this.ageText = new System.Windows.Forms.TextBox();
            this.nameText = new System.Windows.Forms.TextBox();
            this.surnameText = new System.Windows.Forms.TextBox();
            this.hasJournalCheck = new System.Windows.Forms.CheckBox();
            this.isHeadmanCheck = new System.Windows.Forms.CheckBox();
            this.ageLabel = new System.Windows.Forms.Label();
            this.scholarshipLabel = new System.Windows.Forms.Label();
            this.AddFinalButton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // scholarshipText
            // 
            this.scholarshipText.Location = new System.Drawing.Point(147, 230);
            this.scholarshipText.Name = "scholarshipText";
            this.scholarshipText.Size = new System.Drawing.Size(73, 22);
            this.scholarshipText.TabIndex = 10;
            this.scholarshipText.Text = "0";
            // 
            // ageText
            // 
            this.ageText.Location = new System.Drawing.Point(131, 145);
            this.ageText.Name = "ageText";
            this.ageText.Size = new System.Drawing.Size(89, 22);
            this.ageText.TabIndex = 8;
            this.ageText.Text = "0";
            // 
            // nameText
            // 
            this.nameText.Location = new System.Drawing.Point(66, 104);
            this.nameText.Name = "nameText";
            this.nameText.Size = new System.Drawing.Size(154, 22);
            this.nameText.TabIndex = 7;
            this.nameText.Text = "Имя";
            // 
            // surnameText
            // 
            this.surnameText.Location = new System.Drawing.Point(66, 62);
            this.surnameText.Name = "surnameText";
            this.surnameText.Size = new System.Drawing.Size(154, 22);
            this.surnameText.TabIndex = 6;
            this.surnameText.Text = "Фамилия";
            // 
            // hasJournalCheck
            // 
            this.hasJournalCheck.AutoSize = true;
            this.hasJournalCheck.Location = new System.Drawing.Point(75, 188);
            this.hasJournalCheck.Name = "hasJournalCheck";
            this.hasJournalCheck.Size = new System.Drawing.Size(136, 21);
            this.hasJournalCheck.TabIndex = 11;
            this.hasJournalCheck.Text = "Журнал с собой";
            this.hasJournalCheck.UseVisualStyleBackColor = true;
            // 
            // isHeadmanCheck
            // 
            this.isHeadmanCheck.AutoSize = true;
            this.isHeadmanCheck.Location = new System.Drawing.Point(98, 23);
            this.isHeadmanCheck.Name = "isHeadmanCheck";
            this.isHeadmanCheck.Size = new System.Drawing.Size(92, 21);
            this.isHeadmanCheck.TabIndex = 12;
            this.isHeadmanCheck.Text = "Староста";
            this.isHeadmanCheck.UseVisualStyleBackColor = true;
            this.isHeadmanCheck.CheckedChanged += new System.EventHandler(this.isHeadmanCheck_CheckedChanged);
            // 
            // ageLabel
            // 
            this.ageLabel.AutoSize = true;
            this.ageLabel.Location = new System.Drawing.Point(63, 148);
            this.ageLabel.Name = "ageLabel";
            this.ageLabel.Size = new System.Drawing.Size(62, 17);
            this.ageLabel.TabIndex = 13;
            this.ageLabel.Text = "Возраст";
            // 
            // scholarshipLabel
            // 
            this.scholarshipLabel.AutoSize = true;
            this.scholarshipLabel.Location = new System.Drawing.Point(63, 233);
            this.scholarshipLabel.Name = "scholarshipLabel";
            this.scholarshipLabel.Size = new System.Drawing.Size(80, 17);
            this.scholarshipLabel.TabIndex = 14;
            this.scholarshipLabel.Text = "Стипендия";
            // 
            // AddFinalButton
            // 
            this.AddFinalButton.Location = new System.Drawing.Point(98, 276);
            this.AddFinalButton.Name = "AddFinalButton";
            this.AddFinalButton.Size = new System.Drawing.Size(75, 23);
            this.AddFinalButton.TabIndex = 15;
            this.AddFinalButton.Text = "Oк";
            this.AddFinalButton.UseVisualStyleBackColor = true;
            this.AddFinalButton.Click += new System.EventHandler(this.AddFinalButton_Click);
            // 
            // AddDialog
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(287, 323);
            this.Controls.Add(this.AddFinalButton);
            this.Controls.Add(this.scholarshipLabel);
            this.Controls.Add(this.ageLabel);
            this.Controls.Add(this.isHeadmanCheck);
            this.Controls.Add(this.hasJournalCheck);
            this.Controls.Add(this.scholarshipText);
            this.Controls.Add(this.ageText);
            this.Controls.Add(this.nameText);
            this.Controls.Add(this.surnameText);
            this.Name = "AddDialog";
            this.Text = "AddDialog";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox scholarshipText;
        private System.Windows.Forms.TextBox ageText;
        private System.Windows.Forms.TextBox nameText;
        private System.Windows.Forms.TextBox surnameText;
        private System.Windows.Forms.CheckBox hasJournalCheck;
        private System.Windows.Forms.CheckBox isHeadmanCheck;
        private System.Windows.Forms.Label ageLabel;
        private System.Windows.Forms.Label scholarshipLabel;
        private System.Windows.Forms.Button AddFinalButton;
    }
}