// 1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int binarySearch(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return 0;
}
int main() {
    std::vector<int> sortedArray = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int target = 91;
    int result = binarySearch(sortedArray, target);
    if (result != -1) {
        std::cout << "Element is present at index " << result << std::endl;
    } else {
        std::cout << "Element is not present in the array." << std::endl;
    }
    return 0;
}

// 2
#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int A[]={64, 34, 25, 12, 22, 11, 90};
    int n= sizeof(A)/sizeof(A[0]);
    int temp;
    for(int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (A[j]>A[j+1])
            {
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp; 
            }
        }
    }
    cout<<"Sorted Array: ";
    for (int i=0; i<n; i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
    return 0;
}

// 3
#include <iostream>
#include <vector>
#include <numeric>

int findMissingNumberSum(const std::vector<int>& arr) {
    int n = arr.size() + 1;
    int expected_sum = n * (n + 1) / 2;
    int actual_sum = 0;
    for (int num : arr) {
        actual_sum += num;
    }
    return expected_sum - actual_sum;
}

// 4(a)
#include <iostream>
#include <string>

int main() {
    std::string str1 = "Hello, ";
    std::string str2 = "World!";

    std::string concatenated_str = str1 + str2;
    std::cout << "Concatenated string (using +): " << concatenated_str << std::endl;

    str1.append(str2);
    std::cout << "Concatenated string (using append()): " << str1 << std::endl;

    return 0;
}

// 4(b)
#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string str = "programming";
    std::string reversed_str_loop = str;
    int n = reversed_str_loop.length();
    for (int i = 0; i < n / 2; i++) {
        std::swap(reversed_str_loop[i], reversed_str_loop[n - i - 1]);
    }
    std::cout<<"Original string: " << str<< std::endl;
    std::cout << "Reversed string: " << reversed_str_loop << std::endl;
    return 0;
}

// 4(c)
#include <iostream>
#include <string>
#include <cctype>
bool isVowel(char ch) {
    ch = tolower(ch);
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int main() {
    std::string str = "Programming Is Fun";
    std::string result_str = "";

    for (char ch : str) {
        if (!isVowel(ch)) {
            result_str += ch;
        }
    }
    std::cout<<"Oringinal string: "<<str<<std::endl;
    std::cout << "String after deleting vowels: " << result_str << std::endl;

    return 0;
}

// 4(d)
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::vector<std::string> words = {"banana", "apple", "cherry", "date"};

    std::sort(words.begin(), words.end());
    std::cout << "Sorted strings:" << std::endl;
    for (const std::string& word : words) {
        std::cout << word << std::endl;
    }

    return 0;
}

// 4(e)
#include <iostream>
#include <string>
#include <cctype>

int main() {
    char ch_upper = 'H';
    char ch_lower = tolower(ch_upper);

    std::cout << "Original character: " << ch_upper << std::endl;
    std::cout << "Converted character: " << ch_lower << std::endl;

    std::string str_upper = "HELLO WORLD";
    std::string str_lower = "";
    for (char ch : str_upper) {
        str_lower += tolower(ch);
    }
    std::cout << "Original string: " << str_upper << std::endl;
    std::cout << "Converted string: " << str_lower << std::endl;

    return 0;
}

// 5(a)
#include <iostream>
#include <vector>

void setDiagonalElement(std::vector<int>& data, int i, int j, int value) {
    if (i == j) {
        data[i] = value;
    }
}

int getDiagonalElement(const std::vector<int>& data, int i, int j) {
    if (i == j) {
        return data[i];
    }
    return 0;
}

void displayDiagonalMatrix(const std::vector<int>& data, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                std::cout << data[i] << " ";
            } else {
                std::cout << "0 ";
            }
        }
        std::cout << std::endl;
    }
}

// 5(b)
#include <iostream>
#include <vector>

int main() {
    int n = 4;
    std::vector<int> data(3 * n - 2, 0);
    
    // Set elements
    auto setElement = [&](int i, int j, int value) {
        if (j == i - 1) data[i - 1] = value;
        else if (j == i) data[n - 1 + i] = value;
        else if (j == i + 1) data[2 * n - 1 + i] = value;
    };
    
    setElement(0, 0, 1);
    setElement(0, 1, 2);
    setElement(1, 0, 3);
    setElement(1, 1, 4);
    setElement(1, 2, 5);
    setElement(2, 1, 6);
    setElement(2, 2, 7);
    setElement(2, 3, 8);
    setElement(3, 2, 9);
    setElement(3, 3, 10);
    
    auto getElement = [&](int i, int j) {
        if (j == i - 1) return data[i - 1];
        if (j == i) return data[n - 1 + i];
        if (j == i + 1) return data[2 * n - 1 + i];
        return 0;
    };
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << getElement(i, j) << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}

