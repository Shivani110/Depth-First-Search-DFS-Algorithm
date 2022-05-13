#include <iostream>
#include <list>
using namespace std;

class Grph {
  int nVertices;
  list<int> *adjacents;
  bool *Visit;

   public:
  Grph(int v);
  void Edge(int s, int d);
  void Depth_FS(int V);
};

Grph::Grph(int Vertices) {
  nVertices = Vertices;
  adjacents = new list<int>[Vertices];
  Visit = new bool[Vertices];
}

void Grph::Edge(int s, int d) {
  adjacents[s].push_front(d);
}
void Grph::Depth_FS(int V) {
  Visit[V] = true;
  list<int> adjacent = adjacents[V];

  cout << V  << " ";

  list<int>::iterator m;
  for (m = adjacent.begin(); m != adjacent.end(); ++m)
    if (!Visit[*m])
      Depth_FS(*m);
}

int main() {
  Grph G(5);
  G.Edge(0, 1);
  G.Edge(0, 2);
  G.Edge(1, 1);
  G.Edge(1, 3);
  G.Edge(2, 3);

  G.Depth_FS(0);

  return 0;
}
