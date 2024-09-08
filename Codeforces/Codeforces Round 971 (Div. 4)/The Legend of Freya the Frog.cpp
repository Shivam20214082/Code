#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        long long x, y, k;
        cin >> x >> y >> k;
        
        // Calculate the number of moves required to cover x and y
        long long x_moves = (x + k - 1) / k;  // Equivalent to ceil(x / k)
        long long y_moves = (y + k - 1) / k;  // Equivalent to ceil(y / k)
        
        // The total moves are the sum of x_moves and y_moves
        int z=abs(x_moves-y_moves);
        if(x_moves>y_moves)z-=1;
        cout << x_moves + y_moves + z << endl;
        
    }
    
    return 0;
}
