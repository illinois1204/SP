#include <iostream>

using namespace std;
/*
     1  0  0  0  1 
     0  1  0  1  0 
     0  0  1  0  0 
     0  1  0  1  0 
     1  0  0  0  1
*/
int main()
{
	cout << "\tArray" << endl;
    const int n = 7;
    int Matrix[n*n];

    for (char i = 0; i < n; i++) 
    {
        for (char j = 0; j < n; j++) 
        {
            Matrix[n*i+j] = 0;
        }
        Matrix[n*i+i] = 1;
        Matrix[n*i+(n-1-i)] = 1;
    }

    for (char i = 0; i < n*n; i+=n)
    {
        for (char j = 0; j < n; j++)
        {
            cout << Matrix[i+j] << "  ";
        }
        cout << endl;
    }
	return 0;
}
