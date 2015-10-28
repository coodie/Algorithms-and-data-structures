#include <iostream>
using namespace std;

class UnionFind
{
    public:
        int *rank;
        int *parent;
        UnionFind(int n)
        {
            rank = new int[n];
            parent = new int[n];
            for(int i = 0; i < n; i++)
            {
                rank[i] = 0;
                parent[i] = i;
            }
        }
        int Find(int v)
        {
            if(parent[v] == v)
                return v;
            parent[v] = Find(parent[v]);
            return parent[v];
        }

        bool Union(int x, int y)
        {
            int xRoot = Find(x);
            int yRoot = Find(y);
            if(xRoot == yRoot) return false;
            if(rank[xRoot] >= rank[yRoot])
            {
                parent[yRoot] = xRoot;
                rank[xRoot] += rank[yRoot];
            }
            else
            {
                parent[xRoot] = yRoot;
                rank[yRoot] += rank[xRoot];
            }
            return true;
        }
	~UnionFind()
	{
		delete[] rank;
		delete[] parent;
	}
};

int main()
{
    UnionFind UF(5);
    UF.Union(3, 4);
    cout << (UF.Find(3) == UF.Find(4)) << endl;
    UF.Union(4, 1);
    cout << (UF.Find(2) == UF.Find(4)) << endl;
}
