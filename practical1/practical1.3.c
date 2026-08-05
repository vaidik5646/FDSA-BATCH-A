
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of words: ";
    cin >> n;

    char word[100], longest[100];
    int max = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> word;
        int count = 0;
        for (int j = 0; word[j] != '\0'; j++)
        {
            count++;
        }
        if (count > max)
        {
            max = count;
            int j;
            for (j = 0; word[j] != '\0'; j++)
            {
                longest[j] = word[j];
            }
            longest[j] = '\0';
        }
    }
    cout << "Longest Word: " << longest << endl;
    cout << "Length: " << max << endl;

    return 0;
}