
class Sort:
    l=[]
    n=0
    def __init__(self):
        self.n=int(input("Enter the Number of element in the List : "))
        for i in range(self.n):
            self.l.append(int(input()))
    def partition(self,l,s,e):
        pivot = self.l[s]
        cnt = 0
        for i in range(s+1,self.n):
            if(pivot > self.l[i]):
                cnt+=1
        pivotindex=s+cnt
        # swap(self.l[s],self.l[pivotindex])
        temp=self.l[s]
        self.l[s]=self.l[pivotindex]
        self.l[pivotindex]=temp

        i=s
        j=e
        while(i < pivotindex and j > pivotindex):
            if(self.l[i] < self.l[pivotindex]):
                i+=1
            if(self.l[j] > self.l[pivotindex]):
                j-=1
            if(i < pivotindex and j > pivotindex):
                temp = self.l[i]
                self.l[i]=self.l[j]
                self.l[j]=temp
        return pivotindex

    def quicksort(self,l,s,e):
        if s < e:
             p = self.partition(self.l,s,e)
             # left part
             self.quicksort(self.l,s,p-1)
             # Right part
             self.quicksort(self.l,p+1,e)





# main
p = Sort()
p.quicksort(p.l,0,p.n-1)
print(p.l)

# class Sort:
#     l=[]
#     n=0
#     def __init__(self):
#         self.n=int(input("Enter the Number of element in the List : "))
#         for i in range(self.n):
#             self.l.append(int(input()))
            
#     def partion(self,list1,low,high):
#         pivot=list1[high]
#         i=low-1
#         for j in range (low,high):
#             if(list1[j]<=pivot):
#                 i+=1
#                 list1[i],list1[j]=list1[j],list1[i]
#         list1[i+1],list1[high]=list1[high],list1[i+1]
#         return i+1
    
#     def q(self,list1,low,high):
#         if(low<high):
#             pi=self.partion(list1,low,high)
#             self.q(self.l,low,pi-1)
#         # Right part
#             self.q(self.l,pi+1,high)
            
# p = Sort()
# p.q(p.l,0,p.n-1)
# print(p.l)      