// 1
#include<iostream>
#include<stdio.h>
using namespace std;
void create(int arr[], int n)
{
    cout << "enter the elements of an array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

int display(int arr[], int n)
{
    cout << "the elements are :" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << " now,size of array is: " << n << endl;
    return n;
}

void insert(int arr[], int &n, int pos, int val)
{
    if (pos < 0 || pos > n)
    {
        cout << "enter a valid position:" << endl;
        return;
    }
    cout << "insertion when the position is equal to index:" << endl;
    for (int i = n - 1; i >= pos; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[pos] = val;
    n++;
    display(arr, n);
}

void del1(int arr[], int &n, int index)
{
    cout << "delete by index:" << endl;
    if (index < 0 || index >= n)
    {
        cout << "Enter a valid index!" << endl;
        return;
    }
    for (int i = index; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    n--;
    cout << "element present at index : " << index << "is now deleted" << endl;
    cout << "now array looks like: " << display(arr, n);
}

void del_value(int arr[], int &n, int val)
{
    cout << "delete by value:" << endl;
    int j = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == val)
        {
            j = i;
            break;
        }
    }
    if (j == -1)
    {
        cout << "deletion not possible: as no such no. exits in array" << endl;
        return;
    }
    for (int i = j; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    n--;
    cout << "value : " << val << "now deleted" << endl;
    display(arr, n);
}

void search(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            cout << "element found at index " << i << endl;
            return;
        }
    }
    cout << "key not found" << endl;
}

int main()
{
    const int max_v = 100;
    int arr[max_v];
    int n = 6;
    int val = 1000;
    int pos = 3;
    int index = 2;
    int key = 5;
    int choice;
    do
    {
        cout << "\nâ€”â€”MENUâ€”â€”\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE BY INDEX\n";
        cout << "5. DELETE BY VALUE\n";
        cout << "6. LINEAR SEARCH\n";
        cout << "7. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            create(arr, n);
            break;
        case 2:
            display(arr, n);
            break;
        case 3:
            insert(arr, n, pos, val);
            break;
        case 4:
            del1(arr, n, index);
            break;
        case 5:
            del_value(arr, n, val);
            break;
        case 6:
            search(arr, n, key);
            break;
        case 7:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 7);
    return 0;
}

// 2
#include <stdio.h>

void removeDuplicates(int arr[], int *n) {
    for (int i = 0; i < *n; i++) {
        for (int j = i + 1; j < *n; ) {
            if (arr[i] == arr[j]) {
                for (int k = j; k < *n - 1; k++)
                    arr[k] = arr[k + 1];
                (*n)--;
            } else {
                j++;
            }
        }
    }
}

int main() {
    int arr[100], n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    removeDuplicates(arr, &n);

    printf("Array after removing duplicates:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}

// 3
// 10000

// 4(a)
#include <stdio.h>
void reverseArray(int arr[], int n) {
    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}

// 4(b)
#include <stdio.h>

void matrixMultiply() {
    int a[10][10], b[10][10], c[10][10], r1, c1, r2, c2;

    printf("Enter rows and columns of first matrix: ");
    scanf("%d%d", &r1, &c1);
    printf("Enter rows and columns of second matrix: ");
    scanf("%d%d", &r2, &c2);

    if (c1 != r2) {
        printf("Matrix multiplication not possible.\n");
        return;
    }

    printf("Enter first matrix:\n");
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            scanf("%d", &a[i][j]);

    printf("Enter second matrix:\n");
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            scanf("%d", &b[i][j]);

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            c[i][j] = 0;
            for (int k = 0; k < c1; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
    }

    printf("Product matrix:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++)
            printf("%d ", c[i][j]);
        printf("\n");
    }
}

//4 (c)
void transposeMatrix() {
    int a[10][10], trans[10][10], r, c;
    printf("Enter rows and columns: ");
    scanf("%d%d", &r, &c);
    printf("Enter matrix:\n");
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &a[i][j]);

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            trans[j][i] = a[i][j];

    printf("Transpose:\n");
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++)
            printf("%d ", trans[i][j]);
        printf("\n");
    }
}

// 5
#include <stdio.h>

int main() {
    int a[10][10], r, c;
    printf("Enter rows and columns: ");
    scanf("%d%d", &r, &c);
    printf("Enter matrix:\n");
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &a[i][j]);

    printf("Row sums:\n");
    for (int i = 0; i < r; i++) {
        int sum = 0;
        for (int j = 0; j < c; j++)
            sum += a[i][j];
        printf("Row %d sum = %d\n", i + 1, sum);
    }

    printf("Column sums:\n");
    for (int j = 0; j < c; j++) {
        int sum = 0;
        for (int i = 0; i < r; i++)
            sum += a[i][j];
        printf("Column %d sum = %d\n", j + 1, sum);
    }

    return 0;
}
