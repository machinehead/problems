import sys
import tempfile
import subprocess
import time
import scipy.optimize
import numpy as np

source_dir = sys.argv[1]
build_dir = sys.argv[2]

from test_framework import TestContext, get_complexities
context = TestContext(build_dir)

sys.path.append(source_dir)
import test_config
tests = test_config.get_tests()

complexity = []
run_time = []

with open("test_report.txt", "w") as report:
    for test in tests:
        print >>report, "Running test with generator {}, complexity {}".format(test.generator, test.complexity)

        gen_start_time = time.time()

        generator_path = context.generator_path(test.generator)
        generator_out_file = tempfile.TemporaryFile()
        subprocess.check_call([generator_path] + test.generator_args, stdout=generator_out_file.fileno())
        generator_out_file.seek(0)

        gen_end_time = time.time()

        print >>report, "Generating data: {} s".format(gen_end_time - gen_start_time)

        program_out_file = tempfile.TemporaryFile()
        program_path = context.program_path()

        prog_start_time = time.time()

        subprocess.check_call([program_path], stdin=generator_out_file.fileno(), stdout=program_out_file.fileno())

        prog_end_time = time.time()

        complexity.append(test.complexity)
        run_time.append(prog_end_time - prog_start_time)

        print >>report, "Program run time: {} s".format(prog_end_time - prog_start_time)
        print >>report, ""

    if len(complexity) > 2:
        complexity = np.array(complexity)
        run_time = np.array(run_time)

        for compl in get_complexities():
            popt, _, infodict, _, _ = scipy.optimize.curve_fit(
                compl.func, 
                complexity, 
                run_time, 
                full_output=1
            )
            residuals = np.sum(infodict['fvec']**2)
            print >>report, "Fitting with {} residual is {}".format(compl.name, residuals)
            print >>report, popt
