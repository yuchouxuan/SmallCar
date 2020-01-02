using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace cktx
{
    public partial class Form1 : Form
    {
        private ArrayList alx = null;
        public Form1()
        {
            alx = new ArrayList();
            InitializeComponent();
        }
        SerialPort sp1 = new SerialPort();
        private void Form1_Load(object sender, EventArgs e)
        {
            Control.CheckForIllegalCrossThreadCalls = false;
            sp1.DataReceived += new SerialDataReceivedEventHandler(sp1_DataReceived);
            string[] str = SerialPort.GetPortNames();//检查是否含有串口 
            if (str == null)
            {
                MessageBox.Show("本机没有串口！", "Error");
                return;
            }

            foreach (string s in SerialPort.GetPortNames())   //添加串口
            {
                comboBox1.Items.Add(s);          //获取有多少个COM口，添加到控件里
            }
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
           
        }
       void sp1_DataReceived(object s,SerialDataReceivedEventArgs e)
        {
            if (sp1.IsOpen == false) return;
            char[] data = new char[sp1.BytesToRead];
            sp1.Read(data, 0, data.Length);
            sp1.DiscardInBuffer();

            string[] stx = (new string(data)).Split(new string[] { "\r\n" },StringSplitOptions.None);
            foreach (string tC in stx)
            {
                if ("".Equals(tC)) continue;
                try
                {
                    long i = long.Parse(tC);
                    alx.Add(i);
                }
                catch { };
            }

            tb1.AppendText(new string(data));

        }
            private void button1_Click(object sender, EventArgs e)
        {
            if (sp1.IsOpen)
            {
                sp1.DiscardInBuffer();
                sp1.Close();
            }
            sp1.PortName = comboBox1.SelectedItem.ToString();
            sp1.BaudRate = 9600;
            sp1.DataBits = 8;
            sp1.StopBits = StopBits.One;
            sp1.Parity = Parity.None;
            sp1.ReadBufferSize= 2147483646;
            sp1.Open();
            alx.Clear();
            Control.CheckForIllegalCrossThreadCalls = false;
            sp1.DataReceived += new SerialDataReceivedEventHandler(sp1_DataReceived);
        }
    }
}
