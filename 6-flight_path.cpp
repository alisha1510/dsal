/* There are flight paths between cities. If there is a flight between city A and city B then there is an edge between the cities. 
The cost of the edge can be the time that flight take to reach city B from A, or the amount of fuel used for the journey. 
Represent this as a graph. The node can be represented by airport name or name of the city.
Use adjacency list representation of the graph or use adjacency matrix representation of the graph.
Check whether the graph is connected or not. Justify the storage representation used.*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string city[20];
    int time_matrix[50][50] = {0}; // Time to travel
    int cost_matrix[50][50] = {0}; // Cost of travel

    cout << "Enter number of cities: ";
    cin >> n;

    // Input city names   
    for (int i = 0; i < n; i++) {
        cout << "Enter the name of city " << i + 1 << ": ";
        cin >> city[i];
    }

    // Input time and cost between cities
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cout << "\nFlight from " << city[i] << " to " << city[j] << ":\n";
            cout << "Enter time  ";
            cin >> time_matrix[i][j];
            time_matrix[j][i] = time_matrix[i][j];

            cout << "Enter cost : ";
            cin >> cost_matrix[i][j];
            cost_matrix[j][i] = cost_matrix[i][j];
        }
    }

    // Display Time Matrix
    cout << "\n=== Time Matrix  ===" << endl;
    cout << "\t";
    for (int i = 0; i < n; i++) {
        cout << city[i] << "\t";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << city[i] << "\t";
        for (int j = 0; j < n; j++) {
            cout << time_matrix[i][j] << "\t";
        }
        cout << endl;
    }

    // Display Cost Matrix
    cout << "\n=== Cost Matrix  ===" << endl;
    cout << "\t";
    for (int i = 0; i < n; i++) {
        cout << city[i] << "\t";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << city[i] << "\t";
        for (int j = 0; j < n; j++) {
            cout << cost_matrix[i][j] << "\t";
        }
        cout << endl;
    }
