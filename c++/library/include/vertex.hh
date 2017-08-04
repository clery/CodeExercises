#ifndef VERTEX_HH_
# define VERTEX_HH_

using namespace std;

# include <vector>
# include "edge.hh"

class Vertex {
  public:
    Vertex();
    ~Vertex();

    Edge &AddEdge(Vertex &v);
    vector<Edge&> edges;
  private:
};

#endif /* VERTEX_HH_ */