using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab4Ex1
{
    public partial class Form1 : Form
    {
        ListViewItem item;
        Worker bufWorker;
        Worker checkWorker;
        Random r;
        TreeNode bufTreeNode;


        public Form1()
        {
            InitializeComponent();
            listView1.View = View.Details;
            bufWorker = checkWorker = null;
            r = new Random();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            treeView1.Nodes.Clear();
            statusStrip1.Items[0].Text = "";
            listView1.Items.Clear();

            treeView1.Nodes.Add(new TreeNode("Workers"));

            r = new Random();
            int count = r.Next(10, 30);

            for (int i = 0; i < count; i++)
            {
                bufWorker = new Worker("FirstName" + i, "LastName" + i, r.Next(0, 101));
                bufTreeNode = new TreeNode(bufWorker.LastName);
                bufTreeNode.Tag = bufWorker;
                treeView1.Nodes[0].Nodes.Add(bufTreeNode);
            }

            for (int i = 0; i < count; i++)
            {
                bufWorker = new Worker("FirstName" + i, "LastName" + i, r.Next(0, 101));
                bufTreeNode = new TreeNode(bufWorker.LastName);
                bufTreeNode.Tag = bufWorker;
                treeView1.Nodes[0].Nodes[5].Nodes.Add(bufTreeNode);
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            try
            {
                bufWorker = treeView1.SelectedNode.Tag as Worker;
                if (bufWorker != null)
                {
                    statusStrip1.Items[0].Text = "LastName: " + bufWorker.LastName +
                                             " | FirstName: " + bufWorker.FirstName +
                                             " | Age: " + bufWorker.Age;
                    bufWorker = null;
                }
                else MessageBox.Show("Select element tree with object type - Worker!");
            }
            catch(NullReferenceException)
            {
                MessageBox.Show("Select element tree with object type - Worker!");
            }
        }

        bool Check(Worker worker)
        {
            foreach(ListViewItem item in listView1.Items)
            {
                checkWorker = item.Tag as Worker;
                if (checkWorker != null && checkWorker == worker) return false;
            }
            return true;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            try
            {
                bufWorker = treeView1.SelectedNode.Tag as Worker;
                if (bufWorker != null)
                {
                    if(Check(bufWorker))
                    {
                        item = new ListViewItem(
                            new string[] 
                            {
                                bufWorker.LastName,
                                bufWorker.FirstName,
                                bufWorker.Age.ToString()
                            }
                        );
                        item.Tag = bufWorker;
                        listView1.Items.Add(item);
                        bufWorker = null;
                    }
                    else MessageBox.Show("The selected tree item is already in the list!");
                }
                else MessageBox.Show("Select element tree with object type - Worker!");
            }
            catch (NullReferenceException)
            {
                MessageBox.Show("Select element tree with object type - Worker!");
            }
        }
    }
}
