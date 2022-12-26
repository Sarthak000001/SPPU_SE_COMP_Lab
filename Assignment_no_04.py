from traceback import print_tb


class Search:
    def __init__(self):
        self.l=[]
        self.n = 0
    def inlist(self):
        self.n=int(input("Enter the Number of Element in list : "))
        for i in range(self.n):
          self.l.append(int(input()))


    def linearSearch(self,key):
        ans = 0
        flag=False
        for i in range(len(self.l)):
            if self.l[i]==key:
                ans=i
                flag = True
                break
            else:
                continue
        if flag:
            print("ELement is Present at Index :",ans)
        else:
            print("Element is not Present ")

    def sserach(self, key):
        ans = 0
        i = 0
        self.l.append(key) #appending the key ele. to the end of the list
        while self.l[i] != key:
            ans = i
            i += 1
        if i == len(self.l) - 1:
            print("Element is not Present")
            self.l.pop() #removing the appended ele. from the list
        else:
            print("Element is Present at Index :", ans + 1)
            self.l.pop()
    def fibo(self,key):
        self.l.sort()
        if(self.l[0]==key):
            print(self.l,end="\n")
            print("Element is Present at Index :",0)
            return
        if(self.l[self.n-1]==key):
            print(self.l,end="\n")
            print("Element is Present at Index :",self.n-1)
            return
        n=len(self.l)
        f1=0
        f2=1
        f3=f1+f2    
        while(f3 < n):
            f1=f2
            f2=f3
            f3 = f2 + f1
        # print(f3,f2,f1)
        offset=-1
        i=min(offset+f1,n)
        # print(i)
        while(f3 != 1 and f1!=0):
            if(self.l[i]==key):
                print(self.l)
                print("Element is Present at Index :",i)
                return
            elif(self.l[i] < key): #if ele. is less than key go one step down
                f3=f2
                f2=f1
                f1=f3-f2
                offset=i
            else:                  #if ele. is greater than key go two step down
                f3=f3-f2
                f2=f2-f1
                f1=f3-f2
            i = min(offset + f1, n)  
        print("Element is not Present")

    def binarySearch(self,key):
        ans = 0
        flag=False
        self.l.sort() #Sorting the list 
        s=0
        e=len(self.l)-1
        while s <= e: #!don't forget the equal to sign
            mid=(s+e)//2
            if key==self.l[mid]:
                ans=mid
                flag=True
                break
            elif key > self.l[mid]:
                s=mid+1
            else:
                e=mid-1
        if flag:
            print(self.l)
            print("Element is Present at Index :",ans)
        else:
            print("Element is not Present")

#* For binary and fibonacci Search the list should be sorted 

# Main
p=Search()
p.inlist()
def menubar():
    print("________________ Menu Bar _________________________")
    print("Enter 1:By Linear Search")
    print("Enter 2:By Sentinal Search")
    print("Enter 3:By Binary Search")
    print("Enter 4:By Fibonacci Search")
    print("Enter 5:Exit")
    print("----------------------------------------------")
    ch=int(input("Enter your choose :"))
    if(ch!=5):
      n1=int(input("Enter the key Value you want to Search : "))
    def first():
        p.linearSearch(n1)
    def second():
        p.sserach(n1)
    def third():
        p.binarySearch(n1)
    def fourth():
        p.fibo(n1)
    if ch==1:
        first()
        op=input("Do you want to continue y/n :")
        if op=="y":
            menubar()
        else:
            print("Thank you!")
    elif ch==2:
        second()
        op=input("Do you want to continue y/n :")
        if op=="y":
            menubar()
        else:
            print("Thank you!")
    elif ch==3:
        third()
        op=input("Do you want to continue y/n :")
        if op=="y":
            menubar()
        else:
            print("Thank you!")
    elif ch==4:
        fourth()
        op=input("Do you want to continue y/n :")
        if op=="y":
            menubar()
        else:
            print("Thank you!")
    elif ch==5:
        print("Thank you!")
    else:
        print("Enter the invalid option")
        op=input("Do you want to continue y/n :")
        if op=="y":
            menubar()
        else:
            print("Thank you!")
        
  
menubar()
    
# print("By Linear Search")
# p.linearSearch(8)
# print("By sentinel Search")
# p.sserach(8)
# print("By Binary Search")
# p.binarySearch(8)
# print("By fibonacci Search")
# p.fibo(4)