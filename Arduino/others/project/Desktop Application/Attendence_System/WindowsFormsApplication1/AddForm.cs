using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using MySql.Data.MySqlClient;

namespace WindowsFormsApplication1
{
    public partial class AddForm : Form
    {
        private string date;

        public AddForm()
        {
            InitializeComponent();
        }

        private void closeBtn_Click(object sender, EventArgs e)
        {
            System.Windows.Forms.Application.Exit();
        }

        private void BackBtn_Click(object sender, EventArgs e)
        {
            DateMonthDisplay dms = new DateMonthDisplay();
            dms.Show();
            this.Hide();
        }

        private void AddForm_Load(object sender, EventArgs e)
        {
            NameText.Select();
            date = dateTimePicker1.Text;
        }

        private void NameText_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                if (NameText.Text != "")
                {
                    RollText.Select();
                }
                else
                {
                    MessageBox.Show("Name must be filled");
                    NameText.Select();
                }
            }
        }

        private void RollText_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                if (RollText.Text != "")
                {
                    DeptText.Select();
                }
                else
                {
                    MessageBox.Show("Roll must be filled");
                    RollText.Select();
                }
            }
        }

        private void DeptText_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                if (DeptText.Text != "")
                {
                    YearText.Select();
                }
                else
                {
                    MessageBox.Show("Dept must be filled");
                    DeptText.Select();
                }
            }
        }

        private void YearText_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                if (YearText.Text != "")
                {
                    dateTimePicker1.Select();
                }
                else
                {
                    MessageBox.Show("Year must be filled");
                    YearText.Select();
                }
            }
        }

        private void dateTimePicker1_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                if (date!="")
                {
                    SubmitBtn.PerformClick();
                }
                else
                {
                    MessageBox.Show("Year must be filled");
                    dateTimePicker1.Select();
                }
            }
        }

        private void SubmitBtn_Click(object sender, EventArgs e)
        {
            if (NameCheck() && RollCheck() && DeptCheck() && YearCheck() && DateCheck())
            {
                if (LastCheckShuva() || LastCheckkoushik() || LastCheckkunal())
                {
                    /*Querry here*/
                    //////////////////////////////////////////////////////////
                    try
                    {
                        string connString = "data source=localhost;port=3306;username=root;password=;database=attendence_system;";
                        MySqlConnection dbConn = new MySqlConnection(connString);
                        dbConn.Open();
                        string insertQuery = "INSERT INTO rkmsm(roll,name,dept,year,time)VALUES('" + RollText.Text + "','" + NameText.Text + "','" + DeptText.Text + "','" + YearText.Text + "','" + NewDate() + "')";
                        MySqlCommand sc = new MySqlCommand(insertQuery, dbConn);
                        int row = sc.ExecuteNonQuery();
                        if (row > 0)
                        {
                            MessageBox.Show("Data has been Inserted");
                            DateMonthDisplay ds = new DateMonthDisplay();
                            ds.Show();
                            this.Hide();
                        }
                        else
                        {
                            MessageBox.Show("Data Not Inserted");
                        }
                    }
                    catch (Exception ex)
                    {
                        MessageBox.Show("Database Problem");
                    }
                    //////////////////////////////////////////////////////////
                }
                else
                {
                    MessageBox.Show("some data is wrong");
                }
            }
        }

        private bool NameCheck()
        {
            string name = NameText.Text.ToLower();
            if (name == "shuvabrata dey" || name == "koushik bhadra" || name == "kunal mukherjee")
            {
                return true;
            }
            else
            {
                MessageBox.Show("Invalid Name!!!");
                NameText.Focus();
                return false;
            }
        }
        private bool RollCheck()
        {
            if (RollText.Text!="")
            {
                return true;
            }
            else
            {
                MessageBox.Show("Enter Roll");
                RollText.Focus();
                return false;
            }
        }
        private bool DeptCheck()
        {
            string dept = DeptText.Text.ToLower();
            if (dept=="etce")
            {
                return true;
            }
            else
            {
                MessageBox.Show("Invaid Dept");
                DeptText.Focus();
                return false;
            }
        }
        private bool YearCheck()
        {
            if (YearText.Text!="")
            {
                return true;
            }
            else
            {
                MessageBox.Show("Invalid Year");
                YearText.Focus();
                return false;
            }
        }

        private bool DateCheck()
        {
            if (date!="")
            {
                return true;
            }
            else
            {
                MessageBox.Show("Please Select a Date.");
                return false;
            }
        }

        public string NewDate()
        {
            string Date = "";
            char splitchar = '/';
            string[] strArr = date.Split(splitchar);
            Date = strArr[2] + "-" + strArr[0] + "-" + strArr[1] + " 09:30:00";// 03/10/2018 --> 2018-03-10 09:30:00
            return Date;
        }

        private void dateTimePicker1_ValueChanged(object sender, EventArgs e)
        {
            date = dateTimePicker1.Text.ToString();
        }
        private bool LastCheckShuva()
        {
            string name = NameText.Text.ToLower();
            string dept = DeptText.Text.ToLower();
            int roll = Convert.ToInt32(RollText.Text);
            if (name == "shuvabrata dey" && roll==7 && dept == "etce" && YearText.Text == "3")
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        private bool LastCheckkoushik()
        {
            string name = NameText.Text.ToLower();
            string dept = DeptText.Text.ToLower();
            int roll = Convert.ToInt32(RollText.Text);
            if (name == "koushik bhadra" && roll == 8 && dept == "etce" && YearText.Text == "3")
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        private bool LastCheckkunal()
        {
            string name = NameText.Text.ToLower();
            string dept = DeptText.Text.ToLower();
            int roll = Convert.ToInt32(RollText.Text);
            if (name == "kunal mukherjee" && roll==9 && dept == "etce" && YearText.Text == "3")
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}
