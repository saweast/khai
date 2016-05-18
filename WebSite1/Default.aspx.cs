using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.IO;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class _Default : System.Web.UI.Page
{

    DataSetTableAdapters.EdgesTableAdapter edgesTableAdapter;
    DataSet.EdgesDataTable edgesTable;
    DataSetTableAdapters.VertexesTableAdapter vertexesTableAdapter;
    DataSet.VertexesDataTable vertexesTable;
    MyFile mFile;

    private void updateAll()
    {
        edgesTableAdapter.Fill(edgesTable);
        vertexesTableAdapter.Fill(vertexesTable);
        SqlDataSource1.UpdateCommand = "select * from Edges";
        SqlDataSource1.Update();
        SqlDataSource1.UpdateCommand = "select * from Vertexes";
        SqlDataSource1.Update();
        DataBind();
    }

    protected void Page_Load(object sender, EventArgs e)
    {
        mFile = new MyFile();
        edgesTable = new DataSet.EdgesDataTable();
        edgesTableAdapter = new DataSetTableAdapters.EdgesTableAdapter();
        vertexesTable = new DataSet.VertexesDataTable();
        vertexesTableAdapter = new DataSetTableAdapters.VertexesTableAdapter();
        edgesTableAdapter.Fill(edgesTable);
        vertexesTableAdapter.Fill(vertexesTable);

        ListBox4.Items.Clear();
        for (int i = 1; i <= edgesTable.Count; i++)
        {
            ListBox4.Items.Add(vertexesTableAdapter.getNameByID(Convert.ToInt32(edgesTableAdapter.getFrom(i))).ToString() +
                "→" + vertexesTableAdapter.getNameByID(Convert.ToInt32(edgesTableAdapter.getTo(i))).ToString() +
                "= " + Convert.ToInt32(edgesTableAdapter.getWeight(i)).ToString());
        }
        writeFromDBToJson();
        Session["selF"] = ddlFrom.SelectedIndex;
        Session["selT"] = ddTo.SelectedIndex;
        Session["selN"] = ddEname.SelectedIndex;
    }

    public void writeFromDBToJson()
    {
        if (File.Exists(@"C:\inetpub\wwwroot\edges.json"))
        {
            File.Delete(@"C:\inetpub\wwwroot\edges.json");
        }
        StreamWriter write_text_to_json = new StreamWriter(@"C:\inetpub\wwwroot\edges.json");

        write_text_to_json.WriteLine("[");
        for (int i = 1; i <= edgesTable.Count; i++)
        {
            if (i <= edgesTable.Count - 1)
            {
                write_text_to_json.WriteLine("[" + edgesTableAdapter.getFrom(i).ToString().Trim() + ", " + edgesTableAdapter.getTo(i).ToString().Trim() + "]");
                write_text_to_json.Write(",");
            }
            else
            {
                write_text_to_json.WriteLine("[" + edgesTableAdapter.getFrom(i).ToString().Trim() + ", " + edgesTableAdapter.getTo(i).ToString().Trim() + "]]");
                break;
            }
        }
        write_text_to_json.Close();

        vertexesTableAdapter.Fill(vertexesTable);
        if (File.Exists(@"C:\inetpub\wwwroot\tops.json"))
        {
            File.Delete(@"C:\inetpub\wwwroot\tops.json");
        }
        write_text_to_json = new StreamWriter(@"C:\inetpub\wwwroot\tops.json");
        write_text_to_json.Write("[");
        for (int i = 1; i <= vertexesTable.Count; i++)
        {
            write_text_to_json.WriteLine("{\"x\":" + vertexesTableAdapter.getX(i).Trim() + ", \"y\":" + vertexesTableAdapter.getY(i).Trim() + ", \"name\": \"" + vertexesTableAdapter.getNameByID(i).ToString().Trim() + "\"}");
            if (i != vertexesTable.Count)
                write_text_to_json.Write(",");
            else
            {
                write_text_to_json.Write("]");
            }
        }
        write_text_to_json.Close();
    }

    protected void Button1_Click(object sender, EventArgs e)
    {
        updateAll();
        Adjacency adjacency = new Adjacency(999);
        int eCount = Convert.ToInt32(edgesTableAdapter.getCount());
        for (int i = 1; i <= eCount; i++)
        {
            adjacency.setElementAt(true, Convert.ToInt32(edgesTableAdapter.getFrom(i)), Convert.ToInt32(edgesTableAdapter.getTo(i)));
            adjacency.setWeight(Convert.ToInt32(edgesTableAdapter.getFrom(i)), Convert.ToInt32(edgesTableAdapter.getTo(i)), Convert.ToInt32(edgesTableAdapter.getWeight(i)));
        }

        KruskalMST mst = new KruskalMST();
        Pair[] A = mst.MSTKruskal(999, adjacency);
        mFile.writeNodeNames();
        mFile.WriteResultToFile(A, adjacency);
        mFile.Close();
        List<string> listPairs = mst.listPairs;
        ListBox5.Items.Add("Log:");
        for(int i = 0; i < listPairs.Count; i++)
        {
            ListBox5.Items.Add(listPairs[i].ToString());
        }
        
        //Response.Redirect("http://127.0.0.1/");
    }

    protected void Button2_Click(object sender, EventArgs e)
    {
        edgesTableAdapter.Insert(edgesTable.Count+1, ddlFrom.SelectedItem.Value, ddTo.SelectedItem.Value, weight.Text);
        updateAll();
        //ListBox4.Items.Clear();
        //for(int i=1; i <= edgesTable.Count; i++) {
            //ListBox4.Items.Add(vertexesTableAdapter.getNameByID(Convert.ToInt32(edgesTableAdapter.getFrom(i))).ToString() +
                //"→" + vertexesTableAdapter.getNameByID(Convert.ToInt32(edgesTableAdapter.getTo(i))).ToString() +
                //"= " + Convert.ToInt32(edgesTableAdapter.getWeight(i)).ToString());
        //}
        if (File.Exists(@"C:\inetpub\wwwroot\edges.json"))
        {
            File.Delete(@"C:\inetpub\wwwroot\edges.json");
        }
        StreamWriter write_text_to_json = new StreamWriter(@"C:\inetpub\wwwroot\edges.json");

        write_text_to_json.WriteLine("[");
        for (int i = 1; i <= edgesTable.Count; i++)
        {
            if (i <= edgesTable.Count - 1)
            {
                write_text_to_json.WriteLine("[" + edgesTableAdapter.getFrom(i).ToString().Trim() + ", " + edgesTableAdapter.getTo(i).ToString().Trim() + "]");
                write_text_to_json.Write(",");
            }
            else
            {
                write_text_to_json.WriteLine("[" + edgesTableAdapter.getFrom(i).ToString().Trim() + ", " + edgesTableAdapter.getTo(i).ToString().Trim() + "]]");
                break;
            }
        }
        write_text_to_json.Close();
    }

    public class MyFile
    {
        private System.IO.StreamWriter write_text;
        DataSet.VertexesDataTable vertexesTable = new DataSet.VertexesDataTable();
        DataSetTableAdapters.VertexesTableAdapter vertexesTableAdapter = new DataSetTableAdapters.VertexesTableAdapter();

        StreamWriter write_text_to_json;

        public void Close()
        {
            //write_text.Close();
        }

        public void writeNodeNames()
        {
            vertexesTableAdapter.Fill(vertexesTable);
            if (File.Exists(@"C:\inetpub\wwwroot\tops.json"))
            {
                File.Delete(@"C:\inetpub\wwwroot\tops.json");
            }
            write_text_to_json = new StreamWriter(@"C:\inetpub\wwwroot\tops.json");
            write_text_to_json.Write("[");
            for (int i = 1; i <= vertexesTable.Count; i++)
            {
                write_text_to_json.WriteLine("{\"x\":"+ vertexesTableAdapter.getX(i).Trim() + ", \"y\":" + vertexesTableAdapter.getY(i).Trim() + ", \"name\": \"" + vertexesTableAdapter.getNameByID(i).ToString().Trim() + "\"}");
                if (i != vertexesTable.Count)
                    write_text_to_json.Write(",");
                else
                {
                    write_text_to_json.Write("]");
                }
            }
            write_text_to_json.Close();
        }

        public void WriteResultToFile(Pair[] p, Adjacency adjacency)
        {
            vertexesTableAdapter.Fill(vertexesTable);
            
            if (File.Exists(@"C:\inetpub\wwwroot\edges.json"))
            {
                File.Delete(@"C:\inetpub\wwwroot\edges.json");
            }
            write_text_to_json = new StreamWriter(@"C:\inetpub\wwwroot\edges.json");

            write_text_to_json.WriteLine("[");
            for (int i = 0; i < p.Length; i++)
            {
                if (p[i + 1] != null)
                {
                    write_text_to_json.WriteLine("[" + p[i].U + ", " + p[i].V + "]");
                        write_text_to_json.Write(",");
                }
                else
                {
                    write_text_to_json.WriteLine("[" + p[i].U + ", " + p[i].V + "]]");
                    break;
                }
            }
            write_text_to_json.Close();

            if (File.Exists(@"C:\inetpub\wwwroot\weight.json"))
            {
                File.Delete(@"C:\inetpub\wwwroot\weight.json");
            }
            write_text_to_json = new StreamWriter(@"C:\inetpub\wwwroot\weight.json");

            write_text_to_json.WriteLine("[");
            for (int i = 0; i < p.Length; i++)
            {
                if (p[i + 1] != null)
                    write_text_to_json.Write(adjacency.getWeight(p[i].U, p[i].V).ToString() + ", ");
                else
                {
                    write_text_to_json.Write(adjacency.getWeight(p[i].U, p[i].V).ToString());
                    break;
                }
            }
            write_text_to_json.Write("]");
            write_text_to_json.Close();
        }
    }

    protected void Button3_Click(object sender, EventArgs e)
    {
        vertexesTableAdapter.Insert(vertexesTable.Count + 1, tbName.Text.ToString(), Convert.ToString(tbX.Text), Convert.ToString(tbY.Text));
        updateAll();
    }
    int selInd = 0;

    protected void Button4_Click(object sender, EventArgs e)
    {
        vertexesTableAdapter.Update(tbEname.Text, Convert.ToString(tbEx.Text), Convert.ToString(tbEy.Text), Convert.ToInt32(ddEname.SelectedValue));
        writeFromDBToJson();
        updateAll();
    }

    protected void DropDownList1_SelectedIndexChanged(object sender, EventArgs e)
    {
        selInd = Convert.ToInt32(ddEname.SelectedValue);
        tbEx.Text = vertexesTableAdapter.getX(selInd).Trim();
        tbEy.Text = vertexesTableAdapter.getY(selInd).Trim();
        tbEname.Text = vertexesTableAdapter.getNameByID(selInd).ToString();
        ddEname.SelectedIndex = Convert.ToInt32(Session["selN"]);
    }

    public void perfWeight()
    {
        ddlFrom.SelectedIndex = Convert.ToInt32(Session["selF"]);
        ddTo.SelectedIndex = Convert.ToInt32(Session["selT"]);
        ddEname.SelectedIndex = Convert.ToInt32(Session["selN"]);
        int xF = 0, xT = 0, yF = 0, yT = 0;
        xF = Convert.ToInt32(vertexesTableAdapter.getX(Convert.ToInt32(ddlFrom.SelectedValue)));
        yF = Convert.ToInt32(vertexesTableAdapter.getY(Convert.ToInt32(ddlFrom.SelectedValue)));
        xT = Convert.ToInt32(vertexesTableAdapter.getX(Convert.ToInt32(ddTo.SelectedValue)));
        yT = Convert.ToInt32(vertexesTableAdapter.getY(Convert.ToInt32(ddTo.SelectedValue)));
        double weightRes = Math.Pow(xF - xT, 2) + Math.Pow(yF - yT, 2);
        weight.Text = weightRes.ToString();
    }

    protected void ddlFrom_SelectedIndexChanged(object sender, EventArgs e)
    {
        perfWeight();
    }

    protected void ddTo_SelectedIndexChanged(object sender, EventArgs e)
    {
        perfWeight();
    }
}