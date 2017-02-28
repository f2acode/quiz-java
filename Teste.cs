using System;
using System.Windows.Forms;
namespace WindowsFormApp
{
    public partial class Form1 : System.Windows.Forms.Form
    {
        // private System.ComponentModel.Container components = null;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.MenuStrip menu1;

        public Form1()
        {
            InitializeComponent();
            this.Size = new System.Drawing.Size(800, 600);
        }
        // internal System.Windows.Forms.Button button1;

        private void InitializeComponent()
        {
            // this.components = new System.ComponentModel.Container();

            this.label1 = new System.Windows.Forms.Label();
            this.Controls.Add(this.label1);

            this.button1 = new System.Windows.Forms.Button();
            this.button1.Name = "Button1";
            this.button1.Location = new System.Drawing.Point(20, 40);
            this.button1.Size = new System.Drawing.Size(120, 32);
		        this.button1.TabIndex = 0;
		        this.button1.Text = "Center textbox on control";
            this.Controls.Add(this.button1);

            this.menu1 = new System.Windows.Forms.MenuStrip();
            this.Controls.Add(this.menu1);
        }

        static void Main()
        {
            System.Windows.Forms.Application.Run(new Form1());
        }
    }
}
