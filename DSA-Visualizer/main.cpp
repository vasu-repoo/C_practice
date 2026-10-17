
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits>
using namespace std;

// ---------- Utility Functions ----------

void displayArray(const vector<int>& arr) {
    cout << "[ ";
    for (int x : arr) cout << x << " ";
    cout << "]\n";
}

void pauseScreen() {
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

vector<int> getArray() {
    int n;
    cout << "Enter number of elements (1-50): ";
    cin >> n;

    if (!cin || n < 1 || n > 50) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid size. Using 5 elements.\n";
        return {64, 25, 12, 22, 11};
    }

    vector<int> arr(n);
    cout << "Enter " << n << " integers: ";
    for (int& x : arr) {
        if (!(cin >> x)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Using default data.\n";
            return {64, 25, 12, 22, 11};
        }
    }
    return arr;
}

// ---------- Sorting Algorithms ----------

void bubbleSort(vector<int> arr) {
    cout << "\n--- Bubble Sort ---\n";
    cout << "Initial array: ";
    displayArray(arr);

    int n = static_cast<int>(arr.size());
    long long comparisons = 0, swaps = 0;

    for (int i = 0; i < n - 1; i++) {
        bool changed = false;

        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;

            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swaps++;
                changed = true;
            }
        }

        cout << "Pass " << i + 1 << ": ";
        displayArray(arr);

        if (!changed) break;
    }

    cout << "Sorted array: ";
    displayArray(arr);
    cout << "Comparisons: " << comparisons
         << " | Swaps: " << swaps << "\n";
    cout << "Time complexity: O(n^2) worst case\n";
}

void selectionSort(vector<int> arr) {
    cout << "\n--- Selection Sort ---\n";
    int n = static_cast<int>(arr.size());

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        swap(arr[i], arr[minIndex]);

        cout << "Pass " << i + 1 << ": ";
        displayArray(arr);
    }

    cout << "Final array: ";
    displayArray(arr);
    cout << "Time complexity: O(n^2)\n";
}

void insertionSort(vector<int> arr) {
    cout << "\n--- Insertion Sort ---\n";
    int n = static_cast<int>(arr.size());

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;

        cout << "Pass " << i << ": ";
        displayArray(arr);
    }

    cout << "Final array: ";
    displayArray(arr);
    cout << "Time complexity: O(n^2) worst case\n";
}

void mergeParts(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp;
    int i = left, j = mid + 1;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) temp.push_back(arr[i++]);
        else temp.push_back(arr[j++]);
    }

    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= right) temp.push_back(arr[j++]);

    for (int k = 0; k < static_cast<int>(temp.size()); k++)
        arr[left + k] = temp[k];
}

void mergeSortHelper(vector<int>& arr, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    mergeSortHelper(arr, left, mid);
    mergeSortHelper(arr, mid + 1, right);
    mergeParts(arr, left, mid, right);

    cout << "Merge step: ";
    displayArray(arr);
}

void mergeSort(vector<int> arr) {
    cout << "\n--- Merge Sort ---\n";
    mergeSortHelper(arr, 0, static_cast<int>(arr.size()) - 1);
    cout << "Final array: ";
    displayArray(arr);
    cout << "Time complexity: O(n log n)\n";
}

int partitionArray(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSortHelper(vector<int>& arr, int low, int high) {
    if (low < high) {
        int p = partitionArray(arr, low, high);

        cout << "Pivot placed: ";
        displayArray(arr);

        quickSortHelper(arr, low, p - 1);
        quickSortHelper(arr, p + 1, high);
    }
}

void quickSort(vector<int> arr) {
    cout << "\n--- Quick Sort ---\n";
    quickSortHelper(arr, 0, static_cast<int>(arr.size()) - 1);
    cout << "Final array: ";
    displayArray(arr);
    cout << "Average time: O(n log n); worst case: O(n^2)\n";
}

// ---------- Searching Algorithms ----------

void linearSearch(const vector<int>& arr) {
    int target;
    cout << "Enter target value: ";
    cin >> target;

    for (int i = 0; i < static_cast<int>(arr.size()); i++) {
        cout << "Checking index " << i
             << " (value " << arr[i] << ")\n";

        if (arr[i] == target) {
            cout << "Found at index " << i << "\n";
            return;
        }
    }

    cout << "Value not found.\n";
}

void binarySearchDemo(vector<int> arr) {
    sort(arr.begin(), arr.end());

    cout << "Sorted array: ";
    displayArray(arr);

    int target;
    cout << "Enter target value: ";
    cin >> target;

    int low = 0, high = static_cast<int>(arr.size()) - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        cout << "Checking middle index " << mid
             << " (value " << arr[mid] << ")\n";

        if (arr[mid] == target) {
            cout << "Found at index " << mid
                 << " in the sorted array.\n";
            return;
        }

        if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }

    cout << "Value not found.\n";
}

