class PeekingIterator:
    def __init__(self, iterator):
        """
        Initialize your data structure here.
        :type iterator: Iterator
        """
        self.it = iterator
        self.cur = None
        self.hasne = True if self.it.hasNext() else False
        if self.hasne:
            self.cur = self.it.next()
        

    def peek(self):
        """
        Returns the next element in the iteration without advancing the iterator.
        :rtype: int
        """
        return self.cur
        

    def next(self):
        """
        :rtype: int
        """
        t = self.cur
        self.hasne = True if self.it.hasNext() else False
        if self.hasne:
            self.cur = self.it.next()
        return t
        

    def hasNext(self):
        """
        :rtype: bool
        """
        return self.hasne