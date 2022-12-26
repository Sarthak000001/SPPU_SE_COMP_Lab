# Write a Python program to compute following operations on
# String:
# a) To display word with the longest length
# b) To determines the frequency of occurrence of particular
# character in the string   --- okay
# c) To check whether given string is palindrome or not --- okay
# d) To display index of first appearance of the substring
# e) To count the occurrences of each word in a given string


class Question:
    def __init__(self, str, list):
        self.str = str
        self.list = list

    def count_str(self, str):
        count = 0
        for i in str:
            count += 1
        return count

    def freq(self, str, x):  # frequency of occurence of the particular character in string
        count = 0  # Done
        for i in str:
            if (x == i):
                  count += 1
            else:
                continue
        print("the character ",x," appears ",count,"times")

    def palindrome(self, str):   #string  is palindrome or not
       for i in range(q.count_str(str)):     #Done
           if str[i] != str[(q.count_str(str))-i-1]:
               return False
       return True
   
    def occword(self,list):
       for i in list:
           key=i
           count=0
           for j in list:
               if(key==j):
                   count+=1
           print("The ",key,"Occur",count," times ")
       print("\n")
       
    def getmaxlength(self,list):
        word=""
        for i in list:
            if(len(i) > len(word)):
                word=i
        print("The word with longest length is ",word)
        
    def indexofsubstring(self,str,substr):
        mystr=''
        if substr not in self.str:
            print("The substring is not present in given string\n")
        else:
            for i in range(0,len(self.str)):
                if (self.str[i:len(substr)+i]) == substr:
                    print("The first occurence of substring : " , i)
            
                        
                    

                    
                    
# Main   
# str = "i am good boyee"  
str=input("Enter the String :")
ls = []
ls = list(str.split(" "))
q = Question(str, list) #initializing the object

# To display word with the longest length
q.getmaxlength(ls)
x=input("Enter the character : ")
#  To determines the frequency of occurrence of particular character in the string
q.freq(str,x)
# To check whether given string is palindrome or not
q.palindrome(str)
# To display index of first appearance of the substring
s=input("Enter the substring you want to search :")
q.indexofsubstring(str,s)
# To count the occurrences of each word in a given string
q.occword(ls)
