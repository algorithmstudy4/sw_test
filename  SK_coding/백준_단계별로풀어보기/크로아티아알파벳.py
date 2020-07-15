
croatia = input()

word_length = len(croatia)

for i in range(0,len(croatia)) :

    if croatia[i] == '=' and i>0 :

        if croatia[i-1] == 'c' or croatia[i-1] == 's' :

            word_length = word_length - 1
        
        elif croatia[i-1] == 'z' :

            if i>1 and croatia[i-2] == 'd' :

                word_length = word_length - 2
            
            else :
                
                word_length = word_length - 1
    
    elif croatia[i] == '-' and i>0 :

        if croatia[i-1] == 'c' or croatia[i-1] == 'd' :

            word_length = word_length - 1
        
    elif croatia[i] == 'j' and i>0 :

        if croatia[i-1] == 'l' or croatia[i-1] == 'n' :

            word_length = word_length - 1

print(word_length)   