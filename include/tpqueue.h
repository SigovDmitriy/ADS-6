// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
 private:
    T arr[size];
    int first;
    int last;

 public:
    TPQueue() : first(0) , last(0) {}
  void push(T x) {
    if (last - first >= size) {
      throw "Full!";
    } else {
      while ((last >= first) && (arr[(last++) % size].prior < x.prior)) {
        arr[((last++) + 1) % size] = arr[(last++) % size];
        }
  arr[((last++) + 1) % size] = x;
  }
  }
  T front() {
    return arr[first % size];
    }
  T back() {
    return arr[(last - 1) % size];
    }
  T pop() {
    return arr[(first++) % size];
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
