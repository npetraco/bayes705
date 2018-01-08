import copy
import numpy as np


def my_loadtxt(filename, single_precision=False, delimiter=" "):
    """
    Load quickly
    """
    # Open the file
    f = open(filename, "r")

    # Storage
    results = []

    # Rows and columns
    nrow = 0
    ncol = None

    while(True):
        # Read the line and split by whitespace
        line = f.readline()
        if delimiter != " ":
            cells = line.split(delimiter)
        else:
            cells = line.split()

        # Quit when you see a different number of columns
        if ncol is not None and len(cells) != ncol:
            break

        # Non-comment lines
        if cells[0][0] != "#":
            # If it's the first one, get the number of columns
            if ncol is None:
                ncol = len(cells)

            # Otherwise, include in results
            if single_precision:
                results.append(np.array([float(cell) for cell in cells],
                                        dtype="float32"))
            else:
                results.append(np.array([float(cell) for cell in cells]))
            nrow += 1

    results = np.vstack(results)
    return results


def expts():

    levels_orig = np.atleast_2d(my_loadtxt("/Users/npetraco/latex/class/fos705/Applied_Bayes/R/bayes705/tests/Dnest_Bullard_spike_test/levels.txt"))
    sample_info = np.atleast_2d(my_loadtxt("/Users/npetraco/latex/class/fos705/Applied_Bayes/R/bayes705/tests/Dnest_Bullard_spike_test/sample_info.txt"))

    logl_levels = [(levels_orig[i, 1], levels_orig[i, 2]) for i in range(0, levels_orig.shape[0])]  # logl, tiebreaker
    logl_samples = [(sample_info[i, 1], sample_info[i, 2], i) for i in range(0, sample_info.shape[0])]  # logl, tiebreaker, id

    # Find sandwiching level for each sample
    sandwich = sample_info[:, 0].copy().astype('int')
    for i in range(0, sample_info.shape[0]):
        while sandwich[i] < levels_orig.shape[0] - 1 and logl_samples[i] > logl_levels[sandwich[i] + 1]:
            sandwich[i] += 1

    # print(logl_levels)
    np.savetxt("/Users/npetraco/latex/class/fos705/Applied_Bayes/R/bayes705/tests/Dnest_Bullard_spike_test/csvfile.csv", sandwich, delimiter=",")


expts()
