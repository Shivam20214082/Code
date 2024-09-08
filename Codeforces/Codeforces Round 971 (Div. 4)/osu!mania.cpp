#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> result;
        
        // Reading the rows and processing from bottom to top
        vector<string> rows(n);
        for (int i = 0; i < n; i++) {
            cin >> rows[i];
        }
        
        // Processing from bottom row to top row
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < 4; j++) {
                if (rows[i][j] == '#') {
                    result.push_back(j + 1);  // Store 1-based index
                    break;
                }
            }
        }
        
        // Output the result for this test case
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
