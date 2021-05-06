#include <bits/stdc++.h>
using namespace std;

#define ll long long;

int numberOfBlock, numberOfFilesToCreate, sum = 0, numberOfSearch;

vector<int> arr;
int main()
{
    cin >> numberOfBlock>>numberOfFilesToCreate;

    while(1)
    {
        int num, fileSize;
        cout << "Enter Total File Number: \n";
        cin >> num;
        cout << "Enter Total File Size: \n";
        cin >> fileSize;
        if(fileSize <= numberOfBlock )
        {
            for(int j = 0; j < fileSize; j++)
            {
                arr.push_back(num);
            }
            sum += fileSize;
            numberOfBlock -= fileSize;
            printf("File %d created\n", num);
        }
        else
        {
            cout << "File can't be created\n";
        }
    }
    cout << "Enter number of search: \n";
    cin >> numberOfSearch;
    while(numberOfSearch--)
    {
        int num;
        cout << "Enter fle number: \n";
        cin >> num;
        bool found = false;
        for(int j = 0; j < arr.size(); j++)
        {
            if(arr[j] == num)
            {
                printf("File found in the blocks ");
                found = true;
                for(int k = j; k < arr.size(); k++)
                {
                    if(arr[k] == num)
                    {
                        cout << k << " ";
                    }
                    else
                    {
                        break;
                    }
                }
                cout << endl;
                break;
            }
        }
        if(!found)
        {
            printf("File not Found.\n");
        }
    }
    return 0;
}
