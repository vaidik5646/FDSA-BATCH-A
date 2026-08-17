#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    int arr[100];

    cout << "Enter colour codes (0, 1, 2): ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int low = 0;
    int mid = 0;
    int high = n - 1;

    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            int temp = arr[low];
            arr[low] = arr[mid];
            arr[mid] = temp;

            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else if (arr[mid] == 2)
        {
            int temp = arr[mid];
            arr[mid] = arr[high];
            arr[high] = temp;

            high--;
        }
    }

    cout << "Sorted colour codes: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
