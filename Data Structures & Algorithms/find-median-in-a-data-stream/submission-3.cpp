class MedianFinder {
   public:
    priority_queue<int>*left;
    priority_queue<int, vector<int>, greater<int>>* right;

    MedianFinder() {
        right = new priority_queue<int, vector<int>, greater<int>>();
        left = new priority_queue<int>();
    }

    void addNum(int num) {
       
       right->push(num);
        // now  making the size equal or left+ 1 size =right size

       if( left->size() < right->size()){
        left->push(right->top());
        right->pop();
       }

       // now is  exact what we want but left highest must be smaller than right lower

       while( left->top() > right->top()){
        left->push(right->top());
        right->push(left->top());
        left->pop();
        right->pop();

       }

    }

    double findMedian() {
        double median=0;
        if( left->size()==0)return 0;
        if( left->size()==right->size()){
          
            median = (left->top() + right->top() )/2.0;
        }else{
           
            median = left->top();
        }
        return median;
    }
};
