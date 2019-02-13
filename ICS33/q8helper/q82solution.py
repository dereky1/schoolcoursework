import cProfile
from graph_goody import random_graph,spanning_tree
import pstats
from goody import irange

# Put script here to generate data for Problem #2
# In case you fail, the data appears in sample8.pdf in the helper folder
def create_random(nodes):
    global rg
    rg = random_graph(nodes, lambda x :10*x)

if __name__ == '__main__':
    for i in irange(2):
        create_random(50000*i)
        cProfile.run('spanning_tree(rg)', ('profile50k' if i == 1 else 'profile100k'))
        if i == 1:
            p = pstats.Stats('profile50k')
            p.strip_dirs().sort_stats('calls').print_stats()
        else: 
            p = pstats.Stats('profile100k')
            p.sort_stats('time').print_stats()
    