int main() {
    int n = 4;
    std::vector<int> data(n, 0);

    setDiagonalElement(data, 0, 0, 5);
    setDiagonalElement(data, 1, 1, 8);
    setDiagonalElement(data, 2, 2, 12);
    setDiagonalElement(data, 3, 3, 7);

    displayDiagonalMatrix(data, n);

    return 0;
}

// 5(c)
#include <iostream>
#include <vector>

int main() {
    int n = 4;
    std::vector<int> data(n * (n + 1) / 2, 0);

    auto setElement = [&](int i, int j, int value) {
        if (i >= j) {
            data[i * (i + 1) / 2 + j] = value;
        }
    };

    setElement(0, 0, 1);
    setElement(1, 0, 2);
    setElement(1, 1, 3);
    setElement(2, 0, 4);
    setElement(2, 1, 5);
    setElement(2, 2, 6);
    setElement(3, 0, 7);
    setElement(3, 1, 8);
    setElement(3, 2, 9);
    setElement(3, 3, 10);

    auto getElement = [&](int i, int j) {
        if (i >= j) {
            return data[i * (i + 1) / 2 + j];
        }
        return 0;
    };

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << getElement(i, j) << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

// 5(d)
#include <iostream>
#include <vector>

int main() {
    int n = 4;
    std::vector<int> data(n * (n + 1) / 2, 0);

    auto setElement = [&](int i, int j, int value) {
        if (i <= j) {
            data[n * i - i * (i + 1) / 2 + j] = value;
        }
    };

    setElement(0, 0, 1);
    setElement(0, 1, 2);
    setElement(0, 2, 3);
    setElement(0, 3, 4);
    setElement(1, 1, 5);
    setElement(1, 2, 6);
    setElement(1, 3, 7);
    setElement(2, 2, 8);
    setElement(2, 3, 9);
    setElement(3, 3, 10);

    auto getElement = [&](int i, int j) {
        if (i <= j) {
            return data[n * i - i * (i + 1) / 2 + j];
        }
        return 0;
    };

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << getElement(i, j) << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

// 5(e)
#include <iostream>
#include <vector>

int main() {
    int n = 4;
    std::vector<int> data(n * (n + 1) / 2, 0);

    auto setElement = [&](int i, int j, int value) {
        if (i >= j) {
            data[i * (i + 1) / 2 + j] = value;
        } else {
            data[j * (j + 1) / 2 + i] = value;
        }
    };

    setElement(0, 0, 1); setElement(1, 0, 2); setElement(1, 1, 3);
    setElement(2, 0, 4); setElement(2, 1, 5); setElement(2, 2, 6);
    setElement(3, 0, 7); setElement(3, 1, 8); setElement(3, 2, 9); setElement(3, 3, 10);
    
    auto getElement = [&](int i, int j) {
        if (i >= j) {
            return data[i * (i + 1) / 2 + j];
        }
        return data[j * (j + 1) / 2 + i];
    };

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << getElement(i, j) << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}

// 6
#include <iostream>
#include <vector>
#include <algorithm>

struct Triplet {
    int row, col, value;
};

class SparseMatrix {
public:
    int rows, cols;
    std::vector<Triplet> triplets;

    SparseMatrix(int r, int c) : rows(r), cols(c) {}

    void addElement(int r, int c, int v) {
        if (v != 0) {
            triplets.push_back({r, c, v});
        }
    }

    void display() {
        if (triplets.empty()) {
            std::cout << "Matrix is empty." << std::endl;
            return;
        }
        int k = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (k < triplets.size() && triplets[k].row == i && triplets[k].col == j) {
                    std::cout << triplets[k].value << " ";
                    k++;
                } else {
                    std::cout << "0 ";
                }
            }
            std::cout << std::endl;
        }
    }
};

SparseMatrix transpose(const SparseMatrix& A);
SparseMatrix add(const SparseMatrix& A, const SparseMatrix& B);
SparseMatrix multiply(const SparseMatrix& A, const SparseMatrix& B);

