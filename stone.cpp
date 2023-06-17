// Link: https://oj.vnoi.info/problem/stone1

#include <bits/stdc++.h>

using namespace std;

class Solver
{
struct Node
{
    std::vector<int> childrens;
};

private:
    // Variable here
    int n, result;
    std::vector<Node> nodes;

public:
    Solver();
    ~Solver();

    // Input functions
    template <typename T>
    void getVector(std::vector<T>& input_vector); // cin predefined-size vector
    std::vector<int> getlineToVec(const std::string& str);
    void getInputs();

    // Solving functions
    void execute();
    int solve_tree(int idx); // return true if leaf

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

std::vector<int> Solver::getlineToVec(const std::string& str)
{
    std::vector<int> result;
    std::string cur_element;
    for (auto& character : str) {
        if (character == (char)32) {
            int num = stoi(cur_element);
            result.push_back(num);
            cur_element.clear();
            continue;
        }
        cur_element.push_back(character);
    }
    int num = stoi(cur_element);
    result.push_back(num);
    return result;
}

void Solver::getInputs()
{
    // Get inputs
    scanf("%d", &n);
    result = n;
    nodes.resize(n);
    int node, num_child, child;
    for (;scanf("%d %d", &node, &num_child) == 2;) {
    // for (int it = 0; it < 3; ++it) {
        for (int i = 0; i < num_child; ++i) {
            scanf("%d", &child);
            nodes[node - 1].childrens.push_back(child - 1);
        }
    }
}

void Solver::printOutputs()
{
    // Print outputs
    std::cout << result;
}

void Solver::execute()
{
    // Running code
    result = solve_tree(0);
}

int Solver::solve_tree(int id)
{
    if (nodes[id].childrens.empty()) {
        return 1;
    }

    std::vector<int> child_results;
    for (auto child : nodes[id].childrens) {
        child_results.push_back(solve_tree(child));
    }
    sort(child_results.begin(), child_results.end(), std::greater<int>());
    int tree_result = child_results[0];
    for (uint64_t i = 0; i < child_results.size() - 1; ++i) {
        int cur_result = child_results[i + 1] + i + 1;
        if (cur_result > tree_result) {
            tree_result = cur_result;
        }
    }
    return tree_result;
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