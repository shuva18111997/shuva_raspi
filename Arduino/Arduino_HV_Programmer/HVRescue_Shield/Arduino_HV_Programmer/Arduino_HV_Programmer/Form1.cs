using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;
using System.IO;

namespace Arduino_HV_Programmer
{
    public partial class HV_Programmer : Form
    {
        bool isConnected = false;
        String[] ports;
        SerialPort port;
        String dataIn;
        String[] fusebits;
        String[] Controllers = {"ATMega8","ATMega328P","ATMega328","ATtiny13","ATtiny85"};
        String[,] Fuses = { { "0XDD", "0XE2", "0XFF" }, { "0XDE", "0XFF", "0XFD" }, { "0XDB", "0XFF", "0XFD" }, { "0XFF", "0X6A", "" }, { "0XDD", "0XE2", "0XFF" } };
        int count;
        StreamReader sr;
        StreamWriter st;
        String path = Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData), "Reserve.txt");
        //@"%AppData%\Local\Reserve.txt";
        
        public HV_Programmer()
        {
            InitializeComponent();
            try
            {
                sr = new StreamReader(path);
                for (int i = 0; i < 5; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        Fuses[i, j] = sr.ReadLine();
                    }
                }
                sr.Close();
            }
            catch (Exception)
            {
                st = File.CreateText(path);
                for (int i = 0; i < 5; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        st.WriteLine(Fuses[i, j]);
                    }
                }
                st.Close();
            }
            disableControls();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            getAvailableComPorts();
            comboBox1.Text = null;
            count = comboBox1.Items.Count;
            for (int i = 0; i < count; i++)
            {
                comboBox1.Items.RemoveAt(0);
            }
            if (ports.Length > 0)
            {
                button1.Enabled = true;
                foreach (string port in ports)
                {
                    comboBox1.Items.Add(port);
                    if (ports[0] != null)
                    {
                        comboBox1.SelectedItem = ports[0];
                    }
                }
            }
            else
            {
                button1.Enabled = false;
            }
        }

        void disableControls()
        {
            label1.Enabled = false;
            comboBox2.Enabled = false;
            HFuse_textBox.Enabled = false;
            LFuse_textBox.Enabled = false;
            EFuse_textBox.Enabled = false;
            label2.Enabled = false;
            label3.Enabled = false;
            label4.Enabled = false;
            connection_check_btn.Enabled = false;
            check_btn.Enabled = false;
            write_btn.Enabled = false;
            read_btn.Enabled = false;
            default_btn.Enabled = false;
            comboBox1.Enabled = true;
            button2.Enabled = true;
            HFuse_Update.Enabled = false;
            LFuse_Update.Enabled = false;
            EFuse_Update.Enabled = false;
            getAvailableComPorts();
            comboBox1.Text = null;
            button3.Enabled = false;
            count = comboBox1.Items.Count;
            for (int i = 0; i < count; i++)
            {
                comboBox1.Items.RemoveAt(0);
            }
            if (ports.Length < 1)
            {
                button1.Enabled = false;
            }
            else
            {
                foreach (string port in ports)
                {
                    comboBox1.Items.Add(port);
                    if (ports[0] != null)
                    {
                        comboBox1.SelectedItem = ports[0];
                    }
                }
            }
        }

        void enableControls()
        {
            label1.Enabled = true;
            comboBox2.Enabled = true;
            comboBox2.DropDownStyle = ComboBoxStyle.DropDownList;   //makes comboBox ReadOnly.
            HFuse_textBox.Enabled = true;
            LFuse_textBox.Enabled = true;
            EFuse_textBox.Enabled = true;
            label2.Enabled = true;
            label3.Enabled = true;
            label4.Enabled = true;
            connection_check_btn.Enabled = true;
            check_btn.Enabled = true;
            write_btn.Enabled = true;
            read_btn.Enabled = true;
            default_btn.Enabled = true;
            comboBox1.Enabled = false;
            button1.Enabled = true;
            button2.Enabled = false;
            HFuse_Update.Enabled = true;
            LFuse_Update.Enabled = true;
            EFuse_Update.Enabled = true;
            button3.Enabled = true;
            foreach (String item in Controllers)
            {
                comboBox2.Items.Add(item);
            }
            comboBox2.SelectedItem = Controllers[0];
        }

        void getAvailableComPorts()
        {
            ports = SerialPort.GetPortNames();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (!isConnected)
            {
                connectToArduino();
            }
            else
            {
                disconnectFromArduino();
            }
        }

        private void connectToArduino()
        {
            isConnected = true;
            string selectedPort = comboBox1.GetItemText(comboBox1.SelectedItem);
            try
            {
                port = new SerialPort(selectedPort, 115200, Parity.None, 8, StopBits.One);
                port.DtrEnable = true;
                port.RtsEnable = true;
                port.Open();
                port.DataReceived += new SerialDataReceivedEventHandler(port_DataReceived);
                button1.Text = "Disconnect";
                comboBox1.Enabled = false;
                button1.Enabled = true;
                button2.Enabled = false;
            }
            catch
            {
                MessageBox.Show("Can not open this port");
            }
        }

        private void port_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            dataIn = port.ReadExisting();
            port.DiscardInBuffer();
            port.DiscardOutBuffer();
            this.Invoke(new EventHandler(ShowData));
        }

        private void ShowData(object sender, EventArgs e)
        {
            if (dataIn.LastIndexOf('\n') > 0)
            {
                dataIn = dataIn.Substring(0, (dataIn.IndexOf('\n') - 1));
                if (dataIn == "#ready")
                {
                    enableControls();
                    port.Write("#START");
                }

                else if (dataIn.StartsWith("#Burn"))
                {
                    MessageBox.Show("Write Successful");
                    dataIn = dataIn.Remove(0, 5);
                    fusebits = dataIn.Split('&');
                    HFuse_textBox.Text = "0X" + fusebits[0];
                    LFuse_textBox.Text = "0X" + fusebits[1];
                    EFuse_textBox.Text = "0X" + fusebits[2];
                }

                else if (dataIn.StartsWith("#Fuse"))
                {
                    MessageBox.Show("Read Successful");
                    dataIn = dataIn.Remove(0, 5);
                    fusebits = dataIn.Split('&');
                    HFuse_textBox.Text = "0X"+fusebits[0];
                    LFuse_textBox.Text = "0X" + fusebits[1];
                    EFuse_textBox.Text = "0X" + fusebits[2];
                }

                else if (dataIn.StartsWith("Port_Ready"))
                {
                    MessageBox.Show("Checked OK");
                    connection_check_btn.Enabled = true;
                }

                else if (dataIn.StartsWith("Con"))
                {
                    dataIn = dataIn.Remove(0, 3);
                    if(dataIn == comboBox2.SelectedIndex.ToString())
                        MessageBox.Show("Controller Set");
                }

                else if (dataIn.StartsWith("High"))
                {
                    dataIn = dataIn.Remove(0, 4);
                    if(dataIn == HFuse_textBox.Text)
                        MessageBox.Show("HFuse Set "+dataIn);
                }

                else if (dataIn.StartsWith("Low"))
                {
                    dataIn = dataIn.Remove(0, 3);
                    if (dataIn == LFuse_textBox.Text)
                        MessageBox.Show("LFuse Set "+dataIn);
                }

                else if (dataIn.StartsWith("Ext"))
                {
                    dataIn = dataIn.Remove(0, 3);
                    if (dataIn == EFuse_textBox.Text)
                        MessageBox.Show("EFuse Set "+dataIn);
                }
            }
        }

        private void disconnectFromArduino()
        {
            port.Close();
            isConnected = false;
            button1.Text = "Connect";
            resetDefaults();
            disableControls();
        }

        void resetDefaults()
        {
            comboBox2.Text = null;
            count = comboBox2.Items.Count;
            for (int i = 0; i < count; i++)
            {
                comboBox2.Items.RemoveAt(0);
            }
            HFuse_textBox.Text = null;
            LFuse_textBox.Text = null;
            EFuse_textBox.Text = null;
        }

        private void comboBox2_SelectedValueChanged(object sender, EventArgs e)
        {
            //when combobox item changed then set fuses.
            if (comboBox2.SelectedIndex > -1)
            {
                HFuse_textBox.Text = Fuses[comboBox2.SelectedIndex, 0];
                LFuse_textBox.Text = Fuses[comboBox2.SelectedIndex, 1];
                EFuse_textBox.Text = Fuses[comboBox2.SelectedIndex, 2];
            }
        }

        private void connection_check_btn_Click(object sender, EventArgs e)
        {
            connection_check_btn.Enabled = false;
            port.Write("P\n");
        }

        private void write_btn_Click(object sender, EventArgs e)
        {
            port.Write("W\n");
        }

        private void read_btn_Click(object sender, EventArgs e)
        {
            port.Write("R\n");
        }

        private void default_btn_Click(object sender, EventArgs e)
        {
            if (comboBox2.SelectedIndex > -1)
            {
                HFuse_textBox.Text = Fuses[comboBox2.SelectedIndex, 0];
                LFuse_textBox.Text = Fuses[comboBox2.SelectedIndex, 1];
                EFuse_textBox.Text = Fuses[comboBox2.SelectedIndex, 2];
            }
        }

        private void check_btn_Click(object sender, EventArgs e)
        {
            port.Write(comboBox2.SelectedIndex.ToString());
        }
        
        private void HFuse_Update_Click(object sender, EventArgs e)
        {
            HFuse_textBox.Text = HFuse_textBox.Text.ToUpper();
            //check here is it a hex or not
            if (isHexNumber(HFuse_textBox.Text))
            {
                port.Write("H" + HFuse_textBox.Text + "\n");
            }
            else
            {
                MessageBox.Show("Number is not HEX");
            }
        }

        private void LFuse_Update_Click(object sender, EventArgs e)
        {
            LFuse_textBox.Text = LFuse_textBox.Text.ToUpper();
            //check here is it a hex or not
            if (isHexNumber(LFuse_textBox.Text))
            {
                port.Write("L" + LFuse_textBox.Text + "\n");
            }
            else
            {
                MessageBox.Show("Number is not HEX");
            }
        }

        private void EFuse_Update_Click(object sender, EventArgs e)
        {
            EFuse_textBox.Text = EFuse_textBox.Text.ToUpper();
            //check here is it a hex or not
            if (isHexNumber(EFuse_textBox.Text))
            {
                port.Write("X" + EFuse_textBox.Text + "\n");
            }
            else
            {
                MessageBox.Show("Number is not HEX");
            }
        }

        public bool isHexNumber(String inputString)
        {
            String Upper;
            String Lower;
            inputString.ToUpper();
            if (inputString.StartsWith("0X", 0))
            {
                inputString = inputString.Remove(0, 2);
                Upper = inputString.Substring(0, 1);
                Lower = inputString.Substring(1, 1);
                if ((Upper.All("0123456789abcdefABCDEF".Contains)) && (Lower.All("0123456789abcdefABCDEF".Contains)))
                    return true;
                else
                    return false;
            }
            else
                return false;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            HFuse_textBox.Text = HFuse_textBox.Text.ToUpper();
            LFuse_textBox.Text = LFuse_textBox.Text.ToUpper();
            EFuse_textBox.Text = EFuse_textBox.Text.ToUpper();

            if ((isHexNumber(HFuse_textBox.Text)) && (isHexNumber(LFuse_textBox.Text)) && (isHexNumber(EFuse_textBox.Text)))
            {
                Fuses[comboBox2.SelectedIndex, 0] = HFuse_textBox.Text;
                Fuses[comboBox2.SelectedIndex, 1] = LFuse_textBox.Text;
                Fuses[comboBox2.SelectedIndex, 2] = EFuse_textBox.Text;
                st = new StreamWriter(path);
                for (int i = 0; i < 5; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        st.WriteLine(Fuses[i, j]);
                    }
                }
                st.Close();
            }
            else
            {
                MessageBox.Show("Number is not HEX");
            }
        }
    }
}
