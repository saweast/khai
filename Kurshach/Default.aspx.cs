using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using DataSetTableAdapters;
using System.IO;

public partial class _Default : System.Web.UI.Page
{
    
    DataSet BigDataSet = new DataSet();
    DistancesTableAdapter DistTableAdapter = new DistancesTableAdapter();
    CityTableAdapter CityTA = new CityTableAdapter();
    List<int> selectedCityes = new List<int>();
    VisualGraf graf = new VisualGraf();
    
    VisualGraf GetGraf
    {
        get
        {
            return Session["Graf"] as VisualGraf;
        }
        set
        {
            Session["Graf"] = value;
        }
    }
    List<int> GetSelCit
    {
        get
        {
            return Session["SelectedCitys"] as List<int>;
        }
        set
        {
            Session["SelectedCitys"] = value;
        }
    }
    protected void Page_Load(object sender, EventArgs e)
    {
        if(GetSelCit != null)
            selectedCityes = GetSelCit;
        if(GetGraf != null)
            graf = GetGraf;
        int counter = 1;
        foreach (Control control in form1.Controls)
        {
            CheckBox cb1 = control as CheckBox;
            if (cb1 != null)
            {
                if (counter != 6)
                {
                    cb1.Text = CityTA.GetCityNameByID(counter);
                    counter++;
                }
            }
        }
        
    }
    
    public void writeNodeNames(List<int> ListKakoe)
    {
        File.Delete(@"C:\inetpub\wwwroot\data.json");
        StreamWriter write_text_to_json = new StreamWriter(@"C:\inetpub\wwwroot\data.json");
        write_text_to_json.WriteLine("{");
        write_text_to_json.Write("\"nodes\": [");
        //foreach (int a in ListKakoe)
        for (int i = 0; i < ListKakoe.Count; i++)
        {
            write_text_to_json.Write(System.Environment.NewLine + "{\"name\": \"" + CityTA.GetCityNameByID(ListKakoe[i]).Trim() + "\"}");
            if (i != ListKakoe.Count - 1)
                write_text_to_json.Write(",");
            else
            {
                write_text_to_json.WriteLine(System.Environment.NewLine + "],");
                write_text_to_json.WriteLine("\"edges\": [");
            }
        }
        write_text_to_json.Close();
    }

    protected void Button1_Click(object sender, EventArgs e)
    {

        writeNodeNames(selectedCityes);
        selectedCityes.Add(6);
        int selC = 0, selC1 = 0;
        for (int i = 0; i < selectedCityes.Count - 1; i++)
        {
            for(int j = i+1; j < selectedCityes.Count; j++)
            {
                selC = selectedCityes[i];
                selC1 = selectedCityes[j];
                graf.AddVertex(selC, selC1);
                graf.Link(selC, selC1, Convert.ToInt32(DistTableAdapter.GetDistanse(selC, selC1)));
            }
        }
        GetGraf = graf;
    }
    int selectedC = 0;
    protected void CheckBox_CheckedChanged(object sender, EventArgs e)
    {
        CheckBox cb = (CheckBox)sender;
        if (cb != null)
        {
            selectedC = Convert.ToInt32(cb.ID.Replace("CheckBox", ""));
            if (cb.Checked)
            {
                selectedCityes.Add(selectedC);
                ListBox2.Items.Add(CityTA.GetCityNameByID(selectedC));
            }
            else
            {
                selectedCityes.Remove(selectedC);
                ListBox2.Items.Remove(CityTA.GetCityNameByID(selectedC));
            }
        }
        GetSelCit = selectedCityes;
    }
    protected void Button2_Click(object sender, EventArgs e)
    {
        VisualGraf.Prima(((Graf<int>)graf));
        Response.Redirect("http://127.0.0.1/");
    }
}