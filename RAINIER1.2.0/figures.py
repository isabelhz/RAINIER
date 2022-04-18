#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Apr 11 16:51:13 2022

@author: isabelhz
"""

import numpy as np
import matplotlib.pyplot as plt
import csv

file = open('statEJ.csv')
csvreader = csv.reader(file)

header = []
header = next(csvreader)
maxJ = int([x for x in header if x][-1])

e = 0
for row in csvreader:
    e = e+1
    row = [x for x in row if x]
    
    for j in range(1,maxJ+1):
        print(str(e) + " " + str(j) + "   " + row[j] + " ")
        coords = [float(i) for i in row[j].split()]
        plt.arrow(j, e, coords[1]-(j), coords[0]-(e), head_width=0.2, length_includes_head=True)
        
        
    print("\n")

plt.xlim(0, e)
plt.ylim(0, maxJ)
plt.ylabel("Energy (MeV)")
plt.xlabel("Angular Momentum")
plt.grid(True)
plt.savefig("figure.png", dpi = 500)

