class PeekingIterator : public Iterator {
public:
    int cur,hasnext;
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
        hasnext = Iterator::hasNext();
        if(hasnext) cur = Iterator::next();
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return cur;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    int t = cur;
        hasnext = Iterator::hasNext();
        if(hasnext) cur = Iterator::next();
        return t;
	}
	
	bool hasNext() const {
        return hasnext;
	}
};