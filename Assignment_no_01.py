def remove_duplicate(a):
    list = []
    for i in a:
        if i not in list:
            list.append(i)
    return list
# -------------------------------------


def intersection(l1, l2):
    l3 = []
    for value in l1:
        if value in l2:
            l3.append(value)
    return l3
# -------------------------------------


def union(l1, l2):
    l3 = l1.copy()  #copying the all ele. from l1 into the l3
    for value in l2:
        if value not in l3:
            l3.append(value)
    return l3
# ----------------------


def diff(l1, l2):
    l3 = []
    for value in l1:
        if value not in l2:
            l3.append(value)
    return l3
# -----------------------------


def sym_diff(l1, l2):
    l3 = []
    d1 = diff(l1, l2)
    d2 = diff(l2, l1)
    l3 = union(d1, d2)
    return l3


# =====================================================
secomp = []
n = int(input("enter number"))
print("enter name of students in secomp")
for i in range(0, n):
    element = input()
    secomp.append(element)

print("the list of student is "+str(secomp))
# ------------------------------------------------------
cricket = []
n = int(input("enter number of student who play cricket"))
print("enter name of students in cricket")
for i in range(0, n):
    element = input()
    cricket.append(element)

print("the list of student is "+str(cricket))
# ----------------------------------------------
badminaton = []
n = int(input("enter number of students who play badmination"))
print("enter name of students in badmination")
for i in range(0, n):
    element = input()
    badminaton.append(element)

print("the list of student is "+str(badminaton))
# ---------------------------------
football = []
n = int(input("enter number of students who play football"))
print("enter name of students in football")
for i in range(0, n):
    element = input()
    football.append(element)

print("the list of student is "+str(football))
# ---------------------------------


def cb(l1, l2):
    l3 = intersection(l1, l2)
    return len(l3)


def eceb(l1, l2):
    l3 = sym_diff(l1, l2)
    return len(l3)


def ncnb(l1, l2, l3):
    l4 = diff(l1, union(l2, l3))
    return len(l4)


def cbnf(l1, l2, l3):
    l4 = diff(intersection(l1, l2), l3)
    return len(l4)

# -----------------------------------------------------------


flag = 1
while flag == 1:
    print("====================main menu========================")
    print("1.list of students who plays cricket and badmination")
    print("2.list of students who plays either play cricket or badmination but not both")
    print("3.list of students who plays neither cricket nor badmination")
    print("4.list of students who plays cricket and football not badminaton")
    print("5.exit")
    c = int(input("enter your choose"))
    if c == 1:
        print("1.list of students who plays cricket and badmination",
              cb(cricket, badminaton))
        a = input("do you want to contiue - > yes or no")
        if a == "yes":
            flag == 1
        else:
            flag == 0
            print("Thank you")
    elif c == 2:
        print("2.list of students who either play cricket or badmination",
              eceb(cricket, badminaton))
        a = input("do you want to contiue - > yes or no")
        if a == "yes":
                flag == 1
        else:
                flag == 0
                print("Thank you")
