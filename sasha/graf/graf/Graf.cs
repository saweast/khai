using System;
using System.Collections.Generic;
using System.Text;

namespace graf
{
    public class Graf<T>
    {
        public class pair
        {
            public int from, to,cost;
            public pair(int from, int to)
            {
                this.from = from;
                this.to = to;
                cost = -1;
            }

            public pair(int from, int to, int cost):this(from,to)
            {
                this.cost = cost;
            }
        }
        public class node
        {
            public int Key;
            public object Tag;
            public T Value;
            public bool Walked;
            public node(int key,T Value)
            {
                this.Key = key;
                this.Value = Value;
                this.Tag = null;
                this.Walked=false;
            }
        }

        public Graf()
        {
        }

        public Graf(Graf<T> from)
        {
            this.vertexs = from.vertexs;
            this.source=from.source;
            this.vertexcount = from.vertexcount;
        }

        protected int vertexcount=0;

        private List<pair> source=new List<pair>();

        public List<pair> Links
        {
          get { return source; }
        }
        private Dictionary<int,node> vertexs = new Dictionary<int,node>();

        public Dictionary<int, node> Vertexs
        {
          get { return vertexs; }
        }

        public virtual void AddVertex(int key,T value)
        {
            if (!Contains(key))
            {
                vertexs.Add(key,new node(key,value));
                vertexcount++;
            }
        }

        public virtual void RemoveVertex(int key)
        {
                   if(vertexs.Remove(key))
                    vertexcount--;
        }

        public int VertexCount
        {
            get { return vertexs.Count; }
        }

        public virtual void Link(int from, int to)
        {
            if(!ContainsLink(from,to))
                source.Add(new pair(from,to));
        }

        public virtual void Link(int from, int to, int cost)
        {
            if (!ContainsLink(from, to))
                source.Add(new pair(from, to, cost));
        }

        public virtual void UnLink(int from, int to)
        {
            for (int i = 0; i < source.Count; i++)
                if ((source[i].from == from && source[i].to == to) ||
                    (source[i].to == from && source[i].from == to))
                    source.RemoveAt(i);
        }

        public bool ContainsLink(int from, int to)
        {
            foreach (pair p in source)
                if ((p.from == from && p.to == to) ||
                   ( p.to == from&& p.from == to))
                    return true;
            return false;
        }

        public bool Contains(int key)
        {
            return vertexs.ContainsKey(key);
        }

        public T GetValue(int key)
        {
            return vertexs[key].Value;
        }

        public void SetValue(int index,T value)
        {
            vertexs[index].Value = value;
        }

        public node this[int key]
        {
            get{
                return vertexs[key];
            }
        }

        public void _walkDepth(node current, Action<node> action)
        {
            current.Walked = true;
            action(current);

            foreach (pair p in source)
            {
                if (p.from == current.Key && !vertexs[p.from].Walked)
                    _walkDepth(vertexs[p.from], action);
                if (p.to == current.Key && !vertexs[p.to].Walked)
                    _walkDepth(vertexs[p.to], action);
            }

            foreach (node p in vertexs.Values)
                if (!p.Walked)
                    _walkDepth(p, action);
        }

        public void WalkDepth(int start,Action<node> action)
        {
            _walkDepth(vertexs[start], action);
        }

        public void WalkWidth(int start, Action<node> action)
        {
            Queue<int> queue = new Queue<int>();
            queue.Enqueue(start);

            while (queue.Count != 0)
            {
                int n = queue.Dequeue();
                if (!vertexs[n].Walked)
                {
                    vertexs[n].Walked = true;
                    action(vertexs[n]);
                    foreach (pair p in source)
                    {
                        if (p.from == n)
                            queue.Enqueue(p.to);
                        if (p.to == n)
                            queue.Enqueue(p.from);
                    }
                }
            }
        }

        public void ClearWalk()
        {
            foreach (node p in vertexs.Values)
                p.Walked = false;
        }

        public static int GetFirst(IEnumerable<int> arr)
        {
            foreach (int i in arr)
                return i;
            return default(int);
        }

        public static void Prima(Graf<T> graf)
        {
            int k = GetFirst(graf.Vertexs.Keys);

            Graf<T> temp=new Graf<T>(graf);
 
            List<int> U=new List<int>();
            U.Add(k);

            List<int> vU = new List<int>();
            vU.AddRange(graf.Vertexs.Keys);

            vU.Remove(k);

            pair[] templinks=new pair[graf.Links.Count];
            graf.Links.CopyTo(templinks);
            graf.Links.Clear();

            while (vU.Count>0)
            {
                pair min=null;
                foreach (pair p in templinks)
                {
                    if(U.Contains( p.from)&&(vU.Contains(p.to))||
                        (U.Contains(p.to)&&(vU.Contains(p.from))))
                    if(min==null||p.cost<min.cost)                        
                            min=p;
                }

                graf.Link(min.from,min.to,min.cost);
                
                if(U.Contains(min.from))
                {
                    U.Add(min.to);
                    vU.Remove(min.to);
                }else
                {
                    U.Add(min.from);
                    vU.Remove(min.from);
                }
            }
        }
    }
}
