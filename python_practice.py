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
        # for i in range(self.n):
        print(self.list)
        print()

    def partition(self, list, low, high):
        pivot = self.list[low]
        cnt = 0
        for i in range(low+1, len(list)):
            if self.list[i] < pivot:
                cnt += 1
        pivotindex = low + cnt
        self.list[pivotindex], self.list[low] = self.list[low], self.list[pivotindex]
        i = low
        j = high
        while i < pivotindex and j > pivotindex:
            if self.list[i] < self.list[pivotindex]:
                i += 1
            if self.list[j] > self.list[pivotindex]:
                j -= 1
            if i < pivotindex and j > pivotindex:
                self.list[i], self.list[j] = self.list[j], self.list[i]
        return pivotindex

    def QuickSort(self, list, low, high):
        if (low < high):
            p = self.partition(list, low, high)
            self.QuickSort(list, low, p-1)
            self.QuickSort(list, p+1, high)
        else:
            return

# Main
# obj = Sort()
# obj.input()
# obj.QuickSort(obj.list,0,obj.n-1)
# obj.output()
# print(obj.list)


class Matrix:
    def __init__(self):
        self.list = [[0, 0, 0, 0, 0], [0, 0, 0, 0, 0], [0, 0, 0, 0, 0]]
        self.col = 0
        self.row = 0

    def Matin(self):
        self.list = []
        self.row = int(input("Enter the no. of row : "))
        self.col = int(input("Enter the no. of col : "))
        print("Enter the ele.  : ")
        for i in range(self.row):
            row = []
            for j in range(self.col):
                row.append(int(input()))
            self.list.append(row)

    def Matout(self):
        for i in range(self.row):
            for j in range(self.col):
                print(self.list[i][j], end=" ")
            print()
            
    def add(self,temp):
        if self.row == temp.row and self.col == temp.col:
            ans = Matrix()
            ans.row = self.row
            ans.col = self.col
            for i in range(self.row):
                for j in range(self.col):
                    ans.list[i][j] = self.list[i][j] + temp.list[i][j]
            return ans          
        else:
            print("Error")
    
    def Subtraction(self,temp):
        if self.row == temp.row and self.col == temp.col:
            ans = Matrix()
            ans.row = self.row
            ans.col = self.col
            for i in range(self.row):
                for j in range(self.col):
                    ans.list[i][j] = self.list[i][j] - temp.list[i][j]
            return ans          
        else:
            print("Error")
    def Multi(self,temp):
        if self.col == temp.row:
            ans = Matrix()
            ans.row = self.row
            ans.col = temp.col
            for i in range(ans.row):
                for j in range(ans.col):
                    for k in range(self.col): #temp.row
                        ans.list[i][j] += self.list[i][k]*temp.list[k][j]
            return ans        
        else:
            print("Multiplication is not possible ")
    def transpose(self):
        ans = Matrix()
        ans.row = self.col
        ans.col = self.row
        for i in range(self.row):
            for j in range(self.col):
                ans.list[j][i] = self.list[i][j]
        return ans
                
    


# Main
# M1 = Matrix()
# M2 = Matrix()
# ans = Matrix()
# M1.Matin()
# M2.Matin()
# print("Matrix 1 ")
# M1.Matout()
# print("Matrix 2 ")
# M2.Matout()
# print("Addition ---> ")
# ans = M1.add(M2)
# ans.Matout()
# print("Subtraction ---> ")
# ans = M1.Subtraction(M2)
# ans.Matout()
# print("Multiplication --->")
# ans = M1.Multi(M2)
# ans.Matout()
# print("Transpose --->")
# ans = M1.transpose()
# ans.Matout()

# -------------------Sorting-----------------------------
class Sort:
    def __init__(self):
        self.list = []
        self.n = []
    def input(self):
        self.n = int(input("Enter the no. of ele. in the list : "))
        print("Enter the ele. :  ")
        for i in range(self.n):
            self.list.append(float(input()))
        print()
    def bubble(self):
        flag = False
        for i in range(0,self.n):
            for j in range(0,self.n-i-1):
                if self.list[j] > self.list[j+1]:
                    self.list[j],self.list[j+1] = self.list[j+1],self.list[j]
                    flag = True
            if flag == False:
              break
    def insertion(self):
        for i in range(1,self.n):
            temp = self.list[i]
            j = i - 1
            while j >= 0:
                if self.list[j] > temp:
                    self.list[j+1] = self.list[j]
                else:
                    break
                j-=1
            self.list[j+1] = temp
            
            
# Main
# obj = Sort()
# obj.input()
# # obj.bubble()
# obj.insertion()
# print(obj.list)

str1 = "Level"
str2 = str1.lower()
print(str2)
