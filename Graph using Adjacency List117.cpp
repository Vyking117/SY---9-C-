#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph
{
    vector<int> adj[20];
    int n;

public:

    void createGraph()
    {
        cout << "Enter number of vertices: ";
        cin >> n;

        int e;
        cout << "Enter number of edges: ";
        cin >> e;

        cout << "Enter edges:\n";

        for (int i = 0; i < e; i++)
        {
            int a, b;
            cin >> a >> b;

            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }

    void displayList()
    {
        cout << "\nAdjacency List:\n";

        for (int i = 0; i < n; i++)
        {
            cout << i << " -> ";

            for (int j = 0; j < adj[i].size(); j++)
            {
                cout << adj[i][j] << " ";
            }

            cout << endl;
        }
    }

    void BFS(int start)
    {
        bool visited[20] = {false};
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal: ";

        while (!q.empty())
        {
            int x = q.front();
            q.pop();

            cout << x << " ";

            for (int i = 0; i < adj[x].size(); i++)
            {
                int y = adj[x][i];

                if (visited[y] == false)
                {
                    visited[y] = true;
                    q.push(y);
                }
            }
        }

        cout << endl;
    }
};

int main()
{
    Graph g;
    int ch, start;

    do
    {
        cout << "\n===== Graph Menu =====";
        cout << "\n1. Create Graph";
        cout << "\n2. Display Adjacency List";
        cout << "\n3. BFS";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            g.createGraph();
            break;

        case 2:
            g.displayList();
            break;

        case 3:
            cout << "Enter starting vertex: ";
            cin >> start;
            g.BFS(start);
            break;

        case 4:
            cout << "Program Exited.";
            break;

        default:
            cout << "Invalid choice!";
        }

    } while (ch != 4);

    return 0;
}