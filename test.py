#!/usr/bin/python3
import sys
import random
import subprocess

count = int(sys.argv[1])
sample = random.sample(range(count), count)
string_sample = [str(int) for int in sample]
args = " ".join(string_sample)
# print("testing with args: " + args)
push_swap = subprocess.run(args = ["./push_swap", args], universal_newlines = True, stdout = subprocess.PIPE)
print("Count: " + str(len(push_swap.stdout.split("\n"))))

checker = subprocess.run(args = ["./checker_Mac", args], universal_newlines = True, stdout = subprocess.PIPE, input = push_swap.stdout)
print("Result: " + checker.stdout)

