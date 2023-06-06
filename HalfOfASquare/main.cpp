#include <iostream>
#include <cstdlib>

using namespace std;

void partOne(int squareSize)
{
    for(int i = 0; i < squareSize; i++)
    {
        // for(int j = squareSize - i; j > 0; j--)
        // {
        //     cout << "#";
        // }
        // cout << "\n";
        for(int j = 0; j < (squareSize - i); j++)
        {
            cout << "#";
        }
        cout << "\n";
    }
}

void partTwo(int triangleSize)
{
    int halfSize = triangleSize / 2;
    for(int i = 0; i < triangleSize; i++)
    {
        for(int j = 0; j <= halfSize - abs(halfSize - i); j++)
        {
            cout << "#";
        }
        cout << "\n";
    }
}

int main()
{
    partTwo(7);
}