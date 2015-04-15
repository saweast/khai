using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;

namespace graf
{
    class VisualGraf:Graf<int>
    {
        //Graf<int> graf = new Graf<int>();

        struct pointInfo
        {
            public Point position;
            public bool ready;

            public pointInfo(int pointCount, int pointInd)
            {
                int R = 100;
                position = new Point();
                position.X = (int)(Math.Cos((2 * Math.PI / pointCount) * pointInd) * R);
                position.Y = (int)(Math.Sin((2 * Math.PI / pointCount) * pointInd) * R);
                ready = false;
            }
        }

        public VisualGraf(Graf<int> from):base(from)
        {
            UpdatePointInfo();
        }

        public VisualGraf()
        {
        }

        public override void AddVertex(int key, int value)
        {
            base.AddVertex(key, value);
            UpdatePointInfo();
        }

        private void UpdatePointInfo()
        {
            int i = 0;
            foreach (node n in Vertexs.Values)
            {
                n.Tag = new pointInfo(vertexcount, i);
                i++;
            }
        }

        public override void RemoveVertex(int key)
        {
            base.RemoveVertex(key);
            UpdatePointInfo();
        }

        Font fnt = new Font("Arial", 10);
        public void Draw(Graphics g,Point pos)
        {
            g.TranslateTransform(pos.X, pos.Y);

            foreach (pair p in Links)
            {
                pointInfo info1 = (pointInfo)Vertexs[p.from].Tag;
                pointInfo info2 = (pointInfo)Vertexs[p.to].Tag;
                g.DrawLine(Pens.Black, info1.position, info2.position);

                PointF textPos = new PointF(
                    (info1.position.X + info2.position.X) / 2,
                    (info1.position.Y + info2.position.Y) / 2);
                g.DrawString(p.cost.ToString(), fnt, Brushes.Green, textPos);
            }

            foreach (node n in Vertexs.Values)
            {
                pointInfo info=(pointInfo)n.Tag;
                Brush clr;
                if (n.Walked)
                    clr = Brushes.Red;
                else
                clr = Brushes.Black;
                g.FillEllipse(clr, info.position.X-15, info.position.Y-15, 30, 30);
                g.DrawString(
                    string.Format("{0}-{1}", n.Key,n.Value),
                    fnt, Brushes.Yellow, new PointF(info.position.X-10, info.position.Y-5));
            }
            g.ResetTransform();
        }
    }
}
