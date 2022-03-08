#include "assignment/code.hpp"

#include <iostream>   // cout, printf
#include <algorithm>  // fill, copy

namespace assignment {

  // Task 1
  int squared_diff(int left, int right) {
    int a = abs(left-right) * abs(left-right);
    return a;
  }

  // Task 2
  bool check_bit(int mask, int bit_pos) {
    if ((mask < 0)||(bit_pos < 0)) {
      return false;
    } else {
      for (int i = bit_pos; i >= 0; i--) {
        if (i == 0) {
          return mask%2 == 1;
        }
        mask /= 2;
      }
    }
    return true;
  }

  // Task 3
  int max3(int left, int middle, int right) {
    if (left >= middle) {
      if (left >= right) {
        return left;
      } else {
        return right;
      }
    } else {
      if (middle >= right) {
        return middle;
      } else {
        return right;
      }
    }
  }

  // Task 4
  void swap_args(int* left, int* right) {
    if ((left != nullptr)&&(right != nullptr)&&(*left != *right)) {
      int a = *left;
      *left = *right;
      *right = a;
    }
  }

  // Task 5
  int arr_sum(int *arr, int length) {
    if ((length <= 0)||(arr == nullptr)) {
      return 0;
    }
    int sum = 0;
    for (int i = 0; i < length; i++) {
      sum += arr[i];
    }
    return sum;
  }

  // Task 6
  int *find_max_elem(int *arr, int length) {
    if((arr == nullptr)||(length <= 0)) {
      return nullptr;
    }
    int *max_elem = &arr[0];
    int max_arr = arr[0];
    for (int i = 1; i < length; i++) {
      if (arr[i] > max_arr) {
        max_arr = arr[i];
        max_elem = &arr[i];
      }
    }
    return max_elem;
  }

  // Task 7
  int *allocate_arr(int length, int init_value) {
    if (length <=0 ) {
      return nullptr;
    }
    int *arr = new int[length];
    for (int i = 0; i < length; i++) {
      arr[i] = init_value;
    }
    return arr;
  }

  // Task 8
  int *clone_arr(int *arr_in, int length) {
    if ((arr_in == nullptr) || (length <= 0)) {
      return nullptr;
    } else {
      int *arr_new = new int[length];
      for (int i = 0; i < length; i++) {
        arr_new[i] = arr_in[i];
      }
      return arr_new;
    }
  }

  // Task 9
  void print_kth_elements(int *arr, int length, int k, std::ostream &os) {
    bool flag = false;
    if (arr == nullptr) {
      flag = true;
      os << "Invalid argument: arr\n";
    }
    if (length <= 0) {
      flag = true;
      os << "Invalid argument: length\n";
    }
    if (k <= 0) {
      flag = true;
      os << "Invalid argument: k\n";
    }
    if (!flag) {
      if (k > length) {
        os << arr[0] + "\n";
      } else {
        for (int i = 0; i < length; i = i + k) {
          os << arr[i];
        }
      }
    }
  }
}  // namespace assignment
