using System.Net.Sockets;

namespace LedClient
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        //byte[] data = new byte[3] {100, 150, 255 };        

        private void Form1_Load(object sender, EventArgs e)
        {
            ColorPaint();
            //FonPaint();
        }

        //void FonPaint()
        //{
        //    Graphics g = Graphics.FromHwnd(this.Handle);
        //    g.DrawPie(new Pen(Color.Black),new Rectangle(), 65,8);
        //    Color c = Color.Gra


        //}


        async void ColorPaint()
        {
            byte[] data = new byte[] { 0, 255};

            CreateConnect:

            try
            {
                TcpClient tc = new TcpClient("192.168.1.166", 2005);
                Console.WriteLine("Server find");
                NetworkStream nc = tc.GetStream();
                textBox1.Text = "Yes";

                while (true)
                {
                    nc.Write(data);
                    nc.Flush();
                    await Task.Delay(200);
                }

                //StreamWriter sw = new StreamWriter(nc);
                // sw.Write(data[0]);

                tc.Close();
            }
            catch (Exception)
            {
                textBox1.Text = "No";
                goto CreateConnect;
            }
        }
    }

}