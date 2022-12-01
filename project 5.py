

# Guess the number into 3 chances
import math
import random
# Enter the lower range
lower_range =int(input("Enter lower range : "))
# Enter the upper range
upper_range = int(input("Enter upper range : "))
random_num=random.randint(lower_range,upper_range)
print("You have only 3 chance to guess the integer")
i=0
while i<3:
    i+=1
# User Guess the number into given range    
    user_num=int(input("Guess a number : "))
    if random_num==user_num:
        print("Congrat's")
        print("The number is",random_num)
        print("You done it in",i,"try")
        break
    elif random_num>user_num:
        print("Your guess was too small") 
        print("Have one more try")
    elif random_num<user_num:
        print("Your guess was too high")
        print("Have one more try")
    if i>=3:
        print("The number is",random_num) 
        print("Better Luck Next Time!")              






