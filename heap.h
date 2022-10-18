#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>

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
  Heap(int m=2, PComparator c = PComparator());
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
  std::vector<object> curheap;
  int m;
  PComparator c; //don't worry about min/max heap
  // c(left child, right child)
  void heapify(int i);
  //heapfiy function
};

// Add implementation of member functions here

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  try{
    if(empty()){
      // ================================
      // throw the appropriate exception
      // ================================
      if (curheap.empty()){
        throw out_of_range("Index is out of range(Heap underflow)");
      }
    }
    // If we get here we know the heap has at least 1 item
    // Add code to return the top element
    return curheap[0];
  }
  catch(const out_of_range){
    cout << "Invalid: not enough items in list" << endl;
  }
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop(){
  try{
    if(empty()){
      // ================================
      // throw the appropriate exception
      // ================================
      if (curheap.empty()){
        throw out_of_range("Index is out of range(Heap underflow)");
      }
    }
    // switch the top with the back one
    curheap[0] = curheap[curheap.size() - 1]; // back item?
    curheap.pop_back();
    // need heapify function for min heap and max heap
    // call heapify here on 0
    heapify(0);
  }

  catch(const out_of_range){
    cout << "Invalid: not enough items in list" << endl;
  }
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item){
  // inserting new element then calling heapify 
  curheap.push_back(item);
  heapify(curheap.size()-1);
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
  int size = 0;
  for (int i = 0; i < curheap.size(); i++){
    size++;
  }
  return size;
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::heapify(int i){
  // check this
  int children[m]; //m-ary so m-children for each node
  if (/* leaf node*/){
    // it is a leaf node 
    return;
  }
  int smallerChild = (m*i) -1 //start with left child
  int nextChild = smallerChild + 1; // go to next child
  if(nextChild != NULL) { // next child exists
    if(c(nextChild, smallerChild)){
      smallerChild = nextChild;
    }
  }
  if(c(i, smallerChild)){ 
    swap(curheap[i], curheap[smallerChild]); 
    heapify(smallerChild);
  }
}

#endif

