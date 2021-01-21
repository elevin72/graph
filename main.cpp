// Data Structures 2
// Eli Levin
// Assignment 5 - graphs
// implement a graph a model with BFS algorithm

#include "graph.h"
using namespace std;

int main() {
    try {
        string v1, v2, name;
        Graph g;
        int choice;
        cout << "choose one of the following:\n";
        cout << "1 - add a writer\n";
        cout << "2 - delete a writer\n";
        cout << "3 - add a follow up (edge)\n";
        cout << "4 - delete a follow up (edge)\n";
        cout << "5 - print all neighbors (followed)\n";
        cout << "6 - print all followers\n";
        cout << "7 - print all vertices that can be reached from V\n";
        cout << "8 - print all the graph\n";
        cout << "10 - exit";
        cout << endl;

        do {
            cin >> choice;
            switch (choice) {
                case 1:
                    cout << "enter the writer name\n";
                    cin >> v1;
                    g.add_vertex(v1);
                    break;
                case 2:
                    cout << "enter the writer name\n";
                    cin >> v1;
                    if (g.remove_vertex(v1))
                        cout << "success";
                    else
                        cout << "ERROR";
                    break;
                case 3:
                    cout << "enter the follower and the writer\n";
                    cin >> v1 >> v2;
                    if (g.add_edge(v1, v2))
                        cout << "success";
                    else
                        cout << "ERROR";
                    break;
                case 4:
                    cout << "enter the follower and the writer\n";
                    cin >> v1 >> v2;
                    if (g.remove_edge(v1, v2))
                        cout << "success";
                    else
                        cout << "ERROR";
                    break;
                case 5:
                    cout << "enter the v you want to print its neighbours\n";
                    cin >> v1;
                    g.print_neighbors_from(v1);
                    break;
                case 6:
                    cout << "enter the v you want to its followers\n";
                    cin >> v1;
                    if (!g.print_neighbors_to(v1))
                        cout << "ERROR";
                    break;
                case 7:
                    cout << "enter writer\n";
                    cin >> v1;
                    if (!g.print_reachable_from(v1))
                        cout << "ERROR";
                    break;
                case 8:
                    cout << "The graph:\n";
                    g.print();
                    break;

                case 10:
                    cout << "byebye";
                    break;
                default:
                    cout << "ERROR";
            }
            cout << endl;
        } while (choice != 10);
    } catch (string s) {
        cout << s << endl;
    }
    return 0;
}
