from tensorflow import keras
import numpy as np
import os
import matplotlib.pyplot as plt
import math

os.chdir("C:/The location of data")
train_loc = "./emgdata.csv"
test_loc = "./test.csv"

trains = np.loadtxt(train_loc, delimiter = ',', dtype = float) # delimiter devides the each number in the 1000 of columns.
train_data = trains[:,0:999]
train_label = trains[:,1000]

tests = np.loadtxt(train_loc, delimiter = ','

def vectorize_sequences(sequences, dimension = 10000):