int main() {
    SparseMatrix A(4, 5);
    A.addElement(0, 0, 1);
    A.addElement(1, 2, 8);
    A.addElement(2, 4, 3);
    A.addElement(3, 0, 4);

    SparseMatrix B(4, 5);
    B.addElement(0, 0, 2);
    B.addElement(1, 1, 5);
    B.addElement(2, 4, 6);
    B.addElement(3, 3, 7);

    SparseMatrix M1(2, 3);
    M1.addElement(0, 0, 1);
    M1.addElement(0, 2, 2);
    M1.addElement(1, 1, 3);
    
    SparseMatrix M2(3, 2);
    M2.addElement(0, 0, 4);
    M2.addElement(1, 1, 5);
    M2.addElement(2, 0, 6);

    std::cout << "Matrix A:" << std::endl;
    A.display();
    std::cout << "------------------" << std::endl;

    std::cout << "Transpose of Matrix A:" << std::endl;
    SparseMatrix A_t = transpose(A);
    A_t.display();
    std::cout << "------------------" << std::endl;

    std::cout << "Addition of Matrix A and B:" << std::endl;
    SparseMatrix C = add(A, B);
    C.display();
    std::cout << "------------------" << std::endl;

    std::cout << "Multiplication of M1 and M2:" << std::endl;
    SparseMatrix P = multiply(M1, M2);
    P.display();
    
    return 0;
}

//  Transpose of a matrix
SparseMatrix transpose(const SparseMatrix& A) {
    SparseMatrix T(A.cols, A.rows);
    if (A.triplets.empty()) return T;

    std::vector<int> col_counts(A.cols, 0);
    std::vector<int> col_start_indices(A.cols, 0);

    for (const auto& triplet : A.triplets) {
        col_counts[triplet.col]++;
    }
    
    col_start_indices[0] = 0;
    for (int i = 1; i < A.cols; ++i) {
        col_start_indices[i] = col_start_indices[i - 1] + col_counts[i - 1];
    }
    
    T.triplets.resize(A.triplets.size());
    for (const auto& triplet : A.triplets) {
        int index = col_start_indices[triplet.col];
        T.triplets[index] = {triplet.col, triplet.row, triplet.value};
        col_start_indices[triplet.col]++;
    }
    
    std::sort(T.triplets.begin(), T.triplets.end(), [](const Triplet& a, const Triplet& b) {
        if (a.row != b.row) return a.row < b.row;
        return a.col < b.col;
    });

    return T;
}

// Addition of two matrices
SparseMatrix add(const SparseMatrix& A, const SparseMatrix& B) {
    if (A.rows != B.rows || A.cols != B.cols) {
        std::cerr << "Error: Matrices must have same dimensions for addition." << std::endl;
        return SparseMatrix(0, 0);
    }

    SparseMatrix C(A.rows, A.cols);
    size_t i = 0, j = 0;
    while (i < A.triplets.size() && j < B.triplets.size()) {
        if (A.triplets[i].row < B.triplets[j].row || (A.triplets[i].row == B.triplets[j].row && A.triplets[i].col < B.triplets[j].col)) {
            C.triplets.push_back(A.triplets[i++]);
        } else if (A.triplets[i].row > B.triplets[j].row || (A.triplets[i].row == B.triplets[j].row && A.triplets[i].col > B.triplets[j].col)) {
            C.triplets.push_back(B.triplets[j++]);
        } else {
            int sum = A.triplets[i].value + B.triplets[j].value;
            if (sum != 0) {
                C.triplets.push_back({A.triplets[i].row, A.triplets[i].col, sum});
            }
            i++;
            j++;
        }
    }
    while (i < A.triplets.size()) {
        C.triplets.push_back(A.triplets[i++]);
    }
    while (j < B.triplets.size()) {
        C.triplets.push_back(B.triplets[j++]);
    }
    return C;
}

// Multiplication of two matrices
SparseMatrix multiply(const SparseMatrix& A, const SparseMatrix& B) {
    if (A.cols != B.rows) {
        std::cerr << "Error: Number of columns in the first matrix must equal "
                  << "number of rows in the second matrix for multiplication." << std::endl;
        return SparseMatrix(0, 0);
    }
    
    SparseMatrix B_t = transpose(B);
    SparseMatrix C(A.rows, B.cols);

    for (const auto& tripletA : A.triplets) {
        for (const auto& tripletB_t : B_t.triplets) {
            if (tripletA.col == tripletB_t.row) {
                int sum = tripletA.value * tripletB_t.value;
                bool found = false;
                for (auto& tripletC : C.triplets) {
                    if (tripletC.row == tripletA.row && tripletC.col == tripletB_t.col) {
                        tripletC.value += sum;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    C.triplets.push_back({tripletA.row, tripletB_t.col, sum});
                }
            }
        }
    }

    std::sort(C.triplets.begin(), C.triplets.end(), [](const Triplet& a, const Triplet& b) {
        if (a.row != b.row) return a.row < b.row;
        return a.col < b.col;
    });

    return C;
}

// 7
#include <iostream>
#include <vector>

// Function to merge two halves and count inversions
long long mergeAndCount(std::vector<int>& arr, std::vector<int>& temp, int left, int mid, int right) {
    long long inv_count = 0;
    int i = left;    // Index for the left subarray
    int j = mid + 1; // Index for the right subarray
    int k = left;    // Index for the merged array

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            // This is where inversions are counted.
            // If arr[j] is smaller than arr[i], then all remaining elements
            // in the left subarray (from i to mid) form inversions with arr[j].
            inv_count += (mid - i + 1);
        }
    }

    // Copy the remaining elements of the left subarray
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // Copy the remaining elements of the right subarray
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy the merged elements back to the original array
    for (int l = left; l <= right; l++) {
        arr[l] = temp[l];
    }

    return inv_count;
}

