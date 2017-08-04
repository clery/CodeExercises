#ifndef EDGE_HH_
# define EDGE_HH_

class Vertex;

class Edge {
  public:
    Edge(Vertex &from, Vertex &to);
    ~Edge();

    Vertex &from;
    Vertex &to;
  private:
};

#endif /* EDGE_HH_ */