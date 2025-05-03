#include <iostream>
using namespace std;
void bfs(int arr[6][6], int n) {
    int visit[n]={0};
    int queue[2*n];
    int front=0,rear=0;
    for (int i=0;i<n;i++) {
        visit[i]=0;
    }
    queue[rear]=0;
    visit[0]=1;
    rear++;
    while (front!=rear) {
        int node = queue[front];
        front++;
        cout<<node+1<<"";
        for (int i=0;i<n;i++) {
            if (arr[node][i]==1 && visit[i]==0) {
                queue[rear] = i;
                rear++;
                visit[i]=1;
            }
        }
    }
    cout<<endl;
}
void dfs(int graph[6][6], int n) {
    int visit[n]={0};
    int stack[2*n];
    int top=0;
    for (int i=0;i<n;i++) {
        visit[i]=0;
    }
    stack[top]=0;
    while (top!=-1) {
        int node = stack[top];
        top--;
        if (visit[node]==0) {
        cout<<node+1<<""; 
        visit[node]=1;
        
        for (int i=0;i<n;i++) {
            if (graph[node][i]==1) {
                top++;
                stack[top] = i;

                
            }
        }
    }
    }
    cout<<endl;
}
int main() {
    int graph[6][6] = {
        {0, 1, 0, 1, 0, 0},
        {1, 0, 0, 0, 1, 1},
        {0, 0, 0, 1, 1, 1},
        {1, 0, 1, 0, 0, 0},
        {0, 1, 1, 0, 0, 0},
        {0, 1, 1, 0, 0, 0}
    };

    int ch;

    do {
      cout << "\nThe graph is:\n    ";
for (int i = 0; i < 6; i++) {
    cout << i + 1 << "   ";
}
cout << endl;

for (int i = 0; i < 6; i++) {
    cout << i + 1 << " | ";
    for (int j = 0; j < 6; j++) {
        cout << graph[i][j] << "   ";
    }
    cout << endl;
}


        cout << "\n......... MENU .........\n";
        cout << "1. BFS traversal of graph\n";
        cout << "2. DFS traversal of graph\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "BFS traversal of graph: ";
                bfs(graph, 6);
                break;
            case 2:
                cout << "DFS traversal of graph: ";
                dfs(graph, 6);
                break;
            case 3:
                cout << "..... Thank you .....\n";
                exit(0);
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (ch != 3);

    return 0;
}