// Recursive function to perform merge sort and count inversions
long long mergeSortAndCount(std::vector<int>& arr, std::vector<int>& temp, int left, int right) {
    long long inv_count = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Count inversions in the left and right halves
        inv_count += mergeSortAndCount(arr, temp, left, mid);
        inv_count += mergeSortAndCount(arr, temp, mid + 1, right);

        // Count inversions during the merge step
        inv_count += mergeAndCount(arr, temp, left, mid, right);
    }
    return inv_count;
}

int main() {
    std::vector<int> arr = {1, 20, 6, 4, 5};
    std::vector<int> temp(arr.size());

    long long inversion_count = mergeSortAndCount(arr, temp, 0, arr.size() - 1);

    std::cout << "Original array: {1, 20, 6, 4, 5}" << std::endl;
    std::cout << "Number of inversions: " << inversion_count << std::endl;

    return 0;
}

// 8
#include <iostream>
#include <vector>
#include <algorithm>

int countDistinct(std::vector<int>& arr) {
    if (arr.empty()) {
        return 0;
    }
    std::sort(arr.begin(), arr.end());
    int count = 1;
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] != arr[i - 1]) {
            count++;
        }
    }
    return count;
}

int main() {
    std::vector<int> arr = {10, 20, 10, 30, 40, 20, 50};
    int distinctCount = countDistinct(arr);
    std::cout << "The number of distinct elements is: " << distinctCount << std::endl;
    return 0;
}

// Additional Questions 1
#include <iostream>
#include <vector>
using namespace std;

int countPairs(vector<int> &arr, int k) {
    int n = arr.size();
    int cnt = 0;

    // generate all possible pairs
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            
            // If absolute difference = k, then increment
            // count by 1
            if (abs(arr[i] - arr[j]) == k) {
                cnt += 1;
            }
        }
    }
    return cnt;
}

int main() {
    vector<int> arr = {1, 4, 1, 4, 5};
    int k = 3;

    cout << countPairs(arr, k);
    return 0;
}

// Additional Questions 2
#include <bits/stdc++.h>
using namespace std;

bool canSplit(string s) {
    int n = s.size();
    // Try all possible first and second split points
    for (int i = 1; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            string a = s.substr(0, i);
            string b = s.substr(i, j-i);
            string c = s.substr(j);
            if ((a.find(b) != string::npos && c.find(b) != string::npos) ||
                (a.find(c) != string::npos && b.find(c) != string::npos) ||
                (b.find(a) != string::npos && c.find(a) != string::npos)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    string s = "abcab";
    if (canSplit(s)) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}

// Additional Questions 3
#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s1, string s2) {
    if (s1.size() != s2.size()) return false;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1 == s2;
}

int main() {
    string s1 = "listen", s2 = "silent";
    if (isAnagram(s1, s2)) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}

// Additional Questions 4
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void sort012(vector<int> &arr) {
    
    // standard sorting function
    sort(arr.begin(), arr.end()); 
}

int main() {
    vector<int> arr = {0, 1, 2, 0, 1, 2};
    
    sort012(arr);

    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    return 0;
}

// Additional Questions 5
#include <bits/stdc++.h>
using namespace std;

void duplicateTwos(vector<int>& arr) {
    int n = arr.size();
    int possibleDups = 0;
    int last = n - 1;

    // Count duplications
    for (int i = 0; i <= last - possibleDups; i++) {
        if (arr[i] == 2) {
            if (i == last - possibleDups) {
                arr[last] = 2;
                last--;
                break;
            }
            possibleDups++;
        }
    }

    int i = last - possibleDups;
    for (int j = last; i >= 0; i--, j--) {
        if (arr[i] == 2) {
            arr[j] = 2;
            j--;
            arr[j] = 2;
        } else {
            arr[j] = arr[i];
        }
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 2, 5};
    duplicateTwos(arr);
    for (int x : arr) cout << x << " ";
    return 0;
}
