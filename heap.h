#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <iostream>

/*
  1. Stack_test works great! DONE
  2. llpivot works great but llfilter doesn't print DONE
  3. ! heap implmentation (missing last test) "cd heap_test" "make test"
  4. logicsim gives one wrong answer "cd logicsim" "make" "./logicsim single_and.txt" make sure pics are good and how to upload them. DONE
  5. upload tree diagrams from part 4 DONE
*/


template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m = 2, PComparator c = PComparator());
  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();
  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);
  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;
  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();
  /// returns true if the heap is empty
  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;
    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;
private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> curheap; 
  int m;
  PComparator c = PComparator(); //don't worry about min/max heap
  // c(left child, right child)
  void heapify(int i); 
  //heapfiy or trickle down function
  void trickleUp(int k);
  //void printHeap(std::vector<T>& curheap);
};

template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m_, PComparator c_){
  m = m_;
  //c = c_;
}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap(){}

// Add implementation of member functions here

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
    if(empty()){
      // ================================
      // throw the appropriate exception
      // ================================
      if (curheap.empty()){
        throw std::out_of_range("Index is out of range(Heap underflow)");
      }
    }
    // If we get here we know the heap has at least 1 item
    // Add code to return the top element
    return curheap[0];
  /*
  catch(const std::out_of_range){
    std::cout << "Invalid: not enough items in list" << std::endl;
  }
  */
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop(){
      // ================================
      // throw the appropriate exception
      // ================================
    if (curheap.empty()){
      throw std::out_of_range("Index is out of range(Heap underflow)");
    }
    // printHeap(curheap);
    // switch the top with the back one
    std::swap(curheap.front(), curheap.back()); // back item?
    curheap.pop_back();

    // NOTE CHANGE
    if (curheap.size() == 1) {
      return ;
    }
    // need heapify function for min heap and max heap
    // call heapify here on 0
    this->heapify(0);
}
  /*
  catch(const std::out_of_range){
    std::cout << "Invalid: not enough items in list" << std::endl;
  }
  */

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item){
  // inserting new element then calling heapify 
  // printHeap(curheap);
  curheap.push_back(item);
  this->trickleUp(curheap.size() - 1);
  // size++;
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const{
  if (curheap.size() == 0){
    return true;
  }
  else{
    return false;
  }
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const{
  // check this
  // int size = curheap.size();
  return curheap.size();
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::heapify(int i){
  
  // check this
  int children[m]; //m-ary so m-children for each node
  size_t size = (m*i) + 1;
  if (size >= curheap.size()){
    // it does not exists 
    return;
  }
  size_t smallerChild = (m*i) +1; //start with left child
  for (size_t j = 1; j < m; j++){
    if ((smallerChild + j) >= curheap.size()){
      // nothing to compare to...
      // do i break here?
      break;
    }
    /*
    if (c(curheap[smallerChild], curheap[smallerChild + j])){
      smallerChild = smallerChild + j;
    }
    */
    if (c(curheap[smallerChild + j], curheap[smallerChild])){
      smallerChild = smallerChild + j;
    } 
  }
  if(c(curheap[smallerChild], curheap[i])){ 
    std::swap(curheap[i], curheap[smallerChild]); 
    heapify(smallerChild);
  }
}

// should be done
template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleUp(int k){
  int parent = (k-1)/m; // 0-based indexing?
  while ((parent >= 0) && c(curheap[k], curheap[parent])){
    std::swap(curheap[k], curheap[parent]);
    k = parent;
    parent = (k-1)/m; 
  }
}

// template <typename T, typename PComparator>
// void Heap<T, PComparator>::printHeap(std::vector<T> &curheap){
//   for (int d = 0; d < curheap.size(); d++){
//     std::cout << curheap[d] << std::endl;
//   }
// }

#endif

