#include "matrix.h"
#include <fstream>
#include <iostream>
#include <stdio.h>

void matrix::createMatrix() {
  std::ifstream inFile;
  inFile.open("input.txt");
  if (!inFile) {
    std::cerr << "Unable to open file" << std::endl;
    exit(1);
  }
  inFile >> rows;
  inFile >> cols;
  grid = new double *[rows];
  grid_temp = new double *[rows];
  for (int i = 0; i < rows; i++) {
    grid[i] = new double[cols];
    grid_temp[i] = new double[cols];
  }
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      inFile >> grid[i][j];
    }
  }
  inFile.close();
  return;
}

void matrix::printMatrix() {
  std::cout << "Printing matrix...\n";
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      std::cout << grid[i][j] << "\t";
    }
    std::cout << "\n";
  }
}

void matrix::addMatrix() {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      grid_temp[i][j] = grid[i][j] + grid[i][j];
    }
  }
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      std::cout << grid_temp[i][j] << "\t";
    }
    std::cout << "\n";
  }
}

double matrix::getMax() {
  // TO DO
  double max_element = grid[0][0];
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (grid[i][j] > max_element) {
        max_element = grid[i][j];
      }
    }
  }
  return max_element;
}

bool matrix::findElement(int no) {
  // TO DO
  bool found = false;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (grid[i][j] == no) {
        std::cout << "Element found at " << i << ", " << j << "\n";
        found = true;
      }
    }
  }
  if (!found) {
    std::cout << "Element not found.\n";
  }
  return found;
}

void matrix::changeElement(int r, int c, int no) {
  // TO DO
  if (r >= rows || c >= cols) {
    std::cout << "Invalid element position. Please try again.\n";
    return;
  }

  // Create a copy of the matrix
  double** grid_temp = new double*[rows];
  for (int i = 0; i < rows; i++) {
    grid_temp[i] = new double[cols];
    for (int j = 0; j < cols; j++) {
      grid_temp[i][j] = grid[i][j];
    }
  }

  // Modify the element in the copy
  grid_temp[r][c] = no;

  // Print the modified copy
  std::cout << "Modified matrix:\n";
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      std::cout << grid_temp[i][j] << "\t";
    }
    std::cout << "\n";
  }
}

void matrix::multiplyMatrix() {
  // TO DO
  // Hint: May want to store the new result in grid_temp and print that matrix
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      grid_temp[i][j] = 0;
      for (int k = 0; k < rows; k++) {
        grid_temp[i][j] += grid[i][k] * grid[k][j];
      }
    }
  }
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      std::cout << grid_temp[i][j] << "\t";
    }
    std::cout << "\n";
  }
}

void matrix::transposeMatrix() {
  // TO DO
  // Hint: May want to store the new results in grid_temp and print that matrix
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      grid_temp[j][i] = grid[i][j];
    }
  }
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      std::cout << grid_temp[i][j] << "\t";
    }
    std::cout << "\n";
  }
  return;
}
matrix::~matrix() {
  for (int i = 0; i < rows; i++) {
    delete[] grid[i];
    delete[] grid_temp[i];
  }
  delete[] grid;
  delete[] grid_temp;
}
