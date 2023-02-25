using System.Net.Sockets;
using System.Windows.Forms;

namespace LedClient
{
    public partial class Form1 : Form
    {
        

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            
        }

        //byte[] data = new byte[3] {100, 150, 255 };        

        private async void button1_Click(object sender, EventArgs e)
        {
            await ColorPaint(new byte[2] { 0, (byte)trackBarBrightness.Value });

            await ColorPaint(new byte[2] { 1, (byte)trackBarColor.Value });
        }
        private async Task ColorPaint(byte[] data)
        {
        CreateConnect:

            try
            {
                TcpClient tc;
                NetworkStream nc;
                tc = new TcpClient("192.168.1.170", 2678);
                nc = tc.GetStream();

                nc.Write(data);
                nc.Flush();
                nc.Close();
                tc.Close();
                await Task.Delay(data.Length * 200);
            }
            catch (Exception)
            {
                goto CreateConnect;
            }
        }

        private async void button2_Click(object sender, EventArgs e)
        {
            await ColorPaint(new byte[2] { 0, (byte)trackBarBrightness.Value });

            await ColorPaint(new byte[4] { 2, 255, 255, 255});
        }
    }
}