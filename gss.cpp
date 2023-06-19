// Link: https://oj.vnoi.info/problem/gss

#include <bits/stdc++.h>

#define MAX(a, b) ((a > b) ? a : b)
#define INVALID -1e9+7

using namespace std;

struct Answer
{
    int max = INVALID;
    int max_left = INVALID, max_right = INVALID, sum = INVALID;

    Answer operator+ (Answer const& obj)
    {
        if (max <= INVALID)
            return obj;
        if (obj.max <= INVALID)
            return *this;
            
        Answer result;
        result.sum = sum + obj.sum;
        result.max_left = MAX(max_left, sum + obj.max_left);
        result.max_right = MAX(max_right + obj.sum, obj.max_right);
        result.max = MAX(max, MAX(obj.max, max_right + obj.max_left));
        return result;
    }
};

class Node
{
public:
    int l, r;
    Answer answer;

    Node()
    {
    }

    Node(int l_, int r_, int val)
    {
        init(l_, r_, val);
    }

    void init(int l_, int r_, int val)
    {
        l = l_;
        r = r_;
        if (l == r) {
            answer.max = answer.max_left = answer.max_right = answer.sum = val;
        }
    }

    Node operator= (Node const& obj)
    {
        Node result(obj.l, obj.r, 0);
        result.answer = obj.answer;
        return result;
    }

    Node operator+ (Node const& obj)
    {
        Node result(l, obj.r, 0);
        result.answer = answer + obj.answer;
        return result;
    }
};

class SegmentTree
{
public:
    std::vector<int> datas;
    std::vector<Node> nodes;
    SegmentTree()
    {
    }

    void initTree()
    {
        nodes.resize(4 * datas.size());
    }

    void createTree(int root, int l, int r)
    {
        if (l == r) {
            nodes[root].init(l, r, datas[l]);
            return;
        }

        nodes[root].init(l, r, datas[l]);
        int m = (r + l) >> 1;
        createTree(root + root + 1, l, m);
        createTree(root + root + 2, m + 1, r);
        nodes[root].answer = nodes[root + root + 1].answer + nodes[root + root + 2].answer;
    }

    Answer getAnswer(int l, int r, int root)
    {
        if (l > nodes[root].r || r < nodes[root].l || l > r || nodes[root].l > nodes[root].r)
            return Answer();

        if (l <= nodes[root].l && r >= nodes[root].r) {
            // if (nodes[root].answer.max > INVALID)
                return nodes[root].answer;
        }

        // int m = (nodes[root].r + nodes[root].l) >> 1;
        // if (l > m) {
        //     nodes[root].answer = getAnswer(l, r, root + root + 2); // Get answer from right child
        //     return nodes[root].answer;
        // }
        // if (r <= m) {
        //     nodes[root].answer = getAnswer(l, r, root + root + 1); // Get answer from left child
        //     return nodes[root].answer;
        // }
        nodes[root].answer = getAnswer(l, r, root + root + 1) + getAnswer(l, r, root + root + 2);
        return nodes[root].answer;
    }
};

class Solver
{
private:
    // Variable here
    int N, M;
    SegmentTree tree;

    std::vector<std::vector<int>> problems;
    std::vector<int> results;

public:
    Solver();
    ~Solver();

    // Input functions
    template <typename T>
    void getVector(std::vector<T>& input_vector); // cin predefined-size vector
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

void Solver::getInputs()
{
    // Get inputs
    scanf("%d", &N);
    tree.datas.resize(N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &tree.datas[i]);
    }
    scanf("%d", &M);
    results.resize(M);
    problems.resize(M, std::vector<int>(2));
    for (int i = 0; i < M; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        problems[i][0] = x - 1;
        problems[i][1] = y - 1;
    }
}

void Solver::printOutputs()
{
    // Print outputs
    // printVector(results);
}

void Solver::execute()
{
    // Running code
    
    /* Build tree */
    tree.initTree();
    tree.createTree(0, 0, N - 1);
    // std::cout << "Init tree done, tree size: " << tree.nodes.size() << std::endl;

    for (int i = 0; i < M; ++i) {
        // std::cout << "Solve problem from " << problems[i][0] 
        //           << " to " << problems[i][1] << std::endl;
        Answer ans = tree.getAnswer(problems[i][0], problems[i][1], 0);
        std::cout << ans.max << std::endl;
    }
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