#include <iostream>

// Function to create a 5x5 2D array
void create2Darray(int**& arr, int rows, int cols) {
    // Allocate memory for the rows
    arr = new int*[rows]; // Allocate space for row pointers

    // Check if allocation was successful
    if (!arr) {
        std::cerr << "Memory allocation failed for outer array." << std::endl;
        return;
    }

    // Allocate memory for each row (columns)
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols]; // Allocate space for columns
        if (!arr[i]) {
            std::cerr << "Memory allocation failed for row " << i << "." << std::endl;

            // Clean up any allocated rows and set to nullptr
            for (int j = 0; j < i; j++) {
                delete[] arr[j];
                arr[j] = nullptr;
            }

            // Delete the outer array and set it to nullptr
            delete[] arr;
            arr = nullptr;
            return;
        }
    }

    // Initialize with default values (0 for simplicity)
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = 0; // Initialize with zero
        }
    }
}

// Function to deallocate a 2D array and avoid memory leaks
void delete2Darray(int**& arr, int rows) {
    if (arr) {
        // Delete each row
        for (int i = 0; i < rows; i++) {
            delete[] arr[i]; // Deallocate row
        }

        // Delete the outer array
        delete[] arr;
        arr = nullptr; // Set to nullptr to avoid dangling pointers
    }
}

// Function to print a 2D array
void print2Darray(int** arr, int rows, int cols) {
    if (arr) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                std::cout << arr[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
}

int main() {
    int** myArray = nullptr; // Initialize to nullptr

    // Create a 5x5 array
    create2Darray(myArray, 5, 5);

    if (myArray) { // Ensure it's not null
        // Use the array (here, just printing it)
        print2Darray(myArray, 5, 5);

        // Clean up when done
        delete2Darray(myArray, 5);
    } else {
        std::cerr << "Failed to create the 2D array." << std::endl;
    }

    return 0;
}
