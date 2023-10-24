#include <iostream>
#include <vector>
#include <algorithm> // Include the standard library for sorting
#include <random>

// Function to partition the array for Quicksort
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Quicksort function
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

int main() {
    // Generate random data and populate the vector
    int n = 6; // Adjust the size as needed
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(1, 100); // Adjust the range as needed
    std::vector<int> data;

    for (int i = 0; i < n; ++i) {
        data.push_back(distribution(generator));
    }

    std::cout << "Unsorted array: ";
    for (int num : data) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    quickSort(data, 0, n - 1);

    std::cout << "Sorted array: ";
    for (int num : data) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
