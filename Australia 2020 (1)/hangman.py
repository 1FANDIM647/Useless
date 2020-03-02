import random

 print("\t\t\t\tExecution Death game :)")
        print("********************************")
        HANGMAN = (
          """
          -1
          """
          ,
          """
          -2      
          """
          ,
          """
          -3
          """
          ,
          """
          -4
          """
          ,
          """
          -5      
          """
          ,
          """
          -6
          """
          ,
          """
          -7
          """
          ,
          """
          -8
          """
        )
        #MAXIMUM  AMOUNT OF MISTAKES
       MAX_WRONG = len(HANGMAN)-1
       #WORDS FOR GAME  
       WORDS  = ['OVERUSED' , 'CLAM', 'GUAM','TAFFETA' , 'PYTHON','PASCAL']

       word = random.choice(WORDS)
       
       so_far = "-" * len(word) #guess by one letter (for example "p")

       wrong = 0 # amount of mistakes 

       used = [] #letters which player used to 
     
       if (quesstion_in_execution_death_game == "yes" or "YES " or "Yep" ):
           print ("\t\t\tWelcome!\n ")
           while wrong < MAX_WRONG and so_far != word :
               print(HANGMAN [wrong])
               print("\nYou used these letters:", used[])
               print("WORD :" , so_far)
           guess input("Enter  the word :")
           guess = guess.upper()
           while guess in used:
               print("You used allready:",guess)
               guess =("Enter letter :")
               guess = guess.upper()
           used.append(guess)
           if guess in word:
               print ("\nYes! ", guess  ,"there is in")
               #new line so_far with gussed letter or letters
               new = ""
               for i in range(len(word)):
                   if guess == word[i]:
                       new += guess
                   else:
                       new += so_far[i]
               so_far = new
            else:
                print("mistake")
                wrong +=1
            if wrong  == MAX_WRONG:
                print(HANGMAN[wrong])
                print("\n DEATH")
            else:
                print("\nYou win")
                print("WORD :"word)  