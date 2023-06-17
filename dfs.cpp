#include <bits/stdc++.h>

using namespace std;

class Solver
{
private:
    // Variable here
    int N = 0, M = 0;
    int count = 0;
    std::vector<int> visit_status;
    std::vector<std::vector<int>> connected_nodes;

public:
    Solver();
    ~Solver();

    // Input functions
    template <typename T>
    void getVector(std::vector<T>& input_vector); // cin predefined-size vector
    void getInputs();

    // Solving functions
    void execute();
    void dfs(int id, int parent_id); // Visit node 'id' from node 'parent_id'

    // Out put functions
    template <typename T>
    void printVector(const std::vector<T>& output_vector);
    void printOutputs();
};

Solver::Solver()
{
}

Solver::~Solver()
{
}

template <typename T>
void Solver::getVector(std::vector<T>& input_vector)
{
    for (auto i = 0; i < input_vector.size(); ++i) {
        std::cin >> input_vector[i];
    }
}

template <typename T>
void Solver::printVector(const std::vector<T>& output_vector)
{
    for (const auto& it : output_vector) {
        std::cout << it << " ";
    }
}

void Solver::getInputs()
{
    // Get inputs
    std::cin >> N >> M;

    // resize vector
    visit_status.resize(N, 0);
    connected_nodes.resize(N, std::vector<int>());

    // get edge
    for (int i = 0; i < M; ++i) {
        int x, y;
        std::cin >> x >> y;
        connected_nodes[x - 1].push_back(y - 1);
        connected_nodes[y - 1].push_back(x - 1);
    }
}

void Solver::printOutputs()
{
    // Print outputs
    std::cout << count;
}

void Solver::execute()
{
    // Running code
    for (int i = 0; i < N; ++i) {
        if (visit_status[i] != 0)
            continue;
        dfs(i, -1);
    }
}

void Solver::dfs(int id, int parent_id)
{
    std::cout << "Visit node " << id << " from node " << parent_id;
    visit_status[id] = 1;
    for (int v : connected_nodes[id]) {
        if (v == parent_id) continue;
        if (visit_status[v] == 0) dfs(v, id);
        else if (visit_status[v] == 1) {
            count++;
        }
    }
    visit_status[id] = 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    Solver solver;

    solver.getInputs();
    solver.execute();
    solver.printOutputs();
    
    cin.tie(NULL);
    
    return 0;
}