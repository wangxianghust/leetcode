#include <iostream>
using namespace std;

#define set_bit(bitmap, c) ( (bitmap)[(c) >> 5] |= ( 1U << ( (c)&31 )  )  )
#define FOR(i,n) for(int i=0, _n = (int)n; i < _n; ++i)

int main() {
    unsigned int m[8];
    FOR(i,8) cout << m[i] << " ";
    cout << endl;
    set_bit(m, ')');
    set_bit(m, '$');
    FOR(i,8) cout << m[i] << " ";
    cout << endl;
    cout << ('$' & 31) << endl;
    return 0;
}
