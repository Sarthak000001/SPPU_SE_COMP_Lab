from cgi import print_arguments
from random import randrange


class Sort:
    def __init__(self):
        self.l=[]
        self.n=int(input("Enter the Number of Element in List :"))

    def inlist(self):
        for i in range(self.n):
            self.l.append(int(input()))
    def outlist(self):
        for i in range(self.n):
            print(self.l[i],end=" ")
        print()
    def bubble(self):
        for i in range(0,self.n):
            flag=False
            for j in range(0,self.n-i-1):
                if self.l[j] > self.l[j+1]:
                    temp = self.l[j]
                    self.l[j]=self.l[j+1]
                    self.l[j+1]=temp
                    flag=True
            if flag==False:
             break
    def selection(self):
        for i in range(0,self.n):
            minindex=i
            for j in range(i+1,self.n):
                if self.l[j] < self.l[minindex]:    
                    minindex = j
            temp = self.l[minindex]
            self.l[minindex]=self.l[i]
            self.l[i]=temp

    def insertion(self):
        for i in range(1,self.n):
            temp = self.l[i]
            j=i-1
            while j>=0 and self.l[j] > temp:
                self.l[j+1]=self.l[j]
                j-=1
            self.l[j+1]=temp

    def shellsort(self):
        gap = self.n//2
        while gap > 0:
            i=gap
            while i < self.n:
                temp=self.l[i]
                j=i
                while j >=gap and self.l[j-gap] > temp:
                    self.l[j]=self.l[j-gap]
                    j=j-gap
                i+=1
                self.l[j]=temp
            gap=gap//2



                

    
# Main
p = Sort()
p.inlist()

# print("Insertion")
# p.insertion()
# p.outlist()


# print("Bubble")
# p.bubble()
# p.outlist()
flag=True
while flag:
    print("Enter 1:Insertion Sort")
    print("Enter 2:Bubble Sort")
    print("Enter 3:Selection Sort")
    print("Enter 4:Shell Sort")
    print("Enter 5:Exit")
    ch=int(input("Enter your Choice :"))
    if ch==1:
        print("Insertion Sort")
        p.insertion()
        p.outlist()
        op=input("Do you want to Contiue :(y/n)")
        if op=='y' or op=='Y':
            flag=True
        else:
            flag=False
    elif ch==2:
        print("Bubble Sort")
        p.bubble()
        p.outlist()
        op=input("Do you want to Contiue (y/n) : ")
        if op=='y' or op=='Y':
            flag=True
        else:
            flag=False
    elif ch==3:
        print("Selection Sort")
        p.selection()
        p.outlist()
        op=input("Do you want to Contiue (y/n) : ")
        if op=='y' or op=='Y':
            flag=True
        else:
            flag=False
    elif ch==4:
        print("Shell Sort")
        p.shellsort()
        p.outlist()
        op=input("Do you want to contiue (y/n) : ")
        if op=='y' or op=='Y':
            flag=True
        else:
            flag=False
    else:
        print("Thank you....!!!")
        flag==False