#include <bits/stdc++.h>

using namespace std;

class Solver
{
private:
    // Variable here
    int N, M;
    std::vector<int> results;

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
    std::string line;
    getline(std::cin, line);
    results = getlineToVec(line);
}

void Solver::printOutputs()
{
    // Print outputs
    printVector(results);
}

void Solver::execute()
{
    // Running code
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