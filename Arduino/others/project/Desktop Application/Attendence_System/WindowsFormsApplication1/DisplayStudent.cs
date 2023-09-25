using MySql.Data.MySqlClient;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;


namespace WindowsFormsApplication1
{
    public partial class DisplayStudent : Form
    {
        
        public DisplayStudent()
        {
            InitializeComponent();
        }

        private void closeBtn_Click(object sender, EventArgs e)
        {
            System.Windows.Forms.Application.Exit();
        }

        private void backBtn(object sender, EventArgs e)
        {
            MainForm mainnform = new MainForm();
            mainnform.Show();
            this.Hide();
        }

        private void DisplayStudent_Load(object sender, EventArgs e)
        {
            if (InitCheck()==7)
            {
                pictureBox1.Image = Properties.Resources.IMG_20160124_00021;
                LoadInit();
                datagrid();
            }
            else if (InitCheck() == 8)
            {
                pictureBox1.Image = Properties.Resources.IMG_20180312_WA0001;//Bhadra's Image
                LoadInit();
                datagrid();
            }
            else if (InitCheck() == 9)
            {
                pictureBox1.Image = Properties.Resources._6f0632c3_955e_4c14_9fa9_6cfa14b726cc;//Kunal's Image
                LoadInit();
                datagrid();
            }
            else
            {
                NoDataFound();
                BackBtn.Select();
            }
        }

        private void LoadInit()
        {
            labelNodataFound.Hide();
            NameLable.Text = DaoPojo.name;
            RollLable.Text = DaoPojo.roll.ToString();
            DeptLable.Text = DaoPojo.dept;
            if (DaoPojo.year==1)
            {
                YearLable.Text = "1st";
            }
            if (DaoPojo.year == 2)
            {
                YearLable.Text = "2nd";
            }
            if (DaoPojo.year == 3)
            {
                YearLable.Text = "3rd";
            }
        }

        private void datagrid()
        {
            string connString = "data source=localhost;port=3306;username=root;password=;database=attendence_system;";
            MySqlConnection dbConn = new MySqlConnection(connString);

            string selectQuery = "SELECT time FROM rkmsm WHERE roll= " + DaoPojo.roll.ToString() +" And dept= '"+DaoPojo.dept+"' And year= "+DaoPojo.year.ToString();
            MySqlDataAdapter sda = new MySqlDataAdapter(selectQuery, dbConn);
            try
            {
                dbConn.Open();
                DataSet ds = new DataSet();
                sda.Fill(ds);
                DataTable dt = new DataTable();
                dt = ds.Tables[0];

                dataGridView1.DataSource = dt;
            }
            catch (Exception ex)
            {
                MessageBox.Show("Database Is Not Connected");
            }
        }
        private void NoDataFound()
        {
            pictureBox1.Hide();
            label1.Hide();
            label3.Hide();
            label5.Hide();
            label7.Hide();
            dataGridView1.Hide();
            MessageBox.Show("No Student Information Found In Database");
            labelNodataFound.Show();
        }
        private int InitCheck()
        {
            string name = DaoPojo.name.ToLower();
            string dept = DaoPojo.dept.ToLower();
            if (name=="shuvabrata dey"&&DaoPojo.roll==7&&dept=="etce"&&DaoPojo.year==3)
            {
                return 7;
            }
            else if (name == "koushik bhadra" && DaoPojo.roll == 8 && dept == "etce" && DaoPojo.year == 3)
            {
                return 8;
            }
            else if (name == "kunal mukherjee" && DaoPojo.roll == 9 && dept == "etce" && DaoPojo.year == 3)
            {
                return 9;
            }
            else
            {
                return 0;
            }
        }
    }
}
