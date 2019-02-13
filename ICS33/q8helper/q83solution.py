from bag import Bag
import unittest  # use unittest.TestCase
import random    # use random.shuffle, random.randint
from random import randint
  #random.shuffle(alist) mutates its alist argument, to be a random permutation
  #random.randint(1,10)  returns a random number in the range 1-10 inclusive
  
def setup():
    global alist
    alist = ['d','a','b','d','c','b','d']
    global bag
    bag = Bag(alist)

class Test_Bag(unittest.TestCase):
    def testlen(self):
        setup()
        random.shuffle(alist)
        for i in range(8):
            self.assertEqual(bag.__len__(),7-i)
            if i != 7:
                bag.remove(alist[1*i])
    
    def testunique(self):
        setup()
        random.shuffle(alist)
        prev = []
        for i in alist:
            if i not in prev:
                prev.append(i)
                self.assertEqual(bag.unique(), len(set(bag)))
                bag.remove(i)
                
    def testcontains(self):
        setup()
        for i in bag:
            self.assertIn(i,alist)
        self.assertNotIn('x', bag)
            
    def testcount(self):
        setup()
        for i in bag:
            for j in range(bag.counts[i]):
                self.assertEqual(bag.count(i),bag.counts[i])
                bag.remove(i)
        self.assertEqual(bag.count('x'),0)
            
    def testeq(self):
        blist = []
        for i in range(1000):
            blist.append(randint(1,10))
        bag1 = Bag(blist)
        random.shuffle(blist)
        bag2 = Bag(blist)
        self.assertTrue(bag1 == bag2)
        bag1.remove(blist[0])
        self.assertFalse(bag1 == bag2)
        
    def testadd(self):
        bag1 = Bag([randint(1,10) for i in range(1000)])
        bag2 = Bag() 
        ran = [i for i in bag1]
        random.shuffle(ran)
        for j in ran:
            bag2.add(j)
        self.assertEqual(bag2, bag1)
    
    def testremove(self):
        alist = [randint(1,10) for i in range(1000)]
        bag1, bag2 = Bag(alist), Bag(alist)
        self.assertRaises(ValueError, bag1.remove, 33)
        random.shuffle(alist)
        for i in range(2):
            for j in alist:
                if i == 0:
                    bag2.add(j)
                else:
                    bag2.remove(j)
        self.assertTrue(bag2 == bag1)
        
        
        