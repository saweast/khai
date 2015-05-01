using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Threading;

namespace graf
{
    public partial class Form1 : Form
    {
        VisualGraf graf = new VisualGraf();

        public Form1()
        {
            InitializeComponent();
        }

        private void add_Click(object sender, EventArgs e)
        {
            graf.AddVertex((int)key.Value, (int)key.Value);
            pictureBox1.Invalidate();
        }

        private void remove_Click(object sender, EventArgs e)
        {
            graf.RemoveVertex((int)key.Value);
            pictureBox1.Invalidate();
        }

        private void pictureBox1_Paint(object sender, PaintEventArgs e)
        {
            graf.Draw(e.Graphics,new Point(150,150));
        }

        private void link_Click(object sender, EventArgs e)
        {
            graf.Link((int)from.Value, (int)to.Value,(int)cost.Value);
            pictureBox1.Invalidate();
        }

        private void unlink_Click(object sender, EventArgs e)
        {
            graf.UnLink((int)from.Value, (int)to.Value);
            pictureBox1.Invalidate();

        }

        private void btnDepth_Click(object sender, EventArgs e)
        {
            graf.WalkDepth((int)key.Value,
                delegate(Graf<int>.node node) {
                    pictureBox1.Invalidate();
                    Thread.Sleep(500);
                    Application.DoEvents();
                }
            );
        }

        private void clear_Click(object sender, EventArgs e)
        {
            graf.ClearWalk();
            pictureBox1.Invalidate();
        }

        private void btnWidth_Click(object sender, EventArgs e)
        {
            graf.WalkWidth((int)key.Value,
                delegate(Graf<int>.node node)
                {
                pictureBox1.Invalidate();
                Thread.Sleep(500);
                Application.DoEvents();
                }
            );
        }

        private void prima_Click(object sender, EventArgs e)
        {
            VisualGraf.Prima(((Graf<int>)graf));
            
            pictureBox1.Invalidate();
        }
    }
}
