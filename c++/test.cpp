#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> v(10, 3);
    for (int i:v) cout<<i<<"\n";
    return 0;
}
