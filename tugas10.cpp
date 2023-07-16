#include <bits/stdc++.h>
//ukuran array
#define MAX 100005
//inf -> sbg nilai tak hingga untuk inisialisasi jaraj awal
#define INF INT_MAX 

using namespace std;
//membuat array dari vector pasangan bilangan bulat 'adj' dengan ukuran 'max'
vector<pair<int, int> > adj[MAX];
bool vis[MAX];
int dist[MAX];
//berisi algoritma dijkstra -> untuk mencari lintasan terpendek
void dijkstra(int start)
{
  memset(vis, false, sizeof vis); //memastikan bahwa semua simpul awal belum dikunjungi saat algoritma dimulai
  for(int i=0; i<MAX; i++)
    dist[i] = INF; //inisialisasi semua elemen array 'dist' dengan nilai tak hingga
  dist[start] = 0; 

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq; //antrian prioritas
  pq.push({0, start});

  while(!pq.empty()) //memulai loop utama yang berjalan selama antrian prioritas tidak kosong
    {
      //mengambil anrian prioritas teratas
      pair<int, int> p = pq.top();
      pq.pop();

      int x = p.second;
      if(vis[x])
        continue;
      vis[x] = true;

      for(int i=0; i<adj[x].size(); i++)
        {
          int e = adj[x][i].first;
          int w = adj[x][i].second;
          if(dist[x] + w < dist[e])
          {
            dist[e] = dist[x] + w;
            pq.push({dist[e], e});
          }
        }
    }
}

int main()
{
  adj[1].push_back({2, 7});
  adj[1].push_back({3, 9});
  adj[1].push_back({6, 14});
  adj[2].push_back({1, 7});
  adj[2].push_back({3, 10});
  adj[2].push_back({4, 15});
  adj[3].push_back({1, 9});
  adj[3].push_back({2, 10});
  adj[3].push_back({4, 11});
  adj[3].push_back({6, 2});
  adj[4].push_back({2, 15});
  adj[4].push_back({3, 11});
  adj[4].push_back({5, 6});
  adj[5].push_back({4, 6});
  adj[5].push_back({6, 9});
  adj[6].push_back({1, 14});
  adj[6].push_back({3, 3});
  adj[6].push_back({5, 9});

  dijkstra(1);

  cout << "Jarak terpendek dari node 1 ke node 5 adalah " << dist[5] << endl;

  return 0;
}
