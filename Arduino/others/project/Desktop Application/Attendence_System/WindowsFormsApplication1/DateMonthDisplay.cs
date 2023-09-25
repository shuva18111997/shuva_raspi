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
    public partial class DateMonthDisplay : Form
    {
        int id;
        public DateMonthDisplay()
        {
            InitializeComponent();
        }

        private void closeBtn_Click(object sender, EventArgs e)
        {
            System.Windows.Forms.Application.Exit();
        }

        private void BackBtn_Click(object sender, EventArgs e)
        {
            MainForm mainnform = new MainForm();
            mainnform.Show();
            this.Hide();
        }

        private void DateMonthDisplay_Load(object sender, EventArgs e)
        {
            try
            {
                string connString = "data source=localhost;port=3306;username=root;password=;database=attendence_system;";
                MySqlConnection dbConn = new MySqlConnection(connString);

                string selectQuery = "SELECT * FROM rkmsm Where time BETWEEN '" + DaoPojo.NewDate() + " 00:00:00' AND '" + DaoPojo.NewDate() + " 23:59:59'";
                MySqlDataAdapter sda = new MySqlDataAdapter(selectQuery, dbConn);
                DataSet ds = new DataSet();
                sda.Fill(ds);
                DataTable dt = new DataTable();
                dt = ds.Tables[0];
                dataGrid.DataSource = dt;
                dataGrid.Columns[0].Visible = false;
            }
            catch (Exception ex)
            {
                MessageBox.Show("Unable to Connect with Database");
            }
        }

        private void SubmitBtn_Click(object sender, EventArgs e)
        {
            if (NameText.Text!="" && RollText.Text!="" && DeptText.Text!="" && YearText.Text!="")
            {
                DaoPojo.name = NameText.Text;
                DaoPojo.roll = Convert.ToInt32(RollText.Text);
                DaoPojo.dept = DeptText.Text;
                DaoPojo.year = Convert.ToInt32(YearText.Text);
                DisplayStudent dspstu = new DisplayStudent();
                dspstu.Show();
                this.Hide();
            }
        }

        private void dataGrid_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            id=Convert.ToInt32(dataGrid[0, e.RowIndex].Value.ToString());
            NameText.Text = dataGrid[2, e.RowIndex].Value.ToString();
            RollText.Text = dataGrid[1, e.RowIndex].Value.ToString();
            DeptText.Text = dataGrid[3, e.RowIndex].Value.ToString();
            YearText.Text = dataGrid[4, e.RowIndex].Value.ToString();
        }

        private bool deleteMsg()
        {
            DialogResult result = MessageBox.Show("Are You Sure?", "Warning", MessageBoxButtons.YesNo, MessageBoxIcon.Warning);
            if (result == DialogResult.Yes)
            {
                return true;
            }
            else if (result == DialogResult.No)
            {
                return false;
            }
            else
            {
                return false;
            }
        }

        private void DeleteBtn_Click(object sender, EventArgs e)
        {
            if(NameText.Text!="")
            if (deleteMsg())
            {
                try
                {
                    string connString = "data source=localhost;port=3306;username=root;password=;database=attendence_system;";
                    MySqlConnection dbConn = new MySqlConnection(connString);
                    dbConn.Open();
                    string updateQuery = "Delete FROM rkmsm Where id=" + id;

                    MySqlCommand sc = new MySqlCommand(updateQuery, dbConn);
                    int row = sc.ExecuteNonQuery();
                    if (row > 0)
                    {
                        string selectQuery = "SELECT * FROM rkmsm Where time BETWEEN '" + DaoPojo.NewDate() + " 00:00:00' AND '" + DaoPojo.NewDate() + " 23:59:59'";
                        MySqlDataAdapter sda = new MySqlDataAdapter(selectQuery, dbConn);

                        DataSet ds = new DataSet();
                        sda.Fill(ds);
                        DataTable dt = new DataTable();
                        dt = ds.Tables[0];

                        dataGrid.DataSource = dt;
                    }
                    else
                    {
                        MessageBox.Show("Not Deleted");
                    }
                    dbConn.Close();
                    NameText.Clear();
                    RollText.Clear();
                    DeptText.Clear();
                    YearText.Clear();
                }
                catch (Exception ex)
                {
                    MessageBox.Show("Can't Deleted");
                }
            }
        }

        private void AddBtn_Click(object sender, EventArgs e)
        {
            AddForm ad = new AddForm();
            ad.Show();
            this.Hide();
        }
    }
}