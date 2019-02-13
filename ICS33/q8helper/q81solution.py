from performance import Performance
from goody import irange
from graph_goody import random_graph, spanning_tree

# Put script here to generate data for Problem #1
# In case you fail, the data appears in sample8.pdf in the helper folder

def create_random(nodes):
    global rg
    rg = random_graph(nodes, lambda x :10*x)

if __name__ == '__main__':
    for i in irange(0,7):
        size = 1000 * 2**i
        p = Performance(lambda : spanning_tree(rg), lambda: create_random(size),5,'\n\nSpanning Tree of size ' + str(size))
        p.evaluate()
        p.analyze()
