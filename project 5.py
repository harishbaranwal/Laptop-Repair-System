# Guess the number
try:
# try and except is used for valid range     
    from random import randint
    level = 1
    points = [30,20,10]
    points_scored = 0
    # use while loop for increasing level upto 1000000
    while level <= 100000:
        a=int(input("Enter the lower bound of the range: "))
        b=int(input("Enter the upper bound of the range: "))

        secret_number = randint(a,b)
        counter=0
    # use while loop for repetitive guessing     
        while counter<3:
            guess_number = int(input("Guess the secret number between {} and {} ({} attempts left): ".format(a,b,3-counter)))

            if secret_number == guess_number:
                print("Congrats, You Won the level {} with {} points".format(level,points[counter]))
                points_scored += points[counter]
                level = level + 1
                break
            elif guess_number < secret_number:
                print("Your guess was too low.")
            else:
                print("Your guess was too high.")
            counter+=1    
        else:
            print("Better Luck Next Time!, secret number was {}.".format(secret_number))
            print("Your total score is {} points.".format(points_scored))
            break
    else:
        print("Congrats, You Won the Game with {} points!!!".format(points_scored))

except:
    print("Error! Enter proper values for the range.")
 # This is the end of the program
               
