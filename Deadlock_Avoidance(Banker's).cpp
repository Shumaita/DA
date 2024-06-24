// DEADLOCK AVOIDANCE ALGORITHM- BANKER'S
// Implemented by myself
// Got some help from chatgpt

#include <iostream>
using namespace std;

int main() {
// Step 1: Take input for the number of processes and resources

    int n, m;
    cout << "Enter the number of processes: ";
    cin >> n;
    cout << "Enter the number of resources: ";
    cin >> m;

// Step 2: Declare arrays to store allocation, maximum, and available resources
    int alloc[n][m], max[n][m], avail[m];

// Step 3: Take input for the allocation matrix
    cout << "Enter the allocation matrix:" << endl;

    for (int i = 0; i < n; i++) {
        cout << "For process P" << i << ": ";//5 ta process(P0,P1,P2,P3,P4)

        for (int j = 0; j < m; j++) {//3 ta resource(A,B,C)
            cin >> alloc[i][j];
        }
    }

// Step 4: Take input for the maximum matrix
    cout << "Enter the maximum matrix:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "For process P" << i << ": ";
        for (int j = 0; j < m; j++) {
            cin >> max[i][j];
        }
    }

 // Step 5: Take input for the available resources
    cout << "Enter the available resources:" << endl;
    for (int i = 0; i < m; i++) {
        cout << "Resource " << i << ": ";
        cin >> avail[i];
    }

    int f[n], ans[n], ind = 0;
    for (int k = 0; k < n; k++) {
        f[k] = 0;
    }
    //complexity  : O(n)
    int need[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];//Need matrix ber kora hocche, max theke allocation subtract kore
    }
    //complexity : O(n * m)

   // SAFETY ALGORITHM
    int y = 0;
    for (int k = 0; k < n; k++) {//O(n)
        for (int i = 0; i < n; i++) {//O(n)
            if (f[i] == 0) {//process dekhbe ashche nki age, 0 mane process ekhono execute kore nai
                int flag = 0;
                for (int j = 0; j < m; j++) {//O(m)
                    if (need[i][j] > avail[j]) { //need k obosshoi work(avail) theke choto hote hobe
                        flag = 1;
                        break;//need jehetu boro tai loop break korlo
                    }
                }
//PURO KAJ TA EKSHATE && DIYE KORTE BOLSE(false[
//total complexity : O(n^2 * m)
//Checks if the flag variable is still 0 after examining all resources. If it's 0, it means that process i can be executed safely.
                if (flag == 0) {
                    ans[ind++] = i;
// If the condition is true(flag er man 0), process i can be executed safely.
//tai i is added to the safe sequence stored in the ans[] array at the index indicated by ind
                    for (y = 0; y < m; y++)
                        avail[y] += alloc[i][y];//work=avail,ja alloc e thakbe, means avail ta update hote thakbe
                    f[i] = 1;
                }
            }
        }
    }

    int flag = 1;

    // To check if sequence is safe or not
    for (int i = 0; i < n; i++) {
        if (f[i] == 0) {
            flag = 0;
            cout << "The given sequence is not safe";
            break;
        }
    }

    if (flag == 1) {
        cout << "Following is the SAFE Sequence" << endl;
        for (int i = 0; i < n - 1; i++)
            cout << " P" << ans[i] << " ->";
        cout << " P" << ans[n - 1] << endl;
    }

    return 0;
}

//total complexity: O(n^2 * m)
