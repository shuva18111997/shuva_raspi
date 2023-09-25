namespace WindowsFormsApplication1
{
    partial class MainForm
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MainForm));
            this.label1 = new System.Windows.Forms.Label();
            this.closeBtn = new System.Windows.Forms.Button();
            this.radioDate = new System.Windows.Forms.RadioButton();
            this.radioStdnt = new System.Windows.Forms.RadioButton();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.comboDept = new System.Windows.Forms.ComboBox();
            this.comboRoll = new System.Windows.Forms.ComboBox();
            this.label5 = new System.Windows.Forms.Label();
            this.first = new System.Windows.Forms.RadioButton();
            this.second = new System.Windows.Forms.RadioButton();
            this.third = new System.Windows.Forms.RadioButton();
            this.SearchBtn = new System.Windows.Forms.Button();
            this.Calendar = new System.Windows.Forms.MonthCalendar();
            this.TextName = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.Color.Red;
            this.label1.Location = new System.Drawing.Point(14, 4);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(282, 24);
            this.label1.TabIndex = 0;
            this.label1.Text = "Student\'s Attendence System";
            // 
            // closeBtn
            // 
            this.closeBtn.BackColor = System.Drawing.Color.Red;
            this.closeBtn.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.closeBtn.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.closeBtn.ForeColor = System.Drawing.Color.Black;
            this.closeBtn.Location = new System.Drawing.Point(309, -1);
            this.closeBtn.Name = "closeBtn";
            this.closeBtn.Size = new System.Drawing.Size(54, 23);
            this.closeBtn.TabIndex = 8;
            this.closeBtn.Text = "X";
            this.closeBtn.UseVisualStyleBackColor = false;
            this.closeBtn.Click += new System.EventHandler(this.closeBtn_Click);
            // 
            // radioDate
            // 
            this.radioDate.AutoSize = true;
            this.radioDate.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.radioDate.ForeColor = System.Drawing.Color.Blue;
            this.radioDate.Location = new System.Drawing.Point(12, 42);
            this.radioDate.Name = "radioDate";
            this.radioDate.Size = new System.Drawing.Size(134, 20);
            this.radioDate.TabIndex = 9;
            this.radioDate.Text = "Search By Date";
            this.radioDate.UseVisualStyleBackColor = true;
            this.radioDate.CheckedChanged += new System.EventHandler(this.radioDate_CheckedChanged);
            // 
            // radioStdnt
            // 
            this.radioStdnt.AutoSize = true;
            this.radioStdnt.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.radioStdnt.ForeColor = System.Drawing.Color.Blue;
            this.radioStdnt.Location = new System.Drawing.Point(12, 42);
            this.radioStdnt.Name = "radioStdnt";
            this.radioStdnt.Size = new System.Drawing.Size(182, 20);
            this.radioStdnt.TabIndex = 10;
            this.radioStdnt.Text = "Search By Student\'s Id";
            this.radioStdnt.UseVisualStyleBackColor = true;
            this.radioStdnt.CheckedChanged += new System.EventHandler(this.radioStdnt_CheckedChanged);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.ForeColor = System.Drawing.Color.Green;
            this.label2.Location = new System.Drawing.Point(22, 105);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(96, 13);
            this.label2.TabIndex = 11;
            this.label2.Text = "Student\'s Name";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.ForeColor = System.Drawing.Color.Green;
            this.label3.Location = new System.Drawing.Point(22, 140);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(86, 13);
            this.label3.TabIndex = 12;
            this.label3.Text = "Student\'s Roll";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.ForeColor = System.Drawing.Color.Green;
            this.label4.Location = new System.Drawing.Point(22, 172);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(91, 13);
            this.label4.TabIndex = 13;
            this.label4.Text = "Student\'s Dept";
            // 
            // comboDept
            // 
            this.comboDept.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboDept.FormattingEnabled = true;
            this.comboDept.Items.AddRange(new object[] {
            "ME",
            "CE",
            "EE",
            "ETCE"});
            this.comboDept.Location = new System.Drawing.Point(120, 170);
            this.comboDept.Name = "comboDept";
            this.comboDept.Size = new System.Drawing.Size(165, 21);
            this.comboDept.TabIndex = 16;
            this.comboDept.KeyDown += new System.Windows.Forms.KeyEventHandler(this.comboDept_KeyDown);
            // 
            // comboRoll
            // 
            this.comboRoll.FormattingEnabled = true;
            this.comboRoll.Items.AddRange(new object[] {
            "01",
            "02",
            "03",
            "04",
            "05",
            "06",
            "07",
            "08",
            "09",
            "10",
            "11",
            "12",
            "13",
            "14",
            "15",
            "16",
            "17",
            "18",
            "19",
            "20",
            "21",
            "22",
            "23",
            "24",
            "25",
            "26",
            "27",
            "28",
            "29",
            "30",
            "31",
            "32",
            "33",
            "34",
            "35",
            "36",
            "37",
            "38",
            "39",
            "40",
            "41",
            "42",
            "43",
            "44",
            "45",
            "46",
            "47",
            "48",
            "49",
            "50",
            "51",
            "52",
            "53",
            "54",
            "55",
            "56",
            "57",
            "58",
            "59",
            "60",
            "61",
            "62",
            "63"});
            this.comboRoll.Location = new System.Drawing.Point(120, 137);
            this.comboRoll.Name = "comboRoll";
            this.comboRoll.Size = new System.Drawing.Size(121, 21);
            this.comboRoll.TabIndex = 17;
            this.comboRoll.KeyDown += new System.Windows.Forms.KeyEventHandler(this.comboRoll_KeyDown);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label5.ForeColor = System.Drawing.Color.Green;
            this.label5.Location = new System.Drawing.Point(23, 201);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(90, 13);
            this.label5.TabIndex = 18;
            this.label5.Text = "Student\'s Year";
            // 
            // first
            // 
            this.first.AutoSize = true;
            this.first.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.first.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(0)))), ((int)(((byte)(192)))));
            this.first.Location = new System.Drawing.Point(118, 201);
            this.first.Name = "first";
            this.first.Size = new System.Drawing.Size(49, 17);
            this.first.TabIndex = 19;
            this.first.Text = "First";
            this.first.UseVisualStyleBackColor = true;
            this.first.KeyDown += new System.Windows.Forms.KeyEventHandler(this.first_KeyDown);
            // 
            // second
            // 
            this.second.AutoSize = true;
            this.second.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.second.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(0)))), ((int)(((byte)(192)))));
            this.second.Location = new System.Drawing.Point(163, 201);
            this.second.Name = "second";
            this.second.Size = new System.Drawing.Size(68, 17);
            this.second.TabIndex = 20;
            this.second.Text = "Second";
            this.second.UseVisualStyleBackColor = true;
            this.second.KeyDown += new System.Windows.Forms.KeyEventHandler(this.second_KeyDown);
            // 
            // third
            // 
            this.third.AutoSize = true;
            this.third.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.third.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(0)))), ((int)(((byte)(192)))));
            this.third.Location = new System.Drawing.Point(228, 201);
            this.third.Name = "third";
            this.third.Size = new System.Drawing.Size(54, 17);
            this.third.TabIndex = 21;
            this.third.Text = "Third";
            this.third.UseVisualStyleBackColor = true;
            this.third.KeyDown += new System.Windows.Forms.KeyEventHandler(this.third_KeyDown);
            // 
            // SearchBtn
            // 
            this.SearchBtn.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(192)))), ((int)(((byte)(0)))));
            this.SearchBtn.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.SearchBtn.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.SearchBtn.ForeColor = System.Drawing.Color.Black;
            this.SearchBtn.Location = new System.Drawing.Point(149, 229);
            this.SearchBtn.Name = "SearchBtn";
            this.SearchBtn.Size = new System.Drawing.Size(75, 23);
            this.SearchBtn.TabIndex = 22;
            this.SearchBtn.Text = "Search";
            this.SearchBtn.UseVisualStyleBackColor = false;
            this.SearchBtn.Click += new System.EventHandler(this.SearchBtn_Click);
            // 
            // Calendar
            // 
            this.Calendar.Location = new System.Drawing.Point(80, 63);
            this.Calendar.Name = "Calendar";
            this.Calendar.TabIndex = 23;
            this.Calendar.KeyDown += new System.Windows.Forms.KeyEventHandler(this.Calendar_KeyDown);
            // 
            // TextName
            // 
            this.TextName.Location = new System.Drawing.Point(120, 105);
            this.TextName.Name = "TextName";
            this.TextName.Size = new System.Drawing.Size(221, 20);
            this.TextName.TabIndex = 14;
            this.TextName.KeyDown += new System.Windows.Forms.KeyEventHandler(this.TextName_KeyDown);
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label6.ForeColor = System.Drawing.Color.Red;
            this.label6.Location = new System.Drawing.Point(101, 72);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(181, 20);
            this.label6.TabIndex = 24;
            this.label6.Text = "Type Student\'s Detail";
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(128)))), ((int)(((byte)(255)))), ((int)(((byte)(128)))));
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.ClientSize = new System.Drawing.Size(362, 264);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.Calendar);
            this.Controls.Add(this.SearchBtn);
            this.Controls.Add(this.third);
            this.Controls.Add(this.second);
            this.Controls.Add(this.first);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.comboRoll);
            this.Controls.Add(this.comboDept);
            this.Controls.Add(this.TextName);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.radioStdnt);
            this.Controls.Add(this.radioDate);
            this.Controls.Add(this.closeBtn);
            this.Controls.Add(this.label1);
            this.ForeColor = System.Drawing.Color.Green;
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "MainForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "MainForm";
            this.Load += new System.EventHandler(this.MainForm_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button closeBtn;
        private System.Windows.Forms.RadioButton radioDate;
        private System.Windows.Forms.RadioButton radioStdnt;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.ComboBox comboDept;
        private System.Windows.Forms.ComboBox comboRoll;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.RadioButton first;
        private System.Windows.Forms.RadioButton second;
        private System.Windows.Forms.RadioButton third;
        private System.Windows.Forms.Button SearchBtn;
        private System.Windows.Forms.MonthCalendar Calendar;
        private System.Windows.Forms.TextBox TextName;
        private System.Windows.Forms.Label label6;
    }
}