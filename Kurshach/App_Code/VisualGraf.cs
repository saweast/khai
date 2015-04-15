using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Drawing;
using System.IO;

/// <summary>
/// Сводное описание для VisualGraf
/// </summary>
public class VisualGraf : Graf<int>
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

    
    
    /*public void SaveMeMyFriend()
    {
        MyFile muFilik = new MyFile();
        muFilik.ClearFile();
        foreach (pair p in Links)
        {
            muFilik.WritePairToFile(p.from, p.to);
        }
        muFilik.Close();
    }*/
}