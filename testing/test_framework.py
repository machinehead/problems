import os
import numpy as np

class TestContext(object):
    project_build_path = None
    root_build_path = None

    def __init__(self, proj_build_path):
        self.project_build_path = proj_build_path
        self.root_build_path = proj_build_path
        while os.path.split(self.root_build_path)[1] != "build":
            self.root_build_path = os.path.split(self.root_build_path)[0]

    def generator_path(self, generator_name):
        return os.path.join(self.root_build_path, "generators", generator_name, generator_name)

    def program_path(self):
        return os.path.join(self.project_build_path, os.path.split(self.project_build_path)[1])

class Test(object):
    generator = None
    generator_args = None
    complexity = None

    def __init__(self, generator=None, generator_args=None, complexity=None):
        self.generator = generator
        self.generator_args = generator_args
        self.complexity = complexity

class Complexity(object):
    name = None

    def __init__(self, name):
        self.name = name

class CompConst(Complexity):
    def __init__(self):
        super(CompConst, self).__init__("1")

    def func(self, _, a):
        return a

class CompLogN(Complexity):
    def __init__(self):
        super(CompLogN, self).__init__("LogN")

    def func(self, N, a, b):
        return a * np.log(N) + b

class CompNLogN(Complexity):
    def __init__(self):
        super(CompNLogN, self).__init__("NLogN")

    def func(self, N, a, b):
        return a * N * np.log(N) + b

class CompN(Complexity):
    def __init__(self):
        super(CompN, self).__init__("N")

    def func(self, x, a, b):
        return a * x + b

class CompN2(Complexity):
    def __init__(self):
        super(CompN2, self).__init__("N2")

    def func(self, x, a, b, c):
        return a * x * x + b * x + c

class CompN3(Complexity):
    def __init__(self):
        super(CompN3, self).__init__("N2")

    def func(self, x, a, b, c, d):
        return a * x * x * x + b * x * x + c * x + d

def get_complexities():
    return [
        CompConst(),
        CompLogN(),
        CompN(),
        CompNLogN(),
        CompN2(),
        CompN3(),
    ]
