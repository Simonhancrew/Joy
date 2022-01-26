#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int n,t;

int main(){
    cin >> n >> t;
    printf("%.6f",(double)n * pow(1.00011,t));
}