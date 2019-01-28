#include <iostream>
#include <climits>
#include <vector>

using namespace std;

typedef struct{
	int key;
	int label;
	bool used;
	vector<int> distances;
	vector<int> adj;
} Vertex;

void fixHeap(vector<Vertex> vertexes, int changed_elem)
{
	int i =  (changed_elem-1) / 2;
	
	while (vertexes[changed_elem].key < vertexes[i].key) 
		i = (i - 1) / 2;
	Vertex aux = vertexes[i];
	vertexes[i] = vertexes[changed_elem];
	vertexes[changed_elem] = aux;
	
}

// Algoritmo de Prim
void prim(int V, vector<Vertex>& vertexes)
{		
	int light_cost;
	int total_light=0;
	
	vertexes[0].key = 0;
	int u, v, n_adj;

	// Para cada vértice
	while (!vertexes.empty())
	{
		vertexes[0].used = true;
		
		n_adj = vertexes[0].adj.size();
		
		for (int j = 0; j < n_adj; j++)
		{
			v = adj[u][j].label;
			if (!vertexes[v].used && distances[u][j] < vertexes[v].key) 
			{
				vertexes[v].key = distances[u][j];
				adj[u][j].key = distances[u][j];
				light_cost = vertexes[v].key;
			}
		}
		total_cost += light_cost;
	}
	
	return total_cost;
	
}

int main()
{
	int V, E, a, b, cost;
	vector<Vertex> vertexes;

	while (cin >> V >> E && V!=0 && E!=0)
	{
		vector<Vertex> adj[V];
		vector<int> distances[V];
		
		int w[V * V];
		int totalCost = 0;
		
		for (int i = 0; i < V; i++)
		{
			Vertex v;
			v.key = INT_MAX;
			v.label = i; // número do vértice
			v.used = false; // used indica se um vértice já foi mapeado
		
			vertexes.push_back(v);
		
		}
		
		// Cria pesos e listas de adjacências
		for (int i = 0; i < E; i++)
		{
			cin >> a >> b >> cost;
			
			vertexes[a].adj.push_back(vertexes[b]);
			vertexes[b].adj.push_back(vertexes[a]);
		
			vertexes[a].distances.push_back(cost);
			vertexes[b].distances.push_back(cost);
		
			totalCost += cost;
		}
		
		/*for (int i = 0; i < V;i++)
		{
			cout << i << ": ";
			for(int j = 0; j < distances[i].size(); j++)
			{
				cout << adj[i][j].label << "-" << distances[i][j] << "; ";
		
			}
				
			cout << endl;
		}*/
		
		int iluminatedArea = prim(V, vertexes);
		
		vertexes.clear();
		for (int i = 0; i < V; i++)
		{
			adj[i].clear();
			distances[i].clear();
		}
		
		cout << (totalCost-iluminatedArea) << endl;	
		
	}
	
	
	return 0;
}