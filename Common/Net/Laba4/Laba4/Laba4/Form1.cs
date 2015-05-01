using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Laba4
{
    public partial class Form1 : Form
    {
        String[] strNames = { "Віталька", "Вадімка", "Ярославка", "Катюха", "Сашка", "Ілюшка", "Богданка", "Кирюшка", "Лєнушка", "Настюшка" };
        String[] strLastNames = { "Волківський", "Лаворчук", "Підгорний", "Анохіна", "Шкідіна", "Козій", "Бодькін", "Кірін", "Холя", "Аніхона" };
        Random rand = new Random();
        Worker worker;
        TreeNode workersNode;
        public Form1()
        {
            InitializeComponent();
            listView1.View = View.Details;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            for(int i=0; i<strNames.Length-1; i++)
            {
                worker = new Worker();
                workersNode = new TreeNode();
                worker.FirstName = strNames[i];
                worker.LastName = strLastNames[i];
                worker.setAge(rand.Next(100));
                workersNode.Tag = worker;
                workersNode.Text = worker.LastName;
                treeView1.Nodes[0].Nodes.Add(workersNode);
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Worker bufWorker = new Worker();
            bufWorker = (Worker)treeView1.SelectedNode.Tag;
            toolStripStatusLabel2.Text = bufWorker.FirstName;    
            toolStripStatusLabel4.Text = bufWorker.LastName;
            toolStripStatusLabel6.Text = bufWorker.getAge().ToString();  
        }

        private void button3_Click(object sender, EventArgs e)
        {
            ListViewItem item;
            Worker bufWorker = (Worker)treeView1.SelectedNode.Tag;
            if (bufWorker != null)
            {
                    item = new ListViewItem(
                        new string[] 
                            {
                                bufWorker.LastName,
                                bufWorker.FirstName,
                                bufWorker.getAge().ToString()
                            }
                    );
                    item.Tag = bufWorker;
                    listView1.Items.Add(item);
                    bufWorker = null;
            }
        }
    }
}
