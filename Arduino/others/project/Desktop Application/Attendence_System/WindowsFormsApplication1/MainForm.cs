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
    public partial class MainForm : Form
    {
        
        private bool state = false;

        public MainForm()
        {
            InitializeComponent();
        }

        private void MainForm_Load(object sender, EventArgs e)
        {
            StudentIdHide();
            Calendar.Select();
        }

        private void closeBtn_Click(object sender, EventArgs e)
        {
            System.Windows.Forms.Application.Exit();
        }

        private void radioDate_CheckedChanged(object sender, EventArgs e)
        {
            state = false;
            StudentIdHide();
            Calendar.Select();
            DateShow();
        }
        private void radioStdnt_CheckedChanged(object sender, EventArgs e)
        {
            state = true;
            StudentIdShow();
            TextName.Select();
            first.Checked = true;
            DateHide();
        }
        private void StudentIdHide()
        {
            radioStdnt.Show();
            label2.Hide();
            label3.Hide();
            label4.Hide();
            label5.Hide();
            label6.Hide();
            TextName.Hide();
            comboDept.Hide();
            comboRoll.Hide();
            first.Hide(); second.Hide(); third.Hide();
        }
        private void StudentIdShow()
        {
            radioStdnt.Hide();
            label2.Show();
            label3.Show();
            label4.Show();
            label5.Show();
            label6.Show();
            TextName.Show();
            comboDept.Show();
            comboRoll.Show();
            first.Show(); second.Show(); third.Show();
        }
        private void DateHide()
        {
            radioDate.Show();
            Calendar.Hide();
        }
        private void DateShow()
        {
            radioDate.Hide();
            Calendar.Show();
        }

        private void TextName_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode==Keys.Enter)
            {
                if (TextName.Text!="")
                {
                    comboRoll.Select();
                }
                else
                {
                    MessageBox.Show("Name must be filled");
                    TextName.Select();
                }
            }
        }

        private void comboRoll_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                comboDept.Select();
            }
        }

        private void comboDept_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                first.Select();
            }
        }

        private void first_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                SearchBtn.PerformClick();
            }
        }

        private void second_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                SearchBtn.PerformClick();
            }
        }

        private void third_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                SearchBtn.PerformClick();
            }
        }

        private void Calendar_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                SearchBtn.PerformClick();
            }
        }

        private void SearchBtn_Click(object sender, EventArgs e)
        {
            if (state == true)
            {
                if (StudentFormfillUp() == true)
                {
                    DaoPojo.name = TextName.Text;
                    DaoPojo.roll = Convert.ToInt32(comboRoll.Text);
                    DaoPojo.dept = comboDept.Text;
                    if (first.Checked==true)
                    {
                        DaoPojo.year = 1;
                    }
                    if (second.Checked==true)
                    {
                        DaoPojo.year = 2;
                    }
                    if (third.Checked==true)
                    {
                        DaoPojo.year = 3;
                    }
                    DisplayStudent dspstu = new DisplayStudent();
                    dspstu.Show();
                    this.Hide();
                }
            }
            else
            {
                DaoPojo.date= Calendar.SelectionStart.ToShortDateString();
                //MessageBox.Show(Calendar.SelectionStart.ToShortDateString());
                DateMonthDisplay dt = new DateMonthDisplay();
                dt.Show();
                this.Hide();
            }
        }

        private bool StudentFormfillUp()
        {
            if (TextName.Text == "")
            {
                TextName.Select();
            }
            if (TextName.Text != "" && comboRoll.Text != "" && comboDept.Text!="")
            {
                return true;
            }
            else
            {
                MessageBox.Show("You can't leave anything Blank!!!");
                return false;
            }
        }
    }
}
