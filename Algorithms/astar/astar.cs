/**********************************************
* Author: Gerald Selvino
* Description: A-Star algorithm demo
* Language: C#
***********************************************/
using System;
using System.Collections.Generic;
using System.Text;

namespace AStar
{
    class Vertex
    {
        string _name;
        int _distance;
        int _mapplacement; //order of location in the map, used in computing the heuristic distance
        int _hdistance; //heuristic distance

        Vertex _prev = null;
        public Vertex(string name, int distance, int mapplacement)
        {
            _name = name;
            _distance = distance;
            _hdistance = 0;
            _mapplacement = mapplacement;
        }
        public Vertex Prev
        {
            get { return _prev; }
            set { _prev = value; }
        }
        public int Distance
        {
            get { return _distance; }
            set { _distance = value; }
        }
        public int HeuristicDistance
        {
            get { return _hdistance; }
            set { _hdistance = value; }
        }
        public int MapPlacement
        {
            get { return _mapplacement; }
            set { _mapplacement = value; }
        }
        public string Name
        {
            get { return _name; }
            set { _name = value; }
        }
    }

    class Edge
    {
        int _weight;
        Vertex _from;
        Vertex _to;
        public Edge(int weight, Vertex from, Vertex to)
        {
            _weight = weight;
            _from = from;
            _to = to;
        }
        public int Weight
        {
            get { return _weight; }
            set { _weight = value; }
        }
        public Vertex From
        {
            get { return _from; }
            set { _from = value; }
        }
        public Vertex To
        {
            get { return _to; }
            set { _to = value; }
        }
    }

    class Graph
    {
        const int MaxDistance = 1000;
        static Dictionary<string,Vertex> _vertices = new Dictionary<string,Vertex>() 
        { 
            {"0", new Vertex("0", 0, 0)},
            {"1", new Vertex("1", MaxDistance, 1)},
            {"7", new Vertex("7", MaxDistance, 1)},
            {"2", new Vertex("2", MaxDistance, 2)},
            {"8", new Vertex("8", MaxDistance, 3)},
            {"6", new Vertex("6", MaxDistance, 2)},
            {"5", new Vertex("5", MaxDistance, 3)},
            {"3", new Vertex("3", MaxDistance, 3)},
            {"4", new Vertex("4", MaxDistance, 4)}
        };
        List<Edge> _edges = new List<Edge>() 
        { 
            new Edge(4, _vertices["0"], _vertices["1"]),
            new Edge(8, _vertices["0"], _vertices["7"]),
            new Edge(11, _vertices["1"], _vertices["7"]),
            new Edge(8, _vertices["1"], _vertices["2"]),
            new Edge(7, _vertices["7"], _vertices["8"]),
            new Edge(1, _vertices["7"], _vertices["6"]),
            new Edge(2, _vertices["2"], _vertices["8"]),
            new Edge(6, _vertices["6"], _vertices["8"]),
            new Edge(4, _vertices["2"], _vertices["5"]),
            new Edge(7, _vertices["2"], _vertices["3"]),
            new Edge(14, _vertices["3"], _vertices["5"]),
            new Edge(9, _vertices["3"], _vertices["4"]),
            new Edge(2, _vertices["6"], _vertices["5"]),
            new Edge(10, _vertices["5"], _vertices["4"])
        };
        public Dictionary<string, Vertex> Vertices
        {
            get { return _vertices; }
        }
        public List<Edge> Edges
        {
            get { return _edges; }
        }
    }

    class Program
    {
        const int MaxDistance = 1000;
        static Dictionary<string,Vertex> AStar(Graph rGraph)
        {
            Dictionary<string, Vertex> Undiscovered = new Dictionary<string, Vertex>();
            Dictionary<string, Vertex> ShortestPathTree = new Dictionary<string, Vertex>();

            Vertex CurrentNode = rGraph.Vertices["0"];
            Undiscovered.Add(CurrentNode.Name, CurrentNode);
 
            while (Undiscovered.Count > 0)
            {
                ShortestPathTree.Add(CurrentNode.Name, CurrentNode);
                Undiscovered.Remove(CurrentNode.Name);
                exploreAdjacent(CurrentNode, rGraph, ref Undiscovered, ShortestPathTree);
                Vertex MinNode = getMinVertex(Undiscovered);
                CurrentNode = MinNode;
            }

            return ShortestPathTree;
        }

        static void exploreAdjacent(Vertex pCurrent, Graph pGraph, ref Dictionary<string, Vertex> pU, Dictionary<string, Vertex> pS)
        {
            for (int i = 0; i < pGraph.Edges.Count; i++)
            {
                if (pCurrent.Equals(pGraph.Edges[i].From) && !pS.ContainsKey(pGraph.Edges[i].To.Name))
                {
                    int prevDistance = pGraph.Edges[i].From.Distance;

                    if (pGraph.Edges[i].Weight + prevDistance < pGraph.Edges[i].To.Distance)
                    {
                        pGraph.Edges[i].To.Distance = pGraph.Edges[i].Weight + prevDistance;
                        pGraph.Edges[i].To.Prev = pGraph.Edges[i].From;

                        // Heuristic computation using Manhattan Distance adapted to our demo graph
                        // i.e. get the current map placement of the vertex being processed and
                        // subtract it to the map placement of the destination vertex, then multiply it
                        // by 1 which is the lowest cost of the edge found in our demo graph
                        pGraph.Edges[i].To.HeuristicDistance = pGraph.Edges[i].To.Distance + (1 * (pGraph.Vertices["4"].MapPlacement - pGraph.Edges[i].To.MapPlacement));

                        if (pU.ContainsKey(pGraph.Edges[i].To.Name))
                        {
                            if (pGraph.Edges[i].To.HeuristicDistance < pU[pGraph.Edges[i].To.Name].HeuristicDistance)
                            {
                                pU[pGraph.Edges[i].To.Name] = pGraph.Edges[i].To;
                            }
                        }
                        else
                        {
                            pU.Add(pGraph.Edges[i].To.Name, pGraph.Edges[i].To);
                        }
                    }
                }
            }
        }

        static Vertex getMinVertex(Dictionary<string, Vertex> pU)
        {
            Vertex ret = new Vertex("", MaxDistance, 0);
            ret.HeuristicDistance = MaxDistance;

            foreach (KeyValuePair<string, Vertex> v in pU)
            {
                if (v.Value.HeuristicDistance < ret.HeuristicDistance)
                {
                    ret = v.Value;
                }
            }

            return ret;
        }

        static void Main(string[] args)
        {
            Graph g = new Graph();
            Dictionary<string, Vertex> l_Spt = AStar(g);
            Vertex endNode = l_Spt["4"];

            while (endNode != null)
            {
                Console.WriteLine(endNode.Name);
                endNode = endNode.Prev;
            }
            Console.ReadLine();
        }
    }
}
