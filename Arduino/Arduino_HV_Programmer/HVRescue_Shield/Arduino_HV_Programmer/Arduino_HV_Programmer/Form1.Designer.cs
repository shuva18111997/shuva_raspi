namespace Arduino_HV_Programmer
{
    partial class HV_Programmer
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(HV_Programmer));
            this.serialPort = new System.IO.Ports.SerialPort(this.components);
            this.button1 = new System.Windows.Forms.Button();
            this.comboBox1 = new System.Windows.Forms.ComboBox();
            this.comboBox2 = new System.Windows.Forms.ComboBox();
            this.label1 = new System.Windows.Forms.Label();
            this.button2 = new System.Windows.Forms.Button();
            this.HFuse_textBox = new System.Windows.Forms.TextBox();
            this.LFuse_textBox = new System.Windows.Forms.TextBox();
            this.EFuse_textBox = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.write_btn = new System.Windows.Forms.Button();
            this.read_btn = new System.Windows.Forms.Button();
            this.check_btn = new System.Windows.Forms.Button();
            this.connection_check_btn = new System.Windows.Forms.Button();
            this.default_btn = new System.Windows.Forms.Button();
            this.HFuse_Update = new System.Windows.Forms.Button();
            this.LFuse_Update = new System.Windows.Forms.Button();
            this.EFuse_Update = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // button1
            // 
            this.button1.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button1.Location = new System.Drawing.Point(154, 15);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(108, 32);
            this.button1.TabIndex = 1;
            this.button1.Text = "Connect";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // comboBox1
            // 
            this.comboBox1.FormattingEnabled = true;
            this.comboBox1.Location = new System.Drawing.Point(30, 19);
            this.comboBox1.Name = "comboBox1";
            this.comboBox1.Size = new System.Drawing.Size(103, 24);
            this.comboBox1.TabIndex = 2;
            // 
            // comboBox2
            // 
            this.comboBox2.FormattingEnabled = true;
            this.comboBox2.Location = new System.Drawing.Point(10, 85);
            this.comboBox2.Name = "comboBox2";
            this.comboBox2.Size = new System.Drawing.Size(164, 24);
            this.comboBox2.TabIndex = 3;
            this.comboBox2.SelectedValueChanged += new System.EventHandler(this.comboBox2_SelectedValueChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(9, 62);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(113, 17);
            this.label1.TabIndex = 4;
            this.label1.Text = "Chose Controller";
            // 
            // button2
            // 
            this.button2.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button2.Location = new System.Drawing.Point(292, 15);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(63, 32);
            this.button2.TabIndex = 5;
            this.button2.Text = "Scan";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // HFuse_textBox
            // 
            this.HFuse_textBox.Location = new System.Drawing.Point(207, 85);
            this.HFuse_textBox.Name = "HFuse_textBox";
            this.HFuse_textBox.Size = new System.Drawing.Size(100, 22);
            this.HFuse_textBox.TabIndex = 6;
            // 
            // LFuse_textBox
            // 
            this.LFuse_textBox.Location = new System.Drawing.Point(333, 85);
            this.LFuse_textBox.Name = "LFuse_textBox";
            this.LFuse_textBox.Size = new System.Drawing.Size(100, 22);
            this.LFuse_textBox.TabIndex = 7;
            // 
            // EFuse_textBox
            // 
            this.EFuse_textBox.Location = new System.Drawing.Point(453, 85);
            this.EFuse_textBox.Name = "EFuse_textBox";
            this.EFuse_textBox.Size = new System.Drawing.Size(100, 22);
            this.EFuse_textBox.TabIndex = 8;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(212, 62);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(49, 17);
            this.label2.TabIndex = 9;
            this.label2.Text = "HFuse";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(338, 62);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(52, 17);
            this.label3.TabIndex = 10;
            this.label3.Text = "LFUSE";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(458, 62);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(53, 17);
            this.label4.TabIndex = 11;
            this.label4.Text = "EFUSE";
            // 
            // write_btn
            // 
            this.write_btn.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.write_btn.Location = new System.Drawing.Point(240, 170);
            this.write_btn.Name = "write_btn";
            this.write_btn.Size = new System.Drawing.Size(63, 32);
            this.write_btn.TabIndex = 12;
            this.write_btn.Text = "Write";
            this.write_btn.UseVisualStyleBackColor = true;
            this.write_btn.Click += new System.EventHandler(this.write_btn_Click);
            // 
            // read_btn
            // 
            this.read_btn.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.read_btn.Location = new System.Drawing.Point(338, 170);
            this.read_btn.Name = "read_btn";
            this.read_btn.Size = new System.Drawing.Size(63, 32);
            this.read_btn.TabIndex = 13;
            this.read_btn.Text = "Read";
            this.read_btn.UseVisualStyleBackColor = true;
            this.read_btn.Click += new System.EventHandler(this.read_btn_Click);
            // 
            // check_btn
            // 
            this.check_btn.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.check_btn.Location = new System.Drawing.Point(42, 115);
            this.check_btn.Name = "check_btn";
            this.check_btn.Size = new System.Drawing.Size(60, 32);
            this.check_btn.TabIndex = 14;
            this.check_btn.Text = "Set";
            this.check_btn.UseVisualStyleBackColor = true;
            this.check_btn.Click += new System.EventHandler(this.check_btn_Click);
            // 
            // connection_check_btn
            // 
            this.connection_check_btn.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.connection_check_btn.Location = new System.Drawing.Point(393, 8);
            this.connection_check_btn.Name = "connection_check_btn";
            this.connection_check_btn.Size = new System.Drawing.Size(155, 47);
            this.connection_check_btn.TabIndex = 15;
            this.connection_check_btn.Text = "Connection Check";
            this.connection_check_btn.UseVisualStyleBackColor = true;
            this.connection_check_btn.Click += new System.EventHandler(this.connection_check_btn_Click);
            // 
            // default_btn
            // 
            this.default_btn.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.default_btn.Location = new System.Drawing.Point(119, 170);
            this.default_btn.Name = "default_btn";
            this.default_btn.Size = new System.Drawing.Size(82, 32);
            this.default_btn.TabIndex = 16;
            this.default_btn.Text = "Default";
            this.default_btn.UseVisualStyleBackColor = true;
            this.default_btn.Click += new System.EventHandler(this.default_btn_Click);
            // 
            // HFuse_Update
            // 
            this.HFuse_Update.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.HFuse_Update.Location = new System.Drawing.Point(214, 113);
            this.HFuse_Update.Name = "HFuse_Update";
            this.HFuse_Update.Size = new System.Drawing.Size(86, 32);
            this.HFuse_Update.TabIndex = 17;
            this.HFuse_Update.Text = "Update";
            this.HFuse_Update.UseVisualStyleBackColor = true;
            this.HFuse_Update.Click += new System.EventHandler(this.HFuse_Update_Click);
            // 
            // LFuse_Update
            // 
            this.LFuse_Update.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.LFuse_Update.Location = new System.Drawing.Point(341, 113);
            this.LFuse_Update.Name = "LFuse_Update";
            this.LFuse_Update.Size = new System.Drawing.Size(86, 32);
            this.LFuse_Update.TabIndex = 18;
            this.LFuse_Update.Text = "Update";
            this.LFuse_Update.UseVisualStyleBackColor = true;
            this.LFuse_Update.Click += new System.EventHandler(this.LFuse_Update_Click);
            // 
            // EFuse_Update
            // 
            this.EFuse_Update.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.EFuse_Update.Location = new System.Drawing.Point(461, 113);
            this.EFuse_Update.Name = "EFuse_Update";
            this.EFuse_Update.Size = new System.Drawing.Size(86, 32);
            this.EFuse_Update.TabIndex = 19;
            this.EFuse_Update.Text = "Update";
            this.EFuse_Update.UseVisualStyleBackColor = true;
            this.EFuse_Update.Click += new System.EventHandler(this.EFuse_Update_Click);
            // 
            // button3
            // 
            this.button3.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button3.Location = new System.Drawing.Point(422, 163);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(125, 47);
            this.button3.TabIndex = 20;
            this.button3.Text = "Save Fuses";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.button3_Click);
            // 
            // HV_Programmer
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(567, 230);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.EFuse_Update);
            this.Controls.Add(this.LFuse_Update);
            this.Controls.Add(this.HFuse_Update);
            this.Controls.Add(this.default_btn);
            this.Controls.Add(this.connection_check_btn);
            this.Controls.Add(this.check_btn);
            this.Controls.Add(this.read_btn);
            this.Controls.Add(this.write_btn);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.EFuse_textBox);
            this.Controls.Add(this.LFuse_textBox);
            this.Controls.Add(this.HFuse_textBox);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.comboBox2);
            this.Controls.Add(this.comboBox1);
            this.Controls.Add(this.button1);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "HV_Programmer";
            this.Text = "HV_Programmer";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.IO.Ports.SerialPort serialPort;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.ComboBox comboBox1;
        private System.Windows.Forms.ComboBox comboBox2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.TextBox HFuse_textBox;
        private System.Windows.Forms.TextBox LFuse_textBox;
        private System.Windows.Forms.TextBox EFuse_textBox;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Button write_btn;
        private System.Windows.Forms.Button read_btn;
        private System.Windows.Forms.Button check_btn;
        private System.Windows.Forms.Button connection_check_btn;
        private System.Windows.Forms.Button default_btn;
        private System.Windows.Forms.Button HFuse_Update;
        private System.Windows.Forms.Button LFuse_Update;
        private System.Windows.Forms.Button EFuse_Update;
        private System.Windows.Forms.Button button3;
    }
}

