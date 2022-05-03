//kruskal
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int getRoot(vector<int>& parent, int x)  // 인수로 넘긴 정점의 부모 정점을 알려줌
{
    if (parent[x] == x) return x;
    return parent[x] = getRoot(parent, parent[x]);
}

void unionParent(vector<int>& parent, int a, int b)  // 두 정점을 병합함. 부모가 같은, 같은 그룹으로.
{
    int par_a = getRoot(parent, a);
    int par_b = getRoot(parent, b);
    if(par_a < par_b) parent[par_b] = par_a;
    else parent[par_a] = par_b;
}

bool find(vector<int>& parent, int a, int b)  // 두 정점이 같은 부모를 가졌는지 확인
{
    int par_a = getRoot(parent, a);
    int par_b = getRoot(parent, b);
    if(par_a == par_b) return true;
    else return false;
}

bool compare(vector<int> a, vector<int> b)
{
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {	
    int answer = 0;
    
	sort(costs.begin(), costs.end(), compare);
    
    vector<int> parents(n);
    
    for(int i = 0; i < parents.size(); i++)
        parents[i] = i;
    
    for(int i = 0; i < costs.size(); i++)
    {
        if(!find(parents, costs[i][0], costs[i][1]))
        {
            unionParent(parents, costs[i][0], costs[i][1]);
            answer += costs[i][2];
        }
    }

	return answer;
}

//prim
#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int solution(int n, vector<vector<int>> costs) {
	int answer = 0;

	vector<vector<int>> graph(n, vector<int>(n));
	for (int i = 0; i < costs.size(); i++)
	{
		graph[costs[i][0]][costs[i][1]] = costs[i][2];
		graph[costs[i][1]][costs[i][0]] = costs[i][2];
	}

	vector<int> visited;
	vector<int> unvisited;

	visited.push_back(0);
	for (int i = 1; i < n; i++)
		unvisited.push_back(i);

	for (int i = 1; i < n; i++)
	{
		int min = INT_MAX;
		int min_index = 0;

		for (int j = 0; j < i; j++)
		{
			for (int k = 0; k < n - i; k++)
			{
				if (graph[visited[j]][unvisited[k]] > 0 && min > graph[visited[j]][unvisited[k]])
				{
					min = graph[visited[j]][unvisited[k]];
					min_index = k;
				}
			}
		}

		visited.push_back(unvisited[min_index]);
		unvisited.erase(unvisited.begin() + min_index);
		answer += min;
	}

	return answer;
}