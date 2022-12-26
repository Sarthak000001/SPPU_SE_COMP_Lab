# ======================================Question==================================================
"In second year comp engg. class, group A student's play cricket , group B students play badmination "
"and group C students play football . Write a python program using functions in compute following"
"1.List of students who plays both cricket and badminaton"
"2.list of students who play either cricket or badminaton but not both"
"3.Number of students who play neither cricket nor badminaton "
"4.Number of students who play cricket and football but not badminaton"
"duplicate not allowed & do not used set"
# -----------------------------------------------------------------------------------------------------


from pickletools import long4


def removeduplicate(a):
    list = []
    for value in a:
        if value not in list:
            list.append(value)
    return list

# --------------------------------------------------------------------------------------------------------


def union(list1, list2):
    list3 = list1.copy()
    for i in list2:
        if i not in list3:
            list3.append(i)
    return list3
# --------------------------------------------------------------------------------------------------------


# def intersection(l1, l2):
#     l3 = []
#     for value in l1:
#         if value in l2:
#             l3.append(value)
#     return l3

# Without using in / not in
def intersection(l1,l2):
    l3=[]
    for i in range(0,len(l1)):
        for j in range(0,len(l2)):
            if(l1[i] == l2[j]):
                l3.append(l1[i])
    return l3
    

# -----------------------------------------------------------------------------------------------

def difference(l1, l2):
    l3 = []
    for value in l1:
        if value not in l2:
            l3.append(value)
    return l3
# ------------------------------------------------------------------------------------------------


def sysmetric_difference(l1, l2):
    l3 = []
    u1 = union(l1, l2)
    i1 = intersection(l1, l2)
    l3 = difference(u1, i1)
    return l3

# ---------------------------------------------------------------------------------------------

#Function for sorting the list 
def sort_the_list(l1): #bubble sort
    for i in range(0, len(l1)):
        for j in range(0, len(l1)-i-1):
           if l1[j] > l1[j+1]:
              temp = l1[j]
              l1[j] = l1[j+1]
              l1[j+1] = temp
    return l1

# ----------------------------------------------------------------------------------------
p = []
n = int(input("Enter number of students in the Second year computer engineering :"))
print("Enter the name of each students in the second year computer engineering :")
print("Note-Click on enter button every time after entering student name ")
for i in range(0, n):
    value = input()
    if value.isalpha(): #checking whether the input enter is valid or not
      p.append(value)
    else:
         print("Your not enter the correct name")
   
SE_comp = removeduplicate(p)

# ------------------------------------------------------------------------
cr = []
n1 = int(input("Enter the number of students in the cricket team : "))
print("Enter the name of each students in the cricket team :")
print("Note-Click on enter button every time after entering student name ")
for i in range(0, n1):
    value = input()
    if value not in SE_comp:
            print("student should be the part of second year computer engineering")
            print("check name that you enter")
    else:
        cr.append(value)
        cricket = removeduplicate(cr)
# -------------------------------------------------------------------------------------------------------
ba = []
n2 = int(input("Enter the number of students in the badmination team : "))
print("Enter the name of each students in the badmination team :")
print("Note-Click on enter button every time after entering student name ")
for i in range(0, n2):
    value = input()
    if value not in SE_comp:
        print("student should be the part of second year computer engineering")
        print("check name that you enter")
    else:
      ba.append(value)
      badmination = removeduplicate(ba)

# ---------------------------------------------------------------------------------------------
fo = []
n3 = int(input("Enter the number of students in the football team : "))
print("Enter the name of each students in the football team :")
print("Note-Click on enter button every time after entering student name ")
for i in range(0, n3):
    value = input()
    if value not in SE_comp:
        print("student should be the part of second year computer engineering")
        print("check name that you enter")
    else:
      fo.append(value)
      football = removeduplicate(fo)
# ---------------------------------------------------------------------------------------------------------


def cb(l1, l2):  # students who plays both cricket and badminaton
    l3 = intersection(l1, l2)
    l4=sort_the_list(l3)
    return l4


def eceb(l1, l2):  # students who plays either circket or badminaton but not both
    l3 = sysmetric_difference(l1, l2)
    l4=sort_the_list(l3)
    return l4


def ncnb(l1, l2, l3):  # number of students who plays neither cricket nor badminaton
    l4 = difference(l1, union(l2, l3))
    l4=sort_the_list(l3)
    return len(l4)


def cfnb(l1, l2, l3):  # number of students who plays cricket and football but not badminaton
    l4 = difference(intersection(l1, l2), l3)
    l4=sort_the_list(l3)
    return len(l4)


# --------------------------------Menu bar-----------------------------------------------
i = 0
while i == 0:
    print("======================= Menu bar ===============================")

    print("1.List of students who plays both cricket and badminaton")
    print("2.list of students who play either cricket or badminaton but not both")
    print("3.Number of students who play neither cricket nor badminaton ")
    print("4.Number of students who play cricket and football but not badminaton")

    choose = int(input("Select the option :"))

    if choose == 1:
        print("List of students who plays both cricket and badminaton :",
              cb(cricket, badmination))
        a = input("Do you want to contiue - yes/no :")
        if a == "yes":
            i == 1
        else:
            i == 0
            print("Thank you")
    elif choose == 2:
        print("list of students who play either cricket or badminaton but not both :", eceb(
            cricket, badmination))
        a = input("Do you want to contiue - yes/no :")
        if a == "yes":
            i == 1
        else:
            i == 0
            print("Thank you")
    elif choose == 3:
         print("Number of students who play neither cricket nor badminaton : ", ncnb(SE_comp, cricket, badmination))
         a = input("Do you want to contiue - yes/no :")
         if a=="yes":
            i==1
         else :
            i==0
            print("Thank you")
    elif choose == 4:
        print("Number of students who play cricket and football but not badminaton : ",cfnb(cricket,football,badmination))
        a = input("Do you want to contiue - yes/no :")
        if a=="yes":
            i==1
        else :
            i==0
            print("Thank you")
    else:
        print("Enter the valid input ")
        a=input("Back to the main menu - yes/no :")
        if a=="yes":
            i==1
        else:
            i==0
            print("Thank you")
        
        