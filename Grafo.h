#include <vector>
 
using namespace std;
class Grafo
{
public:
    Grafo();
    Grafo(int nodos);
    vector< vector<int> > prim();
private:
    const int INF = -1;
    int cn; //cantidad de nodos
    vector< vector<int> > ady; //matriz de adyacencia
};