
num = int(input())

word = 'a'
count = 0
check_count = 0
word_list = []
checklist = []

for i in range(0,num) :

    word = input()

    word_list.insert(i,word)

for i in range(0,num) :

    for j in range(0,len(word_list[i])) :

        if j == 0 :

            checklist.insert(j,word_list[i][j])
        
        elif j == 1 :

            if checklist[j-1] != word_list[i][j] :

                checklist.insert(j,word_list[i][j])

        elif j > 1 :
            
            if checklist[len(checklist)-1] != word_list[i][j] :

                for k in range(0,len(checklist)) :

                    if checklist[k] == word_list[i][j] :

                        count = count + 1

                        break

                if check_count + 1 == count :

                    check_count = check_count + 1

                    break

                elif check_count == count :

                    checklist.insert(j,word_list[i][j])
    
    del checklist[:]
    
print(num - count)
            

           
        