// ---------- Stack and Queue ----------

void stackDemo() {
    stack<int> st;
    int choice, value;

    do {
        cout << "\n--- Stack (LIFO) ---\n"
             << "1. Push\n2. Pop\n3. View top\n"
             << "4. Display\n0. Back\nChoice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Value: ";
                cin >> value;
                st.push(value);
                cout << "Pushed successfully.\n";
                break;
            case 2:
                if (st.empty()) cout << "Stack is empty.\n";
                else {
                    cout << "Popped: " << st.top() << "\n";
                    st.pop();
                }
                break;
            case 3:
                if (st.empty()) cout << "Stack is empty.\n";
                else cout << "Top: " << st.top() << "\n";
                break;
            case 4: {
                if (st.empty()) {
                    cout << "Stack is empty.\n";
                    break;
                }
                stack<int> copy = st;
                cout << "Top -> ";
                while (!copy.empty()) {
                    cout << copy.top() << " ";
                    copy.pop();
                }
                cout << "\n";
                break;
            }
            case 0: break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);
}

void queueDemo() {
    queue<int> q;
    int choice, value;

    do {
        cout << "\n--- Queue (FIFO) ---\n"
             << "1. Enqueue\n2. Dequeue\n3. Front\n"
             << "4. Display\n0. Back\nChoice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Value: ";
                cin >> value;
                q.push(value);
                cout << "Enqueued successfully.\n";
                break;
            case 2:
                if (q.empty()) cout << "Queue is empty.\n";
                else {
                    cout << "Dequeued: " << q.front() << "\n";
                    q.pop();
                }
                break;
            case 3:
                if (q.empty()) cout << "Queue is empty.\n";
                else cout << "Front: " << q.front() << "\n";
                break;
            case 4: {
                if (q.empty()) {
                    cout << "Queue is empty.\n";
                    break;
                }
                queue<int> copy = q;
                cout << "Front -> ";
                while (!copy.empty()) {
                    cout << copy.front() << " ";
                    copy.pop();
                }
                cout << "<- Rear\n";
                break;
            }
            case 0: break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);
}

// ---------- Singly Linked List ----------

class LinkedList {
    struct Node {
        int data;
        Node* next;

        explicit Node(int value) : data(value), next(nullptr) {}
    };

    Node* head = nullptr;

public:
    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insert(int value) {
        Node* node = new Node(value);

        if (!head) {
            head = node;
            return;
        }

        Node* current = head;
        while (current->next)
            current = current->next;

        current->next = node;
    }

    void remove(int value) {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Deleted " << value << ".\n";
            return;
        }

        Node* current = head;
        while (current->next && current->next->data != value)
            current = current->next;

        if (!current->next) {
            cout << "Value not found.\n";
            return;
        }

        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
        cout << "Deleted " << value << ".\n";
    }

    void display() const {
        const Node* current = head;
        cout << "HEAD -> ";

        while (current) {
            cout << current->data << " -> ";
            current = current->next;
        }

        cout << "NULL\n";
    }
};

void linkedListDemo() {
    LinkedList list;
    int choice, value;

    do {
        cout << "\n--- Singly Linked List ---\n"
             << "1. Insert at end\n2. Delete by value\n"
             << "3. Display\n0. Back\nChoice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Value: ";
                cin >> value;
                list.insert(value);
                cout << "Inserted successfully.\n";
                break;
            case 2:
                cout << "Value to delete: ";
                cin >> value;
                list.remove(value);
                break;
            case 3:
                list.display();
                break;
            case 0: break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);
}

// ---------- Main Menu ----------

int main() {
    int choice;

    cout << "====================================\n";
    cout << "       C++ DSA VISUALIZER\n";
    cout << "====================================\n";

    do {
        cout << "\n========== MAIN MENU ==========\n"
             << "1. Bubble Sort\n"
             << "2. Selection Sort\n"
             << "3. Insertion Sort\n"
             << "4. Merge Sort\n"
             << "5. Quick Sort\n"
             << "6. Linear Search\n"
             << "7. Binary Search\n"
             << "8. Stack Operations\n"
             << "9. Queue Operations\n"
             << "10. Linked List Operations\n"
             << "0. Exit\n"
             << "Enter choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5: {
                vector<int> arr = getArray();

                if (choice == 1) bubbleSort(arr);
                if (choice == 2) selectionSort(arr);
                if (choice == 3) insertionSort(arr);
                if (choice == 4) mergeSort(arr);
                if (choice == 5) quickSort(arr);
                break;
            }
            case 6: {
                vector<int> arr = getArray();
                linearSearch(arr);
                break;
            }
            case 7: {
                vector<int> arr = getArray();
                binarySearchDemo(arr);
                break;
            }
            case 8: stackDemo(); break;
            case 9: queueDemo(); break;
            case 10: linkedListDemo(); break;
            case 0:
                cout << "Thank you for using DSA Visualizer!\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
