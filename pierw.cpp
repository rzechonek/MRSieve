# include <iostream>
# include <iomanip>

using namespace std;

unsigned pierw(unsigned n) {
    if (n == 0) return 0;
    if (n < 4) return 1;
    unsigned b1 = 2u, b2 = 8u;
}

int main() {
    unsigned n;
    cin >> n;
    cout << pierw(n) << endl;
    return 0;
}

