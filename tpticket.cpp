// Link: https://vnoi.info/problems/TPTICKET/

#include <bits/stdc++.h>

using namespace std;

class Solver
{
struct Journey
{
    int departure_station;
    int arrival_station;
};
struct SeatStatus
{
    std::vector<Journey> journeys;
};

private:
    // Variable here
    int N, M, K;
    std::vector<SeatStatus> seats;
    std::vector<Journey> requests;
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
    bool checkSeatAvailable(int request_id, int seat);
    bool checkRequestAvailable(int request_id);

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
    std::cin >> N >> K >> M;
    seats.resize(K);
    results.resize(M, 0);

    for (auto i = 0; i < M; ++i) {
        int a, b;
        Journey journey;
        std::cin >> a >> b;
        journey.departure_station = a;
        journey.arrival_station = b;
        requests.push_back(journey);
    }
}

void Solver::printOutputs()
{
    // Print outputs
    for (int i = 0; i < M; ++i) {
        std::cout << results[i] << std::endl;
    }
}

void Solver::execute()
{
    // Running code
    for (int i = 0; i < M; ++i) {
        // std::cout << "Check request " << i << std::endl;
        checkRequestAvailable(i);
    }
}

bool Solver::checkSeatAvailable(int request_id, int seat)
{
    // Check seat avalible and assign a journey
    if (seats[seat].journeys.empty()) {
        // std::cout << "<> <> Available" << std::endl;/
        seats[seat].journeys.push_back(requests[request_id]);
        return true;
    }

    for (auto& journey : seats[seat].journeys) {
        // std::cout << " - - Check journey from " << journey.departure_station << " to " << journey.arrival_station << std::endl;
        if (!((requests[request_id].departure_station  >= journey.arrival_station) || 
                (requests[request_id].arrival_station <= journey.departure_station))) {
            // std::cout << "<> <> Not available" << std::endl; 
            return false;
        }
    }
    // std::cout << "<> <> Available" << std::endl;
    seats[seat].journeys.push_back(requests[request_id]);
    return true;
}

bool Solver::checkRequestAvailable(int request_id)
{
    for (int seat = 0; seat < K; ++seat) {
        // std::cout << " - Check seat " << seat << " of request " << request_id << " from " 
        //           << requests[request_id].departure_station << " to " << requests[request_id].arrival_station << std::endl;
        if (checkSeatAvailable(request_id, seat)) {
            results[request_id] = 1;
            return true;
        }
    }
    return false;
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