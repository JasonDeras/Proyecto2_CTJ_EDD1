#include <vector>
 
using namespace std;
class Grafo
{
public:
    Grafo();
    Grafo(int nodos);
    vector< vector<Object> > prim();
    vector< vector<Object> > kruskal();
private:
    const int INF = -1;
    int cn; //cantidad de nodos
    vector< vector<Object> > ady; //matriz de adyacencia
};
