# class Sort:
#     def __init__(self):
#         self.list = []
#         self.n = 0
#         self.n = int(input("Enter the length of list :"))
#         print("Ente the ele. in the list :")
#         for i in range(self.n):
#             self.list.append(int(input()))
#         self.low = 0
#         self.high = self.n-1

#     def shellsort(self):
#         gap = self.n//2
#         while gap > 0:
#             j = gap
#             while j < self.n:
#                 i = j-gap
#                 while i >= 0:
#                     if (self.list[i+gap] > self.list[i]):
#                         break
#                     else:
#                         self.list[i+gap], self.list[i] = self.list[i], self.list[i+gap]
#                     i = i-gap
#                 j += 1
#             gap = gap//2

#     def insertion(self):
#         for i in range(1, self.n):
#             temp = self.list[i]
#             j = i-1
#             while j >= 0:
#                 if (self.list[j] > temp):
#                     self.list[j+1] = self.list[j]
#                 else:
#                     break
#                 j -= 1
#             self.list[j+1] = temp

#     def display(self):
#         for i in range(self.n):
#             print(self.list[i], end=" ")

#     def quicksort(self, list, low, high):
#         if (low > high):
#             return


# obj = Sort()
# obj.quicksort(obj.list, obj.low, obj.high)
# # obj.shellsort()
# # obj.insertion()
# obj.display()

# ---------------------------------
# class Sort:
#     def __init__(self):
#         self.list = []
#         self.n = 0
#     def input(self):
#         self.n = int(input("Enter the no. of ele. in the list : "))
#         print("Enter the ele. :")
#         for i in range(0,self.n):
#             self.list.append(int(input()))
#         print()
#     def output(self):
#         for i in range(0,self.n):
#             print(self.list[i],end=" ")
#     def partition(self,list1,low,high):
#         pivot = list1[low]
#         i = low
#         j = high
#         while i < j:
#             while list1[i] <= pivot and i < j:
#                 i+=1
#             while list1[j] > pivot and i < j:
#                 j-=1
#             if i < j: 
#                 list1[i],list1[j] = list1[j],list1[i]
#         list1[low],list1[j] = list1[j],list1[low]
#         return j
#     def Quicksort(self,list1,low,high):
#         if low > high:
#             return 
#         p = self.partition(list1,low,high)
#         self.Quicksort(self.list,low,p)
#         self.Quicksort(self.list,p+1,high)
        
# -------------------------------------------------------
class Sort:
    def __init__(self):
        self.list = []
        self.n = []
    def input(self):
        self.n = int(input("Enter the Number of ele. in the list : "))
        print("Enter the ele. : ")
        for i in range(self.n):
            self.list.append(float(input()))
            
    def output(self):
        for i in range(self.n):
            print(self.list[i],end=" ")
            
    def partition(self,list,low,high):
        pivot = self.list[low]
        cnt = 0
        for i in range(low+1,high):
            if self.list[i] < pivot:
                cnt+=1
        pivotindex = low + cnt
        self.list[pivotindex],self.list[low] = self.list[low],self.list[pivotindex]
        i = low
        j = high
        while i < pivotindex and j > pivotindex:
            if self.list[i] < self.list[pivotindex]:
                i+=1
            if self.list[j] > self.list[pivotindex]:
                j-=1
            if i < pivotindex and j > pivotindex:
                self.list[i],self.list[j]=self.list[j],self.list[i]
        return pivotindex
        
    def QuickSort(self,list,low,high):
        if(low < high):
           p = self.partition(list,low,high)
           self.QuickSort(list,low,p-1)
           self.QuickSort(list,p+1,high)
        else:
            return 
    
#Main
obj = Sort()
obj.input()
obj.QuickSort(obj.list,0,obj.n-1)
# obj.output()
print(obj.list)
   
        
        