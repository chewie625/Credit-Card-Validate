import re
from cs50 import get_string

sum1 = sum2 = 0
CC = get_string("Input: ")
# Put CC to x do that it becomes an integer for easier calculation
x = int(CC)

# Just like in C program in Week 1, x % 10 will spits out the end digit of the CC.
for i in range(len(CC)):
    if i % 2 == 1 and (x % 10) * 2 >= 10:
        sum1 += ((x % 10) * 2) % 10 + 1
# need to do double divide ("//") here as it will spit out a whole number of the CC,
# whereas if you just do "X/=10", it gives you decimal.
        x //= 10
    elif (i % 2 == 1):
        sum1 += (x % 10) * 2
        x //= 10
    else:
        sum2 += x % 10
        x //= 10
Total = sum1 + sum2

# Conditional checking, no dramas here, only if statements according to the CC validation rules.
if len(CC) == 15 and Total % 10 == 0 and CC[0] == '3' and CC[1] == '7':
    print("AMEX")
elif len(CC) == 16 and Total % 10 == 0 and CC[0] == '5':
    print("MASTERCARD")
elif len(CC) >= 13 and Total % 10 == 0 and CC[0] == '4':
    print("VISA")
else:
    print("INVALID")