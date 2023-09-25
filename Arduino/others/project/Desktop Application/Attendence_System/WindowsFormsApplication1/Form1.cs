using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        private string user = "RKMSM";
        private string pass = "1234";

        public Form1()
        {
            InitializeComponent();
        }

        private void closeBtn_Click(object sender, EventArgs e)
        {
            System.Windows.Forms.Application.Exit();
        }

        private void submitBtn_Click(object sender, EventArgs e)
        {
            if (UserName.Text != "" && Password.Text != "")
            {
                if (UserName.Text == user && Password.Text == pass)
                {
                    this.Hide();
                    MainForm mainform = new MainForm();
                    mainform.Show();
                }
                else
                {
                    MessageBox.Show("wrong UserName or Password!!!");
                }
            }
            else
            {
                MessageBox.Show("TextBoxs must be filled!!!");
            }
        }

        private void UserName_TextChanged(object sender, EventArgs e)
        {
            string pattern = "[^a-zA-Z]";
            if (Regex.IsMatch(UserName.Text, pattern))
            {
                MessageBox.Show("Please Don't Enter any number or special char");
            } 
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            UserName.Select();
        }

        private void UserName_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                if (UserName.Text != "")
                {
                    Password.Select();
                }
                else
                {
                    MessageBox.Show("User Name must be filled");
                    UserName.Select();
                }
            }
        }

        private void Password_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                if (UserName.Text != "")
                {
                    submitBtn.PerformClick();
                }
                else
                {
                    MessageBox.Show("password must be filled");
                    Password.Select();
                }
            }
        }
    }
}
