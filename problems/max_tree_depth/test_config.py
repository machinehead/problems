import sys
from test_framework import Test

def get_tests():
    N_values = [n**2 for n in xrange(1, 300, 8)]

    return [Test(generator="gen_binary_tree", generator_args=[str(N)], complexity=N) for N in N_values]
