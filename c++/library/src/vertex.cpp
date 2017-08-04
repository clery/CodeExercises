#include "vertex.hh"

Vertex::Vertex() {
  edges = vector<Edge&>();
}

Vertex::~Vertex() {}

Edge &Vertex::AddEdge(Vertex &v) {
  edges.push_back(new Edge(this, v));
  return edges.back();
}

int main() {
  Vertex v1 = Vertex();
  Vertex v2 = Vertex();
  v1.AddEdge(v2);

  return (0);
}