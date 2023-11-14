#include "matrix.h"
#include <iostream>
#include <stdio.h>
int main() {
  int menu_option = 0;
  int num = 0;
  int r = 0;
  int c = 0;
  matrix m1;
  m1.createMatrix();
  while (menu_option != 8) {
    std::cout << "\n1. Print the Matrix";
    std::cout << "\n2. Perform an addition of the matrix with itself";
    std::cout << "\n3. Get the maximum value in the matrix";
    std::cout << "\n4. Find whether an element exists in the matrix";
    std::cout << "\n5. Change an existing element in the matrix";
    std::cout << "\n6. Perform matrix multiplication";
    std::cout << "\n7. Transpose of a matrix";
    std::cout << "\n8. Exit";
    std::cout << "\nWhich operation would you like to perform on the matrix: ";
    std::cin >> menu_option;

    if (menu_option == 1) {
      m1.printMatrix();
      std::cout << "\n";
    } else if (menu_option == 2) {
      m1.addMatrix();
      std::cout << "\n";
    } else if (menu_option == 3) {
      std::cout << m1.getMax();
      std::cout << "\n";
    } else if (menu_option == 4) {
      std::cout << "\nEnter the number to find: ";
      std::cin >> num;
      m1.findElement(num);
    } else if (menu_option == 5) {
      std::cout << "\nEnter the row of the element to change: ";
      std::cin >> r;
      std::cout << "\nEnter the column of the element to change: ";
      std::cin >> c;
      std::cout << "\nEnter the new value: ";
      std::cin >> num;
      m1.changeElement(r, c, num);
    } else if (menu_option == 6) {
      m1.multiplyMatrix();
      std::cout << "\n";
    } else if (menu_option == 7) {
      m1.transposeMatrix();
      std::cout << "\n";
    } else if (menu_option == 8) {
      break;
    } else {
      std::cout << "Invalid input. Please try again.\n";
    }
  }
  return 0;
}